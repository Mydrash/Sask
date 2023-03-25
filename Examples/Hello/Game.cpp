#include <Sask/Engine.hpp>

void Render(sask::Renderer R) { R.ClearColor(0xFA, 0xFA, 0xFA, 0xFF); }

int main(void) {
  auto engine = new sask::Engine();
  auto window = engine->CreateWindow("Hello", 800, 600);
  window->MakeCurrent();

  while (!window->ShouldClose()) {
    window->UpdateViewport();

    Render(engine->Renderer);

    window->Flush();
    engine->PollEvents();
  }

  return 0;
}