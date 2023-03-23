#pragma once

#include <Core/Graphics/Display.hpp>
#include <string_view>
namespace sask {
class Window {
private:
  core::graphics::Display Display;

public:
  Window(std::string_view title, uint width, uint height)
      : Display(title, width, height) {}
};
} // namespace sask