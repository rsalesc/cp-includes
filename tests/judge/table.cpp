#include "../../HashMap.cpp"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e15 + 21;
const ll MAXN = 1e5 + 5;
typedef pair<ll, ll> pii;
typedef lib::GoldenMap<ll, ll> ht;

ll N, Q;
ll V[MAXN];
ll C[MAXN];
ll dp[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for (ll i = 0; i < N; i++) {
    cin >> V[i];
  }
  for (ll i = 0; i < N; i++) {
    cin >> C[i];
  }
  ht curMax;
  for (int i = 0; i < N; i++) {
    curMax[C[i]] = -INF;
  }
  for (ll i = 0; i < Q; i++) {
    for (size_t i = 0; i < curMax.cap; i++) {
      if (curMax.no[i].state == ht::State::USED) {
        curMax.no[i].value = -INF;
      }
    }
    ll a, b;
    cin >> a >> b;
    fill(dp, dp + N, -1);
    pii mx1 = {0, 1e5 + 5};
    pii mx2 = {0, 1e5 + 4};
    for (ll j = 0; j < N; j++) {
      if (mx1.second == C[j]) {
        dp[j] = mx2.first + b * V[j];
      } else {
        dp[j] = mx1.first + b * V[j];
      }
      dp[j] = max(dp[j], curMax[C[j]] + a * V[j]);
      if (dp[j] > mx1.first) {
        if (C[j] == mx1.second) {
          mx1 = {dp[j], C[j]};
        } else {
          mx2 = {mx1.first, mx1.second};
          mx1 = {dp[j], C[j]};
        }
      } else if (dp[j] > mx2.first) {
        if (C[j] == mx1.second) {
          continue;
        } else {
          mx2 = {dp[j], C[j]};
        }
      }
      curMax[C[j]] = max(curMax[C[j]], dp[j]);
    }
    cout << mx1.first << endl;
  }
}
