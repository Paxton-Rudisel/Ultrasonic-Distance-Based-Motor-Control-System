// Function to read data from the ultrasonic sensor​

float readSensorData() {
  digitalWrite(trigPin, LOW);  // Trigger a low signal before sending a high signal​
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Send a 10-microsecond high signal to the trigPin​
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Return to low signal​

  // Measure the duration of the high signal on the echoPin​
  unsigned long microsecond = pulseIn(echoPin, HIGH);

  // Calculate the distance using the speed of sound (29.00µs per centimeter)​
  float distance = microsecond / 29.00 / 2;

  // Return the calculated distance​
  return distance;
}