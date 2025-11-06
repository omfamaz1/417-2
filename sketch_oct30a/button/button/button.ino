const int buttonPin = 2;
const int ledPin = 13;

volatile int clickCount = 0;
volatile bool buttonFlag = false;  

volatile unsigned long lastInterruptTime = 0;
const unsigned long debounceDelay = 250; 

void setup() {
  Serial.begin(9600);
  Serial.println("Button Click Counter - Working ISR");
  Serial.println("----------------------------------");
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  // Sadece buton basıldığında (FALLING)
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}
void loop() {
  if (buttonFlag) {
    buttonFlag = false;  
    
    while (digitalRead(buttonPin) == LOW) {
    }
    
    delay(50);
    
    Serial.print("Button Clicks: ");
    Serial.println(clickCount);
  }
}
void buttonISR() {
  unsigned long interruptTime = millis();
  
  if (interruptTime - lastInterruptTime > debounceDelay) {
    clickCount++;
    buttonFlag = true;
    lastInterruptTime = interruptTime;
  }
}