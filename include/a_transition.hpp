#if !defined(A_TRANSITION_HPP_)
#define A_TRANSITION_HPP_

#include "a_state.hpp"

class ATransition
{
private:
public:
    AState *past_state;
    AState *new_state;
};

#endif // A_TRANSITION_HPP_
