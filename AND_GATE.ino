
#include <arduino-timer.h>

#define COBFIRMATION_LETTER 'G'
#define CONFIRMATION_TIME 1000
#define RELAY_PIN 2
#define USB_BAUD_RATE 9600

auto timer = timer_create_default(); // create a timer with default settings

void turnOffRelay();

void setup() 
{
  Serial.begin(USB_BAUD_RATE);
  pinMode(RELAY_PIN, OUTPUT);

}

void loop() 
{
  if (Serial.available())
  {
    inByte = Serial.read();
  }
  
  timer.every(CONFIRMATION_TIME, turnOffRelay);

}

void turnOffRelay() 
{
  digitalWrite(RELAY_PIN, LOW);
}
