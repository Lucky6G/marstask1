#define pinA 2
#define pinB 3
#define pinC 4

unsigned long timeA=0;
unsigned long timeB=0;
unsigned long timeC=0;

bool statusA=HIGH;
bool statusB=HIGH;
bool statusC=HIGH;

void setup(){
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  
  digitalWrite(pinA,HIGH);
  digitalWrite(pinB,HIGH);
  digitalWrite(pinC,HIGH);
}

void loop(){
  unsigned long current=millis();

  if (current-timeA>=500) {
    timeA=current;
    statusA=!statusA;
    digitalWrite(pinA,statusA);
  }
  
  if (current-timeB>=1000){
    timeB=current;
    statusB=!statusB;
    digitalWrite(pinB,statusB);
  }
  
  if (current-timeC>=1500) {
    timeC=current;
    statusC=!statusC;
    digitalWrite(pinC,statusC);
  }
}
