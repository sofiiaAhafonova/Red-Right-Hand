#include <Servo.h>//for working with servo-motor
//define the servo name
Servo myServo1;
int msg[1];
int data; //data variable
int pos; //position variable

//define the flex sensor input pins
int flex_1 = A1;

//define variables for flex sensor values
int flex_1_val;
                //5 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
void setup(void){
  //define the servo input pins
  myServo1.attach(9); //A1
  Serial.begin(9600);
}

void loop(){
  flex_1_val = analogRead(flex_1);
                            //175 - 0
  flex_1_val = map(flex_1_val, 1023, 0, 255, 0);
  pos = map(flex_1_val, 130, 170, 0, 180); 
  Serial.println(pos);
  myServo1.write(pos); 
  
  

}
