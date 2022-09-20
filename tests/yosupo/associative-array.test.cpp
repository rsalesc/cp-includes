#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "Template.cpp"
#include "FastMap.cpp"

int32_t main() {
  iopt;

  lib::FastMap<int, int> st;

  int n; cin >> n;

  for(int i = 0; i < n; i++) {
    int t, k; cin >> t >> k;
    if (t == 0) {
      int v;
      cin >> v;
      st[k] = v;
    } else {
      cout << st[k] << endl;
    }
  }
}
