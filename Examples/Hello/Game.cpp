#include <Sask/Engine.hpp>
#include <iostream>

class Game : public sask::Application {
  float red = 0.0f;

public:
  void Setup() {
    std::cout << "GL Renderer: " << *window->GetRenderer() << "\n";
    std::cout << "GL Version: " << *window->GetOpenGLVersion() << "\n";
    std::cout << "Keep pressing <Space> to change color.\n";
  }

  void Update() {
    if (window->IsKeyDown(Escape)) {
      window->shouldClose = true;
    }

    if (window->IsKeyDown(Space)) {
      this->red += 1.0f;
    }
  }

  void Render(sask::Renderer R) { R.ClearColor(red, 0xF, 0xF, 0xFF); }
};

int main(void) {
  sask::Engine engine;
  auto window = engine.CreateWindow("Hello", 800, 600);
  auto game = new Game();

  game->window = window;

  engine.Run(game);
  return 0;
}