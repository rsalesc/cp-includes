#ifndef _LIB_GEOMETRY_POLY_2D
#define _LIB_GEOMETRY_POLY_2D
#include <bits/stdc++.h>
#include "Line2D.cpp"

namespace lib {
  using namespace std;
namespace geo {
namespace plane {
  template<typename T, typename Large = T>
  struct Barycentric {
    typedef Point<T, Large> point;
    point r1, r2, r3;
    T a, b, c;

    Barycentric(const point& r1, const point& r2, const point& r3, 
        T a = 1, T b = 1, T c = 1)
      : r1(r1), r2(r2), r3(r3), a(a), b(b), c(c) {}
    point as_point() const { return (r1 * a + r2 * b + r3 * c) / (a + b + c); }

    static Barycentric centroid(const point& r1, const point& r2, const point& r3) {
      return Barycentric(r1, r2, r3);
    }
    static Barycentric circumcenter(const point& r1, const point& r2, const point& r3) {
      Large a = norm_sq(r2 - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);
      return Barycentric(r1, r2, r3, a*(b+c-a), b*(c+a-b), c*(a+b-c));
    }
    static Barycentric incenter(const point& r1, const point& r2, const point& r3) {
      return Barycentric(r1, r2, r3, norm(r2 - r3), norm(r1 - r3), norm(r1 - r2));
    }
    static Barycentric orthocenter(const point& r1, const point& r2, const point& r3) {
      Large a = norm_sq(r2 - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);
      return Barycentric(r1, r2, r3, (a+b-c)*(c+a-b), (b+c-a)*(a+b-c), (c+a-b)*(b+c-a));
    }
    static Barycentric excenter(const point& r1, const point& r2, const point& r3) {
      return Barycentric(r1, r2, r3, -norm(r2 - r3), norm(r1 - r3), norm(r1 - r2));
    }
  };

  template<typename T, typename Large = T>
  struct Circle {
    typedef Point<T, Large> point;
    typedef Line<T, Large> line;
    typedef Barycentric<Large> bary;
    point center;
    T radius;

    Circle(point center, T radius) : center(center), radius(radius) {}
    Circle(const point& p1, const point& p2, const point& p3) {
      center = bary::circumcenter(p1, p2, p3).as_point();
      radius = dist(center, p1);
    }
    Circle(const point& p1, const point& p2) {
      center = (p1 + p2) / 2;
      radius = dist(center, p1);
    }
    static Circle incircle(const point& p1, const point& p2, const point& p3) {
      point center = bary::incenter(p1, p2, p3).as_point();
      return Circle(center, dist(line(p1, p2), center));
    }
    friend vector<point> tangents(const Circle& C, const point& p) {
      point v = C.center - p;
      Large d = norm(v);
      if(GEOMETRY_COMPARE(Large, d, C.radius) < 0)
        return {};
      Large alpha = trig::asin(C.radius / d);
      Large L = sqrtl(max((Large)0, d*d - C.radius*C.radius));
      v = normalized(v, L);

      vector<point> res;
      res.push_back(p + rotate(v, alpha));
      if(GEOMETRY_COMPARE0(Large, L) != 0)
        res.push_back(p + rotate(v, -alpha));
      return res;
    }
    template<typename L>
    friend bool has_unique_intersection(const Circle& c, const L& l) {
      return GEOMETRY_COMPARE(Large, dist(l, c.center), c.radius) == 0;
    }
    template<typename L>
    friend bool has_intersection(const Circle& c, const L& l) {
      return GEOMETRY_COMPARE(Large, dist(l, c.center), c.radius) <= 0;
    }
  };
}  // namespace plane

  template<typename T, typename Large = T>
  struct CirclePlane : public CartesianPlane<T, Large> {
    typedef plane::Circle<T, Large> circle;
  };

}  // namespace geo
}  // namespace lib

#endif
