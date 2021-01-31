#ifndef _LIB_MATROID
#define _LIB_MATROID
#include <bits/stdc++.h>
#include "../Lambda.cpp"

namespace lib {
struct Matroid {
  lambda::SubsetFilter I;
  bool in_I(int i) const {
    return I(i);
  }
  vector<bool> get_I() const {
    return I();
  }
  int ground_set_size() const { return I.size(); }

  /** docstring
   * Used to build a Matroid object from an M (independent set provider).
   */ 
  virtual void build(const lambda::SubsetFilter& I_) {
    I = I_;
  }

  void setup() {}
  void setup_graph() {}
  void setup_exchange(int i) {}
  void finish_exchange(int i) {}

  bool can_add(int i) { return false; }
  bool can_exchange(int i, int j) { return false; }

  void print_I() {
    for(int i = 0; i < I.size(); i++) cout << in_I(i) << " ";
    cout << endl;
  }
};
} // namespace lib

#endif
