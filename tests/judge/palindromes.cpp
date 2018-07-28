#include <bits/stdc++.h>
#include "../../RollingHash.cpp"

using namespace std;
using namespace lib;

using Roll = hashing::DefaultProvider::Roll;
using Hash = hashing::DefaultProvider::Hash;
hashing::BiDefaultProvider rk;

int cnt[5005][5005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;

  auto r = rk(s);
  for(int l = 1; l <= s.size(); l++) {
    for(int j = l; j <= s.size(); j++) {
      auto p = r(j-l, j-1);
      if(p.first == p.second)
        cnt[j-l][j-1]++;
      cnt[j-l][j-1] += cnt[j-l+1][j-1];
      cnt[j-l][j-1] += cnt[j-l][j-2];
      cnt[j-l][j-1] -= cnt[j-l+1][j-2];
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    cout << cnt[i][j] << "\n";
  }
}
