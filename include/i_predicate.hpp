#if !defined(I_PREDICATE_HPP_)
#define I_PREDICATE_HPP_

typedef bool (*Predicate)(...);

class IPredicate
{
public:
    virtual bool Predicate(...) = 0;
};

#endif // I_PREDICATE_HPP_
