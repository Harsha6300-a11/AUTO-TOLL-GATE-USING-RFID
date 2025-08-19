🚦 Auto Toll Gate System using RFID, Servo Motor, and IR Sensor

This project demonstrates an automatic toll gate system built with Arduino, RFID, Servo motor, LEDs, and an IR sensor.
It allows vehicles with authorized RFID cards to pass, while unauthorized cards are denied.

📸 Project Overview :

RFID Module (RC522) reads the card/tag UID.

Arduino Uno processes the UID.

Servo Motor acts as the toll gate barrier.

Green LED indicates Access Granted.

Red LED indicates Access Denied.

IR Sensor detects when the vehicle passes, and then the gate closes automatically.

 Components Required
  Component	Quantity
    Arduino Uno/Nano	1
    RFID Module RC522	1
    RFID Card/Tag	1+
    Servo Motor	1
    IR Sensor Module	1
    LED (Green)	1
    LED (Red)	1
    Resistors (220Ω)	2
    Jumper Wires	-
    Breadboard	1

RFID RC522  →  Arduino
SDA (SS)    →  Pin 10
RST         →  Pin 9
MOSI        →  Pin 11
MISO        →  Pin 12
SCK         →  Pin 13

Servo       →  Pin 6
IR Sensor   →  Pin 7
LED Green   →  Pin 3
LED Red     →  Pin 4

💻 Code

The full Arduino code is available in Auto_Toll_Gate.ino
.
It includes:

RFID card UID verification

Gate opening/closing with servo

LED indicators

IR sensor vehicle detection

🔑 Features

✅ Reads RFID card UID
✅ Grants/Deny access based on UID
✅ Controls servo motor as toll gate
✅ Green LED for Access Granted
✅ Red LED for Access Denied
✅ IR sensor closes gate after vehicle passes

📊 Workflow

Vehicle approaches toll gate.

RFID card is scanned.

If UID matches → Gate opens, Green LED ON.

IR sensor waits until vehicle passes → Gate closes.

If UID does not match → Red LED ON, access denied.
