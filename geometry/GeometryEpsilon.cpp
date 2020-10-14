#ifndef _LIB_GEOMETRY_EPSILON
#define _LIB_GEOMETRY_EPSILON
#include <bits/stdc++.h>
#include "../Epsilon.cpp"

#define GEOMETRY_EPSILON(T, x) template<> \
  lib::Epsilon<T>* lib::geo::GeometryEpsilon<T>::eps \
    = new lib::Epsilon<T>((x));

#define GEOMETRY_COMPARE0(T, x) GeometryEpsilon<T>()((x))
#define GEOMETRY_COMPARE(T, x, y) GeometryEpsilon<T>()((x), (y))

namespace lib {
  using namespace std;
namespace geo {
  template<typename T>
  struct GeometryEpsilon {
    static Epsilon<T>* eps;
    template<typename G>
    int operator()(G a, G b = 0) const {
      return (*eps)(a, b);
    }
  };

  GEOMETRY_EPSILON(int, 0);
  GEOMETRY_EPSILON(long, 0);
  GEOMETRY_EPSILON(long long, 0);
}  // namespace geo
}  // namespace lib

#endif
