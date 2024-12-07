/* Ardumoto Example Sketch
   Modified for Maze Navigation - Reactive Control


   This code demonstrates reactive control for a mobile robot navigating a maze
   using bump sensors. The robot employs a "right-hand rule" wall-following 
   algorithm. This approach ensures that the robot can traverse any simply connected maze.

   Key Functions:
     - setupArdumoto() initializes Ardumoto Shield pins.
     - driveArdumoto(motor, direction, speed) drives a motor (A or B) in a specific 
       direction (CW or CCW) at a given speed (0-255).
     - stopArdumoto(motor) stops the specified motor.
     - setup() configures initial settings, including input/output pins.
     - loop() runs the main navigation algorithm, incorporating reactive controls.

   Algorithm:
     - Navigate forward with a slight right-hand bias.
     - If the left bump sensor is triggered, reverse and turn left slightly.
     - If the right bump sensor is triggered, reverse and turn right sharply.
     - Stop if the button is pressed again.
*/

// Clockwise and counter-clockwise definitions.
// Adjust based on motor wiring to ensure proper directional control.
#define CW  0   // Clockwise rotation
#define CCW 1   // Counter-clockwise rotation

// Motor identifiers for convenience.
#define MOTOR_A 0 // Motor A controls the right wheel
#define MOTOR_B 1 // Motor B controls the left wheel

// Pin Assignments //
// These pins are fixed by the Ardumoto Shield layout.
const byte PWMA = 3;  // PWM control for motor A speed
const byte PWMB = 11; // PWM control for motor B speed
const byte DIRA = 12; // Direction control for motor A
const byte DIRB = 13; // Direction control for motor B

// Global variables for sensor and button states.
int rightButton;       // Pin for right bump sensor
int leftButton;        // Pin for left bump sensor
int buttonPush;        // State of the start/stop button
int buttonPin;         // Pin for start/stop button
int rightPushButton;   // State of the right bump sensor
int leftPushButton;    // State of the left bump sensor

void setup() {
  // Assign pin numbers to buttons.
  buttonPin = 7;      // Start/stop button pin
  rightButton = 6;    // Right bump sensor pin
  leftButton = 2;     // Left bump sensor pin

  // Initialize Ardumoto Shield pins.
  setupArdumoto();    // Set motor control pins as outputs.

  // Configure button pins as inputs with pull-up resistors.
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);

  // Initialize serial communication for debugging.
  Serial.begin(9600);
}

void loop() {
  // Check the state of the start/stop button.
  buttonPush = digitalRead(buttonPin);

  // If button is pressed, begin navigation.
  if (buttonPush == LOW) {
    buttonPush = HIGH; // Toggle button state.
    while (buttonPush == HIGH) {
      // Drive motors forward with right-hand bias.
      driveArdumoto(MOTOR_A, CCW, 70);  // Slower speed for right wheel.
      driveArdumoto(MOTOR_B, CCW, 160); // Faster speed for left wheel.

      // Check bump sensor states.
      leftPushButton = digitalRead(leftButton);
      rightPushButton = digitalRead(rightButton);
      buttonPush = digitalRead(buttonPin);

      // React to bump sensors.
      if (leftPushButton == LOW || rightPushButton == LOW) {
        if (leftPushButton == LOW) {
          // Left sensor triggered: Reverse and turn left slightly.
          driveArdumoto(MOTOR_A, CW, 120);
          driveArdumoto(MOTOR_B, CW, 120);
          delay(160); // Short reverse delay.
          driveArdumoto(MOTOR_A, CCW, 200);
          driveArdumoto(MOTOR_B, CW, 200);
          delay(210); // Turn left.
        } else if (rightPushButton == LOW) {
          // Right sensor triggered: Reverse and turn right sharply.
          driveArdumoto(MOTOR_A, CW, 120);
          driveArdumoto(MOTOR_B, CW, 120);
          delay(150); // Short reverse delay.
          driveArdumoto(MOTOR_A, CCW, 130);
          driveArdumoto(MOTOR_B, CW, 130);
          delay(160); // Turn right.
        }
      } else if (buttonPush == LOW) {
        // If button is pressed again, stop motors.
        stopArdumoto(MOTOR_A);
        stopArdumoto(MOTOR_B);
      }
    }
  } else {
    // Stop motors if button is not pressed.
    stopArdumoto(MOTOR_A);
    stopArdumoto(MOTOR_B);
  }
}

// Function to drive a motor at a specific speed and direction.
void driveArdumoto(byte motor, byte dir, byte spd) {
  if (motor == MOTOR_A) {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  } else if (motor == MOTOR_B) {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }
}

// Function to stop a motor.
void stopArdumoto(byte motor) {
  driveArdumoto(motor, 0, 0); // Set speed to 0.
}

// Initialize Ardumoto Shield pins.
void setupArdumoto() {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Set all pins to LOW initially.
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}
