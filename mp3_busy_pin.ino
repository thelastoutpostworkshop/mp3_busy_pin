#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define RX_PIN 10
#define TX_PIN 11

DFRobotDFPlayerMini MP3;
SoftwareSerial *softwareSerialMP3;

void setup(void)
{
    Serial.begin(9600);
}

void loop(void)
{
}

void initMP3(void)
{
    softwareSerialMP3 = new SoftwareSerial(RX_PIN, TX_PIN);

    softwareSerialMP3->begin(9600);
    Serial.println(F("Initializing MP3Player ..."));

    if (!MP3.begin(*softwareSerialMP3, true, false))
    {
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while (true)
            ;
    }
    Serial.println(F("MP3Player online."));
}