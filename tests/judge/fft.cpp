#include <bits/stdc++.h>
#include "../../PolynomialRing.cpp"
#include "../../PowerSeries.cpp"

using namespace std;
using namespace lib;

const int MOD = (int)1e9+7;
using Poly = math::Polynomial<Mint64<MOD>, math::poly::NaiveMultiplication>;

int main() {
  Poly a = {0, 3};
  Poly b = {5, 7};
  Poly w = {4, 1, -3, -1, 2, 1, -1, 1};
  Poly y = {3, 5, 6, 1};
  Poly wr = w.reciprocal().inverse();

  cout << "inverse" << endl;
  cout << w << " " << wr << endl;
  cout << w*wr << endl;

  cout << "multiplication" << endl;
  cout << a << endl;
  cout << b << endl;
  cout << a*b << endl;

  cout << "division" << endl;
  //auto p = Poly::divmod(Poly(1) << 14, w.reciprocal());
  //coutn<< p.first << endl;

  auto root = Poly::from_root(-2);
  auto p = Poly::divmod(y, root);
  cout << y << endl;
  cout << p.first << " " << p.second << " " << (p.first * root + p.second) << endl;

  auto pq = Poly::power(a, 4, Poly({1, 1}));
  cout << pq << endl;

  cout << "integral" << endl;
  cout << w << endl;
  cout << y.integral() << endl;
  cout << y.derivative() << endl;

  cout << "series" << endl;
  cout << series::power(Poly(31), 2, 1) << endl;
  cout << series::power(root, 1023912, 4) << " " << Poly::power(root, 1023912, 4) << endl;
  auto pw = 10293109239012;
  assert(series::power(w, pw, 50) == Poly::power(w, pw, 50));
}
