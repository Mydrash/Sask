#include <Sask/Engine.hpp>
#include <Sask/Utils/Shader.hpp>
#include <iostream>
#include <unistd.h>

class Game : public sask::Application {
  float red = 0.0f;
  std::shared_ptr<sask::Shader> vertexShader;
  std::shared_ptr<sask::Shader> fragmentShader;
  sask::VertexArray *triangle = nullptr;

public:
  void Setup() {
    using namespace sask::utils;

    std::cout << "GL Renderer: " << *window->GetRenderer() << "\n";
    std::cout << "GL Version: " << *window->GetOpenGLVersion() << "\n";
    std::cout << "Keep pressing <Space> to change color.\n";

    std::cout << "Uploading data onto GPU ... ";
    this->triangle = new sask::VertexArray({0.0f, 0.5f, 0.0f,  //
                                            0.5f, -0.5f, 0.0f, //
                                            -0.5f, -0.5f, 0.0f},
                                           3);

    std::cout << "V";
    this->vertexShader =
        shader::LoadFromFile("./VertexShader.glsl", sask::VertexShader);
    std::cout << "F";

    this->fragmentShader =
        shader::LoadFromFile("./FragmentShader.glsl", sask::FragmentShader);

    fragmentShader->Attach(this->shaders);
    vertexShader->Attach(this->shaders);
    std::cout << " <Finished> \n";
  }

  void Update() {
    if (window->IsKeyDown(Escape)) {
      window->shouldClose = true;
    }

    if (window->IsKeyDown(Space)) {
      this->red += 1.0f;
    }
  }

  void Render(sask::Renderer R) {
    R.ClearColor(red, 0xF, 0xF, 0xFF);
    triangle->Bind();

    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
};

int main(void) {
  sask::Engine engine;
  auto window = engine.CreateWindow("Hello", 800, 600);
  auto game = new Game();

  game->window = window;

  engine.Run(game);
  return 0;
}