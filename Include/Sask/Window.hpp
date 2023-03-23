#pragma once

#include "Core/Graphics/Display.hpp"
#include <string>
namespace sask {
class Window {
private:
  core::graphics::Display Display;

public:
  Window(std::string Title, uint width, uint height)
      : Display(Title, width, height) {}
};
} // namespace sask