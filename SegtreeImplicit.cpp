#ifndef _LIB_SEGTREE_IMPLICIT
#define _LIB_SEGTREE_IMPLICIT
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace seg {

  template<typename Node>
  struct ImplicitNodeManager {
    struct NodeWrapper {
      Node no;
      NodeWrapper* left = nullptr;
      NodeWrapper* right = nullptr;
    };

    struct VirtualNode {
      NodeWrapper *cur = nullptr, **edge = nullptr;
    };

    typedef VirtualNode vnode;

    vnode r = {new NodeWrapper()};

    template<typename Builder>
    void initialize(const Builder& builder) {}

    inline bool has(vnode no) const { return no.cur; }
    inline vnode root() { return r; }
    inline vnode new_root(vnode no) { return r = no; }
    inline vnode left(vnode no) { return {no.cur->left, &(no.cur->left)}; }
    inline vnode right(vnode no) { return {no.cur->right, &(no.cur->right)}; }
    inline Node& ref(vnode no) { return no.cur->no; }
    inline Node* ptr(vnode no) { return &(no.cur->no); }
    inline Node value(vnode no) { return no.cur->no; }

    inline vnode persist(vnode no) {
      if(no.cur)
        return no;
      vnode res = no;
      res.cur = *res.edge = new NodeWrapper();
      return res;
    }
    inline void ensure_left(vnode no) {
      if(!no.cur->left)
        no.cur->left = new NodeWrapper();
    }
    inline void ensure_right(vnode no) {
      if(!no.cur->right)
        no.cur->right = new NodeWrapper();
    }
  };
 
  template<typename Node>
  using Implicit = ImplicitNodeManager<Node>;
}  // namespace seg
}  // namespace lib

#endif
