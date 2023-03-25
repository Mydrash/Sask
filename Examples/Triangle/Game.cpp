#include <Sask/Engine.hpp>
#include <Sask/Utils/Shader.hpp>
#include <iostream>

class Game : public sask::Application
{
  std::shared_ptr<sask::Shader> vertexShader;
  std::shared_ptr<sask::Shader> fragmentShader;
  sask::VertexArray* triangle = nullptr;
  sask::ShaderContainer shaders;

 public:
  void Setup()
  {
    using namespace sask::utils;
    std::cout << "GL Renderer: " << *window->GetRenderer() << "\n";
    std::cout << "GL Version: " << *window->GetOpenGLVersion() << "\n";

    std::cout << "Compiling shaders ... ";
    this->triangle = new sask::VertexArray({ 0.0f, 0.5f, 0.0f,   //
                                             0.5f, -0.5f, 0.0f,  //
                                             -0.5f, -0.5f, 0.0f },
                                           3);

    std::cout << "V";
    this->vertexShader =
        shader::LoadFromFile("./VertexShader.glsl", sask::VertexShader);
    std::cout << "F";

    this->fragmentShader =
        shader::LoadFromFile("./FragmentShader.glsl", sask::FragmentShader);

    fragmentShader->Attach(&this->shaders);
    vertexShader->Attach(&this->shaders);
    shaders.Attach();

    std::cout << ": Done.\n";
  }

  void Render(sask::Renderer R)
  {
    shaders.Bind();
    triangle->Bind();

    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
};

int main(void)
{
  sask::Engine engine;
  auto window = engine.CreateWindow("Triangle", 800, 600);
  auto game = new Game();

  game->window = window;

  engine.Run(game);
  return 0;
}
