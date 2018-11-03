#include <bits/stdc++.h>
#include "../../SegtreeNormal.cpp"
#include "../../SegtreePersistent.cpp"

using namespace std;
using namespace lib;

int32_t main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];

  seg::SegtreeNormal<int, seg::MinFolder<int>, seg::Persistent<int>> tree(seg::make_builder(p));
  seg::MinFolder<int> folder;

  int m;
  cin >> m;
  for(int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      cout << tree.query<int>(x, y, folder) << endl;
    } else {
      int idx, x;
      cin >> idx >> x;
      idx--;
      tree.update_element(idx, seg::SetUpdater<int>(x));
    }
  }
}
