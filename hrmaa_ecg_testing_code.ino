// Code prints the ecg reading directly to the Serial of the bluetooth as well as Serial of the arduino.
// Currently testing the ecg data on data stream streamer of excel, would like to make programmatical soln to it soon

#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3); // RX | TX
int waitingLED=4;

//Sayani_ka_ecg
int LONeg = 10;
int LOPos = 11;
int ECGRead = A0;

void setup() {

  BTserial.begin(9600); 
  Serial.begin(9600);

  pinMode( LONeg, INPUT);
  pinMode( LOPos, INPUT); 

}

void loop() {
  digitalWrite(waitingLED,HIGH);
  //necesssary to wait else, the arduino will keep on taking in values and put it in the 
  //output buffer. From where they will flood into the android
  //on connection

  //BTserial.read() on input 1 wont give 1, it will give 210
  digitalWrite(waitingLED,LOW);
  
  if((digitalRead(LONeg) == 1) || (digitalRead(LOPos) == 1)){
    BTserial.println("!");
    Serial.println("!");
  }
  else{
    time=millis();
    //Serial.println(time);
    time = time * 1000;
    BTserial.println(analogRead(ECGRead)+time);
    Serial.println(analogRead(ECGRead));
  }
  delay(5);
}