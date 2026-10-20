void ReverseState() {

  strip.setPixelColor(3, strip.Color(255, 255, 0));  //Set last 2 LEDS to max yellow by mixing max red and green
  strip.setPixelColor(4, strip.Color(255, 255, 0));  //Set last 2 LEDS to max yellow by mixing max red and green
  strip.show();                                      //  Update strip to match

  delay(1000);  //Delay by 1 second

  ledcWrite(motor1Apin, 0);          //Dont Spin motor forward
  ledcWrite(motor2Apin, halfSpeed);  //Spin motor in reverse
}