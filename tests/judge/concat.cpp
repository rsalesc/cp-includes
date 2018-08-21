#include <bits/stdc++.h>
#include "../../Graph.cpp"
#include "../../SegtreeHLD.cpp"
#include "../../SegtreeBeats.cpp"

using namespace std;
using namespace lib;
using lib::graph::Graph;
using lib::graph::HLD;
using lib::seg::SegtreeBeats;

struct Node {
  int mx = 0, lz = 0;
  Node() {}
  Node(int mx) : mx(mx) {}
  operator int() const { return mx; }
  Node& operator+=(const int rhs) {
    lz += rhs;
    return *this;
  }
  Node operator+(const Node& rhs) const {
    return Node(max(mx, rhs.mx));
  }
};

struct Pushdown {
  void operator()(Node& no, int l, int r, Node* lf, Node* rt) const {
    if(no.lz != 0) {
      no.mx += no.lz;
      if(l != r) {
        lf->lz += no.lz;
        rt->lz += no.lz;
      }
      no.lz = 0;
    }
  }
};

void solve() {
  int n;
  cin >> n;

  Graph<> g(n);
  for(int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g.add_2edge(x, y);
  }

  auto f = graph::builders::make_rooted_forest(g, {0});
  auto hld = graph::make_range_hld<SegtreeBeats<Node, seg::CombineFolder<Node>, Pushdown>>(f);

  int Q;
  cin >> Q;
  while(Q--) {
    string t;
    cin >> t;
    if(t == "add") {
      int u, x;
      cin >> u >> x; u--;
      auto updater = seg::AddUpdater<int>(x);
      hld.update_subtree(u, updater);
    } else {
      int x, y;
      cin >> x >> y;
      x--, y--;
      auto folder = seg::MaxFolder<int>();
      cout << hld.query_path<int>(x, y, folder) << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

