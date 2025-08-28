#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor1, sensor2, sensor3;

const int TURN_RIGHT_DISTANCE = 200; // 20cm in mm
const int TURN_LEFT_DISTANCE = 300; // 30cm in mm

void setup() {
  Wire.begin();
  Serial.begin(115200);

  sensor1.init();
  sensor2.init();
  sensor3.init();

  sensor1.setTimeout(500);
  sensor2.setTimeout(500);
  sensor3.setTimeout(500);

  sensor1.startContinuous();
  sensor2.startContinuous();
  sensor3.startContinuous();
}

void loop() {
  int distance1 = sensor1.readRangeContinuousMillimeters();
  int distance2 = sensor2.readRangeContinuousMillimeters();
  int distance3 = sensor3.readRangeContinuousMillimeters();

  if (distance2 <= TURN_RIGHT_DISTANCE) {
    turnRight();
  } else if (distance3 <= TURN_LEFT_DISTANCE) {
    turnLeft();
  } else {
    moveForward();
  }

  delay(100);
}

void turnRight() {
  Serial.println("Turning right");
  // Add code to control motors for right turn
}

void turnLeft() {
  Serial.println("Turning left");
  // Add code to control motors for left turn
}

void moveForward() {
  Serial.println("Moving forward");
  // Add code to control motors for forward movement
}