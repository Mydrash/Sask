#pragma once
#include <Core/Utils/Alias.hpp>

namespace core::utils
{
  inline float IntoGLColor(u8 color)
  {
    return (1.0f / 255) * color;
  }
}  // namespace core::utils