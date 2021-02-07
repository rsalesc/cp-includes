#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include <bits/stdc++.h>
#include "PowerSeries.cpp"
#include "PolynomialRing.cpp"
#include "ModularInteger.cpp"
#include "FHT.cpp"
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

    int n, T;
    cin >> n >> T;
    vector<int> v;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      v.pb(x);
    }

    poly p = series::ln_1px<poly>(v, T + 1);
    
    p = series::exp(p, T + 1);
    for(int i = 1; i <= T; i++) cout << p[i] << " ";
    cout << endl;
    return 0;
}
