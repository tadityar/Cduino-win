#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>

#include <eHealth.h>
#include <eHealthDisplay.h>

int cont = 0;
uint8_t bpm = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  eHealth.initPulsioximeter();
  pinMode(13, OUTPUT);
  // Attach the interruptions for using the pulsioximeter.
  PCintPort::attachInterrupt(6, readPulsioximeter, RISING);
}

void loop() {
    /*int bpm = eHealth.getBPM(); // get heart beats per minute
    Serial.print(bpm); // print heart beats per minute and send value to XBee module
    delay(490);*/
    Serial.print(1);
    int incomingByte = Serial.read();
    switch (incomingByte)
    {
      case '1':
        digitalWrite(13, HIGH);
        break;
      case '2':
        digitalWrite(13, LOW);
        break;
    }
}

//Always include this code when using the pulsioximeter sensor
//=========================================================================

void readPulsioximeter(){
  cont ++;
  if (cont == 10)
  {
    eHealth.readPulsioximeter();
    cont = 0;
  }
}
