// C++ code
//
int red=13,blue=12,green=11;
void setup()
{
  pinMode(red,OUTPUT); // output at 13 pin 
  pinMode(blue,OUTPUT);//output at 12 pin 
  pinMode(green,OUTPUT);//output at 11 pin 
}

void loop()
{
   rgb();  //rgb function call
  yellow();//yellow function call
}

void rgb()   //rgb function
{
digitalWrite(red,HIGH); //13 pin er moddhe 5v output dibe
delay(1000);
digitalWrite(red,LOW);//13 pin er moddhe 0v output dibe
delay(1000);
digitalWrite(blue,HIGH);
delay(1000);
digitalWrite(blue,LOW);
delay(1000);
digitalWrite(green,HIGH);
delay(1000);
digitalWrite(green,LOW);
delay(1000);
}


void yellow()
{
digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(1000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);
delay(1000);
}
