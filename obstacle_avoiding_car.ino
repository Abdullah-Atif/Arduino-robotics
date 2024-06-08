

#include <Servo.h>
Servo myServo; int echo =5,trig=4,x=1,y=200;
const int r_ena=10;
const int l_ena=11;
const int r_in1=9;
const int r_in2=8;
const int l_in3=7;
const int l_in4=6;
int speeds=255, data=0;
void setup()
{
  Serial.begin(9600);
  myServo.attach(13);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
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
  myServo.write(90);
}

void loop()
{
 /* forward();
  delay(5000);
  backward();
  delay(5000);
  leftward();
  delay(5000);
  rightward();
  delay(5000);*/

  Serial.println(distance_Function(echo,trig));
  if(distance_Function(echo,trig)<30)
  {
   
    if(x==1)
    {
     // delay(2000);
      myServo.write(135);
      //backward();
      leftward();
      delay(y);
      x=x+1;
    }
    if(x==2)
    {
     // delay(2000);
      myServo.write(180);
      //backward();
      leftward();
      delay(y);
      x=x+1;
    }
    if(x==3)
    {
    //  delay(2000);
      myServo.write(45);
     // backward();
      rightward();
      delay(y);
      x=x+1;
    }
    if(x==4)
    {
    //  delay(2000);
      myServo.write(0);
      //backward();
      rightward();
      delay(y);
      x=x+1;
    }
    if(x==5)
     x=1;
    
    //delay(2000);
  }
  else
  {
    
      myServo.write(90);
      forward();
      x=1;
   
}
}

int distance_Function(int echo,int trig)
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  int duration=pulseIn(echo,HIGH);
  int distance=0.034*duration/2;
  return distance;
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
