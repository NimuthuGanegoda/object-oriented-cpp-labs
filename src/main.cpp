#include "object-oriented-cpp-labs/tmp.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char** argv) {
  if (argc == 3) {
    char* end1 = nullptr;
    char* end2 = nullptr;
    long a = std::strtol(argv[1], &end1, 10);
    long b = std::strtol(argv[2], &end2, 10);
    if ((end1 && *end1 == '\0') && (end2 && *end2 == '\0')) {
      int result = tmp::add(static_cast<int>(a), static_cast<int>(b));
      std::cout << result << "\n";
      return 0;
    } else {
      std::cerr << "Invalid arguments. Usage: object-oriented-cpp-labs <int a> <int b>\n";
      return 2;
    }
  }

  int a = 2;
  int b = 3;
  int result = tmp::add(a, b);
  std::cout << "tmp::add(" << a << ", " << b << ") = " << result << "\n";
  return result == 5 ? 0 : 1;
}
