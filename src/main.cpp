#include<Arduino.h>
#include <timer.h>

int led_pin = 13; 
bool led_is_on = false; 


Timer timer;


void blinkLed() {
  if(led_is_on) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }
  
  led_is_on = !led_is_on;
}

void setup()
{
  pinMode(led_pin, OUTPUT);
  timer.setInterval(1000);
  timer.setCallback(blinkLed);
  timer.start();
}

void loop()
{
  timer.update();
}
