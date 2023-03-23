#pragma once

#include <Core/Graphics/Display.hpp>
#include <string_view>
namespace sask {
class Window {
private:
  core::graphics::Display Display;

public:
  Window(std::string_view Title, uint width, uint height)
      : Display(Title, width, height) {}
};
} // namespace sask