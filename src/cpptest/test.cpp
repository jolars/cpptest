#include "test.hpp"

namespace cpptest {

std::vector<double>
addVectors(const std::vector<double>& a, const std::vector<double>& b)
{
  std::vector<double> out;

  for (int i = 0; i < a.size(); ++i) {
    out[i] += a[i] + b[i];
  }

  return out;
}

}
