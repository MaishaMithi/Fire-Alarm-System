int redLed = 4;
int blueLed = 8;
int buzzer1 = 5;
int buzzer2 = 6;
int gasPin = A0;
int flamePin = 2;

int gasSensorThres = 600;

void setup() 
{ 
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(gasPin, INPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int gasSensor = analogRead(gasPin);
  int flameSensor = digitalRead(flamePin);
  
  Serial.print("gasPin Value: ");
  Serial.println(gasSensor);
  Serial.print("flamePin Value: ");
  Serial.println(flameSensor);
  delay(1000);
  
  if (gasSensor > gasSensorThres  && flameSensor==LOW)
  {
    tone(buzzer1, 5000);
    digitalWrite(redLed, HIGH);
    tone(buzzer2, 5000);
    digitalWrite(blueLed, LOW);
  }
   else if (gasSensor > gasSensorThres)
  {
    tone(buzzer1, 5000);
    digitalWrite(redLed, LOW);
    noTone(buzzer2);
    digitalWrite(blueLed, LOW);
  }
  else if (flameSensor==LOW)
  {
    noTone(buzzer1);
    digitalWrite(redLed, HIGH);
    tone(buzzer2, 5000);
    digitalWrite(blueLed, LOW);
    }
  
  else
  {
    digitalWrite(redLed, LOW);
    noTone(buzzer1);
    noTone(buzzer2);
    digitalWrite(blueLed, HIGH);    
  }
}
