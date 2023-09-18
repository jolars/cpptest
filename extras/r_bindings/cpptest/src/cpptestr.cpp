#include "Rcpp.h"
#include "cpptest/test.hpp"

// [[Rcpp::export]]
std::vector<double>
add_vectors_cpp(std::vector<double> a, std::vector<double> b)
{
  auto out = cpptest::addVectors(a, b);

  return out;
}
