#include <bits/stdc++.h>
#include "../../SegtreeNormal.cpp"
#include "../../SegtreePersistent.cpp"

using namespace std;
using namespace lib;
using namespace lib::seg;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  auto seg = SegtreeNormal<int, SumFolder<int>, Persistent<int>>(make_builder(a));

  int q;
  cin >> q;

  vector<decltype(seg)::vnode> versions;
  versions.push_back(seg.root());

  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int v, pos, x;
      cin >> v >> pos >> x;
      --pos;

      seg.update_element(versions[v], pos, AddUpdater<int>(x));
      versions.push_back(seg.root());
    } else {
      int v, l, r;
      cin >> v >> l >> r;
      --l, --r;
      cout << seg.query<int>(versions[v], l, r, SumFolder<int>()) << endl;
    }
  }
}
