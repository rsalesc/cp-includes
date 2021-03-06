#include "../../ModularInteger.cpp"
#include "../../PolynomialRing.cpp"
#include "../../FFT.cpp"
#include "../../NTT.cpp"
#include "../../LongMultiplication.cpp"
#include "../../polynomial/MultipointEvaluation.cpp"
#include "../../Lagrange.cpp"

#include "stress.cpp"

using namespace lib;
using namespace lib::linalg;
using namespace lib::math;

TEST_CASE_METHOD(StressTestFixture, "multiplication with 1e9+7 mod", "[polynomial]") {
    const static int n = (int)1e4;
    const static int MOD = (int)1e9+7;
    using Field = Mint32<MOD>;
    using Poly = Polynomial<Field, SafeMultiplication>;
    using Naive = Polynomial<Field, NaiveMultiplication>;

    STRESS(10) {
        auto v = Array::random(n, MOD);
        vector<Field> a(v.begin(), v.end());
        Poly p = a;
        Naive p_naive = a;

        p *= p;
        p_naive *= p_naive;

        REQUIRE_THAT(p.data(), Catch::Equals(p_naive.data()));
    }
}

TEST_CASE_METHOD(StressTestFixture, "multiplication with NTT mod", "[polynomial]") {
    const static int n = (int)1e3;
    using Field = MintNTT;
    using Poly = Polynomial<Field, NTTMultiplication>;
    using Naive = Polynomial<Field, NaiveMultiplication>;

    STRESS(10) {
        auto v = Array::random(n, int(Field::mod));
        vector<Field> a(v.begin(), v.end());
        Poly p = a;
        Naive p_naive = a;

        p *= p;
        p_naive *= p_naive;

        REQUIRE_THAT(p.data(), Catch::Equals(p_naive.data()));
    }
}

TEST_CASE_METHOD(StressTestFixture, "chirp-z with mod 1e9+7", "[polynomial]") {
    const static int n = 500;
    const static int K = 1000;
    const static int MOD = (int)1e9+7;
    using Field = Mint32<MOD>;
    using Poly = Polynomial<Field, SafeMultiplication>;

    STRESS(10) {
        auto v = Array::random(n, MOD);
        auto z = rnd.next(MOD);
        vector<Field> a(v.begin(), v.end());
        Poly p = a;

        vector<Field> ans = p.czt(z, K);
        vector<Field> ans_naive(K);
        for(int i = 0; i < K; i++)
            ans_naive[i] = p(Field(z) ^ i);

        REQUIRE_THAT(ans, Catch::Equals(ans_naive));
    }
}

TEST_CASE_METHOD(StressTestFixture, "multipoint evaluation with mod 1e9+7", "[polynomial]") {
    const static int n = 500;
    const static int K = 1000;
    const static int MOD = (int)1e9+7;
    using Field = Mint32<MOD>;
    using Poly = Polynomial<Field, SafeMultiplication>;

    STRESS(10) {
        auto v = Array::random(n, MOD);
        auto z = Array::random(K, MOD);
        vector<Field> a(v.begin(), v.end());
        Poly p = a;

        MultipointEvaluation<Poly> me(z);
        auto ans = me.eval(p);
        vector<Field> ans_naive(K);
        for(int i = 0; i < K; i++)
            ans_naive[i] = p(z[i]);

        REQUIRE_THAT(ans, Catch::Equals(ans_naive));
    }
}

TEST_CASE_METHOD(StressTestFixture, "interpolation with mod 1e9+7", "[polynomial]") {
    const static int n = 500;
    const static int K = 1000;
    const static int MOD = (int)1e9+7;
    using Field = Mint32<MOD>;
    using Poly = Polynomial<Field, SafeMultiplication>;

    STRESS(10) {
        auto v = Array::random(n, MOD);
        auto z = Array::random(K, MOD);
        vector<Field> a(v.begin(), v.end());
        Poly p = a;

        MultipointEvaluation<Poly> me(z);
        auto ans_mid = me.eval(p);
        auto ans = me.interp(ans_mid.begin(), ans_mid.end());

        REQUIRE_THAT(ans.p, Catch::Equals(a));
    }
}

TEST_CASE_METHOD(StressTestFixture, "lagrange iota with mod 1e9+7", "[polynomial]") {
    const static int n = 500;
    const static int MOD = (int)1e9+7;
    using Field = Mint32<MOD>;
    using Poly = Polynomial<Field, NaiveMultiplication>;

    STRESS(5) {
        auto v = Array::random(n, MOD);
        vector<Field> a(v.begin(), v.end());
        Poly p = a;

        vector<Field> z(n);
        iota(z.begin(), z.end(), 0);

        vector<Field> ans_mid(n);
        for(int i = 0; i < n; i++) ans_mid[i] = p.eval(i);

        auto N = rnd.next((long long)1e18);
        auto ans = linalg::lagrange_iota(ans_mid, N);
        auto expected = p.eval(N);

        REQUIRE(expected == ans);
    }
}