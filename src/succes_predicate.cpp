#include "succes_predicate.hpp"

SuccesPredicate::SuccesPredicate()
{
    this->succes = false;
}

SuccesPredicate::~SuccesPredicate()
{
}

bool SuccesPredicate::Predicate(...)
{
    return succes;
}
