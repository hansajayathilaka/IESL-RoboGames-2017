#include <QTRSensors.h>
#include <Servo.h>

Servo s1, s2, s3;

int const RB = 8;
int const RF = 9;
int const LB = 11;
int const LF = 10;
int const cal = 53;

int x = 0;

byte const trigPin = 24;
byte const echoPin = 22;

byte clr = 0;

int lastError = 0;
int error = 0;
//kp 0.02 kd 0.5 max 150 def 80
//kp 0.02 kd 0.7 max 220 def 110
int MAXsp = 255;
long junkdelay = 0;

unsigned int DEFAULTsp = 100;

int integral = 0;
#define KP 0.05
float KD = 0.7;
#define KI 0.001
#define NUM_SENSORS   8     // number of sensors used tharuindu paka
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   QTR_NO_EMITTER_PIN     // emitter is controlled by digital pin 2 ta ukanda
QTRSensorsRC qtrrc((unsigned char[]) {
  A0, A1, A2, A3, A4, A5, A6, A7
}, NUM_SENSORS, TIMEOUT, QTR_NO_EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];



void go(int leftSpeed, int rightSpeed, int MAX = MAXsp);
void line_follow(unsigned int DEFAULT_SPEED = DEFAULTsp, unsigned int MAX = MAXsp);



void setup() {

  s1.attach(3);
  s2.attach(4);
  s3.attach(5);
  s1.write(0);
  s2.write(40);
  s3.write(180);

  pinMode(LF, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(cal, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Calibrate() ;

  while (digitalRead(cal) == 0) {
  }
  delay(200);
  go(0, 0);
  delay(40);
}

void loop() {
  if ((sensorValues[0]) > 700 && (sensorValues[7]) > 700) {
    clr = 1;//black line
  }
  if ((sensorValues[0]) < 700 && (sensorValues[7]) < 700) {
    clr = 0;
  }
  if (D(0) == 1 && D(1) == 1 && D(2) == 1 &&  D(7) == 0) {
    go(-100, 100);
    delay(40);
  }
  if (D(7) == 1 && D(6) == 1 && D(5) == 1 &&  D(0) == 0) {
    go(100, -100);
    if (clr == 0) {
      delay(200);
    } else {
      delay(40);
    }
  }
  if (clr == 0 && dis() < 5 && x == 0) {
    go(0, 0);
    box();
    go(200, -200);
    delay(300);
    x = 1;
  }
  if (clr == 1 && x == 1) {
    if (D(0) == 1 && D(1) == 1 && D(2) == 1 &&  D(3) == 1 && D(4) == 1 && D(5) == 1 &&  D(6) == 6 && D(7) == 1)
      go(0, 0);
      delay(1000);
  }
  line_follow();
}
