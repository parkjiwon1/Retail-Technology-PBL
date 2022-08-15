#include <Servo.h>

int val;

int servo1_pin = 8;
int servo2_pin = 7;
int main_servo = 4;

int magnet_pin = 13;

Servo servo1;
Servo servo2;
Servo mainservo;

void setup() {
  Serial.begin(9600);

  pinMode(magnet_pin, INPUT);

  mainservo.attach(main_servo);
  mainservo.write(130);
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
}

void loop() {
  val = digitalRead(magnet_pin);

  delay(60);

  Serial.print("\tMagnet Sensor\t"); Serial.println(val);

  if (val == 1 ) { // 조건을 완성하세요. val == 1
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해주세요.
    servo1.write(40);
    servo2.write(40);
    delay(3000);
  }
  
  else {
    servo1.write(90);
    servo2.write(90);
  }
}
