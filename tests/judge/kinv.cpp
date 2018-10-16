#include <bits/stdc++.h>
#include "../../PolynomialRing.cpp"
#include "../../LongMultiplication.cpp"

using namespace std;
using namespace lib;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;

  int n = s.size();

  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) {
    if(s[i] == 'A') a[i] = 1;
    else b[i] = 1;
  }

  auto res = math::circular_conv<math::FastMultiplication>(a, b);
  for(int i = 1; i < n; i++) cout << res[i] << endl;
}
