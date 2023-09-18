#include "cpptest/test.hpp"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int
main()
{
  std::cout << "Let's do some vector math!" << std::endl;

  std::vector<double> a = { 1, 2, 3 };
  std::vector<double> b = { 1, 2, 3 };
  auto out = cpptest::addVectors(a, b);

  std::cout << "Vector a: ";
  for (auto a_i : a) {
    std::cout << a_i << ", ";
  }
  std::cout << std::endl;

  std::cout << "Vector b: ";
  for (auto b_i : b) {
    std::cout << b_i << ", ";
  }
  std::cout << std::endl;

  std::cout << "a + b: ";
  for (auto out_i : out) {
    std::cout << out_i << ", ";
  }
  std::cout << std::endl;

  return 0;
}
