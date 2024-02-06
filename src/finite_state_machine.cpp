#include "finite_state_machine.hpp"
#include <Arduino.h>

const unsigned long kMaxUnsignedLong = ~0ul;

bool FiniteStateMachine::IsTimeToUpdate(unsigned long now, unsigned long interval)
{
    return now >= last_updated + interval;
}

void FiniteStateMachine::HandlePredicateTransitions()
{
    for (size_t i = 0; i < predicate_transitions_size; i++)
    {
        if (predicate_transitions[i].past_state != this->current_state)
        {
            continue;
        }

        if (predicate_transitions[i].ExecutePredicate())
        {
            TransitionState(predicate_transitions[i].new_state);
            return;
        }
    }
}

void FiniteStateMachine::HandleTimedTransitions(unsigned long now)
{
    for (size_t i = 0; i < timed_transitions_size; i++)
    {
        if (timed_transitions[i].past_state != this->current_state)
        {
            continue;
        }

        // Calculate the time between state start and now and check if it is bigger then the transition duration
        if (timed_transitions[i].GetDurationInMs() <= now + (kMaxUnsignedLong - this->current_state->GetStateStartTimeInMs()) + 1)
        {
            TransitionState(timed_transitions[i].new_state);
            return;
        }
    }
}

void FiniteStateMachine::TransitionState(AState *new_state)
{
    if (current_state != nullptr)
    {
        this->current_state->PostFunction();
    }
    this->current_state = new_state;
    if (new_state != nullptr)
    {
        this->current_state->SetStateStartTimeInMs(millis());
        this->current_state->PreFunction();
    }
}

FiniteStateMachine::FiniteStateMachine(AState *current_state)
{
    this->predicate_transitions = nullptr;
    this->predicate_transitions_size = 0;
    this->timed_transitions = nullptr;
    this->timed_transitions_size = 0;
    this->current_state = nullptr;
    this->last_updated = 0;
    TransitionState(current_state);
}

FiniteStateMachine::~FiniteStateMachine()
{
}

void FiniteStateMachine::SetTimedTransitions(TimedTransition *timed_transitions, size_t timed_transitions_size)
{
    size_t size = sizeof(TimedTransition) * timed_transitions_size;
    TimedTransition *temp = (TimedTransition *)malloc(size);
    if (temp == nullptr)
    {
        return;
    }
    memcpy(temp, timed_transitions, size);
    free(this->timed_transitions);

    this->timed_transitions = temp;
    this->timed_transitions_size = timed_transitions_size;
}

void FiniteStateMachine::SetPredicateTransitions(PredicateTransition *predicate_transitions, size_t predicate_transitions_size)
{
    size_t size = sizeof(PredicateTransition) * predicate_transitions_size;
    PredicateTransition *temp = (PredicateTransition *)malloc(size);
    if (temp == nullptr)
    {
        return;
    }
    memcpy(temp, predicate_transitions, size);
    free(this->predicate_transitions);

    this->predicate_transitions = temp;
    this->predicate_transitions_size = predicate_transitions_size;
}

void FiniteStateMachine::Update(int interval_is_ms)
{
    unsigned long now = millis();

    // Check if state is initialised
    if (this->current_state == nullptr)
    {
        return;
    }

    // Check if interval is met
    if (!IsTimeToUpdate(now, interval_is_ms))
    {
        return;
    }
    // Save time as time last updated
    this->last_updated = now;

    // Handle transitions
    HandlePredicateTransitions();
    HandleTimedTransitions(now);

    // Execute function
    current_state->ExecuteFunction();
}
