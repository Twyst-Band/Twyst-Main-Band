#include "serial.h"

void initSerial()
{
    Serial.begin(BAUDRATE);

    while (!Serial) {
        delay(10);
    }
}