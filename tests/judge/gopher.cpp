#include <bits/stdc++.h>
#include "matroid/MatroidIntersection.cpp"
#include "matroid/ColorMatroid.cpp"
#include "geometry/Line2D.cpp"
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

GEOMETRY_EPSILON(LD, 1e-9);
using G = lib::geo::CartesianPlane<LD>;

int32_t main() {
  iopt;

  int L, R;
  while(cin >> L >> R) {
    int s, V;
    cin >> s >> V;

    vector<G::point> LL, RR;
    for(int i = 0; i < L; i++) {
      G::point p;
      cin >> p;
      LL.pb(p);
    }
    for(int i = 0; i < R; i++) {
      G::point p;
      cin >> p;
      RR.pb(p);
    }

    vector<pair<int, int>> v;
    for(int i = 0; i < L; i++) {
      for(int j = 0; j < R; j++) {
        if(norm(LL[i] - RR[j]) / V < (LD)s)
          v.pb({i, j});
      }
    }

    lib::ColorMatroid mL(L, 1, [v](int i) { return v[i].ff; });
    lib::ColorMatroid mR(R, 1, [v](int i) { return v[i].ss; });
    auto mi = lib::make_matroid_intersection(v.size(), mL, mR);

    auto res = mi->solve();
    vector<int> ans;
    for(int i = 0; i < v.size(); i++) if(res[i]) ans.pb(i);

    cout << ans.size() << endl;
  }
}
