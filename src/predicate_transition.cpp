#include "predicate_transition.hpp"

PredicateTransition::PredicateTransition(AState *const past_state, AState *const new_state, Predicate predicate)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->predicate = predicate;
}

PredicateTransition::PredicateTransition(AState *const past_state, AState *const new_state, IPredicate *predicate)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->i_predicate = predicate;
}

PredicateTransition::~PredicateTransition()
{
}

bool PredicateTransition::ExecutePredicate()
{
    if (this->predicate != nullptr)
    {
        return this->predicate();
    }
    else if (this->i_predicate != nullptr)
    {
        return this->i_predicate->Predicate();
    }
    return false;
}