#if !defined(TIMED_TRANSITION_HPP_)
#define TIMED_TRANSITION_HPP_

#include "a_transition.hpp"
#include "i_set_duration_in_ms.hpp"
#include "i_get_duration_in_ms.hpp"

class TimedTransition : public ATransition, public ISetDurationInMs, public IGetDurationInMs
{
private:
    unsigned long duration_in_ms;
    IGetDurationInMs *get_duration_in_ms;

public:
    TimedTransition(AState *const past_state, AState *const new_state, const unsigned long duration_in_ms);
    TimedTransition(AState *const past_state, AState *const new_state, IGetDurationInMs *get_duration_in_ms);
    ~TimedTransition();

    unsigned long GetDurationInMs() override;
    void SetDurationInMs(const unsigned long duration_in_ms) override;
};

#endif // TIMED_TRANSITION_HPP_
