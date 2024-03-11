#include "timed_transition.hpp"

TimedTransition::TimedTransition(AState *const past_state, AState *const new_state, const unsigned long duration_in_ms)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->get_duration_in_ms = nullptr;
    this->duration_in_ms = duration_in_ms;
}

TimedTransition::TimedTransition(AState *const past_state, AState *const new_state, IGetDurationInMs *get_duration_in_ms)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->get_duration_in_ms = get_duration_in_ms;
    this->duration_in_ms = 0;
}

TimedTransition::TimedTransition()
{
    this->past_state = nullptr;
    this->new_state = nullptr;
    this->get_duration_in_ms = nullptr;
    this->duration_in_ms = 0;
}

TimedTransition::~TimedTransition()
{
}

unsigned long TimedTransition::GetDurationInMs()
{
    if (get_duration_in_ms != nullptr)
    {
        return get_duration_in_ms->GetDurationInMs();
    }
    else if (duration_in_ms != 0)
    {
        return duration_in_ms;
    }

    return 0;
}

void TimedTransition::SetDurationInMs(const unsigned long duration_in_ms)
{
    this->duration_in_ms = duration_in_ms;
}

void TimedTransition::SetDurationInMs(IGetDurationInMs *get_duration_in_ms)
{
    this->get_duration_in_ms = get_duration_in_ms;
}
