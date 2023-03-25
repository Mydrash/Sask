#include <Sask/Shader.hpp>
#include <Sask/Utils/Shader.hpp>
#include <cstring>
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <system_error>

using namespace sask::utils;

std::shared_ptr<sask::Shader> shader::LoadFromFile(std::string filePath,
                                                   sask::ShaderKind kind) {
  std::ifstream source(filePath);

  if (source.fail()) {
    throw std::ios_base::failure(filePath + ": " + std::strerror(errno));
  }

  std::string line;
  std::stringstream content;

  while (getline(source, line)) {
    content << line << "\n";
  }

  sask::Shader shader(content.str(), kind);

  return std::make_shared<sask::Shader>(shader);
}