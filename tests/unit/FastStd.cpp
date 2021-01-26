#include "../../utils/FastAdj.cpp"
#include "../../utils/FastQueue.cpp"
#include "../catch.hpp"

using namespace lib;

TEST_CASE("fast queue", "[fast_queue]") {
  SECTION("overall test") {
    FastQueue<int> q(10);
    q.push(5);
    q.push(3);
    q.push(1);
    REQUIRE(q.size() == 3);
    REQUIRE(q.front() == 5);
    REQUIRE(q.pop() == 5);
    q.push(2);
    std::vector<int> v;
    while(!q.empty()) v.push_back(q.pop());

    std::vector<int> expected = {3, 1, 2};
    REQUIRE_THAT(expected, Catch::Equals(v));
  }
}

TEST_CASE("fast adj", "[fast_adj]") {
  auto adj = FastAdj<int>(3, 10);
  adj.add(0) = 1;
  adj.add(1) = 2;
  adj.add(0, 2);
  adj.add(2, 0);
  REQUIRE(adj.size() == 3);
  REQUIRE(adj.edge_size() == 4);
  vector<vector<int>> v;
  for(int i = 0; i < 3; i++) {
    auto ite = adj.n_edges(i);
    v.push_back(vector<int>(ite.begin(), ite.end()));
  }

  vector<vector<int>> expected = {
    {2, 1},
    {2},
    {0}
  };
  REQUIRE_THAT(expected, Catch::Equals(v));
}