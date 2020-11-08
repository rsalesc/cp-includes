#include "../../ModularInteger.cpp"
#include "../../PolynomialRing.cpp"
#include "../../FFT.cpp"
#include "../../NTT.cpp"
#include "../../LongMultiplication.cpp"
#include "../../polynomial/MultipointEvaluation.cpp"
#include "../../PowerSeries.cpp"

#include "bench.h"

using namespace lib;
using namespace lib::linalg;
using namespace lib::math;

namespace lib::bench::PolynomialRing {

const static int MOD = (int)1e9+7;
using Field = Mint32<MOD>;
using Poly = Polynomial<Field, SafeMultiplication>;

static void BM_Polynomial_SafeMultiplication(benchmark::State& state) {
    const int n = state.range(0);
    auto v = Array::random(n, MOD);
    vector<Field> a(v.begin(), v.end());
    Poly p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(p*p);
    }
}

static void BM_Polynomial_FastMultiplication(benchmark::State& state) {
    const int n = state.range(0);
    auto v = Array::random(n, MOD);
    vector<Field> a(v.begin(), v.end());
    Polynomial<Field, FastMultiplication> p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(p*p);
    }
}

static void BM_Polynomial_NTTMultiplication(benchmark::State& state) {
    const int n = state.range(0);
    auto v = Array::random(n, int(Field::mod));
    vector<Field> a(v.begin(), v.end());
    Polynomial<Field, NTTMultiplication> p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(p*p);
    }
}


static void BM_Polynomial_Power(benchmark::State& state) {
    const int n = state.range(0);
    const int K = state.range(1);
    auto v = Array::random(n, MOD);
    vector<Field> a(v.begin(), v.end());
    Poly p = a;

    for(auto _ : state) {
        benchmark::DoNotOptimize(Poly::power(p, K, n*K - (K-1)));
    }
}

static void BM_Polynomial_Division(benchmark::State& state) {
    const int n = state.range(0);
    const int m = state.range(1);
    auto v1 = Array::random(n, MOD);
    auto v2 = Array::random(m, MOD);
    vector<Field> a(v1.begin(), v1.end()), b(v2.begin(), v2.end());
    Poly p = a;
    Poly q = b;

    for(auto _ : state) {
        benchmark::DoNotOptimize(Poly::divmod(p, q));
    }
}

static void BM_Polynomial_MultipointEvaluation(benchmark::State& state) {
    const int n = state.range(0);
    const int m = state.range(1);
    auto v1 = Array::random(n, MOD);
    auto v2 = Array::random(m, MOD);
    vector<Field> a(v1.begin(), v1.end()), b(v2.begin(), v2.end());
    Poly p = a;
    MultipointEvaluation<Poly> me(b);

    for(auto _ : state) {
        benchmark::DoNotOptimize(me.eval(p));
    }
}

static void BM_Polynomial_Interpolation(benchmark::State& state) {
    const int n = state.range(0);
    auto v1 = Array::random(n, MOD);
    vector<Field> y(v1.begin(), v1.end());
    vector<Field> x(n);
    iota(x.begin(), x.end(), 0);
    MultipointEvaluation<Poly> me(x);

    for(auto _ : state) {
        benchmark::DoNotOptimize(me.interp(y.begin(), y.end()));
    }
}

BENCHMARK(BM_Polynomial_SafeMultiplication)
    ->Arg(100000)->Arg((int)1e6)
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Polynomial_FastMultiplication)
    ->Arg((int)1e5)->Arg((int)1e6)
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Polynomial_NTTMultiplication)
    ->Arg((int)1e5)->Arg((int)1e6)
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Polynomial_Power)
    ->Args({1000, 1000})->Args({10000, 20})
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Polynomial_Division)
    ->Args({100000, 10000})
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Polynomial_MultipointEvaluation)
    ->Args({100000, 100000})
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_Polynomial_Interpolation)
    ->Arg((int)1e5)
    ->Unit(benchmark::kMillisecond);

}  // end namespace