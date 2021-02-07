#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include <bits/stdc++.h>
#include "ModularInteger.cpp"
#include "FHT.cpp"
#include "PolynomialRing.cpp"
#include "LinearRecurrence.cpp"
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
using mint = MintNTT;
using poly = math::Polynomial<mint, FHTMultiplication>;

int32_t main(){
    // Scanner sc(stdin);
    // Printer pr(stdout);
    iopt;

    int n; cin >> n;
    vector<mint> b;

    for(int i = 0; i < n; i++) {
      mint x; cin >> x;
      b.pb(x);
    }

    linalg::BMSolver<poly> lr;
    lr.solve(b);
    cout << lr.T.size() << endl;
    for(mint x : lr.T) cout << x << " ";
    cout << endl;
    return 0;
}
