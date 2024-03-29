#if !defined(PREDICATE_TRANSITION_HPP_)
#define PREDICATE_TRANSITION_HPP_

#include "a_transition.hpp"
#include "i_predicate.hpp"

class PredicateTransition : public ATransition
{
private:
    Predicate predicate = nullptr;
    IPredicate *i_predicate = nullptr;

public:
    explicit PredicateTransition(AState *const past_state, AState *const new_state, Predicate predicate);
    explicit PredicateTransition(AState *const past_state, AState *const new_state, IPredicate *predicate);
    PredicateTransition();
    ~PredicateTransition();

    void SetPredicate(Predicate predicate);
    void SetPredicate(IPredicate *predicate);

    bool ExecutePredicate();
};

#endif // PREDICATE_TRANSITION_HPP_
