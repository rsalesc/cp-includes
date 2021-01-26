#ifndef _LIB_FAST_ADJ
#define _LIB_FAST_ADJ
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
template<typename T>
struct FastAdj {
  int n;
  vector<T> edges;
  vector<int> head, next;
  FastAdj(int n, int cap = 0) : n(n), edges(), head(), next() {
    edges.reserve(cap);
    next.reserve(cap);
    head.assign(n, -1);
  }
  int size() const {
    return n;
  }
  int edge_size() const {
    return edges.size();
  }
  void reserve(int c) {
    edges.reserve(c);
    next.reserve(c);
  }
  void clear() {
    edges.clear();
    next.clear();
    head.assign(n, -1);
  }
  T& add(int u) {
    int K = edges.size();
    next.push_back(head[u]);
    head[u] = K;
    edges.emplace_back();
    return edges.back();
  }
  void add(int u, T v) {
    int K = edges.size();
    next.push_back(head[u]);
    head[u] = K;
    edges.push_back(v);
  }

  class iterator {
  public:
    typedef iterator self_type;
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef int difference_type;
    iterator(vector<int> *next, vector<T> *edges, int ptr = 0)
        : next_(next), edges_(edges), ptr_(ptr) {}
    self_type operator++() {
      ptr_ = (*next_)[ptr_];
      return *this;
    }
    self_type operator++(int junk) {
      self_type i = *this;
      ptr_ = (*next_)[ptr_];
      return i;
    }
    reference operator*() { return (*edges_)[ptr_]; }
    pointer operator->() { return &(*edges_)[ptr_]; }
    bool operator==(const self_type &rhs) const {
      return ptr_ == rhs.ptr_;
    }
    bool operator!=(const self_type &rhs) const { return !(*this == rhs); }

  private:
    vector<int> *next_;
    vector<T> *edges_;
    int ptr_;
  };

  class const_iterator {
  public:
    typedef const_iterator self_type;
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef int difference_type;
    const_iterator(vector<int> *next, vector<T> *edges, int ptr = 0)
        : next_(next_), edges_(edges), ptr_(ptr) {}
    self_type operator++() {
      ptr_ = (*next_)[ptr_];
      return *this;
    }
    self_type operator++(int junk) {
      self_type i = *this;
      ptr_ = (*next_)[ptr_];
      return i;
    }
    const value_type &operator*() { return (*edges_)[ptr_]; }
    const value_type *operator->() { return &(*edges_)[ptr_]; }
    bool operator==(const self_type &rhs) const {
      return ptr_ == rhs.ptr_;
    }
    bool operator!=(const self_type &rhs) const { return !(*this == rhs); }

  private:
    vector<int> *next_;
    vector<T> *edges_;
    int ptr_;
  };

  struct iterable {
    vector<int> *next_;
    vector<T> *edges_;
    int head_;

    iterable(vector<int> *next, vector<T> *edges, int head)
        : next_(next), edges_(edges), head_(head) {}

    inline iterator begin() { return iterator(next_, edges_, head_); }
    inline iterator end() { return iterator(next_, edges_, -1); }

    inline const_iterator cbegin() const {
      return const_iterator(next_, edges_);
    }
    inline const_iterator cend() const {
      return const_iterator(next_, edges_, -1);
    }

    inline const_iterator begin() const { return cbegin(); }
    inline const_iterator end() const { return cend(); }
  };

  inline iterable n_edges(int i) { return iterable(&next, &edges, head[i]); }
  inline const iterable n_edges(int i) const {
    return iterable(const_cast<vector<int> *>(&next),
                    const_cast<vector<T> *>(&edges),
                    head[i]);
  }
};
} // namespace lib

#endif
