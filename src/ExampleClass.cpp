#include "object-oriented-cpp-labs/ExampleClass.hpp"

namespace example {

ExampleClass::ExampleClass(const std::string& name) : name_(name) {}

const std::string& ExampleClass::getName() const { return name_; }

void ExampleClass::setName(const std::string& name) { name_ = name; }

int ExampleClass::process(int value) const {
  // Example processing logic
  return value * 2 + name_.length();
}

}  // namespace example
