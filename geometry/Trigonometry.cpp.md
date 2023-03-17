---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':warning:'
    path: geometry/Caliper.cpp
    title: geometry/Caliper.cpp
  - icon: ':warning:'
    path: geometry/Circle2D.cpp
    title: geometry/Circle2D.cpp
  - icon: ':warning:'
    path: geometry/Line2D.cpp
    title: geometry/Line2D.cpp
  - icon: ':warning:'
    path: geometry/Polygon2D.cpp
    title: geometry/Polygon2D.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "geometry/Trigonometry.cpp"



    #include <bits/stdc++.h>


    namespace lib {

    using namespace std;

    namespace geo {

    namespace trig {

    constexpr static long double PI = 3.141592653589793238462643383279502884197169399375105820974944l;

    double cos(double x) { return ::cos(x); }

    double sin(double x) { return ::sin(x); }

    double asin(double x) { return ::asin(x); }

    double acos(double x) { return ::acos(x); }

    double atan2(double y, double x) { return ::atan2(y, x); }

    long double cos(long double x) { return ::cosl(x); }

    long double sin(long double x) { return ::sinl(x); }

    long double asin(long double x) { return ::asinl(x); }

    long double acos(long double x) { return ::acosl(x); }

    long double atan2(long double y, long double x) { return ::atan2l(y, x); }

    } // namespace trig

    } // namespace geo

    } // namespace lib



    '
  code: '#ifndef _LIB_TRIGONOMETRY

    #define _LIB_TRIGONOMETRY

    #include <bits/stdc++.h>


    namespace lib {

    using namespace std;

    namespace geo {

    namespace trig {

    constexpr static long double PI = 3.141592653589793238462643383279502884197169399375105820974944l;

    double cos(double x) { return ::cos(x); }

    double sin(double x) { return ::sin(x); }

    double asin(double x) { return ::asin(x); }

    double acos(double x) { return ::acos(x); }

    double atan2(double y, double x) { return ::atan2(y, x); }

    long double cos(long double x) { return ::cosl(x); }

    long double sin(long double x) { return ::sinl(x); }

    long double asin(long double x) { return ::asinl(x); }

    long double acos(long double x) { return ::acosl(x); }

    long double atan2(long double y, long double x) { return ::atan2l(y, x); }

    } // namespace trig

    } // namespace geo

    } // namespace lib


    #endif

    '
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: geometry/Trigonometry.cpp
  requiredBy:
  - geometry/Line2D.cpp
  - geometry/Circle2D.cpp
  - geometry/Polygon2D.cpp
  - geometry/Caliper.cpp
  - FFT.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/Trigonometry.cpp
layout: document
redirect_from:
- /library/geometry/Trigonometry.cpp
- /library/geometry/Trigonometry.cpp.html
title: geometry/Trigonometry.cpp
---
