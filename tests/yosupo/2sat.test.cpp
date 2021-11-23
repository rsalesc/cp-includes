#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <bits/stdc++.h>
#include "TwoSat.cpp"
#define int long long
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

using namespace lib;

int32_t main(){
    // Scanner sc(stdin);
    // Printer pr(stdout);
    iopt;
    string _;
    int n, m;
    cin >> _ >> _ >> n >> m;

    graph::TwoSat sat(n + 1);

    for(int i = 0; i < m; i++) {
      int a, b, _;
      cin >> a >> b >> _;
      sat.or_clause(VAR(a), VAR(b));
    }

    if(!sat.solve()) {
      cout << "s UNSATISFIABLE" << endl;
      return 0;
    }
    cout << "s SATISFIABLE" << endl;
    cout << "v ";
    for(int i = 1; i <= n; i++) {
      if(sat.get(i)) cout << i << " ";
      else cout << -i << " ";
    }
    cout << 0 << endl;
}
