#include "predicate_transition.hpp"

PredicateTransition::PredicateTransition(AState *const past_state, AState *const new_state, Predicate predicate)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->predicate = predicate;
    this->i_predicate = nullptr;
}

PredicateTransition::PredicateTransition(AState *const past_state, AState *const new_state, IPredicate *predicate)
{
    this->past_state = past_state;
    this->new_state = new_state;
    this->i_predicate = predicate;
    this->predicate = nullptr;
}

PredicateTransition::PredicateTransition()
{
    this->past_state = nullptr;
    this->new_state = nullptr;
    this->predicate = nullptr;
    this->i_predicate = nullptr;
}

PredicateTransition::~PredicateTransition()
{
}

void PredicateTransition::SetPredicate(Predicate predicate)
{
    this->predicate = predicate;
}

void PredicateTransition::SetPredicate(IPredicate *predicate)
{
    this->i_predicate = predicate;
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