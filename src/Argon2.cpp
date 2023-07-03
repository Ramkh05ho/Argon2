/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/ramikhosho/Argon2/src/Argon2.ino"

void setup();
void loop();
#line 2 "/Users/ramikhosho/Argon2/src/Argon2.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

// Define LED pin
#define LED D2 // LED connected to D2 pin
#define BUTTON D7

// setup() runs once, when the device is first turned on.
void setup()
{
  pinMode(LED, OUTPUT); // Initialize the LED pin as an output
  pinMode(BUTTON, INPUT);

  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.isConnected();
  Serial.available();
  while (!Serial.isConnected())
  {
  }
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  if (Serial1.available())
  {

    char CMND = Serial1.read();

    if (CMND == '1')
    {
      digitalWrite(LED, HIGH); // Turn on the LED
      Serial.println("LED turned on");
    }
    else if (CMND == '0')
    {
      digitalWrite(LED, LOW); // Turn off the LED
      Serial.println("LED turned off");
    }
    if (CMND == '?')
    {
      // digitalRead(BUTTON);
      Serial1.write(digitalRead(BUTTON));
      if (digitalRead(BUTTON))
      {
        Serial.println("Button State is HIGH!");
  
      }
      else
      {
        Serial.println("Button State is LOW!");
      }
    }
  }
}
