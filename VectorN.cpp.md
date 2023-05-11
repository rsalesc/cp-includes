---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':question:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':heavy_check_mark:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':question:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':question:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':question:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fht-convolution.test.cpp
    title: tests/yosupo/fht-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/find-lr.test.cpp
    title: tests/yosupo/find-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fps-inv.test.cpp
    title: tests/yosupo/fps-inv.test.cpp
  - icon: ':x:'
    path: tests/yosupo/fps-power.test.cpp
    title: tests/yosupo/fps-power.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/kth-term-lr.test.cpp
    title: tests/yosupo/kth-term-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/multipoint.test.cpp
    title: tests/yosupo/multipoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/subset-sum.test.cpp
    title: tests/yosupo/subset-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"VectorN.cpp\"\n\n\n#include <bits/stdc++.h>\n#line 1 \"\
    Traits.cpp\"\n\n\n#line 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace traits {\n\ntemplate <typename...> struct make_void { using type = void;\
    \ };\n\ntemplate <typename... T> using void_t = typename make_void<T...>::type;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IteratorCategory = typename\
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
    } // namespace traits\n} // namespace lib\n\n\n#line 5 \"VectorN.cpp\"\n\n#define\
    \ VEC_CONST_OP(op, typ) \\\n  type operator op(const typ rhs) const { \\\n   \
    \ auto res = *this; \\\n    return res op##= rhs; \\\n  }\n\n#define VEC_BIN_OP(op)\
    \ \\\n  type& operator op##=(const type& rhs) { \\\n    if(rhs.size() > this->size())\
    \ \\\n      this->resize(rhs.size()); \\\n    int sz = this->size(); \\\n    for(int\
    \ i = 0; i < (int)rhs.size(); i++) \\\n      (*this)[i] op##= rhs[i]; \\\n   \
    \ for(int i = rhs.size(); i < sz; i++) \\\n      (*this)[i] op##= 0; \\\n    return\
    \ *this; \\\n  } \\\n  VEC_CONST_OP(op, type)\n\n#define VEC_SINGLE_OP(op, typ)\
    \ \\\n  type& operator op##=(const typ rhs) { \\\n    for(auto& x : *this) \\\n\
    \      x op##= rhs; \\\n    return *this; \\\n  } \\\n  VEC_CONST_OP(op, typ)\n\
    \  \n\nnamespace lib {\nusing namespace std;\ntemplate<typename T>\nstruct VectorN\
    \ : vector<T> {\n  using type = VectorN<T>;\n\n  template <\n      typename Container,\n\
    \      typename enable_if<traits::HasInputIterator<Container>::value>::type *\
    \ = nullptr>\n  VectorN(const Container &container)\n      : vector<T>(container.begin(),\
    \ container.end()) {}\n\n  VectorN(const initializer_list<T> &v)\n      : vector<T>(v.begin(),\
    \ v.end()) {}\n\n  template<typename... Args>\n  VectorN( Args&&... args ) \n\
    \      : vector<T>(std::forward<Args>(args)...) {}\n\n  VEC_BIN_OP(+)\n  VEC_BIN_OP(-)\n\
    \  VEC_BIN_OP(*)\n\n  VEC_SINGLE_OP(+, T&)\n  VEC_SINGLE_OP(-, T&)\n  VEC_SINGLE_OP(*,\
    \ T&)\n  VEC_SINGLE_OP(/, T&)\n  VEC_SINGLE_OP(^, int64_t)\n\n  type operator-()\
    \ const {\n    auto res = *this;\n    for(auto& x : res) x = -x;\n    return res;\n\
    \  }\n\n  type operator%(int n) const {\n    // TODO: get rid of this\n    //\
    \ return *const_cast<type*>(this);\n    return *this;\n  }\n};\n} // namespace\
    \ lib\n\n\n"
  code: "#ifndef _LIB_VECTOR_N\n#define _LIB_VECTOR_N\n#include <bits/stdc++.h>\n\
    #include \"Traits.cpp\"\n\n#define VEC_CONST_OP(op, typ) \\\n  type operator op(const\
    \ typ rhs) const { \\\n    auto res = *this; \\\n    return res op##= rhs; \\\n\
    \  }\n\n#define VEC_BIN_OP(op) \\\n  type& operator op##=(const type& rhs) { \\\
    \n    if(rhs.size() > this->size()) \\\n      this->resize(rhs.size()); \\\n \
    \   int sz = this->size(); \\\n    for(int i = 0; i < (int)rhs.size(); i++) \\\
    \n      (*this)[i] op##= rhs[i]; \\\n    for(int i = rhs.size(); i < sz; i++)\
    \ \\\n      (*this)[i] op##= 0; \\\n    return *this; \\\n  } \\\n  VEC_CONST_OP(op,\
    \ type)\n\n#define VEC_SINGLE_OP(op, typ) \\\n  type& operator op##=(const typ\
    \ rhs) { \\\n    for(auto& x : *this) \\\n      x op##= rhs; \\\n    return *this;\
    \ \\\n  } \\\n  VEC_CONST_OP(op, typ)\n  \n\nnamespace lib {\nusing namespace\
    \ std;\ntemplate<typename T>\nstruct VectorN : vector<T> {\n  using type = VectorN<T>;\n\
    \n  template <\n      typename Container,\n      typename enable_if<traits::HasInputIterator<Container>::value>::type\
    \ * = nullptr>\n  VectorN(const Container &container)\n      : vector<T>(container.begin(),\
    \ container.end()) {}\n\n  VectorN(const initializer_list<T> &v)\n      : vector<T>(v.begin(),\
    \ v.end()) {}\n\n  template<typename... Args>\n  VectorN( Args&&... args ) \n\
    \      : vector<T>(std::forward<Args>(args)...) {}\n\n  VEC_BIN_OP(+)\n  VEC_BIN_OP(-)\n\
    \  VEC_BIN_OP(*)\n\n  VEC_SINGLE_OP(+, T&)\n  VEC_SINGLE_OP(-, T&)\n  VEC_SINGLE_OP(*,\
    \ T&)\n  VEC_SINGLE_OP(/, T&)\n  VEC_SINGLE_OP(^, int64_t)\n\n  type operator-()\
    \ const {\n    auto res = *this;\n    for(auto& x : res) x = -x;\n    return res;\n\
    \  }\n\n  type operator%(int n) const {\n    // TODO: get rid of this\n    //\
    \ return *const_cast<type*>(this);\n    return *this;\n  }\n};\n} // namespace\
    \ lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  - Traits.cpp
  isVerificationFile: false
  path: VectorN.cpp
  requiredBy:
  - polynomial/MultipointEvaluation.cpp
  - PolynomialRing.cpp
  - PowerSeries.cpp
  - LinearRecurrence.cpp
  - FHT.cpp
  - NTT.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/fht-convolution.test.cpp
  - tests/yosupo/find-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/fps-power.test.cpp
documentation_of: VectorN.cpp
layout: document
redirect_from:
- /library/VectorN.cpp
- /library/VectorN.cpp.html
title: VectorN.cpp
---
