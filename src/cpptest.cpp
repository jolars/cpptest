#include "cpptest/test.hpp"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    // // report version
    // std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
    //           << Tutorial_VERSION_MINOR << std::endl;
    // std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  std::vector<double> a = { 1, 2, 3 };
  std::vector<double> b = { 1, 2, 3 };

  auto out = cpptest::addVectors(a, b);

  std::cout << "Result: ";
  for (auto out_i : out) {
    std::cout << out_i << ", ";
  }
  std::cout << std::endl;

  return 0;
}
