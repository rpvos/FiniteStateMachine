#if !defined(GREEN_LIGHT_STATE_HP_)
#define GREEN_LIGHT_STATE_HP_

#include "a_state.hpp"
#include <Arduino.h>

class GreenLightState : public AState
{
private:
public:
    GreenLightState();
    ~GreenLightState();

    void PreFunction() override;
    void ExucuteFunction() override;
    void PostFunction() override;
};

void GreenLightState::PreFunction()
{
    Serial.println("Green light on");
}
void GreenLightState::ExucuteFunction()
{
    Serial.print(".");
}
void GreenLightState::PostFunction()
{
    Serial.println("\nGreen light off");
}

GreenLightState::GreenLightState()
{
}

GreenLightState::~GreenLightState()
{
}

#endif // GREEN_LIGHT_STATE_HP_
