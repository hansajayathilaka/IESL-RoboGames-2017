long dis(){
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH,2000);
  if (duration==0){
    duration = 2000;
  }
  distance = (duration/2) / 29.1;
  return distance;
}
