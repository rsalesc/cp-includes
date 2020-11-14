#ifndef _LIB_VECTOR_N
#define _LIB_VECTOR_N
#include <bits/stdc++.h>
#include "Traits.cpp"

#define VEC_CONST_OP(op, typ) \
  type operator op(const typ rhs) const { \
    auto res = *this; \
    return res op##= rhs; \
  }

#define VEC_BIN_OP(op) \
  type& operator op##=(const type& rhs) { \
    if(rhs.size() > this->size()) \
      this->resize(rhs.size()); \
    int sz = this->size(); \
    for(int i = 0; i < (int)rhs.size(); i++) \
      (*this)[i] op##= rhs[i]; \
    for(int i = rhs.size(); i < sz; i++) \
      (*this)[i] op##= 0; \
    return *this; \
  } \
  VEC_CONST_OP(op, type)

#define VEC_SINGLE_OP(op, typ) \
  type& operator op##=(const typ rhs) { \
    for(auto& x : *this) \
      x op##= rhs; \
    return *this; \
  } \
  VEC_CONST_OP(op, typ)
  

namespace lib {
using namespace std;
template<typename T>
struct VectorN : vector<T> {
  using type = VectorN<T>;

  template <
      typename Container,
      typename enable_if<traits::HasInputIterator<Container>::value>::type * = nullptr>
  VectorN(const Container &container)
      : vector<T>(container.begin(), container.end()) {}

  VectorN(const initializer_list<T> &v)
      : vector<T>(v.begin(), v.end()) {}

  template<typename... Args>
  VectorN( Args&&... args ) 
      : vector<T>(std::forward<Args>(args)...) {}

  VEC_BIN_OP(+)
  VEC_BIN_OP(-)
  VEC_BIN_OP(*)

  VEC_SINGLE_OP(+, T&)
  VEC_SINGLE_OP(-, T&)
  VEC_SINGLE_OP(*, T&)
  VEC_SINGLE_OP(/, T&)
  VEC_SINGLE_OP(^, int64_t)

  type operator-() const {
    auto res = *this;
    for(auto& x : res) x = -x;
    return res;
  }

  type operator%(int n) const {
    // TODO: get rid of this
    // return *const_cast<type*>(this);
    return *this;
  }
};
} // namespace lib

#endif
