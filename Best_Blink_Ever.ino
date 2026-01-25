#define PROG_NAME "Best_Blink_Ever"
#define VERSION " V0.0.3 "
// Author: Yehia Ayman
// Date: 20260125
// A simple code on which to develope features.

// Customized this by changing these defines


#define MODEL_NAME "Model: ESP32 Dev Module"
#define DEVICE_UNDER_TEST "SN: 00001"  //A Serial Number
#define LICENSE "GNU Affero General Public License, version 3 "
#define ORIGIN "EG"

#define BAUDRATE 115200  //Serial port

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/


#define LED_BUILTIN 2

//Claases defined below
class Flasher {
  // Class Member Variables
  // These are initialized at startup
  int ledPin;    // the number of the LED pin
  long OnTime;   // milliseconds of on-time
  long OffTime;  // milliseconds of off-time

  // These maintain the current state
  int ledState;                  // ledState used to set the LED
  unsigned long previousMillis;  // will store last time LED was updated

  // Constructor - creates a Flasher
  // and initializes the member variables and state
public:
  Flasher(int pin, long on, long off) {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    ledState = LOW;
    previousMillis = 0;
  }
  void Update() {  // defining a member function of the Flasher class
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();

    if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) {
      ledState = LOW;                  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    } else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) {
      ledState = HIGH;                 // turn it on
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
  }
};

Flasher led1(LED_BUILTIN, 250, 250);  // LED 2 blinks 0.5 period and 50% duty cycle
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(BAUDRATE);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB
  }
  pinMode(LED_BUILTIN, OUTPUT);
  serialSplash();
}

// the loop function runs over and over again forever
void loop() {
led1.Update();
  // digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  
  // delay(1000);                      // wait for a second
  // digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  // delay(1000);                      // wait for a second
}
