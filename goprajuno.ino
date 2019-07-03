

const int trigPin1 = 4;
const int echoPin1 = 5;
const int echoPin = 7;
const int trigPin = 6;
int relayPin1=13;
int relayPin2=10;

long duration;
int distance,distance1;
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(trigPin1, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(echoPin1, INPUT);
Serial.begin(9600); 
pinMode(relayPin1,OUTPUT);
pinMode(relayPin2,OUTPUT);
}
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delay(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delay(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin1, HIGH);

distance1= duration*0.034/2;

Serial.print("Distance1: ");
Serial.println(distance1);

if(distance<10)
{
  digitalWrite(relayPin1,HIGH);
  delay(500);
}
else
{digitalWrite(relayPin1,LOW);
}
if(distance1<12)
{
  digitalWrite(relayPin2,HIGH);
  delay(750);
}
else
{digitalWrite(relayPin2,LOW);
}
}
