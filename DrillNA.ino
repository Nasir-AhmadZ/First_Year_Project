const int LeftLedA=12,LeftLedB=13,RightLedA=4,RightLedB=5,LedC=1,Lenable6=6,Lmotor7=7,Lmotor8=8,Rmotor9=9,Rmotor10=10,Renable11=11,
LeftBmpr=2,RightBmpr=3;
int i;

void setup() {
pinMode(LeftLedA,OUTPUT);
pinMode(LeftLedB,OUTPUT);
pinMode(RightLedA,OUTPUT);
pinMode(RightLedB,OUTPUT);
pinMode(LedC,OUTPUT);
pinMode(Lenable6,OUTPUT);
pinMode(Lmotor7,OUTPUT);
pinMode(Lmotor8,OUTPUT);
pinMode(Rmotor9,OUTPUT);
pinMode(Rmotor10,OUTPUT);
pinMode(Renable11,OUTPUT);
pinMode(LeftBmpr,INPUT);
pinMode(RightBmpr,INPUT);
attachInterrupt(digitalPinToInterrupt(LeftBmpr), leftbmpr, LOW); 
attachInterrupt(digitalPinToInterrupt(RightBmpr), rightbmpr, LOW); 
}

void forward()
{
digitalWrite(Lenable6,HIGH);
digitalWrite(Renable11,HIGH);
digitalWrite(Lmotor7,HIGH);
digitalWrite(Lmotor8,LOW);
digitalWrite(Rmotor9,HIGH);
digitalWrite(Rmotor10,LOW);
digitalWrite(LedC,HIGH);
delay(500);
digitalWrite(LedC,LOW);
delay(500);
digitalWrite(RightLedB,HIGH);
digitalWrite(LeftLedB,HIGH);
delay(500);
digitalWrite(RightLedB,LOW);
digitalWrite(LeftLedB,LOW);
delay(500);
digitalWrite(RightLedA,HIGH);
digitalWrite(LeftLedA,HIGH);
delay(500);
digitalWrite(RightLedA,LOW);
digitalWrite(LeftLedA,LOW);
delay(500);


}

void backward()
{
digitalWrite(Lenable6,HIGH);
digitalWrite(Renable11,HIGH);
digitalWrite(Lmotor7,LOW);
digitalWrite(Lmotor8,HIGH);
digitalWrite(Rmotor9,LOW);
digitalWrite(Rmotor10,HIGH);
}
void rightbmpr()
{

  detachInterrupt(digitalPinToInterrupt(LeftBmpr)); 
  detachInterrupt(digitalPinToInterrupt(RightBmpr)); 
  backward();
  for (int i=0;i<40;i++) 
  {
  delayMicroseconds(15000);
  } 
  digitalWrite(Lenable6,HIGH);
  digitalWrite(Renable11,LOW);
  digitalWrite(RightLedA,LOW);
  digitalWrite(RightLedB,LOW);
  digitalWrite(LeftLedA,HIGH);
  digitalWrite(LeftLedB,HIGH);
  for (int i=0;i<45;i++) 
  {
  delayMicroseconds(15000);
  } 
  digitalWrite(Lenable6,LOW);
  digitalWrite(Renable11,LOW);
  attachInterrupt(digitalPinToInterrupt(LeftBmpr), leftbmpr, LOW); 
  attachInterrupt(digitalPinToInterrupt(RightBmpr), rightbmpr, LOW);

}
void leftbmpr()
{
  detachInterrupt(digitalPinToInterrupt(LeftBmpr)); 
detachInterrupt(digitalPinToInterrupt(RightBmpr)); 
  backward();
  for (int i=0;i<40;i++) 
  {
  delayMicroseconds(15000);
  } 
  digitalWrite(Renable11,HIGH);
  digitalWrite(Lenable6,LOW);
  digitalWrite(LeftLedA,LOW);
  digitalWrite(LeftLedB,LOW);
  digitalWrite(RightLedA,HIGH);
  digitalWrite(RightLedB,HIGH);
  for (int i=0;i<45;i++) 
  {
  delayMicroseconds(15000);
  } 
  digitalWrite(Lenable6,LOW);
  digitalWrite(Renable11,LOW);
  attachInterrupt(digitalPinToInterrupt(LeftBmpr), leftbmpr, LOW); 
  attachInterrupt(digitalPinToInterrupt(RightBmpr), rightbmpr, LOW);
}
void loop() {

forward();
attachInterrupt(digitalPinToInterrupt(LeftBmpr), leftbmpr, LOW); 
attachInterrupt(digitalPinToInterrupt(RightBmpr), rightbmpr, LOW); 


}
