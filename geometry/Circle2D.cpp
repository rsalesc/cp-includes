#ifndef _LIB_GEOMETRY_CIRCLE_2D
#define _LIB_GEOMETRY_CIRCLE_2D
#include "Line2D.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace geo {
namespace plane {
template <typename T, typename Large = T> struct Barycentric {
  typedef Point<T, Large> point;
  point r1, r2, r3;
  T a, b, c;

  Barycentric(const point &r1, const point &r2, const point &r3, T a = 1,
              T b = 1, T c = 1)
      : r1(r1), r2(r2), r3(r3), a(a), b(b), c(c) {}
  point as_point() const { return (r1 * a + r2 * b + r3 * c) / (a + b + c); }

  static Barycentric centroid(const point &r1, const point &r2,
                              const point &r3) {
    return Barycentric(r1, r2, r3);
  }
  static Barycentric circumcenter(const point &r1, const point &r2,
                                  const point &r3) {
    Large a = norm_sq(r2 - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);
    return Barycentric(r1, r2, r3, a * (b + c - a), b * (c + a - b),
                       c * (a + b - c));
  }
  static Barycentric incenter(const point &r1, const point &r2,
                              const point &r3) {
    return Barycentric(r1, r2, r3, norm(r2 - r3), norm(r1 - r3), norm(r1 - r2));
  }
  static Barycentric orthocenter(const point &r1, const point &r2,
                                 const point &r3) {
    Large a = norm_sq(r2 - r3), b = norm_sq(r3 - r1), c = norm_sq(r1 - r2);
    return Barycentric(r1, r2, r3, (a + b - c) * (c + a - b),
                       (b + c - a) * (a + b - c), (c + a - b) * (b + c - a));
  }
  static Barycentric excenter(const point &r1, const point &r2,
                              const point &r3) {
    return Barycentric(r1, r2, r3, -norm(r2 - r3), norm(r1 - r3),
                       norm(r1 - r2));
  }
};

template <typename T, typename Large = T> struct Circle {
  typedef Point<T, Large> point;
  typedef Line<T, Large> line;
  typedef Barycentric<Large> bary;
  typedef Segment<T, Large> segment;
  point center;
  T radius;

  Circle(point center, T radius) : center(center), radius(radius) {}
  Circle(const point &p1, const point &p2, const point &p3) {
    center = bary::circumcenter(p1, p2, p3).as_point();
    radius = dist(center, p1);
  }
  Circle(const point &p1, const point &p2) {
    center = (p1 + p2) / 2;
    radius = dist(center, p1);
  }
  static Circle incircle(const point &p1, const point &p2, const point &p3) {
    point center = bary::incenter(p1, p2, p3).as_point();
    return Circle(center, dist(line(p1, p2), center));
  }
  friend pair<segment, int> intersect_segment(const Circle &c, const line &l) {
    point H = project(c.center, l);
    Large h = norm(H - c.center);
    if (GEOMETRY_COMPARE(Large, c.radius, h) < 0)
      return {{}, 0};
    Large norma = sqrtl(c.radius + h) * sqrtl(c.radius - h);
    point v = normalized(l.direction(), norma);
    segment res = segment(H - v, H + v);
    return {res, res.is_degenerate() ? 1 : 2};
  }
  friend Large intersection_area(const Circle &a, const Circle &b) {
    Large d = norm(a.center - b.center);
    if (GEOMETRY_COMPARE(Large, a.radius + b.radius, d) <= 0)
      return 0.0;
    if (GEOMETRY_COMPARE(Large, d, abs(a.radius - b.radius)) <= 0) {
      T r = min(a.radius, b.radius);
      return r * r * trig::PI;
    }

    auto compute = [d](Large ra, Large rb) {
      Large sup = rb * rb + d * d - ra * ra;
      Large alpha = trig::acos(sup / (2.0 * rb * d));
      Large s = alpha * rb * rb;
      Large t = rb * rb * trig::sin(alpha) * trig::cos(alpha);
      return s - t;
    };
    return compute(a.radius, b.radius) + compute(b.radius, a.radius);
  }
  static Large intersection_signed_area(T r, const point &a, const point &b) {
    Circle C(point(), r);
    auto ps = intersect_segment(C, line(a, b));
    if (!ps.second)
      return r * r * signed_angle(a, b) / 2;
    auto s = ps.first;
    bool outa = !contains(C, a), outb = !contains(C, b);
    if (outa && outb) {
      segment ab(a, b);
      if (ab.contains(s.a) && ab.contains(s.b))
        return (r * r * (signed_angle(a, b) - signed_angle(s.a, s.b)) +
                cross(s.a, s.b)) /
               2;
      return r * r * signed_angle(a, b) / 2;
    } else if (outa)
      return (r * r * signed_angle(a, s.a) + cross(s.a, b)) / 2;
    else if (outb)
      return (r * r * signed_angle(s.b, b) + cross(a, s.b)) / 2;
    else
      return cross(a, b) / 2;
  }
  friend vector<point> tangents(const Circle &C, const point &p) {
    point v = C.center - p;
    Large d = norm(v);
    if (GEOMETRY_COMPARE(Large, d, C.radius) < 0)
      return {};
    Large alpha = trig::asin(C.radius / d);
    Large L = sqrtl(d + C.radius) * sqrtl(max((Large)0, d - C.radius));
    v = normalized(v, L);

    vector<point> res;
    res.push_back(p + rotate(v, alpha));
    if (GEOMETRY_COMPARE0(Large, L) != 0)
      res.push_back(p + rotate(v, -alpha));
    return res;
  }
  friend bool contains(const Circle &c, const point &p) {
    return GEOMETRY_COMPARE(Large, dist(p, c.center), c.radius) <= 0;
  }
  friend bool contains(const Circle &c, const segment &s) {
    return GEOMETRY_COMPARE(Large, dist(s.a, c.center), c.radius) <= 0 &&
           GEOMETRY_COMPARE(Large, dist(s.b, c.center), c.radius) <= 0;
  }
  template <typename L>
  friend bool partially_contains(const Circle &c, const L &l) {
    return GEOMETRY_COMPARE(Large, dist(l, c.center), c.radius) <= 0;
  }
  template <typename L>
  friend bool has_unique_intersection(const Circle &c, const L &l) {
    return GEOMETRY_COMPARE(Large, dist(l, c.center), c.radius) == 0;
  }
  template <typename L>
  friend bool has_intersection(const Circle &c, const L &l) {
    return GEOMETRY_COMPARE(Large, dist(l, c.center), c.radius) <= 0;
  }
  friend bool has_intersection(const Circle &c, const segment &s) {
    return GEOMETRY_COMPARE(Large, dist(s, c.center), c.radius) <= 0 &&
           (GEOMETRY_COMPARE(Large, dist(s.a, c.center), c.radius) >= 0 ||
            GEOMETRY_COMPARE(Large, dist(s.b, c.center), c.radius) >= 0);
  }
};
} // namespace plane

template <typename T, typename Large = T>
struct CirclePlane : public CartesianPlane<T, Large> {
  typedef plane::Circle<T, Large> circle;
};

} // namespace geo
} // namespace lib

#endif
