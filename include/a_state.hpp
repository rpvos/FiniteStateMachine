#if !defined(A_STATE_HPP_)
#define A_STATE_HPP_

class AState
{
private:
protected:
    unsigned long state_start_time_in_ms;

public:
    AState();

    virtual void PreFunction() = 0;
    virtual void ExecuteFunction() = 0;
    virtual void PostFunction() = 0;
    void SetStateStartTimeInMs(unsigned long now);
    unsigned long GetStateStartTimeInMs();
};

#endif // A_STATE_HPP_
