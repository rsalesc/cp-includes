---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Bitset.cpp
    title: Bitset.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tests/judge/bitset.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 1 \"Bitset.cpp\"\n\n\n#line 4 \"Bitset.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\n\nnamespace {\ntemplate <typename T> T maskout(size_t cnt, size_t n, T\
    \ x) {\n  size_t trailing = cnt - n;\n  return x & ((~0) >> trailing);\n}\n} //\
    \ namespace\n\ntemplate <typename T = uint64_t> struct Bitset {\n  const static\
    \ size_t B = sizeof(T) << 3;\n  const static size_t BUCKET_SIZE = B;\n  const\
    \ static size_t SHIFT = 31 - __builtin_clz(B);\n  const static size_t MASK = B\
    \ - 1;\n\n  size_t n, bucket_cnt;\n  vector<T> v;\n\n  Bitset(size_t n) : n(n),\
    \ bucket_cnt((n + B - 1) >> SHIFT), v(bucket_cnt) {\n    assert(bucket_cnt > 0);\n\
    \  }\n\n  void maskout_last() {\n    size_t trailing = (bucket_cnt << SHIFT) -\
    \ n;\n    v.back() &= (~0) >> trailing;\n  }\n\n  void resize(size_t n) {\n  \
    \  this->n = n;\n    size_t new_bucket_cnt = (n + B - 1) >> SHIFT;\n    if (new_bucket_cnt\
    \ != bucket_cnt)\n      v.resize(new_bucket_cnt);\n    bucket_cnt = new_bucket_cnt;\n\
    \    maskout_last();\n    assert(bucket_cnt > 0);\n  }\n\n  void extend_to(size_t\
    \ nw) {\n    return;\n    if (nw > n)\n      resize(nw);\n  }\n\n  inline int\
    \ size() const { return n; }\n\n  inline bool operator[](int pos) const { return\
    \ test(pos); }\n\n  inline bool test(size_t pos) const {\n    return (v[pos >>\
    \ SHIFT] >> (pos & MASK)) & (T)1;\n  }\n\n  Bitset<T> &set() {\n    for (T &x\
    \ : v)\n      x = ~0;\n    maskout_last();\n    return *this;\n  }\n\n  Bitset<T>\
    \ &reset() {\n    for (T &x : v)\n      x = 0;\n    return *this;\n  }\n\n  Bitset<T>\
    \ &flip() {\n    for (T &x : v)\n      x = ~x;\n    maskout_last();\n    return\
    \ *this;\n  }\n\n  Bitset<T> &set(size_t pos) {\n    assert(pos < n);\n    v[pos\
    \ >> SHIFT] |= ((T)1 << (pos & MASK));\n    return *this;\n  }\n\n  Bitset<T>\
    \ &reset(size_t pos) {\n    assert(pos < n);\n    v[pos >> SHIFT] &= ~((T)1 <<\
    \ (pos & MASK));\n    return *this;\n  }\n\n  Bitset<T> &set(size_t pos, bool\
    \ value) {\n    if (!value)\n      reset(pos);\n    else\n      set(pos);\n  \
    \  return *this;\n  }\n\n  Bitset<T> &flip(size_t pos) {\n    assert(pos < n);\n\
    \    v[pos >> SHIFT] ^= ((T)1 << (pos & MASK));\n    return *this;\n  }\n\n  int\
    \ count() const {\n    size_t res = 0;\n    for (size_t i = 0; i < bucket_cnt;\
    \ i++)\n      res += __builtin_popcountll((uint64_t)v[i]);\n    return res;\n\
    \  }\n\n  bool any() const {\n    for (size_t i = 0; i < bucket_cnt; i++)\n  \
    \    if (v[i])\n        return true;\n    return false;\n  }\n\n  bool none()\
    \ const { return !any(); }\n\n  bool all() const { return (~*this).none(); }\n\
    \n  Bitset<T> &operator|=(const Bitset<T> &rhs) {\n    assert(n >= rhs.n);\n \
    \   for (size_t i = 0; i < rhs.bucket_cnt; i++)\n      v[i] |= rhs.v[i];\n   \
    \ return *this;\n  }\n\n  Bitset<T> &operator^=(const Bitset<T> &rhs) {\n    assert(n\
    \ >= rhs.n);\n    for (size_t i = 0; i < rhs.bucket_cnt; i++)\n      v[i] ^= rhs.v[i];\n\
    \    return *this;\n  }\n\n  Bitset<T> &operator&=(const Bitset<T> &rhs) {\n \
    \   assert(n >= rhs.n);\n    for (size_t i = 0; i < rhs.bucket_cnt; i++)\n   \
    \   v[i] &= rhs.v[i];\n    return *this;\n  }\n\n  void do_left_shift(size_t shift)\
    \ {\n    if (bucket_cnt == 0)\n      return;\n    int wshift = min(shift >> SHIFT,\
    \ bucket_cnt);\n    if (wshift < bucket_cnt) {\n      int offset = shift & MASK;\n\
    \      if (offset == 0) {\n        for (int i = (int)bucket_cnt - 1; i >= wshift;\
    \ i--) {\n          v[i] = v[i - wshift];\n        }\n      } else {\n       \
    \ int sub_offset = B - offset;\n        for (int i = (int)bucket_cnt - 1; i >\
    \ wshift; i--) {\n          v[i] =\n              ((v[i - wshift] << offset) |\
    \ (v[i - wshift - 1] >> sub_offset));\n        }\n        v[wshift] = v[0] <<\
    \ offset;\n      }\n    }\n    fill(v.begin(), v.begin() + wshift, (T)0);\n  \
    \  maskout_last();\n  }\n\n  void do_right_shift(size_t shift) {\n    if (bucket_cnt\
    \ == 0)\n      return;\n    int wshift = min(shift >> SHIFT, bucket_cnt);\n  \
    \  int limit = (int)bucket_cnt - wshift - 1;\n\n    if (wshift < bucket_cnt) {\n\
    \      int offset = shift & MASK;\n\n      if (offset == 0) {\n        for (int\
    \ i = 0; i <= limit; i++)\n          v[i] = v[i + wshift];\n      } else {\n \
    \       int sub_offset = (int)B - offset;\n        for (int i = 0; i < limit;\
    \ i++) {\n          v[i] =\n              ((v[i + wshift] >> offset) | (v[i +\
    \ wshift + 1] << sub_offset));\n        }\n        v[limit] = v[bucket_cnt - 1]\
    \ >> offset;\n      }\n    }\n\n    fill(v.begin() + (limit + 1), v.end(), (T)0);\n\
    \  }\n\n  Bitset<T> &operator<<=(size_t shift) {\n    do_left_shift(shift);\n\
    \    return *this;\n  }\n\n  Bitset<T> &operator>>=(size_t shift) {\n    do_right_shift(shift);\n\
    \    return *this;\n  }\n\n  Bitset<T> operator~() const {\n    Bitset<T> res\
    \ = *this;\n    for (size_t i = 0; i < bucket_cnt; i++)\n      res.v[i] = ~res.v[i];\n\
    \    res.maskout_last();\n    return res;\n  }\n\n  bool operator==(const Bitset<T>\
    \ &rhs) const {\n    if (n != rhs.n)\n      return false;\n    for (size_t i =\
    \ 0; i < bucket_cnt; i++)\n      if (v[i] != rhs.v[i])\n        return false;\n\
    \    return true;\n  }\n\n  bool operator!=(const Bitset<T> &rhs) const { return\
    \ !(*this == rhs); }\n\n  bool operator<(const Bitset<T>& rhs) const {\n    int\
    \ b = min(bucket_cnt, rhs.bucket_cnt);\n    for(int i = 0; i < b; i++) {\n   \
    \   if(v[i] != rhs.v[i])\n        return v[i] < rhs.v[i];\n    }\n    return n\
    \ < rhs.n;\n  }\n\n  Bitset<T> operator|(const Bitset<T> &rhs) const {\n    if\
    \ (rhs.n > n)\n      return Bitset<T>(rhs) |= *this;\n    return Bitset<T>(*this)\
    \ |= rhs;\n  }\n\n  Bitset<T> operator^(const Bitset<T> &rhs) const {\n    if\
    \ (rhs.n > n)\n      return Bitset<T>(rhs) ^= *this;\n    return Bitset<T>(*this)\
    \ ^= rhs;\n  }\n\n  Bitset<T> operator&(const Bitset<T> &rhs) const {\n    if\
    \ (rhs.n > n)\n      return Bitset<T>(rhs) &= *this;\n    return Bitset<T>(*this)\
    \ &= rhs;\n  }\n\n  Bitset<T> operator<<(size_t shift) const {\n    return Bitset<T>(*this)\
    \ <<= shift;\n  }\n\n  Bitset<T> operator>>(size_t shift) const {\n    return\
    \ Bitset<T>(*this) >>= shift;\n  }\n\n  friend ostream &operator<<(ostream &output,\
    \ const Bitset<T> &rhs) {\n    for (int i = (int)rhs.n - 1; i >= 0; i--)\n   \
    \   output << rhs[i];\n    return output;\n  }\n\n  static Bitset<T> from_int(T\
    \ x) {\n    auto b = Bitset<T>(B);\n    b.v[0] = x;\n    return b;\n  }\n  \n\
    \  T to_int() const {\n    return v[0];\n  }\n};\n\nusing Bitset64 = Bitset<uint64_t>;\n\
    using Bitset32 = Bitset<uint32_t>;\n} // namespace lib\n\n\n#line 3 \"tests/judge/bitset.cpp\"\
    \n\nusing namespace std;\n\ntypedef lib::Bitset32 Bitset;\n\ntemplate<int N>\n\
    bool compare(const bitset<N>& std_bs, const Bitset& lib_bs) {\n  for(int i = 0;\
    \ i < N; i++)\n    if(std_bs[i] != lib_bs[i])\n      return false;\n  return true;\n\
    }\n\ntemplate<int N>\npair<bitset<N>, Bitset> random() {\n  bitset<N> std_bs;\n\
    \  Bitset lib_bs(N);\n  \n  for(int i = 0; i < N; i++) {\n    int x = rand()%2;\n\
    \    std_bs.set(i, x);\n    lib_bs.set(i, x);\n  }\n\n  if(!compare<N>(std_bs,\
    \ lib_bs))\n    throw logic_error(\"difference in assignment\");\n\n  return {std_bs,\
    \ lib_bs};\n}\n\ntemplate<typename A>\nvoid benchmark_one(const A& bs, int n)\
    \ {\n  A a = bs;\n  a = bs ^ (bs >> (n/2));\n  a = bs | (bs << (n/2));\n  a =\
    \ bs ^ bs;\n  a = bs | bs;\n  a = bs & bs;\n  a <<= (n/16);\n  a >>= (n/16);\n\
    \  a = ~bs;\n\n  for(int i = 0; i < n; i += 2)\n    bool x = a[i];\n  for(int\
    \ i = 1; i < n; i += 3)\n    a.reset(i);\n  for(int i = 2; i < n; i += 5)\n  \
    \  a.set(i);\n\n  int x = a.count();\n  bool y = a.any();\n  bool z = a.none();\n\
    \  bool w = a.all();\n  a = a.flip();\n  a = a.set();\n  a = a.reset();\n}\n\n\
    template<typename A>\nvoid benchmark_all(const vector<A>& v, int n, string name)\
    \ {\n  clock_t start_clock = clock();\n  for(const A& a : v)\n    benchmark_one(a,\
    \ n);\n  cout << name << \" takes \" << ((clock() - start_clock) * 1000.0 / CLOCKS_PER_SEC)\
    \ << endl;\n}\n\ntemplate<int N>\nvoid benchmark(int samples) {\n  cout << \"\
    Benchmarking for n = \" << N << endl;\n\n  vector<bitset<N>> va;\n  vector<Bitset>\
    \ vb;\n  for(int i = 0; i < samples; i++) {\n    auto p = random<N>();\n    va.push_back(p.first);\n\
    \    vb.push_back(p.second);\n  }\n\n  benchmark_all(va, N, \"bitset<>\");\n \
    \ benchmark_all(vb, N, \"lib::Bitset64\");\n}\n\ntemplate<int N>\nvoid test()\
    \ {\n  for(int i = 0; i < 50; i++) {\n    auto p = random<N>();\n    auto q =\
    \ random<N>();\n\n    if(!compare<N>(p.first ^ q.first, p.second ^ q.second))\n\
    \      throw logic_error(\"difference in binary xor\");\n\n    if(!compare<N>(p.first\
    \ | q.first, p.second | q.second))\n      throw logic_error(\"difference in binary\
    \ or\");\n\n    if(!compare<N>(p.first & q.first, p.second & q.second))\n    \
    \  throw logic_error(\"difference in binary and\");\n\n    if(!compare<N>(~p.first,\
    \ ~p.second))\n      throw logic_error(\"difference in unary negation\");\n\n\
    \    for(int j = 0; j < 7; j++) {\n      int sz = rand() % (2*N);\n      if(!compare<N>(p.first\
    \ << sz, p.second << sz))\n        throw logic_error(\"difference on left shift\"\
    );\n\n      if(!compare<N>(p.first >> sz, p.second >> sz))\n        throw logic_error(\"\
    difference on right shift\");\n    }\n  }\n}\n\nint main() {\n  test<1>();\n \
    \ test<2>();\n  test<4>();\n  test<8>();\n  test<(1<<16)>();\n  test<129831>();\n\
    \  \n  benchmark<129831>(10000);\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"../../Bitset.cpp\"\n\nusing namespace\
    \ std;\n\ntypedef lib::Bitset32 Bitset;\n\ntemplate<int N>\nbool compare(const\
    \ bitset<N>& std_bs, const Bitset& lib_bs) {\n  for(int i = 0; i < N; i++)\n \
    \   if(std_bs[i] != lib_bs[i])\n      return false;\n  return true;\n}\n\ntemplate<int\
    \ N>\npair<bitset<N>, Bitset> random() {\n  bitset<N> std_bs;\n  Bitset lib_bs(N);\n\
    \  \n  for(int i = 0; i < N; i++) {\n    int x = rand()%2;\n    std_bs.set(i,\
    \ x);\n    lib_bs.set(i, x);\n  }\n\n  if(!compare<N>(std_bs, lib_bs))\n    throw\
    \ logic_error(\"difference in assignment\");\n\n  return {std_bs, lib_bs};\n}\n\
    \ntemplate<typename A>\nvoid benchmark_one(const A& bs, int n) {\n  A a = bs;\n\
    \  a = bs ^ (bs >> (n/2));\n  a = bs | (bs << (n/2));\n  a = bs ^ bs;\n  a = bs\
    \ | bs;\n  a = bs & bs;\n  a <<= (n/16);\n  a >>= (n/16);\n  a = ~bs;\n\n  for(int\
    \ i = 0; i < n; i += 2)\n    bool x = a[i];\n  for(int i = 1; i < n; i += 3)\n\
    \    a.reset(i);\n  for(int i = 2; i < n; i += 5)\n    a.set(i);\n\n  int x =\
    \ a.count();\n  bool y = a.any();\n  bool z = a.none();\n  bool w = a.all();\n\
    \  a = a.flip();\n  a = a.set();\n  a = a.reset();\n}\n\ntemplate<typename A>\n\
    void benchmark_all(const vector<A>& v, int n, string name) {\n  clock_t start_clock\
    \ = clock();\n  for(const A& a : v)\n    benchmark_one(a, n);\n  cout << name\
    \ << \" takes \" << ((clock() - start_clock) * 1000.0 / CLOCKS_PER_SEC) << endl;\n\
    }\n\ntemplate<int N>\nvoid benchmark(int samples) {\n  cout << \"Benchmarking\
    \ for n = \" << N << endl;\n\n  vector<bitset<N>> va;\n  vector<Bitset> vb;\n\
    \  for(int i = 0; i < samples; i++) {\n    auto p = random<N>();\n    va.push_back(p.first);\n\
    \    vb.push_back(p.second);\n  }\n\n  benchmark_all(va, N, \"bitset<>\");\n \
    \ benchmark_all(vb, N, \"lib::Bitset64\");\n}\n\ntemplate<int N>\nvoid test()\
    \ {\n  for(int i = 0; i < 50; i++) {\n    auto p = random<N>();\n    auto q =\
    \ random<N>();\n\n    if(!compare<N>(p.first ^ q.first, p.second ^ q.second))\n\
    \      throw logic_error(\"difference in binary xor\");\n\n    if(!compare<N>(p.first\
    \ | q.first, p.second | q.second))\n      throw logic_error(\"difference in binary\
    \ or\");\n\n    if(!compare<N>(p.first & q.first, p.second & q.second))\n    \
    \  throw logic_error(\"difference in binary and\");\n\n    if(!compare<N>(~p.first,\
    \ ~p.second))\n      throw logic_error(\"difference in unary negation\");\n\n\
    \    for(int j = 0; j < 7; j++) {\n      int sz = rand() % (2*N);\n      if(!compare<N>(p.first\
    \ << sz, p.second << sz))\n        throw logic_error(\"difference on left shift\"\
    );\n\n      if(!compare<N>(p.first >> sz, p.second >> sz))\n        throw logic_error(\"\
    difference on right shift\");\n    }\n  }\n}\n\nint main() {\n  test<1>();\n \
    \ test<2>();\n  test<4>();\n  test<8>();\n  test<(1<<16)>();\n  test<129831>();\n\
    \  \n  benchmark<129831>(10000);\n}\n"
  dependsOn:
  - Bitset.cpp
  isVerificationFile: false
  path: tests/judge/bitset.cpp
  requiredBy: []
  timestamp: '2021-02-03 01:52:23-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/bitset.cpp
layout: document
redirect_from:
- /library/tests/judge/bitset.cpp
- /library/tests/judge/bitset.cpp.html
title: tests/judge/bitset.cpp
---
