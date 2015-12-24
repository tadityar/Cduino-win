const int ledPin = 13;

int pulse = 0;
uint8_t bpm = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(ledPin, OUTPUT);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly: 
  /*if (Serial.available())
  {
    bpm = Serial1.read();
    Serial.print(bpm);
  }
  if (Serial.available())
  {
    int incomingBytes = Serial.read();
    switch (incomingBytes)
    {
      case '1': 
        digitalWrite(ledPin, HIGH);
        Serial1.print('1');
        break;
      case '2':
        digitalWrite(ledPin, LOW);
        Serial1.print('2');
        break;
    }
  }*/
  Serial.print((char)Serial1.read());
  delay(100);
  
}
