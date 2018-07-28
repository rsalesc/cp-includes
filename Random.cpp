#ifndef _LIB_RANDOM
#define _LIB_RANDOM
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace rng {
  struct Generator {
    mt19937 rng;
    Generator() {
      seed_seq seq{(uint64_t) chrono::duration_cast<chrono::nanoseconds>(
          chrono::high_resolution_clock::now().time_since_epoch()).count(),
#if __cplusplus > 201300
               (uint64_t) make_unique<char>().get(),
#else
               (uint64_t) unique_ptr<char>(new char).get(),
#endif
               (uint64_t) __builtin_ia32_rdtsc()};
      rng = mt19937(seq);
    }
    Generator(seed_seq& seq) : rng(seq) {}

    template<typename T,
             typename enable_if<is_integral<T>::value>::type* = nullptr>
    T uniform_int(T L, T R) {
      return uniform_int_distribution<T>(L, R)(rng);
    }

    template<typename T>
    T uniform_int(T N) {
      return uniform_int(0, N-1);
    }

    template<typename T>
    T uniform_real(T N) {
      return uniform_real(0.0, static_cast<double>(N));
    }

    template<typename T>
    T uniform_real(T L, T R) {
      return uniform_real_distribution<double>(static_cast<double>(L),
                                               static_cast<double>(R))(rng);
    }

    double uniform_real() {
      return uniform_real(0.0, 1.0);
    }
  };

  static Generator gen = Generator();
}  // namespace rng
static rng::Generator& rng_gen = rng::gen;
}  // namespace lib

#endif
