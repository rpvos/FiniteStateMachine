#if !defined(RED_LIGHT_STATE_HPP_)
#define RED_LIGHT_STATE_HPP_

#include "a_state.hpp"
#include <Arduino.h>

class RedLightState : public AState
{
private:
public:
    RedLightState();
    ~RedLightState();

    void PreFunction() override;
    void ExucuteFunction() override;
    void PostFunction() override;
};

RedLightState::RedLightState()
{
}

RedLightState::~RedLightState()
{
}

void RedLightState::PreFunction()
{
    Serial.println("Red light on");
}
void RedLightState::ExucuteFunction()
{
    Serial.print(".");
}
void RedLightState::PostFunction()
{
    Serial.println("\nRed light off");
}

#endif // RED_LIGHT_STATE_HPP_
