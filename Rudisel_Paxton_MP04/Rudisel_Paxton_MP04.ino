/*
  Program: Rudisel_Paxton_MP04.ino
  Author: Paxton Rudisel
  Date created: 10/01/26
  Last revised: 10/01/26

  Description: The ultrasonic sensor measures distance to control
  the DC motor and NeoPixel LEDs. The motor moves forward, stops,
  or reverses based on measured distance.

  Hardware: ESP32 Dev Module, ultrasonic sensor, DC motor,
  L293D motor driver, 8-pixel NeoPixel strip and power supply module.

  Functions: readSensorData reads the distance from the ultrasonic
  sensor. startup initializes the hardware, GoState runs the motor
  forward, StopState stops it, and ReverseState reverses it.
  These states also set the LED indicators. OffState turns the LEDs off.
*/
#include <Adafruit_NeoPixel.h>  //include NeoPixel Library

#define RGB_CONTROL_PIN 25  //Pin for LED Strip
#define NUMPIXELS 8         //Popular NeoPixel ring size​
#define motor1Apin 26       //Motor pin 1
#define motor2Apin 27       //Motor pin 2

// PWM settings​
const int freq = 500;      //PWM frequency: 500 Hz​
const int resolution = 8;  //PWM resolution: 8 bits​
int dutyCycle = 190;       //~75% speed​
int halfSpeed = 128;       //Half of max speed for ReverseState

// Define pins for the ultrasonic sensor​
const int echoPin = 12;  //Echo pin
const int trigPin = 14;  //Trigger pin

float readSensorData();  //Function prototype for reading sensor data​
void startup();          //Function prototype for all setup functions
void GoState();          //Function prototype for spinning the motor forward and setting the first 2 LEDs to green
void StopState();        //Function prototype for stopping the motor and setting the last 2 LEDs to red
void ReverseState();     //Function prototype for reversing the motor and setting the middle 2 LEDs to yellow
void OffState();         //Function prototype for reseting LEDs to be off.
//Creates the NeoPixel strip
Adafruit_NeoPixel strip(NUMPIXELS, RGB_CONTROL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  startup();    //call all setup functions from startup code page
  StopState();  //Start in StopState
}

void loop() {

  float distance = readSensorData();  //Read distance from the ultrasonic sensor​

  //Spin the motor forward and set the first 2 LEDs to green if distance read by sensor greater than 12
  if (distance > 12) {
    Serial.print("GO! | ");  //Print what state (GoState)
    Serial.print(distance);  //Print the measured distance to the serial monitor​
    Serial.println(" cm");   //Print "cm" next to measured distance
    GoState();               //Call GoState
    OffState();              //Call OffState
  }
  //Stop the motor and set the last 2 LEDs to red if distance read by sensor less than or equal to 12, but also greater than 10
  else if (distance <= 12 && distance > 10) {
    Serial.print("STOP! | ");  //Print what state (StopState)
    Serial.print(distance);    //Print the measured distance to the serial monitor​
    Serial.println(" cm");     //Print "cm" next to measured distance
    StopState();               //Call StopState
    OffState();                //Call OffState
  }
  //Spin the motor in reverse and set the middle 2 LEDs to yellow if distance read by sensor less than 10
  else if (distance <= 12) {
    Serial.print("REVERSE! | ");  //Print what state (ReverseState)
    Serial.print(distance);       //Print the measured distance to the serial monitor​
    Serial.println(" cm");        //Print "cm" next to measured distance
    ReverseState();               //Call ReverseState
    OffState();                   //Call OffState
  } else {
    OffState();  //Call OffState (Reset LED Strip)
  }
}
