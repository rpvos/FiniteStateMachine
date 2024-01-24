#include "a_state.hpp"

AState::AState()
{
    this->state_start_time_in_ms = 0;
}

void AState::SetStateStartTimeInMs(unsigned long now)
{
    this->state_start_time_in_ms = now;
}

unsigned long AState::GetStateStartTimeInMs()
{
    return this->state_start_time_in_ms;
}