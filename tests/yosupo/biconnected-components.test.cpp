#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "graphs/BlockCut.cpp"
#include "Template.cpp"

using namespace lib;

int32_t main() {
  iopt;

  int n, m; cin >> n >> m;

  graph::Graph<int> g(n);

  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g.add_2edge(a, b);
  }

  auto bct = graph::make_block_cut(g);

  cout << bct.n_components() << endl;
  for(int i = 0; i < bct.n_components(); i++) {
    const auto comp = bct.component(i);
    cout << comp.size() << " ";
    for(const auto v : comp) cout << v << " ";
    cout << endl;
  }
}