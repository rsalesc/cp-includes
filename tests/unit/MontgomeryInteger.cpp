#include "../../MontgomeryInteger.cpp"
#include "../catch.hpp"

using namespace lib;

using mint = MontNTT;
using mint17 = Mont32<17>;

TEST_CASE("addition") {
  WHEN("using NTT mod") {
    mint a = 3;
    mint b = 5;

    REQUIRE(8 == (a + b).get());
  }
  WHEN("using 17 mod") {
    mint17 a = 12;
    mint17 b = 10;

    REQUIRE(5 == (a + b).get());
  }
}

TEST_CASE("multiplication") {
  WHEN("using NTT mod") {
    mint a = 10;
    mint b = 30;

    REQUIRE(300 == (a * b).get());
  }
  WHEN("using 17 mod") {
    mint17 a = 5;
    mint17 b = 4;

    REQUIRE(3 == (a * b).get());
  }
}

TEST_CASE("power") {
  WHEN("using 17 mod") {
    mint17 a = 2;

    REQUIRE(15 == (a ^ 5).get());
  }
}