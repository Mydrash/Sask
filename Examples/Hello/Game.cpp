#include <Sask/Engine.hpp>

int main(void) {
  auto engine = sask::Engine();

  auto window = engine.CreateWindow("Game", 800, 600);

  while (true)
    ;
  return 0;
}