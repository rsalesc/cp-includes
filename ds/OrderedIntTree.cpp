#ifndef _LIB_ORDERED_INT_TREE
#define _LIB_ORDERED_INT_TREE
#include <bits/stdc++.h>

namespace lib {
using namespace std;

namespace ds {

template <typename T>
struct Node {
  int key;
  T data;
};

template<>
struct Node<void> {
  int key;
};

template <typename T = void>
struct OrderedIntTree {
  
};

}
} // namespace lib

#endif
