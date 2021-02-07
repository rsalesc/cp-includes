---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../geometry/2D.cpp:\
    \ line -1: no such header\n"
  code: "#include \"../../geometry/2D.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\nusing namespace lib::geo;\n\nGEOMETRY_EPSILON(double, 1e-9);\nusing Point\
    \ = plane::Point<double>;\n\nint main() {\n  lib::geo::GeometryEpsilon<double>\
    \ eps;\n  cout << eps(0, 1) << endl;\n  Point p;\n  versor(p);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tests/judge/geo.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/geo.cpp
layout: document
redirect_from:
- /library/tests/judge/geo.cpp
- /library/tests/judge/geo.cpp.html
title: tests/judge/geo.cpp
---
