#include <bits/stdc++.h>
#include "../../ModularInteger.cpp"

using namespace std;
using namespace lib;

const int MOD = (int)1e9+7;
typedef Mint32<MOD> mint;

int32_t main() {
  mint n;
  int L;

  while(cin >> n >> L, L) {
    cout << n*((n^L) - 1)/(n-1) << endl;
  }
}
