---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Bitset.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\n\nnamespace {\ntemplate <typename T> T maskout(size_t\
    \ cnt, size_t n, T x) {\n  size_t trailing = cnt - n;\n  return x & ((~0) >> trailing);\n\
    }\n} // namespace\n\ntemplate <typename T = uint64_t> struct Bitset {\n  const\
    \ static size_t B = sizeof(T) << 3;\n  const static size_t BUCKET_SIZE = B;\n\
    \  const static size_t SHIFT = 31 - __builtin_clz(B);\n  const static size_t MASK\
    \ = B - 1;\n\n  size_t n, bucket_cnt;\n  vector<T> v;\n\n  Bitset(size_t n) :\
    \ n(n), bucket_cnt((n + B - 1) >> SHIFT), v(bucket_cnt) {\n    assert(bucket_cnt\
    \ > 0);\n  }\n\n  void maskout_last() {\n    size_t trailing = (bucket_cnt <<\
    \ SHIFT) - n;\n    v.back() &= (~0) >> trailing;\n  }\n\n  void resize(size_t\
    \ n) {\n    this->n = n;\n    size_t new_bucket_cnt = (n + B - 1) >> SHIFT;\n\
    \    if (new_bucket_cnt != bucket_cnt)\n      v.resize(new_bucket_cnt);\n    bucket_cnt\
    \ = new_bucket_cnt;\n    maskout_last();\n    assert(bucket_cnt > 0);\n  }\n\n\
    \  void extend_to(size_t nw) {\n    return;\n    if (nw > n)\n      resize(nw);\n\
    \  }\n\n  inline int size() const { return n; }\n\n  inline bool operator[](int\
    \ pos) const { return test(pos); }\n\n  inline bool test(size_t pos) const {\n\
    \    return (v[pos >> SHIFT] >> (pos & MASK)) & (T)1;\n  }\n\n  Bitset<T> &set()\
    \ {\n    for (T &x : v)\n      x = ~0;\n    maskout_last();\n    return *this;\n\
    \  }\n\n  Bitset<T> &reset() {\n    for (T &x : v)\n      x = 0;\n    return *this;\n\
    \  }\n\n  Bitset<T> &flip() {\n    for (T &x : v)\n      x = ~x;\n    maskout_last();\n\
    \    return *this;\n  }\n\n  Bitset<T> &set(size_t pos) {\n    assert(pos < n);\n\
    \    v[pos >> SHIFT] |= ((T)1 << (pos & MASK));\n    return *this;\n  }\n\n  Bitset<T>\
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
    using Bitset32 = Bitset<uint32_t>;\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_BITSET\n#define _LIB_BITSET\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\n\nnamespace {\ntemplate <typename T> T maskout(size_t\
    \ cnt, size_t n, T x) {\n  size_t trailing = cnt - n;\n  return x & ((~0) >> trailing);\n\
    }\n} // namespace\n\ntemplate <typename T = uint64_t> struct Bitset {\n  const\
    \ static size_t B = sizeof(T) << 3;\n  const static size_t BUCKET_SIZE = B;\n\
    \  const static size_t SHIFT = 31 - __builtin_clz(B);\n  const static size_t MASK\
    \ = B - 1;\n\n  size_t n, bucket_cnt;\n  vector<T> v;\n\n  Bitset(size_t n) :\
    \ n(n), bucket_cnt((n + B - 1) >> SHIFT), v(bucket_cnt) {\n    assert(bucket_cnt\
    \ > 0);\n  }\n\n  void maskout_last() {\n    size_t trailing = (bucket_cnt <<\
    \ SHIFT) - n;\n    v.back() &= (~0) >> trailing;\n  }\n\n  void resize(size_t\
    \ n) {\n    this->n = n;\n    size_t new_bucket_cnt = (n + B - 1) >> SHIFT;\n\
    \    if (new_bucket_cnt != bucket_cnt)\n      v.resize(new_bucket_cnt);\n    bucket_cnt\
    \ = new_bucket_cnt;\n    maskout_last();\n    assert(bucket_cnt > 0);\n  }\n\n\
    \  void extend_to(size_t nw) {\n    return;\n    if (nw > n)\n      resize(nw);\n\
    \  }\n\n  inline int size() const { return n; }\n\n  inline bool operator[](int\
    \ pos) const { return test(pos); }\n\n  inline bool test(size_t pos) const {\n\
    \    return (v[pos >> SHIFT] >> (pos & MASK)) & (T)1;\n  }\n\n  Bitset<T> &set()\
    \ {\n    for (T &x : v)\n      x = ~0;\n    maskout_last();\n    return *this;\n\
    \  }\n\n  Bitset<T> &reset() {\n    for (T &x : v)\n      x = 0;\n    return *this;\n\
    \  }\n\n  Bitset<T> &flip() {\n    for (T &x : v)\n      x = ~x;\n    maskout_last();\n\
    \    return *this;\n  }\n\n  Bitset<T> &set(size_t pos) {\n    assert(pos < n);\n\
    \    v[pos >> SHIFT] |= ((T)1 << (pos & MASK));\n    return *this;\n  }\n\n  Bitset<T>\
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
    using Bitset32 = Bitset<uint32_t>;\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Bitset.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Bitset.cpp
layout: document
redirect_from:
- /library/Bitset.cpp
- /library/Bitset.cpp.html
title: Bitset.cpp
---
