#include <Servo.h>
Servo myServo; int echo =5,trig=4;
void setup()
{
  Serial.begin(9600);
  myServo.attach(8);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}

void loop()
{
  Serial.println(distance_Function(echo,trig));
  if(distance_Function(echo,trig)<30)
  {
    myServo.write(90);
    delay(2000);
  }
  else
  {
    myServo.write(0);
  }
}
\things\1Y78YTxFQTK-glorious-gaaris\editel
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