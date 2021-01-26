#ifndef _LIB_FAST_QUEUE
#define _LIB_FAST_QUEUE
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
template<typename T>
struct FastQueue {
  vector<T> v;
  int L = 0, R = 0;
  FastQueue(int cap) : v(cap) {}

  void push(const T& no) {
    v[R++] = no;
  }
  T& front() {
    return v[L];
  }
  T front() const {
    return v[L];
  }
  T pop() {
    return v[L++];
  }
  bool empty() const {
    return L >= R;
  }
  int size() const {
    return max(R - L, 0);
  }
  void clear() {
    L = 0, R = 0;
  }
};
} // namespace lib

#endif
