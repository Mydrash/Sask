#pragma once
#include <Core/Graphics/OpenGL.hpp>
#include <Sask/ShaderContainer.hpp>
#include <string>

namespace sask
{
  enum ShaderKind
  {
    FragmentShader = GL_FRAGMENT_SHADER,
    VertexShader = GL_VERTEX_SHADER
  };
  class Shader
  {
   private:
    GLuint id;

   public:
    Shader(std::string content, ShaderKind kind);
    void Attach(sask::ShaderContainer* container);
  };

}  // namespace sask