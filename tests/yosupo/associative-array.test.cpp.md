---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FastMap.cpp
    title: FastMap.cpp
  - icon: ':heavy_check_mark:'
    path: Template.cpp
    title: Template.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"tests/yosupo/associative-array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n#line 1 \"Template.cpp\"\
    \n#include <bits/stdc++.h>\n#define int long long\nusing namespace std;\n \n#define\
    \ mp make_pair\n#define mt make_tuple\n#define pb push_back\n#define ms(v, x)\
    \ memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n#define\
    \ ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false); cin.tie(0)\n\
    #define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second) b = p.second\n\
    \ \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n#line 1 \"FastMap.cpp\"\
    \n\n\n#line 4 \"FastMap.cpp\"\n\n// Pretty much copied from:\n// https://nyaannyaan.github.io/library/data-structure/hash-map-variable-length.hpp\n\
    namespace lib {\nusing namespace std;\n\ntemplate <typename Key, typename Val\
    \ = Key>\nstruct FastMap {\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\
    \n  u32 cap, s;\n  vector<Key> keys;\n  vector<Val> vals;\n  vector<bool> flag;\n\
    \  u64 r;\n  u32 shift;\n  Val DefaultValue;\n\n  static u64 rng() {\n    u64\
    \ m = chrono::duration_cast<chrono::nanoseconds>(\n                chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n  void reallocate() {\n    cap <<= 1;\n    vector<Key> k(cap);\n    vector<Val>\
    \ v(cap);\n    vector<bool> f(cap);\n    u32 sh = shift - 1;\n    for (int i =\
    \ 0; i < (int)flag.size(); i++) {\n      if (flag[i]) {\n        u32 hash = (u64(keys[i])\
    \ * r) >> sh;\n        while (f[hash]) hash = (hash + 1) & (cap - 1);\n      \
    \  k[hash] = keys[i];\n        v[hash] = vals[i];\n        f[hash] = 1;\n    \
    \  }\n    }\n    keys.swap(k);\n    vals.swap(v);\n    flag.swap(f);\n    --shift;\n\
    \  }\n\n  explicit FastMap()\n      : cap(8),\n        s(0),\n        keys(cap),\n\
    \        vals(cap),\n        flag(cap),\n        r(rng()),\n        shift(64 -\
    \ __lg(cap)),\n        DefaultValue(Val()) {}\n\n  Val& operator[](const Key&\
    \ i) {\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n      if (!flag[hash])\
    \ {\n        if (s + s / 4 >= cap) {\n          reallocate();\n          return\
    \ (*this)[i];\n        }\n        keys[hash] = i;\n        flag[hash] = 1;\n \
    \       ++s;\n        return vals[hash] = DefaultValue;\n      }\n      if (keys[hash]\
    \ == i) return vals[hash];\n      hash = (hash + 1) & (cap - 1);\n    }\n  }\n\
    \n  // exist -> return pointer of Val\n  // not exist -> return nullptr\n  const\
    \ Val* find(const Key& i) const {\n    u32 hash = (u64(i) * r) >> shift;\n   \
    \ while (true) {\n      if (!flag[hash]) return nullptr;\n      if (keys[hash]\
    \ == i) return &(vals[hash]);\n      hash = (hash + 1) & (cap - 1);\n    }\n \
    \ }\n\n  // return vector< pair<const Key&, val& > >\n  vector<pair<Key, Val>>\
    \ enumerate() const {\n    vector<pair<Key, Val>> ret;\n    for (u32 i = 0; i\
    \ < cap; ++i)\n      if (flag[i]) ret.emplace_back(keys[i], vals[i]);\n    return\
    \ ret;\n  }\n\n  int size() const { return s; }\n\n  // set default_value\n  void\
    \ set_default(const Val& val) { DefaultValue = val; }\n};\n} // namespace lib\n\
    \n\n#line 4 \"tests/yosupo/associative-array.test.cpp\"\n\nint32_t main() {\n\
    \  iopt;\n\n  lib::FastMap<int, int> st;\n\n  int n; cin >> n;\n\n  for(int i\
    \ = 0; i < n; i++) {\n    int t, k; cin >> t >> k;\n    if (t == 0) {\n      int\
    \ v;\n      cin >> v;\n      st[k] = v;\n    } else {\n      cout << st[k] <<\
    \ endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"Template.cpp\"\n#include \"FastMap.cpp\"\n\nint32_t main() {\n  iopt;\n\n\
    \  lib::FastMap<int, int> st;\n\n  int n; cin >> n;\n\n  for(int i = 0; i < n;\
    \ i++) {\n    int t, k; cin >> t >> k;\n    if (t == 0) {\n      int v;\n    \
    \  cin >> v;\n      st[k] = v;\n    } else {\n      cout << st[k] << endl;\n \
    \   }\n  }\n}\n"
  dependsOn:
  - Template.cpp
  - bits/stdc++.h
  - FastMap.cpp
  isVerificationFile: true
  path: tests/yosupo/associative-array.test.cpp
  requiredBy: []
  timestamp: '2022-12-14 09:29:18-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/associative-array.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/associative-array.test.cpp
- /verify/tests/yosupo/associative-array.test.cpp.html
title: tests/yosupo/associative-array.test.cpp
---
