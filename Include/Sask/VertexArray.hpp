#pragma once
#include <cstddef>
#include <vector>

namespace sask
{
  class VertexArray
  {
   private:
    unsigned int vbo, vao;

   public:
    VertexArray(std::vector<float> vec, std::size_t count);
    void Bind();
  };
}  // namespace sask
