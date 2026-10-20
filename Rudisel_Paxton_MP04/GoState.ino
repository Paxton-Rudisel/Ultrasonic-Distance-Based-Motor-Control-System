void GoState() {
  strip.setPixelColor(0, strip.Color(0, 255, 0));  //Set first 2 LEDS to max green
  strip.setPixelColor(1, strip.Color(0, 255, 0));  //Set first 2 LEDS to max green
  strip.show();                                    //  Update strip to match

  delay(1000);  //Delay by 1 second

  ledcWrite(motor1Apin, dutyCycle);  //Spin motor forward at 70% speed
  ledcWrite(motor2Apin, 0);          //Dont Spin motor in reverse
}