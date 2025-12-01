#include "object-oriented-cpp-labs/ExampleClass.hpp"

#include <gtest/gtest.h>

using namespace example;

// Test fixture for ExampleClass
class ExampleClassTest : public ::testing::Test {
protected:
  void SetUp() override {
    // Setup code that runs before each test
  }

  void TearDown() override {
    // Cleanup code that runs after each test
  }
};

TEST_F(ExampleClassTest, ConstructorSetsName) {
  ExampleClass obj("TestName");
  EXPECT_EQ(obj.getName(), "TestName");
}

TEST_F(ExampleClassTest, SetNameChangesName) {
  ExampleClass obj("Initial");
  obj.setName("Updated");
  EXPECT_EQ(obj.getName(), "Updated");
}

TEST_F(ExampleClassTest, ProcessCalculatesCorrectly) {
  ExampleClass obj("test");  // length = 4
  int result = obj.process(5);
  EXPECT_EQ(result, 14);  // 5 * 2 + 4 = 14
}

TEST_F(ExampleClassTest, ProcessWithDifferentValues) {
  ExampleClass obj("ab");  // length = 2
  EXPECT_EQ(obj.process(0), 2);   // 0 * 2 + 2 = 2
  EXPECT_EQ(obj.process(10), 22); // 10 * 2 + 2 = 22
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
