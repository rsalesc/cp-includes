#include "../../LongMultiplication.cpp"
#include "../../PolynomialRing.cpp"
#include <bits/stdc++.h>

using namespace std;
using namespace lib;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<long double> a(n + 1), b(n + 1);
    for (int i = n; i >= 0; i--)
      cin >> a[i];
    for (int i = n; i >= 0; i--)
      cin >> b[i];

    vector<long double> res = math::FastMultiplication()(a, b);
    for (int i = 2 * n; i >= 0; i--) {
      cout << (long long)(res[i] + 0.5);
      if (i)
        cout << " ";
    }
    cout << endl;
  }
}
