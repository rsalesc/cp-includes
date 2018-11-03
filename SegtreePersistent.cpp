#ifndef _LIB_SEGTREE_PERSISTENT
#define _LIB_SEGTREE_PERSISTENT
#include <bits/stdc++.h>
#include "SegtreeImplicit.cpp"

namespace lib {
  using namespace std;
namespace seg {

  template<typename Node>
  struct PersistentNodeManager : ImplicitNodeManager<Node> {
    using typename ImplicitNodeManager<Node>::vnode;
    using typename ImplicitNodeManager<Node>::NodeWrapper;

    inline vnode persist(vnode no) {
      vnode res = no;
      res.cur = no.cur ? new NodeWrapper(*no.cur) : new NodeWrapper();
      if(res.edge) *res.edge = res.cur;
      return res;
    }
  };
 
  template<typename Node>
  using Persistent = PersistentNodeManager<Node>;
}  // namespace seg
}  // namespace lib

#endif
