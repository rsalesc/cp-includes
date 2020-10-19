#include <bits/stdc++.h>
#include "../../ModularInteger.cpp"
#include "../../LongMultiplication.cpp"
#include "../../FFT.cpp"
#include "../../PolynomialRing.cpp"

using namespace std;
using namespace lib;

typedef long long ll;

const int MOD = 786433;
//const int MOD = (int)1e9+7;
using Field = Mint32<MOD>;
using Poly = math::Polynomial<Field, math::SafeMultiplication>;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    vector<Field> v(n+1);
    for(int i = 0; i < n+1; i++)
        cin >> v[i];

    Poly p = v;

    vector<Field> z = p.czt(10, MOD);
    vector<Field> ans(MOD);

    ans[0] = v[0];
    Field acc = 1;
    for(int i = 0; i < MOD; i++) {
        ans[(int)acc] = z[i];
        acc *= 10;
    }

    int q;
    cin >> q;

    while(q--) {
        int x; cin >> x;
        cout << ans[x] << "\n";
    }
}
