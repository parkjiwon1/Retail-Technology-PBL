#include <Servo.h>

int trigPin = 10;
int echoPin = 9;

long duration;
float cm;

int servo1_pin = 8;
int servo2_pin = 7;
int main_servo = 4;

Servo servo1;
Servo servo2;
Servo mainservo;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  mainservo.attach(main_servo);
  mainservo.write(130);
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;

  delay(150);

  Serial.print("cm: "); Serial.println(cm);
  
  if ( cm >= 4 && cm <= 7 ) { // 조건을 완성하세요. cm >= 4 && cm <= 6
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해 주세요.
    servo1.write(45);
    servo2.write(45);
    delay(3000);
  }
  else if ( cm >= 7.5 && cm <= 9.5 ) { // 조건을 완성하세요. cm >= 7 && cm <= 9
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해 주세요.
    servo1.write(90);
    servo2.write(90);
    delay(3000);
  }
  else {
    servo1.write(90);
    servo2.write(90);
  }
}
