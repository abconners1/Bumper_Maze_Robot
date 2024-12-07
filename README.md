Reactive Control Maze Navigation Robot
Overview

This project implements a reactive control system for a mobile robot designed to navigate a maze using bump sensors. The robot follows the "right-hand rule" to traverse the maze effectively. It is programmed using an Arduino microcontroller with the Ardumoto motor shield, and the control logic ensures simple, reliable, and adaptive navigation through the maze.
Features

    Reactive Control Algorithm: Employs a "right-hand rule" navigation strategy.
    Bump Sensor Integration: Detects obstacles and adjusts the robot's path.
    Right-Hand Bias: Maintains alignment with the maze walls.
    Simple Button Start/Stop: Allows easy control of the robot's operation.
    Modular Functions: Includes reusable functions for motor control and system initialization.

Components

    Arduino Uno: The main microcontroller.
    Ardumoto Shield: Controls the motors.
    Two DC Motors: Drive the left and right wheels.
    Bump Sensors: Mounted on the front to detect obstacles.
    Push Button: Starts and stops the robot.
    Power Supply: Powers the motors and Arduino.

Project Structure

.
├── Reactive_Control_Code.ino      # Main Arduino code
├── README.md                      # Project documentation
└── Lab_Report.pdf                 # Detailed analysis and results

How It Works

    Setup: The bump sensors and motors are configured, and the Arduino initializes the system.
    Navigation:
        The robot drives forward with a slight right-hand bias to follow the wall.
        If the left bump sensor is triggered, the robot reverses and turns slightly left.
        If the right bump sensor is triggered, the robot reverses and turns sharply right.
    Stop: The robot halts when the push button is pressed again.

Algorithm Flow

    Start the robot with the push button.
    Continuously check bump sensor states while driving forward.
    React to sensor input:
        Left bump sensor: Reverse and turn left slightly.
        Right bump sensor: Reverse and turn right sharply.
    Stop if the push button is pressed.

Control Logic

    Right-Hand Rule: Ensures the robot follows the maze's right-hand wall.
    Reactive Adjustments: Immediate response to sensor triggers for real-time obstacle avoidance.

Hardware Setup

    Wiring:
        Connect the bump sensors to pins 2, 6, and 7 on the Arduino.
        Attach motor control pins as follows:
            Motor A: Speed on pin 3, direction on pin 12.
            Motor B: Speed on pin 11, direction on pin 13.
        Push button on pin 7.
    Power:
        Ensure the motors and Arduino are powered appropriately.
    Assembly:
        Attach bump sensors and motors securely to the robot chassis.

Software Setup

    Install the Arduino IDE.
    Open the Reactive_Control_Code.ino file.
    Connect the Arduino to your computer and upload the code.

Usage Instructions

    Press the push button to start the robot.
    Place the robot at the maze's entrance.
    Observe the robot navigate using the right-hand rule.
    Press the push button again to stop the robot.

Results

    Performance: The robot consistently completes the maze with an average time of 51.3 seconds (tested over three runs).
    Key Observations:
        Effective wall-following using a reactive control algorithm.
        Simple and robust logic for obstacle handling.

Possible Improvements

    Add logic to detect and escape from corners more efficiently.
    Include feedback mechanisms for error correction.
    Enhance navigation speed with optimized motor control.

References

    "Maze Solving Algorithm." Wikipedia. Wikimedia Foundation, 23 Jan. 2017.
    "Maze Solver Robot, Using Artificial Intelligence." Arduino Project Hub.

Authors

    Andrew Conners
    Yer Yang
    Team #: 408
