#define trigPin 9
#define echoPin 10
#define trigPin2 2
#define echoPin2 8
String voice;
int led1 = 4; //Connect LED 1 To Pin #2
int led2 = 5; //Connect LED 2 To Pin #3
int led3 = 6; //Connect LED 3 To Pin #4
int led4 = 7; //Connect LED 4 To Pin #5
int flag1,flag2;
void setup() 
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite (13, HIGH);
  digitalWrite (12, HIGH);
}
void loop()
 {
    long duration1, distance1,duration2, distance2;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration1 = pulseIn(echoPin, HIGH);
    distance1 = (duration1/2) / 29.1;
    if (distance1 < 10)
    {
     Serial.println(flag1);
     Serial.println(flag2);
     if(flag2==1)
     {
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     }
    }
     digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;
    if (distance2 < 10) 
    { 
      if(flag1==1)
      {
      digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
      }
    }
    else {

  while (Serial.available()) { //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {
      break; //Exit the loop when the # is detected after the word
    }
    voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) 
{
    Serial.println(voice);    
    if ((voice == "*forward")&&(distance1>10))
 {
      flag2=1;
      flag1=0;
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH); 
      Serial.println(flag1);
     Serial.println(flag2); 
    }
    else if ((voice == "*back")&&(distance2>10))
    {
      flag1=1;
      flag2=0;
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    }
    else if (voice == "*left")
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      delay(1500);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);     
  }
    else if (voice == "*right")
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(1500); 
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
     }
    else if (voice == "*stop")
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    voice = "";
  }
 } 

