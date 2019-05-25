#include <Servo.h>

int r = 90 ;

const int servo1 = 3; //Высота

const int servo2 = 4; // По горизонтали

const int servo3 = 7;

const int servo4 = 2;

const int joyH = 0; // выход L/R джойстика Parallax

const int joyV = 1; // выход U/D джойстика Parallax


int servoVal; // для хранения данных 

Servo myservo1;

Servo myservo2;

Servo servo;
Servo myservo4;
void setup() {
  pinMode( 5, INPUT);
  pinMode( 8, INPUT);
  pinMode( 9, INPUT);

  // Servo
  servo.attach(servo3);

  myservo1.attach(servo1);

  myservo2.attach(servo2);

  myservo4.attach(servo4);


  Serial.begin(9600);

}

void loop() {

  if (digitalRead(5)) {
    r--*8;   
   
  }
  if (digitalRead(8)) {
    r++*8;
   

  }
Serial.println(r);



  servo.write(r);

  outputJoystick();



  servoVal = analogRead(joyH);

  servoVal = map(servoVal, 0, 1023, 0, 180);

  myservo2.write(servoVal);


  servoVal = analogRead(joyV);

  servoVal = map(servoVal, 0, 1023, 0, 180);

  myservo1.write(servoVal);
  delay(15);



  if (digitalRead(9)) {
    myservo4.write(180);

  }
  else {
    myservo4.write(75);
  }
}



void outputJoystick() {

  Serial.print(analogRead(joyH));

  Serial.print ("---");

  Serial.print(analogRead(joyV));

  Serial.println ("----------------");

}


