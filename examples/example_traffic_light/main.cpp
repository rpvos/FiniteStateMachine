#include <Arduino.h>
#include "finite_state_machine.hpp"
#include "states/green_light_state.hpp"
#include "states/red_light_state.hpp"

GreenLightState green = GreenLightState();
RedLightState red = RedLightState();

TimedTransition transitions[] = {
    TimedTransition(&green, &red, 4000),
    TimedTransition(&red, &green, 6000),
};

FiniteStateMachine fsm;

void setup()
{
  Serial.begin(9600);

  fsm = FiniteStateMachine(&red);

  const size_t transitions_size = sizeof(transitions) / sizeof(TimedTransition);
  fsm.SetTimedTransitions(transitions, transitions_size);
}

void loop()
{
  fsm.Update(millis());
}