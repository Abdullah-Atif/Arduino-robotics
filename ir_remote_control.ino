#include <IRremote.h>
IRrecv IR(3);
const int r_ena=10;
const int l_ena=11;
const int r_in1=9;
const int r_in2=8;
const int l_in3=7;
const int l_in4=6;
int speeds=255, data=0;
void setup() {
  pinMode(r_ena,OUTPUT);
  pinMode(r_in1,OUTPUT);
  pinMode(r_in2,OUTPUT);
  pinMode(l_ena,OUTPUT);
  pinMode(l_in3,OUTPUT);
  pinMode(l_in4,OUTPUT);
  digitalWrite(r_in1,LOW);
  digitalWrite(r_in2,LOW);
  digitalWrite(l_in3,LOW); 
  digitalWrite(l_in4,LOW);
  analogWrite(r_ena,0);
  analogWrite(l_ena,0);
  // put your setup code here, to run once:
  IR.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(IR.decode())
   {
      Serial.println( IR.decodedIRData.decodedRawData, HEX);
      if(IR.decodedIRData.decodedRawData== 0xF30CFF00)
      {
          forward();
          delay(2000);
          backward();
      }
      if(IR.decodedIRData.decodedRawData== 0xBF40FF00)
      {
          rightward();
          delay(2000);
          backward();
      }
      if(IR.decodedIRData.decodedRawData== 0xBB44FF00)
      {
          leftward();
          delay(2000);
          backward();
      }
      if(IR.decodedIRData.decodedRawData== 0xE916FF00)
      {
          backward();
      }
      delay(1500);
      IR.resume();
   }
}
void backward(){
  digitalWrite(r_in1,HIGH);
  digitalWrite(r_in2,LOW);
  digitalWrite(l_in3,HIGH); 
  digitalWrite(l_in4,LOW);
  analogWrite(r_ena,0);
  analogWrite(l_ena,0);
}
 
void forward(){
  digitalWrite(r_in1,LOW);
  digitalWrite(r_in2,HIGH);
  digitalWrite(l_in3,LOW); 
  digitalWrite(l_in4,HIGH);
  analogWrite(r_ena,speeds);
  analogWrite(l_ena,speeds);
}
 
void rightward(){
  digitalWrite(r_in1,HIGH);
  digitalWrite(r_in2,LOW);
  digitalWrite(l_in3,LOW); 
  digitalWrite(l_in4,HIGH);
  analogWrite(r_ena,speeds);
  analogWrite(l_ena,speeds);
}
 
void leftward(){
  digitalWrite(r_in1,LOW);
  digitalWrite(r_in2,HIGH);
  digitalWrite(l_in3,HIGH); 
  digitalWrite(l_in4,LOW);
  analogWrite(r_ena,speeds);
  analogWrite(l_ena,speeds);
}
