
#define ENA 10           ////left wheel
#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8
#define ENB 11          //////right wheel
#define ENC A2
#define IN5 A0
#define IN6 A1
#define WAT 9
#define SOE 12
char f,g,up=1,w=1,s=1;

int IR1,IR2,IR3;

void setup() {
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {

while(g=='A')
 {
 // Serial.println("abc=");
  //Serial.print(g);
   digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  
  IR1=digitalRead(4);
  IR2=digitalRead(3);
  IR3=digitalRead(2);

  if(IR1==0 && IR2==0 && IR3==0)
  {
    drillup();
    wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,0);
  }
    if(IR1==0 && IR2==0 && IR3==1)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,230);
  }
      if(IR1==0 && IR2==1 && IR3==0)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,0);
  }
       if(IR1==0 && IR2==1 && IR3==1)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,230);
  }
      if(IR1==1 && IR2==0 && IR3==0)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,230);
    analogWrite(11,0);
  }
      if(IR1==1 && IR2==0 && IR3==1)
  {
   drilldw();
   wateron();
   soeon();
    analogWrite(10,130);
    analogWrite(11,130);
  }
        if(IR1==1 && IR2==1 && IR3==0)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,230);
    analogWrite(11,0);
  }
       if(IR1==1 && IR2==1 && IR3==1)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,0);
  }
  if(Serial.available())
{ 
  f=Serial.read();

if(f=='M'||'F'||'S'||'R'||'L'||'B'||'T'||'D'||'W'||'O'||'E'||'I')
{
g='a';
}}
 }
 
if(Serial.available())
{ 
f=Serial.read();

if(f=='M'||'F'||'S'||'R'||'L'||'B'||'T'||'D'||'W'||'O'||'E'||'I')
{
g='a';
}
//Serial.println("blue=");
//Serial.print(f);
 switch(f)
 {
 case 'F':
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
analogWrite(10,130);
analogWrite(11,130);

break;
 
 case 'B':
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(10,130);
  analogWrite(11,130);
 break;

 case 'R':
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(10,200);
  analogWrite(11,0);
 break;
 
 case 'L' :
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(10,0);
  analogWrite(11,200);
 break;

 case 'S':
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(10,0);
  analogWrite(11,0);
 break;

case 'D':
drilldw();
break;

case 'I':
drillup();
break;

case 'T':
 wateron();
 break;
 
case 'E':
 wateroff();
 break;

 case 'O':
 soeon();
 break;

 case 'W':
 soeoff();
 break;


case 'A':
 digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  
  IR1=digitalRead(4);
  IR2=digitalRead(3);
  IR3=digitalRead(2);

  if(IR1==0 && IR2==0 && IR3==0)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,0);
  }
    if(IR1==0 && IR2==0 && IR3==1)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,230);
  }
      if(IR1==0 && IR2==1 && IR3==0)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,0);
  }
       if(IR1==0 && IR2==1 && IR3==1)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,230);
  }
      if(IR1==1 && IR2==0 && IR3==0)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,230);
    analogWrite(11,0);
  }
      if(IR1==1 && IR2==0 && IR3==1)
  {
    drilldw();
      wateron();
   soeon();
    analogWrite(10,130);
    analogWrite(11,130);
  }
        if(IR1==1 && IR2==1 && IR3==0)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,230);
    analogWrite(11,0);
  }
       if(IR1==1 && IR2==1 && IR3==1)
  {
    drillup();
     wateroff();
    soeoff();
    analogWrite(10,0);
    analogWrite(11,0);
  }
  g='A';
  break;
  
 default:
 drillup();
  wateroff();
  soeoff();
 analogWrite(10,0);
 analogWrite(11,0);
 break;
 }}
 }

 void drillup()
 {
   if(up==0)
    {
    analogWrite(IN5,0);
    analogWrite(IN6,255);
    analogWrite(ENC,150);
    delay(100);
    analogWrite(ENC,0);
    
    }
    up=1;  
 }

 void drilldw()
 {
     if(up==1)
    {
    analogWrite(IN5,255);
    analogWrite(IN6,0);
    analogWrite(ENC,150);
    delay(30);
    analogWrite(IN5,0);
    analogWrite(IN6,255);
    analogWrite(ENC,50);
    
    }
    up=0;
 }

 void wateron()
 {
  int pos = 0;
  if(w==1)
    {
      for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    analogWrite(WAT,pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }
    w=0;
 }
 void wateroff()
 {
  int pos = 0;
  if(w==0)
    {
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    analogWrite(WAT,pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    }
    }
    w=1;
 }
  void soeon()
 {
  int pos = 0;
  if(s==1)
    {
      digitalWrite(SOE,HIGH);
    }
    s=0;
 }
 void soeoff()
 {
  int pos = 0;
  if(s==0)
    {
  digitalWrite(SOE,LOW);
    }
    s=1;
 }
