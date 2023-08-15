#include <Servo.h>

// Define servo objects for each joint
Servo servo1;
Servo servo2;
Servo servo3;
Servo gripper;

// Pins for each servo
const int PIN_SERVO1 = 10;   // ekbare nicher ta  Replace 9 with the actual pin number for servo 1 
const int PIN_SERVO2 = 11;  // Replace 10 with the actual pin number for servo 2
const int PIN_SERVO3 = 12;  // Replace 11 with the actual pin number for servo 3
const int PIN_GRIPPER = 9; // Replace 12 with the actual pin number for the gripper servo

// Angles for initial positions
const int ANGLE1_INITIAL = 90;  // Initial angle for servo 1
const int ANGLE2_INITIAL = 0;  // Initial angle for servo 2
const int ANGLE3_INITIAL = 90;  // Initial angle for servo 3
const int GRIPPER_OPEN_ANGLE = 150;   // Gripper open angle       90
const int GRIPPER_CLOSE_ANGLE = 65;  // Gripper close angle

void setup() {
  // Attach the servos to their respective pins
  servo1.attach(PIN_SERVO1);
  servo2.attach(PIN_SERVO2);
  servo3.attach(PIN_SERVO3);
  gripper.attach(PIN_GRIPPER);

  // Set initial positions for all servos
  servo1.write(ANGLE1_INITIAL);
  servo2.write(ANGLE2_INITIAL);
  servo3.write(ANGLE3_INITIAL);
  gripper.write(GRIPPER_OPEN_ANGLE); // Gripper is initially open
}

void loop() {
  // Move the arm to desired positions
  moveArmToPosition(90, 30, 135); // Replace these angles with your desired positions
  delay(1000); // Wait for 1 second before moving to the next position

  moveArmToPosition(45, 150, 60); // Replace these angles with your desired positions
  delay(1000); // Wait for 1 second before moving to the next position

  // Control the gripper
  openGripper();
  delay(1000); // Wait for 1 second before closing the gripper

  closeGripper();
  delay(1000); // Wait for 1 second before opening the gripper
}

void moveArmToPosition(int angle1, int angle2, int angle3) {
  // Move each servo to the desired angles
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
}

void openGripper() {
  gripper.write(GRIPPER_OPEN_ANGLE);
}

void closeGripper() {
  gripper.write(GRIPPER_CLOSE_ANGLE);
}
