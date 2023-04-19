#define USE_NIMBLE
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;



const int Pin_Potentiometer = 26;  /*Potentiometer connected at GPIO 25 (Analog ADC2_CH8)*/

int Val_Potentiometer = 0;

bool keyStates[2] = {0, 0};
int x1 = 0;
int x2 = 0;

uint8_t keyCodes[2] = {'w','s'};


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
  if(Val_Potentiometer < 2000 ){
    if ( Val_Potentiometer > 1600){
    Serial.println('W');
    handleButton(1);
  }
  
  else if(Val_Potentiometer < 1600 and Val_Potentiometer > 1000){
    Serial.println('S');
    handleButton(0);/*Prints Potentiometer value*/
  }
  }
  else if (Val_Potentiometer > 2000){
      for( int i=0; i < 2; i++){
      // key currently pressed
      x1 = 0;
      x2 = 0;
      keyStates[i] = 1;
      bleKeyboard.release(keyCodes[i]);
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
  if (Val_Potentiometer < 2000) {
    // button pressed
    if (Val_Potentiometer < 2000 and Val_Potentiometer > 1600  and x1 == 0){
      // key not currently pressed
      x1 = 1;
      bleKeyboard.press(keyCodes[0]);
    }
    else if (Val_Potentiometer < 1600 and x2== 0){
      // key not currently pressed
      x2 = 1;
      bleKeyboard.press(keyCodes[1]);
    }
  }
  else if(Val_Potentiometer > 2000) {
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
