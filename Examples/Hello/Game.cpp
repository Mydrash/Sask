#include <Sask/Engine.hpp>

int main(void) {
  auto engine = new sask::Engine();
  auto window = engine->CreateWindow("Hello", 800, 600);
  while (true)
    ;
  return 0;
}