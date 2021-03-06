#include <bits/stdc++.h>
#include "../../SegtreeNormal.cpp"
#include "../../SegtreePersistent.cpp"

using namespace std;
using namespace lib;

int32_t main() {
  int n, m;
  cin >> n >> m;

  seg::ImplicitBuilder builder(0, 2 * n - 1);
  seg::SegtreeNormal<int, seg::SumFolder<int>, seg::Persistent<int>> tree(builder);
  seg::SumFolder<int> folder;

  for(int i = 0; i < m; i++) {
    char t;
    cin >> t;
    if(t == '?') {
      int x, y;
      cin >> x >> y;
      x--, y--;
      if(x > y) y += n;
      cout << tree.query<int>(x, y, folder) << endl;
    } else {
      int idx, x;
      cin >> idx >> x;
      idx--;
      tree.update_element(idx, seg::AddUpdater<int>(x));
      tree.update_element(idx + n, seg::AddUpdater<int>(x));
    }
  }
}
