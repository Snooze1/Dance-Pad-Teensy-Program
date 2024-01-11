#include <Keyboard.h>

void setup() {
#define DB_Val 4000         // Debounce
//#define FSR1_Thresh 310
//#define FSR2_Thresh 340
//#define FSR3_Thresh 440
//#define FSR4_Thresh 340

#define FSR1_Thresh 340
#define FSR2_Thresh 440
#define FSR3_Thresh 440
#define FSR4_Thresh 440

#define FSR1 21
#define FSR2 20
#define FSR3 19
#define FSR4 18
}
int val1;
int val2;
int val3;
int val4;

int FSR1_Debounce = 30000;
int FSR2_Debounce = 30000;
int FSR3_Debounce = 30000;
int FSR4_Debounce = 30000;

int FSR1_DBFlag = 0;
int FSR2_DBFlag = 0;
int FSR3_DBFlag = 0;
int FSR4_DBFlag = 0;

void loop()
{
  Keyboard.begin();
  val1 = analogRead(FSR1);                   // Reads current Up Arrow Pressure
  val2 = analogRead(FSR2);                   // Reads current Right Arrow Pressure
  val3 = analogRead(FSR3);                   // Reads current Right Arrow Pressure
  val4 = analogRead(FSR4);                   // Reads current Right Arrow Pressure
  Visualization();


  //// UP ARROW LOGIC
  if (val1 > FSR1_Thresh) {                // If we pass our user defined threshold:
    Keyboard.press(KEY_UP_ARROW);           // Press arrow
    FSR1_DBFlag = 1;
  }
  else {
    Keyboard.release(KEY_UP_ARROW);         // Release arrow when we drop below threshold
  }

  if (val2 > FSR2_Thresh) {
    Keyboard.press(KEY_RIGHT_ARROW);
    FSR2_DBFlag = 1;
  }
  else {
    Keyboard.release(KEY_RIGHT_ARROW);
  }

  if (val3 > FSR3_Thresh) {
    Keyboard.press(KEY_DOWN_ARROW);
    FSR3_DBFlag = 1;
  }
  else {
    Keyboard.release(KEY_DOWN_ARROW);
  }

  if (val4 > FSR4_Thresh) {
    Keyboard.press(KEY_LEFT_ARROW);
    FSR4_DBFlag = 1;
  }
  else {
    Keyboard.release(KEY_LEFT_ARROW);

  }

  //Debounce Up
  if ((FSR1_Debounce > DB_Val) &&  FSR1_DBFlag == 1) {
    FSR1_DBFlag = 0;
    FSR1_Debounce = 0;
  }
  else if (FSR1_DBFlag == 1) {
    FSR1_Debounce++;
  }
  //Debounce Right
  if ((FSR2_Debounce > DB_Val) &&  FSR2_DBFlag == 1) {
    FSR2_DBFlag = 0;
    FSR2_Debounce = 0;
  }
  else if (FSR2_DBFlag == 1) {
    FSR2_Debounce++;
  }
  //Debounce Down
  if ((FSR3_Debounce > DB_Val) &&  FSR3_DBFlag == 1) {
    FSR3_DBFlag = 0;
    FSR3_Debounce = 0;
  }
  else if (FSR3_DBFlag == 1) {
    FSR3_Debounce++;
  }
  //Debounce Left
  if ((FSR4_Debounce > DB_Val) &&  FSR4_DBFlag == 1) {
    FSR4_DBFlag = 0;
    FSR4_Debounce = 0;
  }
  else if (FSR4_DBFlag == 1) {
    FSR4_Debounce++;
  }
}

void Visualization() {
  Serial.print("Up/Right/Down/Left is: ");
  Serial.print(val1);
  Serial.print("/");
  Serial.print(val2);
  Serial.print("/");
  Serial.print(val3);
  Serial.print("/");
  Serial.println(val4);
}
