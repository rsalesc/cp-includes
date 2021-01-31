#include <bits/stdc++.h>
#include "../../matroid/MatroidIntersection.cpp"
#include "../../matroid/CographicMatroid.cpp"
#include "../../matroid/Compose.cpp"
#define int long long

using namespace std;
using namespace lib;

struct Edge {
  int u, v, w, color;
};

vector<Edge> edges;
int n, m;

matroid::Filter<CographicMatroid> build_comatroid(int vis) {
  lambda::Filter filter = [vis](int i) -> bool {
    return edges[i].color & vis;
  };
  auto edges_fn = [](int i) {
    return make_pair(edges[i].u, edges[i].v); 
  };
  CographicMatroid mat(n, filter.subset(edges.size(), edges_fn));
  return matroid::make_filter(mat, filter);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  int sum = 0;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    char c;
    cin >> u >> v >> w >> c;
    --u, --v;
    int color;
    if(c == 'R') color = 1;
    if(c == 'B') color = 2;
    if(c == 'G') color = 3;
    edges.push_back({u, v, w, color});
    sum += w;
  }

  auto m1 = build_comatroid(1);
  auto m2 = build_comatroid(2);
  auto mi = make_weighted_matroid_intersection<int>(m, m1, m2, [](int i) {
    return edges[i].w;
  });
  vector<int> ans(m + 1, -1);
  for(int k = m; k >= 1; k--) {
    ans[k] = sum - mi->cost();
    if(!mi->augment()) break;
  }

  for(int i = 1; i <= m; i++) cout << ans[i] << endl;
}
