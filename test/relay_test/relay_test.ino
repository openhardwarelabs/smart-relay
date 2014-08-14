// Simple sketch to test the relay
 
// Relay pin
const int relay_pin = 8;

// Define measurement variables
float amplitude_current;
float effective_value;
float effective_voltage = 230; // Set voltage to 230V (Europe) or 110V (US)
float effective_power;
float zero_sensor;

void setup() {
  
  Serial.begin(115200);
  
  pinMode(relay_pin,OUTPUT);
  
  // Calibrate sensor with null current
  zero_sensor = getSensorValue(A0);
  
  Serial.print("Zero sensor: ");
  Serial.println(zero_sensor);
}

void loop() {
  
  // Activate relay
  digitalWrite(relay_pin, HIGH);
  
  // Perform power measurement
  float sensor_value = getSensorValue(A0);
    
  // Convert to power
  amplitude_current = (float)(sensor_value-zero_sensor)/1024*5/185*1000000;
  effective_value = amplitude_current/1.414;
  effective_power = abs(effective_value*effective_voltage/1000);
  Serial.print("Power: ");
  Serial.println(effective_power);
  
  // Wait for 5 seconds
  delay(5000);
  
   // Deactivate relay
  digitalWrite(relay_pin, LOW);
  
  // Perform power measurement
  sensor_value = getSensorValue(A0);
  
  // Convert to power
  amplitude_current = (float)(sensor_value-zero_sensor)/1024*5/185*1000000;
  effective_value = amplitude_current/1.414;
  effective_power = abs(effective_value*effective_voltage/1000);
  Serial.print("Power: ");
  Serial.println(effective_power);
  
  // Wait for 5 seconds
  delay(5000);
}

// Get the reading from the current sensor
float getSensorValue(int pin)
{
  delay(5000);
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
