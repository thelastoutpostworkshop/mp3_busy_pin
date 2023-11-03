#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define RX_PIN 10
#define TX_PIN 11
#define BUSY_PIN 13

DFRobotDFPlayerMini mp3;
SoftwareSerial *softwareSerialMP3;

void setup(void)
{
    Serial.begin(9600);
    initMP3();
    mp3.volume(25);
    mp3.play(1);
}

void loop(void)
{
    int b = digitalRead(BUSY_PIN);
    Serial.print("Busy pin = ");
    Serial.println(b);
}

void initMP3(void)
{
    pinMode(BUSY_PIN,INPUT);
    softwareSerialMP3 = new SoftwareSerial(RX_PIN, TX_PIN);

    softwareSerialMP3->begin(9600);
    Serial.println(F("Initializing MP3Player ..."));

    if (!mp3.begin(*softwareSerialMP3, true, false))
    {
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while (true)
            ;
    }
    Serial.println(F("MP3Player online."));
}