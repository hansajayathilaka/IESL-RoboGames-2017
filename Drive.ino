
void go(int leftSpeed, int rightSpeed, int MAX) {
//  if (leftSpeed == 0 && rightSpeed == 0) {
//    lineCount = 0;
//    MAXsp = 150;
//    DEFAULTsp = 80;
//    KD = 0.5;
//
//  }

  if (leftSpeed >= 0 && rightSpeed >= 0) {
    if (leftSpeed > MAX) {
      leftSpeed = MAX;
    }
    if (rightSpeed > MAX) {
      rightSpeed = MAX;
    }
    analogWrite(LF, leftSpeed);
    analogWrite(RF, rightSpeed);
    analogWrite(LB, 0);
    analogWrite(RB, 0);
  }
  else if (leftSpeed >= 0 && rightSpeed <= 0) {
    if (leftSpeed > MAX) {
      leftSpeed = MAX;
    }
    if (rightSpeed < - MAX) {
      rightSpeed = -MAX;
    }
    analogWrite(LF, leftSpeed);
    analogWrite(RF, 0);
    analogWrite(LB, 0);
    analogWrite(RB, -rightSpeed);
  }
  else if (leftSpeed <= 0 && rightSpeed >= 0) {
    if (leftSpeed < -MAX) {
      leftSpeed = -MAX;
    }
    if (rightSpeed > MAX) {
      rightSpeed = MAX;
    }
    analogWrite(LF, 0);
    analogWrite(RF, rightSpeed);
    analogWrite(LB, -leftSpeed);
    analogWrite(RB, 0);
  }
  else if (leftSpeed <= 0 && rightSpeed <= 0) {
    if (leftSpeed < -MAX) {
      leftSpeed = -MAX;
    }
    if (rightSpeed < -MAX) {
      rightSpeed = -MAX;
    }
    analogWrite(LF, 0);
    analogWrite(RF, 0);
    analogWrite(LB, -leftSpeed);
    analogWrite(RB, -rightSpeed);
  }

}


