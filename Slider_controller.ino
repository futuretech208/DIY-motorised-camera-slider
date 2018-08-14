//Code written by Sumukh Anil Purohit
//Licenced under GNU GPL v2
//
//Arduino Based DIY motorised slider controller


// Defines pins numbers
const int stepPin = 2;
const int dirPin = 3;
const int limitLeft = 4;        //for limit switch on one side of the slider
const int limitRight = 5;       //for other side limit switch
long customDelay, customDelayMapped; // Defines variables for mapping delays set using potentiometer

void setup()
{
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(limitLeft, INPUT);
  pinMode(limitRight, INPUT);
  digitalWrite(limitLeft, LOW);
  digitalWrite(limitRight, LOW);
  digitalWrite(dirPin, LOW); //Movement towards right direction by default
  Serial.begin(9600);
}
void loop()
{
  setDirection();
  customDelayMapped = speedUp(); // Gets custom delay values from the custom speedUp function
  // Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  digitalWrite(stepPin, HIGH);
  delay(customDelayMapped);
  digitalWrite(stepPin, LOW);
  delay(customDelayMapped);
}
// Function for reading the Potentiometer
int speedUp()
{
  int customDelay = analogRead(A4); // Reads the potentiometer
  long newCustom = map(customDelay, 0, 1023, 100, 1023 ); // Converts the read values of the potentiometer from 0 to 1023 into desired delay values (100 to 1023)
  return newCustom;
}
//Setting direction and limit switches
void setDirection()
{
  if (digitalRead(limitLeft) == HIGH)
  {
    digitalWrite(dirPin, LOW);                 // Right
  }
  if (digitalRead(limitRight) == HIGH)
  {
    digitalWrite(dirPin, HIGH);                 // Left
  }
}


