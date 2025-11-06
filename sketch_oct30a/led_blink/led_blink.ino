const int ledPin = 13;  

void setup() {
  
  pinMode(ledPin, OUTPUT);
}
void loop() {
  digitalWrite(ledPin, HIGH);
 
  delay(1000);

  digitalWrite(ledPin, LOW);
  
  delay(1000);
}
// LED Blink Program without delay()
// This program blinks an LED using millis() for non-blocking timing

const int ledPin = 13; 
unsigned long previousMillis = 0;  
const long interval = 1000;         
int ledState = LOW;  

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}