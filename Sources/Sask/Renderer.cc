#include <Core/Graphics/OpenGL.hpp>
#include <Core/Utils/GL.hpp>
#include <Sask/Renderer.hpp>

const u8 SKY_BLUE[4] = { 180, 200, 250, 255 };

using sask::Renderer;

void Renderer::ClearColor(u8 r, u8 g, u8 b, u8 a)
{
  using core::utils::IntoGLColor;
  glClearColor(IntoGLColor(r), IntoGLColor(g), IntoGLColor(b), IntoGLColor(a));
}

void Renderer::ClearColor(u8 rgba[4]) // example: {180, 200, 250, 255} or SKY_BLUE
{
  using core::utils::IntoGLColor;
  glClearColor(IntoGLColor(rgba[0]), IntoGLColor(rgba[1]), IntoGLColor(rgba[2]), IntoGLColor(rgba[3]))
}
