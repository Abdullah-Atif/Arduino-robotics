int sensor=A0,red=7,blue=6,green=5;
void setup() {
 Serial.begin(9600) ; // put your setup code here, to run once:
 pinMode(red,OUTPUT);
 pinMode(blue,OUTPUT);
 pinMode(green,OUTPUT);
}

void loop() {
  int moisture=analogRead(sensor);
  Serial.println(moisture);
  if(moisture>=0 && moisture<=300)
  {
    Red();
  }
  if(moisture >300 &&  moisture<=600)
  {
    Yellow();
  }
  if(moisture>600)
  {
    Green();
  }
  // put your main code here, to run repeatedly:

}
void Red()
{
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);

}
void Yellow()
{
  digitalWrite(red,HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(green,LOW);

}
void Green()
{
  digitalWrite(red,HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(green,HIGH);

}
