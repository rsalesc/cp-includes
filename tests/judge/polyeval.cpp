#include <bits/stdc++.h>
#include "../../ModularInteger.cpp"
#include "../../LongMultiplication.cpp"
#include "../../FFT.cpp"
#include "../../PolynomialRing.cpp"
#include "../../polynomial/MultipointEvaluation.cpp"

using namespace std;
using namespace lib;

typedef long long ll;

const int MOD = (int)1e9+7;
using Field = Mint32<MOD>;
using Poly = math::Polynomial<Field, math::FastMultiplication>;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    vector<Field> v(n+1);
    for(int i = 0; i < n+1; i++)
    cin >> v[i];

    Poly p = v;

    int q; cin >> q;
    vector<Field> qrs(q);
    for(int i = 0; i < q; i++) cin >> qrs[i];

    math::MultipointEvaluation<Poly> me(qrs);
    auto res = me.eval(p);

    for(auto x : res) {
        cout << x << "\n";
    }
}
