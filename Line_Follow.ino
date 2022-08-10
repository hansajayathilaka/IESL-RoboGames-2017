void line_follow(unsigned int DEFAULT_SPEED, unsigned int MAX) {
//  if (lineCount < 300) {
//    lineCount++;
//  } else {
//    MAXsp = 255;
//    DEFAULTsp = 140;
//    KD = 1;
//  }

  unsigned int position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON,clr);
  error = position - 3500;
  integral = integral + error;

  int motorSpeed = KP * error + KD * (error - lastError) + KI * integral;
  lastError = error;

  int leftMotorSpeed = DEFAULT_SPEED + motorSpeed;
  int rightMotorSpeed = DEFAULT_SPEED - motorSpeed;
  //  Serial.print(leftMotorSpeed);
  //  Serial.print('\t');
  //  Serial.print(rightMotorSpeed);
  //  Serial.println();
  go(leftMotorSpeed, rightMotorSpeed, MAX);
}

void updateVal() {
  unsigned int position = qtrrc.readLine(sensorValues);
  error = position - 3500;

  int motorSpeed = KP * error + KD * (error - lastError);
  lastError = error;

  int leftMotorSpeed = DEFAULTsp;
  int rightMotorSpeed = DEFAULTsp;
  //  Serial.print(leftMotorSpeed);
  //  Serial.print('\t');
  //  Serial.print(rightMotorSpeed);
  //  Serial.println();
  //go(leftMotorSpeed, rightMotorSpeed);
}
