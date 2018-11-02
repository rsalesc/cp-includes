#include <bits/stdc++.h>
#include "../../Lagrange.cpp"
#include "../../ModularInteger.cpp"

using namespace std;
const int MOD = (int)1e9+7;
using Field = lib::Mint32<MOD>;

lib::linalg::PrefixLagrange<Field> lagrange;

const int N = 3010;
int n;
Field dp[N][N];
vector<int> adj[N];

void dfs(int u) {
  for(int i = 0; i <= n; i++) dp[u][i] = 1;
  for(int v : adj[u]) {
    dfs(v);
    Field acc = 0;
    for(int i = 0; i <= n; i++) {
      acc += dp[v][i];
      dp[u][i] *= acc;
    }
  }
}

int32_t main() {
  int X;
  cin >> n >> X;

  for(int i = 1; i < n; i++) {
    int p; cin >> p;
    --p;
    adj[p].push_back(i);
  }

  dfs(0);
  vector<Field> p(n + 1);
  p[0] = dp[0][0];
  for(int i = 1; i <= n; i++) p[i] = p[i-1] + dp[0][i];
  cout << lagrange.eval(p, --X) << endl;
}
