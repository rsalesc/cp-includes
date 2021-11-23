#define PROBLEM "https://judge.yosupo.jp/problem/chordal_graph_recognition"

#include <bits/stdc++.h>
#include "Graph.cpp"
#include "graphs/Chordal.cpp"
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

    int n, m;
    cin >> n >> m;
    graph::Graph<> g(n);

    for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      g.add_2edge(a, b);
    }

    auto ch = graph::make_chordal(g);
    if(ch.is_valid()) {
      cout << "YES" << endl;
      for(int x : ch.order) cout << x << " ";
      cout << endl;
    } else {
      cout << "NO" << endl;
      cout << ch.induced_cycle().size() << endl;
      for(int x : ch.induced_cycle()) cout << x << " ";
      cout << endl;
    }
    return 0;
}
