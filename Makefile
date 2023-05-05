CC     ?= gcc
OUT    ?= out
DRIVER ?= SDL2
TARGET  = libsask
CFLAGS  = -Wall -Iinc -D VERSION=$(VERSION)
SRC     = 
OBJS 	= $(SRC:%.c=%.o)
LDFLAGS =
VERSION = 0.1.0-fly
CMPFLAG = compile_flags.txt

ifndef PLATFORM 
	ifeq ($(OS),Windows_NT)
		PLATFORM ?= Windows
	else ifeq ($(shell uname -s),Linux)
		PLATFORM ?= Linux
	endif
endif

ifeq ($(PLATFORM),Windows)
	CFLAGS += -D PLAT_WINDOWS
	CC 		 := x86_64-w64-mingw32-gcc
	TARGET := $(TARGET).dll
else ifeq ($(PLATFORM),WindowsLegacy)
	CFLAGS 	+= -D PLAT_WINDOWSLEGACY
	CC 			:= i686-w64-mingw32-gcc
	TARGET  := $(TARGET).dll
else ifeq ($(PLATFORM),Linux)
  CFLAGS  += -D PLAT_LINUX
	TARGET  := $(TARGET).so
endif

ifeq ($(BUILD_TYPE),Release)
	CFLAGS += -O2 -D BUILD_RELEASE
else ifdef ($(BUILD_TYPE),RelDbg)
	CFLAGS += -O2 -D BUILD_RELDBG
else ifdef ($(BUILD_TYPE),Debug)
	CFLAGS += -O2 -D BUILD_DEBUG
endif

ifeq ($(DRIVER),SDL2)
	SDL2 		= $(shell pkg-config --cflags --libs sdl2)
	SRC 		+= src/drivers/sdl2/video.c
	LDFLAGS 	+= $(SDL2)
endif

sask: prepare $(OBJS) 
	$(CC) -o $(OUT)/$(TARGET) $(OBJS) -shared $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS)

list-drivers:
	$(info Avaliable drivers:  \
			 	sdl: Linux,Windows)
describe:
	$(info Version: $(VERSION))
	$(info Compiler: $(CC))
	$(info Compiler flags: $(CFLAGS))
	$(info Platform: $(PLATFORM))
	$(info Driver: $(DRIVER))

prepare:
	mkdir -p $(OUT)

clean:
	rm -rf $(OBJS) $(OUT)/$(TARGET)

