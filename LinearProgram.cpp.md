---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Simplex.cpp
    title: Simplex.cpp
  - icon: ':warning:'
    path: Symbolic.cpp
    title: Symbolic.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/unit/LinearProgram.cpp
    title: tests/unit/LinearProgram.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"LinearProgram.cpp\"\n\n\n#line 1 \"Simplex.cpp\"\n\n\n#include\
    \ <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\ntemplate <typename\
    \ DOUBLE> struct LPSolver {\n  typedef vector<DOUBLE> VD;\n  typedef vector<VD>\
    \ VVD;\n  typedef vector<int> VI;\n\n  constexpr static DOUBLE EPS = 1e-9;\n\n\
    \  int m, n;\n  VI B, N;\n  VVD D;\n\n  LPSolver(const VVD &A, const VD &b, const\
    \ VD &c)\n      : m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, VD(n + 2))\
    \ {\n    for (int i = 0; i < m; i++)\n      for (int j = 0; j < n; j++)\n    \
    \    D[i][j] = A[i][j];\n    for (int i = 0; i < m; i++) {\n      B[i] = n + i;\n\
    \      D[i][n] = -1;\n      D[i][n + 1] = b[i];\n    }\n    for (int j = 0; j\
    \ < n; j++) {\n      N[j] = j;\n      D[m][j] = -c[j];\n    }\n    N[n] = -1;\n\
    \    D[m + 1][n] = 1;\n  }\n\n  void Pivot(int r, int s) {\n    for (int i = 0;\
    \ i < m + 2; i++)\n      if (i != r)\n        for (int j = 0; j < n + 2; j++)\n\
    \          if (j != s)\n            D[i][j] -= D[r][j] * D[i][s] / D[r][s];\n\
    \    for (int j = 0; j < n + 2; j++)\n      if (j != s)\n        D[r][j] /= D[r][s];\n\
    \    for (int i = 0; i < m + 2; i++)\n      if (i != r)\n        D[i][s] /= -D[r][s];\n\
    \    D[r][s] = 1.0 / D[r][s];\n    swap(B[r], N[s]);\n  }\n\n  bool Simplex(int\
    \ phase) {\n    int x = phase == 1 ? m + 1 : m;\n    while (true) {\n      int\
    \ s = -1;\n      for (int j = 0; j <= n; j++) {\n        if (phase == 2 && N[j]\
    \ == -1)\n          continue;\n        if (s == -1 || D[x][j] < D[x][s] || D[x][j]\
    \ == D[x][s] && N[j] < N[s])\n          s = j;\n      }\n      if (D[x][s] > -EPS)\n\
    \        return true;\n      int r = -1;\n      for (int i = 0; i < m; i++) {\n\
    \        if (D[i][s] < EPS)\n          continue;\n        if (r == -1 || D[i][n\
    \ + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||\n            (D[i][n + 1] / D[i][s])\
    \ == (D[r][n + 1] / D[r][s]) && B[i] < B[r])\n          r = i;\n      }\n    \
    \  if (r == -1)\n        return false;\n      Pivot(r, s);\n    }\n  }\n\n  DOUBLE\
    \ Solve(VD &x) {\n    int r = 0;\n    for (int i = 1; i < m; i++)\n      if (D[i][n\
    \ + 1] < D[r][n + 1])\n        r = i;\n    if (D[r][n + 1] < -EPS) {\n      Pivot(r,\
    \ n);\n      if (!Simplex(1) || D[m + 1][n + 1] < -EPS)\n        return -numeric_limits<DOUBLE>::infinity();\n\
    \      for (int i = 0; i < m; i++)\n        if (B[i] == -1) {\n          int s\
    \ = -1;\n          for (int j = 0; j <= n; j++)\n            if (s == -1 || D[i][j]\
    \ < D[i][s] ||\n                D[i][j] == D[i][s] && N[j] < N[s])\n         \
    \     s = j;\n          Pivot(i, s);\n        }\n    }\n    if (!Simplex(2))\n\
    \      return numeric_limits<DOUBLE>::infinity();\n    x = VD(n);\n    for (int\
    \ i = 0; i < m; i++)\n      if (B[i] < n)\n        x[B[i]] = D[i][n + 1];\n  \
    \  return D[m][n + 1];\n  }\n};\n} // namespace lib\n\n\n#line 1 \"Symbolic.cpp\"\
    \n\n\n#line 4 \"Symbolic.cpp\"\n\nnamespace lib {\nusing namespace std;\nstatic\
    \ int g_VAR_PTR = 0;\n\nenum Operation { variable, literal, sum };\n\ntemplate\
    \ <typename T> struct Variable;\n\ntemplate <typename T> struct BasicExp {\n \
    \ using node = shared_ptr<BasicExp<T>>;\n  using variable = Variable<T>;\n\n \
    \ T coef = 1;\n  Operation op;\n  vector<node> children;\n  variable var;\n\n\
    \  BasicExp(Operation n_op, const vector<node> &n_children, T n_coef = 1);\n \
    \ BasicExp(const T &v);\n\n  BasicExp(const Variable<T> &v);\n\n  bool has_children()\
    \ const {\n    return op != Operation::variable && op != Operation::literal;\n\
    \  }\n\n  Variable<T> get_variable() const { return var; }\n};\n\ntemplate <typename\
    \ T> using Expression = shared_ptr<BasicExp<T>>;\n\ntemplate <typename T, typename...\
    \ Args>\nExpression<T> make_exp(Args &&... args) {\n  return make_shared<BasicExp<T>,\
    \ Args...>(std::forward<Args>(args)...);\n}\n\ntemplate <typename T> struct Variable\
    \ {\n  int id;\n\n  static Variable<T> get_variable() { return {g_VAR_PTR++};\
    \ }\n\n  static vector<Variable<T>> get_variables(int n) {\n    vector<Variable<T>>\
    \ vars(n);\n    for (int i = 0; i < n; i++)\n      vars[i] = get_variable();\n\
    \    return vars;\n  }\n\n  static Expression<T> get_exp_variable() {\n    return\
    \ Variable<T>::get_variable().as_exp();\n  }\n\n  static vector<Expression<T>>\
    \ get_exp_variables(int n) {\n    vector<Expression<T>> vs(n);\n    int i = 0;\n\
    \    for (const auto &v : Variable<T>::get_variables(n)) {\n      vs[i++] = v.as_exp();\n\
    \    }\n    return vs;\n  }\n\n  operator Expression<T>() const { return make_exp<T>(*this);\
    \ }\n\n  Expression<T> as_exp() const { return Expression<T>(*this); }\n\n  bool\
    \ operator<(const Variable<T> &rhs) const { return id < rhs.id; }\n};\n\ntemplate\
    \ <typename T>\nBasicExp<T>::BasicExp(Operation n_op, const vector<node> &n_children,\
    \ T n_coef)\n    : op(n_op), children(n_children), coef(n_coef) {}\n\ntemplate\
    \ <typename T> BasicExp<T>::BasicExp(const T &v) {\n  op = Operation::literal;\n\
    \  coef = v;\n}\n\ntemplate <typename T> BasicExp<T>::BasicExp(const Variable<T>\
    \ &v) {\n  op = Operation::variable;\n  var = v;\n}\n\ntemplate <typename T> Expression<T>\
    \ &operator*=(Expression<T> &e, const T &x) {\n  e->coef *= x;\n  return e;\n\
    }\n\ntemplate <typename T>\nExpression<T> operator*(const Expression<T> &e, const\
    \ T &x) {\n  auto res = make_exp<T>(*e);\n  return res *= x;\n}\n\ntemplate <typename\
    \ T>\nExpression<T> &operator+=(Expression<T> &e, const Expression<T> &rhs) {\n\
    \  if (e->op == Operation::sum) {\n    e->children.push_back(rhs);\n  } else {\n\
    \    e = make_exp<T>(Operation::sum, vector<Expression<T>>{e, rhs});\n  }\n  return\
    \ e;\n}\n\ntemplate <typename T>\nExpression<T> &operator+=(Expression<T> &e,\
    \ const Variable<T> &rhs) {\n  return e += make_exp<T>(rhs);\n}\n\ntemplate <typename\
    \ T> Expression<T> &operator+=(Expression<T> &e, const T &x) {\n  return e +=\
    \ make_exp<T>(x);\n}\n\ntemplate <typename T>\nExpression<T> operator+(const Expression<T>\
    \ &e, const Expression<T> &rhs) {\n  auto res = e->op == Operation::sum ? make_exp<T>(*e)\
    \ : e;\n  return res += rhs;\n}\n\ntemplate <typename T>\nExpression<T> operator+(const\
    \ Expression<T> &e, const Variable<T> &rhs) {\n  return e + make_exp<T>(rhs);\n\
    }\n\ntemplate <typename T>\nExpression<T> operator+(const Expression<T> &e, const\
    \ T &x) {\n  return e + make_exp<T>(x);\n}\n\ntemplate <typename T>\nExpression<T>\
    \ operator+(const Variable<T> &v, const Expression<T> &rhs) {\n  return make_exp<T>(v)\
    \ + rhs;\n}\n\ntemplate <typename T>\nExpression<T> operator+(const Variable<T>\
    \ &v, const Variable<T> &rhs) {\n  return make_exp<T>(v) + make_exp<T>(rhs);\n\
    }\n\ntemplate <typename T>\nExpression<T> operator+(const Variable<T> &v, const\
    \ T &x) {\n  return make_exp<T>(v) + make_exp<T>(x);\n}\n\ntemplate <typename\
    \ T>\nExpression<T> operator*(const Variable<T> &v, const T &x) {\n  return make_exp<T>(v)\
    \ * x;\n}\n\ntemplate <typename T> struct ExpressionVisitor {\n  void visit(const\
    \ Expression<T> &e) {\n    if (e->op == Operation::sum)\n      this->visit_sum(e);\n\
    \    else if (e->op == Operation::variable)\n      this->visit_variable(e);\n\
    \    else if (e->op == Operation::literal)\n      this->visit_literal(e);\n  }\n\
    \  virtual void visit_children(const Expression<T> &e) {\n    if (e->has_children())\
    \ {\n      for (const Expression<T> &child : e->children)\n        this->visit(child);\n\
    \    }\n  }\n\n  virtual void visit_sum(const Expression<T> &e) { this->visit_children(e);\
    \ }\n  virtual void visit_variable(const Expression<T> &e) {}\n  virtual void\
    \ visit_literal(const Expression<T> &e) {}\n};\n\ntemplate <typename T> struct\
    \ VariableVisitor : ExpressionVisitor<T> {\n  set<Variable<T>> seen;\n  virtual\
    \ void visit_variable(const Expression<T> &e) { seen.insert(e->var); }\n};\n\n\
    template <typename T, typename S = T>\nstruct StackVisitor : ExpressionVisitor<T>\
    \ {\n  vector<S> sta;\n  virtual void visit_children(const Expression<T> &e) override\
    \ {\n    sta.push_back(sta.empty() ? e->coef : sta.back() * e->coef);\n    ExpressionVisitor<T>::visit_children(e);\n\
    \    if (!sta.empty())\n      sta.pop_back();\n  }\n  S top() const { return sta.empty()\
    \ ? S(1) : sta.back(); }\n};\n\ntemplate <typename T> struct EvalVisitor : StackVisitor<T>\
    \ {\n  map<Variable<T>, T> values;\n  T result;\n  T eval(const Expression<T>\
    \ &e, const map<Variable<T>, T> &values) {\n    result = T();\n    this->values\
    \ = values;\n    this->visit(e);\n    return result;\n  }\n  virtual void visit_variable(const\
    \ Expression<T> &e) override {\n    result += this->top() * e->coef * values[e->var];\n\
    \  }\n  virtual void visit_literal(const Expression<T> &e) override {\n    result\
    \ += this->top() * e->coef;\n  }\n};\n\nenum ConstraintOperation {\n  equals,\n\
    \  different,\n  greater,\n  less,\n  greater_eq,\n  less_eq\n};\n\ntemplate <typename\
    \ T> struct Constraint {\n  Expression<T> lhs, rhs;\n  ConstraintOperation op;\n\
    \  Constraint(const Expression<T> &a, const Expression<T> &b,\n             ConstraintOperation\
    \ op)\n      : lhs(a), rhs(b), op(op) {}\n};\n\ntemplate <typename T>\nConstraint<T>\
    \ operator==(const Expression<T> &a, const Expression<T> &b) {\n  return Constraint<T>(a,\
    \ b, ConstraintOperation::equals);\n}\n\ntemplate <typename T>\nConstraint<T>\
    \ operator!=(const Expression<T> &a, const Expression<T> &b) {\n  return Constraint<T>(a,\
    \ b, ConstraintOperation::different);\n}\n\ntemplate <typename T>\nConstraint<T>\
    \ operator>=(const Expression<T> &a, const Expression<T> &b) {\n  return Constraint<T>(a,\
    \ b, ConstraintOperation::greater_eq);\n}\n\ntemplate <typename T>\nConstraint<T>\
    \ operator<=(const Expression<T> &a, const Expression<T> &b) {\n  return Constraint<T>(a,\
    \ b, ConstraintOperation::less_eq);\n}\n\ntemplate <typename T>\nConstraint<T>\
    \ operator>(const Expression<T> &a, const Expression<T> &b) {\n  return Constraint<T>(a,\
    \ b, ConstraintOperation::greater);\n}\n\ntemplate <typename T>\nConstraint<T>\
    \ operator<(const Expression<T> &a, const Expression<T> &b) {\n  return Constraint<T>(a,\
    \ b, ConstraintOperation::less);\n}\n\ntemplate <typename T>\nT eval(const Expression<T>\
    \ &e, const map<Variable<T>, T> &values) {\n  auto visitor = std::make_unique<EvalVisitor<T>>();\n\
    \  return visitor->eval(e, values);\n}\n\n} // namespace lib\n\n\n#line 6 \"LinearProgram.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\ntemplate <typename T = double> struct\
    \ LinearProgram {\n  struct ConstraintVisitor : StackVisitor<T> {\n    const vector<Variable<T>>\
    \ &vars;\n    const vector<Constraint<T>> &consts;\n\n    vector<vector<T>> A;\n\
    \    vector<T> b;\n    T mult;\n\n    ConstraintVisitor(const vector<Variable<T>>\
    \ &vars,\n                      const vector<Constraint<T>> &consts)\n       \
    \ : vars(vars), consts(consts), mult(1) {\n      A = vector<vector<T>>();\n  \
    \    b = vector<T>();\n    }\n\n    void populate() {\n      for (int i = 0; i\
    \ < consts.size(); i++) {\n        const auto &constraint = consts[i];\n     \
    \   if (constraint.op == ConstraintOperation::less_eq)\n          visit_constraint(constraint,\
    \ 1);\n        else if (constraint.op == ConstraintOperation::greater_eq)\n  \
    \        visit_constraint(constraint, -1);\n        else if (constraint.op ==\
    \ ConstraintOperation::equals)\n          visit_constraint(constraint, 1), visit_constraint(constraint,\
    \ -1);\n      }\n\n      // for(int i = 0; i < b.size(); i++) {\n      //    \
    \ for(int j = 0; j < vars.size(); j++) {\n      //         cout << A[i][j] <<\
    \ \" \";\n      //     }\n      //     cout << b[i] << endl;\n      // }\n   \
    \ }\n\n    void visit_constraint(const Constraint<T> &constraint, T constraint_mult)\
    \ {\n      A.emplace_back(vars.size());\n      b.emplace_back();\n      mult *=\
    \ constraint_mult;\n      this->visit(constraint.lhs);\n      mult = -mult;\n\
    \      this->visit(constraint.rhs);\n      mult = -mult;\n      mult *= constraint_mult;\n\
    \    }\n\n    int index(const Variable<T> &v) const {\n      return lower_bound(vars.begin(),\
    \ vars.end(), v) - vars.begin();\n    }\n\n    virtual void visit_variable(const\
    \ Expression<T> &e) override {\n      A.back()[index(e->var)] += this->top() *\
    \ e->coef * mult;\n    }\n    virtual void visit_literal(const Expression<T> &e)\
    \ override {\n      b.back() -= this->top() * e->coef * mult;\n    }\n  };\n\n\
    \  struct ObjectiveVisitor : StackVisitor<T> {\n    const vector<Variable<T>>\
    \ &vars;\n    const Expression<T> &obj;\n\n    vector<T> c;\n    T mult;\n\n \
    \   ObjectiveVisitor(const vector<Variable<T>> &vars, const Expression<T> &obj,\n\
    \                     T mult)\n        : vars(vars), obj(obj), mult(mult) {\n\
    \      c = vector<T>(vars.size());\n    }\n\n    void populate() {\n      this->visit(obj);\n\
    \      // cout << \"---\" << endl;\n      // for(int i = 0; i < vars.size(); i++)\n\
    \      //     cout << c[i] << \" \";\n      // cout << endl;\n    }\n\n    int\
    \ index(const Variable<T> &v) const {\n      return lower_bound(vars.begin(),\
    \ vars.end(), v) - vars.begin();\n    }\n\n    virtual void visit_variable(const\
    \ Expression<T> &e) override {\n      c[index(e->var)] += this->top() * e->coef\
    \ * mult;\n    }\n  };\n\n  vector<Constraint<T>> constraints;\n  void add_constraint(Constraint<T>\
    \ constraint) {\n    constraints.push_back(constraint);\n  }\n  set<Variable<T>>\
    \ get_variables(const Expression<T> &obj) const {\n    auto visitor = make_unique<VariableVisitor<T>>();\n\
    \    for (const auto &c : constraints) {\n      visitor->visit(c.lhs);\n     \
    \ visitor->visit(c.rhs);\n    }\n    visitor->visit(obj);\n    return visitor->seen;\n\
    \  }\n  map<Variable<T>, T> _solve(const Expression<T> &obj, T obj_mult = 1) {\n\
    \    const auto &variables = get_variables(obj);\n    vector<Variable<T>> vs(variables.begin(),\
    \ variables.end());\n    auto visitor = make_unique<ConstraintVisitor>(vs, constraints);\n\
    \    visitor->populate();\n    auto objVisitor = make_unique<ObjectiveVisitor>(vs,\
    \ obj, obj_mult);\n    objVisitor->populate();\n\n    LPSolver<T> solver(visitor->A,\
    \ visitor->b, objVisitor->c);\n    vector<T> ans;\n    solver.Solve(ans);\n  \
    \  if (ans.size() < vs.size())\n      return {};\n\n    map<Variable<T>, T> res;\n\
    \    for (int i = 0; i < vs.size(); i++)\n      res[vs[i]] = ans[i];\n    return\
    \ res;\n  }\n\n  map<Variable<T>, T> maximize(const Expression<T> &obj) { return\
    \ _solve(obj); }\n\n  map<Variable<T>, T> minimize(const Expression<T> &obj) {\n\
    \    return _solve(obj, -1);\n  }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_LINEAR_PROGRAM\n#define _LIB_LINEAR_PROGRAM\n#include \"Simplex.cpp\"\
    \n#include \"Symbolic.cpp\"\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing\
    \ namespace std;\ntemplate <typename T = double> struct LinearProgram {\n  struct\
    \ ConstraintVisitor : StackVisitor<T> {\n    const vector<Variable<T>> &vars;\n\
    \    const vector<Constraint<T>> &consts;\n\n    vector<vector<T>> A;\n    vector<T>\
    \ b;\n    T mult;\n\n    ConstraintVisitor(const vector<Variable<T>> &vars,\n\
    \                      const vector<Constraint<T>> &consts)\n        : vars(vars),\
    \ consts(consts), mult(1) {\n      A = vector<vector<T>>();\n      b = vector<T>();\n\
    \    }\n\n    void populate() {\n      for (int i = 0; i < consts.size(); i++)\
    \ {\n        const auto &constraint = consts[i];\n        if (constraint.op ==\
    \ ConstraintOperation::less_eq)\n          visit_constraint(constraint, 1);\n\
    \        else if (constraint.op == ConstraintOperation::greater_eq)\n        \
    \  visit_constraint(constraint, -1);\n        else if (constraint.op == ConstraintOperation::equals)\n\
    \          visit_constraint(constraint, 1), visit_constraint(constraint, -1);\n\
    \      }\n\n      // for(int i = 0; i < b.size(); i++) {\n      //     for(int\
    \ j = 0; j < vars.size(); j++) {\n      //         cout << A[i][j] << \" \";\n\
    \      //     }\n      //     cout << b[i] << endl;\n      // }\n    }\n\n   \
    \ void visit_constraint(const Constraint<T> &constraint, T constraint_mult) {\n\
    \      A.emplace_back(vars.size());\n      b.emplace_back();\n      mult *= constraint_mult;\n\
    \      this->visit(constraint.lhs);\n      mult = -mult;\n      this->visit(constraint.rhs);\n\
    \      mult = -mult;\n      mult *= constraint_mult;\n    }\n\n    int index(const\
    \ Variable<T> &v) const {\n      return lower_bound(vars.begin(), vars.end(),\
    \ v) - vars.begin();\n    }\n\n    virtual void visit_variable(const Expression<T>\
    \ &e) override {\n      A.back()[index(e->var)] += this->top() * e->coef * mult;\n\
    \    }\n    virtual void visit_literal(const Expression<T> &e) override {\n  \
    \    b.back() -= this->top() * e->coef * mult;\n    }\n  };\n\n  struct ObjectiveVisitor\
    \ : StackVisitor<T> {\n    const vector<Variable<T>> &vars;\n    const Expression<T>\
    \ &obj;\n\n    vector<T> c;\n    T mult;\n\n    ObjectiveVisitor(const vector<Variable<T>>\
    \ &vars, const Expression<T> &obj,\n                     T mult)\n        : vars(vars),\
    \ obj(obj), mult(mult) {\n      c = vector<T>(vars.size());\n    }\n\n    void\
    \ populate() {\n      this->visit(obj);\n      // cout << \"---\" << endl;\n \
    \     // for(int i = 0; i < vars.size(); i++)\n      //     cout << c[i] << \"\
    \ \";\n      // cout << endl;\n    }\n\n    int index(const Variable<T> &v) const\
    \ {\n      return lower_bound(vars.begin(), vars.end(), v) - vars.begin();\n \
    \   }\n\n    virtual void visit_variable(const Expression<T> &e) override {\n\
    \      c[index(e->var)] += this->top() * e->coef * mult;\n    }\n  };\n\n  vector<Constraint<T>>\
    \ constraints;\n  void add_constraint(Constraint<T> constraint) {\n    constraints.push_back(constraint);\n\
    \  }\n  set<Variable<T>> get_variables(const Expression<T> &obj) const {\n   \
    \ auto visitor = make_unique<VariableVisitor<T>>();\n    for (const auto &c :\
    \ constraints) {\n      visitor->visit(c.lhs);\n      visitor->visit(c.rhs);\n\
    \    }\n    visitor->visit(obj);\n    return visitor->seen;\n  }\n  map<Variable<T>,\
    \ T> _solve(const Expression<T> &obj, T obj_mult = 1) {\n    const auto &variables\
    \ = get_variables(obj);\n    vector<Variable<T>> vs(variables.begin(), variables.end());\n\
    \    auto visitor = make_unique<ConstraintVisitor>(vs, constraints);\n    visitor->populate();\n\
    \    auto objVisitor = make_unique<ObjectiveVisitor>(vs, obj, obj_mult);\n   \
    \ objVisitor->populate();\n\n    LPSolver<T> solver(visitor->A, visitor->b, objVisitor->c);\n\
    \    vector<T> ans;\n    solver.Solve(ans);\n    if (ans.size() < vs.size())\n\
    \      return {};\n\n    map<Variable<T>, T> res;\n    for (int i = 0; i < vs.size();\
    \ i++)\n      res[vs[i]] = ans[i];\n    return res;\n  }\n\n  map<Variable<T>,\
    \ T> maximize(const Expression<T> &obj) { return _solve(obj); }\n\n  map<Variable<T>,\
    \ T> minimize(const Expression<T> &obj) {\n    return _solve(obj, -1);\n  }\n\
    };\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - Simplex.cpp
  - Symbolic.cpp
  isVerificationFile: false
  path: LinearProgram.cpp
  requiredBy:
  - tests/unit/LinearProgram.cpp
  timestamp: '2020-10-19 18:36:16-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: LinearProgram.cpp
layout: document
redirect_from:
- /library/LinearProgram.cpp
- /library/LinearProgram.cpp.html
title: LinearProgram.cpp
---
