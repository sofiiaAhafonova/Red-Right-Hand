#include <Servo.h>//for working with servo-motor
//define the servo name
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

//int msg[1];
int data; //data variable
int pos; //position variable

//define the flex sensor input pins
int flex_1 = A1; //великий палець
int flex_2 = A2; //вказівний палець
int flex_3 = A3; //середній палець
int flex_4 = A4; //безіменний і мізінець

//define variables for flex sensor values
int flex_1_val;
int flex_2_val;
int flex_3_val;
int flex_4_val;
int flex_5_val;

                //5 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
void setup(void){
  //define the servo input pins
  myServo1.attach(5); //великий палець
  myServo2.attach(6); //вказівниковий
  myServo3.attach(9); //середній
  myServo4.attach(10); //безіменний
  myServo5.attach(11); //мізінець

  Serial.begin(9600);
}

void loop(){
  //Великий палець
  flex_1_val = analogRead(flex_1);
                            //175 - 0
  flex_1_val = map(flex_1_val, 1023, 0, 255, 0);
  pos = map(flex_1_val, 130, 170, 0, 180); 
  //Serial.println(pos);
  myServo1.write(pos);
  //Вказівний палець 
   flex_2_val = analogRead(flex_2);
   flex_2_val = map(flex_2_val, 1023, 0, 255, 0);
   pos = map(flex_2_val, 130, 170, 0, 180);
   myServo2.write(pos); 
  //Середній палець
  flex_3_val = analogRead(flex_3);
   flex_3_val = map(flex_3_val, 1023, 0, 255, 0);
   pos = map(flex_3_val, 130, 170, 0, 180);
   myServo3.write(pos);
  //Безіменний
   flex_4_val = analogRead(flex_4);
   flex_4_val = map(flex_4_val, 1023, 0, 255, 0);
   pos = map(flex_4_val, 130, 170, 0, 180);
   myServo4.write(pos);  
   myServo5.write(pos); 
}
