#include <Sask/Engine.hpp>

int main(void) {
  auto engine = new sask::Engine();
  auto window = engine->CreateWindow("Hello", 800, 600);
  window->MakeCurrent();

  while (!window->ShouldClose()) {
    engine->PollEvents();
  }

  return 0;
}