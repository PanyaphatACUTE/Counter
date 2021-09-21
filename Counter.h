#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <arduino.h>

class Counter{
  public: // public method
  Counter(const int btnPin,
            const int ledPin,
            const int timeSecond = 10,
            const bool btnPinActive = LOW,
            const bool ledPinActive = LOW);
  ~Counter();

  // set time second
  void setTimeSecond(const int timeSecond);
  // loop 
  void loop();

  private: // private data
  int btnPin;
  int ledPin;
  int timeSecond;
  bool btnPinActive;
  bool ledPinActive;
  uint32_t cur;
  uint32_t _next;
};

#endif
