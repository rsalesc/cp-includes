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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    dsu/DSU.cpp\"\n#include \"dsu/Compress.cpp\"\n\n#include \"Template.cpp\"\n\n\
    int32_t main() {\n  iopt;\n\n  int n, Q;\n  cin >> n >> Q;\n\n  using UF = lib::dsu::ByRank<lib::dsu::Compress>;\n\
    \n  UF uf(n);\n\n  for(int i = 0; i < Q; i++) {\n    int t, a, b;\n    cin >>\
    \ t >> a >> b;\n    if(t == 0) uf.merge(a, b);\n    else cout << (int)(uf[a] ==\
    \ uf[b]) << endl;\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: tests/yosupo/unionfind-with-compression.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/yosupo/unionfind-with-compression.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/unionfind-with-compression.test.cpp
- /verify/tests/yosupo/unionfind-with-compression.test.cpp.html
title: tests/yosupo/unionfind-with-compression.test.cpp
---
