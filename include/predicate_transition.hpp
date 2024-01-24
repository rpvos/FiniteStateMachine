#if !defined(PREDICATE_TRANSITION_HPP_)
#define PREDICATE_TRANSITION_HPP_

#include "a_transition.hpp"

typedef bool (*Predicate)(...);

class PredicateTransition : public ATransition
{
private:
    Predicate predicate = nullptr;

public:
    PredicateTransition(AState *const past_state, AState *const new_state, Predicate predicate);
    ~PredicateTransition();

    bool ExecutePredicate();
};

#endif // PREDICATE_TRANSITION_HPP_
