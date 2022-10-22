#include <SoftwareSerial.h>
SoftwareSerial esp(12, 13);
const int sensorPin[] = {A0, A1, A2, A3, A4};
int counter[5] = {0};

#define MODE "SERVER"

void setup() {

  // put your setup code here, to run once:
  for (int pinNumber = 2; pinNumber < 12; pinNumber++) 
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
  Serial.begin(115200);
  esp.begin(9600);
  while (!Serial) continue;
  String msg;

  while (msg = esp.readString())
  {
    msg.trim();
    esp.println(msg);
    if (msg == "OK") {
      Serial.println("OK Received to Arduino");
      break;
    }
    esp.println("SET MODE SERVER");
    delay(1000);
  }
}

void server() {
  // 2 3 4 5 6 7 8 9 10 11
  // bool isOn[13] = {false};
  // for (int i = 0; i <= 4; i++) 
  // {
  //   int sensorVal = analogRead(sensorPin[i]);
  //   // Serial.print("\nR");
  //   // Serial.print(i);
  //   // Serial.print(":\nSensor Value: ");
  //   // Serial.print(sensorVal);
  //   if (sensorVal < 400)
  //   {
  //     isOn[1 + i * 2] = true;
  //     isOn[2 + i * 2] = true;
  //     isOn[3 + i * 2] = true;
  //     isOn[4 + i * 2] = true;
  //     counter[i]++;
  //   }
  // }
  esp.print("[");
  for (int i = 0; i <= 0; i++)
  {
    esp.print("{\"id\":");
    esp.print(i);
    esp.print(",\"state\":");
    esp.print(analogRead(sensorPin[i])<400 == 1 ? "true" : "false");
    esp.print("}");
    esp.print(i < 4 ? "," : "");
  }
  esp.println("]");
  Serial.print("[");
  for (int i = 0; i <= 0; i++)
  {
    Serial.print("{\"id\":");
    Serial.print(i);
    Serial.print(",\"state\":");
    Serial.print(analogRead(sensorPin[i])<400 == 1 ? "true" : "false");
    Serial.print("}");
    Serial.print(i < 4 ? "," : "");
  }
  Serial.println("]");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (MODE == "SERVER") {
    server();
  // }

  // for (int i = 0; i < 5; i++)
  // {
  //   Serial.print("\nA");
  //   Serial.print(i);
  //   Serial.print(": ");
  //   Serial.println(counter[i]);
  // }
  // for (int i = 2; i < 12; i++) 
  // {
  //   digitalWrite(i, (isOn[i]) ? HIGH : LOW);
  // }
  delay(500);
}
