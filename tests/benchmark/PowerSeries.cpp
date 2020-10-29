#include "../../ModularInteger.cpp"
#include "../../PolynomialRing.cpp"
#include "../../FFT.cpp"
#include "../../LongMultiplication.cpp"
#include "../../polynomial/MultipointEvaluation.cpp"
#include "../../PowerSeries.cpp"

#include "bench.h"

using namespace lib;
using namespace lib::linalg;
using namespace lib::math;

namespace lib::bench::PowerSeries {

const static int MOD = (int)1e9+7;
using Field = Mint32<MOD>;
using Poly = Polynomial<Field, SafeMultiplication>;

static void BM_Series_Power(benchmark::State& state) {
    const int n = state.range(0);
    const int K = state.range(1);
    auto v = Array::random(n, MOD);
    vector<Field> a(v.begin(), v.end());
    Poly p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(series::power(p, K, n*K - (K-1)));
    }
}

static void BM_Series_Inverse(benchmark::State& state) {
    const int n = state.range(0);
    auto v = Array::random(n, MOD);
    vector<Field> a(v.begin(), v.end());
    Poly p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(series::inverse(p, n));
    }
}

static void BM_Series_Exp(benchmark::State& state) {
    const int n = state.range(0);
    auto v = Array::random(n, MOD);
    vector<Field> a(v.begin(), v.end());
    a[0] = 0; // exp needs a[0] to be zero
    Poly p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(series::exp(p, n));
    }
}

static void BM_Series_Ln(benchmark::State& state) {
    const int n = state.range(0);
    auto v = Array::random(n, MOD);
    vector<Field> a(v.begin(), v.end());
    a[0] = 1; // ln needs a[0] to be non-null
    Poly p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(series::ln(p, n));
    }
}

BENCHMARK(BM_Series_Power)
    ->Args({1000, 1000})->Args({10000, 20})
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Series_Inverse)
    ->Arg(1000)->Arg((int)1e5)
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Series_Exp)
    ->Arg((int)1e5)
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Series_Ln)
    ->Arg((int)1e5)
    ->Unit(benchmark::kMillisecond);

}  // end namespace