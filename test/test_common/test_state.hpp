#if !defined(TEST_STATE_HPP_)
#define TEST_STATE_HPP_

#include "a_state.hpp"
#include <stdio.h>

class TestState : public AState
{
private:
    int number = 0;

public:
    TestState();
    ~TestState();
    void SetNumber(const int number);

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

TestState::TestState()
{
#ifdef PRINT_CONSTRUCTOR
    printf("Constructor called: %d\n", number);
#endif
}

TestState::~TestState()
{
#ifdef PRINT_DESTRUCTOR
    printf("Destructor called: %d\n", number);
#endif
}

inline void TestState::SetNumber(const int number)
{
    this->number = number;
}

inline void TestState::PreFunction()
{
#ifdef PRINT_PRE
    printf("Pre called: %d\n", number);
#endif
}

inline void TestState::ExecuteFunction()
{
#ifdef PRINT_EXE
    printf("Execute called: %d\n", number);
#endif
}

inline void TestState::PostFunction()
{
#ifdef PRINT_POST
    printf("Post called: %d\n", number);
#endif
}

#endif // TEST_STATE_HPP_
