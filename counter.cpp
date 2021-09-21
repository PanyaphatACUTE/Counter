#include "Counter.h"

Counter::Counter(const int btnPin, const int ledPin, const int timeSecond, 
const bool btnPinActive, const bool ledPinActive){
  this->btnPin = btnPin;
  this->ledPin = ledPin;
  this->btnPinActive = btnPinActive;
  this->ledPinActive = ledPinActive;
  setTimeSecond(timeSecond);
  pinMode(this->btnPin, INPUT);
  pinMode(this->ledPin, OUTPUT);
}

Counter::~Counter(){

}

void Counter::setTimeSecond(const int timeSecond){
  this->timeSecond = timeSecond;
}

void Counter::loop(){
  int countDown = timeSecond;
  bool button = false;
  if (digitalRead(btnPin) == btnPinActive)
    button = true;
  if (digitalRead(btnPin) == !btnPinActive && button)  {
    uint32_t cur = millis();
    uint32_t prev = cur;
    uint32_t timeSecondPrev = prev + ((timeSecond) * 1000);
    while (cur <= (timeSecondPrev)) {
      if (cur >= _next) {
        digitalWrite(ledPin, !digitalRead(ledPin));  //blinks
        _next = cur + 500;
        // print
        if (digitalRead(ledPin) == this->ledPinActive) {
          if ( countDown == 0) {
            Serial.println("Time Up!!!");
          } else {
            Serial.print("Counter remian ");
            Serial.print(countDown--) ;
            Serial.println(" seconds");
          }
        }
      }
      cur = millis();
    }
    button = false;
  } else {
    // turn off led
    digitalWrite(ledPin, this->ledPinActive == LOW ? HIGH : LOW);
  }

}
