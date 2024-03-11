#include "finite_state_machine.hpp"

// #define PRINT_EXE

#include "test_state.hpp"
#include "test_predicate.hpp"
#include "test_i_predicate_state.hpp"
#include "test_i_timed_state.hpp"

#include "unity.h"

FiniteStateMachine fsm;

const size_t count = 128;
const unsigned long step_size = 500;
const size_t amount_of_updates = count * 4;
unsigned long now;

const unsigned long timed_duration = 1000;

void setUp(void)
{
    fsm = FiniteStateMachine();
    now = 0;
}

void tearDown(void)
{
    fsm.~FiniteStateMachine();
}

void test_predicate_states()
{
    TestState states[count];
    PredicateTransition transitions[count];

    for (size_t i = 0; i < count; i++)
    {
        states[i].SetNumber(i);
        if (i > 0)
        {
            transitions[i].past_state = &states[i - 1];
        }
        else
        {
            transitions[i].past_state = &states[count - 1];
        }

        transitions[i].new_state = &states[i];
        transitions[i].SetPredicate(TestPredicate);
    }

    fsm.SetPredicateTransitions(transitions, count);

    fsm.TransitionState(&states[0], 0);

    for (size_t i = 0; i < amount_of_updates; i++)
    {
        fsm.Update(now += step_size);
    }
}

void test_i_predicate_states()
{
    TestIPredicateState states[count];
    PredicateTransition transitions[count];

    for (size_t i = 0; i < count; i++)
    {
        states[i].SetNumber(i);
        if (i > 0)
        {
            transitions[i].past_state = &states[i - 1];
            transitions[i].SetPredicate(&states[i - 1]);
        }
        else
        {
            transitions[i].past_state = &states[count - 1];
            transitions[i].SetPredicate(&states[count - 1]);
        }

        transitions[i].new_state = &states[i];
    }

    fsm.SetPredicateTransitions(transitions, count);

    fsm.TransitionState(&states[0], 0);

    for (size_t i = 0; i < amount_of_updates; i++)
    {
        fsm.Update(now += step_size);
    }
}

void test_timed_states()
{
    TestState states[count];
    TimedTransition transitions[count];

    for (size_t i = 0; i < count; i++)
    {
        states[i].SetNumber(i);
        if (i > 0)
        {
            transitions[i].past_state = &states[i - 1];
        }
        else
        {
            transitions[i].past_state = &states[count - 1];
        }

        transitions[i].new_state = &states[i];
        transitions[i].SetDurationInMs(timed_duration);
    }

    fsm.SetTimedTransitions(transitions, count);

    fsm.TransitionState(&states[0], 0);

    for (size_t i = 0; i < amount_of_updates; i++)
    {
        fsm.Update(now += step_size);
    }
}

void test_i_timed_states()
{
    TestITimedState states[count];
    TimedTransition transitions[count];

    for (size_t i = 0; i < count; i++)
    {
        states[i].SetNumber(i);
        if (i > 0)
        {
            transitions[i].past_state = &states[i - 1];
        }
        else
        {
            transitions[i].past_state = &states[count - 1];
        }

        transitions[i].new_state = &states[i];
        states[i].SetDurationInMs(timed_duration);
        transitions[i].SetDurationInMs(&states[i]);
    }

    fsm.SetTimedTransitions(transitions, count);

    fsm.TransitionState(&states[0], 0);

    for (size_t i = 0; i < amount_of_updates; i++)
    {
        fsm.Update(now += step_size);
    }
}

void run_tests(void)
{
    UNITY_BEGIN(); // Start unit testing

    RUN_TEST(test_predicate_states);
    RUN_TEST(test_i_predicate_states);
    RUN_TEST(test_timed_states);
    RUN_TEST(test_i_timed_states);

    UNITY_END(); // Stop unit testing
}

#ifdef ARDUINO
#include <Arduino.h>

void setup()
{
    delay(2000);
    run_tests();
}

void loop()
{
    delay(1000);
}

#else

int main(int argc, char const *argv[])
{
    run_tests();
    return 0;
}

#endif