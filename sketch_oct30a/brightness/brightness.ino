
const int potPin = A0;    
const int ledPin = 9;     

int potValue = 0;         
int brightness = 0;       

void setup() {
  pinMode(ledPin, OUTPUT);
  
  
  Serial.begin(9600);
  Serial.println("LED Brightness Control");
  Serial.println("---------------------");
}

void loop() {

  potValue = analogRead(potPin);
  

  brightness = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, brightness);
  
  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print("\t");
  Serial.print("Brightness: ");
  Serial.println(brightness);
  
  delay(100);
}