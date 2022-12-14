---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/associative-array.test.cpp
    title: tests/yosupo/associative-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/data-structure/hash-map-variable-length.hpp
  bundledCode: "#line 1 \"FastMap.cpp\"\n\n\n#include <bits/stdc++.h>\n\n// Pretty\
    \ much copied from:\n// https://nyaannyaan.github.io/library/data-structure/hash-map-variable-length.hpp\n\
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
    \n\n"
  code: "#ifndef _LIB_FAST_MAP\n#define _LIB_FAST_MAP\n#include <bits/stdc++.h>\n\n\
    // Pretty much copied from:\n// https://nyaannyaan.github.io/library/data-structure/hash-map-variable-length.hpp\n\
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
    \n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: FastMap.cpp
  requiredBy: []
  timestamp: '2022-12-14 09:29:18-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/associative-array.test.cpp
documentation_of: FastMap.cpp
layout: document
redirect_from:
- /library/FastMap.cpp
- /library/FastMap.cpp.html
title: FastMap.cpp
---
