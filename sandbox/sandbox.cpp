#include "object-oriented-cpp-labs/tmp.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
  int a = 2, b = 3;
  if (argc == 3) {
    a = std::atoi(argv[1]);
    b = std::atoi(argv[2]);
  }
  std::cout << tmp::add(a, b) << "\n";
  return 0;
}
