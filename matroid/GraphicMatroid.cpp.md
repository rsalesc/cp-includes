---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Lambda.cpp
    title: Lambda.cpp
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':warning:'
    path: matroid/Matroid.cpp
    title: matroid/Matroid.cpp
  - icon: ':warning:'
    path: utils/FastAdj.cpp
    title: utils/FastAdj.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: matroid/CographicMatroid.cpp
    title: matroid/CographicMatroid.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matroid/GraphicMatroid.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    #line 1 \"matroid/Matroid.cpp\"\n\n\n#line 1 \"Lambda.cpp\"\n\n\n#line 1 \"Traits.cpp\"\
    \n\n\n#line 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ traits {\n\ntemplate <typename...> struct make_void { using type = void; };\n\
    \ntemplate <typename... T> using void_t = typename make_void<T...>::type;\n\n\
    /// keep caide\ntemplate <typename Iterator>\nusing IteratorCategory = typename\
    \ iterator_traits<Iterator>::iterator_category;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorCategoryOf = IteratorCategory<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IteratorValue = typename\
    \ iterator_traits<Iterator>::value_type;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorValueOf = IteratorValue<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsRandomIterator =\n   \
    \ is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\n/// keep\
    \ caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IsBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing HasRandomIterator =\n \
    \   is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;\n\n\
    /// keep caide\ntemplate <typename Container>\nusing HasInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n\n/// keep caide\ntemplate <typename Container>\n\
    using HasBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;\n\
    } // namespace traits\n} // namespace lib\n\n\n#line 5 \"Lambda.cpp\"\n\nnamespace\
    \ lib {\n  using namespace std;\nnamespace lambda {\n  using namespace traits;\n\
    \nconst auto identity = [](int i) -> int { return i; };\nconst auto all = [](int\
    \ i) -> bool { return true; };\nconst auto none = [](int i) -> bool { return false;\
    \ };\n\nauto first_n(int n) {\n  return [n](int i) -> bool { return i < n; };\n\
    }\n\ntemplate<typename F, typename I = int>\nusing ValueType = decltype(declval<F>()(declval<I>()));\n\
    \ntemplate<typename T>\nstruct Map {\n  std::function<T(int)> f;\n  Map() {}\n\
    \  template<typename F>\n  Map(const F& f_) : f(f_) {}\n  T operator()(int i)\
    \ const {\n    return f(i);\n  }\n};\n\nstruct Subset;\n\ntemplate<typename T>\n\
    struct SubsetMap : Map<T> {\n  using Map<T>::operator();\n  using Map<T>::f;\n\
    \n  int n;\n  SubsetMap() : Map<T>(), n(0) {}\n  template<typename F>\n  SubsetMap(int\
    \ n, F && f_) : Map<T>(f_), n(n) {}\n  int size() const { return n; }\n  int count()\
    \ const {\n    int cnt = 0;\n    for(int i = 0; i < n; i++)\n      cnt += f(i)\
    \ != 0;\n    return cnt;\n  }\n  vector<T> operator()() const {\n    vector<T>\
    \ res(n);\n    for(int i = 0; i < n; i++)\n      res[i] = f(i);\n    return res;\n\
    \  }\n\n  Subset as_subset() const;\n\n  template<typename U = T,\n          \
    \ enable_if_t<is_same<U, bool>::value>* = nullptr>\n  SubsetMap<T> operator!()\
    \ const {\n    return SubsetMap<T>(n, [f=f](int i) { return !f(i); });\n  }\n\n\
    \  template<typename U = T,\n           enable_if_t<is_same<U, bool>::value>*\
    \ = nullptr>\n  SubsetMap<T> operator|(const SubsetMap<T>& rhs) const {\n    return\
    \ SubsetMap<T>(n, [f=f, g=rhs.f](int i) { return f(i) || g(i); });\n  }\n\n  SubsetMap<T>\
    \ operator+(const SubsetMap<T>& rhs) const {\n    int N = size() + rhs.size();\n\
    \    return SubsetMap<T>(N, [n=n, f=f, g=rhs.f](int i) {\n      return i >= n\
    \ ? g(i - n) : f(i);\n    });\n  }\n\n  SubsetMap<T> operator*(const SubsetMap<T>&\
    \ rhs) const {\n    return SubsetMap<T>(n, [f=f, g=rhs.f](int i) {\n      return\
    \ f(g(i));\n    });\n  }\n};\n\nstruct Subset {\n  mutable vector<int> map;\n\
    \  Subset() {}\n  Subset(const vector<int>& map_) : map(map_) {\n  }\n  void add(int\
    \ i) {\n    map.push_back(i);\n  }\n  void pop() { map.pop_back(); }\n  void clear()\
    \ { map.clear(); }\n  int size() const { return map.size(); }\n  int operator()(int\
    \ i) const { return map[i]; }\n  vector<int> items() const { return map; }\n\n\
    \  template<typename F>\n  SubsetMap<ValueType<F>> take_from(F && g) const {\n\
    \    using T = ValueType<F>;\n    auto map_ = map;\n    return SubsetMap<T>(map.size(),\
    \ [g, map_](int i) -> T {\n      return g(map_[i]);\n    });\n  }\n\n  Subset\
    \ take_subset(const Subset& s) const {\n    vector<int> res;\n    for(int i :\
    \ items()) {\n      res.push_back(s(i));\n    }\n    return Subset(res);\n  }\n\
    \n  SubsetMap<int> take_indices() const {\n    return take_from(identity);\n \
    \ }\n\n  SubsetMap<int> take_inverse(int def = -1) const {\n    int n = 0;\n \
    \   auto it = max_element(map.begin(), map.end());\n    if(it != map.end()) n\
    \ = *it + 1;\n    vector<int> inv(n, def);\n    for(int i = 0; i < map.size();\
    \ i++)\n      inv[map[i]] = i;\n    return SubsetMap<int>(n, [inv](int i) -> int\
    \ {\n      return inv[i];\n    });\n  }\n\n  void sort() const {\n    std::sort(map.begin(),\
    \ map.end());\n  }\n\n  Subset operator|(const Subset& rhs) const {\n    sort();\n\
    \    rhs.sort();\n    vector<int> res;\n    res.reserve(size() + rhs.size());\n\
    \    merge(map.begin(), map.end(), rhs.map.begin(), rhs.map.end(), back_inserter(res));\n\
    \    auto it = unique(res.begin(), res.end());\n    res.resize(it - res.begin());\n\
    \    return res;\n  }\n};\n\ntemplate<>\nstruct Map<bool> {\n    std::function<bool(int)>\
    \ f;\n    Map() {}\n    template<typename F>\n    Map(const F& f_) : f(f_) {}\n\
    \    bool operator()(int i) const {\n      return f(i);\n    }\n\n    template\
    \ <\n      typename Iterator,\n      typename enable_if<IsInputIterator<Iterator>::value>::type\
    \ * = nullptr>\n    vector<IteratorValue<Iterator>> operator()(Iterator begin,\
    \ Iterator end) const {\n      vector<IteratorValue<Iterator>> res;\n      int\
    \ i = 0;\n      for(auto it = begin; it != end; ++it, ++i) {\n        if(f(i))\
    \ res.push_back(*it);\n      }\n      return res;\n    }\n    template <\n   \
    \   typename Container,\n      typename enable_if<HasInputIterator<Container>::value>::type\
    \ * = nullptr>\n    vector<IteratorValueOf<Container>> operator()(const Container&\
    \ c) const {\n      return (*this)(c.begin(), c.end());\n    }\n\n    Subset subset(int\
    \ n) const {\n      Subset map;\n      for(int i = 0; i < n; i++)\n        if(f(i))\
    \ map.add(i);\n      return map;\n    }\n\n    template<typename F>\n    SubsetMap<ValueType<F>>\
    \ subset(int n, F && g) const {\n      return subset(SubsetMap<ValueType<F>>(n,\
    \ g));\n    }\n\n    template<typename T>\n    SubsetMap<T> subset(const SubsetMap<T>&\
    \ g) const {\n      return subset(g.size()).take_from(g);\n    }\n};\n\nnamespace\
    \ {\ntemplate<typename T,\n         enable_if_t<is_same<T, bool>::value>* = nullptr>\n\
    Subset as_subset_(const SubsetMap<T>& rhs) {\n  Subset map;\n  for(int i = 0;\
    \ i < rhs.size(); i++)\n    if(rhs(i)) map.add(i);\n  return map;\n}\ntemplate<typename\
    \ T,\n         enable_if_t<!is_same<T, bool>::value>* = nullptr>\nSubset as_subset_(const\
    \ SubsetMap<T>& rhs) {\n  Subset map;\n  for(int i = 0; i < rhs.size(); i++)\n\
    \    map.add(rhs(i));\n  return map;\n}\n}\n\n\ntemplate<typename T>\nSubset SubsetMap<T>::as_subset()\
    \ const {\n  return as_subset_(*this);\n  \n}\n\nusing Filter = Map<bool>;\nusing\
    \ SubsetFilter = SubsetMap<bool>;\n\ntemplate<typename T>\nSubsetMap<T> from_vector(const\
    \ vector<T>& v) {\n  return SubsetMap<T>(v.size(), [v](int i) -> T {\n    return\
    \ v[i];\n  });\n}\n\ntemplate<typename U, typename F, typename T = ValueType<F,\
    \ U>>\nSubsetMap<T> map_from_vector(const vector<U>& v, const F& f) {\n  return\
    \ SubsetMap<T>(v.size(), [v, f](int i) -> T {\n    return f(v[i]);\n  });\n}\n\
    \ntemplate<typename T>\nSubsetFilter filter_from_vector(const vector<T>& v) {\n\
    \  return SubsetFilter(v.size(), [v](int i) -> bool {\n    return v[i];\n  });\n\
    }\n\ntemplate<typename T>\nSubsetFilter filter_from_sparse_vector(const vector<T>&\
    \ v) {\n  return SubsetFilter(v.size(), [v](int i) -> bool {\n    return v[i];\n\
    \  });\n}\n} // namespace lambda\n} // namespace lib\n\n\n#line 5 \"matroid/Matroid.cpp\"\
    \n\nnamespace lib {\nstruct Matroid {\n  lambda::SubsetFilter I;\n  bool in_I(int\
    \ i) const {\n    return I(i);\n  }\n  vector<bool> get_I() const {\n    return\
    \ I();\n  }\n  int ground_set_size() const { return I.size(); }\n\n  /** docstring\n\
    \   * Used to build a Matroid object from an M (independent set provider).\n \
    \  */ \n  virtual void build(const lambda::SubsetFilter& I_) {\n    I = I_;\n\
    \  }\n\n  void setup() {}\n  void setup_graph() {}\n  void setup_exchange(int\
    \ i) {}\n  void finish_exchange(int i) {}\n\n  bool can_add(int i) { return false;\
    \ }\n  bool can_exchange(int i, int j) { return false; }\n\n  void print_I() {\n\
    \    for(int i = 0; i < I.size(); i++) cout << in_I(i) << \" \";\n    cout <<\
    \ endl;\n  }\n};\n} // namespace lib\n\n\n#line 1 \"utils/FastAdj.cpp\"\n\n\n\
    #line 4 \"utils/FastAdj.cpp\"\n\nnamespace lib {\n  using namespace std;\ntemplate<typename\
    \ T>\nstruct FastAdj {\n  int n;\n  vector<T> edges;\n  vector<int> head, next;\n\
    \  FastAdj(int n, int cap = 0) : n(n), edges(), head(), next() {\n    edges.reserve(cap);\n\
    \    next.reserve(cap);\n    head.assign(n, -1);\n  }\n  int size() const {\n\
    \    return n;\n  }\n  int edge_size() const {\n    return edges.size();\n  }\n\
    \  void reserve(int c) {\n    edges.reserve(c);\n    next.reserve(c);\n  }\n \
    \ void clear() {\n    edges.clear();\n    next.clear();\n    head.assign(n, -1);\n\
    \  }\n  T& add(int u) {\n    int K = edges.size();\n    next.push_back(head[u]);\n\
    \    head[u] = K;\n    edges.emplace_back();\n    return edges.back();\n  }\n\
    \  void add(int u, T v) {\n    int K = edges.size();\n    next.push_back(head[u]);\n\
    \    head[u] = K;\n    edges.push_back(v);\n  }\n\n  class iterator {\n  public:\n\
    \    typedef iterator self_type;\n    typedef T value_type;\n    typedef T &reference;\n\
    \    typedef T *pointer;\n    typedef std::forward_iterator_tag iterator_category;\n\
    \    typedef int difference_type;\n    iterator(vector<int> *next, vector<T> *edges,\
    \ int ptr)\n        : next_(next), edges_(edges), ptr_(ptr) {}\n    self_type\
    \ operator++() {\n      ptr_ = (*next_)[ptr_];\n      return *this;\n    }\n \
    \   self_type operator++(int junk) {\n      self_type i = *this;\n      ptr_ =\
    \ (*next_)[ptr_];\n      return i;\n    }\n    reference operator*() { return\
    \ (*edges_)[ptr_]; }\n    pointer operator->() { return &(*edges_)[ptr_]; }\n\
    \    bool operator==(const self_type &rhs) const {\n      return ptr_ == rhs.ptr_;\n\
    \    }\n    bool operator!=(const self_type &rhs) const { return !(*this == rhs);\
    \ }\n\n  private:\n    vector<int> *next_;\n    vector<T> *edges_;\n    int ptr_;\n\
    \  };\n\n  class const_iterator {\n  public:\n    typedef const_iterator self_type;\n\
    \    typedef T value_type;\n    typedef T &reference;\n    typedef T *pointer;\n\
    \    typedef std::forward_iterator_tag iterator_category;\n    typedef int difference_type;\n\
    \    const_iterator(vector<int> *next, vector<T> *edges, int ptr)\n        : next_(next_),\
    \ edges_(edges), ptr_(ptr) {}\n    self_type operator++() {\n      ptr_ = (*next_)[ptr_];\n\
    \      return *this;\n    }\n    self_type operator++(int junk) {\n      self_type\
    \ i = *this;\n      ptr_ = (*next_)[ptr_];\n      return i;\n    }\n    const\
    \ value_type &operator*() { return (*edges_)[ptr_]; }\n    const value_type *operator->()\
    \ { return &(*edges_)[ptr_]; }\n    bool operator==(const self_type &rhs) const\
    \ {\n      return ptr_ == rhs.ptr_;\n    }\n    bool operator!=(const self_type\
    \ &rhs) const { return !(*this == rhs); }\n\n  private:\n    vector<int> *next_;\n\
    \    vector<T> *edges_;\n    int ptr_;\n  };\n\n  struct iterable {\n    vector<int>\
    \ *next_;\n    vector<T> *edges_;\n    int head_;\n\n    iterable(vector<int>\
    \ *next, vector<T> *edges, int head)\n        : next_(next), edges_(edges), head_(head)\
    \ {}\n\n    inline iterator begin() { return iterator(next_, edges_, head_); }\n\
    \    inline iterator end() { return iterator(next_, edges_, -1); }\n\n    inline\
    \ const_iterator cbegin() const {\n      return const_iterator(next_, edges_,\
    \ head_);\n    }\n    inline const_iterator cend() const {\n      return const_iterator(next_,\
    \ edges_, -1);\n    }\n\n    inline const_iterator begin() const { return cbegin();\
    \ }\n    inline const_iterator end() const { return cend(); }\n  };\n\n  inline\
    \ iterable n_edges(int i) { return iterable(&next, &edges, head[i]); }\n  inline\
    \ const iterable n_edges(int i) const {\n    return iterable(const_cast<vector<int>\
    \ *>(&next),\n                    const_cast<vector<T> *>(&edges),\n         \
    \           head[i]);\n  }\n};\n} // namespace lib\n\n\n#line 6 \"matroid/GraphicMatroid.cpp\"\
    \n\nnamespace lib {\n  using namespace std;\nstruct GraphicMatroid : Matroid {\n\
    \  lambda::Map<pair<int, int>> edge;\n  FastAdj<pair<int, int>> g;\n  vector<int>\
    \ comp, st, nd, low;\n  vector<int> bridges;\n  int tempo, comps;\n  bool printer\
    \ = true;\n\n  GraphicMatroid(int n, const lambda::Map<pair<int, int>>& edge_)\n\
    \    : Matroid(), edge(edge_), g(n, n) {}\n  void setup() {\n    g.clear();\n\
    \    g.reserve(ground_set_size());\n    for(int i = 0; i < ground_set_size();\
    \ i++)\n      if(in_I(i)) {\n        auto p = edge(i);\n        g.add(p.first,\
    \ {p.second, i});\n        g.add(p.second, {p.first, i});\n      }\n    build_graph();\n\
    \  }\n  void build_graph() {\n    int n = g.size();\n    comp.assign(n, -1);\n\
    \    st.assign(n, 0);\n    nd.assign(n, 0);\n    low.assign(n, 0);\n    bridges.assign(ground_set_size(),\
    \ 0);\n\n    tempo = 0;\n    comps = 0;\n    for(int i = 0; i < n; i++) {\n  \
    \    if(comp[i] == -1) dfs(i, -1, comps++);\n    }\n  }\n  void dfs(int u, int\
    \ p, int c) {\n    comp[u] = c;\n    st[u] = low[u] = tempo++;\n    for(auto e\
    \ : g.n_edges(u)) {\n      int v = e.first;\n      if(v == p) {\n        p = -1;\n\
    \        continue;\n      }\n      if(comp[v] != -1) low[u] = min(low[u], st[v]);\n\
    \      else {\n        dfs(v, u, c);\n        low[u] = min(low[u], low[v]);\n\
    \        if(low[v] > st[u]) {\n          bridges[e.second] = 1;\n        }\n \
    \     }\n    }\n    nd[u] = tempo++;\n  }\n  bool is_bridge(int i) {\n    return\
    \ bridges[i];\n  }\n  bool is_anc(int u, int v) {\n    return st[u] <= st[v] &&\
    \ st[v] <= nd[u];\n  }\n  bool can_exchange(int i, int j) {\n    auto e1 = edge(i);\n\
    \    auto e2 = edge(j);\n    if(st[e1.first] > st[e1.second]) swap(e1.first, e1.second);\n\
    \    return is_anc(e1.second, e2.first) + is_anc(e1.second, e2.second) == 1;\n\
    \  }\n  bool can_add(int i) {\n    auto e = edge(i);\n    return comp[e.first]\
    \ != comp[e.second];\n  }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_GRAPHIC_MATROID\n#define _LIB_GRAPHIC_MATROID\n#include <bits/stdc++.h>\n\
    #include \"Matroid.cpp\"\n#include \"../utils/FastAdj.cpp\"\n\nnamespace lib {\n\
    \  using namespace std;\nstruct GraphicMatroid : Matroid {\n  lambda::Map<pair<int,\
    \ int>> edge;\n  FastAdj<pair<int, int>> g;\n  vector<int> comp, st, nd, low;\n\
    \  vector<int> bridges;\n  int tempo, comps;\n  bool printer = true;\n\n  GraphicMatroid(int\
    \ n, const lambda::Map<pair<int, int>>& edge_)\n    : Matroid(), edge(edge_),\
    \ g(n, n) {}\n  void setup() {\n    g.clear();\n    g.reserve(ground_set_size());\n\
    \    for(int i = 0; i < ground_set_size(); i++)\n      if(in_I(i)) {\n       \
    \ auto p = edge(i);\n        g.add(p.first, {p.second, i});\n        g.add(p.second,\
    \ {p.first, i});\n      }\n    build_graph();\n  }\n  void build_graph() {\n \
    \   int n = g.size();\n    comp.assign(n, -1);\n    st.assign(n, 0);\n    nd.assign(n,\
    \ 0);\n    low.assign(n, 0);\n    bridges.assign(ground_set_size(), 0);\n\n  \
    \  tempo = 0;\n    comps = 0;\n    for(int i = 0; i < n; i++) {\n      if(comp[i]\
    \ == -1) dfs(i, -1, comps++);\n    }\n  }\n  void dfs(int u, int p, int c) {\n\
    \    comp[u] = c;\n    st[u] = low[u] = tempo++;\n    for(auto e : g.n_edges(u))\
    \ {\n      int v = e.first;\n      if(v == p) {\n        p = -1;\n        continue;\n\
    \      }\n      if(comp[v] != -1) low[u] = min(low[u], st[v]);\n      else {\n\
    \        dfs(v, u, c);\n        low[u] = min(low[u], low[v]);\n        if(low[v]\
    \ > st[u]) {\n          bridges[e.second] = 1;\n        }\n      }\n    }\n  \
    \  nd[u] = tempo++;\n  }\n  bool is_bridge(int i) {\n    return bridges[i];\n\
    \  }\n  bool is_anc(int u, int v) {\n    return st[u] <= st[v] && st[v] <= nd[u];\n\
    \  }\n  bool can_exchange(int i, int j) {\n    auto e1 = edge(i);\n    auto e2\
    \ = edge(j);\n    if(st[e1.first] > st[e1.second]) swap(e1.first, e1.second);\n\
    \    return is_anc(e1.second, e2.first) + is_anc(e1.second, e2.second) == 1;\n\
    \  }\n  bool can_add(int i) {\n    auto e = edge(i);\n    return comp[e.first]\
    \ != comp[e.second];\n  }\n};\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  - matroid/Matroid.cpp
  - Lambda.cpp
  - Traits.cpp
  - utils/FastAdj.cpp
  isVerificationFile: false
  path: matroid/GraphicMatroid.cpp
  requiredBy:
  - matroid/CographicMatroid.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/GraphicMatroid.cpp
layout: document
redirect_from:
- /library/matroid/GraphicMatroid.cpp
- /library/matroid/GraphicMatroid.cpp.html
title: matroid/GraphicMatroid.cpp
---
