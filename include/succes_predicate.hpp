#if !defined(SUCCES_PREDICATE_HPP_)
#define SUCCES_PREDICATE_HPP_

#include "i_predicate.hpp"

class SuccesPredicate : IPredicate
{
private:
    bool succes;

public:
    SuccesPredicate();
    ~SuccesPredicate();

    bool Predicate(...) override;
};

#endif // SUCCES_PREDICATE_HPP_
