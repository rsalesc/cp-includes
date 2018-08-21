#ifndef _LIB_SEGTREE_FAST
#define _LIB_SEGTREE_FAST
#include <bits/stdc++.h>
#include "Segtree.cpp"

namespace lib {
  using namespace std;
namespace seg {
  template<typename Node, typename CombinerFn>
  struct SegtreeFastBase {
    const static int MULTIPLIER = 2;

    CombinerFn combiner_fn;
    
    vector<Node> t;
    int L, n;

    template<typename Builder>
    explicit SegtreeFastBase(const Builder& builder) {
      pair<int, int> range = builder.range();
      L = range.first;
      n = range.second - range.first + 1;
      assert(n > 0);
      t = vector<Node>(n * MULTIPLIER);
      build(builder);
    }

    template<typename Builder>
    void build(const Builder& builder) {
      for(int i = n; i < 2*n; i++)
        builder(t[i], L + i - n);
      for(int i = n-1; i > 0; i--)
        t[i] = combiner_fn(t[i<<1], t[i<<1|1]);
    }

    template<typename Rebuilder>
    void rebuild(const Rebuilder& rebuilder) {
      for(int i = n; i < 2*n; i++)
        rebuilder(t[i]);
      for(int i = n-1; i > 0; i--)
        rebuilder(t[i], t[i<<1], t[i<<1|1]);
    }
  };

  template<typename Node, typename CombinerFn>
  struct SegtreeFast : SegtreeFastBase<Node, CombinerFn> {
    typedef SegtreeFastBase<Node, CombinerFn> Base;
    using Base::SegtreeFastBase;
    using Base::combiner_fn;
    using Base::n;
    using Base::t;
    using Base::L;

    template<typename Updater>
    void update_element(int i, const Updater& updater)  {
      i -= L;
      assert(i >= 0);
      for(updater(t[i += n]); i /= 2; )
        t[i] = combiner_fn(t[i<<1], t[i<<1|1]);
    }

    template<typename T, typename Folder>
    T query(int i, int j, const Folder& folder) {
      // input is [i, j]
      i -= L, j -= L;
      assert(i >= 0 && j >= 0);
      i += n, j += n;
      if(i == j) return folder(t[i]);
      T resl = folder(t[i]), resr = folder(t[j]);

      // now it is [i, j)
      i++;
      while(i < j) {
        if(i&1)
          resl = folder(resl, folder(t[i++]));
        if(j&1)
          resr = folder(folder(t[--j]), resr);
        i /= 2, j /= 2;
      }

      return folder(resl, resr);
    }
  };
  
  template<typename Node>
  struct SegtreeFastSplash : SegtreeFastBase<Node, EmptyFolder<Node>> {
    typedef SegtreeFastBase<Node, EmptyFolder<Node>> Base;
    using Base::SegtreeFastBase;
    using Base::n;
    using Base::t;
    using Base::L;

    template<typename T, typename Folder>
    T query_element(int i, const Folder& folder)  {
      i -= L;
      assert(i >= 0);
      T res = folder(t[i += n]);
      while(i /= 2) {
        res = folder(folder(t[i]), res);
      }
      return res;
    }

    template<typename Updater>
    void splash(int i, int j, const Updater& updater) {
      // input is [i, j]
      i -= L, j -= L;
      assert(i >= 0 && j >= 0);
      // now it is [i, j)
      i += n, j += n+1;

      while(i < j) {
        if(i&1)
          updater(t[i++]);
        if(j&1)
          updater(t[--j]);
        i /= 2, j /= 2;
      }
    }
  };

}  // namespace seg
}  // namespace lib

#endif
