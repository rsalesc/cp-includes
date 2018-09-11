#include <bits/stdc++.h>
#include "../../geometry/2D.cpp"

using namespace std;
using namespace lib::geo;

GEOMETRY_EPSILON(double, 1e-9);
using Point = plane::Point<double>;

int main() {
  lib::geo::GeometryEpsilon<double> eps;
  cout << eps(0, 1) << endl;
  Point p;
  versor(p);
}
