#ifndef _LIB_BINARY_MATROID
#define _LIB_BINARY_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"

namespace lib {
  using namespace std;
namespace {
template<typename T>
struct BinaryMatroidFn {
  T operator()(const T& a, const T& b) const {
    return min(a, a^b);
  }
};
}

template<typename T = uint64_t>
struct BinaryMatroid : IncrementalMatroid {
  lambda::Map<T> bit_fn;
  vector<T> basis_;
  BinaryMatroid() {}
  BinaryMatroid(const lambda::SubsetMap<T>& fn) 
    : IncrementalMatroid(), bit_fn(fn) {
      set_ground(fn.size());
    }
  void clear() override {
    basis_.clear();
  }
  void add(int i) override {
    auto x = bit_fn(i);
    if((x = accumulate(basis_.begin(), basis_.end(), x, BinaryMatroidFn<T>())) > 0) {
      for(int i = 0; i < basis_.size(); i++) {
        if(basis_[i] < x) {
          basis_.insert(basis_.begin() + i, x);
          return;
        }
      }
      basis_.push_back(x);
    }
  }
  bool check(int i) override {
    auto x = bit_fn(i);
    bool res = 
      accumulate(basis_.begin(), basis_.end(), x, BinaryMatroidFn<T>()) > 0;
    return res;
  }
};
} // namespace lib

#endif
