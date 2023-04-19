const int Pin_Potentiometer = 26;  /*Potentiometer connected at GPIO 25 (Analog ADC2_CH8)*/
int Val_Potentiometer = 0;        /*Potentiometer read value will be stored here*/
void setup() {
  Serial.begin(115200);          /*Serial communication begins*/
}
void loop() {
  Val_Potentiometer = analogRead(Pin_Potentiometer); /*Reading potentiometer value*/
  Serial.println(Val_Potentiometer);
  if(Val_Potentiometer > 3700){
    Serial.println('A');/*Prints Potentiometer value*/
  }
  else if ( Val_Potentiometer < 3700){
    Serial.println('B');
  }
  delay(500);                     /*delay of 2sec*/
}
