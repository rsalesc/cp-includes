#ifndef _LIB_WRAPPERS
#define _LIB_WRAPPERS
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace graph {
  template<typename T>
  struct Edge {
    const int from, to;
    T data;
  };

  template<>
  struct Edge<void> { const int from, to; };

  template<typename T>
  struct VertexWrapper { T data; };

  template<>
  struct VertexWrapper<void> {};
}  // namespace graph
}  // namespace lib

#endif
