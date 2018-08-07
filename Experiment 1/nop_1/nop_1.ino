// Pulse A2 and read all 16 bit values from 6502's address bus
#define CLOCK 52
#define SYNC 50
#define RWB 51 
#define A0 22
#define A1 23
#define A2 24
#define A3 25
#define A4 26
#define A5 27
#define A6 28
#define A7 29
#define A8 30
#define A9 31
#define A10 32
#define A11 33
#define A12 34
#define A13 35
#define A14 36
#define A15 37


void setup() {
    pinMode(CLOCK, OUTPUT);
    digitalWrite(CLOCK, LOW);
    Serial.begin(115200);
    delay(500);
//    digitalWrite(CLOCK, HIGH);
//    delay(100);
//    digitalWrite(CLOCK, LOW);
//    delay(100);
//    digitalWrite(CLOCK, HIGH);
//    delay(100);
//    digitalWrite(CLOCK, LOW);
}

void loop() {
    digitalWrite(CLOCK, LOW);
    delay(100);
    digitalWrite(CLOCK, HIGH);

    // read value on address bus
    byte a0 = digitalRead(A0);
    byte a1 = digitalRead(A1);
    byte a2 = digitalRead(A2);
    byte a3 = digitalRead(A3);
    byte a4 = digitalRead(A4);
    byte a5 = digitalRead(A5);
    byte a6 = digitalRead(A6);
    byte a7 = digitalRead(A7);
    byte a8 = digitalRead(A8);
    byte a9 = digitalRead(A9);
    byte a10 = digitalRead(A10);
    byte a11 = digitalRead(A11);
    byte a12 = digitalRead(A12);
    byte a13 = digitalRead(A13);
    byte a14 = digitalRead(A14);
    byte a15 = digitalRead(A15);


    byte address_value_low  = a7 << 7;
    address_value_low  += a6 << 6;
    address_value_low  += a5 << 5;
    address_value_low  += a4 << 4;
    address_value_low  += a3 << 3;
    address_value_low  += a2 << 2;
    address_value_low  += a1 << 1;
    address_value_low  += a0;

    byte address_value_high  = a15 << 7;
    address_value_high  += a14 << 6;
    address_value_high  += a13 << 5;
    address_value_high  += a12 << 4;
    address_value_high  += a11 << 3;
    address_value_high  += a10 << 2;
    address_value_high  += a9 << 1;
    address_value_high  += a8;
    // display value

    //Little Endian LOW -> end HIGH -> front
    //Serial.print("Address bus : ");
    Serial.print(a15); 
    Serial.print(a14);
    Serial.print(a13);
    Serial.print(a12);
    Serial.print(a11);
    Serial.print(a10);
    Serial.print(a9);
    Serial.print(a8);
    Serial.print(' ');
    Serial.print(a7);
    Serial.print(a6);
    Serial.print(a5);
    Serial.print(a4);
    Serial.print(a3);
    Serial.print(a2);
    Serial.print(a1);
    Serial.print(a0);
    Serial.print(" : 0x");
    Serial.print(address_value_high, HEX);
    Serial.print(" 0x");
    Serial.print(address_value_low, HEX);
    Serial.print("    RWB: ");
    Serial.print(digitalRead(RWB));
    Serial.print("    SYNC: ");
    Serial.print(digitalRead(SYNC));
    Serial.println();
}
