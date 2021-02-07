---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: HashMap.cpp
    title: HashMap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"HashMap.cpp\"\n\n\n#include <bits/stdc++.h>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nnamespace lib {\nusing namespace __gnu_pbds;\nusing namespace std;\n\n/* 1.\
    \ Maybe remove lazy delete and transfer delete work all to the erase\n *function\
    \ PRO: about 400ms faster for N = 5kk in lookup functions (erases will\n *be rare\
    \ in CP) CONS: it will increase (almost double) memory usage per node to\n *keep\
    \ offsets and stuff\n **/\n\ntemplate <typename Key, typename Value, typename\
    \ Hash = std::hash<Key>>\nstruct GoldenMap {\n  enum class State { FREE, ERASED,\
    \ USED };\n\n  enum class Action { NONE, CREATED, REUSED };\n\n  struct Node {\n\
    \    Key key;\n    Value value;\n    State state = State::FREE;\n  };\n\n  const\
    \ static int shift_amount = 5;\n\n  Node *no;\n  size_t size, cap, occ;\n  Hash\
    \ h;\n\n  GoldenMap(size_t capacity) : cap(capacity), size(0) {\n    assert(capacity\
    \ > 0 && ((capacity) & (capacity - 1)) == 0);\n    no = new Node[cap]();\n  }\n\
    \n  GoldenMap() : GoldenMap(2) {}\n  ~GoldenMap() { delete[] no; }\n\n  size_t\
    \ index(const Key &key, size_t sz_minus_one) const {\n    size_t hash = h(key);\n\
    \    hash ^= hash >> shift_amount;\n    return ((11400714819323198485llu * hash)\
    \ >> shift_amount) & sz_minus_one;\n  }\n\n  size_t count(const Key &key) const\
    \ {\n    size_t pos = index(key, cap - 1);\n    size_t last = cap;\n\n    for\
    \ (size_t it = 0; it < cap; it++) {\n      if (no[pos].state == State::FREE)\n\
    \        return false;\n      if (no[pos].state == State::USED && no[pos].key\
    \ == key) {\n        if (last != cap)\n          swap(no[last], no[pos]);\n  \
    \      return true;\n      }\n      if (no[pos].state == State::ERASED && last\
    \ == cap)\n        last = pos;\n\n      pos = step_forward(pos, it);\n      if\
    \ (pos >= cap)\n        pos %= cap;\n    }\n\n    return false;\n  }\n\n  Value\
    \ &operator[](const Key &key) {\n    if ((occ << 1) > cap)\n      rehash(cap <<\
    \ 1);\n\n    size_t pos;\n    Action has = add(key, pos, no, cap);\n    if (has\
    \ != Action::NONE) {\n      size++;\n      if (has == Action::CREATED)\n     \
    \   occ++;\n    }\n\n    return no[pos].value;\n  }\n\n  void clear() {\n    occ\
    \ = size = 0;\n    delete[] no;\n    no = new Node[cap = 4]();\n  }\n\n  void\
    \ apply(const function<void(const Key &, Value &)> &func) {\n    for (size_t i\
    \ = 0; i < cap; i++) {\n      if (no[i].state == State::USED)\n        func(no[i].key,\
    \ no[i].value);\n    }\n  }\n\n  void rehash(int n_cap) {\n    size_t n_occ =\
    \ 0;\n    Node *n_no = new Node[n_cap]();\n\n    for (size_t i = 0; i < cap; i++)\
    \ {\n      if (no[i].state == State::USED) {\n        size_t pos;\n        add(no[i].key,\
    \ pos, n_no, n_cap);\n        n_no[pos].value = no[i].value;\n        n_occ++;\n\
    \      }\n    }\n\n    delete[] no;\n    no = n_no;\n    cap = n_cap;\n    occ\
    \ = n_occ;\n  }\n\n  bool erase(const Key &key) {\n    size_t pos = index(key,\
    \ cap - 1);\n    ;\n    for (size_t it = 0; it < cap; it++) {\n      if (no[pos].state\
    \ == State::FREE)\n        return false;\n      if (no[pos].state == State::USED\
    \ && no[pos].key == key) {\n        no[pos].state = State::ERASED;\n        size--;\n\
    \        return true;\n      }\n\n      pos = step_forward(pos, it);\n      if\
    \ (pos >= cap)\n        pos %= cap;\n    }\n\n    return false;\n  }\n\nprivate:\n\
    \  inline int step_forward(int x, int i) const { return x + 1; }\n\n  Action add(const\
    \ Key &key, size_t &pos, Node *no, size_t cap) {\n    pos = index(key, cap - 1);\n\
    \    size_t last = cap;\n\n    for (size_t it = 0; it < cap; it++) {\n      if\
    \ (no[pos].state == State::FREE) {\n        if (last != cap)\n          pos =\
    \ last;\n        no[pos].key = key;\n        no[pos].state = State::USED;\n  \
    \      return pos == last ? Action::REUSED : Action::CREATED;\n      }\n\n   \
    \   if (no[pos].state == State::ERASED && last == cap)\n        last = pos;\n\
    \      else if (no[pos].key == key) {\n        if (last != cap) {\n          swap(no[pos],\
    \ no[last]);\n          pos = last;\n        }\n        return Action::NONE;\n\
    \      }\n\n      pos = step_forward(pos, it);\n      if (pos >= cap)\n      \
    \  pos %= cap;\n    }\n\n    throw std::logic_error(\"shouldnt get here in add()\"\
    );\n  }\n};\n\ntemplate <typename T, typename Hash = hash<T>, typename N = T>\n\
    using GpHashMap = gp_hash_table<\n    T, N, Hash, equal_to<T>, direct_mask_range_hashing<T>,\
    \ linear_probe_fn<>,\n    hash_standard_resize_policy<hash_exponential_size_policy<>,\n\
    \                                hash_load_check_resize_trigger<true>, true>>;\n\
    \ntemplate <typename T, typename Hash = hash<T>>\nusing GpHashSet = GpHashMap<T,\
    \ Hash, null_type>;\n} // namespace lib\n\n\n#line 3 \"tests/judge/table.cpp\"\
    \n\nusing namespace std;\n\ntypedef long long ll;\nconst ll INF = 1e15 + 21;\n\
    const ll MAXN = 1e5 + 5;\ntypedef pair<ll, ll> pii;\ntypedef lib::GoldenMap<ll,\
    \ ll> ht;\n\nll N, Q;\nll V[MAXN];\nll C[MAXN];\nll dp[MAXN];\nint main() {\n\
    \  ios::sync_with_stdio(0);\n  cin.tie(0);\n  cin >> N >> Q;\n  for (ll i = 0;\
    \ i < N; i++) {\n    cin >> V[i];\n  }\n  for (ll i = 0; i < N; i++) {\n    cin\
    \ >> C[i];\n  }\n  ht curMax;\n  for (int i = 0; i < N; i++) {\n    curMax[C[i]]\
    \ = -INF;\n  }\n  for (ll i = 0; i < Q; i++) {\n    for (size_t i = 0; i < curMax.cap;\
    \ i++) {\n      if (curMax.no[i].state == ht::State::USED) {\n        curMax.no[i].value\
    \ = -INF;\n      }\n    }\n    ll a, b;\n    cin >> a >> b;\n    fill(dp, dp +\
    \ N, -1);\n    pii mx1 = {0, 1e5 + 5};\n    pii mx2 = {0, 1e5 + 4};\n    for (ll\
    \ j = 0; j < N; j++) {\n      if (mx1.second == C[j]) {\n        dp[j] = mx2.first\
    \ + b * V[j];\n      } else {\n        dp[j] = mx1.first + b * V[j];\n      }\n\
    \      dp[j] = max(dp[j], curMax[C[j]] + a * V[j]);\n      if (dp[j] > mx1.first)\
    \ {\n        if (C[j] == mx1.second) {\n          mx1 = {dp[j], C[j]};\n     \
    \   } else {\n          mx2 = {mx1.first, mx1.second};\n          mx1 = {dp[j],\
    \ C[j]};\n        }\n      } else if (dp[j] > mx2.first) {\n        if (C[j] ==\
    \ mx1.second) {\n          continue;\n        } else {\n          mx2 = {dp[j],\
    \ C[j]};\n        }\n      }\n      curMax[C[j]] = max(curMax[C[j]], dp[j]);\n\
    \    }\n    cout << mx1.first << endl;\n  }\n}\n"
  code: "#include \"../../HashMap.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\ntypedef long long ll;\nconst ll INF = 1e15 + 21;\nconst ll MAXN = 1e5\
    \ + 5;\ntypedef pair<ll, ll> pii;\ntypedef lib::GoldenMap<ll, ll> ht;\n\nll N,\
    \ Q;\nll V[MAXN];\nll C[MAXN];\nll dp[MAXN];\nint main() {\n  ios::sync_with_stdio(0);\n\
    \  cin.tie(0);\n  cin >> N >> Q;\n  for (ll i = 0; i < N; i++) {\n    cin >> V[i];\n\
    \  }\n  for (ll i = 0; i < N; i++) {\n    cin >> C[i];\n  }\n  ht curMax;\n  for\
    \ (int i = 0; i < N; i++) {\n    curMax[C[i]] = -INF;\n  }\n  for (ll i = 0; i\
    \ < Q; i++) {\n    for (size_t i = 0; i < curMax.cap; i++) {\n      if (curMax.no[i].state\
    \ == ht::State::USED) {\n        curMax.no[i].value = -INF;\n      }\n    }\n\
    \    ll a, b;\n    cin >> a >> b;\n    fill(dp, dp + N, -1);\n    pii mx1 = {0,\
    \ 1e5 + 5};\n    pii mx2 = {0, 1e5 + 4};\n    for (ll j = 0; j < N; j++) {\n \
    \     if (mx1.second == C[j]) {\n        dp[j] = mx2.first + b * V[j];\n     \
    \ } else {\n        dp[j] = mx1.first + b * V[j];\n      }\n      dp[j] = max(dp[j],\
    \ curMax[C[j]] + a * V[j]);\n      if (dp[j] > mx1.first) {\n        if (C[j]\
    \ == mx1.second) {\n          mx1 = {dp[j], C[j]};\n        } else {\n       \
    \   mx2 = {mx1.first, mx1.second};\n          mx1 = {dp[j], C[j]};\n        }\n\
    \      } else if (dp[j] > mx2.first) {\n        if (C[j] == mx1.second) {\n  \
    \        continue;\n        } else {\n          mx2 = {dp[j], C[j]};\n       \
    \ }\n      }\n      curMax[C[j]] = max(curMax[C[j]], dp[j]);\n    }\n    cout\
    \ << mx1.first << endl;\n  }\n}\n"
  dependsOn:
  - HashMap.cpp
  isVerificationFile: false
  path: tests/judge/table.cpp
  requiredBy: []
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/table.cpp
layout: document
redirect_from:
- /library/tests/judge/table.cpp
- /library/tests/judge/table.cpp.html
title: tests/judge/table.cpp
---
