#include <bits/stdc++.h>
#include "matroid/MatroidIntersection.cpp"
#include "matroid/ColorMatroid.cpp"
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ms(v, x) memset((v), (x), sizeof(v))
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define iopt ios::sync_with_stdio(false); cin.tie(0)
#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second) b = p.second
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int power(int x, int p, int MOD) {
    if(p == 0) return 1%MOD;
    if(p == 1) return x%MOD;
    int res = power(x, p/2, MOD);
    res = (long long)res*res%MOD;
    if(p&1) res = (long long)res*x%MOD;
    return res;
}
 
typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;


int32_t main() {
  iopt;
  int L, R, m;
  cin >> L >> R >> m;

  vector<pair<int, int>> v;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v.pb({a, b});
  }

  lib::ColorMatroid mL(L, 1, [v](int i) { return v[i].ff; });
  lib::ColorMatroid mR(R, 1, [v](int i) { return v[i].ss; });
  auto mi = lib::make_matroid_intersection(m, mL, mR);

  auto res = mi->solve();
  vector<int> ans;
  for(int i = 0; i < m; i++) if(res[i]) {
    ans.pb(i);
  }

  cout << ans.size() << endl;
}