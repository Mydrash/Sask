#include <Core/Graphics/OpenGL.hpp>
#include <Sask/VertexArray.hpp>
#include <cstddef>
#include <iostream>
#include <vector>

using sask::VertexArray;

VertexArray::VertexArray(std::vector<float> vec, std::size_t count)
{
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glBufferData(GL_ARRAY_BUFFER, vec.size() * sizeof(float), vec.data(),
               GL_STATIC_DRAW);

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, count, GL_FLOAT, GL_FALSE, 0, NULL);
}

void VertexArray::Bind()
{
  glBindVertexArray(vao);
}