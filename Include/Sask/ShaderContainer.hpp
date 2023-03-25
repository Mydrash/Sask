#pragma once
#include <Core/Utils/Alias.hpp>
#include <Sask/Window.hpp>

namespace sask
{
  class ShaderContainer
  {
   private:
    uint id;

   public:
    ShaderContainer();
    ~ShaderContainer();

    void Attach();
    void Bind();

    friend class Shader;
  };
}  // namespace sask