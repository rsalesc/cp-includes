#ifndef _LIB_SYMBOLIC
#define _LIB_SYMBOLIC
#include <bits/stdc++.h>

namespace lib {
using namespace std;
    int g_VAR_PTR = 0;

    enum Operation { variable, literal, sum };

    template<typename T>
    struct Variable;

    template<typename T>
    struct BasicExp {
        using node = shared_ptr<BasicExp<T>>;
        using variable = Variable<T>;

        T coef = 1;
        Operation op;
        vector<node> children;
        variable var;

        BasicExp(Operation n_op, const vector<node>& n_children, T n_coef = 1);
        BasicExp(const T& v);

        BasicExp(const Variable<T>& v);

        bool has_children() const {
            return op != Operation::variable && op != Operation::literal;
        }

        Variable<T> get_variable() const { return var; }
    };

    template<typename T>
    using Expression = shared_ptr<BasicExp<T>>;

    template<typename T, typename... Args>
    Expression<T> make_exp(Args&&... args) {
        return make_shared<BasicExp<T>, Args...>(std::forward<Args>(args)...);
    }

    template<typename T>
    struct Variable {
        int id;

        static Variable<T> get_variable() {
            return {g_VAR_PTR++};
        }

        static vector<Variable<T>> get_variables(int n) {
            vector<Variable<T>> vars(n);
            for(int i = 0; i < n; i++) vars[i] = get_variable();
            return vars;
        }

        static Expression<T> get_exp_variable() {
            return Variable<T>::get_variable().as_exp();
        }

        static vector<Expression<T>> get_exp_variables(int n) {
            vector<Expression<T>> vs(n);
            int i = 0;
            for(const auto & v : Variable<T>::get_variables(n)) {
                vs[i++] = v.as_exp();
            }
            return vs;
        }

        operator Expression<T>() const {
            return make_exp<T>(*this);
        }

        Expression<T> as_exp() const {
            return Expression<T>(*this);
        }

        bool operator<(const Variable<T>& rhs) const {
            return id < rhs.id;
        }
    };

    template<typename T>
    BasicExp<T>::BasicExp(Operation n_op, const vector<node>& n_children, T n_coef)
        : op(n_op), children(n_children), coef(n_coef) {}

    template<typename T>
    BasicExp<T>::BasicExp(const T& v) {
        op = Operation::literal;
        coef = v;
    }

    template<typename T>
    BasicExp<T>::BasicExp(const Variable<T>& v) {
        op = Operation::variable;
        var = v;
    }

    template<typename T>
    Expression<T>& operator*=(Expression<T>& e, const T& x) {
        e->coef *= x;
        return e;
    }

    template<typename T>
    Expression<T> operator*(const Expression<T>& e, const T& x) {
        auto res = make_exp<T>(*e);
        return res *= x;
    }

    template<typename T>
    Expression<T>& operator+=(Expression<T>& e, const Expression<T>& rhs) {
        if(e->op == Operation::sum) {
            e->children.push_back(rhs);
        } else {
            e = make_exp<T>(Operation::sum, vector<Expression<T>>{e, rhs});
        }
        return e;
    }

    template<typename T>
    Expression<T>& operator+=(Expression<T>& e, const Variable<T>& rhs) {
        return e += make_exp<T>(rhs);
    }

    template<typename T>
    Expression<T>& operator+=(Expression<T>& e, const T& x) {
        return e += make_exp<T>(x);
    }


    template<typename T>
    Expression<T> operator+(const Expression<T>& e, const Expression<T>& rhs) {
        auto res = e->op == Operation::sum ? make_exp<T>(*e) : e;
        return res += rhs;
    }

    template<typename T>
    Expression<T> operator+(const Expression<T>& e, const Variable<T>& rhs) {
        return e + make_exp<T>(rhs);
    }

    template<typename T>
    Expression<T> operator+(const Expression<T>& e, const T& x) {
        return e + make_exp<T>(x);
    }

    template<typename T>
    Expression<T> operator+(const Variable<T>& v, const Expression<T>& rhs) {
        return make_exp<T>(v) + rhs;
    }

    template<typename T>
    Expression<T> operator+(const Variable<T>& v, const Variable<T>& rhs) {
        return make_exp<T>(v) + make_exp<T>(rhs);
    }

    template<typename T>
    Expression<T> operator+(const Variable<T>& v, const T& x) {
        return make_exp<T>(v) + make_exp<T>(x);
    }

    template<typename T>
    Expression<T> operator*(const Variable<T>& v, const T& x) {
        return make_exp<T>(v) * x;
    }

    template<typename T>
    struct ExpressionVisitor {
        void visit(const Expression<T>& e) {
            if(e->op == Operation::sum)
                this->visit_sum(e);
            else if(e->op == Operation::variable)
                this->visit_variable(e);
            else if(e->op == Operation::literal)
                this->visit_literal(e);
        }
        virtual void visit_children(const Expression<T>& e) {
            if(e->has_children()) {
                for(const Expression<T>& child : e->children)
                    this->visit(child);
            }
        }

        virtual void visit_sum(const Expression<T>& e) {
            this->visit_children(e);
        }
        virtual void visit_variable(const Expression<T>& e) {}
        virtual void visit_literal(const Expression<T>& e) {}
    };

    template<typename T>
    struct VariableVisitor : ExpressionVisitor<T> {
        set<Variable<T>> seen;
        virtual void visit_variable(const Expression<T>& e) {
            seen.insert(e->var);   
        }
    };

    template<typename T, typename S = T>
    struct StackVisitor : ExpressionVisitor<T> {
        vector<S> sta;
        virtual void visit_children(const Expression<T>& e) override {
            sta.push_back(sta.empty() ? e->coef : sta.back() * e->coef);
            ExpressionVisitor<T>::visit_children(e);
            if(!sta.empty()) sta.pop_back();
        }
        S top() const { return sta.empty() ? S(1) : sta.back(); }
    };

    template<typename T>
    struct EvalVisitor : StackVisitor<T> {
        map<Variable<T>, T> values;
        T result;
        T eval(const Expression<T>& e, const map<Variable<T>, T>& values) {
            result = T();
            this->values = values;
            this->visit(e);
            return result;
        }
        virtual void visit_variable(const Expression<T>& e) override {
            result += this->top() * e->coef * values[e->var];
        }
        virtual void visit_literal(const Expression<T>& e) override {
            result += this->top() * e->coef;
        }
    };

    enum ConstraintOperation {
        equals, different, greater, less, greater_eq, less_eq
    };

    template<typename T>
    struct Constraint {
        Expression<T> lhs, rhs;
        ConstraintOperation op;
        Constraint(const Expression<T>& a, const Expression<T>& b, ConstraintOperation op) : lhs(a), rhs(b), op(op) {}
    };

    template<typename T>
    Constraint<T> operator==(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::equals);
    }

    template<typename T>
    Constraint<T> operator!=(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::different);
    }

    template<typename T>
    Constraint<T> operator>=(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::greater_eq);
    }

    template<typename T>
    Constraint<T> operator<=(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::less_eq);
    }

    template<typename T>
    Constraint<T> operator>(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::greater);
    }

    template<typename T>
    Constraint<T> operator<(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::less);
    }

    template<typename T>
    T eval(const Expression<T>& e, const map<Variable<T>, T>& values) {
        auto visitor = std::make_unique<EvalVisitor<int>>();
        return visitor->eval(e, values);
    }

}  // namespace lib

#endif
