#define ledPin 3
#define btn 5

bool ledStatus=LOW;
unsigned long lastTime=0;
int delayInterval;

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(btnPin,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){  
  if(!ledStatus){
    digitalWrite(ledPin,LOW);
    delayInterval=random(2000,3500);
    int waitTime=delayInterval;
    delay(waitTime);
    digitalWrite(ledPin,HIGH);
    ledStatus=HIGH;
  }   
  if(ledStatus==HIGH && digitalRead(btnPin)==LOW){
    unsigned long currentTime=millis();
    int reactionTime=currentTime-lastTime-delayInterval;
    lastTime=currentTime;
    ledStatus=LOW;
    Serial.println(reactionTime);
  }
}
}
