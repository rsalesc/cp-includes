#ifndef _LIB_SUBSET
#define _LIB_SUBSET
#include <bits/stdc++.h>

namespace lib {
using namespace std;
// Source: https://github.com/NyaanNyaan/library/tree/master/set-function

template <typename T>
void superset_zeta_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j] += f[j | i];
      }
    }
  }
}

template <typename T>
void superset_mobius_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j] -= f[j | i];
      }
    }
  }
}

template <typename T>
void subset_zeta_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j | i] += f[j];
      }
    }
  }
}

template <typename T>
void subset_mobius_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j | i] -= f[j];
      }
    }
  }
}

template <typename T>
vector<T> or_convolution(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  subset_zeta_transform(a);
  subset_zeta_transform(b);
  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];
  subset_mobius_transform(a);
  return a;
}

template <typename T>
vector<T> and_convolution(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  superset_zeta_transform(a);
  superset_zeta_transform(b);
  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];
  superset_mobius_transform(a);
  return a;
}

template<typename T>
vector<vector<T>> ranked_zeta_transform(const vector<T>& f) {
  int N = f.size();
  assert((N & (N-1)) == 0);
  int R = __builtin_ctz(N);
  vector<vector<T>> F(R + 1, vector<T>(N));
  for(int i = 0; i < N; i++)
    F[__builtin_popcount(i)][i] = f[i];
  for(int i = 0; i <= R; i++)
    subset_zeta_transform(F[i]);
  return F;
}

template<typename T>
vector<T> subset_convolution(const vector<T>& a, const vector<T>& b, int offset = 0) {
  int N = a.size();
  assert(N == b.size());
  assert((N & (N-1)) == 0);
  int R = __builtin_ctz(N);

  auto A = ranked_zeta_transform(a), B = ranked_zeta_transform(b);
  auto C = vector<vector<T>>(R + 1, vector<T>(N));

  for(int m = 0; m < N; m++) {
    for(int i = 0; i <= R; i++) {
      for(int j = offset; j <= i; j++) {
        C[i][m] += A[j][m] * B[i + offset - j][m];
      }
    }
  }

  for(int i = 0; i <= R; i++)
    subset_mobius_transform(C[i]);
  vector<T> res(N);
  for(int i = 0; i < N; i++)
    res[i] = C[__builtin_popcount(i)][i];
  return res;
}
} // namespace lib

#endif
