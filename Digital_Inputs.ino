int D(byte n) {
  if (clr == 0) {
    if ((sensorValues[n]) > 700) {
      return 1;
    }
    else {
      return 0;
    }
  }
  if (clr == 1) {
    if ((sensorValues[n]) > 700) {
      return 0;
    }
    else {
      return 1;
    }
  }
}

byte dSum() {
  int sum = 0;
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    sum += D(i);
  }
  return sum;
}
