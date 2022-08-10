void raw_inputs(){
   qtrrc.read(sensorValues);

  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
  
  delay(250);
}
