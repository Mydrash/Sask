build:
  cmake --build Build -j $(nproc)

Hello: build
  ./Build/Examples/Hello/Game

HelloDebug: build
  lldb ./Build/Examples/Hello/Game


