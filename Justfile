build:
  cmake --build Build -j $(nproc)

Hello: build
  cd ./Build/Examples/Hello && ./Game

HelloDebug: build
  cd ./Build/Examples/Hello && lldb ./Game


