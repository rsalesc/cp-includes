#include <bits/stdc++.h>
#include "matroid/v2/MatroidIntersection.cpp"
#include "matroid/v2/BinaryMatroid.cpp"
#include "matroid/v2/ColorMatroid.cpp"
#include "matroid/v2/ContractionMatroid.cpp"

#define int long long

using namespace std;
using namespace lib;

int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0);

  vector<uint64_t> bs;
  int n;
  cin >> n;

  vector<int32_t> color, limits;
  limits.push_back(n);
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    bs.push_back(x);
    color.push_back(0);
  }

  int m; cin >> m;

  for(int i = 1; i <= m; i++) {
    int K; cin >> K;
    limits.push_back(1);
    for(int j = 0; j < K; j++) {
      int x; cin >> x;
      color.push_back(i);
      bs.push_back(x);
    }
  }
  
  auto color_fn = lambda::from_vector(color);
  ColorMatroid m1(limits, color_fn);

  auto bit_fn = lambda::from_vector(bs);
  BinaryMatroid<> m2(bit_fn);

  auto mi = make_matroid_intersection(m2, m1);
  mi->solve();
  if(mi->cardinality() != n+m)
    cout << -1 << endl;
  else {
    for(int i = n; i < color.size(); i++) {
      if(mi->in_I(i)) {
        cout << bs[i] << endl;
      }
    }
  }
}