 /* Ardumoto Example Sketch
  by: Jim Lindblom
  date: November 8, 2013
  license: Public domain. Please use, reuse, and modify this 
  sketch!

  Three useful functions are defined:
    setupArdumoto() -- Setup the Ardumoto Shield pins
    driveArdumoto([motor], [direction], [speed]) -- Drive [motor] 
      (0 for A, 1 for B) in [direction] (0 or 1) at a [speed]
      between 0 and 255. It will spin until told to stop.
    stopArdumoto([motor]) -- Stop driving [motor] (0 or 1).

  setupArdumoto() is called in the setup().
  The loop() demonstrates use of the motor driving functions.
*/

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define CW  0
#define CCW 1

// Motor definitions to make life easier:
#define MOTOR_A 0 //A RIGHT
#define MOTOR_B 1 //B LEFT


// Pin Assignments //
// Don't change these! These pins are statically defined by shield layout
const byte PWMA = 3;  // PWM control (speed) for motor A
const byte PWMB = 11; // PWM control (speed) for motor B
const byte DIRA = 12; // Direction control for motor A
const byte DIRB = 13; // Direction control for motor B
int rightButton;
int leftButton;
int buttonPush;
int buttonPin;
int rightPushButton;
int leftPushButton;


void setup()
{
  buttonPin = 7;
  rightButton = 6;
  leftButton = 2;
  setupArdumoto(); // Set all pins as outputs
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{ 
  
  buttonPush = digitalRead(buttonPin);

  
if (buttonPush == LOW) {
  buttonPush = HIGH;
  while(buttonPush == HIGH){
    driveArdumoto(MOTOR_A, CCW, 70); //1st leg (197 cm)
    driveArdumoto(MOTOR_B, CCW, 160); //1st leg (197 cm)
    leftPushButton =digitalRead(leftButton);
    rightPushButton =digitalRead(rightButton);
    buttonPush = digitalRead(buttonPin);
    if (leftPushButton == LOW || rightPushButton == LOW ){
      if (leftPushButton == LOW){
            driveArdumoto(MOTOR_A, CW, 120); //1st leg (197 cm)
            driveArdumoto(MOTOR_B, CW, 120); //1st leg (197 cm)
            delay(160);
            driveArdumoto(MOTOR_A, CCW, 200); //1st leg (197 cm)
            driveArdumoto(MOTOR_B, CW, 200); //1st leg (197 cm)
            delay(210);
      }
      else if (rightPushButton == LOW){
            driveArdumoto(MOTOR_A, CW, 120); //1st leg (197 cm)
            driveArdumoto(MOTOR_B, CW, 120); //1st leg (197 cm)
            delay(150);
            driveArdumoto(MOTOR_A, CCW, 130); //1st leg (197 cm)
            driveArdumoto(MOTOR_B, CW, 130); //1st leg (197 cm)
            delay(160);
      }
    }
    else if (buttonPush == LOW ){
         stopArdumoto(MOTOR_A); //2nd leg (60 cm)
         stopArdumoto(MOTOR_B); //2nd leg (60 cm)
    }
  }

 }

else{
  stopArdumoto(MOTOR_A); //2nd leg (60 cm)
  stopArdumoto(MOTOR_B); //2nd leg (60 cm)
}

}

// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}

// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

// setupArdumoto initialize all pins
void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

