#ifndef _LIB_GEOMETRY_CALIPER
#define _LIB_GEOMETRY_CALIPER
#include <bits/stdc++.h>
#include "Line2D.cpp"
#include "Polygon2D.cpp"

namespace lib {
  using namespace std;
namespace geo {
namespace plane {
  template<typename T, typename Large = T,
           typename enable_if<!is_integral<T>::value>::type* = nullptr,
           typename enable_if<!is_integral<T>::value>::type* = nullptr>
 struct Caliper {
   typedef Point<T, Large> point;
   typedef Line<T, Large> line;
   point p;
   Large ang;
   Caliper(point a, Large alpha) : p(a) {
     ang = remainder(alpha, 2*trig::PI);
     while(ang < 0) ang += 2*trig::PI;
   }
   Large angle_to(const point& q) const {
     return remainder(arg(q - p) - ang, 2*trig::PI);
   }
   void rotate(double theta) {
     ang += theta;
     while(ang > 2*trig::PI) ang -= 2*trig::PI;
     while(ang < 0) ang += 2*trig::PI;
   }
   void move(const point& q) { p = q; }
   point versor() const { return point::polar(1.0, ang); }
   line as_line(Large scale = 1.0) const { return line(p, p + versor() * scale); }
   friend Large dist(const Caliper& a, const Caliper& b) {
     return dist(a.as_line(), b.p);
   }
 };

  template<typename T, typename Large = T>
  struct PolygonCalipers {
    constexpr static Large LIMIT = 4*acosl(-1);

    typedef Point<T, Large> point;
    typedef Caliper<T, Large> caliper;
    typedef ConvexPolygon<T, Large> polygon;
    typedef pair<int, Large> descriptor;
    
    polygon poly;
    vector<caliper> calipers;
    vector<int> indices;
    vector<int> walked;
    Large angle_walked;

    PolygonCalipers(const polygon& poly, 
                    const vector<descriptor>& descriptors) 
      : poly(poly),
        walked(descriptors.size()),
        angle_walked(0) {
      indices.reserve(descriptors.size());
      calipers.reserve(descriptors.size());
      for(size_t i = 0; i < descriptors.size(); i++) {
        calipers.emplace_back(poly[descriptors[i].first], descriptors[i].second);
        indices.emplace_back(descriptors[i].first);
      }
    }
    caliper operator[](int i) const { return calipers[i]; }
    int index(int i) const { return indices[i]; }
    bool has_next() const {
      return *min_element(walked.begin(), walked.end()) < poly.size()
        && angle_walked < LIMIT;
    }
    Large angle_to_next(int i) const {
      int u = indices[i];
      return calipers[i].angle_to(poly[u+1]);
    }
    void step_(int i) {
      int u = indices[i]++;
      indices[i] %= poly.size();
      calipers[i].move(poly[u+1]);
      walked[i]++;
    }

    void next() {
      int i = 0;
      Large best = angle_to_next(0);
      for(size_t j = 1; j < calipers.size(); j++) {
        Large cur = angle_to_next(j);
        if(cur < best) {
          best = cur;
          i = j;
        }
      }
      Large alpha = angle_to_next(i);
      for(auto& caliper : calipers)
        caliper.rotate(alpha);
      step_(i);
      angle_walked += alpha;
    }
  };
}  // namespace plane

}  // namespace geo
}  // namespace lib

#endif
