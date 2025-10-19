#include <Adafruit_PCF8574.h>
#include <elapsedMillis.h>

// Create PCF8574 object
Adafruit_PCF8574 pcf;

//Create Millis
elapsedMillis millisLED;

// Motor control pins
#define IN4 7
#define IN3 2
#define IN2 4
#define IN1 3
#define ENA 5
#define ENB 6

// Ultrasonic sensor pins
#define TRIGGER_PINF  10 
#define ECHO_PINF     11  
#define TRIGGER_PINL  8
#define ECHO_PINL     9 
#define TRIGGER_PINR  12 
#define ECHO_PINR     13  
#define MAX_DISTANCE 200 

// Speed settings
#define SPEED_NORMAL 150
#define SPEED_TURN 180
#define SPEED_SHARP_TURN 200

// Button pin
#define BUTTON_PIN A6
#define BUTTON_THRESHOLD 100

#define INDICATOR_PIN 17
int BLINK_DELAY = 0;
bool currentLED = 0;

// Modes
#define MODE_STOP 0
#define MODE_LINE_FOLLOW 1
#define MODE_WALL_FOLLOW 2
#define MODE_BLUETOOTH 3
int currentMode = MODE_STOP;

// Ultrasonic distance thresholds (in cm)
#define WALL_DISTANCE_TARGET 15
#define WALL_DISTANCE_MIN 10
#define WALL_DISTANCE_MAX 20
#define OBSTACLE_DISTANCE 20

// Bluetooth command
char btCommand = 'S';

// IR sensor bit positions on PCF8574T
#define IR_LEFTMOST 0   // IO0
#define IR_LEFT 1       // IO1
#define IR_RIGHT 6      // IO6
#define IR_RIGHTMOST 7  // IO7

void motorControl(int in1Value, int in2Value, int in3Value, int in4Value, int leftSpeed, int rightSpeed) {
  digitalWrite(IN1, in1Value);
  digitalWrite(IN2, in2Value);
  digitalWrite(IN3, in3Value);
  digitalWrite(IN4, in4Value);
  analogWrite(ENB, rightSpeed);
  analogWrite(ENA, leftSpeed);
}

void setup() {
  Serial.begin(9600);
  
  // Initialize PCF8574
  if (!pcf.begin(0x20, &Wire)) {
    Serial.println("PCF8574 not found!");
    while (1);
  }
  
  // Set all pins as inputs
  for (uint8_t i = 0; i < 8; i++) {
    pcf.pinMode(i, INPUT);
  }
  
  // Initialize motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Initialize ultrasonic sensor pins
  pinMode(TRIGGER_PINF, OUTPUT);
  pinMode(ECHO_PINF, INPUT);
  pinMode(TRIGGER_PINL, OUTPUT);
  pinMode(ECHO_PINL, INPUT);
  pinMode(TRIGGER_PINR, OUTPUT);
  pinMode(ECHO_PINR, INPUT);
  
  delay(1000);
  Serial.println("Robot Started - Press button to change mode");
}

void loop() {
  // Check button press (A6 analog read)
  int buttonValue = analogRead(BUTTON_PIN);
  static bool lastButtonState = false;
  bool buttonPressed = (buttonValue < BUTTON_THRESHOLD);
  
  if (buttonPressed && !lastButtonState) {
    // Button just pressed - cycle through modes
    currentMode++;
    if (currentMode > MODE_BLUETOOTH) {
      currentMode = MODE_STOP;
    }
    
    Serial.print("Mode changed to: ");
    if (currentMode == MODE_STOP) Serial.println("STOP");
    else if (currentMode == MODE_LINE_FOLLOW) Serial.println("LINE FOLLOW");
    else if (currentMode == MODE_WALL_FOLLOW) Serial.println("WALL FOLLOW");
    else if (currentMode == MODE_BLUETOOTH) Serial.println("BLUETOOTH");
    
    delay(300); // Debounce
  }
  lastButtonState = buttonPressed;

  if (BLINK_DELAY < millisLED){
    if(!currentLED){
      digitalWrite(INDICATOR_PIN, HIGH);
      currentLED = 1;
    }else{
      digitalWrite(INDICATOR_PIN, LOW);
      currentLED = 0;
    }
    millisLED = 0;
  }
  
  // If in STOP mode, stop motors and return
  if (currentMode == MODE_STOP) {
    BLINK_DELAY = 10000;
    motorControl(LOW, LOW, LOW, LOW, 0, 0);
    delay(50);
    return;
  }
  
  // BLUETOOTH mode
  if (currentMode == MODE_BLUETOOTH) {
    BLINK_DELAY = 100;
    // Read bluetooth command from Serial
    if (Serial.available() > 0) {
      btCommand = Serial.read();
      Serial.print("BT Command: ");
      Serial.println(btCommand);
    }
    
    // Execute bluetooth command
    switch (btCommand) {
      case 'A': // Forward
        motorControl(, SPEED_NORMAL, SPEED_NORMAL);
        break;
      case 'B': // Backward
        motorControl(, SPEED_NORMAL, SPEED_NORMAL);
        break;
      case 'L': // Left
        motorControl(LOW, HIGH, HIGH, LOW, SPEED_TURN, SPEED_TURN);
        break;
      case 'R': // Right
        motorControl(HIGH, LOW, LOW, HIGH, SPEED_TURN, SPEED_TURN);
        break;
      case 'S': // Stop
      default:
        motorControl(LOW, LOW, LOW, LOW, 0, 0);
        break;
    }
    
    delay(10);
    return;
  }
  
  // WALL FOLLOW mode
  if (currentMode == MODE_WALL_FOLLOW) {
    BLINK_DELAY = 300;
    long distanceF = getDistance(TRIGGER_PINF, ECHO_PINF);
    long distanceL = getDistance(TRIGGER_PINL, ECHO_PINL);
    long distanceR = getDistance(TRIGGER_PINR, ECHO_PINR);
    
    Serial.print("Distances - F:");
    Serial.print(distanceF);
    Serial.print(" L:");
    Serial.print(distanceL);
    Serial.print(" R:");
    Serial.println(distanceR);
    
    // Obstacle in front - turn away from closest wall
    if (distanceF < OBSTACLE_DISTANCE) {
      if (distanceL < distanceR) {
        // Turn right
        motorControl(, SPEED_TURN, SPEED_TURN);
      } else {
        // Turn left
        motorControl(LOW, HIGH, HIGH, LOW, SPEED_TURN, SPEED_TURN);
      }
    }
    // Follow right wall
    else if (distanceR < WALL_DISTANCE_MIN) {
      // Too close to right wall - turn left
      motorControl(LOW, HIGH, HIGH, LOW, SPEED_TURN, SPEED_TURN);
    }
    else if (distanceR > WALL_DISTANCE_MAX) {
      // Too far from right wall - turn right
      motorControl(HIGH, LOW, LOW, HIGH, SPEED_TURN, SPEED_TURN);
    }
    else {
      // Good distance - go forward
      motorControl(HIGH, LOW, HIGH, LOW, SPEED_NORMAL, SPEED_NORMAL);
    }
    
    delay(10);
    return;
  }
  
  // LINE FOLLOW mode
  if (currentMode == MODE_LINE_FOLLOW) {
  BLINK_DELAY = 500;
  // Read sensors from PCF8574
  bool leftmost = !pcf.digitalRead(IR_LEFTMOST);
  bool left = !pcf.digitalRead(IR_LEFT);
  bool right = !pcf.digitalRead(IR_RIGHT);
  bool rightmost = !pcf.digitalRead(IR_RIGHTMOST);
  
  // Debug output
  Serial.print("Sensors: ");
  Serial.print(leftmost); Serial.print(" ");
  Serial.print(left); Serial.print(" ");
  Serial.print(right); Serial.print(" ");
  Serial.println(rightmost);
  
  // Line following logic
  if (!left && !right) {
    // Both middle sensors on line - forward
    motorControl(, SPEED_NORMAL, SPEED_NORMAL);
  }
  else if (!left || !leftmost) {
    // Left side sensors detect line - turn left
    motorControl(, SPEED_TURN, SPEED_TURN);
  }
  else if (!right || !rightmost) {
    // Right side sensors detect line - turn right
    motorControl(HIGH, LOW, LOW, HIGH, SPEED_TURN, SPEED_TURN);
  }
  else {
    // No line - stop
    motorControl(LOW, LOW, LOW, LOW, 0, 0);
  }
  
  delay(10);  // Small delay for stability
}
}

long getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 30000); // Timeout 30ms
  long distance = duration * 0.034 / 2; // Convert to cm
  
  if (distance == 0 || distance > MAX_DISTANCE) {
    return MAX_DISTANCE; // Return max if no echo or out of range
  }
  
  return distance;
}
