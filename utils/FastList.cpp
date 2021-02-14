#ifndef _LIB_FAST_LIST
#define _LIB_FAST_LIST
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace list {
template<typename T>
struct Node {
  T val;
  Node *next = nullptr, *prev = nullptr;
  Node() {}
  Node(T v) : val(v) {}

  void clear_links() {
    if(next != nullptr) next->prev = prev;
    if(prev != nullptr) prev->next = next;
    next = prev = nullptr;
  }
};

template<typename T>
void remove(Node<T>* no) {
  if(no != nullptr) no->clear_links();
}

template<typename T>
void append(Node<T>* no, Node<T>* nw) {
  assert(no != nullptr);
  remove(nw);
  if(no->next != nullptr) no->next->prev = nw;
  if(nw != nullptr) {
    nw->next = no->next;
    nw->prev = no;
  }
  no->next = nw;
}

template<typename T>
void prepend(Node<T>* no, Node<T>* nw) {
  assert(no != nullptr);
  remove(nw);
  if(no->prev != nullptr) no->prev->next = nw;
  if(nw != nullptr) {
    nw->prev = no->prev;
    nw->next = no;
  }
  no->prev = nw;
}
} // namespace list
} // namespace lib

#endif
