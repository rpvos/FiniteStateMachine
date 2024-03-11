#if !defined(FINITE_STATE_MACHINE_HPP_)
#define FINITE_STATE_MACHINE_HPP_

#include "a_state.hpp"
#include "timed_transition.hpp"
#include "predicate_transition.hpp"
#include <stddef.h>

class FiniteStateMachine
{
private:
    unsigned int timed_transitions_size;
    TimedTransition *timed_transitions;

    unsigned int predicate_transitions_size;
    PredicateTransition *predicate_transitions;

    AState *current_state;
    unsigned long last_updated;

    bool IsTimeToUpdate(const unsigned long now, const unsigned long interval);
    void HandlePredicateTransitions(const unsigned long now);
    void HandleTimedTransitions(const unsigned long now);

public:
    FiniteStateMachine(AState *current_state = nullptr, const unsigned long now = 0);
    ~FiniteStateMachine();

    void TransitionState(AState *new_state, const unsigned long now);
    void SetTimedTransitions(TimedTransition *timed_transitions, const size_t time_transitions_size);
    void SetPredicateTransitions(PredicateTransition *predicate_transitions, const size_t predicate_transitions_size);

    void Update(const unsigned long now, const int interval_is_ms = 1000);
};

#endif // FINITE_STATE_MACHINE_HPP_
