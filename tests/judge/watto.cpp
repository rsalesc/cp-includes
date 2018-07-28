#include <bits/stdc++.h>
#include "../../RollingHash.cpp"

using namespace std;
using namespace lib;

using Roll = hashing::DefaultProvider::Roll;
using Hash = hashing::DefaultProvider::Hash;
hashing::DefaultProvider rk;

set<Hash, Hash::less> mem;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mem.insert(rk(s).all());
  }

  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    auto r = rk(s);

    int L = r.size();
    bool good = false;

    for(int i = 0; i < L; i++) {
      Hash left = r.prefix(i);
      Hash right = r.substr(i+1);
      for(char z = 'a'; z <= 'c'; z++) {
        if(z == s[i]) continue;
        good |= mem.count(rk.cat(left, Hash(z), right));
      }
    }

    if(good) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}
