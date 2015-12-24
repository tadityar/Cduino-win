void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop()
{
  if (Serial.available()){
    int incomingByte = Serial.read();
    switch(incomingByte){
      case '1':
        // '1' received through COM port, send 'H' via XBee.
        Serial1.print('H');
        break;
      case'2':
        // '2' received through COM port, send 'L' via XBee.
        Serial1.print('L');
        break;
    }
  }
}
