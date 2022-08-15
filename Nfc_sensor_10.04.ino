#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

int nfc_data [48] = {4, 77, 243, 242, 4, 200, 229, 58, 4, 6, 61, 98,
                     4, 123, 229, 58, 4, 38, 225, 58, 4, 22, 62, 98,
                     4, 56, 61, 98, 4, 5, 225, 58, 4, 162, 227, 58,
                     4, 213, 227, 58, 4, 182, 228, 58, 4, 46, 63, 98
                    };

String nfc_val [12] = { "D1", "D2", "D3",  "G1", "G2", "G3",  "L1", "L2", "L3",  "M1", "M2", "M3"};

int RST_PIN  = 9;
int SS_PIN = 10;

int servo1_pin = 8;
int servo2_pin = 7;
int main_servo = 4;

String nfc;

Servo servo1;
Servo servo2;
Servo mainservo;

MFRC522 mfrc(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);

  SPI.begin();
  mfrc.PCD_Init();

  mainservo.attach(main_servo);
  mainservo.write(130);
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  }

void loop() {
  if (!mfrc.PICC_IsNewCardPresent()   // RFID NFC 인식
      || !mfrc.PICC_ReadCardSerial()) {
    delay(500);
    return;
  }
  for (int i = 0; i < 48; i+=4) {   // RFID NFC 판단(숫자로 변환)
    if (mfrc.uid.uidByte[0] == nfc_data[i] && mfrc.uid.uidByte[1] == nfc_data[i + 1] && mfrc.uid.uidByte[2] == nfc_data[i + 2] && mfrc.uid.uidByte[3] == nfc_data[i + 3]) {
      nfc = nfc_val[i / 4];
      Serial.print("nfc : ");
      Serial.println(nfc);
    }
  }

  // if문을 완성해 보세요.

  if ( nfc == "G1"  ) {  // 조건을 완성하세요. nfc ==  "D1" 
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해주세요.
    servo1.write(45);
    servo2.write(45);
    delay(3000);
    servo1.write(90);
    servo2.write(90);
  }
  else if  ( nfc == "G2" ) { // 조건을 완성하세요. nfc ==  "D1" 
    //실행내용을 입력하세요.
    //작동 후 delay를 주어 물건이 컨베이어벨트를 지나갈 수 있도록 유도해주세요.
    servo1.write(140);
    servo2.write(140);
    delay(3000);
    servo1.write(90);
    servo2.write(90);
  }
  else {
    servo1.write(90);
    servo2.write(90);
  }
}
