#include <bits/stdc++.h>
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
#define TESTCASE(tn) cout << "Case #" << tn << ": "
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int floor2(int x, int y);
int ceil2(int x, int y) {
  if(y < 0) return ceil2(-x, -y);
  return x < 0 ? -floor2(-x, y) : (x + y - 1) / y;
}
int floor2(int x, int y) {
  if(y < 0) return floor2(-x, -y);
  return x < 0 ? -ceil2(-x, y) : x / y;
}
 
typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;

#define TC_MAIN int32_t main() { iopt; int T; cin >> T; for(int i = 1; i <= T; i++) solve(i); }