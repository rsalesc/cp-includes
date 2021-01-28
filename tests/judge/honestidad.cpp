#include <bits/stdc++.h>
#include "../../matroid/MatroidIntersection.cpp"
#include "../../matroid/ColorMatroid.cpp"
#include "../../matroid/GraphicMatroid.cpp"
#define int long long

using namespace std;
using namespace lib;

struct Edge {
  int u, v, color;
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, K;
  int it = 0;
  while(cin >> n >> m >> K) {
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      --u, --v, --c;
      edges.push_back({u, v, c});
    }
    ColorMatroid m_color(K, 1, [edges](int i) { return edges[i].color; });
    GraphicMatroid m_graph(n, [edges](int i) -> pair<int, int> { return {edges[i].u, edges[i].v}; });
    auto mi = make_matroid_intersection(m, m_color, m_graph);
    auto res = mi->solve();
    cout << "Instancia " << ++it << endl;
    if(accumulate(res.begin(), res.end(), 0) >= n-1) {
      cout << "sim" << endl;
    } else {
      cout << "nao" << endl;
    }
    cout << endl;
  }
}
