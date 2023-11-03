# 1 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
# 2 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 2
# 3 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 2




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
    softwareSerialMP3 = new SoftwareSerial(10, 11);

    softwareSerialMP3->begin(9600);
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 24 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 24 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                  "Initializing MP3Player ..."
# 24 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                  ); &__c[0];}))
# 24 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                  )));

    if (!MP3.begin(*softwareSerialMP3, true, false))
    {
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 28 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 28 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                      "Unable to begin:"
# 28 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                      ); &__c[0];}))
# 28 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                      )));
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 29 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 29 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                      "1.Please recheck the connection!"
# 29 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                      ); &__c[0];}))
# 29 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                      )));
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 30 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 30 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                      "2.Please insert the SD card!"
# 30 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                      ); &__c[0];}))
# 30 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                      )));
        while (true)
            ;
    }
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 34 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 34 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                  "MP3Player online."
# 34 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino" 3
                  ); &__c[0];}))
# 34 "C:\\Users\\Charles\\Desktop\\Public Repo\\mp3_busy_pin\\mp3_busy_pin.ino"
                  )));
}
