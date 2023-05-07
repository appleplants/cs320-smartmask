/**
 * Arduino code to control heating and cooling elements
 * in the smartmask, based on skin conductivity readings.
 * @file smartmask.ino
 * @author Abby, Mattie and Alice
 */


//PIN definitions for heating and cooling elements, as well as the GSR sensor.
int heatingPIN = 7;
int coolingPIN = 6;
const int GSRPIN = A2;


//GSR sensor readings
int sensorValue;




void setup() {
  Serial.begin(9600);


 //set initial controller pin modes to low
  pinMode(heatingPIN, OUTPUT);
  digitalWrite(heatingPIN, LOW);
  pinMode(coolingPIN, OUTPUT);
  digitalWrite(coolingPIN, LOW);
}


void loop() {
  sensorValue=analogRead(GSR);
  //turn the heating pad on if the user is awake/puts the sensor on
  if (sensorValue <= 600) {
  	digitalWrite(heatingPIN, HIGH);
  }
  //turn the cooling pad on if the user is asleep/takes the sensor off
  else {
    digitalWrite(coolingPIN, HIGH);
  }


  Serial.println(sensorValue);
  delay(1000);
  //reset heating and cooling elements
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}




