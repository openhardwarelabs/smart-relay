// Simple sketch to test the sensor

void setup() {
  
  Serial.begin(115200);
}

void loop() {

  Serial.println(getSensorValue(A0));
  delay(10);
  
}

// Get the reading from the current sensor
float getSensorValue(int pin)
{
  int sensorValue;
  float avgSensor = 0;
  int nb_measurements = 500;
  for (int i = 0; i < nb_measurements; i++) {
    sensorValue = analogRead(pin);
    avgSensor = avgSensor + float(sensorValue);
  }	  
  avgSensor = avgSensor/float(nb_measurements);
  return avgSensor;
}
