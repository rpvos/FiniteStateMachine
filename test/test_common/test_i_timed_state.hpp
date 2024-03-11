#if !defined(TEST_I_TIMED_STATE_HPP_)
#define TEST_I_TIMED_STATE_HPP_

#include "i_get_duration_in_ms.hpp"
#include "i_set_duration_in_ms.hpp"
#include "test_state.hpp"

class TestITimedState : public IGetDurationInMs, public ISetDurationInMs, public TestState
{
private:
    unsigned long duration_in_ms;

public:
    unsigned long GetDurationInMs() override;
    void SetDurationInMs(const unsigned long duration_in_ms) override;
};

inline unsigned long TestITimedState::GetDurationInMs()
{
    return duration_in_ms;
}

inline void TestITimedState::SetDurationInMs(const unsigned long duration_in_ms)
{
    this->duration_in_ms = duration_in_ms;
}

#endif // TEST_I_TIMED_STATE_HPP_
