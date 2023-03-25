#pragma once

#include <Sask/Shader.hpp>
#include <memory>

namespace sask::utils::shader
{
  std::shared_ptr<Shader> LoadFromFile(std::string filePath,
                                       sask::ShaderKind kind);
}  // namespace sask::utils::shader