CC        ?= gcc
OUT        = out
DRIVER     = SDL2
CFLAGS     = -Wall -Iinc -D VERSION=$(VERSION)
SRC        = 
OBJS 	     = $(SRC:%.c=%.o)
LDFLAGS    =
VERSION    = 0.1.0_fly
PROFILE    = Debug
BUILD_TYPE = dynamic


ifndef PLATFORM 
	ifeq ($(OS),Windows_NT)
		PLATFORM ?= Windows
	else ifeq ($(shell uname -s),Linux)
		PLATFORM ?= Linux
	endif
endif

ifeq ($(PROFILE),Release)
	CFLAGS += -O2 -D BUILD_RELEASE
	LDFLGS += -flto
else ifdef ($(PROFILE),RelDbg)
	CFLAGS += -O2 -g -D BUILD_RELDBG
	LDFLGS += -flto
else ifdef ($(PROFILE),Debug)
	CFLAGS += -Og -D BUILD_DEBUG
endif

TARGET = libsask-$(PLATFORM)-$(VERSION)-$(PROFILE)-$(DRIVER)
ifeq ($(DRIVER),SDL2)
	SDL2 		= $(shell pkg-config --cflags --libs sdl2)
	SRC 		+= src/drivers/sdl2/video.c
	LDFLAGS += $(SDL2)
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

ifeq ($(BUILD_TYPE),static)
	TARGET  := $(TARGET).a
	LDFLAGS += -static
else 
	LDFLAGS += -shared
endif

sask: prepare $(OBJS) 
	$(CC) -o $(OUT)/$(TARGET) $(LDFLAGS) $(OBJS) 

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

