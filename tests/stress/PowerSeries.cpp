#include "../../ModularInteger.cpp"
#include "../../PolynomialRing.cpp"
#include "../../FFT.cpp"
#include "../../LongMultiplication.cpp"
#include "../../polynomial/MultipointEvaluation.cpp"
#include "../../PowerSeries.cpp"

#include "stress.cpp"

using namespace lib;
using namespace lib::linalg;
using namespace lib::math;

TEST_CASE_METHOD(StressTestFixture, "exp(k*log(p(x))", "[polynomial]") {
    const static int n = 1000;
    const static int K = 10;
    const static int MOD = (int)1e9+7;
    using Field = Mint32<MOD>;
    using Poly = Polynomial<Field, SafeMultiplication>;

    STRESS(5) {
        auto v = Array::random(n, MOD);
        vector<Field> a(v.begin(), v.end());
        Poly p = a;
        auto ans = series::power(p, K, n*K - (K-1));
        auto ans_naive = Poly::power(p, K, n*K - (K-1));

        REQUIRE_THAT(ans.data(), Catch::Equals(ans_naive.data()));
    }
}