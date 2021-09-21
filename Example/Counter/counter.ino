#include "Counter.h"

#define PIN_BUTTON  0
#define PIN_LED     LED_BUILTIN

// instand object
Counter counter(PIN_BUTTON, PIN_LED);

void setup() {
  // serial setup
  Serial.begin(115200);

  // counter time
  counter.setTimeSecond(5);
}

void loop() {
  // call counter
  counter.loop();

}
