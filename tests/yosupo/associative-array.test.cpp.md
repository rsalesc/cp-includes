---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Template.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"Template.cpp\"\n#include \"FastMap.cpp\"\n\nint32_t main() {\n  iopt;\n\n\
    \  lib::FastMap<int, int> st;\n\n  int n; cin >> n;\n\n  for(int i = 0; i < n;\
    \ i++) {\n    int t, k; cin >> t >> k;\n    if (t == 0) {\n      int v;\n    \
    \  cin >> v;\n      st[k] = v;\n    } else {\n      cout << st[k] << endl;\n \
    \   }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/yosupo/associative-array.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/yosupo/associative-array.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/associative-array.test.cpp
- /verify/tests/yosupo/associative-array.test.cpp.html
title: tests/yosupo/associative-array.test.cpp
---
