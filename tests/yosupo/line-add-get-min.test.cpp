#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <bits/stdc++.h>
#include "ds/LiChaoTree.cpp"
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

struct Query {
  int type, a, b;
};

int32_t main(){
  iopt;
  
  int n, Q;
  cin >> n >> Q;

  vector<Query> queries;
  vector<int> xs;

  for(int i = 0; i < n; i++)  {
    int a, b; cin >> a >> b;
    queries.push_back({0, a, b});
  }

  for(int i = 0; i < Q; i++) {
    int t; cin >> t;
    if(t == 0) {
      int a, b; cin >> a >> b;
      queries.push_back({t, a, b});
    } else {
      int x; cin >> x;
      queries.push_back({t, x});
      xs.push_back(x);
    }
  }

  lib::LiChaoTree<int, int> t(xs);

  for(const auto& q : queries) {
    if (q.type == 0) {
      t.add([q](int x) {
        return q.a * x + q.b;
      });
    } else {
      cout << t.query(q.a) << endl;
    }
  }
}
