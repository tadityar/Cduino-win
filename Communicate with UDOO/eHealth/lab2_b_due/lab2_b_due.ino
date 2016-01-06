int pulse = 0;
uint8_t bpm = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(500);
}

void loop() {
  if(Serial1.available()){
  Serial.print(Serial1.read());
  Serial.println();
  delay(490);
  }
}
