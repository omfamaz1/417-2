const int potPin = A0;  

int potValue = 0;
int mappedValue = 0;   
float mappedVoltage = 0.0;  
float voltage = 0.0;

void setup() {
  Serial.begin(9600);
  
  Serial.println("Potentiometer Reader");
  Serial.println("-------------------");
}

void loop() {
  potValue = analogRead(potPin);
  mappedValue = map(potValue, 0, 1023, 0, 5);
  mappedVoltage = (float)mappedValue;
  voltage = potValue * (5.0 / 1023.0);

  Serial.print("Raw Value: ");
  Serial.print(potValue);
  Serial.print("\t");
  
  Serial.print("Mapped Value (int): ");
  Serial.print(mappedValue);
  Serial.print("\t");
  
  Serial.print("Mapped Voltage (float): ");
  Serial.print(mappedVoltage, 3); 
  Serial.print(" V");
  Serial.print("\t");
  
  Serial.print("Direct Voltage (float): ");
  Serial.print(voltage, 4); 
  Serial.println(" V");
  
  delay(500);  
}
