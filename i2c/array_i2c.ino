#include <Wire.h>

#define SLAVE_ADDRESS 0x04
//int number = 0;
int state = 0;
int n=0;
int cmd[2]={0,0};
byte output[6]={1,2,3,4,5,6};
int x = 0;

void setup() {
Serial.begin(9600); 
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Wire.begin(SLAVE_ADDRESS);
Wire.onReceive(receiveData);
Wire.onRequest(sendData);

Serial.println("Ready!");
}
void loop() {
delay(100);
}

void receiveData(int byteCount){
while(Wire.available()) {
cmd[0] = Wire.read();
cmd[1] = Wire.read();
}
movement();
}
void movement()
{
  if(cmd[0]==1&&cmd[1]==1)
  {
  Serial.println("Forward");
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  }
  else if(cmd[0]==0&&cmd[1]==0)
  {
  Serial.println("Stop");
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  }
  else if(cmd[0]==2&&cmd[1]==2)
  Serial.println("Back");
  else if(cmd[0]==2&&cmd[1]==1)
  Serial.println("Left");
  else if(cmd[0]==1&&cmd[1]==2)
  Serial.println("Right");
  else if(cmd[0]==1&&cmd[1]==0)
  Serial.println("only left forward");
  else if(cmd[0]==0&&cmd[1]==1)
  Serial.println("only right forward");
  else if(cmd[0]==2&&cmd[1]==0)
  Serial.println("only left back");
  else if(cmd[0]==0&&cmd[1]==2)
  Serial.println("only right back");
}


void sendData(){

  Serial.println("THE RPM DATA IS SENT");
  Wire.write(output,6);
  
}
