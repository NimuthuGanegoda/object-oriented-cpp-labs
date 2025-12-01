#ifndef OBJECT_ORIENTED_CPP_LABS_EXAMPLE_CLASS_HPP_
#define OBJECT_ORIENTED_CPP_LABS_EXAMPLE_CLASS_HPP_

#include <string>

namespace example {

/**
 * @brief Example class demonstrating the project structure
 * 
 * This is a template showing how to add new classes to the project.
 * To use:
 * 1. Copy this file to include/object-oriented-cpp-labs/YourClass.hpp
 * 2. Create corresponding src/YourClass.cpp
 * 3. Add both to cmake/SourcesAndHeaders.cmake
 * 4. Create test/src/YourClass_test.cpp
 */
class ExampleClass {
public:
  /**
   * @brief Construct a new Example Class object
   * @param name The name to store
   */
  explicit ExampleClass(const std::string& name);

  /**
   * @brief Get the stored name
   * @return const std::string& Reference to the name
   */
  const std::string& getName() const;

  /**
   * @brief Set a new name
   * @param name The new name
   */
  void setName(const std::string& name);

  /**
   * @brief Example method that processes data
   * @param value Input value
   * @return int Processed result
   */
  int process(int value) const;

private:
  std::string name_;
};

}  // namespace example

#endif  // OBJECT_ORIENTED_CPP_LABS_EXAMPLE_CLASS_HPP_
