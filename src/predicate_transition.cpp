#include "predicate_transition.hpp"

PredicateTransition::PredicateTransition(AState *const past_state, AState *const new_state, Predicate predicate)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->predicate = predicate;
}

PredicateTransition::~PredicateTransition()
{
}

bool PredicateTransition::ExecutePredicate()
{
    return this->predicate();
}