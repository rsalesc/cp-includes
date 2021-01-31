#include <bits/stdc++.h>
#include "../../Maxflow.cpp"
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

  lib::flow::Maxflow<int> f(L + R + 2);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    f.add_edge(a, L + b, 1);
  }

  for(int i = 0; i < L; i++) f.add_edge(f.source, i, 1);
  for(int i = 0; i < R; i++) f.add_edge(L + i, f.sink, 1);

  cout << f.maxflow() << endl;
}
