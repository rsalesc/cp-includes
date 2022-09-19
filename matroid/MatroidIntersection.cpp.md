---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Lambda.cpp
    title: Lambda.cpp
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: utils/FastAdj.cpp
    title: utils/FastAdj.cpp
  - icon: ':warning:'
    path: utils/FastQueue.cpp
    title: utils/FastQueue.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matroid/MatroidIntersection.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    #line 1 \"utils/FastAdj.cpp\"\n\n\n#line 4 \"utils/FastAdj.cpp\"\n\nnamespace\
    \ lib {\n  using namespace std;\ntemplate<typename T>\nstruct FastAdj {\n  int\
    \ n;\n  vector<T> edges;\n  vector<int> head, next;\n  FastAdj(int n, int cap\
    \ = 0) : n(n), edges(), head(), next() {\n    edges.reserve(cap);\n    next.reserve(cap);\n\
    \    head.assign(n, -1);\n  }\n  int size() const {\n    return n;\n  }\n  int\
    \ edge_size() const {\n    return edges.size();\n  }\n  void reserve(int c) {\n\
    \    edges.reserve(c);\n    next.reserve(c);\n  }\n  void clear() {\n    edges.clear();\n\
    \    next.clear();\n    head.assign(n, -1);\n  }\n  T& add(int u) {\n    int K\
    \ = edges.size();\n    next.push_back(head[u]);\n    head[u] = K;\n    edges.emplace_back();\n\
    \    return edges.back();\n  }\n  void add(int u, T v) {\n    int K = edges.size();\n\
    \    next.push_back(head[u]);\n    head[u] = K;\n    edges.push_back(v);\n  }\n\
    \n  class iterator {\n  public:\n    typedef iterator self_type;\n    typedef\
    \ T value_type;\n    typedef T &reference;\n    typedef T *pointer;\n    typedef\
    \ std::forward_iterator_tag iterator_category;\n    typedef int difference_type;\n\
    \    iterator(vector<int> *next, vector<T> *edges, int ptr)\n        : next_(next),\
    \ edges_(edges), ptr_(ptr) {}\n    self_type operator++() {\n      ptr_ = (*next_)[ptr_];\n\
    \      return *this;\n    }\n    self_type operator++(int junk) {\n      self_type\
    \ i = *this;\n      ptr_ = (*next_)[ptr_];\n      return i;\n    }\n    reference\
    \ operator*() { return (*edges_)[ptr_]; }\n    pointer operator->() { return &(*edges_)[ptr_];\
    \ }\n    bool operator==(const self_type &rhs) const {\n      return ptr_ == rhs.ptr_;\n\
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
    \           head[i]);\n  }\n};\n} // namespace lib\n\n\n#line 1 \"utils/FastQueue.cpp\"\
    \n\n\n#line 4 \"utils/FastQueue.cpp\"\n\nnamespace lib {\n  using namespace std;\n\
    template<typename T>\nstruct FastQueue {\n  vector<T> v;\n  int L = 0, R = 0;\n\
    \  FastQueue(int cap) : v(cap) {}\n\n  void push(const T& no) {\n    if(R >= v.size())\
    \ v.emplace_back();\n    v[R++] = no;\n  }\n  T& front() {\n    return v[L];\n\
    \  }\n  T front() const {\n    return v[L];\n  }\n  T pop() {\n    return v[L++];\n\
    \  }\n  bool empty() const {\n    return L >= R;\n  }\n  int size() const {\n\
    \    return max(R - L, 0);\n  }\n  void clear() {\n    L = 0, R = 0;\n  }\n};\n\
    } // namespace lib\n\n\n#line 1 \"Lambda.cpp\"\n\n\n#line 1 \"Traits.cpp\"\n\n\
    \n#line 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace traits\
    \ {\n\ntemplate <typename...> struct make_void { using type = void; };\n\ntemplate\
    \ <typename... T> using void_t = typename make_void<T...>::type;\n\n/// keep caide\n\
    template <typename Iterator>\nusing IteratorCategory = typename iterator_traits<Iterator>::iterator_category;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing IteratorCategoryOf = IteratorCategory<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IteratorValue = typename iterator_traits<Iterator>::value_type;\n\n/// keep\
    \ caide\ntemplate <typename Container>\nusing IteratorValueOf = IteratorValue<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IsRandomIterator =\n    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
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
    \  });\n}\n} // namespace lambda\n} // namespace lib\n\n\n#line 7 \"matroid/MatroidIntersection.cpp\"\
    \n\nnamespace lib {\ntemplate<typename M1, typename M2, typename W = int>\nstruct\
    \ MatroidIntersection {\n  int n;\n  M1 m1;\n  M2 m2;\n\n  // aux vectors\n  vector<int>\
    \ vI;\n  vector<int> I;\n  vector<int> nd;\n  FastQueue<int> q;\n  vector<int>\
    \ p;\n  vector<int> ch;\n  vector<int> in_q;\n  vector<W> w;\n  vector<W> dist;\n\
    \n  FastAdj<int> g;\n\n  MatroidIntersection() : q(1) { init (); }\n  MatroidIntersection(int\
    \ n, const M1& m1, const M2& m2) : m1(m1), m2(m2), n(n), g(n+2, n), q(n) {\n \
    \   init();\n  }\n  void set_weights(const vector<W>& w_) {\n    assert(n == w_.size());\n\
    \    w = w_;\n  }\n  int size() const { return n; }\n  void init() {\n    vI.reserve(n);\n\
    \    p.assign(n, -1);\n    I.assign(n, false);\n    nd.assign(n, 0);\n  }\n  void\
    \ setup_augment() {\n    vI.clear();\n    g.clear();\n    for(int i = 0; i < n;\
    \ i++) {\n      if(I[i]) vI.push_back(i);\n      nd[i] = 0;\n    }\n  }\n  bool\
    \ is_weighted() const {\n    return !w.empty();\n  }\n  bool augment(int truncate\
    \ = 1e9) {\n    setup_augment();\n    if(vI.size() == min(truncate, n)) return\
    \ false;\n    auto f = lambda::SubsetFilter(n, [this](int i) -> bool { return\
    \ in_I(i); });\n    m1.build(f), m2.build(f);\n    m1.setup(), m2.setup();\n \
    \   // Check potential starting and ending points of the path.\n    // Also, return\
    \ earlier if is both starting and ending point.\n    for(int i = 0; i < n; i++)\
    \ {\n      if(I[i]) continue;\n      if(m1.can_add(i)) nd[i] |= 1;\n      if(m2.can_add(i))\
    \ nd[i] |= 2;\n      if(nd[i] == 3 && !is_weighted()) {\n        I[i] = true;\n\
    \        return true;\n      }\n    }\n    m1.setup_graph(), m2.setup_graph();\n\
    \    for(int i : vI) {\n      I[i] = false;\n      m1.setup_exchange(i), m2.setup_exchange(i);\n\
    \      for(int j = 0; j < n; j++) {\n        if(I[j] || i == j) continue;\n  \
    \      if(m1.can_exchange(i, j)) g.add(i, j);\n        if(m2.can_exchange(i, j))\
    \ g.add(j, i);\n      }\n      I[i] = true;\n      m1.finish_exchange(i), m2.finish_exchange(i);\n\
    \    }\n\n    int st = is_weighted() ? weighted_sp() : unweighted_sp();\n    if(st\
    \ == -1) return false;\n    I[st] ^= 1;\n    while(p[st] != st) {\n      st =\
    \ p[st];\n      I[st] ^= 1;\n    }\n    return true;\n  }\n  int unweighted_sp()\
    \ {\n    q.clear();\n    p.assign(n, -1);\n    for(int i = 0; i < n; i++)\n  \
    \    if(nd[i]&1) q.push(i), p[i] = i;\n\n    int st = -1;\n    while(!q.empty()\
    \ && st == -1) {\n      int u = q.pop();\n      if(nd[u]&2) {\n        st = u;\n\
    \        break;\n      }\n      for(int v : g.n_edges(u)) {\n        if(p[v] ==\
    \ -1) {\n          p[v] = u;\n          q.push(v);\n        }\n      }\n    }\n\
    \    return st;\n  }\n  int weighted_sp() {\n    q.clear();\n    in_q.assign(n,\
    \ 0);\n    p.assign(n, -1);\n    const W oo = numeric_limits<W>::max() / 2;\n\
    \    ch.assign(n, 1e9);\n    dist.assign(n, oo);\n    for(int i = 0; i < n; i++)\n\
    \      if(nd[i]&1)\n        dist[i] = -w[i], ch[i] = 0, p[i] = i, q.push(i), in_q[i]\
    \ = 1;\n    while(!q.empty()) {\n      int i = q.pop();\n      in_q[i] = 0;\n\
    \      for(int v : g.n_edges(i)) {\n        if(v == i) continue;\n        W n_dist\
    \ = dist[i] + (I[v] ? w[v] : -w[v]);\n        int n_ch = ch[i] + 1;\n        using\
    \ ii = pair<W, int>;\n        if(ii(n_dist, n_ch) < ii(dist[v], ch[v])) {\n  \
    \        dist[v] = n_dist;\n          ch[v] = n_ch;\n          p[v] = i;\n   \
    \       if(!in_q[v]) {\n            in_q[v] = 1;\n            q.push(v);\n   \
    \       }\n        }\n      }\n    }\n\n    pair<pair<W, int>, int> best = {{oo,\
    \ 1e9}, -1};\n    for(int i = 0; i < n; i++) {\n      if(nd[i]&2) {\n        best\
    \ = min(best, {{dist[i], ch[i]}, i});\n      }\n    }\n    return best.second;\n\
    \  }\n  vector<int> solve(int truncate = 1e9) {\n    while(augment(truncate));\n\
    \    return I;\n  }\n  W cost() const {\n    W res = 0;\n    for(int i = 0; i\
    \ < n; i++) {\n      if(I[i])\n        res += is_weighted() ? w[i] : 1;\n    }\n\
    \    return res;\n  }\n  int cardinality() const {\n    int res = 0;\n    for(int\
    \ i = 0; i < n; i++)\n      res += I[i];\n    return res;\n  }\n  bool in_I(int\
    \ i) const {\n    return I[i];\n  }\n  void flip(int i) {\n    I[i] ^= 1;\n  }\n\
    \  const vector<int>& get_I() const {\n    return I;\n  }\n};\n\ntemplate<typename\
    \ M1, typename M2>\nshared_ptr<MatroidIntersection<M1, M2>> make_matroid_intersection(int\
    \ n, const M1& m1, const M2& m2) {\n  return make_shared<MatroidIntersection<M1,\
    \ M2>>(n, m1, m2);\n}\ntemplate<typename W, typename M1, typename M2>\nshared_ptr<MatroidIntersection<M1,\
    \ M2, W>> make_weighted_matroid_intersection(int n, const M1& m1, const M2& m2,\
    \ const lambda::Map<W>& f) {\n  auto res = make_shared<MatroidIntersection<M1,\
    \ M2, W>>(n, m1, m2);\n  vector<W> w(n);\n  for(int i = 0; i < n; i++) w[i] =\
    \ f(i);\n  res->set_weights(w);\n  return res;\n}\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_MATROID_INTERSECTION\n#define _LIB_MATROID_INTERSECTION\n#include\
    \ <bits/stdc++.h>\n#include \"../utils/FastAdj.cpp\"\n#include \"../utils/FastQueue.cpp\"\
    \n#include \"../Lambda.cpp\"\n\nnamespace lib {\ntemplate<typename M1, typename\
    \ M2, typename W = int>\nstruct MatroidIntersection {\n  int n;\n  M1 m1;\n  M2\
    \ m2;\n\n  // aux vectors\n  vector<int> vI;\n  vector<int> I;\n  vector<int>\
    \ nd;\n  FastQueue<int> q;\n  vector<int> p;\n  vector<int> ch;\n  vector<int>\
    \ in_q;\n  vector<W> w;\n  vector<W> dist;\n\n  FastAdj<int> g;\n\n  MatroidIntersection()\
    \ : q(1) { init (); }\n  MatroidIntersection(int n, const M1& m1, const M2& m2)\
    \ : m1(m1), m2(m2), n(n), g(n+2, n), q(n) {\n    init();\n  }\n  void set_weights(const\
    \ vector<W>& w_) {\n    assert(n == w_.size());\n    w = w_;\n  }\n  int size()\
    \ const { return n; }\n  void init() {\n    vI.reserve(n);\n    p.assign(n, -1);\n\
    \    I.assign(n, false);\n    nd.assign(n, 0);\n  }\n  void setup_augment() {\n\
    \    vI.clear();\n    g.clear();\n    for(int i = 0; i < n; i++) {\n      if(I[i])\
    \ vI.push_back(i);\n      nd[i] = 0;\n    }\n  }\n  bool is_weighted() const {\n\
    \    return !w.empty();\n  }\n  bool augment(int truncate = 1e9) {\n    setup_augment();\n\
    \    if(vI.size() == min(truncate, n)) return false;\n    auto f = lambda::SubsetFilter(n,\
    \ [this](int i) -> bool { return in_I(i); });\n    m1.build(f), m2.build(f);\n\
    \    m1.setup(), m2.setup();\n    // Check potential starting and ending points\
    \ of the path.\n    // Also, return earlier if is both starting and ending point.\n\
    \    for(int i = 0; i < n; i++) {\n      if(I[i]) continue;\n      if(m1.can_add(i))\
    \ nd[i] |= 1;\n      if(m2.can_add(i)) nd[i] |= 2;\n      if(nd[i] == 3 && !is_weighted())\
    \ {\n        I[i] = true;\n        return true;\n      }\n    }\n    m1.setup_graph(),\
    \ m2.setup_graph();\n    for(int i : vI) {\n      I[i] = false;\n      m1.setup_exchange(i),\
    \ m2.setup_exchange(i);\n      for(int j = 0; j < n; j++) {\n        if(I[j] ||\
    \ i == j) continue;\n        if(m1.can_exchange(i, j)) g.add(i, j);\n        if(m2.can_exchange(i,\
    \ j)) g.add(j, i);\n      }\n      I[i] = true;\n      m1.finish_exchange(i),\
    \ m2.finish_exchange(i);\n    }\n\n    int st = is_weighted() ? weighted_sp()\
    \ : unweighted_sp();\n    if(st == -1) return false;\n    I[st] ^= 1;\n    while(p[st]\
    \ != st) {\n      st = p[st];\n      I[st] ^= 1;\n    }\n    return true;\n  }\n\
    \  int unweighted_sp() {\n    q.clear();\n    p.assign(n, -1);\n    for(int i\
    \ = 0; i < n; i++)\n      if(nd[i]&1) q.push(i), p[i] = i;\n\n    int st = -1;\n\
    \    while(!q.empty() && st == -1) {\n      int u = q.pop();\n      if(nd[u]&2)\
    \ {\n        st = u;\n        break;\n      }\n      for(int v : g.n_edges(u))\
    \ {\n        if(p[v] == -1) {\n          p[v] = u;\n          q.push(v);\n   \
    \     }\n      }\n    }\n    return st;\n  }\n  int weighted_sp() {\n    q.clear();\n\
    \    in_q.assign(n, 0);\n    p.assign(n, -1);\n    const W oo = numeric_limits<W>::max()\
    \ / 2;\n    ch.assign(n, 1e9);\n    dist.assign(n, oo);\n    for(int i = 0; i\
    \ < n; i++)\n      if(nd[i]&1)\n        dist[i] = -w[i], ch[i] = 0, p[i] = i,\
    \ q.push(i), in_q[i] = 1;\n    while(!q.empty()) {\n      int i = q.pop();\n \
    \     in_q[i] = 0;\n      for(int v : g.n_edges(i)) {\n        if(v == i) continue;\n\
    \        W n_dist = dist[i] + (I[v] ? w[v] : -w[v]);\n        int n_ch = ch[i]\
    \ + 1;\n        using ii = pair<W, int>;\n        if(ii(n_dist, n_ch) < ii(dist[v],\
    \ ch[v])) {\n          dist[v] = n_dist;\n          ch[v] = n_ch;\n          p[v]\
    \ = i;\n          if(!in_q[v]) {\n            in_q[v] = 1;\n            q.push(v);\n\
    \          }\n        }\n      }\n    }\n\n    pair<pair<W, int>, int> best =\
    \ {{oo, 1e9}, -1};\n    for(int i = 0; i < n; i++) {\n      if(nd[i]&2) {\n  \
    \      best = min(best, {{dist[i], ch[i]}, i});\n      }\n    }\n    return best.second;\n\
    \  }\n  vector<int> solve(int truncate = 1e9) {\n    while(augment(truncate));\n\
    \    return I;\n  }\n  W cost() const {\n    W res = 0;\n    for(int i = 0; i\
    \ < n; i++) {\n      if(I[i])\n        res += is_weighted() ? w[i] : 1;\n    }\n\
    \    return res;\n  }\n  int cardinality() const {\n    int res = 0;\n    for(int\
    \ i = 0; i < n; i++)\n      res += I[i];\n    return res;\n  }\n  bool in_I(int\
    \ i) const {\n    return I[i];\n  }\n  void flip(int i) {\n    I[i] ^= 1;\n  }\n\
    \  const vector<int>& get_I() const {\n    return I;\n  }\n};\n\ntemplate<typename\
    \ M1, typename M2>\nshared_ptr<MatroidIntersection<M1, M2>> make_matroid_intersection(int\
    \ n, const M1& m1, const M2& m2) {\n  return make_shared<MatroidIntersection<M1,\
    \ M2>>(n, m1, m2);\n}\ntemplate<typename W, typename M1, typename M2>\nshared_ptr<MatroidIntersection<M1,\
    \ M2, W>> make_weighted_matroid_intersection(int n, const M1& m1, const M2& m2,\
    \ const lambda::Map<W>& f) {\n  auto res = make_shared<MatroidIntersection<M1,\
    \ M2, W>>(n, m1, m2);\n  vector<W> w(n);\n  for(int i = 0; i < n; i++) w[i] =\
    \ f(i);\n  res->set_weights(w);\n  return res;\n}\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - utils/FastAdj.cpp
  - utils/FastQueue.cpp
  - Lambda.cpp
  - Traits.cpp
  isVerificationFile: false
  path: matroid/MatroidIntersection.cpp
  requiredBy: []
  timestamp: '2021-02-03 01:52:23-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/MatroidIntersection.cpp
layout: document
redirect_from:
- /library/matroid/MatroidIntersection.cpp
- /library/matroid/MatroidIntersection.cpp.html
title: matroid/MatroidIntersection.cpp
---
