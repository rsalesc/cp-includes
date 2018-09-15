#ifndef _LIB_GEOMETRY_POLY_2D
#define _LIB_GEOMETRY_POLY_2D
#include <bits/stdc++.h>
#include "Line2D.cpp"
#include "Circle2D.cpp"

namespace lib {
  using namespace std;
namespace geo {
namespace plane {

  template<typename T, typename Large = T>
  struct ConvexHullComparator {
    typedef Point<T, Large> point;
    point pivot;
    ConvexHullComparator(point p) : pivot(p) {}
    template<typename G>
    bool operator()(const pair<point, G>& a, const pair<point, G>& b) const {
      int k = ccw(pivot, a.first, b.first);
      if(k == 0) return norm_sq(a.first) < norm_sq(b.first);
      return k > 0;
    }
  };

  template<typename T, typename Large = T>
  struct Polygon {
    typedef Point<T, Large> point;
    typedef Polygon<T, Large> polygon;
    typedef Circle<T, Large> circle;
    vector<point> p;

    Polygon(const vector<point>& p) : p(p) {}
    template<typename G>
    Polygon(const vector<pair<point, G>>& g) : p(g.size()) {
      for(size_t i = 0; i < g.size(); i++) p[i] = g[i].first;
    }
    template<typename A, typename B>
    explicit operator Polygon<A, B>() const {
      vector<Point<A, B>> v(p.size());
      for(size_t i = 0; i < p.size(); i++) v[i] = Point<A, B>(p[i]);
      return Polygon<A, B>(v);
    }
    inline int index(int i) const {
      if(i >= size()) i %= size();
      else if(i < 0) {
        i %= size();
        if(i < 0) i += size();
      }
      return i;
    }
    inline int size() const { return p.size(); }
    inline point& operator[](int i) {
      return p[index(i)];
    }
    inline point operator[](int i) const {
      return p[index(i)];
    }
    void erase(int i) { p.erase(p.begin() + index(i)); }
    polygon& operator+=(const point& pt) {
      for(auto& q : p)
        q += pt;
      return *this;
    }
    polygon& operator-=(const point& pt) {
      for(auto& q : p)
        q -= pt;
      return *this;
    }
    polygon& operator*=(const Large k) {
      for(auto& q : p)
        q *= k;
      return *this;
    }
    polygon& operator/=(const Large k) {
      for(auto& q : p)
        q /= k;
      return *this;
    }
    polygon operator-() const {
      polygon res = *this;
      for(auto& q : res.p) q = -q;
      return res;
    }
    void reserve(int n) { p.reserve(n); }
    bool is_ccw() const {
      int n = size();
      int i = min_element(p.begin(), p.end()) - p.begin();
      return ccw(p[i], p[i+1], p[i-1]) >= 0;
    }
    bool is_degenerate() const {
      int n = size();
      if(n < 3) return true;
      for(int i = 0; i < n; i++) {
        if(GEOMETRY_COMPARE0(Large, cross(p[i+2] - p[i], p[i+1] - p[i])))
          return false;
      }
      return true;
    }
    inline operator vector<point>() const { return p; }
    
    friend Large double_area(const Polygon& p) {
      int n = p.size();
      Large res = 0;
      for(int i = 0; i < n; i++) {
        res += cross(p[i], p[i+1]);
      }
      return abs(res);
    }
    friend Large area(const Polygon& p) { return double_area(p)/2; }
    friend Large perimeter(const Polygon& p) {
      int n = p.size();
      Large res = 0;
      for(int i = 0; i < n; i++)
        res += dist(p[i], p[i+1]);
      return res;
    }

    int test(const point& p) const {
      const Polygon& poly = *this;
      int n = size();
      int wn = 0;
      for(int i = 0; i < n; i++) {
        if(p == poly[i]) return 0;
        int j = i+1;
        if(poly[i].y == p.y && poly[j].y == p.y) {
          if(min(poly[i].x, poly[j].x) <= p.x && p.x <= max(poly[i].x, poly[j].x))
            return 0;
        } else {
          bool below = poly[i].y < p.y;
          if(below != (poly[j].y < p.y)) {
            auto sig = ccw(poly[i], poly[j], p);
            if(sig == 0) return 0;
            if(below == (sig > 0)) wn += below ? 1 : -1;
          }
        }
      }
      return wn == 0 ? 1 : -1;
    }

    template<typename G>
    static vector<pair<point, G>> convex_hull(vector<pair<point, G>> p, 
                                              bool keep_border = false) {
      if(p.size() <= 1) return p;
      sort(p.begin(), p.end());
      vector<pair<point, G>> res;
      res.reserve(p.size() + 1);
      for(int step = 0; step < 2; step++) {
        auto start = res.size();
        for(auto& q : p) {
          while(res.size() >= start + 2) {
            int sig = ccw(res[res.size() - 2].first, res.back().first, q.first);
            if((sig == 0 && !keep_border) || sig < 0)
              res.pop_back();
            else break;
          }
          res.push_back(q);
        }
        res.pop_back();
        if(step == 0) reverse(p.begin(), p.end());
      }
      if(res.size() == 2 && res[0] == res[1]) res.pop_back();
      return res;
    }

    static polygon convex_hull(const vector<point>& p, bool keep_border = false) {
      vector<pair<point, int>> v(p.size());
      for(size_t i = 0; i < p.size(); i++) v[i] = {p[i], i};
      auto res = convex_hull(v, keep_border);
      return polygon(res);
    }

    friend vector<polygon> triangulation(polygon poly) {
      if(poly.size() < 3) return {};
      vector<polygon> res;
      int ptr = 0;
      int n;
      while((n = poly.size()) > 3) {
        for(int& i = ptr; ; i++) {
          if(ccw(poly[i-1], poly[i], poly[i+1]) > 0) {
            auto trig = polygon({poly[i-1], poly[i], poly[i+1]});
            bool good = true;
            for(int j = 0; j < n; j++) {
              good &= trig.test(poly[j]) >= 0;
            }
            if(!good) continue;
            poly.erase(i--);
            res.push_back(trig);
            break;
          }
        }
      }
      res.push_back(poly);
      return res;
    }

    friend Large intersection_area(const Polygon& p, const circle& C) {
      Large res = 0;
      int n = p.size();
      for(int i = 0; i < n; i++) {
        res += circle::
          intersection_signed_area(C.radius, p[i+1] - C.center, p[i] - C.center);
      }
      return abs(res);
    }
  };

  template<typename T, typename Large = T>
  struct ConvexPolygon : public Polygon<T, Large> {
    typedef Point<T, Large> point;
    typedef Segment<T, Large> segment;
    typedef Line<T, Large> line;
    typedef Circle<T, Large> circle;
    typedef AngleComparator<T, Large> angle_comparator;
    using Polygon<T, Large>::p;
    int top;
    ConvexPolygon(const vector<point>& p) : Polygon<T, Large>(p) {
      normalize();
    }
    template<typename G>
    ConvexPolygon(const vector<pair<point, G>>& p) : Polygon<T, Large>(p) {
      normalize();
    }
    void normalize() {
      auto bottom = min_element(p.begin(), p.end());
      rotate(p.begin(), bottom, p.end());
      top = max_element(p.begin(), p.end()) - p.begin();
    }
    ConvexPolygon& operator+=(const point& pt) {
      for(auto& q : p)
        q += pt;
      return *this;
    }
    ConvexPolygon& operator-=(const point& pt) {
      for(auto& q : p)
        q -= pt;
      return *this;
    }
    ConvexPolygon& operator*=(const Large k) {
      for(auto& q : p)
        q *= k;
      return *this;
    }
    ConvexPolygon& operator/=(const Large k) {
      for(auto& q : p)
        q /= k;
      return *this;
    }
    ConvexPolygon operator-() const {
      ConvexPolygon res = *this;
      for(auto& q : res.p) q = -q;
      return res;
    }

    int test(const point& q) const {
      if(q < p[0] || q > p[top]) return 1;
      auto sig = ccw(p[0], p[top], q);
      if(sig == 0) {
        if(q == p[0] || q == p[top]) return 0;
        return top == 1 || top + 1 == this->size() ? 0 : -1;
      } else if(sig < 0) {
        auto it = lower_bound(p.begin() + 1, p.begin() + top, q);
        return ccw(it[-1], q, it[0]);
      } else {
        auto it = upper_bound(p.rbegin(), p.rend() - top - 1, q);
        auto pit_deref = it == p.rbegin() ? p[0] : it[-1];
        return ccw(*it, q, pit_deref);
      }
    }
    template<typename Function>
    int extreme(Function direction) const {
      int n = this->size(), left = 0, leftSig;
      const ConvexPolygon& poly = *this;
      auto vertex_cmp = [&poly, direction](int i, int j) {
        return ccw(poly[j] - poly[i], direction(poly[j]));
      };
      auto is_extreme = [n, vertex_cmp](int i, int& iSig) {
        return (iSig = vertex_cmp(i+1, i)) >= 0 && vertex_cmp(i, i-1) < 0;
      };
      for(int right = is_extreme(0, leftSig) ? 1 : n; left + 1 < right;) {
        int mid = (left + right) / 2, midSig;
        if(is_extreme(mid, midSig)) return mid;
        if(leftSig != midSig ? leftSig < midSig : leftSig == vertex_cmp(left, mid))
          right = mid;
        else left = mid, leftSig = midSig;
      }
      return poly.index(left);
    }
    void stab_extremes(const line& l, int& left, int& right) const {
      point direction = l.direction();
      right = extreme([&direction](const point&) { return direction; });
      left = extreme([&direction](const point&) { return -direction; });
    }
    friend vector<point> intersect(const ConvexPolygon& poly, const line& l) {
      point direction = l.direction();

      int left, right;
      poly.stab_extremes(l, left, right);
      auto vertex_cmp = [&l, &direction](const point& q) {
        return ccw(q - l.a, direction);
      };
      int rightSig = vertex_cmp(poly[right]), leftSig = vertex_cmp(poly[left]);
      if(rightSig < 0 || leftSig > 0) return {};
      auto intersectChain = [&l, &poly, vertex_cmp](int first, int last, int firstSig) {
        int n = poly.size();
        while(poly.index(first + 1) != poly.index(last)) {
          int mid = (first + last + (first < last ? 0 : n)) / 2;
          mid = poly.index(mid);
          if(vertex_cmp(poly[mid]) == firstSig) first = mid;
          else last = mid;
        }
        return intersect(l, line(poly[first], poly[last]));
      };
      return {intersectChain(left, right, leftSig).first, 
              intersectChain(right, left, rightSig).first};
    }
    friend bool has_intersection(const ConvexPolygon& p, const line& l) {
      point direction = l.direction();
      int left, right;
      p.stab_extremes(l, left, right);
      auto vertex_cmp = [&l, &direction](const point& q) {
        return ccw(q -l.a, direction);
      };
      int rightSig = vertex_cmp(p[right]), leftSig = vertex_cmp(p[left]);
      if(rightSig < 0 || leftSig > 0) return false;
      return true;
    }
    friend Large dist(const ConvexPolygon& p, const line& l) {
      point direction = l.direction();
      int left, right;
      p.stab_extremes(l, left, right);
      auto vertex_cmp = [&l, &direction](const point& q) {
        return ccw(q - l.a, direction);
      };
      int rightSig = vertex_cmp(p[right]), leftSig = vertex_cmp(p[left]);
      if(rightSig < 0 || leftSig > 0) {
        return min(dist(l, p[right]), dist(l, p[left]));
      } else {
        return 0;
      }
    }
    template<typename Function>
    friend void antipodals(const ConvexPolygon& poly, Function f) {
      if(poly.size() <= 1) return;
      if(poly.size() == 2) return void(f(0, 1));
      auto area = [&poly](int i, int j, int k) {
        return abs(cross(poly[i], poly[j], poly[k]));
      };
      auto func = [f, &poly](int i, int j) { return f(poly.index(i), poly.index(j)); };

      int p = -1;
      int q = 0;
      while(area(p, p+1, q+1) > area(p, p+1, q))
        q++;
      int p0 = 0;
      int q0 = q;
      while(poly.index(q) != p0) {
        p++;
        func(p, q);
        while(area(p, p+1, q+1) > area(p, p+1, q)) {
          q++;
          if(poly.index(p) != poly.index(q0) || poly.index(q) != p0)
            func(p, q);
          else
            return;
        }
        if(area(p, p+1, q+1) == area(p, p+1, q)) {
          if(poly.index(p) != poly.index(q0) || poly.index(q) != p0)
            func(p, q+1);
          else func(p+1, q);
        }
      }
    }
    friend ConvexPolygon minkowski_sum(const vector<ConvexPolygon>& v) {
      vector<point> vectors;
      point origin;
      for(auto& poly : v) {
        origin += poly[0];
        for(int i = 0; i < poly.size(); i++)
          vectors.push_back(poly[i+1] - poly[i]);
      }
      angle_comparator::sortByAngle(vectors.begin(), vectors.end(), point());
      auto last = point();
      if(!vectors.empty()) {
        last = vectors.back();
        vectors.pop_back();
      }
      vector<point> res;
      res.push_back(origin);
      for(auto& v : vectors) {
        res.push_back(res.back() + v);
        int n = res.size();
        if(n >= 3 && collinear(res[n-3], res[n-2], res[n-1]))
          res.erase(res.begin() + n - 2);
      }
      int n = res.size();
      if(n >= 3 && collinear(res[n-2], res[n-1], res[0]))
        res.pop_back();
      if(res.size() >= 3 && collinear(res.back(), res[0], res[1]))
        res.erase(res.begin());
      return ConvexPolygon(res);
    }
    friend ConvexPolygon minkowski_sum(const ConvexPolygon& a, const ConvexPolygon& b) {
      vector<ConvexPolygon> v;
      v.push_back(a);
      v.push_back(b);
      return minkowski_sum(v);
    }
    friend ConvexPolygon intersect(const ConvexPolygon& a, const ConvexPolygon& b) {
      vector<point> candidates;
      auto consider = [&candidates](const ConvexPolygon& a, const ConvexPolygon& b) {
        for(int i = 0; i < a.size(); i++) {
          if(b.test(a[i]) <= 0)
            candidates.push_back(a[i]);
          segment s(a[i], a[i+1]);
          vector<point> ps = intersect(b, s.as_line());
          for(auto p : ps) {
            if(s.contains(p))
              candidates.push_back(p);
          }
        }
      };
      consider(a, b);
      consider(b, a);
      auto res = ConvexPolygon(ConvexPolygon::convex_hull(candidates));
      return res;
    }
    friend Large intersection_area_or_dist(const ConvexPolygon& a,
        const ConvexPolygon& b) {
      ConvexPolygon inter = intersect(a, b);
      if(inter.size() > 0) return max(area(inter), Large(0));
      ConvexPolygon sum = minkowski_sum(a, -b);
      Large res = numeric_limits<Large>::max();
      for(int i = 0; i < sum.size(); i++) {
        res = min(res, dist(segment(sum[i], sum[i+1]), point()));
      }
      return -res;
    }
  };
}  // namespace plane

  template<typename T, typename Large = T>
  struct PolygonPlane : public CirclePlane<T, Large> {
    typedef plane::Polygon<T, Large> polygon;
    typedef plane::ConvexPolygon<T, Large> convex_polygon;
  };

}  // namespace geo
}  // namespace lib

#endif
