void startup() {
  Serial.begin(115200);      // Begin serial communication at 115200 baud rate​
  pinMode(echoPin, INPUT);   // Set echoPin as input
  pinMode(trigPin, OUTPUT);  // Set trigPin as output​

  Serial.println("Ultrasonic sensor:");  // Print sensor information to the serial monitor​
  strip.begin();                         // initialize the NeoPixel strip object (REQUIRED in setup)​
  strip.show();                          // Initialize all pixels to 'off'​

  // Set up PWM​
  ledcAttach(motor1Apin, freq, resolution);  //Set up forward motor
  ledcAttach(motor2Apin, freq, resolution);  //Set up reverse motor
}