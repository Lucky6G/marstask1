#define ultratrig 2
#define ultraecho 3
#define led 11
#define limit 100

void setup(){
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trig, LOW);
  delay(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo,HIGH);
  int distance = duration * 0.034 / 2;
  if(distance < limit) {
    Serial.println("ALERT");
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}
