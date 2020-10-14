#include "../catch.hpp"
#include "../../FFT.cpp"
#include "../../ModularInteger.cpp"
#include "../../LongMultiplication.cpp"
#include "../../PolynomialRing.cpp"
#include "../../polynomial/MultipointEvaluation.cpp"

using namespace lib;
using namespace lib::math;
using namespace lib::linalg;

TEST_CASE("fast multipoint evaluation") {
    using Field = Mint64<(int)1e9+7>;
    using Poly = Polynomial<Field, SafeMultiplication, poly::DefaultDivmod>;
    Poly p = {0, 1, 3};

    vector<Field> w = {0, 2, 4, 6};
    
    MultipointEvaluation<Poly> me(w);
    auto res = me.eval(p);

    vector<Field> naive_res(w.size());
    for(int i = 0; i < w.size(); i++)
        naive_res[i] = p(w[i]);

    REQUIRE_THAT(res, Catch::Equals(naive_res));
}

TEST_CASE("Polynomial<double> fast multiplicaton") {
    using Poly = Polynomial<double, FFTMultiplication>;
    Poly p = {0, 1, 3, 5, 7, 9, 11};
    Poly q = {1, 3, 5, 11, 13};

    auto r1 = p*q;

    using Poly2 = Polynomial<double, NaiveMultiplication>;
    Poly2 a = {0, 1, 3, 5, 7, 9, 11};
    Poly2 b = {1, 3, 5, 11, 13};

    auto r2 = a*b;

    REQUIRE_THAT(r1.p, Catch::Approx(r2.p).margin(1e-9));
}