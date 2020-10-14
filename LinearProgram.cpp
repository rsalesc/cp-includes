#ifndef _LIB_LINEAR_PROGRAM
#define _LIB_LINEAR_PROGRAM
#include <bits/stdc++.h>
#include "Symbolic.cpp"
#include "Simplex.cpp"

namespace lib {
using namespace std;
    template<typename T = double>
    struct LinearProgram {
        struct ConstraintVisitor : StackVisitor<T> {
            const vector<Variable<T>>& vars;
            const vector<Constraint<T>>& consts;

            vector<vector<T>> A;
            vector<T> b;
            T mult;

            ConstraintVisitor(const vector<Variable<T>>& vars, const vector<Constraint<T>>& consts)
                : vars(vars), consts(consts), mult(1) {
                A = vector<vector<T>>();
                b = vector<T>();
            }

            void populate() {
                for(int i = 0; i < consts.size(); i++) {
                    const auto& constraint = consts[i];
                    if(constraint.op == ConstraintOperation::less_eq)
                        visit_constraint(constraint, 1);
                    else if(constraint.op == ConstraintOperation::greater_eq)
                        visit_constraint(constraint, -1);
                    else if(constraint.op == ConstraintOperation::equals)
                        visit_constraint(constraint, 1), visit_constraint(constraint, -1);
                }

                // for(int i = 0; i < b.size(); i++) {
                //     for(int j = 0; j < vars.size(); j++) {
                //         cout << A[i][j] << " ";
                //     }
                //     cout << b[i] << endl;
                // }
            }

            void visit_constraint(const Constraint<T>& constraint, T constraint_mult) {
                A.emplace_back(vars.size());
                b.emplace_back();
                mult *= constraint_mult;
                this->visit(constraint.lhs);
                mult = -mult;
                this->visit(constraint.rhs);
                mult = -mult;
                mult *= constraint_mult;
            }

            int index(const Variable<T>& v) const {
                return lower_bound(vars.begin(), vars.end(), v) - vars.begin();
            }

            virtual void visit_variable(const Expression<T>& e) override {
                A.back()[index(e->var)] += this->top() * e->coef * mult;
            }
            virtual void visit_literal(const Expression<T>& e) override {
                b.back() -= this->top() * e->coef * mult;
            }
        };

        struct ObjectiveVisitor : StackVisitor<T> {
            const vector<Variable<T>>& vars;
            const Expression<T>& obj;

            vector<T> c;
            T mult;

            ObjectiveVisitor(const vector<Variable<T>>& vars, const Expression<T>& obj, T mult)
                : vars(vars), obj(obj), mult(mult) {
                c = vector<T>(vars.size());
            }

            void populate() {
                this->visit(obj);
                // cout << "---" << endl;
                // for(int i = 0; i < vars.size(); i++)
                //     cout << c[i] << " ";
                // cout << endl;
            }

            int index(const Variable<T>& v) const {
                return lower_bound(vars.begin(), vars.end(), v) - vars.begin();
            }

            virtual void visit_variable(const Expression<T>& e) override {
                c[index(e->var)] += this->top() * e->coef * mult;
            }
        };

        vector<Constraint<T>> constraints;
        void add_constraint(Constraint<T> constraint) {
            constraints.push_back(constraint);
        }
        set<Variable<T>> get_variables(const Expression<T>& obj) const {
            auto visitor = make_unique<VariableVisitor<T>>();
            for(const auto& c : constraints) {
                visitor->visit(c.lhs);
                visitor->visit(c.rhs);
            }
            visitor->visit(obj);
            return visitor->seen;
        }
        map<Variable<T>, T> _solve(const Expression<T>& obj, T obj_mult = 1) {
            const auto& variables = get_variables(obj);
            vector<Variable<T>> vs(variables.begin(), variables.end());
            auto visitor = make_unique<ConstraintVisitor>(vs, constraints);
            visitor->populate();
            auto objVisitor = make_unique<ObjectiveVisitor>(vs, obj, obj_mult);
            objVisitor->populate();

            LPSolver<T> solver(visitor->A, visitor->b, objVisitor->c);
            vector<T> ans;
            solver.Solve(ans);
            if(ans.size() < vs.size()) return {};

            map<Variable<T>, T> res;
            for(int i = 0; i < vs.size(); i++)
                res[vs[i]] = ans[i];
            return res;
        }

        map<Variable<T>, T> maximize(const Expression<T>& obj) {
            return _solve(obj);
        }

        map<Variable<T>, T> minimize(const Expression<T>& obj) {
            return _solve(obj, -1);
        }
    };
}  // namespace lib

#endif
