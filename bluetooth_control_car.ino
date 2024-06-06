const int r_ena=10;
const int l_ena=9;
const int r_in1=8;
const int r_in2=7;
const int l_in3=12;
const int l_in4=13;
int speeds=255, data=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(r_ena,OUTPUT);
  pinMode(r_in1,OUTPUT);
  pinMode(r_in2,OUTPUT);
  pinMode(l_ena,OUTPUT);
  pinMode(l_in3,OUTPUT);
  pinMode(l_in4,OUTPUT);
  Serial.begin(9600);
  digitalWrite(r_in1,LOW);
  digitalWrite(r_in2,LOW);
  digitalWrite(l_in3,LOW); 
  digitalWrite(l_in4,LOW);
  analogWrite(r_ena,0);
  analogWrite(l_ena,0);
 
 
}
 
void loop() {
  forward();
    //for bluetooth
      if(Serial.available()>0)
      {
      data=Serial.read();
      Serial.print(data);
      if(data=='L')
      {
        leftward();
        //Serial.print("L");
      }
      if(data=='R')
      {
        rightward();
        //Serial.print("R");
      }
      if(data=='F')
      {
        forward();
        //Serial.print("F");
      }
      if(data=='B')
      {
        backward();
        //Serial.print("B");
      }
      }   
 
}
 
void forward(){
  digitalWrite(r_in1,HIGH);
  digitalWrite(r_in2,LOW);
  digitalWrite(l_in3,HIGH); 
  digitalWrite(l_in4,LOW);
  analogWrite(r_ena,speeds);
  analogWrite(l_ena,speeds);
}
 
void backward(){
  digitalWrite(r_in1,LOW);
  digitalWrite(r_in2,HIGH);
  digitalWrite(l_in3,LOW); 
  digitalWrite(l_in4,HIGH);
  analogWrite(r_ena,speeds);
  analogWrite(l_ena,speeds);
}
 
void leftward(){
  digitalWrite(r_in1,HIGH);
  digitalWrite(r_in2,LOW);
  digitalWrite(l_in3,LOW); 
  digitalWrite(l_in4,HIGH);
  analogWrite(r_ena,speeds);
  analogWrite(l_ena,speeds);
}
 
void rightward(){
  digitalWrite(r_in1,LOW);
  digitalWrite(r_in2,HIGH);
  digitalWrite(l_in3,HIGH); 
  digitalWrite(l_in4,LOW);
  analogWrite(r_ena,speeds);
  analogWrite(l_ena,speeds);
}