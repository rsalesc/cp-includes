#include "../../Traits.cpp"
#include "../../traits/Tuple.cpp"
#include "../catch.hpp"

using namespace lib::traits;

TEST_CASE("find_first", "[tuple traits]") {
  REQUIRE(find_first<std::tuple<char, int>, int>::value == 1);
}