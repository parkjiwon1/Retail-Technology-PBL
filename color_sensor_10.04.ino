#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Servo.h>

int servo1_pin = 8;
int servo2_pin = 7;
int main_servo = 4;

float red, green, blue;
int color;

Servo servo1;
Servo servo2;
Servo mainservo;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);

  mainservo.attach(main_servo);
  mainservo.write(130);
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  }

  else {
    Serial.println("No found");
    while (1);
  }

}

void loop() {

  tcs.getRGB(&red, &green, &blue);  // 칼라센서 인식
  Color_calibration(int(red), int(green), int(blue));

  Serial.print("\tR:\t"); Serial.print(int(red));
  Serial.print("\tG:\t"); Serial.print(int(green));
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.print("\n");


  // if문을 완성해 보세요.

  if ( color == 'r' ) {  // 조건을 완성하세요. color ='r'
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해 주세요.
    servo1.write(30);
    servo2.write(30);
    Serial.println("\tColor : Red");
    delay(3000);
  }
  else if  ( color == 'y' ) {  // 조건을 완성하세요. color ='r'
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해 주세요.
    servo1.write(140);
    servo2.write(140);
    Serial.println("\tColor : Yellow");
    delay(3000);
  }
  else if  ( color == 'b' ) {  // 조건을 완성하세요. color ='r'
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해 주세요.
    servo1.write(90);
    servo2.write(90);
    Serial.println("\tColor : Blue");
    delay(3000);
  }
  else {
    servo1.write(90);
    servo2.write(90);
    Serial.println("\tColor : Nothing");
  }
}


void Color_calibration(int r, int g, int b) { // 학교 현장에 맞춰서 다시 수정해 주세요.
  if ( r > 121  && g < 65 && b < 60 ) {
    color = 'r';
  }
  else if ( r < 120 && r > 100 && g > 55 && g < 90 && b < 60 ) {
    color = 'y';
  }
  else if ( r < 70  && g > 80 && g < 90 && b > 80 && b < 90 ) {
    color = 'b';
  }
  else {
    color = 'n';
  }
}
