#include "EEPROM.h"
int addr = 0;
#define EEPROM_SIZE 64


void writetoeeprom(char ssid[64])
{
    // the sample text which we are storing in EEPROM
    if (!EEPROM.begin(EEPROM_SIZE))
    {
        Serial.println("failed to init EEPROM");
        delay(10000);
    }

    // writing byte-by-byte to EEPROM
    for (int i = 0; i < EEPROM_SIZE; i++)
    {
        EEPROM.write(addr, ssid[i]);
        addr += 1;
    }
    EEPROM.commit();
    Serial.println("Wrote ");
    Serial.print(ssid);
    Serial.print(" to eeprom");
}
char [64] readfromeeprom(){
    // reading byte-by-byte from EEPROM
    for (int i = 0; i < EEPROM_SIZE; i++)
    {
        byte readValue = EEPROM.read(i);

        if (readValue == 0)
        {
            break;
        }

        char readValueChar = char(readValue);
        Serial.print(readValueChar);
        return readValueChar;
    }

}
