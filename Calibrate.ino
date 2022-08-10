void Calibrate() {

  int k = 0;

  for (int i = 0; i < 400; i++)
  {
    k = i / 40;
    if (k % 2 == 0) {
      go(-50, 50);
      qtrrc.calibrate();
    }
    else {
      go(50, -50);
      qtrrc.calibrate();
    }
  }
  go(0, 0);
  delay(5000);
}
