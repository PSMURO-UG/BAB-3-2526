#include <SoftwareSerial.h>

#define HCRx 16
#define HCTx 15
SoftwareSerial HC05(HCRx, HCTx);

// Motor control pins
#define IN4 7
#define IN3 2
#define IN2 4
#define IN1 3
#define ENA 5
#define ENB 6

void setup() {
 pinMode(IN4, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(SpeedKiri, OUTPUT);
 pinMode(SpeedKanan, OUTPUT);
 Serial.begin(115200);
 HC05.begin(9600);
}
void loop()
{
 char c;
String voice;
 while (HC05.available())
 {
 delay (10);
 c = HC05.read();
 voice += c;
 }
 if (voice.length()>0)
 {
 Serial.println (voice);
 if (voice == "forward" || voice == "forwards" ||voice == "maju" || voice == “A”)
 {
 //Forward
 motorControl(1,0,1,0,255,255);
 delay (1000);
 }
 else if (voice == "backward" || voice == "backwards" ||voice == "mundur" || voice == “C”)
 {
 //Backward
 delay (1000);
 }
 else if (voice == "right" || voice == "kanan" || voice == “B”)
 {
 //Turn Right
 delay (500);
 }
 else if (voice == "left" || voice == "kiri" || voice == “D”)
 {
 //Right
 delay (500);
 }
 else
 {
 //Stop
 }
 voice = "";
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
