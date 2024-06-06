//LDR sensor
int light=9; //pwm pin
void setup()
{
   Serial.begin(9600);
   pinMode (light, OUTPUT);
}

void loop()
  {
  int resistance=analogRead(A0);   //for analog pin
  Serial.println(resistance);
  if (resistance<400)
  { 
    digitalWrite(light, HIGH); 
    delay(1000);
  }

  else{
   digitalWrite(light, LOW);
  }
}
