#include <Wire.h>

#define SLAVE_ADDRESS 0x04
//int number = 0;
int state = 0;
int n=0;
int cmd[3]={0,0,0};
byte output[5]={2,2,2,2,2};
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
delay(200);
}

void receiveData(int byteCount){
while(Wire.available()) {
cmd[0] = Wire.read();
cmd[1] = Wire.read();
cmd[2] = Wire.read();
}
movement();
}
void movement()
{
  if(cmd[0]>=8 && cmd[0]<=12 && cmd[1]>=15 && cmd[1]<=20)
  {
   Serial.println("Forward");
  Serial.print("PWM:  ");
  Serial.println(cmd[2]);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  }
  else if(cmd[0]==10 && cmd[1]==10)
  {
    Serial.println("Stop");
    Serial.print("PWM:  ");
    Serial.println(cmd[2]);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
  else if(cmd[0]>=9 && cmd[0]<=11 && cmd[1]>=0 && cmd[1]<=5)
  {
    Serial.println("Back");
    Serial.print("PWM:");
    Serial.println(cmd[2]);
    
  }
  else if(cmd[0]==2 && cmd[1]==10)
   {
    Serial.println("Left");
    Serial.print("PWM:  ");
    Serial.println(cmd[2]);
  }
  else if(cmd[0]==18 && cmd[1]==10)
  {
    Serial.println("Right");
    Serial.print("PWM:  ");
    Serial.println(cmd[2]);
  }
  else if(cmd[0]>=16 && cmd[0]<=18 && cmd[1]>=15 && cmd[1]<=20)
  {
    Serial.println("only left forward");
    Serial.print("PWM:  ");
    Serial.println(cmd[2]);
    Serial.print(cmd[2]);
  }
  else if(cmd[0]>=2 && cmd[0]<=4 && cmd[1]>=15 && cmd[1]<=20)
  {
    Serial.println("only right forward");
    Serial.print("PWM:  ");
    Serial.println(cmd[2]);
  }
  else if(cmd[0]>=16 && cmd[0]<=18 && cmd[1]>=0 && cmd[1]<=5)
  {
    Serial.println("only left back");
    Serial.print("PWM:  ");
    Serial.println(cmd[2]);
  }
  else if(cmd[0]>=2 && cmd[0]<=4 && cmd[1]>=0 && cmd[1]<=5)
 {
    Serial.println("only right back");
    Serial.print("PWM:  ");
    Serial.println(cmd[2]);
  }
  /*else
  {
    Serial.println("***");
    Serial.println(cmd[0]);
    Serial.println(cmd[1]);
    Serial.println(cmd[2]);
    Serial.println("***");
  }*/
}


void sendData(){

  //Serial.println("THE RPM DATA IS SENT");
  //for(int i=0;i<5;i++)
    //output[i]=Serial.read()-48;
  //Wire.write(output,5);
  //Serial.println("Data Sent");
  
}
