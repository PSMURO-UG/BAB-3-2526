#include <NewPing.h>
#include <elapsedMillis.h>
elapsedMillis timer1;
elapsedMillis timer2;

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


NewPing sonarF(TRIGGER_PINF, ECHO_PINF, MAX_DISTANCE);
NewPing sonarL(TRIGGER_PINL, ECHO_PINL, MAX_DISTANCE);
NewPing sonarR(TRIGGER_PINR, ECHO_PINR, MAX_DISTANCE);
int distanceF, distanceR, distanceL, currentOrient;
void setup() {
 pinMode(kiriMaju, OUTPUT);
 pinMode(kiriMundur, OUTPUT);
 pinMode(kananMaju, OUTPUT);
 pinMode(kananMundur, OUTPUT);
 pinMode(speedKanan, OUTPUT);
 pinMode(speedKiri, OUTPUT);
 Serial.begin(115200);
}
void loop() {
 distanceF = sonarF.ping_cm();
 distanceL = sonarL.ping_cm();
 distanceR = sonarR.ping_cm();
 if (distanceF >=5) {
 // Maju lurus kalau gak ada halangan
 Serial.println("MAJU");
 motorControl(1, 0, 1, 0, 80, 80);
 } else {
 // Terlalu dekat, mundur dulu
 Serial.println("Halangan di depan, mundur sebentar");
 motorControl( 80, 80);
 delay(300);
 // Stop sebentar
 motorControl();
 delay(2500);
 // Bandingkan kiri dan kanan
 if (distanceL < distanceR) {
 Serial.println("Belok Kiri");
 motorControl(0,1, 1, 0, 80, 80); // Belok kiri
 delay(400);
 motorControl(0, 0, 0, 0, 0, 0);
 delay(500);
 } else {
 Serial.println("Belok kanan");
 }
 // Stop sebentar setelah belok
 motorControl(0, 0, 0, 0, 0, 0);
 delay(500);
 }
}
void motorControl(int In1, int In2, int In3, int In4, int SpeedL, int SpeedR){
 digitalWrite(IN1, In1);
 digitalWrite(IN2, In2);
 digitalWrite(IN3, In3);
 digitalWrite(IN4, In4);
 analogWrite(ENA, SpeedL);
 analogWrite(ENB, SpeedR);
}
