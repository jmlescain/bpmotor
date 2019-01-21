#include <ADCTouch.h>

int ref0, ref1, ref2; //Reference values to take account the foil's own capacitance

void setup(){
    Serial.begin(9600);

    ref0 = ADCTouch.read(A1, 500);
    ref1 = ADCTouch.read(A2, 500);

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
}

void loop(){
    int up, down;

    int upTouch = ADCTouch.read(A1) - ref0;
    int downTouch = ADCTouch.read(A2) - ref1;

    int infrared = analogRead(A3);
    int battery_level = analogRead(A0);

    battery_level = (battery_level - 640) * 100 / 307; 

    Serial.print(up);
    Serial.print("\t\t");
    Serial.print(down);
    Serial.print("\t\t");

    Serial.print(upTouch);
    Serial.print("\t\t");
    Serial.print(downTouch);
    Serial.print("\t\t");

    Serial.print(infrared);
    Serial.print("\t\t");

    Serial.print(battery_level);

    Serial.print("\n");

    if (upTouch > 40) {
        up = 1;
        down = 0;
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
    } else
    if ( downTouch > 40) {
        down = 1;
        up = 0;
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
    }

    if (infrared > 15) {
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
    } else {
        digitalWrite(4, LOW);
    }
}