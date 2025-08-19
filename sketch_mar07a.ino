#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

//Auto Toll Gate System using RFID & Servo Motor with LED Indicators 
#include <SPI.h>
//#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define IR_SENSOR 7
#define SERVO_PIN 6
#define LED_GREEN 3  // Access Granted LED
#define LED_RED 4    // Access Denied LED

MFRC522 rfid(SS_PIN, RST_PIN);
Servo gate;

// Predefined valid RFID card UID
byte validUID[] = {0x6A, 0x6A, 0x28, 0x03};  // Replace with your card's UID

void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
    gate.attach(SERVO_PIN);
    pinMode(IR_SENSOR, INPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
    gate.write(0);  // Keep gate closed at the start
}

bool compareUID(byte *cardUID, byte *validUID, int length) {
    for (int i = 0; i < length; i++) {
        if (cardUID[i] != validUID[i]) return false;
    }
    return true;
}

void loop() {
  while(1)
  {
       if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

    Serial.print("Card UID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print(" ");
    }
    Serial.println();
  
   if (compareUID(rfid.uid.uidByte, validUID, sizeof(validUID))) {
        Serial.println("Access Granted");
        digitalWrite(LED_GREEN, HIGH);  // Turn ON Green LED
        digitalWrite(LED_RED, LOW);
        gate.write(90);  // Open gate
        delay(2000);

        while (digitalRead(IR_SENSOR) == HIGH);  // Wait until vehicle passes
        gate.write(0);  // Close gate
        digitalWrite(LED_GREEN, LOW);  // Turn OFF Green LED
    } else {
        Serial.println("Access Denied");
        digitalWrite(LED_RED, HIGH);  // Turn ON Red LED
        delay(2000);
        digitalWrite(LED_RED, LOW);  // Turn OFF Red LED
    }
  }

    rfid.PICC_HaltA();
}
