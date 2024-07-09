int trig=2;
int echo=3;
int buzzer=4;
int led1=5;
int led2=6;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  long distance,duration;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration/2) / 29.1;
  if(distance<20 && distance>10){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    delay(500);
        Serial.print("ALERT");
    digitalWrite(buzzer,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    delay(500);
  }
    else if(distance<10){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    delay(250);
      Serial.print("CALL");
    digitalWrite(buzzer,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    delay(250);     
  }
}