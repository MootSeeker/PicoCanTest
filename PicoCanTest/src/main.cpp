#include <Arduino.h>
#include <math.h>


#include "can.h"

unsigned int id;
const unsigned int id_max = pow(2, 11) - 1;

void setup( ) 
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);

   Serial.println("CAN SENDER init...");
  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) 
  {
    Serial.println("CAN init failed");
    while (1);
  }
  Serial.println("CAN init successful");
  delay(1000);

}

void loop( ) 
{
  id = (id + 4) % id_max;

  CAN.beginPacket(id+1);
  CAN.write('H');
  CAN.write('e');
  CAN.write('l');
  CAN.write('l');
  CAN.write('o');
  CAN.endPacket();

  CAN.beginPacket(id+3);
  CAN.write('O');
  CAN.write('d');
  CAN.write('d');
  CAN.endPacket();

  Serial.println("...Hello World sent!");
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(500);
}




