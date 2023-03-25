#include <Core/Graphics/OpenGL.hpp>
#include <Sask/ShaderContainer.hpp>

using sask::ShaderContainer;

ShaderContainer::ShaderContainer()
{
  this->id = glCreateProgram();
}

ShaderContainer::~ShaderContainer()
{
  glDeleteProgram(id);
}

void ShaderContainer::Attach()
{
  glLinkProgram(id);
}

void ShaderContainer::Bind()
{
  glUseProgram(id);
}