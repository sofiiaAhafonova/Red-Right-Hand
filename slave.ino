#include <Servo.h>
#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial BTSerial(2, 3);
String input = "";
const char control_symbol = '#';

Servo thumb;
Servo pointer;
Servo middle;
Servo ring;
Servo little;

int thumb_val = 0;
int pointer_val = 0;
int middle_val = 0;
int ring_val = 0;

void setup(void)
{
  thumb.attach(4); //великий палець
  pointer.attach(5); //вказівниковий
  middle.attach(6); //середній
  ring.attach(7); //безіменний
  little.attach(8); //мізінець

  Serial.begin(9600);
  BTSerial.begin(38400);  
}

using namespace std;

void loop()
{
  while(BTSerial.available())
  {
    char c = (char)BTSerial.read();
    if(c != control_symbol) input += c;
    else {
      sscanf(input.c_str(),"%i,%i,%i,%i",&thumb_val,&pointer_val,&middle_val,&ring_val);
      Serial.println(thumb_val);
      thumb.write(thumb_val);
      Serial.println(pointer_val);
      pointer.write(pointer_val);
      Serial.println(middle_val);
      middle.write(middle_val);
      Serial.println(ring_val);
      ring.write(ring_val);
      Serial.println(ring_val);
      little.write(ring_val);
      Serial.println();
      input = "";
      break;
    }
  }
}
