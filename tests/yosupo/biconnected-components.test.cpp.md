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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"graphs/BlockCut.cpp\"\n#include \"Template.cpp\"\n\nusing namespace\
    \ lib;\n\nint32_t main() {\n  iopt;\n\n  int n, m; cin >> n >> m;\n\n  graph::Graph<int>\
    \ g(n);\n\n  for(int i = 0; i < m; i++) {\n    int a, b;\n    cin >> a >> b;\n\
    \    g.add_2edge(a, b);\n  }\n\n  auto bct = graph::make_block_cut(g);\n\n  cout\
    \ << bct.comps.size() << endl;\n  for(const auto& comp : bct.comps) {\n    cout\
    \ << comp.size() << \" \";\n    for(const auto v : comp) cout << v << \" \";\n\
    \    cout << endl;\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: tests/yosupo/biconnected-components.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/yosupo/biconnected-components.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/biconnected-components.test.cpp
- /verify/tests/yosupo/biconnected-components.test.cpp.html
title: tests/yosupo/biconnected-components.test.cpp
---
