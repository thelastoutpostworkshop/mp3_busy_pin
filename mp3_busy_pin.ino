#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Adafruit_NeoPixel.h>

#define RX_PIN 10
#define TX_PIN 11
#define BUSY_PIN 8

DFRobotDFPlayerMini mp3;
SoftwareSerial *softwareSerialMP3;

// Neopixels
#define PIXELSPIN 7
#define PIXELSCOUNT 14

Adafruit_NeoPixel pixels(PIXELSCOUNT, PIXELSPIN, NEO_GRB + NEO_KHZ800);
#define COLOR_CYAN pixels.Color(0, 255, 255)

void setup(void)
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);
    initMP3();
    initPixels();
    mp3.volume(25);
    mp3.play(7);
    pixels.fill(COLOR_CYAN);
    pixels.show();

    while (readBusyPin() == HIGH)
    {
        /* wait for play sound to start */
    }
    Serial.println("Playing sound...");
    while (readBusyPin() == LOW)
    {
        // digitalWrite(LED_BUILTIN, HIGH);
        // delay(200);
        // digitalWrite(LED_BUILTIN, LOW);
        // delay(200);
        showPixelsRandomLevel();
        delay(60);
    }
    pixels.clear();
    pixels.show();
    Serial.println("Sound finished playing.");
}

void loop(void)
{
}

void initPixels(void)
{
    pixels.begin();
    pixels.setBrightness(100);
    pixels.clear();
    pixels.show();
}

void showPixelsRandomLevel(void)
{
    int level = random(PIXELSCOUNT);
    pixels.clear();
    pixels.show();
    for (int i = 0; i < level; i++)
    {
        pixels.setPixelColor(i, COLOR_CYAN);
    }
    pixels.show();
}

int readBusyPin(void)
{
    int b = digitalRead(BUSY_PIN);
    Serial.print("Busy pin = ");
    Serial.println(b);
    return b;
}

void initMP3(void)
{
    pinMode(BUSY_PIN, INPUT);
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