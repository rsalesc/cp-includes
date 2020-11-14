#include "../../VectorN.cpp"
#include "../catch.hpp"

using namespace lib;

TEST_CASE("VectorN addition") {
  using Vec = VectorN<int>;
  WHEN("|a| == |b|") {
    Vec a = {1, 3, 5};
    Vec b = {2, 4, 6};
    Vec expected = {3, 7, 11};

    REQUIRE(expected == a + b);
  }
  WHEN("|a| > |b|") {
    Vec a = {1, 3, 5, 11};
    Vec b = {2, 4, 6};
    Vec expected = {3, 7, 11, 11};

    REQUIRE(expected == a + b);
  }
  WHEN("|a| < |b|") {
    Vec a = {1, 3, 5};
    Vec b = {2, 4, 6, 13};
    Vec expected = {3, 7, 11, 13};

    REQUIRE(expected == a + b);
  }
}

TEST_CASE("VectorN multiplication") {
  using Vec = VectorN<int>;
  WHEN("|a| == |b|") {
    Vec a = {1, 3, 5};
    Vec b = {2, 4, 6};
    Vec expected = {2, 12, 30};

    REQUIRE(expected == a * b);
  }
  WHEN("|a| > |b|") {
    Vec a = {1, 3, 5, 7, 11};
    Vec b = {2, 4, 6};
    Vec expected = {2, 12, 30, 0, 0};

    REQUIRE(expected == a * b);
  }
}

TEST_CASE("VectorN addition in-place") {
  using Vec = VectorN<int>;
  Vec a = {1, 3, 5};
  Vec b = {2, 4, 6};
  Vec expected = {3, 7, 11};
  a += b;

  REQUIRE(expected == a);
}

TEST_CASE("VectorN addition with literal") {
  using Vec = VectorN<int>;
  Vec a = {1, 3, 5};
  Vec expected = {3, 5, 7};

  REQUIRE(expected == a + 2);
}

TEST_CASE("VectorN xor with literal") {
  using Vec = VectorN<int>;
  Vec a = {1, 3, 5};
  Vec expected = {3, 1, 7};

  REQUIRE(expected == (a ^ 2));
}

TEST_CASE("VectorN negation") {
  using Vec = VectorN<int>;
  Vec a = {1, 3, 5};
  Vec expected = {-1, -3, -5};

  REQUIRE(expected == -a);
}