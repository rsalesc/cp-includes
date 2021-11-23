#ifndef _LIB_POLYNOMIAL_TRANSFORM
#define _LIB_POLYNOMIAL_TRANSFORM
#include <bits/stdc++.h>

namespace lib {
using namespace std;
template<template <class> class T>
struct TransformMultiplication {
  template<typename Field>
  using Transform = T<Field>;

  template <typename Field>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return T<Field>::convolve(a, b);
  };

  template<typename Field>
  inline VectorN<Field> transform(int n, const vector<Field>& p) const {
    int np = next_power_of_two(n);
    return T<Field>::transform(p, np);
  }

  template<typename Field>
  inline vector<Field> itransform(int n, const vector<Field>& p) const {
    return T<Field>::itransform(p, n);
  }

  template <typename Field, typename Functor, typename ...Ts>
  inline vector<Field> on_transform(
    int n,
    Functor& f,        
    const vector<Ts>&... vs) const {
    int np = next_power_of_two(n);
    return T<Field>::itransform(
      f(n, T<Field>::transform(vs, np)...), n);
  }
};
} // namespace lib

#endif
