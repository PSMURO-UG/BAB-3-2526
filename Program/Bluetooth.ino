#include <SofwareSerial.h>
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 7
#define ENA 6
#define ENB 5
#define HCRx 15
#define HCTx 16
SoftwarSerial HC05();
void setup() {
 // put your setup code here, to run once:
 pinMode(kiriMaju, OUTPUT);
 pinMode(kiriMundur, OUTPUT);
 pinMode(kananMaju, OUTPUT);
 pinMode(kananMundur, OUTPUT);
 pinMode(speedKanan, OUTPUT);
 pinMode(speedKiri, OUTPUT);
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
 if (voice == "forward" || voice == "forwards" ||
 voice == "maju" || voice == “A”)
 {
 //Forward
 motorControl(1,0,1,0,255,255);
 delay (1000);
 }
 else if (voice == "backward" || voice == "backwards" ||
 voice == "mundur" || voice == “C”)
 {
 //Backward
 delay (1000);
 }
 else if (voice == "right" ||
 voice == "kanan" || voice == “B”)
 {
 //Turn Right
 delay (500);
 }
 else if (voice == "left" ||
 voice == "kiri" || voice == “D”)
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
void motorControl(int In1, int In1, int In1, int In1, int SpeedL, int SpeedR){
 digitalWrite(IN1, In1);
 digitalWrite(IN2, In2);
 digitalWrite(IN3, In3);
 digitalWrite(IN4, In4);
 analogWrite(ENA, SpeedL);
 analogWrite(ENB, SpeedR);
}
