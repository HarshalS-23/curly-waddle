#include <EEPROM.h>
int address = 0;
int count;
int flag = 0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  int storedValue = EEPROM.read(address);
  if (storedValue == 0 || storedValue == 255) { 
    count = 30; 
    EEPROM.write(address, count); 
    Serial.println("Initial count=30");
  } else {
    count = storedValue; 
   // Serial.print("Read count from EEPROM: ");
    //Serial.println(count);
  }
  
 
  //Serial.print("Initial count value from EEPROM: ");
  Serial.println(count);
}

void loop() {
  if (flag == 0) {
    if (count == 0) {
      digitalWrite(LED_BUILTIN, HIGH);
      flag = 1;
    } else {
      delay(1000);
      count = count - 1;
      //Serial.println(count);

      
      EEPROM.write(address, count);
      //Serial.print("Updated count written to EEPROM: ");
      Serial.println(count);
    }
  }
}
