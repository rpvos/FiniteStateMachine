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

    bool IsTimeToUpdate(unsigned long now, unsigned long interval);
    void HandlePredicateTransitions();
    void HandleTimedTransitions(unsigned long now);

public:
    FiniteStateMachine(AState *current_state = nullptr);
    ~FiniteStateMachine();

    void TransitionState(AState *new_state);
    void SetTimedTransitions(TimedTransition *timed_transitions, size_t time_transitions_size);
    void SetPredicateTransitions(PredicateTransition *predicate_transitions, size_t predicate_transitions_size);

    void Update(int interval_is_ms = 1000);
};

#endif // FINITE_STATE_MACHINE_HPP_
