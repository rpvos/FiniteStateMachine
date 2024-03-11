#if !defined(TEST_I_PREDICATE_STATE_HPP_)
#define TEST_I_PREDICATE_STATE_HPP_

#include "i_predicate.hpp"
#include "test_state.hpp"

class TestIPredicateState : public IPredicate, public TestState
{
private:
public:
    bool Predicate() override;
};

inline bool TestIPredicateState::Predicate()
{
    return true;
}

#endif // TEST_I_PREDICATE_STATE_HPP_
