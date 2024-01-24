#if !defined(TIMED_TRANSITION_HPP_)
#define TIMED_TRANSITION_HPP_

#include "a_transition.hpp"

class TimedTransition : public ATransition
{
private:
    unsigned long duration_in_ms;

public:
    TimedTransition(AState *const past_state, AState *const new_state, const unsigned long duration_in_ms);
    ~TimedTransition();

    unsigned long GetDurationInMs();
};

#endif // TIMED_TRANSITION_HPP_
