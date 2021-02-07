---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: LinearProgram.cpp
    title: LinearProgram.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Symbolic.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nstatic int g_VAR_PTR = 0;\n\nenum Operation { variable,\
    \ literal, sum };\n\ntemplate <typename T> struct Variable;\n\ntemplate <typename\
    \ T> struct BasicExp {\n  using node = shared_ptr<BasicExp<T>>;\n  using variable\
    \ = Variable<T>;\n\n  T coef = 1;\n  Operation op;\n  vector<node> children;\n\
    \  variable var;\n\n  BasicExp(Operation n_op, const vector<node> &n_children,\
    \ T n_coef = 1);\n  BasicExp(const T &v);\n\n  BasicExp(const Variable<T> &v);\n\
    \n  bool has_children() const {\n    return op != Operation::variable && op !=\
    \ Operation::literal;\n  }\n\n  Variable<T> get_variable() const { return var;\
    \ }\n};\n\ntemplate <typename T> using Expression = shared_ptr<BasicExp<T>>;\n\
    \ntemplate <typename T, typename... Args>\nExpression<T> make_exp(Args &&... args)\
    \ {\n  return make_shared<BasicExp<T>, Args...>(std::forward<Args>(args)...);\n\
    }\n\ntemplate <typename T> struct Variable {\n  int id;\n\n  static Variable<T>\
    \ get_variable() { return {g_VAR_PTR++}; }\n\n  static vector<Variable<T>> get_variables(int\
    \ n) {\n    vector<Variable<T>> vars(n);\n    for (int i = 0; i < n; i++)\n  \
    \    vars[i] = get_variable();\n    return vars;\n  }\n\n  static Expression<T>\
    \ get_exp_variable() {\n    return Variable<T>::get_variable().as_exp();\n  }\n\
    \n  static vector<Expression<T>> get_exp_variables(int n) {\n    vector<Expression<T>>\
    \ vs(n);\n    int i = 0;\n    for (const auto &v : Variable<T>::get_variables(n))\
    \ {\n      vs[i++] = v.as_exp();\n    }\n    return vs;\n  }\n\n  operator Expression<T>()\
    \ const { return make_exp<T>(*this); }\n\n  Expression<T> as_exp() const { return\
    \ Expression<T>(*this); }\n\n  bool operator<(const Variable<T> &rhs) const {\
    \ return id < rhs.id; }\n};\n\ntemplate <typename T>\nBasicExp<T>::BasicExp(Operation\
    \ n_op, const vector<node> &n_children, T n_coef)\n    : op(n_op), children(n_children),\
    \ coef(n_coef) {}\n\ntemplate <typename T> BasicExp<T>::BasicExp(const T &v) {\n\
    \  op = Operation::literal;\n  coef = v;\n}\n\ntemplate <typename T> BasicExp<T>::BasicExp(const\
    \ Variable<T> &v) {\n  op = Operation::variable;\n  var = v;\n}\n\ntemplate <typename\
    \ T> Expression<T> &operator*=(Expression<T> &e, const T &x) {\n  e->coef *= x;\n\
    \  return e;\n}\n\ntemplate <typename T>\nExpression<T> operator*(const Expression<T>\
    \ &e, const T &x) {\n  auto res = make_exp<T>(*e);\n  return res *= x;\n}\n\n\
    template <typename T>\nExpression<T> &operator+=(Expression<T> &e, const Expression<T>\
    \ &rhs) {\n  if (e->op == Operation::sum) {\n    e->children.push_back(rhs);\n\
    \  } else {\n    e = make_exp<T>(Operation::sum, vector<Expression<T>>{e, rhs});\n\
    \  }\n  return e;\n}\n\ntemplate <typename T>\nExpression<T> &operator+=(Expression<T>\
    \ &e, const Variable<T> &rhs) {\n  return e += make_exp<T>(rhs);\n}\n\ntemplate\
    \ <typename T> Expression<T> &operator+=(Expression<T> &e, const T &x) {\n  return\
    \ e += make_exp<T>(x);\n}\n\ntemplate <typename T>\nExpression<T> operator+(const\
    \ Expression<T> &e, const Expression<T> &rhs) {\n  auto res = e->op == Operation::sum\
    \ ? make_exp<T>(*e) : e;\n  return res += rhs;\n}\n\ntemplate <typename T>\nExpression<T>\
    \ operator+(const Expression<T> &e, const Variable<T> &rhs) {\n  return e + make_exp<T>(rhs);\n\
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
    \  return visitor->eval(e, values);\n}\n\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_SYMBOLIC\n#define _LIB_SYMBOLIC\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\nstatic int g_VAR_PTR = 0;\n\nenum Operation\
    \ { variable, literal, sum };\n\ntemplate <typename T> struct Variable;\n\ntemplate\
    \ <typename T> struct BasicExp {\n  using node = shared_ptr<BasicExp<T>>;\n  using\
    \ variable = Variable<T>;\n\n  T coef = 1;\n  Operation op;\n  vector<node> children;\n\
    \  variable var;\n\n  BasicExp(Operation n_op, const vector<node> &n_children,\
    \ T n_coef = 1);\n  BasicExp(const T &v);\n\n  BasicExp(const Variable<T> &v);\n\
    \n  bool has_children() const {\n    return op != Operation::variable && op !=\
    \ Operation::literal;\n  }\n\n  Variable<T> get_variable() const { return var;\
    \ }\n};\n\ntemplate <typename T> using Expression = shared_ptr<BasicExp<T>>;\n\
    \ntemplate <typename T, typename... Args>\nExpression<T> make_exp(Args &&... args)\
    \ {\n  return make_shared<BasicExp<T>, Args...>(std::forward<Args>(args)...);\n\
    }\n\ntemplate <typename T> struct Variable {\n  int id;\n\n  static Variable<T>\
    \ get_variable() { return {g_VAR_PTR++}; }\n\n  static vector<Variable<T>> get_variables(int\
    \ n) {\n    vector<Variable<T>> vars(n);\n    for (int i = 0; i < n; i++)\n  \
    \    vars[i] = get_variable();\n    return vars;\n  }\n\n  static Expression<T>\
    \ get_exp_variable() {\n    return Variable<T>::get_variable().as_exp();\n  }\n\
    \n  static vector<Expression<T>> get_exp_variables(int n) {\n    vector<Expression<T>>\
    \ vs(n);\n    int i = 0;\n    for (const auto &v : Variable<T>::get_variables(n))\
    \ {\n      vs[i++] = v.as_exp();\n    }\n    return vs;\n  }\n\n  operator Expression<T>()\
    \ const { return make_exp<T>(*this); }\n\n  Expression<T> as_exp() const { return\
    \ Expression<T>(*this); }\n\n  bool operator<(const Variable<T> &rhs) const {\
    \ return id < rhs.id; }\n};\n\ntemplate <typename T>\nBasicExp<T>::BasicExp(Operation\
    \ n_op, const vector<node> &n_children, T n_coef)\n    : op(n_op), children(n_children),\
    \ coef(n_coef) {}\n\ntemplate <typename T> BasicExp<T>::BasicExp(const T &v) {\n\
    \  op = Operation::literal;\n  coef = v;\n}\n\ntemplate <typename T> BasicExp<T>::BasicExp(const\
    \ Variable<T> &v) {\n  op = Operation::variable;\n  var = v;\n}\n\ntemplate <typename\
    \ T> Expression<T> &operator*=(Expression<T> &e, const T &x) {\n  e->coef *= x;\n\
    \  return e;\n}\n\ntemplate <typename T>\nExpression<T> operator*(const Expression<T>\
    \ &e, const T &x) {\n  auto res = make_exp<T>(*e);\n  return res *= x;\n}\n\n\
    template <typename T>\nExpression<T> &operator+=(Expression<T> &e, const Expression<T>\
    \ &rhs) {\n  if (e->op == Operation::sum) {\n    e->children.push_back(rhs);\n\
    \  } else {\n    e = make_exp<T>(Operation::sum, vector<Expression<T>>{e, rhs});\n\
    \  }\n  return e;\n}\n\ntemplate <typename T>\nExpression<T> &operator+=(Expression<T>\
    \ &e, const Variable<T> &rhs) {\n  return e += make_exp<T>(rhs);\n}\n\ntemplate\
    \ <typename T> Expression<T> &operator+=(Expression<T> &e, const T &x) {\n  return\
    \ e += make_exp<T>(x);\n}\n\ntemplate <typename T>\nExpression<T> operator+(const\
    \ Expression<T> &e, const Expression<T> &rhs) {\n  auto res = e->op == Operation::sum\
    \ ? make_exp<T>(*e) : e;\n  return res += rhs;\n}\n\ntemplate <typename T>\nExpression<T>\
    \ operator+(const Expression<T> &e, const Variable<T> &rhs) {\n  return e + make_exp<T>(rhs);\n\
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
    \  return visitor->eval(e, values);\n}\n\n} // namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Symbolic.cpp
  requiredBy:
  - LinearProgram.cpp
  timestamp: '2020-10-19 18:36:16-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Symbolic.cpp
layout: document
redirect_from:
- /library/Symbolic.cpp
- /library/Symbolic.cpp.html
title: Symbolic.cpp
---
