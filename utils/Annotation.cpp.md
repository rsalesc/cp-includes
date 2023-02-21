---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/Caliper.cpp
    title: geometry/Caliper.cpp
  - icon: ':warning:'
    path: geometry/Circle2D.cpp
    title: geometry/Circle2D.cpp
  - icon: ':warning:'
    path: geometry/Polygon2D.cpp
    title: geometry/Polygon2D.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/Annotation.cpp\"\n\n\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\ntemplate <typename T, typename A = void>\n\
    struct Note : public T {\nprivate:\n    A m_data = A();\n    Note(const T& t,\
    \ const A& a) : T(t), m_data(a) {}\npublic:\n    using T::T;\n\n    static Note\
    \ make(const T& t, const A& a) {\n        return Note(t, a);\n    }\n\n    friend\
    \ A& annotation(Note& note) {\n        return note.m_data;\n    }\n    friend\
    \ const A& annotation(const Note& note) {\n        return note.m_data;\n    }\n\
    \n    template<typename C, typename D>\n    operator Note<T,A>() const {\n   \
    \     return Note<C, D>(*this, m_data);\n    }\n};\n\ntemplate <typename T>\n\
    struct Note<T, void> : public T {\n    using T::T;\n    using T::operator=;\n\
    \    \n    Note(const T& a) : T(a) {}\n    Note(T &&a): T(std::move(a)) {}\n};\n\
    \ntemplate<typename T, typename A>\nNote<T, A> make_note(const T& t, const A&\
    \ a) {\n    return Note<T, A>::make(t, a);\n}\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_ANNOTATION\n#define _LIB_ANNOTATION\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\ntemplate <typename T, typename A = void>\n\
    struct Note : public T {\nprivate:\n    A m_data = A();\n    Note(const T& t,\
    \ const A& a) : T(t), m_data(a) {}\npublic:\n    using T::T;\n\n    static Note\
    \ make(const T& t, const A& a) {\n        return Note(t, a);\n    }\n\n    friend\
    \ A& annotation(Note& note) {\n        return note.m_data;\n    }\n    friend\
    \ const A& annotation(const Note& note) {\n        return note.m_data;\n    }\n\
    \n    template<typename C, typename D>\n    operator Note<T,A>() const {\n   \
    \     return Note<C, D>(*this, m_data);\n    }\n};\n\ntemplate <typename T>\n\
    struct Note<T, void> : public T {\n    using T::T;\n    using T::operator=;\n\
    \    \n    Note(const T& a) : T(a) {}\n    Note(T &&a): T(std::move(a)) {}\n};\n\
    \ntemplate<typename T, typename A>\nNote<T, A> make_note(const T& t, const A&\
    \ a) {\n    return Note<T, A>::make(t, a);\n}\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: utils/Annotation.cpp
  requiredBy:
  - geometry/Polygon2D.cpp
  - geometry/Caliper.cpp
  - geometry/Circle2D.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/Annotation.cpp
layout: document
redirect_from:
- /library/utils/Annotation.cpp
- /library/utils/Annotation.cpp.html
title: utils/Annotation.cpp
---
