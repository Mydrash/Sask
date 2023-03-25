#include <GL/gl.h>

#include <Core/Utils/GL.hpp>
#include <Sask/Renderer.hpp>

using sask::Renderer;

void Renderer::ClearColor(u8 r, u8 g, u8 b, u8 a)
{
  using core::utils::IntoGLColor;

  glClearColor(IntoGLColor(r), IntoGLColor(g), IntoGLColor(b), IntoGLColor(a));
}
