#define rPin 9
#define bPin 10
#define gPin 11
#define blinkLed 8
#define potPin A0

unsigned long lastTime=0;
bool ledState=HIGH;

void setup(){
  pinMode(rPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(blinkLed,OUTPUT);

  digitalWrite(blinkLed,HIGH);
  Serial.begin(9600);
}

void loop(){
  int potValue=analogRead(potPin);
  int brightness=map(potValue,0,1023,0,255);
  int delayTime=map(potValue,0,1023,0,1000);

  Serial.println(potValue);
  Serial.println(delayTime);

  unsigned long currentTime=millis();

  if(currentTime-lastTime>=delayTime){
    lastTime=currentTime;
    ledState=!ledState;
    digitalWrite(blinkLed,ledState);
  }

  analogWrite(rPin,brightness);
  analogWrite(bPin,255-brightness);
  analogWrite(gPin,brightness/2);
}
