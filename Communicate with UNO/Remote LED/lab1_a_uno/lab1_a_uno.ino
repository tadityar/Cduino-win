#include <SoftwareSerial.h>

// Initialize another serial because Serial will be used to communicate through COM port.
SoftwareSerial XBee(2,3);

void setup()
{
  Serial.begin(9600);
  XBee.begin(9600);
}

void loop()
{
  if (Serial.available()){
    int incomingByte = Serial.read();
    switch(incomingByte){
      case '1':
        // '1' received through COM port, send 'H' via XBee.
        XBee.print('H');
        break;
      case'2':
        // '2' received through COM port, send 'L' via XBee.
        XBee.print('L');
        break;
    }
  }
}
