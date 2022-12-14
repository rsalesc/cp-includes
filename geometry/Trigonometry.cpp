#ifndef _LIB_TRIGONOMETRY
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
