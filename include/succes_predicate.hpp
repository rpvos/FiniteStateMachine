#if !defined(SUCCES_PREDICATE_HPP_)
#define SUCCES_PREDICATE_HPP_

#include "i_predicate.hpp"

class SuccesPredicate : public IPredicate
{
private:
public:
    SuccesPredicate();
    ~SuccesPredicate();

    bool succes;

    bool Predicate(...) override;
};

#endif // SUCCES_PREDICATE_HPP_
