#include <Sask/Engine.hpp>

class Game : public sask::Application {
public:
  void Update() {
    if (window->IsKeyDown(Escape)) {
      window->shouldClose = true;
    }
  }

  void Render(sask::Renderer R) { R.ClearColor(0xFA, 0xFA, 0xFA, 0xFF); }
};

int main(void) {
  sask::Engine engine;
  auto window = engine.CreateWindow("Hello", 800, 600);
  auto game = new Game();

  game->window = window;

  engine.Run(game);
  return 0;
}