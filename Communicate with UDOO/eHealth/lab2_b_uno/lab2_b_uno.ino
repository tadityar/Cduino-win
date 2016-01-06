//download the eHealth library from 
//https://www.cooking-hacks.com/documentation/tutorials/ehealth-biometric-sensor-platform-arduino-raspberry-pi-medical#step3_1


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
  // Attach the interruptions for using the pulsioximeter.
  PCintPort::attachInterrupt(6, readPulsioximeter, RISING);
  delay(1000);
}

void readPulsioximeter(){
  cont ++;
  if (cont == 10)
  {
    eHealth.readPulsioximeter();
    cont = 0;
  }
}


void loop() {
    int bpm = eHealth.getBPM(); // get heart beats per minute
    Serial.print(bpm); // print heart beats per minute and send value to XBee module
    Serial.println();
    delay(490);
}
