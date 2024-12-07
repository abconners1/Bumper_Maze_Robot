Youtube Demonstration:
https://youtube.com/shorts/b2h_pgnrEKo?feature=share

Reactive Control Maze Navigation Robot

A reactive control system for a mobile robot to navigate a maze using bump sensors and a "right-hand rule" algorithm. This project demonstrates real-time obstacle avoidance and wall-following capabilities, implemented with Arduino and the Ardumoto motor shield.
Table of Contents

    Features
    Hardware Components
    Project Setup
    How It Works
    Results
    Possible Improvements
    Authors

Features

    Reactive Control: Uses bump sensors for real-time obstacle detection and path adjustment.
    Wall-Following Algorithm: Implements the "right-hand rule" for maze navigation.
    Simple Operation: Start and stop the robot using a push button.
    Modular Code: Reusable functions for motor control and system setup.

Hardware Components

    Arduino Uno: Microcontroller for logic and motor control.
    Ardumoto Shield: Drives the motors and handles PWM control.
    DC Motors: Left and right motors for movement.
    Bump Sensors: Detect obstacles and trigger navigation adjustments.
    Push Button: Starts and stops the robot.
    Power Supply: Battery pack for Arduino and motors.

Project Setup
Wiring Diagram

    Motor A:
        PWM (speed): Pin 3
        Direction: Pin 12
    Motor B:
        PWM (speed): Pin 11
        Direction: Pin 13
    Bump Sensors:
        Left sensor: Pin 2
        Right sensor: Pin 6
    Push Button: Pin 7

Software Requirements

    Arduino IDE: Download here

Steps to Run

    Clone the repository:

    git clone https://github.com/yourusername/reactive-control-robot.git

    Open the Reactive_Control_Code.ino file in the Arduino IDE.
    Connect the Arduino to your computer.
    Compile and upload the code to the Arduino board.

How It Works

    Start: Press the push button to activate the robot.
    Navigation:
        Moves forward with a slight right-hand bias.
        Adjusts path based on bump sensor input:
            Left bump sensor → Reverse and turn slightly left.
            Right bump sensor → Reverse and turn sharply right.
    Stop: Press the push button again to halt the robot.

Core Algorithm

    Right-Hand Rule: Keeps the robot aligned with the maze's right-hand wall.
    Reactive Adjustments: Immediate response to sensor triggers for seamless navigation.

Results

    Performance: Successfully completed the maze in an average of 51.3 seconds across three runs.
    Observations:
        Reliable navigation using reactive control.
        Efficient obstacle handling with simple logic.

Possible Improvements

    Add advanced corner detection and escape logic.
    Implement feedback loops for error correction.
    Optimize motor speeds for faster navigation.

Authors

    Andrew Conners
    Yer Yang
