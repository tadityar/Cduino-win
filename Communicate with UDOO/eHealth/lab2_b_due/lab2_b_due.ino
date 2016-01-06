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
  Serial.print((char)Serial1.read());
  delay(490);
}
