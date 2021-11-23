---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Epsilon.cpp
    title: Epsilon.cpp
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
    path: utils/Annotation.cpp
    title: utils/Annotation.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/Caliper.cpp
    title: geometry/Caliper.cpp
  - icon: ':warning:'
    path: geometry/Polygon2D.cpp
    title: geometry/Polygon2D.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/Circle2D.cpp\"\n\n\n#line 1 \"utils/Annotation.cpp\"\
    \n\n\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\ntemplate\
    \ <typename T, typename A = void>\nstruct Note : public T {\nprivate:\n    A m_data\
    \ = A();\n    Note(const T& t, const A& a) : T(t), m_data(a) {}\npublic:\n   \
    \ using T::T;\n\n    static Note make(const T& t, const A& a) {\n        return\
    \ Note(t, a);\n    }\n\n    friend A& annotation(Note& note) {\n        return\
    \ note.m_data;\n    }\n    friend const A& annotation(const Note& note) {\n  \
    \      return note.m_data;\n    }\n\n    template<typename C, typename D>\n  \
    \  operator Note<T,A>() const {\n        return Note<C, D>(*this, m_data);\n \
    \   }\n};\n\ntemplate <typename T>\nstruct Note<T, void> : public T {\n    using\
    \ T::T;\n    using T::operator=;\n    \n    Note(const T& a) : T(a) {}\n    Note(T\
    \ &&a): T(std::move(a)) {}\n};\n\ntemplate<typename T, typename A>\nNote<T, A>\
    \ make_note(const T& t, const A& a) {\n    return Note<T, A>::make(t, a);\n}\n\
    } // namespace lib\n\n\n#line 1 \"geometry/Line2D.cpp\"\n\n\n#line 1 \"geometry/GeometryEpsilon.cpp\"\
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
    \ // namespace lib\n\n\n#line 6 \"geometry/Circle2D.cpp\"\n\nnamespace lib {\n\
    using namespace std;\nnamespace geo {\nnamespace plane {\ntemplate <typename T,\
    \ typename Large = T> struct Barycentric {\n  typedef Point<T, Large> point;\n\
    \  point r1, r2, r3;\n  T a, b, c;\n\n  Barycentric(const point &r1, const point\
    \ &r2, const point &r3, T a = 1,\n              T b = 1, T c = 1)\n      : r1(r1),\
    \ r2(r2), r3(r3), a(a), b(b), c(c) {}\n  point as_point() const { return (r1 *\
    \ a + r2 * b + r3 * c) / (a + b + c); }\n\n  static Barycentric centroid(const\
    \ point &r1, const point &r2,\n                              const point &r3)\
    \ {\n    return Barycentric(r1, r2, r3);\n  }\n  static Barycentric circumcenter(const\
    \ point &r1, const point &r2,\n                                  const point &r3)\
    \ {\n    Large a = norm_sq(r2 - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);\n\
    \    return Barycentric(r1, r2, r3, a * (b + c - a), b * (c + a - b),\n      \
    \                 c * (a + b - c));\n  }\n  static Barycentric incenter(const\
    \ point &r1, const point &r2,\n                              const point &r3)\
    \ {\n    return Barycentric(r1, r2, r3, norm(r2 - r3), norm(r1 - r3), norm(r1\
    \ - r2));\n  }\n  static Barycentric orthocenter(const point &r1, const point\
    \ &r2,\n                                 const point &r3) {\n    Large a = norm_sq(r2\
    \ - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);\n    return Barycentric(r1,\
    \ r2, r3, (a + b - c) * (c + a - b),\n                       (b + c - a) * (a\
    \ + b - c), (c + a - b) * (b + c - a));\n  }\n  static Barycentric excenter(const\
    \ point &r1, const point &r2,\n                              const point &r3)\
    \ {\n    return Barycentric(r1, r2, r3, -norm(r2 - r3), norm(r1 - r3),\n     \
    \                  norm(r1 - r2));\n  }\n};\n\ntemplate <typename T, typename\
    \ Large = T> struct Circle {\n  typedef Point<T, Large> point;\n  typedef Line<T,\
    \ Large> line;\n  typedef Barycentric<Large> bary;\n  typedef Segment<T, Large>\
    \ segment;\n  point center;\n  T radius;\n\n  Circle(point center, T radius) :\
    \ center(center), radius(radius) {}\n  Circle(const point &p1, const point &p2,\
    \ const point &p3) {\n    center = bary::circumcenter(p1, p2, p3).as_point();\n\
    \    radius = dist(center, p1);\n  }\n  Circle(const point &p1, const point &p2)\
    \ {\n    center = (p1 + p2) / 2;\n    radius = dist(center, p1);\n  }\n  bool\
    \ crosses_x_axis(point p = point()) const {\n    auto c = center - p;\n    return\
    \ GEOMETRY_COMPARE0(T, c.y + radius) >= 0 && GEOMETRY_COMPARE0(T, c.y - radius)\
    \ < 0;\n  }\n  static Circle incircle(const point &p1, const point &p2, const\
    \ point &p3) {\n    point center = bary::incenter(p1, p2, p3).as_point();\n  \
    \  return Circle(center, dist(line(p1, p2), center));\n  }\n  friend pair<segment,\
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
    \ Large> circle;\n};\n\n} // namespace geo\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_GEOMETRY_CIRCLE_2D\n#define _LIB_GEOMETRY_CIRCLE_2D\n#include\
    \ \"../utils/Annotation.cpp\"\n#include \"Line2D.cpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace geo {\nnamespace plane {\n\
    template <typename T, typename Large = T> struct Barycentric {\n  typedef Point<T,\
    \ Large> point;\n  point r1, r2, r3;\n  T a, b, c;\n\n  Barycentric(const point\
    \ &r1, const point &r2, const point &r3, T a = 1,\n              T b = 1, T c\
    \ = 1)\n      : r1(r1), r2(r2), r3(r3), a(a), b(b), c(c) {}\n  point as_point()\
    \ const { return (r1 * a + r2 * b + r3 * c) / (a + b + c); }\n\n  static Barycentric\
    \ centroid(const point &r1, const point &r2,\n                              const\
    \ point &r3) {\n    return Barycentric(r1, r2, r3);\n  }\n  static Barycentric\
    \ circumcenter(const point &r1, const point &r2,\n                           \
    \       const point &r3) {\n    Large a = norm_sq(r2 - r3), b = norm_sq(r3 - r1),\
    \ c = norm_sq(r1 - r2);\n    return Barycentric(r1, r2, r3, a * (b + c - a), b\
    \ * (c + a - b),\n                       c * (a + b - c));\n  }\n  static Barycentric\
    \ incenter(const point &r1, const point &r2,\n                              const\
    \ point &r3) {\n    return Barycentric(r1, r2, r3, norm(r2 - r3), norm(r1 - r3),\
    \ norm(r1 - r2));\n  }\n  static Barycentric orthocenter(const point &r1, const\
    \ point &r2,\n                                 const point &r3) {\n    Large a\
    \ = norm_sq(r2 - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);\n    return\
    \ Barycentric(r1, r2, r3, (a + b - c) * (c + a - b),\n                       (b\
    \ + c - a) * (a + b - c), (c + a - b) * (b + c - a));\n  }\n  static Barycentric\
    \ excenter(const point &r1, const point &r2,\n                              const\
    \ point &r3) {\n    return Barycentric(r1, r2, r3, -norm(r2 - r3), norm(r1 - r3),\n\
    \                       norm(r1 - r2));\n  }\n};\n\ntemplate <typename T, typename\
    \ Large = T> struct Circle {\n  typedef Point<T, Large> point;\n  typedef Line<T,\
    \ Large> line;\n  typedef Barycentric<Large> bary;\n  typedef Segment<T, Large>\
    \ segment;\n  point center;\n  T radius;\n\n  Circle(point center, T radius) :\
    \ center(center), radius(radius) {}\n  Circle(const point &p1, const point &p2,\
    \ const point &p3) {\n    center = bary::circumcenter(p1, p2, p3).as_point();\n\
    \    radius = dist(center, p1);\n  }\n  Circle(const point &p1, const point &p2)\
    \ {\n    center = (p1 + p2) / 2;\n    radius = dist(center, p1);\n  }\n  bool\
    \ crosses_x_axis(point p = point()) const {\n    auto c = center - p;\n    return\
    \ GEOMETRY_COMPARE0(T, c.y + radius) >= 0 && GEOMETRY_COMPARE0(T, c.y - radius)\
    \ < 0;\n  }\n  static Circle incircle(const point &p1, const point &p2, const\
    \ point &p3) {\n    point center = bary::incenter(p1, p2, p3).as_point();\n  \
    \  return Circle(center, dist(line(p1, p2), center));\n  }\n  friend pair<segment,\
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
    \ Large> circle;\n};\n\n} // namespace geo\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - utils/Annotation.cpp
  - geometry/Line2D.cpp
  - geometry/GeometryEpsilon.cpp
  - Epsilon.cpp
  - geometry/Trigonometry.cpp
  isVerificationFile: false
  path: geometry/Circle2D.cpp
  requiredBy:
  - geometry/Caliper.cpp
  - geometry/Polygon2D.cpp
  timestamp: '2021-11-23 18:59:56-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/Circle2D.cpp
layout: document
redirect_from:
- /library/geometry/Circle2D.cpp
- /library/geometry/Circle2D.cpp.html
title: geometry/Circle2D.cpp
---
