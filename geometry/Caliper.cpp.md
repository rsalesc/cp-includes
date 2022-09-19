---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Epsilon.cpp
    title: Epsilon.cpp
  - icon: ':warning:'
    path: geometry/Circle2D.cpp
    title: geometry/Circle2D.cpp
  - icon: ':warning:'
    path: geometry/GeometryEpsilon.cpp
    title: geometry/GeometryEpsilon.cpp
  - icon: ':warning:'
    path: geometry/Line2D.cpp
    title: geometry/Line2D.cpp
  - icon: ':warning:'
    path: geometry/Polygon2D.cpp
    title: geometry/Polygon2D.cpp
  - icon: ':warning:'
    path: geometry/Trigonometry.cpp
    title: geometry/Trigonometry.cpp
  - icon: ':warning:'
    path: utils/Annotation.cpp
    title: utils/Annotation.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/Caliper.cpp\"\n\n\n#line 1 \"geometry/Line2D.cpp\"\
    \n\n\n#line 1 \"geometry/GeometryEpsilon.cpp\"\n\n\n#line 1 \"Epsilon.cpp\"\n\n\
    \n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\n\ntemplate\
    \ <typename T = double> struct Epsilon {\n  T eps;\n  constexpr Epsilon(T eps\
    \ = 1e-9) : eps(eps) {}\n\n  template <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  int operator()(G a, G b = 0) const {\n    return a + eps < b\
    \ ? -1 : (b + eps < a ? 1 : 0);\n  }\n\n  template <typename G,\n            typename\
    \ enable_if<!is_floating_point<G>::value>::type * = nullptr>\n  int operator()(G\
    \ a, G b = 0) const {\n    return a < b ? -1 : (a > b ? 1 : 0);\n  }\n\n  template\
    \ <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
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
    \ T, typename Large = T> struct Halfplane {\n  typedef Point<T, Large> point;\n\
    \  typedef Line<T, Large> line;\n  typedef Ray<T, Large> ray;\n  typedef Halfplane<T,\
    \ Large> halfplane;\n  point a, b;\n\n  Halfplane(point a, point direction) :\
    \ a(a), b(a + direction) {}\n\n  static halfplane from_points(point a, point b)\
    \ { return halfplane(a, b - a); }\n  point direction() const { return b - a; }\n\
    \  point direction_versor() const { return versor(direction()); }\n\n  line as_line()\
    \ const { return line(a, b); }\n  explicit operator line() const { return as_line();\
    \ }\n\n  ray as_ray() const { return ray(a, b); }\n  explicit operator ray() const\
    \ { return as_ray(); }\n\n  template <typename G, typename H> explicit operator\
    \ Halfplane<G, H>() const {\n    return Halfplane<G, H>(Point<G, H>(a), Point<G,\
    \ H>(b));\n  }\n\n  bool contains(const point& p) const {\n    return ccw(a, b,\
    \ p) <= 0;\n  }\n  bool strictly_contains(const point& p) const {\n    return\
    \ ccw(a, b, p) < 0;\n  }\n};\n\ntemplate <typename T, typename Large = T> struct\
    \ Segment {\n  typedef Point<T, Large> point;\n  typedef Line<T, Large> line;\n\
    \  typedef Segment<T, Large> segment;\n  typedef Ray<T, Large> ray;\n  point a,\
    \ b;\n\n  Segment() {}\n  Segment(point a, point b) : a(a), b(b) {}\n  line as_line()\
    \ const { return line(a, b); }\n  explicit operator line() const { return as_line();\
    \ }\n  bool is_degenerate() const { return a == b; }\n\n  template <typename G,\
    \ typename H> explicit operator Segment<G, H>() const {\n    return Segment<G,\
    \ H>(Point<G, H>(a), Point<G, H>(b));\n  }\n  bool contains(const point &p) const\
    \ { return between(a, p, b); }\n  bool strictly_contains(const point &p) const\
    \ {\n    return strictly_between(a, p, b);\n  }\n  bool collinear_contains(const\
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
    \ Large> segment;\n  typedef plane::Ray<T, Large> ray;\n  typedef plane::Halfplane<T,\
    \ Large> halfplane;\n\n  template<typename Direction>\n  using angle_comparator\
    \ = plane::AngleComparator<Direction, T, Large>;\n};\n\n} // namespace geo\n}\
    \ // namespace lib\n\n\n#line 1 \"geometry/Polygon2D.cpp\"\n\n\n#line 1 \"geometry/Circle2D.cpp\"\
    \n\n\n#line 1 \"utils/Annotation.cpp\"\n\n\n#line 4 \"utils/Annotation.cpp\"\n\
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
    \ a) {\n    return Note<T, A>::make(t, a);\n}\n} // namespace lib\n\n\n#line 6\
    \ \"geometry/Circle2D.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ geo {\nnamespace plane {\ntemplate <typename T, typename Large = T> struct Barycentric\
    \ {\n  typedef Point<T, Large> point;\n  point r1, r2, r3;\n  T a, b, c;\n\n \
    \ Barycentric(const point &r1, const point &r2, const point &r3, T a = 1,\n  \
    \            T b = 1, T c = 1)\n      : r1(r1), r2(r2), r3(r3), a(a), b(b), c(c)\
    \ {}\n  point as_point() const { return (r1 * a + r2 * b + r3 * c) / (a + b +\
    \ c); }\n\n  static Barycentric centroid(const point &r1, const point &r2,\n \
    \                             const point &r3) {\n    return Barycentric(r1, r2,\
    \ r3);\n  }\n  static Barycentric circumcenter(const point &r1, const point &r2,\n\
    \                                  const point &r3) {\n    Large a = norm_sq(r2\
    \ - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);\n    return Barycentric(r1,\
    \ r2, r3, a * (b + c - a), b * (c + a - b),\n                       c * (a + b\
    \ - c));\n  }\n  static Barycentric incenter(const point &r1, const point &r2,\n\
    \                              const point &r3) {\n    return Barycentric(r1,\
    \ r2, r3, norm(r2 - r3), norm(r1 - r3), norm(r1 - r2));\n  }\n  static Barycentric\
    \ orthocenter(const point &r1, const point &r2,\n                            \
    \     const point &r3) {\n    Large a = norm_sq(r2 - r3), b = norm_sq(r3 - r1),\
    \ c = norm_sq(r1 - r2);\n    return Barycentric(r1, r2, r3, (a + b - c) * (c +\
    \ a - b),\n                       (b + c - a) * (a + b - c), (c + a - b) * (b\
    \ + c - a));\n  }\n  static Barycentric excenter(const point &r1, const point\
    \ &r2,\n                              const point &r3) {\n    return Barycentric(r1,\
    \ r2, r3, -norm(r2 - r3), norm(r1 - r3),\n                       norm(r1 - r2));\n\
    \  }\n};\n\ntemplate <typename T, typename Large = T> struct Circle {\n  typedef\
    \ Point<T, Large> point;\n  typedef Line<T, Large> line;\n  typedef Barycentric<Large>\
    \ bary;\n  typedef Segment<T, Large> segment;\n  point center;\n  T radius;\n\n\
    \  Circle(point center, T radius) : center(center), radius(radius) {}\n  Circle(const\
    \ point &p1, const point &p2, const point &p3) {\n    center = bary::circumcenter(p1,\
    \ p2, p3).as_point();\n    radius = dist(center, p1);\n  }\n  Circle(const point\
    \ &p1, const point &p2) {\n    center = (p1 + p2) / 2;\n    radius = dist(center,\
    \ p1);\n  }\n  bool crosses_x_axis(point p = point()) const {\n    auto c = center\
    \ - p;\n    return GEOMETRY_COMPARE0(T, c.y + radius) >= 0 && GEOMETRY_COMPARE0(T,\
    \ c.y - radius) < 0;\n  }\n  static Circle incircle(const point &p1, const point\
    \ &p2, const point &p3) {\n    point center = bary::incenter(p1, p2, p3).as_point();\n\
    \    return Circle(center, dist(line(p1, p2), center));\n  }\n  friend pair<segment,\
    \ int> intersect_segment(const Circle &c, const line &l) {\n    point H = project(c.center,\
    \ l);\n    Large h = norm(H - c.center);\n    if (GEOMETRY_COMPARE(Large, c.radius,\
    \ h) < 0)\n      return {{}, 0};\n    Large norma = sqrtl(c.radius + h) * sqrtl(c.radius\
    \ - h);\n    point v = normalized(l.direction(), norma);\n    segment res = segment(H\
    \ - v, H + v);\n    return {res, res.is_degenerate() ? 1 : 2};\n  }\n  friend\
    \ Large intersection_area(const Circle &a, const Circle &b) {\n    Large d = norm(a.center\
    \ - b.center);\n    if (GEOMETRY_COMPARE(Large, a.radius + b.radius, d) <= 0)\n\
    \      return 0.0;\n    if (GEOMETRY_COMPARE(Large, d, abs(a.radius - b.radius))\
    \ <= 0) {\n      T r = min(a.radius, b.radius);\n      return r * r * trig::PI;\n\
    \    }\n\n    auto compute = [d](Large ra, Large rb) {\n      Large sup = rb *\
    \ rb + d * d - ra * ra;\n      Large alpha = trig::acos(sup / (2.0 * rb * d));\n\
    \      Large s = alpha * rb * rb;\n      Large t = rb * rb * trig::sin(alpha)\
    \ * trig::cos(alpha);\n      return s - t;\n    };\n    return compute(a.radius,\
    \ b.radius) + compute(b.radius, a.radius);\n  }\n  static Large intersection_signed_area(T\
    \ r, const point &a, const point &b) {\n    Circle C(point(), r);\n    auto ps\
    \ = intersect_segment(C, line(a, b));\n    if (!ps.second)\n      return r * r\
    \ * signed_angle(a, b) / 2;\n    auto s = ps.first;\n    bool outa = !contains(C,\
    \ a), outb = !contains(C, b);\n    if (outa && outb) {\n      segment ab(a, b);\n\
    \      if (ab.contains(s.a) && ab.contains(s.b))\n        return (r * r * (signed_angle(a,\
    \ b) - signed_angle(s.a, s.b)) +\n                cross(s.a, s.b)) /\n       \
    \        2;\n      return r * r * signed_angle(a, b) / 2;\n    } else if (outa)\n\
    \      return (r * r * signed_angle(a, s.a) + cross(s.a, b)) / 2;\n    else if\
    \ (outb)\n      return (r * r * signed_angle(s.b, b) + cross(a, s.b)) / 2;\n \
    \   else\n      return cross(a, b) / 2;\n  }\n  friend vector<point> tangents(const\
    \ Circle &C, const point &p) {\n    return _tangents({p, T()}, C, {1});\n  }\n\
    \  friend vector<line> inner_tangents(const Circle& a, const Circle& b) {\n  \
    \  return _tangents(a, b, {-1});\n  }\n  friend vector<line> outer_tangents(const\
    \ Circle& a, const Circle& b) {\n    return _tangents(a, b, {1});\n  }\n  friend\
    \ vector<line> _tangents(const Circle& a, const Circle& b, const initializer_list<int>&\
    \ r_sgn) {\n    vector<line> res;\n    for(int r_s : r_sgn) {\n      point d =\
    \ b.center - a.center;\n      Large dr = (a.radius - b.radius*r_s), d2 = norm_sq(d),\
    \ h2 = d2 - dr*dr;\n      if(GEOMETRY_COMPARE0(Large, d2) == 0) continue;\n  \
    \    if(GEOMETRY_COMPARE0(Large, h2) < 0) continue;\n      for(T sgn : {-1, 1})\
    \ {\n        point v = (d * dr + ortho(d) * sqrtl(h2) * sgn) / d2;\n        res.push_back({a.center\
    \ + v * a.radius, b.center + v * (b.radius * r_s)});\n      }\n      if(GEOMETRY_COMPARE0(Large,\
    \ h2) == 0) res.pop_back();\n    }\n    return res;\n  }\n  friend vector<Note<line,\
    \ int>> angular_tangents(const Circle& a, const vector<Circle>& v, vector<int>&\
    \ sgn) {\n    vector<Note<line, int>> res;\n    res.reserve(4 * v.size());\n \
    \   int i = 0;\n    sgn = vector<int>(v.size());\n    vector<bool> reversed(4);\n\
    \    bool null_a = GEOMETRY_COMPARE0(T, a.radius) == 0;\n\n    for(int i = 0;\
    \ i < v.size(); i++) {\n      bool null_i = GEOMETRY_COMPARE0(T, v[i].radius)\
    \ == 0;\n      assert(!null_a || !null_i);\n      vector<line> tgts;\n      if(null_a\
    \ || null_i) tgts = _tangents(a, v[i], {1});\n      else tgts = _tangents(a, v[i],\
    \ {+1, -1});\n      if(tgts.empty()) continue;\n\n      fill(reversed.begin(),\
    \ reversed.end(), false);\n      int j = 0;\n      for(auto& t : tgts) {\n   \
    \     // direct tangents\n        if(ccw(t.b - t.a, a.center - t.a) < 0)\n   \
    \       swap(t.a, t.b), reversed[j] = true;\n        res.push_back(make_note<line,\
    \ int>(t, i));\n        j++;\n      }\n\n      // check signal\n      auto it\
    \ = AngleComparator<RayDirection<line>, T, Large>::minByAngle(tgts.begin(), tgts.end());\n\
    \      point ta = reversed[it - tgts.begin()] ? it->b : it->a;\n      point dir\
    \ = v[i].center - ta;\n      sgn[i] = half_ccw(it->direction(), dir);\n    }\n\
    \    AngleComparator<RayDirection<line>, T, Large>::sortByAngle(res.begin(), res.end());\n\
    \    return res;\n  }\n  friend bool contains(const Circle &c, const point &p)\
    \ {\n    return GEOMETRY_COMPARE(Large, dist(p, c.center), c.radius) <= 0;\n \
    \ }\n  friend bool contains(const Circle &c, const segment &s) {\n    return GEOMETRY_COMPARE(Large,\
    \ dist(s.a, c.center), c.radius) <= 0 &&\n           GEOMETRY_COMPARE(Large, dist(s.b,\
    \ c.center), c.radius) <= 0;\n  }\n  template <typename L>\n  friend bool partially_contains(const\
    \ Circle &c, const L &l) {\n    return GEOMETRY_COMPARE(Large, dist(l, c.center),\
    \ c.radius) <= 0;\n  }\n  template <typename L>\n  friend bool has_unique_intersection(const\
    \ Circle &c, const L &l) {\n    return GEOMETRY_COMPARE(Large, dist(l, c.center),\
    \ c.radius) == 0;\n  }\n  template <typename L>\n  friend bool has_intersection(const\
    \ Circle &c, const L &l) {\n    return GEOMETRY_COMPARE(Large, dist(l, c.center),\
    \ c.radius) <= 0;\n  }\n  friend bool has_intersection(const Circle &c, const\
    \ segment &s) {\n    return GEOMETRY_COMPARE(Large, dist(s, c.center), c.radius)\
    \ <= 0 &&\n           (GEOMETRY_COMPARE(Large, dist(s.a, c.center), c.radius)\
    \ >= 0 ||\n            GEOMETRY_COMPARE(Large, dist(s.b, c.center), c.radius)\
    \ >= 0);\n  }\n};\n} // namespace plane\n\ntemplate <typename T, typename Large\
    \ = T>\nstruct CirclePlane : public CartesianPlane<T, Large> {\n  typedef plane::Circle<T,\
    \ Large> circle;\n};\n\n} // namespace geo\n} // namespace lib\n\n\n#line 6 \"\
    geometry/Polygon2D.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace geo\
    \ {\nnamespace plane {\n\ntemplate <typename T, typename Large = T> struct ConvexHullComparator\
    \ {\n  typedef Point<T, Large> point;\n  point pivot;\n  ConvexHullComparator(point\
    \ p) : pivot(p) {}\n  template <typename G>\n  bool operator()(const pair<point,\
    \ G> &a, const pair<point, G> &b) const {\n    int k = ccw(pivot, a.first, b.first);\n\
    \    if (k == 0)\n      return norm_sq(a.first) < norm_sq(b.first);\n    return\
    \ k > 0;\n  }\n};\n\ntemplate <typename T, typename Large = T> struct Polygon\
    \ {\n  typedef Point<T, Large> point;\n  typedef Polygon<T, Large> polygon;\n\
    \  typedef Circle<T, Large> circle;\n  vector<point> p;\n\n  Polygon() {}\n  Polygon(const\
    \ vector<point> &p) : p(p) {}\n  template <typename G> Polygon(const vector<pair<point,\
    \ G>> &g) : p(g.size()) {\n    for (size_t i = 0; i < g.size(); i++)\n      p[i]\
    \ = g[i].first;\n  }\n  template <typename A, typename B> explicit operator Polygon<A,\
    \ B>() const {\n    vector<Point<A, B>> v(p.size());\n    for (size_t i = 0; i\
    \ < p.size(); i++)\n      v[i] = Point<A, B>(p[i]);\n    return Polygon<A, B>(v);\n\
    \  }\n  inline int index(int i) const {\n    if (i >= size())\n      i %= size();\n\
    \    else if (i < 0) {\n      i %= size();\n      if (i < 0)\n        i += size();\n\
    \    }\n    return i;\n  }\n  inline int size() const { return p.size(); }\n \
    \ inline point &operator[](int i) { return p[index(i)]; }\n  inline point operator[](int\
    \ i) const { return p[index(i)]; }\n  void erase(int i) { p.erase(p.begin() +\
    \ index(i)); }\n  polygon &operator+=(const point &pt) {\n    for (auto &q : p)\n\
    \      q += pt;\n    return *this;\n  }\n  polygon &operator-=(const point &pt)\
    \ {\n    for (auto &q : p)\n      q -= pt;\n    return *this;\n  }\n  polygon\
    \ &operator*=(const Large k) {\n    for (auto &q : p)\n      q *= k;\n    return\
    \ *this;\n  }\n  polygon &operator/=(const Large k) {\n    for (auto &q : p)\n\
    \      q /= k;\n    return *this;\n  }\n  polygon operator-() const {\n    polygon\
    \ res = *this;\n    for (auto &q : res.p)\n      q = -q;\n    return res;\n  }\n\
    \  void reserve(int n) { p.reserve(n); }\n  bool is_ccw() const {\n    int n =\
    \ size();\n    int i = min_element(p.begin(), p.end()) - p.begin();\n    return\
    \ ccw(p[i], p[i + 1], p[i - 1]) >= 0;\n  }\n  bool is_degenerate() const {\n \
    \   int n = size();\n    if (n < 3)\n      return true;\n    for (int i = 0; i\
    \ < n; i++) {\n      if (GEOMETRY_COMPARE0(Large, cross(p[i + 2] - p[i], p[i +\
    \ 1] - p[i])))\n        return false;\n    }\n    return true;\n  }\n  inline\
    \ operator vector<point>() const { return p; }\n\n  friend Large double_area(const\
    \ Polygon &p) {\n    int n = p.size();\n    Large res = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n      res += cross(p[i], p[i + 1]);\n    }\n    return abs(res);\n\
    \  }\n  friend Large area(const Polygon &p) { return double_area(p) / 2; }\n \
    \ friend Large perimeter(const Polygon &p) {\n    int n = p.size();\n    Large\
    \ res = 0;\n    for (int i = 0; i < n; i++)\n      res += dist(p[i], p[i + 1]);\n\
    \    return res;\n  }\n\n  int test(const point &p) const {\n    const Polygon\
    \ &poly = *this;\n    int n = size();\n    int wn = 0;\n    for (int i = 0; i\
    \ < n; i++) {\n      if (p == poly[i])\n        return 0;\n      int j = i + 1;\n\
    \      if (poly[i].y == p.y && poly[j].y == p.y) {\n        if (min(poly[i].x,\
    \ poly[j].x) <= p.x &&\n            p.x <= max(poly[i].x, poly[j].x))\n      \
    \    return 0;\n      } else {\n        bool below = poly[i].y < p.y;\n      \
    \  if (below != (poly[j].y < p.y)) {\n          auto sig = ccw(poly[i], poly[j],\
    \ p);\n          if (sig == 0)\n            return 0;\n          if (below ==\
    \ (sig > 0))\n            wn += below ? 1 : -1;\n        }\n      }\n    }\n \
    \   return wn == 0 ? 1 : -1;\n  }\n\n  template <typename G>\n  static vector<pair<point,\
    \ G>> convex_hull(vector<pair<point, G>> p,\n                                \
    \            bool keep_border = false) {\n    if (p.size() <= 1)\n      return\
    \ p;\n    sort(p.begin(), p.end());\n    vector<pair<point, G>> res;\n    res.reserve(p.size()\
    \ + 1);\n    for (int step = 0; step < 2; step++) {\n      auto start = res.size();\n\
    \      for (auto &q : p) {\n        while (res.size() >= start + 2) {\n      \
    \    int sig = ccw(res[res.size() - 2].first, res.back().first, q.first);\n  \
    \        if ((sig == 0 && !keep_border) || sig < 0)\n            res.pop_back();\n\
    \          else\n            break;\n        }\n        res.push_back(q);\n  \
    \    }\n      res.pop_back();\n      if (step == 0)\n        reverse(p.begin(),\
    \ p.end());\n    }\n    if (res.size() == 2 && res[0] == res[1])\n      res.pop_back();\n\
    \    return res;\n  }\n\n  static polygon convex_hull(const vector<point> &p,\
    \ bool keep_border = false) {\n    vector<pair<point, int>> v(p.size());\n   \
    \ for (size_t i = 0; i < p.size(); i++)\n      v[i] = {p[i], i};\n    auto res\
    \ = convex_hull(v, keep_border);\n    return polygon(res);\n  }\n\n  friend vector<polygon>\
    \ triangulation(polygon poly) {\n    if (poly.size() < 3)\n      return {};\n\
    \    vector<polygon> res;\n    int ptr = 0;\n    int n;\n    while ((n = poly.size())\
    \ > 3) {\n      for (int &i = ptr;; i++) {\n        if (ccw(poly[i - 1], poly[i],\
    \ poly[i + 1]) > 0) {\n          auto trig = polygon({poly[i - 1], poly[i], poly[i\
    \ + 1]});\n          bool good = true;\n          for (int j = 0; j < n; j++)\
    \ {\n            good &= trig.test(poly[j]) >= 0;\n          }\n          if (!good)\n\
    \            continue;\n          poly.erase(i--);\n          res.push_back(trig);\n\
    \          break;\n        }\n      }\n    }\n    res.push_back(poly);\n    return\
    \ res;\n  }\n\n  friend Large intersection_area(const Polygon &p, const circle\
    \ &C) {\n    Large res = 0;\n    int n = p.size();\n    for (int i = 0; i < n;\
    \ i++) {\n      res += circle::intersection_signed_area(C.radius, p[i + 1] - C.center,\n\
    \                                              p[i] - C.center);\n    }\n    return\
    \ abs(res);\n  }\n};\n\ntemplate <typename T, typename Large = T>\nstruct ConvexPolygon\
    \ : public Polygon<T, Large> {\n  typedef Point<T, Large> point;\n  typedef Segment<T,\
    \ Large> segment;\n  typedef Line<T, Large> line;\n  typedef Halfplane<T, Large>\
    \ halfplane;\n  typedef Circle<T, Large> circle;\n  typedef AngleComparator<PointDirection<point>,\
    \ T, Large> angle_comparator;\n  using Polygon<T, Large>::p;\n  int top;\n  ConvexPolygon()\
    \ {}\n  ConvexPolygon(const vector<point> &p) : Polygon<T, Large>(p) { normalize();\
    \ }\n  template <typename G>\n  ConvexPolygon(const vector<pair<point, G>> &p)\
    \ : Polygon<T, Large>(p) {\n    normalize();\n  }\n  void normalize() {\n    auto\
    \ bottom = min_element(p.begin(), p.end());\n    rotate(p.begin(), bottom, p.end());\n\
    \    top = max_element(p.begin(), p.end()) - p.begin();\n  }\n  ConvexPolygon\
    \ &operator+=(const point &pt) {\n    for (auto &q : p)\n      q += pt;\n    return\
    \ *this;\n  }\n  ConvexPolygon &operator-=(const point &pt) {\n    for (auto &q\
    \ : p)\n      q -= pt;\n    return *this;\n  }\n  ConvexPolygon &operator*=(const\
    \ Large k) {\n    for (auto &q : p)\n      q *= k;\n    return *this;\n  }\n \
    \ ConvexPolygon &operator/=(const Large k) {\n    for (auto &q : p)\n      q /=\
    \ k;\n    return *this;\n  }\n  ConvexPolygon operator-() const {\n    ConvexPolygon\
    \ res = *this;\n    for (auto &q : res.p)\n      q = -q;\n    return res;\n  }\n\
    \n  int test(const point &q) const {\n    if (q < p[0] || q > p[top])\n      return\
    \ 1;\n    auto sig = ccw(p[0], p[top], q);\n    if (sig == 0) {\n      if (q ==\
    \ p[0] || q == p[top])\n        return 0;\n      return top == 1 || top + 1 ==\
    \ this->size() ? 0 : -1;\n    } else if (sig < 0) {\n      auto it = lower_bound(p.begin()\
    \ + 1, p.begin() + top, q);\n      return ccw(it[-1], q, it[0]);\n    } else {\n\
    \      auto it = upper_bound(p.rbegin(), p.rend() - top - 1, q);\n      auto pit_deref\
    \ = it == p.rbegin() ? p[0] : it[-1];\n      return ccw(*it, q, pit_deref);\n\
    \    }\n  }\n  template <typename Function> int extreme(Function direction) const\
    \ {\n    int n = this->size(), left = 0, leftSig;\n    const ConvexPolygon &poly\
    \ = *this;\n    auto vertex_cmp = [&poly, direction](int i, int j) {\n      return\
    \ ccw(poly[j] - poly[i], direction(poly[j]));\n    };\n    auto is_extreme = [n,\
    \ vertex_cmp](int i, int &iSig) {\n      return (iSig = vertex_cmp(i + 1, i))\
    \ >= 0 && vertex_cmp(i, i - 1) < 0;\n    };\n    for (int right = is_extreme(0,\
    \ leftSig) ? 1 : n; left + 1 < right;) {\n      int mid = (left + right) / 2,\
    \ midSig;\n      if (is_extreme(mid, midSig))\n        return mid;\n      if (leftSig\
    \ != midSig ? leftSig < midSig\n                            : leftSig == vertex_cmp(left,\
    \ mid))\n        right = mid;\n      else\n        left = mid, leftSig = midSig;\n\
    \    }\n    return poly.index(left);\n  }\n  void stab_extremes(const line &l,\
    \ int &left, int &right) const {\n    point direction = l.direction();\n    right\
    \ = extreme([&direction](const point &) { return direction; });\n    left = extreme([&direction](const\
    \ point &) { return -direction; });\n  }\n  friend vector<point> intersect(const\
    \ ConvexPolygon &poly, const line &l) {\n    point direction = l.direction();\n\
    \n    int left, right;\n    poly.stab_extremes(l, left, right);\n    auto vertex_cmp\
    \ = [&l, &direction](const point &q) {\n      return ccw(q - l.a, direction);\n\
    \    };\n    int rightSig = vertex_cmp(poly[right]), leftSig = vertex_cmp(poly[left]);\n\
    \    if (rightSig < 0 || leftSig > 0)\n      return {};\n    auto intersectChain\
    \ = [&l, &poly, vertex_cmp](int first, int last,\n                           \
    \                       int firstSig) {\n      int n = poly.size();\n      while\
    \ (poly.index(first + 1) != poly.index(last)) {\n        int mid = (first + last\
    \ + (first < last ? 0 : n)) / 2;\n        mid = poly.index(mid);\n        if (vertex_cmp(poly[mid])\
    \ == firstSig)\n          first = mid;\n        else\n          last = mid;\n\
    \      }\n      return intersect(l, line(poly[first], poly[last]));\n    };\n\
    \    return {intersectChain(left, right, leftSig).first,\n            intersectChain(right,\
    \ left, rightSig).first};\n  }\n  friend bool has_intersection(const ConvexPolygon\
    \ &p, const line &l) {\n    point direction = l.direction();\n    int left, right;\n\
    \    p.stab_extremes(l, left, right);\n    auto vertex_cmp = [&l, &direction](const\
    \ point &q) {\n      return ccw(q - l.a, direction);\n    };\n    int rightSig\
    \ = vertex_cmp(p[right]), leftSig = vertex_cmp(p[left]);\n    if (rightSig < 0\
    \ || leftSig > 0)\n      return false;\n    return true;\n  }\n  friend Large\
    \ dist(const ConvexPolygon &p, const line &l) {\n    point direction = l.direction();\n\
    \    int left, right;\n    p.stab_extremes(l, left, right);\n    auto vertex_cmp\
    \ = [&l, &direction](const point &q) {\n      return ccw(q - l.a, direction);\n\
    \    };\n    int rightSig = vertex_cmp(p[right]), leftSig = vertex_cmp(p[left]);\n\
    \    if (rightSig < 0 || leftSig > 0) {\n      return min(dist(l, p[right]), dist(l,\
    \ p[left]));\n    } else {\n      return 0;\n    }\n  }\n  template <typename\
    \ Function>\n  friend void antipodals(const ConvexPolygon &poly, Function f) {\n\
    \    if (poly.size() <= 1)\n      return;\n    if (poly.size() == 2)\n      return\
    \ void(f(0, 1));\n    auto area = [&poly](int i, int j, int k) {\n      return\
    \ abs(cross(poly[i], poly[j], poly[k]));\n    };\n    auto func = [f, &poly](int\
    \ i, int j) {\n      return f(poly.index(i), poly.index(j));\n    };\n\n    int\
    \ p = -1;\n    int q = 0;\n    while (area(p, p + 1, q + 1) > area(p, p + 1, q))\n\
    \      q++;\n    int p0 = 0;\n    int q0 = q;\n    while (poly.index(q) != p0)\
    \ {\n      p++;\n      func(p, q);\n      while (area(p, p + 1, q + 1) > area(p,\
    \ p + 1, q)) {\n        q++;\n        if (poly.index(p) != poly.index(q0) || poly.index(q)\
    \ != p0)\n          func(p, q);\n        else\n          return;\n      }\n  \
    \    if (area(p, p + 1, q + 1) == area(p, p + 1, q)) {\n        if (poly.index(p)\
    \ != poly.index(q0) || poly.index(q) != p0)\n          func(p, q + 1);\n     \
    \   else\n          func(p + 1, q);\n      }\n    }\n  }\n  friend ConvexPolygon\
    \ minkowski_sum(const vector<ConvexPolygon> &v) {\n    vector<point> vectors;\n\
    \    point origin;\n    for (auto &poly : v) {\n      origin += poly[0];\n   \
    \   for (int i = 0; i < poly.size(); i++)\n        vectors.push_back(poly[i +\
    \ 1] - poly[i]);\n    }\n    angle_comparator::sortByAngle(vectors.begin(), vectors.end());\n\
    \    auto last = point();\n    if (!vectors.empty()) {\n      last = vectors.back();\n\
    \      vectors.pop_back();\n    }\n    vector<point> res;\n    res.push_back(origin);\n\
    \    for (auto &v : vectors) {\n      res.push_back(res.back() + v);\n      int\
    \ n = res.size();\n      if (n >= 3 && collinear(res[n - 3], res[n - 2], res[n\
    \ - 1]))\n        res.erase(res.begin() + n - 2);\n    }\n    int n = res.size();\n\
    \    if (n >= 3 && collinear(res[n - 2], res[n - 1], res[0]))\n      res.pop_back();\n\
    \    if (res.size() >= 3 && collinear(res.back(), res[0], res[1]))\n      res.erase(res.begin());\n\
    \    return ConvexPolygon(res);\n  }\n  friend ConvexPolygon minkowski_sum(const\
    \ ConvexPolygon &a,\n                                     const ConvexPolygon\
    \ &b) {\n    vector<ConvexPolygon> v;\n    v.push_back(a);\n    v.push_back(b);\n\
    \    return minkowski_sum(v);\n  }\n  friend ConvexPolygon intersect(const ConvexPolygon\
    \ &a,\n                                 const ConvexPolygon &b) {\n    vector<point>\
    \ candidates;\n    auto consider = [&candidates](const ConvexPolygon &a,\n   \
    \                               const ConvexPolygon &b) {\n      for (int i =\
    \ 0; i < a.size(); i++) {\n        if (b.test(a[i]) <= 0)\n          candidates.push_back(a[i]);\n\
    \        segment s(a[i], a[i + 1]);\n        vector<point> ps = intersect(b, s.as_line());\n\
    \        for (auto p : ps) {\n          if (s.contains(p))\n            candidates.push_back(p);\n\
    \        }\n      }\n    };\n    consider(a, b);\n    consider(b, a);\n    auto\
    \ res = ConvexPolygon(ConvexPolygon::convex_hull(candidates));\n    return res;\n\
    \  }\n  friend Large intersection_area_or_dist(const ConvexPolygon &a,\n     \
    \                                    const ConvexPolygon &b) {\n    ConvexPolygon\
    \ inter = intersect(a, b);\n    if (inter.size() > 0)\n      return max(area(inter),\
    \ Large(0));\n    ConvexPolygon sum = minkowski_sum(a, -b);\n    Large res = numeric_limits<Large>::max();\n\
    \    for (int i = 0; i < sum.size(); i++) {\n      res = min(res, dist(segment(sum[i],\
    \ sum[i + 1]), point()));\n    }\n    return -res;\n  }\n  void cut(const halfplane&\
    \ pl) {\n    int n = this->size();\n    if(n < 3) return;\n    p.push_back(p[0]);\n\
    \n    auto pl_line = pl.as_line();\n\n    vector<point> out;\n    bool inside\
    \ = pl.strictly_contains(p[0]);\n    if(inside) out.push_back(p[0]);\n\n    for(int\
    \ i = 1; i <= n; i++) {\n      if(pl.strictly_contains(p[i])) {\n        if(!inside)\
    \ {\n          out.push_back(intersect(pl_line, line(p[i-1], p[i])).first);\n\
    \        }\n        out.push_back(p[i]);\n        inside = true;\n      } else\
    \ {\n        if(inside) {\n          out.push_back(intersect(pl_line, line(p[i-1],\
    \ p[i])).first);\n        }\n        inside = false;\n      }\n    }\n\n    if(!out.empty()\
    \ && out[0] == out.back()) out.pop_back();\n    *this = ConvexPolygon(ConvexPolygon::convex_hull(out));\n\
    \  }\n  void cut(const ConvexPolygon &rhs) {\n    for(int i = 0; i < rhs.size();\
    \ i++) {\n      cut(halfplane::from_points(rhs[i], rhs[i+1]));\n    }\n  }\n};\n\
    } // namespace plane\n\ntemplate <typename T, typename Large = T>\nstruct PolygonPlane\
    \ : public CirclePlane<T, Large> {\n  typedef plane::Polygon<T, Large> polygon;\n\
    \  typedef plane::ConvexPolygon<T, Large> convex_polygon;\n};\n\n} // namespace\
    \ geo\n} // namespace lib\n\n\n#line 6 \"geometry/Caliper.cpp\"\n\nnamespace lib\
    \ {\nusing namespace std;\nnamespace geo {\nnamespace plane {\ntemplate <typename\
    \ T, typename Large = T,\n          typename enable_if<!is_integral<T>::value>::type\
    \ * = nullptr,\n          typename enable_if<!is_integral<T>::value>::type * =\
    \ nullptr>\nstruct Caliper {\n  typedef Point<T, Large> point;\n  typedef Line<T,\
    \ Large> line;\n  point p;\n  Large ang;\n  Caliper(point a, Large alpha) : p(a)\
    \ {\n    ang = remainder(alpha, 2 * trig::PI);\n    while (ang < 0)\n      ang\
    \ += 2 * trig::PI;\n  }\n  Large angle_to(const point &q) const {\n    return\
    \ remainder(arg(q - p) - ang, 2 * trig::PI);\n  }\n  void rotate(double theta)\
    \ {\n    ang += theta;\n    while (ang > 2 * trig::PI)\n      ang -= 2 * trig::PI;\n\
    \    while (ang < 0)\n      ang += 2 * trig::PI;\n  }\n  void move(const point\
    \ &q) { p = q; }\n  point versor() const { return point::polar(1.0, ang); }\n\
    \  line as_line(Large scale = 1.0) const {\n    return line(p, p + versor() *\
    \ scale);\n  }\n  friend Large dist(const Caliper &a, const Caliper &b) {\n  \
    \  return dist(a.as_line(), b.p);\n  }\n};\n\ntemplate <typename T, typename Large\
    \ = T> struct PolygonCalipers {\n  constexpr static Large LIMIT = 4 * acosl(-1);\n\
    \n  typedef Point<T, Large> point;\n  typedef Caliper<T, Large> caliper;\n  typedef\
    \ ConvexPolygon<T, Large> polygon;\n  typedef pair<int, Large> descriptor;\n\n\
    \  polygon poly;\n  vector<caliper> calipers;\n  vector<int> indices;\n  vector<int>\
    \ walked;\n  Large angle_walked;\n\n  PolygonCalipers(const polygon &poly, const\
    \ vector<descriptor> &descriptors)\n      : poly(poly), walked(descriptors.size()),\
    \ angle_walked(0) {\n    indices.reserve(descriptors.size());\n    calipers.reserve(descriptors.size());\n\
    \    for (size_t i = 0; i < descriptors.size(); i++) {\n      calipers.emplace_back(poly[descriptors[i].first],\
    \ descriptors[i].second);\n      indices.emplace_back(descriptors[i].first);\n\
    \    }\n  }\n  caliper operator[](int i) const { return calipers[i]; }\n  int\
    \ index(int i) const { return indices[i]; }\n  bool has_next() const {\n    return\
    \ *min_element(walked.begin(), walked.end()) < poly.size() &&\n           angle_walked\
    \ < LIMIT;\n  }\n  Large angle_to_next(int i) const {\n    int u = indices[i];\n\
    \    return calipers[i].angle_to(poly[u + 1]);\n  }\n  void step_(int i) {\n \
    \   int u = indices[i]++;\n    indices[i] %= poly.size();\n    calipers[i].move(poly[u\
    \ + 1]);\n    walked[i]++;\n  }\n\n  void next() {\n    int i = 0;\n    Large\
    \ best = angle_to_next(0);\n    for (size_t j = 1; j < calipers.size(); j++) {\n\
    \      Large cur = angle_to_next(j);\n      if (cur < best) {\n        best =\
    \ cur;\n        i = j;\n      }\n    }\n    Large alpha = angle_to_next(i);\n\
    \    for (auto &caliper : calipers)\n      caliper.rotate(alpha);\n    step_(i);\n\
    \    angle_walked += alpha;\n  }\n};\n} // namespace plane\n\n} // namespace geo\n\
    } // namespace lib\n\n\n"
  code: "#ifndef _LIB_GEOMETRY_CALIPER\n#define _LIB_GEOMETRY_CALIPER\n#include \"\
    Line2D.cpp\"\n#include \"Polygon2D.cpp\"\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace geo {\nnamespace plane {\ntemplate <typename\
    \ T, typename Large = T,\n          typename enable_if<!is_integral<T>::value>::type\
    \ * = nullptr,\n          typename enable_if<!is_integral<T>::value>::type * =\
    \ nullptr>\nstruct Caliper {\n  typedef Point<T, Large> point;\n  typedef Line<T,\
    \ Large> line;\n  point p;\n  Large ang;\n  Caliper(point a, Large alpha) : p(a)\
    \ {\n    ang = remainder(alpha, 2 * trig::PI);\n    while (ang < 0)\n      ang\
    \ += 2 * trig::PI;\n  }\n  Large angle_to(const point &q) const {\n    return\
    \ remainder(arg(q - p) - ang, 2 * trig::PI);\n  }\n  void rotate(double theta)\
    \ {\n    ang += theta;\n    while (ang > 2 * trig::PI)\n      ang -= 2 * trig::PI;\n\
    \    while (ang < 0)\n      ang += 2 * trig::PI;\n  }\n  void move(const point\
    \ &q) { p = q; }\n  point versor() const { return point::polar(1.0, ang); }\n\
    \  line as_line(Large scale = 1.0) const {\n    return line(p, p + versor() *\
    \ scale);\n  }\n  friend Large dist(const Caliper &a, const Caliper &b) {\n  \
    \  return dist(a.as_line(), b.p);\n  }\n};\n\ntemplate <typename T, typename Large\
    \ = T> struct PolygonCalipers {\n  constexpr static Large LIMIT = 4 * acosl(-1);\n\
    \n  typedef Point<T, Large> point;\n  typedef Caliper<T, Large> caliper;\n  typedef\
    \ ConvexPolygon<T, Large> polygon;\n  typedef pair<int, Large> descriptor;\n\n\
    \  polygon poly;\n  vector<caliper> calipers;\n  vector<int> indices;\n  vector<int>\
    \ walked;\n  Large angle_walked;\n\n  PolygonCalipers(const polygon &poly, const\
    \ vector<descriptor> &descriptors)\n      : poly(poly), walked(descriptors.size()),\
    \ angle_walked(0) {\n    indices.reserve(descriptors.size());\n    calipers.reserve(descriptors.size());\n\
    \    for (size_t i = 0; i < descriptors.size(); i++) {\n      calipers.emplace_back(poly[descriptors[i].first],\
    \ descriptors[i].second);\n      indices.emplace_back(descriptors[i].first);\n\
    \    }\n  }\n  caliper operator[](int i) const { return calipers[i]; }\n  int\
    \ index(int i) const { return indices[i]; }\n  bool has_next() const {\n    return\
    \ *min_element(walked.begin(), walked.end()) < poly.size() &&\n           angle_walked\
    \ < LIMIT;\n  }\n  Large angle_to_next(int i) const {\n    int u = indices[i];\n\
    \    return calipers[i].angle_to(poly[u + 1]);\n  }\n  void step_(int i) {\n \
    \   int u = indices[i]++;\n    indices[i] %= poly.size();\n    calipers[i].move(poly[u\
    \ + 1]);\n    walked[i]++;\n  }\n\n  void next() {\n    int i = 0;\n    Large\
    \ best = angle_to_next(0);\n    for (size_t j = 1; j < calipers.size(); j++) {\n\
    \      Large cur = angle_to_next(j);\n      if (cur < best) {\n        best =\
    \ cur;\n        i = j;\n      }\n    }\n    Large alpha = angle_to_next(i);\n\
    \    for (auto &caliper : calipers)\n      caliper.rotate(alpha);\n    step_(i);\n\
    \    angle_walked += alpha;\n  }\n};\n} // namespace plane\n\n} // namespace geo\n\
    } // namespace lib\n\n#endif\n"
  dependsOn:
  - geometry/Line2D.cpp
  - geometry/GeometryEpsilon.cpp
  - Epsilon.cpp
  - geometry/Trigonometry.cpp
  - geometry/Polygon2D.cpp
  - geometry/Circle2D.cpp
  - utils/Annotation.cpp
  isVerificationFile: false
  path: geometry/Caliper.cpp
  requiredBy: []
  timestamp: '2021-11-23 18:59:56-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/Caliper.cpp
layout: document
redirect_from:
- /library/geometry/Caliper.cpp
- /library/geometry/Caliper.cpp.html
title: geometry/Caliper.cpp
---
