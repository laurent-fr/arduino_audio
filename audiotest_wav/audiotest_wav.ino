
#include "sound_data.h"


int length=sizeof(sound_data)/2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  analogWriteResolution(12);
  Serial.begin(115200);
  
}

// the loop function runs over and over again forever
void loop() {

  long t0=micros();

  Serial.println(length);

  for(int i=0;i<length;i++) {

    long t=micros();
    long elapsed=i*100000/2205;
    if (elapsed>(t-t0)) delayMicroseconds(elapsed-t+t0);
   
    int out=sound_data[i]/16+2048;
    //Serial.println(out);
    
   analogWrite(DAC0,out);
    
  }

  Serial.println(micros()-t0);

  while(1) delay(1000);
  
}
