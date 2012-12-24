
#include "Tlc5940.h"
//48 // 96 // 144 // 192
#define N_LIGHTS 96

int values[N_LIGHTS];
int readCount;


void setup(){

  Serial.begin(115200);
  Tlc.init();
  readCount = 0;
  for (int i = 0; i < N_LIGHTS; i++){
    values[i] = 0;
  }
}


void loop(){
 
    /* Tlc.clear() sets all the grayscale values to zero, but does not send
       them to the TLCs.  To actually send the data, call Tlc.update() */
    Tlc.clear();

    while (Serial.available() > 0) {
      int inByte = Serial.read();
      
      if (inByte == 255){
        readCount = 0;
      } else {
        if (readCount < N_LIGHTS){
        values[readCount] = inByte;
        }
        readCount++;
        
      }
      //readCount %= N_LIGHTS;
    }
   

    for (int i = 0; i < N_LIGHTS; i++){
      float valMapped = map(values[i], 0, 254, 0, 4095); //4095
      Tlc.set(i, valMapped);
    }

    Tlc.update();
    //delay(5);
}

