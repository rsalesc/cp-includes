#ifndef _LIB_GEOMETRY_LINE_2D
#define _LIB_GEOMETRY_LINE_2D
#include <bits/stdc++.h>
#include "GeometryEpsilon.cpp"
#include "Trigonometry.cpp"

namespace lib {
  using namespace std;
namespace geo {
namespace plane {
  namespace {
    template<typename T>
    bool scalar_between(T a, T o, T b) {
      if(a > b)
        swap(a, b);
      return GEOMETRY_COMPARE(T, a, o) <= 0
        && GEOMETRY_COMPARE(T, o, b) <= 0;
    }
    
    template<typename T>
    bool scalar_strictly_between(T a, T o, T b) {
      if(a > b) 
        swap(a, b);
      int x = GEOMETRY_COMPARE(T, a, o);
      int y = GEOMETRY_COMPARE(T, o, b);
      return x <= 0 && y <= 0 && (x < 0 || y < 0);
    }
  } 

  template<typename T, typename Large = T>
  struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}
    template<typename G, typename H>
    explicit operator Point<G, H>() const {
      return Point<G, H>((G)x, (G)y);
    }
    friend Point reversed(const Point& a) { return Point(a.y, a.x); }
    Point& operator+=(const Point& rhs) {
      x += rhs.x, y += rhs.y;
      return *this;
    }
    Point& operator-=(const Point& rhs) {
      x -= rhs.x, y -= rhs.y;
      return *this;
    }
    Point& operator*=(T k) {
      x *= k, y *= k;
      return *this;
    }
    Point& operator/=(T k) {
      x /= k, y /= k;
      return *this;
    }
    Point operator+(const Point& rhs) const {
      Point res = *this;
      return res += rhs;
    }
    Point operator-(const Point& rhs) const {
      Point res = *this;
      return res -= rhs;
    }
    Point operator*(T k) const {
      Point res = *this;
      return res *= k;
    }
    Point operator/(T k) const {
      Point res = *this;
      return res /= k;
    }
    Point operator-() const { return Point(-x, -y); }
    inline friend Point convolve(const Point& a, const Point& b) {
      return Point(a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y);
    }
    inline friend Large cross(const Point& a, const Point& b) {
      return (Large)a.x*b.y - (Large)a.y*b.x;
    }
    friend Large cross(const Point& a, const Point& b, const Point& c) {
      return cross(b-a, c-a);
    }
    inline friend Large dot(const Point& a, const Point& b) {
      return (Large)a.x*b.x + (Large)a.y*b.y;
    }
    friend int ccw(const Point& u, const Point& v) {
      return GEOMETRY_COMPARE0(Large, cross(u, v));
    }
    friend int ccw(const Point& a, const Point& b, const Point& c) {
      return ccw(b-a, c-a);
    }
    friend Large norm(const Point& a) {
      return sqrtl(dot(a, a));
    }
    friend Large norm_sq(const Point& a) {
      return dot(a, a);
    }
    bool is_null() const {
      return GEOMETRY_COMPARE0(Large, norm_sq(*this)) == 0;
    }
    bool is_versor() const {
      return GEOMETRY_COMPARE(Large, norm_sq(*this), (Large)1) == 0;
    }
    static Point polar(Large d, Large theta) {
      return Point(trig::cos(theta) * d, trig::sin(theta) * d);
    }
    friend Point rotate(const Point& a, Large theta) {
      return convolve(a, polar((Large)1, theta));
    }
    friend Point ortho(const Point& a) {
      return Point(-a.y, a.x);
    }
    friend Large arg(const Point& a) {
      return trig::atan2(a.y, a.x);
    }
    friend Large signed_angle(const Point& v, const Point& w) {
      return remainder(arg(w) - arg(v), 2.0 * trig::PI);
    }
    friend Large angle(const Point& v, const Point& w) {
      return abs(signed_angle(v, w));
    }
    friend Large ccw_angle(const Point& v) {
      Large res = arg(v);
      if(res < 0) res += 2.0 * trig::PI;
      return res;
    }
    friend Large ccw_angle(const Point& v, const Point& w) {
      Large res = signed_angle(v, w);
      if(res < 0) res += 2.0 * trig::PI;
      return res;
    }
    inline friend Point normalized(const Point& a, Large k) {
      return a.is_null() ? Point() : a / norm(a) * k; 
    }
    inline friend Point versor(const Point& a) {
      return normalized(a, (Large)1);
    }
    friend bool collinear(const Point& a, const Point& b) {
      return GEOMETRY_COMPARE0(Large, cross(a, b)) == 0;
    }
    friend bool collinear(const Point& a, const Point& b, const Point& c) {
      return collinear(b - a, c - a);
    } 
    friend Point project(const Point& a, const Point& v) {
      return v / norm_sq(v) * dot(a, v);
    }
    template<typename G = T,
             typename enable_if<!is_integral<G>::value>::type* = nullptr>
    friend Point reflect(const Point& a, const Point& v) {
      Point n = versor(v);
      return a - n * 2 * dot(n, v);
    }
    friend bool between(const Point& a, const Point& b, const Point& c) {
      return collinear(a, b, c) && GEOMETRY_COMPARE0(Large, dot(a - b, c - b)) <= 0; 
    }
    friend bool strictly_between(const Point& a, const Point& b, const Point& c) {
      return collinear(a, b, c) && GEOMETRY_COMPARE0(Large, dot(a - b, c - b)) < 0; 
    }
    friend bool collinear_between(const Point a, const Point& o, const Point& b) {
      return scalar_between(a.x, o.x, b.x) && scalar_between(a.y, o.y, b.y);
    }
    friend bool collinear_strictly_between(const Point& a, const Point& o, const Point& b) {
      return scalar_between(a.x, o.x, b.x) && scalar_between(a.y, o.y, b.y);
    }
    friend Large dist(const Point& a, const Point& b) {
      return norm(a - b);
    }
    friend bool operator==(const Point& a, const Point& b) {
      return GEOMETRY_COMPARE(T, a.x, b.x) == 0
        && GEOMETRY_COMPARE(T, a.y, b.y) == 0;
    }
    friend bool operator!=(const Point& a, const Point& b) {
      return !(a == b);
    }
    friend bool operator<(const Point& a, const Point& b) {
      return tie(a.y, a.x) < tie(b.y, b.x);
    }
    friend bool operator>(const Point& a, const Point& b) {
      return tie(a.y, a.x) > tie(b.y, b.x);
    }
    friend bool operator>=(const Point& a, const Point& b) {
      return tie(a.y, a.x) >= tie(b.y, b.x);
    }
    friend bool operator<=(const Point& a, const Point& b) {
      return tie(a.y, a.x) <= tie(b.y, b.x);
    }
    friend istream& operator>>(istream& in, Point& p) {
      return in >> p.x >> p.y;
    }
    friend ostream& operator<<(ostream& out, const Point& p) {
      return out << p.x << " " << p.y;
    }
  };

  template<typename T, typename Large = T>
  struct Rectangle {
    typedef Point<T, Large> point;

    T minx, miny, maxx, maxy;
    Rectangle() {
      minx = miny = numeric_limits<T>::max();
      maxx = maxy = numeric_limits<T>::min();
    }

    Rectangle(const initializer_list<point>& points) : Rectangle() {
      for(const auto& p : points) {
        minx = min(minx, p.x);
        maxx = max(maxx, p.x);
        miny = min(miny, p.y);
        maxy = max(maxy, p.y);
      }
    }

    bool contains(const point& p) const {
      return GEOMETRY_COMPARE(T, minx, p.x) <= 0
          && GEOMETRY_COMPARE(T, p.x, maxx) <= 0
          && GEOMETRY_COMPARE(T, miny, p.y) <= 0
          && GEOMETRY_COMPARE(T, p.y, maxy) <= 0;
    }
  };

  template<typename T, typename Large = T>
  struct Line {
    typedef Point<T, Large> point;
    typedef Line<T, Large> line;
    point a, b;
    Line(point a, point b) : a(a), b(b) {}
    template<typename G = T,
             typename enable_if<!is_integral<G>::value>::type* = nullptr>
    Line(T A, T B, T C) {
      if(GEOMETRY_COMPARE0(Large, A))
        a = point(-C/A, 0), b = point((-C-B)/A, 1);
      else if(GEOMETRY_COMPARE0(Large, B))
        a = point(0, -C/B), b = point(1, (-C-A)/B);
      else
        assert(false);
    }
    template<typename G, typename H>
    explicit operator Line<G, H>() const {
      return Line<G, H>(Point<G, H>(a), Point<G, H>(b));
    }
    point direction() const { return b - a; }
    friend point project(const point& p, const line& v) {
      return project(p - v.a, v.b - v.a) + v.a;
    }
    friend bool collinear(const line& u, const line& v) {
      return collinear(u.a, u.b, v.a) && collinear(u.a, u.b, v.b);
    }
    bool contains(const point& p) const {
      return collinear(a, b, p);
    }
    friend bool parallel(const line& u, const line& v) {
      return collinear(u.b - u.a, v.b - v.a);
    }
    friend bool opposite(const line& l, const point& p1, const point& p2) {
      int x = GEOMETRY_COMPARE0(Large, cross(p1 - l.a, l.direction()));
      int y = GEOMETRY_COMPARE0(Large, cross(p2 - l.a, l.direction()));
      return x * y <= 0;
    }
    friend pair<point, bool> intersect(const line& l1, const line& l2) {
      Large c1 = cross(l2.a - l1.a, l1.b - l1.a);
      Large c2 = cross(l2.b - l1.a, l1.b - l1.a);
      if(GEOMETRY_COMPARE0(Large, c1 - c2) == 0)
        return {{}, false};
      return {(l2.b * c1 - l2.a * c2) / (c1 - c2), true};
    }
    friend bool has_unique_intersection(const line& l1, const line& l2) {
      return !parallel(l1, l2);
    }
    friend bool has_intersection(const line& l1, const line& l2) {
      return collinear(l1, l2) || has_unique_intersection(l1, l2);
    }
    friend Large dist(const line& l1, const point& p) {
      // TODO: improve this
      return dist(p, project(p, l1));
    }
    friend Large dist(const line& l1, const line& l2) {
      if(has_intersection(l1, l2))
        return 0;
      // TODO: improve this
      return dist(l1.a, project(l1.a, l2));
    }
  };

  template<typename T, typename Large = T>
  struct Ray {
    typedef Point<T, Large> point;
    typedef Line<T, Large> line;
    typedef Ray<T, Large> ray;
    point a, b;

    Ray(point a, point direction) : a(a), b(a + direction) {}

    static ray from_points(point a, point b) { return ray(a, b - a); }
    point direction() const { return b - a; }
    point direction_versor() const { return versor(direction()); }

    line as_line() const { return line(a, b); }
    explicit operator line() const { return as_line(); }

    template<typename G, typename H>
    explicit operator Ray<G, H>() const {
      return Ray<G, H>(Point<G, H>(a), Point<G, H>(b));
    }
    bool contains(const point& p) const {
      return collinear(a, b, p) &&
        GEOMETRY_COMPARE0(Large, dot(p - a, b - a)) >= 0;
    }
    bool strictly_contains(const point& p) const {
      return collinear(a, b, p) &&
        GEOMETRY_COMPARE0(Large, dot(p - a, b - a)) > 0;
    }
    bool collinear_contains(const point& p) const {
      point dir = direction();
      int dx = GEOMETRY_COMPARE0(T, dir.x);
      if(dx == 0)
        return GEOMETRY_COMPARE0(T, dir.y) * GEOMETRY_COMPARE0(T, p.y - a.y) >= 0;
      else
        return dx * GEOMETRY_COMPARE0(T, p.x - a.x) >= 0;
    }
    bool collinear_strictly_contains(const point& p) const {
      point dir = direction();
      int dx = GEOMETRY_COMPARE0(T, dir.x);
      if(dx == 0)
        return GEOMETRY_COMPARE0(T, dir.y) * GEOMETRY_COMPARE0(T, p.y - a.y) > 0;
      else
        return dx * GEOMETRY_COMPARE0(T, p.x - a.x) > 0;
    }
    friend pair<point, bool> intersect(const ray& r, const line& l) {
      auto p = intersect(r.as_line(), l);
      if(!p.second)
        return {{}, false};
      if(!r.collinear_contains(p.first))
        return {{}, false};
      return p;
    }
    friend pair<point, bool> intersect(const ray& a, const ray& b) {
      auto p = intersect(a, b.as_line());
      if(!p.second)
        return {{}, false};
      if(!b.collinear_contains(p.first))
        return {{}, false};
      return p;
    }
    friend bool has_unique_intersection(const ray& r, const line& l) {
      if(!has_unique_intersection(r.as_line(), l))
        return false;
      int x = GEOMETRY_COMPARE0(Large, cross(r.direction(), l.direction()));
      int y = GEOMETRY_COMPARE0(Large, cross(r.a - l.a, l.direction()));
      return x * y <= 0;
    }
    friend bool has_intersection(const ray& r, const line& l) {
      return collinear(r.as_line(), l) || has_unique_intersection(r, l);
    }
    friend bool has_unique_intersection(const ray& r1, const ray& r2) {
      // TODO: not efficient
      return has_unique_intersection(r1, r2.as_line())
        && has_unique_intersection(r2, r1.as_line());
    }
    friend bool has_intersection(const ray& r1, const ray& r2) {
      return r1.contains(r2.a) || has_unique_intersection(r1, r2);
    }
    friend Large dist(const ray& r, const point& p) {
      if(GEOMETRY_COMPARE0(Large, dot(r.direction(), p - r.a)) < 0)
        return dist(p, r.a);
      return dist(r.as_line(), p);
    }
    friend Large dist(const ray& r, const line& l) {
      if(has_intersection(r, l))
        return Large(0);
      return dist(l, r.a);
    }
    friend Large dist(const ray& r1, const ray& r2) {
      if(has_intersection(r1, r2))
        return Large(0);
      return min(dist(r1, r2.a), dist(r2, r1.a));
    }
  };

  template<typename T, typename Large = T>
  struct Segment {
    typedef Point<T, Large> point;
    typedef Line<T, Large> line;
    typedef Segment<T, Large> segment;
    typedef Ray<T, Large> ray;
    point a, b;

    Segment() {}
    Segment(point a, point b) : a(a), b(b) {}
    line as_line() const { return line(a, b); }
    explicit operator line() const { return as_line(); }
    bool is_degenerate() const { return a == b; }

    template<typename G, typename H>
    explicit operator Segment<G, H>() const {
      return Segment<G, H>(Point<G, H>(a), Point<G, H>(b));
    }
    bool contains(const point& p) const {
      return between(a, p, b);
    }
    bool strictly_contains(const point& p) const {
      return strictly_between(a, p, b);
    }
    bool collinear_contains(const point& p) const {
      return collinear_between(a, p, b);
    }
    bool collinear_strictly_contains(const point& p) const {
      return collinear_strictly_between(a, p, b);
    }
    friend pair<point, bool> intersect(const segment& s, const line& l) {
      auto p = intersect(s.as_line(), l);
      if(!p.second)
        return {{}, false};
      if(!s.collinear_contains(p.first))
        return {{}, false};
      return p;
    }
    friend pair<point, bool> intersect(const segment& s, const ray& r) {
      auto p = intersect(s.as_line(), r.as_line());
      if(!p.second)
        return {{}, false};
      if(!s.collinear_contains(p.first) || !r.collinear_contains(p.first))
        return {{}, false};
      return p;
    }
    friend pair<segment, int> intersect_segment(segment s1,
                                                 segment s2) {
      if(collinear(s1.as_line(), s2.as_line())) {
        if(s1.a > s1.b) swap(s1.a, s1.b);
        if(s2.a > s2.b) swap(s2.a, s2.b);
        segment res(max(s1.a, s2.a), min(s1.b, s2.b));
        return {res, int(res.a <= res.b) * 2};
      } else {
        auto p = intersect(s1, s2);
        return {segment(p.first, p.first), p.second};
      }
    }
    friend pair<point, bool> intersect(const segment& s1, const segment& s2) {
      auto p = intersect(s1, s2.as_line());
      if(!p.second)
        return {{}, false};
      if(!s2.collinear_contains(p.first))
        return {{}, false};
      return p;
    }
    friend bool has_unique_intersection(const segment& s, const line& l) {
      if(!has_unique_intersection(s.as_line(), l))
        return false;
      return opposite(l, s.a, s.b);
    }
    friend bool has_intersection(const segment& s, const line& l) {
      return collinear(s.as_line(), l) || has_unique_intersection(s, l);
    }
    friend bool has_unique_intersection(const segment& s, const ray& r) {
      if(!has_unique_intersection(r, s.as_line()))
        return false;
      return opposite(r.as_line(), s.a, s.b);
    }
    friend bool has_intersection(const segment& s, const ray& r) {
      return r.contains(s.a) || r.contains(s.b) || has_unique_intersection(s, r);
    }
    friend bool has_unique_intersection(const segment& s1, const segment& s2) {
      if(!has_unique_intersection(s1.as_line(), s2.as_line()))
        return false;
      return opposite(s2.as_line(), s1.a, s1.b)
        && opposite(s1.as_line(), s2.a, s2.b);
    }
    friend bool has_intersection(const segment& s1, const segment& s2) {
      return s1.contains(s2.a) || s1.contains(s2.b) || has_unique_intersection(s1, s2);
    }
    friend Large dist(const segment& s, const point& p) {
      if(GEOMETRY_COMPARE0(Large, dot(p - s.a, s.b - s.a)) <= 0)
        return dist(s.a, p);
      if(GEOMETRY_COMPARE0(Large, dot(p - s.b, s.a - s.b)) <= 0)
        return dist(s.b, p);
      return dist(s.as_line(), p);
    }
    friend Large dist(const segment& s, const line& l) {
      if(has_intersection(s, l))
        return Large(0);
      return min(dist(l, s.a), dist(l, s.b));
    }
    friend Large dist(const segment& s, const ray& r) {
      if(has_intersection(s, r))
        return Large(0);
      return min({dist(r, s.a),
                  dist(r, s.b),
                  dist(s, r.a)});
    }
    friend Large dist(const segment& s1, const segment& s2) {
      if(has_intersection(s1, s2))
        return Large(0);
      return min({dist(s1, s2.a),
                  dist(s1, s2.b),
                  dist(s2, s1.a),
                  dist(s2, s1.b)});
    }

    friend bool operator==(const segment& l1, const segment& l2) {
      return tie(l1.a, l1.b) == tie(l2.a, l2.b);
    }
    friend bool operator!=(const segment& l1, const segment& l2) {
      return !(l1 == l2);
    }
    friend bool operator<(const segment& l1, const segment& l2) {
      return tie(l1.a, l1.b) < tie(l2.a, l2.b);
    }
  };

  template<typename T, typename Large = T>
  struct AngleComparator {
    typedef Point<T, Large> point;
    point pivot;
    AngleComparator(point p) : pivot(p) {}
    bool operator()(const point& a, const point& b) const {
      return ccw(pivot, a, b) > 0;
    }
    template<typename Iterator>
    static void sortByAngle(Iterator begin, Iterator end, const point& pivot) {
      AngleComparator<T, Large> cmp(pivot);
      begin = partition(begin, end, [&pivot](const point& p) { return p == pivot; });
      auto half = partition(begin, end, [&pivot](const point& p) { return p > pivot; });
      sort(begin, half, cmp);
      sort(half, end, cmp);
    }
  };
}  // namespace plane

  template<typename T, typename Large = T>
  struct CartesianPlane {
    typedef plane::Point<T, Large> point;
    typedef plane::Line<T, Large> line;
    typedef plane::Rectangle<T, Large> rectangle;
    typedef plane::Segment<T, Large> segment;
    typedef plane::Ray<T, Large> ray;
    typedef plane::AngleComparator<T, Large> angle_comparator;
  };

}  // namespace geo
}  // namespace lib

#endif
