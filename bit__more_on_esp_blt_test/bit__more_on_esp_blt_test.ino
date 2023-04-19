#define USE_NIMBLE
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

// 13 - 2700 -26
//12 - 3100 - 25

const int Pin_Potentiometer = 26;  /*Potentiometer connected at GPIO 25 (Analog ADC2_CH8)*/
const int flex2 = 25;
int Val_Potentiometer = 0;
int Val_flex2 = 0;

bool keyStates[2] = {0, 0};
int x1 = 0;
int x2 = 0;

bool keyStates2[2] = {0,0};
int x3 = 0;
int x4 = 0;

uint8_t keyCodes[2] = {'w','s'};
uint8_t keyCodes2[2] = {'a','d'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Code running...");
  bleKeyboard.begin();
  
}

bool connectNotificationSent = false;


void loop() {
  // put your main code here, to run repeatedly:

  int counter;
  if(bleKeyboard.isConnected()) {
    if (!connectNotificationSent) {
      Serial.println("Code connected...");
      connectNotificationSent = true;
    }
  Val_Potentiometer = analogRead(Pin_Potentiometer); /*Reading potentiometer value*/
  Serial.println(Val_Potentiometer);
  Val_flex2 = analogRead(flex2); /*Reading potentiometer value*/
  Serial.println(Val_flex2);

  
if(Val_Potentiometer < 2300 ){
    if ( Val_Potentiometer > 1900){
    Serial.println('W');
    handleButton(1);
  }
  
  else if(Val_Potentiometer < 1800 and Val_Potentiometer > 1500){
    Serial.println('S');
   handleButton(0);/*Prints Potentiometer value*/
  }
  }
  else if (Val_Potentiometer > 2300){
      for( int i=0; i < 2; i++){
      // key currently pressed
      x1 = 0;
      x2 = 0;
      keyStates[i] = 1;
      bleKeyboard.release(keyCodes[i]);
    }
    }


if(Val_flex2 < 3000 ){
    if ( Val_flex2 > 2600){
    Serial.println('a');
    handleButton2(1);
  }
  
  else if(Val_flex2 <2600 and Val_flex2 > 2200){
    Serial.println('d');
    handleButton2(0);/*Prints Potentiometer value*/
  }
  }
  else if (Val_flex2 > 3000){
      for( int i=0; i < 2; i++){
      // key currently pressed
      x3 = 0;
      x4 = 0;
      keyStates2[i] = 1;
      bleKeyboard.release(keyCodes2[i]);
    }
    }
    
    delay(1000);
  } 
}







//
//void setInputs() {
//  pinMode(GP_A, INPUT_PULLUP);
//  pinMode(GP_B, INPUT_PULLUP);
//}



void handleButton(int keyIndex){
  // handle the button press
  if (Val_Potentiometer < 2300) {
    // button pressed
    if (Val_Potentiometer < 2300 and Val_Potentiometer > 1900  and x1 == 0){
      // key not currently pressed
      x1 = 1;
      bleKeyboard.press(keyCodes[0]);
    }
    else if (Val_Potentiometer < 1800 and x2== 0){
      // key not currently pressed
      x2 = 1;
      bleKeyboard.press(keyCodes[1]);
    }
  }
  else if(Val_Potentiometer > 2300) {
    // button not pressed
    for( int i=0; i < 2; i++){
      // key currently pressed
      x1 = 0;
      x2 = 0;
      keyStates[i] = 1;
      bleKeyboard.release(keyCodes[i]);
    }
  }
  }


void handleButton2(int keyIndex){
  // handle the button press
  if (Val_flex2 < 3000) {
    // button pressed
    if (Val_flex2 < 3000 and Val_flex2 > 2600  and x3 == 0){
      // key not currently pressed
      x3 = 1;
      bleKeyboard.press(keyCodes2[0]);
    }
    else if (Val_flex2 < 2600 and x4 == 0){
      // key not currently pressed
      x4 = 1;
      bleKeyboard.press(keyCodes2[1]);
    }
  }
  else if(Val_flex2 > 3000) {
    // button not pressed
    for( int i=0; i < 2; i++){
      // key currently pressed
      x3 = 0;
      x4 = 0;
      keyStates2[i] = 1;
      bleKeyboard.release(keyCodes2[i]);
    }
  }
  }





















//void handleButton2(int keyIndex){
//  // handle the button press
//  if (!digitalRead(keyPins[keyIndex])){
//    // button pressed
//    if (!keyStates[keyIndex]){
//      // key not currently pressed
//      keyStates[keyIndex] = true;
//      bleKeyboard.press(keyCodes[keyIndex]);
//    }
//  }
//  else {
//    // button not pressed
//    if (keyStates[keyIndex]){
//      // key currently pressed
//      keyStates[keyIndex] = false;
//      bleKeyboard.release(keyCodes[keyIndex]);
//    }
//  }
//}












//void handleButton(int keyIndex){
//  // handle the button press
//  if (!digitalRead(keyPins[keyIndex])){
//    // button pressed
//    if (!keyStates[keyIndex]){
//      // key not currently pressed
//      keyStates[keyIndex] = true;
//      bleKeyboard.press(keyCodes[keyIndex]);
//    }
//  }
//  else {
//    // button not pressed
//    if (keyStates[keyIndex]){
//      // key currently pressed
//      keyStates[keyIndex] = false;
//      bleKeyboard.release(keyCodes[keyIndex]);
//    }
//  }
//}
