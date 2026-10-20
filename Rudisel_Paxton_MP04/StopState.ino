void StopState() {
  strip.setPixelColor(6, strip.Color(255, 0, 0));  //Set middle 2 LEDS to max red
  strip.setPixelColor(7, strip.Color(255, 0, 0));  //Set middle 2 LEDS to max red
  strip.show();                                    //  Update strip to match

  delay(1000);  //Delay by 1 second

  ledcWrite(motor1Apin, 0);  //Dont Spin motor forward
  ledcWrite(motor2Apin, 0);  //Dont Spin motor in reverse
}