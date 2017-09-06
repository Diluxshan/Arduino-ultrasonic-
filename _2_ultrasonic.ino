#define trigPin1 3  //right senssor
#define echoPin1 2
#define trigPin2 4  //left sensor
#define echoPin2 5
int const buzzPinR = 13;
int const buzzPinL = 12;
const int pirPin = 6;
//const int green = 11;

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;
long   cm;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
//pinMode(trigPin3, OUTPUT);
//pinMode(echoPin3, INPUT);
pinMode(buzzPinR, OUTPUT);
pinMode(buzzPinL, OUTPUT);
pinMode(pirPin, INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
//SonarSensor(trigPin3, echoPin3);
//FrontSensor = distance;
Serial.print("LeftSensor  :  ");
Serial.print(LeftSensor);
Serial.print("    ");
//Serial.print(FrontSensor);
//Serial.print("  ");
Serial.print("RightSensor  :  ");
Serial.print (RightSensor);

//.................................................................PIR SENSOR.........................................................................................
  //for(int y=0;y<=2;y++) {
  int value = digitalRead(pirPin);
  if (value == HIGH)
  {

   
     digitalWrite(buzzPinR, HIGH);
      digitalWrite(buzzPinL, HIGH);
     //digitalWrite(buzzPinL, LOW);

      Serial.println("        Motion Detected");
   
     
    
        delay(200);
  }
  else
  {
   // digitalWrite(green, LOW);
    Serial.println("                Motion OFF");
    //delay(500);
  }
   //} 
  
}

//.................................................................end  of loop..............................................................................................

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

delay(250);

// ..................................................Coading for Buzzar right buzzzar....................................................................................... 
if (RightSensor < 50 && RightSensor >= 0) {

 digitalWrite(buzzPinR, HIGH);
 delay(50);
 digitalWrite(buzzPinR, LOW);
 delay(50);
  }
  else if (RightSensor <= 100 && RightSensor >= 50) {
 digitalWrite(buzzPinR, HIGH);
 delay(1000);
 digitalWrite(buzzPinR, LOW);
 delay(1000);
 }
else {
// Don't buzz
digitalWrite(buzzPinR, LOW);
}
//................................................................................................................................................................................




// .............................................Coading for Buzzar left buzzzar...................................................................................................
if (LeftSensor < 50 && LeftSensor >= 0) {

digitalWrite(buzzPinL, HIGH);
 delay(50);
 digitalWrite(buzzPinL, LOW);
 delay(50);
  }

  else if (LeftSensor <= 100 && LeftSensor >= 50) {

 digitalWrite(buzzPinL, HIGH);
 delay(1000);
 digitalWrite(buzzPinL, LOW);
 delay(1000);

  }
else {

// Don't buzz
digitalWrite(buzzPinL, LOW);
}
//....................................................................................................................................

}
