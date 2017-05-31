#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX

char * write_to_str(int pos1, int pos2, int pos3, int pos4) {
    static char str[20];
    sprintf(str,"%i,%i,%i,%i", pos1,pos2,pos3,pos4);
    return str;
}

int pos1 = 0; //A1
int pos2 = 0; //A2
int pos3 = 0; //A2
int pos4 = 0; //A2

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

void setup(void){
    Serial.begin(9600);
    BTSerial.begin(38400);  		
}

void loop(void){
  /**
   * Зчитування з рукавиці і перетворення даних
   *
  **/			
  flex_1_val = analogRead(flex_1);
                
  flex_1_val = map(flex_1_val, 1023, 0, 255, 0);
  pos1 = map(flex_1_val, 130, 170, 0, 180); 

  flex_2_val = analogRead(flex_2);
    
  flex_2_val = map(flex_2_val, 1023, 0, 255, 0);
  pos2 = map(flex_2_val, 130, 170, 0, 180); 	

  flex_3_val = analogRead(flex_3);
                
  flex_3_val = map(flex_3_val, 1023, 0, 255, 0);
  pos3 = map(flex_3_val, 130, 170, 0, 180); 

  flex_4_val = analogRead(flex_4);
                
  flex_4_val = map(flex_4_val, 1023, 0, 255, 0);
  pos4 = map(flex_4_val, 130, 170, 0, 180); 	
  
  /**
   *sending walue by bluetooth to servomotors
  **/
   BTSerial.write('#');
   BTSerial.write(write_to_str(pos1,pos2,pos3,pos4)); 
   Serial.println(write_to_str(pos1,pos2,pos3,pos4));
   delay(100);

  	
}


