#define USE_NIMBLE
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

// 13 - 2700 - 26
//12 - 3100 - 25
//5 - 3600 - 27    2400<

const int flex1 = 26;  
const int flex2 = 25;
const int flex3 = 27;

int Val_flex1 = 0;
int Val_flex2 = 0;
int Val_flex3 = 0;

bool keyStates[2] = {0, 0};
int x1 = 0;
int x2 = 0;

bool keyStates2[2] = {0,0};
int x3 = 0;
int x4 = 0;

bool keyStates3[2] = {0,0};
int x5 = 0;
int x6 = 0;

uint8_t keyCodes[2] = {'w','s'};
uint8_t keyCodes2[2] = {'a','d'};
uint8_t keyCodes3[2] = {'z','x'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Code running...");
  bleKeyboard.begin();
  
}

bool connectNotificationSent = false;


void loop() {

  int counter;
  if(bleKeyboard.isConnected()) {
    if (!connectNotificationSent) {
      Serial.println("Code connected...");
      connectNotificationSent = true;
    }
  Val_flex1 = analogRead(flex1); 
  Serial.println(Val_flex1);
  Val_flex2 = analogRead(flex2); 
  Serial.println(Val_flex2);
  Val_flex3 = analogRead(flex3); 
  Serial.println(Val_flex3);
  
  

  
if(Val_flex1 < 2000 ){
    if ( Val_flex1 > 1500){
    Serial.println('W');
    handleButton(1);
  }
  
  else if(Val_flex1 < 1500 and Val_flex1 > 1000){
    Serial.println('S');
   handleButton(0);
  }
  }
  else if (Val_flex1 > 2000){
      for( int i=0; i < 2; i++){
      // key currently pressed
      x1 = 0;
      x2 = 0;
      keyStates[i] = 1;
      bleKeyboard.release(keyCodes[i]);
    }
    }


if(Val_flex2 < 2800 ){
    if ( Val_flex2 > 2400){
    Serial.println('a');
    handleButton2(1);
  }
  
  else if(Val_flex2 < 2400 and Val_flex2 > 1800){
    Serial.println('d');
    handleButton2(0);/*Prints Potentiometer value*/
  }
  }
  else if (Val_flex2 > 2800){
      for( int i=0; i < 2; i++){
      // key currently pressed
      x3 = 0;
      x4 = 0;
      keyStates2[i] = 1;
      bleKeyboard.release(keyCodes2[i]);
    }
    }

if(Val_flex3 < 3000 ){
    if ( Val_flex3 > 2700){
    Serial.println('flex3 1');
    handleButton3(1);
  }
  
  else if(Val_flex3 < 2600 and Val_flex3 > 2000){
    Serial.println('flex3 2');
   handleButton3(0);
  }
  }
  else if (Val_flex3 > 3000){
      for( int i=0; i < 2; i++){
      // key currently pressed
      x5 = 0;
      x6 = 0;
      keyStates3[i] = 1;
      bleKeyboard.release(keyCodes3[i]);
    }
    }    
    
    delay(250);
  } 
}





void handleButton(int keyIndex){
  // handle the button press
  if (Val_flex1 < 2000) {
    // button pressed
    if (Val_flex1 < 2000 and Val_flex1 > 1500  and x1 == 0){
      // key not currently pressed
      x1 = 1;
      bleKeyboard.press(keyCodes[0]);
    }
    else if (Val_flex1 < 1500 and x2== 0){
      // key not currently pressed
      x2 = 1;
      bleKeyboard.press(keyCodes[1]);
    }
  }
  else if(Val_flex1 > 2000) {
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
  if (Val_flex2 < 2800) {
    // button pressed
    if (Val_flex2 < 2800 and Val_flex2 > 2400  and x3 == 0){
      // key not currently pressed
      x3 = 1;
      bleKeyboard.press(keyCodes2[0]);
    }
    else if (Val_flex2 < 2400 and x4 == 0){
      // key not currently pressed
      x4 = 1;
      bleKeyboard.press(keyCodes2[1]);
    }
  }
  else if(Val_flex2 > 2800) {
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


void handleButton3(int keyIndex){
  if (Val_flex3 < 3000) {
    // button pressed
    if (Val_flex3 < 3000 and Val_flex3 > 2700  and x5 == 0){
      // key not currently pressed
      x5 = 1;
      bleKeyboard.press(keyCodes3[0]);
    }
    else if (Val_flex3 < 2600 and x6 == 0){
      // key not currently pressed
      x6 = 1;
      bleKeyboard.press(keyCodes3[1]);
    }
  }
  else if(Val_flex3 > 3000) {
    // button not pressed
    for( int i=0; i < 2; i++){
      // key currently pressed
      x5 = 0;
      x6 = 0;
      keyStates3[i] = 1;
      bleKeyboard.release(keyCodes3[i]);
    }
  }
  }  
