#ifndef _LIB_SEGTREE_LAZY
#define _LIB_SEGTREE_LAZY
#include <bits/stdc++.h>
#include "SegtreeBeats.cpp"

namespace lib {
  using namespace std;
namespace seg { 
  template<typename Node,
           typename CombinerFn,
           typename PushdownFn,
           typename NodeManager = Explicit<Node>>
  struct SegtreeLazy : SegtreeImpl<Node, NodeManager, CombinerFn, PushdownFn> {
    typedef SegtreeImpl<Node, NodeManager, CombinerFn, PushdownFn> Base;
    using Base::SegtreeImpl;
    using typename Base::vnode;
  };
}  // namespace seg
}  // namespace lib

#endif
