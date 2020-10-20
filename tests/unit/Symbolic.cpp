#include "../../Symbolic.cpp"
#include "../catch.hpp"

using namespace lib;

TEST_CASE("eval symbolic expression", "[symbolic]") {
  auto a = Variable<int>::get_variable();
  auto b = Variable<int>::get_variable();
  auto c = Variable<int>::get_variable();

  auto exp = (a * 3 + b * 2 + c) * 2;

  auto visitor = std::make_unique<EvalVisitor<int>>();
  auto result = visitor->eval(exp, {
                                       {a, 15},
                                       {b, 4},
                                       {c, 2},
                                   });

  REQUIRE(result == 110);
}