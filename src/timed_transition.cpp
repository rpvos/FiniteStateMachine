#include "timed_transition.hpp"

TimedTransition::TimedTransition(AState *const past_state, AState *const new_state, const unsigned long duration_in_ms)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->duration_in_ms = duration_in_ms;
}

TimedTransition::~TimedTransition()
{
}

unsigned long TimedTransition::GetDurationInMs()
{
    return this->duration_in_ms;
}