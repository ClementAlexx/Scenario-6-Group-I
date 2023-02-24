#include<Arduino.h>
#include<Proximity.h>
#include<Adafruit_CircuitPlayground.h>

int IR;
bool goodflow = false;
bool lowflow = false;
bool highflow = false;

void setup(){
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop(){
  CircuitPlayground.clearPixels();
  delay(200);
  digitalWrite(25, HIGH);
  delay(50);
  IR = analogRead(A8);
  digitalWrite(25, LOW);
  Serial.print("IR :");
  Serial.println(IR);
  if (IR>971){
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);   
    CircuitPlayground.setPixelColor(3, 255, 0, 0); 
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
    delay (100);
    if (lowflow==false){
      CircuitPlayground.playTone(100, 200);
      CircuitPlayground.playTone(300, 200);
      CircuitPlayground.playTone(500, 500);
      lowflow = true;
    }
  }
  if (IR>969 && IR<971){
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);   
    CircuitPlayground.setPixelColor(3, 0, 255, 0); 
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0);
    CircuitPlayground.setPixelColor(9, 0, 255, 0);
    delay(100); 
    if (goodflow==false){
      CircuitPlayground.playTone(300, 500);
      delay(500);
      CircuitPlayground.playTone(300, 500);
      delay(500);
      CircuitPlayground.playTone(300, 500);
      delay(500);
      CircuitPlayground.playTone(300, 1000);
      goodflow = true;  
    }       
  }
  if (IR<970){
    CircuitPlayground.setPixelColor(0, 255, 111, 234);
    CircuitPlayground.setPixelColor(1, 255, 111, 234);
    CircuitPlayground.setPixelColor(2, 255, 111, 234);   
    CircuitPlayground.setPixelColor(3, 255, 111, 234);
    CircuitPlayground.setPixelColor(4, 255, 111, 234);
    CircuitPlayground.setPixelColor(5, 255, 111, 234);
    CircuitPlayground.setPixelColor(6, 255, 111, 234);
    CircuitPlayground.setPixelColor(7, 255, 111, 234);
    CircuitPlayground.setPixelColor(8, 255, 111, 234);
    CircuitPlayground.setPixelColor(9, 255, 111, 234);
    delay(100);
    if (highflow == false){
      CircuitPlayground.playTone(1000, 100);
      delay(100);
      CircuitPlayground.playTone(1000, 100);
      delay(100);
      CircuitPlayground.playTone(1000, 100);
      delay(100);
      CircuitPlayground.playTone(1000, 100);
      highflow = true;
    }
  } 
}
