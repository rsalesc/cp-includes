#include "../../PolynomialRing.cpp"
#include "../../FFT.cpp"
#include "../../ModularInteger.cpp"
#include "../../NTT.cpp"
#include "../../FHT.cpp"
#include "../../LongMultiplication.cpp"
#include "../../ModularInteger.cpp"
#include "../../polynomial/MultipointEvaluation.cpp"
#include "../catch.hpp"

using namespace lib;
using namespace lib::math;
using namespace lib::linalg;

TEST_CASE("fast multipoint evaluation", "[polynomial]") {
  using Field = Mint64<(int)1e9 + 7>;
  using Poly = Polynomial<Field, SafeMultiplication, poly::DefaultDivmod>;
  Poly p = {0, 1, 3};

  vector<Field> w = {0, 2, 4, 6};

  MultipointEvaluation<Poly> me(w);
  auto res = me.eval(p);

  vector<Field> naive_res(w.size());
  for (int i = 0; i < w.size(); i++)
    naive_res[i] = p(w[i]);

  REQUIRE_THAT(res, Catch::Equals(naive_res));
}

TEST_CASE("fast interpolation", "[polynomial]") {
  using Field = MintNTT;
  using Poly = Polynomial<Field, NTTMultiplication, poly::DefaultDivmod>;
  Poly p = {0, 1, 3};

  vector<Field> w = {0, 2, 4};

  MultipointEvaluation<Poly> me(w);
  auto res_mid = me.eval(p);
  auto res = me.interp(res_mid.begin(), res_mid.end());

  REQUIRE_THAT(res.p, Catch::Equals(p.p));
}

TEST_CASE("Polynomial<MintNTT> fast multiplication", "[polynomial]") {
  using Poly = Polynomial<MintNTT, NTTMultiplication>;
  Poly p = {0, 1, 3, 5, 7, 9, 11};
  Poly q = {1, 3, 5, 11, 13};

  auto r1 = p * q;

  using Poly2 = Polynomial<MintNTT, NaiveMultiplication>;
  Poly2 a = {0, 1, 3, 5, 7, 9, 11};
  Poly2 b = {1, 3, 5, 11, 13};

  auto r2 = a * b;

  REQUIRE_THAT(r1.p, Catch::Equals(r2.p));
}

TEST_CASE("Polynomial<double> fast multiplication", "[polynomial]") {
  using Poly = Polynomial<double, FFTMultiplication>;
  Poly p = {0, 1, 3, 5, 7, 9, 11};
  Poly q = {1, 3, 5, 11, 13};

  auto r1 = p * q;

  using Poly2 = Polynomial<double, NaiveMultiplication>;
  Poly2 a = {0, 1, 3, 5, 7, 9, 11};
  Poly2 b = {1, 3, 5, 11, 13};

  auto r2 = a * b;

  REQUIRE_THAT(r1.p, Catch::Approx(r2.p).margin(1e-9));
}


TEST_CASE("chirp-z transform", "[polynomial]") {
  using Field = Mint32<(int)1e9+7>;
  using Poly = Polynomial<Field, NaiveMultiplication>;

  const int z = 2;
  const int n = 5;

  Poly p = {1, 2, 3};
  auto r1 = p.czt(z, n);

  vector<Field> r2(n);
  for(int i = 0; i < n; i++) {
    r2[i] = p(power(Field(z), i));
  }
  REQUIRE_THAT(r1, Catch::Equals(r2));
}

TEST_CASE("Polynomial<MintNTT> FHT multiplication", "[polynomial]") {
  using Poly = Polynomial<MintNTT, FHTMultiplication>;
  Poly p = {0, 1, 3, 5, 7, 9, 11};
  Poly q = {1, 3, 5, 11, 13};

  auto r1 = p * q;

  using Poly2 = Polynomial<MintNTT, NaiveMultiplication>;
  Poly2 a = {0, 1, 3, 5, 7, 9, 11};
  Poly2 b = {1, 3, 5, 11, 13};

  auto r2 = a * b;

  REQUIRE_THAT(r1.p, Catch::Equals(r2.p));
}