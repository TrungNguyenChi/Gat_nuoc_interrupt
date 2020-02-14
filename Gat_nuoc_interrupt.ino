#include <Servo.h>

Servo sv;
int btn1 = 2;
int btn2 = 3;
int btnStatus1 = 0, btnStatus2 = 0;
int stt = 0;
void updateState1()
{
  if(stt == 0)
  {
    stt = 1;
    delay(200);
  }
  else 
  {
    stt = 0;
    delay(200);
  }
  Serial.println(stt);
}
void updateState2()
{
  if(stt != 0)
  {
    stt += 1;
    if(stt >3)
    {
      stt = 1;
    } 
    delay(200);
  }
  Serial.println(stt);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, updateState1, RISING);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(1, updateState2, RISING);
  sv.attach(9);
  Serial.begin(9600);
}
void turnTo(int angle)
{
  int pos = 0;
  for(pos = 0; pos < angle; pos += 2)
  {                                  // mỗi bước của vòng lặp tăng 1 độ
    sv.write(pos);              // xuất tọa độ ra cho servo
    delay(10);                       // đợi 10 ms cho servo quay đến góc đó rồi tới bước tiếp theo
  } 
}

void turnBack(int angle)
{
  int pos = 0;
  for(pos = angle; pos>=1; pos-=2 )     
  {                                
    sv.write(pos);              // xuất tọa độ ra cho servo
    delay(10);                       // đợi 15 ms cho servo quay đến góc đó rồi tới bước tiếp theo
  } 
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(stt);
  if(stt == 1)
  {
    //sv.write(133);
    turnTo(133);
    delay(5000);
    turnBack(133);
    //sv.write(0);
  }
  else if (stt == 2)
  {
    //sv.write(133);
    turnTo(133);
    delay(3000);
    turnBack(133);
    //sv.write(0);
  }
  else if (stt == 3)
  {
    //sv.write(133);
    turnTo(133);
    delay(1000);
    turnBack(133);
    //sv.write(0);
  }
  delay(200);
}
