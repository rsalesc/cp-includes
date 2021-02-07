---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Epsilon.cpp
    title: Epsilon.cpp
  - icon: ':warning:'
    path: Lambda.cpp
    title: Lambda.cpp
  - icon: ':warning:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: geometry/GeometryEpsilon.cpp
    title: geometry/GeometryEpsilon.cpp
  - icon: ':warning:'
    path: geometry/Line2D.cpp
    title: geometry/Line2D.cpp
  - icon: ':warning:'
    path: geometry/Trigonometry.cpp
    title: geometry/Trigonometry.cpp
  - icon: ':warning:'
    path: matroid/ColorMatroid.cpp
    title: matroid/ColorMatroid.cpp
  - icon: ':warning:'
    path: matroid/Matroid.cpp
    title: matroid/Matroid.cpp
  - icon: ':warning:'
    path: matroid/MatroidIntersection.cpp
    title: matroid/MatroidIntersection.cpp
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
  bundledCode: "#line 1 \"tests/judge/gopher.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 1 \"matroid/MatroidIntersection.cpp\"\n\n\n#line 1 \"utils/FastAdj.cpp\"\n\n\
    \n#line 4 \"utils/FastAdj.cpp\"\n\nnamespace lib {\n  using namespace std;\ntemplate<typename\
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
    \ f(i);\n  res->set_weights(w);\n  return res;\n}\n} // namespace lib\n\n\n#line\
    \ 1 \"matroid/ColorMatroid.cpp\"\n\n\n#line 1 \"matroid/Matroid.cpp\"\n\n\n#line\
    \ 5 \"matroid/Matroid.cpp\"\n\nnamespace lib {\nstruct Matroid {\n  lambda::SubsetFilter\
    \ I;\n  bool in_I(int i) const {\n    return I(i);\n  }\n  vector<bool> get_I()\
    \ const {\n    return I();\n  }\n  int ground_set_size() const { return I.size();\
    \ }\n\n  /** docstring\n   * Used to build a Matroid object from an M (independent\
    \ set provider).\n   */ \n  virtual void build(const lambda::SubsetFilter& I_)\
    \ {\n    I = I_;\n  }\n\n  void setup() {}\n  void setup_graph() {}\n  void setup_exchange(int\
    \ i) {}\n  void finish_exchange(int i) {}\n\n  bool can_add(int i) { return false;\
    \ }\n  bool can_exchange(int i, int j) { return false; }\n\n  void print_I() {\n\
    \    for(int i = 0; i < I.size(); i++) cout << in_I(i) << \" \";\n    cout <<\
    \ endl;\n  }\n};\n} // namespace lib\n\n\n#line 5 \"matroid/ColorMatroid.cpp\"\
    \n\nnamespace lib {\n  using namespace std;\nstruct ColorMatroid : Matroid {\n\
    \  vector<int> cnt, limits;\n  lambda::Map<int> color;\n  ColorMatroid(vector<int>\
    \ limits, const lambda::Map<int>& color_)\n    : Matroid(), limits(limits), color(color_)\
    \ {}\n  ColorMatroid(int n, int K, const lambda::Map<int>& color_)\n    : Matroid(),\
    \ limits(n, K), color(color_) {}\n  void setup() {\n    cnt.assign(limits.size(),\
    \ 0);\n    for(int i = 0; i < ground_set_size(); i++)\n      if(in_I(i))\n   \
    \     cnt[color(i)]++;\n  }\n  void setup_exchange(int i) {\n    cnt[color(i)]--;\n\
    \  }\n  void finish_exchange(int i) {\n    cnt[color(i)]++;\n  }\n  bool can_exchange(int\
    \ i, int j) {\n    return can_add(j);\n  }\n  bool can_add(int i) {\n    int c\
    \ = color(i);\n    return cnt[c] < limits[c];\n  }\n  void print() const {\n \
    \   for(int x : cnt) cout << x << \" \";\n    cout << endl;\n  }\n};\n} // namespace\
    \ lib\n\n\n#line 1 \"geometry/Line2D.cpp\"\n\n\n#line 1 \"geometry/GeometryEpsilon.cpp\"\
    \n\n\n#line 1 \"Epsilon.cpp\"\n\n\n#line 4 \"Epsilon.cpp\"\n\nnamespace lib {\n\
    using namespace std;\n\ntemplate <typename T = double> struct Epsilon {\n  T eps;\n\
    \  constexpr Epsilon(T eps = 1e-9) : eps(eps) {}\n\n  template <typename G,\n\
    \            typename enable_if<is_floating_point<G>::value>::type * = nullptr>\n\
    \  int operator()(G a, G b = 0) const {\n    return a + eps < b ? -1 : (b + eps\
    \ < a ? 1 : 0);\n  }\n\n  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  int operator()(G a, G b = 0) const {\n    return a < b ? -1\
    \ : (a > b ? 1 : 0);\n  }\n\n  template <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return (*this)(a) == 0;\n  }\n\n\
    \  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return a == 0;\n  }\n};\n} // namespace\
    \ lib\n\n\n#line 5 \"geometry/GeometryEpsilon.cpp\"\n\n#define GEOMETRY_EPSILON(T,\
    \ x)                                                 \\\n  template <>       \
    \                                                           \\\n  lib::Epsilon<T>\
    \ *lib::geo::GeometryEpsilon<T>::eps =                         \\\n      new lib::Epsilon<T>((x));\n\
    \n#define GEOMETRY_COMPARE0(T, x) GeometryEpsilon<T>()((x))\n#define GEOMETRY_COMPARE(T,\
    \ x, y) GeometryEpsilon<T>()((x), (y))\n\nnamespace lib {\nusing namespace std;\n\
    namespace geo {\ntemplate <typename T> struct GeometryEpsilon {\n  static Epsilon<T>\
    \ *eps;\n  template <typename G> int operator()(G a, G b = 0) const {\n    return\
    \ (*eps)(a, b);\n  }\n};\n\nGEOMETRY_EPSILON(int, 0);\nGEOMETRY_EPSILON(long,\
    \ 0);\nGEOMETRY_EPSILON(long long, 0);\n} // namespace geo\n} // namespace lib\n\
    \n\n#line 1 \"geometry/Trigonometry.cpp\"\n\n\n#line 4 \"geometry/Trigonometry.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace geo {\nnamespace trig {\n\
    constexpr static long double PI = acosl(-1);\ndouble cos(double x) { return ::cos(x);\
    \ }\ndouble sin(double x) { return ::sin(x); }\ndouble asin(double x) { return\
    \ ::asin(x); }\ndouble acos(double x) { return ::acos(x); }\ndouble atan2(double\
    \ y, double x) { return ::atan2(y, x); }\nlong double cos(long double x) { return\
    \ ::cosl(x); }\nlong double sin(long double x) { return ::sinl(x); }\nlong double\
    \ asin(long double x) { return ::asinl(x); }\nlong double acos(long double x)\
    \ { return ::acosl(x); }\nlong double atan2(long double y, long double x) { return\
    \ ::atan2l(y, x); }\n} // namespace trig\n} // namespace geo\n} // namespace lib\n\
    \n\n#line 6 \"geometry/Line2D.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace geo {\nnamespace plane {\nnamespace {\ntemplate <typename T> bool scalar_between(T\
    \ a, T o, T b) {\n  if (a > b)\n    swap(a, b);\n  return GEOMETRY_COMPARE(T,\
    \ a, o) <= 0 && GEOMETRY_COMPARE(T, o, b) <= 0;\n}\n\ntemplate <typename T> bool\
    \ scalar_strictly_between(T a, T o, T b) {\n  if (a > b)\n    swap(a, b);\n  int\
    \ x = GEOMETRY_COMPARE(T, a, o);\n  int y = GEOMETRY_COMPARE(T, o, b);\n  return\
    \ x <= 0 && y <= 0 && (x < 0 || y < 0);\n}\n} // namespace\n\ntemplate <typename\
    \ T, typename Large = T> struct Point {\n  T x, y;\n  Point() : x(0), y(0) {}\n\
    \  Point(T x, T y) : x(x), y(y) {}\n  template <typename G, typename H> explicit\
    \ operator Point<G, H>() const {\n    return Point<G, H>((G)x, (G)y);\n  }\n \
    \ friend Point reversed(const Point &a) { return Point(a.y, a.x); }\n  Point &operator+=(const\
    \ Point &rhs) {\n    x += rhs.x, y += rhs.y;\n    return *this;\n  }\n  Point\
    \ &operator-=(const Point &rhs) {\n    x -= rhs.x, y -= rhs.y;\n    return *this;\n\
    \  }\n  Point &operator*=(T k) {\n    x *= k, y *= k;\n    return *this;\n  }\n\
    \  Point &operator/=(T k) {\n    x /= k, y /= k;\n    return *this;\n  }\n  Point\
    \ operator+(const Point &rhs) const {\n    Point res = *this;\n    return res\
    \ += rhs;\n  }\n  Point operator-(const Point &rhs) const {\n    Point res = *this;\n\
    \    return res -= rhs;\n  }\n  Point operator*(T k) const {\n    Point res =\
    \ *this;\n    return res *= k;\n  }\n  Point operator/(T k) const {\n    Point\
    \ res = *this;\n    return res /= k;\n  }\n  Point operator-() const { return\
    \ Point(-x, -y); }\n  inline friend Point convolve(const Point &a, const Point\
    \ &b) {\n    return Point(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);\n  }\n\
    \  inline friend Large cross(const Point &a, const Point &b) {\n    return (Large)a.x\
    \ * b.y - (Large)a.y * b.x;\n  }\n  friend Large cross(const Point &a, const Point\
    \ &b, const Point &c) {\n    return cross(b - a, c - a);\n  }\n  inline friend\
    \ Large dot(const Point &a, const Point &b) {\n    return (Large)a.x * b.x + (Large)a.y\
    \ * b.y;\n  }\n  friend int ccw(const Point &u, const Point &v) {\n    return\
    \ GEOMETRY_COMPARE0(Large, cross(u, v));\n  }\n  friend int ccw(const Point &a,\
    \ const Point &b, const Point &c) {\n    return ccw(b - a, c - a);\n  }\n  friend\
    \ int half_ccw(const Point& u, const Point& v) {\n    int dot_sgn = GEOMETRY_COMPARE0(Large,\
    \ dot(u, v));\n    int ccw_sgn = ccw(u, v);\n    if(dot_sgn == 0) return ccw_sgn\
    \ ? 1 : 0;\n    return dot_sgn * ccw_sgn;\n  }\n  friend Large norm(const Point\
    \ &a) { return sqrtl(dot(a, a)); }\n  friend Large norm_sq(const Point &a) { return\
    \ dot(a, a); }\n  bool is_null() const { return GEOMETRY_COMPARE0(Large, norm_sq(*this))\
    \ == 0; }\n  bool is_versor() const {\n    return GEOMETRY_COMPARE(Large, norm_sq(*this),\
    \ (Large)1) == 0;\n  }\n  static Point polar(Large d, Large theta) {\n    return\
    \ Point(trig::cos(theta) * d, trig::sin(theta) * d);\n  }\n  friend Point rotate(const\
    \ Point &a, Large theta) {\n    return convolve(a, polar((Large)1, theta));\n\
    \  }\n  friend Point ortho(const Point &a) { return Point(-a.y, a.x); }\n  friend\
    \ Large arg(const Point &a) { return trig::atan2(a.y, a.x); }\n  friend Large\
    \ signed_angle(const Point &v, const Point &w) {\n    return remainder(arg(w)\
    \ - arg(v), 2.0 * trig::PI);\n  }\n  friend Large angle(const Point &v, const\
    \ Point &w) {\n    return abs(signed_angle(v, w));\n  }\n  friend Large ccw_angle(const\
    \ Point &v) {\n    Large res = arg(v);\n    if (res < 0)\n      res += 2.0 * trig::PI;\n\
    \    return res;\n  }\n  friend Large ccw_angle(const Point &v, const Point &w)\
    \ {\n    Large res = signed_angle(v, w);\n    if (res < 0)\n      res += 2.0 *\
    \ trig::PI;\n    return res;\n  }\n  inline friend Point normalized(const Point\
    \ &a, Large k) {\n    return a.is_null() ? Point() : a / norm(a) * k;\n  }\n \
    \ inline friend Point versor(const Point &a) { return normalized(a, (Large)1);\
    \ }\n  friend bool collinear(const Point &a, const Point &b) {\n    return GEOMETRY_COMPARE0(Large,\
    \ cross(a, b)) == 0;\n  }\n  friend bool collinear(const Point &a, const Point\
    \ &b, const Point &c) {\n    return collinear(b - a, c - a);\n  }\n  friend Point\
    \ project(const Point &a, const Point &v) {\n    return v / norm_sq(v) * dot(a,\
    \ v);\n  }\n  template <typename G = T,\n            typename enable_if<!is_integral<G>::value>::type\
    \ * = nullptr>\n  friend Point reflect(const Point &a, const Point &v) {\n   \
    \ Point n = versor(v);\n    return a - n * 2 * dot(n, v);\n  }\n  friend bool\
    \ between(const Point &a, const Point &b, const Point &c) {\n    return collinear(a,\
    \ b, c) &&\n           GEOMETRY_COMPARE0(Large, dot(a - b, c - b)) <= 0;\n  }\n\
    \  friend bool strictly_between(const Point &a, const Point &b, const Point &c)\
    \ {\n    return collinear(a, b, c) &&\n           GEOMETRY_COMPARE0(Large, dot(a\
    \ - b, c - b)) < 0;\n  }\n  friend bool collinear_between(const Point a, const\
    \ Point &o, const Point &b) {\n    return scalar_between(a.x, o.x, b.x) && scalar_between(a.y,\
    \ o.y, b.y);\n  }\n  friend bool collinear_strictly_between(const Point &a, const\
    \ Point &o,\n                                         const Point &b) {\n    return\
    \ scalar_between(a.x, o.x, b.x) && scalar_between(a.y, o.y, b.y);\n  }\n  friend\
    \ Large dist(const Point &a, const Point &b) { return norm(a - b); }\n  friend\
    \ bool operator==(const Point &a, const Point &b) {\n    return GEOMETRY_COMPARE(T,\
    \ a.x, b.x) == 0 &&\n           GEOMETRY_COMPARE(T, a.y, b.y) == 0;\n  }\n  friend\
    \ bool operator!=(const Point &a, const Point &b) { return !(a == b); }\n  friend\
    \ bool operator<(const Point &a, const Point &b) {\n    return tie(a.y, a.x) <\
    \ tie(b.y, b.x);\n  }\n  friend bool operator>(const Point &a, const Point &b)\
    \ {\n    return tie(a.y, a.x) > tie(b.y, b.x);\n  }\n  friend bool operator>=(const\
    \ Point &a, const Point &b) {\n    return tie(a.y, a.x) >= tie(b.y, b.x);\n  }\n\
    \  friend bool operator<=(const Point &a, const Point &b) {\n    return tie(a.y,\
    \ a.x) <= tie(b.y, b.x);\n  }\n  friend istream &operator>>(istream &in, Point\
    \ &p) { return in >> p.x >> p.y; }\n  friend ostream &operator<<(ostream &out,\
    \ const Point &p) {\n    return out << p.x << \" \" << p.y;\n  }\n};\n\ntemplate\
    \ <typename T, typename Large = T> struct Rectangle {\n  typedef Point<T, Large>\
    \ point;\n\n  T minx, miny, maxx, maxy;\n  Rectangle() {\n    minx = miny = numeric_limits<T>::max();\n\
    \    maxx = maxy = numeric_limits<T>::min();\n  }\n\n  Rectangle(const initializer_list<point>\
    \ &points) : Rectangle() {\n    for (const auto &p : points) {\n      minx = min(minx,\
    \ p.x);\n      maxx = max(maxx, p.x);\n      miny = min(miny, p.y);\n      maxy\
    \ = max(maxy, p.y);\n    }\n  }\n\n  bool contains(const point &p) const {\n \
    \   return GEOMETRY_COMPARE(T, minx, p.x) <= 0 &&\n           GEOMETRY_COMPARE(T,\
    \ p.x, maxx) <= 0 &&\n           GEOMETRY_COMPARE(T, miny, p.y) <= 0 &&\n    \
    \       GEOMETRY_COMPARE(T, p.y, maxy) <= 0;\n  }\n};\n\ntemplate <typename T,\
    \ typename Large = T> struct Line {\n  typedef Point<T, Large> point;\n  typedef\
    \ Line<T, Large> line;\n  point a, b;\n  Line(point a, point b) : a(a), b(b) {}\n\
    \  template <typename G = T,\n            typename enable_if<!is_integral<G>::value>::type\
    \ * = nullptr>\n  Line(T A, T B, T C) {\n    if (GEOMETRY_COMPARE0(Large, A))\n\
    \      a = point(-C / A, 0), b = point((-C - B) / A, 1);\n    else if (GEOMETRY_COMPARE0(Large,\
    \ B))\n      a = point(0, -C / B), b = point(1, (-C - A) / B);\n    else\n   \
    \   assert(false);\n  }\n  template <typename G, typename H> explicit operator\
    \ Line<G, H>() const {\n    return Line<G, H>(Point<G, H>(a), Point<G, H>(b));\n\
    \  }\n  point direction() const { return b - a; }\n  friend point project(const\
    \ point &p, const line &v) {\n    return project(p - v.a, v.b - v.a) + v.a;\n\
    \  }\n  friend bool collinear(const line &u, const line &v) {\n    return collinear(u.a,\
    \ u.b, v.a) && collinear(u.a, u.b, v.b);\n  }\n  bool contains(const point &p)\
    \ const { return collinear(a, b, p); }\n  friend bool parallel(const line &u,\
    \ const line &v) {\n    return collinear(u.b - u.a, v.b - v.a);\n  }\n  friend\
    \ bool opposite(const line &l, const point &p1, const point &p2) {\n    int x\
    \ = GEOMETRY_COMPARE0(Large, cross(p1 - l.a, l.direction()));\n    int y = GEOMETRY_COMPARE0(Large,\
    \ cross(p2 - l.a, l.direction()));\n    return x * y <= 0;\n  }\n  friend pair<point,\
    \ bool> intersect(const line &l1, const line &l2) {\n    Large c1 = cross(l2.a\
    \ - l1.a, l1.b - l1.a);\n    Large c2 = cross(l2.b - l1.a, l1.b - l1.a);\n   \
    \ if (GEOMETRY_COMPARE0(Large, c1 - c2) == 0)\n      return {{}, false};\n   \
    \ return {(l2.b * c1 - l2.a * c2) / (c1 - c2), true};\n  }\n  friend bool has_unique_intersection(const\
    \ line &l1, const line &l2) {\n    return !parallel(l1, l2);\n  }\n  friend bool\
    \ has_intersection(const line &l1, const line &l2) {\n    return collinear(l1,\
    \ l2) || has_unique_intersection(l1, l2);\n  }\n  friend Large dist(const line\
    \ &l1, const point &p) {\n    // TODO: improve this\n    return dist(p, project(p,\
    \ l1));\n  }\n  friend Large dist(const line &l1, const line &l2) {\n    if (has_intersection(l1,\
    \ l2))\n      return 0;\n    // TODO: improve this\n    return dist(l1.a, project(l1.a,\
    \ l2));\n  }\n};\n\ntemplate <typename T, typename Large = T> struct Ray {\n \
    \ typedef Point<T, Large> point;\n  typedef Line<T, Large> line;\n  typedef Ray<T,\
    \ Large> ray;\n  point a, b;\n\n  Ray(point a, point direction) : a(a), b(a +\
    \ direction) {}\n\n  static ray from_points(point a, point b) { return ray(a,\
    \ b - a); }\n  point direction() const { return b - a; }\n  point direction_versor()\
    \ const { return versor(direction()); }\n\n  line as_line() const { return line(a,\
    \ b); }\n  explicit operator line() const { return as_line(); }\n\n  template\
    \ <typename G, typename H> explicit operator Ray<G, H>() const {\n    return Ray<G,\
    \ H>(Point<G, H>(a), Point<G, H>(b));\n  }\n  bool contains(const point &p) const\
    \ {\n    return collinear(a, b, p) &&\n           GEOMETRY_COMPARE0(Large, dot(p\
    \ - a, b - a)) >= 0;\n  }\n  bool strictly_contains(const point &p) const {\n\
    \    return collinear(a, b, p) &&\n           GEOMETRY_COMPARE0(Large, dot(p -\
    \ a, b - a)) > 0;\n  }\n  bool collinear_contains(const point &p) const {\n  \
    \  point dir = direction();\n    int dx = GEOMETRY_COMPARE0(T, dir.x);\n    if\
    \ (dx == 0)\n      return GEOMETRY_COMPARE0(T, dir.y) * GEOMETRY_COMPARE0(T, p.y\
    \ - a.y) >= 0;\n    else\n      return dx * GEOMETRY_COMPARE0(T, p.x - a.x) >=\
    \ 0;\n  }\n  bool collinear_strictly_contains(const point &p) const {\n    point\
    \ dir = direction();\n    int dx = GEOMETRY_COMPARE0(T, dir.x);\n    if (dx ==\
    \ 0)\n      return GEOMETRY_COMPARE0(T, dir.y) * GEOMETRY_COMPARE0(T, p.y - a.y)\
    \ > 0;\n    else\n      return dx * GEOMETRY_COMPARE0(T, p.x - a.x) > 0;\n  }\n\
    \  friend pair<point, bool> intersect(const ray &r, const line &l) {\n    auto\
    \ p = intersect(r.as_line(), l);\n    if (!p.second)\n      return {{}, false};\n\
    \    if (!r.collinear_contains(p.first))\n      return {{}, false};\n    return\
    \ p;\n  }\n  friend pair<point, bool> intersect(const ray &a, const ray &b) {\n\
    \    auto p = intersect(a, b.as_line());\n    if (!p.second)\n      return {{},\
    \ false};\n    if (!b.collinear_contains(p.first))\n      return {{}, false};\n\
    \    return p;\n  }\n  friend bool has_unique_intersection(const ray &r, const\
    \ line &l) {\n    if (!has_unique_intersection(r.as_line(), l))\n      return\
    \ false;\n    int x = GEOMETRY_COMPARE0(Large, cross(r.direction(), l.direction()));\n\
    \    int y = GEOMETRY_COMPARE0(Large, cross(r.a - l.a, l.direction()));\n    return\
    \ x * y <= 0;\n  }\n  friend bool has_intersection(const ray &r, const line &l)\
    \ {\n    return collinear(r.as_line(), l) || has_unique_intersection(r, l);\n\
    \  }\n  friend bool has_unique_intersection(const ray &r1, const ray &r2) {\n\
    \    // TODO: not efficient\n    return has_unique_intersection(r1, r2.as_line())\
    \ &&\n           has_unique_intersection(r2, r1.as_line());\n  }\n  friend bool\
    \ has_intersection(const ray &r1, const ray &r2) {\n    return r1.contains(r2.a)\
    \ || has_unique_intersection(r1, r2);\n  }\n  friend Large dist(const ray &r,\
    \ const point &p) {\n    if (GEOMETRY_COMPARE0(Large, dot(r.direction(), p - r.a))\
    \ < 0)\n      return dist(p, r.a);\n    return dist(r.as_line(), p);\n  }\n  friend\
    \ Large dist(const ray &r, const line &l) {\n    if (has_intersection(r, l))\n\
    \      return Large(0);\n    return dist(l, r.a);\n  }\n  friend Large dist(const\
    \ ray &r1, const ray &r2) {\n    if (has_intersection(r1, r2))\n      return Large(0);\n\
    \    return min(dist(r1, r2.a), dist(r2, r1.a));\n  }\n};\n\ntemplate <typename\
    \ T, typename Large = T> struct Segment {\n  typedef Point<T, Large> point;\n\
    \  typedef Line<T, Large> line;\n  typedef Segment<T, Large> segment;\n  typedef\
    \ Ray<T, Large> ray;\n  point a, b;\n\n  Segment() {}\n  Segment(point a, point\
    \ b) : a(a), b(b) {}\n  line as_line() const { return line(a, b); }\n  explicit\
    \ operator line() const { return as_line(); }\n  bool is_degenerate() const {\
    \ return a == b; }\n\n  template <typename G, typename H> explicit operator Segment<G,\
    \ H>() const {\n    return Segment<G, H>(Point<G, H>(a), Point<G, H>(b));\n  }\n\
    \  bool contains(const point &p) const { return between(a, p, b); }\n  bool strictly_contains(const\
    \ point &p) const {\n    return strictly_between(a, p, b);\n  }\n  bool collinear_contains(const\
    \ point &p) const {\n    return collinear_between(a, p, b);\n  }\n  bool collinear_strictly_contains(const\
    \ point &p) const {\n    return collinear_strictly_between(a, p, b);\n  }\n  friend\
    \ pair<point, bool> intersect(const segment &s, const line &l) {\n    auto p =\
    \ intersect(s.as_line(), l);\n    if (!p.second)\n      return {{}, false};\n\
    \    if (!s.collinear_contains(p.first))\n      return {{}, false};\n    return\
    \ p;\n  }\n  friend pair<point, bool> intersect(const segment &s, const ray &r)\
    \ {\n    auto p = intersect(s.as_line(), r.as_line());\n    if (!p.second)\n \
    \     return {{}, false};\n    if (!s.collinear_contains(p.first) || !r.collinear_contains(p.first))\n\
    \      return {{}, false};\n    return p;\n  }\n  friend pair<segment, int> intersect_segment(segment\
    \ s1, segment s2) {\n    if (collinear(s1.as_line(), s2.as_line())) {\n      if\
    \ (s1.a > s1.b)\n        swap(s1.a, s1.b);\n      if (s2.a > s2.b)\n        swap(s2.a,\
    \ s2.b);\n      segment res(max(s1.a, s2.a), min(s1.b, s2.b));\n      return {res,\
    \ int(res.a <= res.b) * 2};\n    } else {\n      auto p = intersect(s1, s2);\n\
    \      return {segment(p.first, p.first), p.second};\n    }\n  }\n  friend pair<point,\
    \ bool> intersect(const segment &s1, const segment &s2) {\n    auto p = intersect(s1,\
    \ s2.as_line());\n    if (!p.second)\n      return {{}, false};\n    if (!s2.collinear_contains(p.first))\n\
    \      return {{}, false};\n    return p;\n  }\n  friend bool has_unique_intersection(const\
    \ segment &s, const line &l) {\n    if (!has_unique_intersection(s.as_line(),\
    \ l))\n      return false;\n    return opposite(l, s.a, s.b);\n  }\n  friend bool\
    \ has_intersection(const segment &s, const line &l) {\n    return collinear(s.as_line(),\
    \ l) || has_unique_intersection(s, l);\n  }\n  friend bool has_unique_intersection(const\
    \ segment &s, const ray &r) {\n    if (!has_unique_intersection(r, s.as_line()))\n\
    \      return false;\n    return opposite(r.as_line(), s.a, s.b);\n  }\n  friend\
    \ bool has_intersection(const segment &s, const ray &r) {\n    return r.contains(s.a)\
    \ || r.contains(s.b) || has_unique_intersection(s, r);\n  }\n  friend bool has_unique_intersection(const\
    \ segment &s1, const segment &s2) {\n    if (!has_unique_intersection(s1.as_line(),\
    \ s2.as_line()))\n      return false;\n    return opposite(s2.as_line(), s1.a,\
    \ s1.b) &&\n           opposite(s1.as_line(), s2.a, s2.b);\n  }\n  friend bool\
    \ has_intersection(const segment &s1, const segment &s2) {\n    return s1.contains(s2.a)\
    \ || s1.contains(s2.b) ||\n           has_unique_intersection(s1, s2);\n  }\n\
    \  friend Large dist(const segment &s, const point &p) {\n    if (GEOMETRY_COMPARE0(Large,\
    \ dot(p - s.a, s.b - s.a)) <= 0)\n      return dist(s.a, p);\n    if (GEOMETRY_COMPARE0(Large,\
    \ dot(p - s.b, s.a - s.b)) <= 0)\n      return dist(s.b, p);\n    return dist(s.as_line(),\
    \ p);\n  }\n  friend Large dist(const segment &s, const line &l) {\n    if (has_intersection(s,\
    \ l))\n      return Large(0);\n    return min(dist(l, s.a), dist(l, s.b));\n \
    \ }\n  friend Large dist(const segment &s, const ray &r) {\n    if (has_intersection(s,\
    \ r))\n      return Large(0);\n    return min({dist(r, s.a), dist(r, s.b), dist(s,\
    \ r.a)});\n  }\n  friend Large dist(const segment &s1, const segment &s2) {\n\
    \    if (has_intersection(s1, s2))\n      return Large(0);\n    return min(\n\
    \        {dist(s1, s2.a), dist(s1, s2.b), dist(s2, s1.a), dist(s2, s1.b)});\n\
    \  }\n\n  friend bool operator==(const segment &l1, const segment &l2) {\n   \
    \ return tie(l1.a, l1.b) == tie(l2.a, l2.b);\n  }\n  friend bool operator!=(const\
    \ segment &l1, const segment &l2) {\n    return !(l1 == l2);\n  }\n  friend bool\
    \ operator<(const segment &l1, const segment &l2) {\n    return tie(l1.a, l1.b)\
    \ < tie(l2.a, l2.b);\n  }\n};\n\ntemplate <typename Direction, typename T, typename\
    \ Large> struct AngleComparator {\n  using type = typename Direction::type;\n\
    \  using point = Point<T, Large>;\n\n  Direction dir;\n  AngleComparator() {}\n\
    \  AngleComparator(Direction dir) : dir(dir) {}\n  bool operator()(const type\
    \ &a, const type &b) const {\n    return ccw(dir(a), dir(b)) > 0;\n  }\n  template\
    \ <typename Iterator>\n  static void sortByAngle(Iterator begin, Iterator end,\
    \ const Direction& dir = Direction()) {\n    AngleComparator cmp(dir);\n    begin\
    \ =\n        partition(begin, end, [&dir](const type &p) { return dir(p).is_null();\
    \ });\n    auto half =\n        partition(begin, end, [&dir](const type &p) {\
    \ return dir(p) > point(); });\n    sort(begin, half, cmp);\n    sort(half, end,\
    \ cmp);\n  }\n  template <typename Iterator>\n  static Iterator minByAngle(Iterator\
    \ begin, Iterator end, const Direction& dir = Direction()) {\n    AngleComparator\
    \ cmp(dir);\n    return min_element(begin, end, [&dir, &cmp](const type& a, const\
    \ type& b) {\n      bool part_a = dir(a) > point();\n      bool part_b = dir(b)\
    \ > point();\n      if(part_a == part_b)\n        return cmp(a, b);\n      return\
    \ part_a > part_b;\n    });\n  }\n};\ntemplate <typename Ray> struct RayDirection\
    \ {\n  using point = typename Ray::point;\n  using type = Ray;\n  point operator()(const\
    \ type& rhs) const {\n    return rhs.direction();\n  }\n};\ntemplate <typename\
    \ Point> struct PointDirection {\n  using type = Point;\n  Point pivot;\n  PointDirection()\
    \ : pivot() {}\n  PointDirection(Point pivot) : pivot(pivot) {}\n  Point operator()(const\
    \ Point& rhs) const {\n    return (rhs - pivot).direction();\n  }\n};\n} // namespace\
    \ plane\n\ntemplate <typename T, typename Large = T> struct CartesianPlane {\n\
    \  typedef plane::Point<T, Large> point;\n  typedef plane::Line<T, Large> line;\n\
    \  typedef plane::Rectangle<T, Large> rectangle;\n  typedef plane::Segment<T,\
    \ Large> segment;\n  typedef plane::Ray<T, Large> ray;\n\n  template<typename\
    \ Direction>\n  using angle_comparator = plane::AngleComparator<Direction, T,\
    \ Large>;\n};\n\n} // namespace geo\n} // namespace lib\n\n\n#line 5 \"tests/judge/gopher.cpp\"\
    \nusing namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n#define\
    \ pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(),\
    \ (v).end()\n#define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\nGEOMETRY_EPSILON(LD,\
    \ 1e-9);\nusing G = lib::geo::CartesianPlane<LD>;\n\nint32_t main() {\n  iopt;\n\
    \n  int L, R;\n  while(cin >> L >> R) {\n    int s, V;\n    cin >> s >> V;\n\n\
    \    vector<G::point> LL, RR;\n    for(int i = 0; i < L; i++) {\n      G::point\
    \ p;\n      cin >> p;\n      LL.pb(p);\n    }\n    for(int i = 0; i < R; i++)\
    \ {\n      G::point p;\n      cin >> p;\n      RR.pb(p);\n    }\n\n    vector<pair<int,\
    \ int>> v;\n    for(int i = 0; i < L; i++) {\n      for(int j = 0; j < R; j++)\
    \ {\n        if(norm(LL[i] - RR[j]) / V < (LD)s)\n          v.pb({i, j});\n  \
    \    }\n    }\n\n    lib::ColorMatroid mL(L, 1, [v](int i) { return v[i].ff; });\n\
    \    lib::ColorMatroid mR(R, 1, [v](int i) { return v[i].ss; });\n    auto mi\
    \ = lib::make_matroid_intersection(v.size(), mL, mR);\n\n    auto res = mi->solve();\n\
    \    vector<int> ans;\n    for(int i = 0; i < v.size(); i++) if(res[i]) ans.pb(i);\n\
    \n    cout << ans.size() << endl;\n  }\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"matroid/MatroidIntersection.cpp\"\n\
    #include \"matroid/ColorMatroid.cpp\"\n#include \"geometry/Line2D.cpp\"\nusing\
    \ namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n#define pb push_back\n\
    #define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n\
    #define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\nGEOMETRY_EPSILON(LD,\
    \ 1e-9);\nusing G = lib::geo::CartesianPlane<LD>;\n\nint32_t main() {\n  iopt;\n\
    \n  int L, R;\n  while(cin >> L >> R) {\n    int s, V;\n    cin >> s >> V;\n\n\
    \    vector<G::point> LL, RR;\n    for(int i = 0; i < L; i++) {\n      G::point\
    \ p;\n      cin >> p;\n      LL.pb(p);\n    }\n    for(int i = 0; i < R; i++)\
    \ {\n      G::point p;\n      cin >> p;\n      RR.pb(p);\n    }\n\n    vector<pair<int,\
    \ int>> v;\n    for(int i = 0; i < L; i++) {\n      for(int j = 0; j < R; j++)\
    \ {\n        if(norm(LL[i] - RR[j]) / V < (LD)s)\n          v.pb({i, j});\n  \
    \    }\n    }\n\n    lib::ColorMatroid mL(L, 1, [v](int i) { return v[i].ff; });\n\
    \    lib::ColorMatroid mR(R, 1, [v](int i) { return v[i].ss; });\n    auto mi\
    \ = lib::make_matroid_intersection(v.size(), mL, mR);\n\n    auto res = mi->solve();\n\
    \    vector<int> ans;\n    for(int i = 0; i < v.size(); i++) if(res[i]) ans.pb(i);\n\
    \n    cout << ans.size() << endl;\n  }\n}\n"
  dependsOn:
  - matroid/MatroidIntersection.cpp
  - utils/FastAdj.cpp
  - utils/FastQueue.cpp
  - Lambda.cpp
  - Traits.cpp
  - matroid/ColorMatroid.cpp
  - matroid/Matroid.cpp
  - geometry/Line2D.cpp
  - geometry/GeometryEpsilon.cpp
  - Epsilon.cpp
  - geometry/Trigonometry.cpp
  isVerificationFile: false
  path: tests/judge/gopher.cpp
  requiredBy: []
  timestamp: '2021-02-03 01:52:23-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/gopher.cpp
layout: document
redirect_from:
- /library/tests/judge/gopher.cpp
- /library/tests/judge/gopher.cpp.html
title: tests/judge/gopher.cpp
---
