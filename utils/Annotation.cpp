#ifndef _LIB_ANNOTATION
#define _LIB_ANNOTATION
#include <bits/stdc++.h>

namespace lib {
using namespace std;
template <typename T, typename A = void>
struct Note : public T {
private:
    A m_data = A();
    Note(const T& t, const A& a) : T(t), m_data(a) {}
public:
    using T::T;

    static Note make(const T& t, const A& a) {
        return Note(t, a);
    }

    friend A& annotation(Note& note) {
        return note.m_data;
    }
    friend const A& annotation(const Note& note) {
        return note.m_data;
    }

    template<typename C, typename D>
    operator Note<T,A>() const {
        return Note<C, D>(*this, m_data);
    }
};

template <typename T>
struct Note<T, void> : public T {
    using T::T;
    using T::operator=;
    
    Note(const T& a) : T(a) {}
    Note(T &&a): T(std::move(a)) {}
};

template<typename T, typename A>
Note<T, A> make_note(const T& t, const A& a) {
    return Note<T, A>::make(t, a);
}
} // namespace lib

#endif
