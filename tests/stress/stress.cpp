#ifndef _LIB_STRESS_TESTING
#define _LIB_STRESS_TESTING
#include "../catch.hpp"
#include "../../Random.cpp"

#include "../jngen.h"

#define INTERNAL_STRESS(name, n) for(int name = 0; name < n; name++)
#define STRESS(n) INTERNAL_STRESS(_stress_cnt##__COUNTER__, n)

class StressTestFixture {
private:
    static int g_id;
    lib::rng::Generator m_gen;
public:
    StressTestFixture() {
        std::seed_seq seq{g_id++};
        m_gen = lib::rng::Generator(seq);
    }
    const int id() const { return g_id; }
    const lib::rng::Generator& gen() {
        return m_gen;
    }
};

int StressTestFixture::g_id = 0;

#endif