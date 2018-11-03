#include <bits/stdc++.h>
#include "../../SegtreeNormal.cpp"
#include "../../SegtreePersistent.cpp"

using namespace std;
using namespace lib;
using namespace lib::seg;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  auto seg = SegtreeNormal<int, SumFolder<int>, Persistent<int>>(ImplicitBuilder((int)-1e9, (int)1e9));

  vector<decltype(seg)::vnode> versions;
  versions.push_back(seg.root());

  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    seg.update_element(x, AddUpdater<int>(1));
    versions.push_back(seg.root());
  }

  while(q--) {
    int a, b, k;
    cin >> a >> b >> k;

    auto check = [&](int mid) {
      int res = seg.query<int>(versions[b], seg.L, mid, SumFolder<int>());
      res -= seg.query<int>(versions[a-1], seg.L, mid, SumFolder<int>());
      return res;
    };

    int l = (int)-1e9, r = (int)1e9;
    while(l < r) {
      int mid = l + (r-l)/2;
      if(check(mid) >= k)
        r = mid;
      else l = mid+1;
    }

    cout << l << endl;
  }
}
