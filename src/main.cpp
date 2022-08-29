#include <Arduino.h>
#include <ArrayShifter.h>

ArrayShifter array;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){}
  
}

void loop() {
  
  if(Serial.available()>0)
  {
    Serial.println(array.getArrayData(0));
    int sizeOption2 = array.getSize();
    Serial.println(sizeOption2);
    array.removeArrayItem(0);
    Serial.println(array.getArrayData(0));

  }
}