#include <test.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Vector addition works", "[vector]")
{
  std::vector<double> a = { 1, 2, 3 };
  std::vector<double> b = { 1, 2, 3 };
  auto a_plus_b = cpptest::addVectors(a, b);

  REQUIRE(a_plus_b[0] == 2);
}
