#include "../../Lambda.cpp"
#include "../catch.hpp"

using namespace lib;
using namespace lib::lambda;

TEST_CASE("lambda map", "[lambda]") {
  SECTION("test vector map") {
    vector<string> vs = {"a", "b", "c", "d"};
    Map<string> m = [&](int i) -> string {
      return vs[i] + vs[i];
    };
    vector<string> res;
    for(int i = 0; i < vs.size(); i++) {
      res.push_back(m(i));
    }
    vector<string> expected = {"aa", "bb", "cc", "dd"};
    REQUIRE_THAT(expected, Catch::Equals(res));
  }

  SECTION("test sized map") {
    vector<string> vs = {"a", "b", "c", "d"};
    SubsetMap<string> m(vs.size(), [&](int i) -> string {
      return vs[i] + vs[i];
    });
    vector<string> res = m();
    vector<string> expected = {"aa", "bb", "cc", "dd"};
    REQUIRE_THAT(expected, Catch::Equals(res));
  }

  SECTION("test conversion") {
    std::function<int(int)> f = Map<int>([](int i) { return i%2; });
    REQUIRE(f(42) == 0);
    REQUIRE(f(43) == 1);
    f = SubsetMap<int>(50, [](int i) { return i%2; });
    REQUIRE(f(42) == 0);
    REQUIRE(f(43) == 1);
  }
}

TEST_CASE("lambda filter", "[lambda]") {
  Filter f = [](int i) {
    return i % 2;
  };
  SECTION("test vector filter") {
    vector<int> vs = {10, 20, 30, 40, 50};
    vector<int> expected = {20, 40};
    REQUIRE_THAT(expected, Catch::Equals(f(vs)));
    REQUIRE_THAT(expected, Catch::Equals(f(vs.begin(), vs.end())));
  }
  SECTION("test subset filter") {
    vector<int> vs = {10, 20, 30, 40, 50};
    auto fs = f.subset(vs.size(), [&](int i) {
      return vs[i] * 2;
    });
    vector<int> expected = {40, 80};
    REQUIRE_THAT(expected, Catch::Equals(fs()));
    REQUIRE(fs(0) == 40);
    REQUIRE(fs(1) == 80);
  }
  SECTION("test subset negation") {
    vector<int> vs = {10, 20, 30, 40, 50};
    auto fs = !SubsetFilter(vs.size(), f);
    vector<bool> expected = {1, 0, 1, 0, 1};
    REQUIRE_THAT(expected, Catch::Equals(fs()));

    auto ff = fs.subset(vs.size(), [&](int i) {
      return vs[i] * 2;
    });

    vector<int> expected2 = {20, 60, 100};
    REQUIRE_THAT(expected2, Catch::Equals(ff()));
  }
}