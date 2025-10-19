#include <Adafruit_PCF8574.h>

// Create PCF8574 object
Adafruit_PCF8574 pcf;

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
  
  delay(1000);
  Serial.println("Line Follower Started");
}

void loop() {
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
  Serial.print(rightmost);
  
  // Line following logic
  if (left && right){
    // stop
    Serial.println("  Stop");
    motorControl(LOW, LOW, LOW, LOW, 0, 0);
  }else if (!left && !right) {
    // Forward
    Serial.println("  Maju");
    motorControl(HIGH, LOW, HIGH, LOW, SPEED_NORMAL, SPEED_NORMAL);
  }else if (left || leftmost) {
    // Turn Left
    Serial.println("  Kiri");
    motorControl(LOW, HIGH, HIGH, LOW, SPEED_TURN, SPEED_TURN);
  }
  else if (right || rightmost) {
    // Turn Right
    Serial.println("  Kanan");
    motorControl(HIGH, LOW, LOW, HIGH, SPEED_TURN, SPEED_TURN);
  }
  
  delay(10);  // Small delay for stability
}
