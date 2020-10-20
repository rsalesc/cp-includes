#include "../../LinearProgram.cpp"
#include "../catch.hpp"

using namespace lib;

TEST_CASE("simplex maximization", "[simplex]") {
  auto a = Variable<double>::get_variable();
  auto b = Variable<double>::get_variable();
  auto c = Variable<double>::get_variable();

  LinearProgram<double> lp;
  lp.add_constraint(a + b <= make_exp<double>(10.0));
  lp.add_constraint(make_exp<double>(a) >= make_exp<double>(c));

  auto result = lp.maximize(c);

  REQUIRE(result[c] == Approx(10.0));
}

TEST_CASE("simplex minimization", "[simplex]") {
  auto a = Variable<double>::get_exp_variable();
  auto b = Variable<double>::get_exp_variable();
  auto c = Variable<double>::get_exp_variable();

  LinearProgram<double> lp;
  lp.add_constraint(b >= c + 1.0);
  lp.add_constraint(a >= b + 1.0); // -a <= -b - 1  ->   -a+b <= -1

  auto result = lp.minimize(c);

  REQUIRE(result[a->get_variable()] == Approx(2.0));
}