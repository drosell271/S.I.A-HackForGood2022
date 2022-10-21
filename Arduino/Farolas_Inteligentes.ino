const int sensorPin[] = {A0, A1, A2, A3, A4};
int counter[5] = {0};

void setup() {

  // put your setup code here, to run once:
  for (int pinNumber = 2; pinNumber < 12; pinNumber++) 
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  // 2 3 4 5 6 7 8 9 10 11
  bool isOn[13] = {false};
  for (int i = 0; i <= 4; i++) 
  {
    int sensorVal = analogRead(sensorPin[i]);
    Serial.print("\nR");
    Serial.print(i);
    Serial.print(":\nSensor Value: ");
    Serial.print(sensorVal);
    if (sensorVal < 400)
    {
      isOn[1 + i * 2] = true;
      isOn[2 + i * 2] = true;
      isOn[3 + i * 2] = true;
      isOn[4 + i * 2] = true;
      counter[i]++;
    }
  }
  for (int i = 0; i < 5; i++)
  {
    Serial.print("\nA");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(counter[i]);
  }
  for (int i = 2; i < 12; i++) 
  {
    digitalWrite(i, (isOn[i]) ? HIGH : LOW);
  }
  Serial.print("\n-------------------\n");
  delay(500);
}
