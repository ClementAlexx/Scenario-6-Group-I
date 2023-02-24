#include<Arduino.h>
#include<Proximity.h>
#include<Adafruit_CircuitPlayground.h>

int IR; //Create integer variable of IR light level
bool goodflow = false; //Create bolean variable to determine if the goodflow sound has played, set initial value to it hasn't happened 
bool lowflow = false; //Create bolean variable to determine if the lowflow sound has played, set initial value to it hasn't happened
bool highflow = false; //Create bolean variable to determine if the highflow sound has played, set initial value to it hasn't happened

void setup(){
  Serial.begin(9600); //Begin communication with computer 
  CircuitPlayground.begin(); //Initialise the CircuitPlayground 
}

void loop(){
  CircuitPlayground.clearPixels(); //Turn off all neopixels 
  delay(200); //Delay to prevent IR transmitter overheating 
  digitalWrite(25, HIGH); //Turn on IR transmitter 
  delay(50); //Delay to allow the IR to reflect 
  IR = analogRead(A8); //Read the IR light level at receiver and assign value to variable IR
  digitalWrite(25, LOW); //Turn off IR transmitter 
  Serial.print("IR :"); //Print the value of IR
  Serial.println(IR);
  if (IR>971){ //Threshold of low flow - hold puck at the bottom and adjust the value to whatever is shown on serial monitor
    CircuitPlayground.setPixelColor(0, 255, 0, 0); //set all neopixels to red
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
    if (lowflow==false){ //Check if the bootup sound has played and execute following code if it hasn't
      CircuitPlayground.playTone(100, 200); //Play set up jingle
      CircuitPlayground.playTone(300, 200);
      CircuitPlayground.playTone(500, 500);
      lowflow = true; //change variable to let device know it has played the jingle 
    }
  }
  if (IR>969 && IR<971){ //Threshold of low flow - hold puck in the middle and adjust the value to whatever is shown on serial monitor
    CircuitPlayground.setPixelColor(0, 0, 255, 0);//Set all neopixels to green
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
    if (goodflow==false){//check if timer sound has played already 
      CircuitPlayground.playTone(300, 500);//play timer tones 
      delay(500);
      CircuitPlayground.playTone(300, 500);
      delay(500);
      CircuitPlayground.playTone(300, 500);
      delay(500);
      CircuitPlayground.playTone(300, 1000);
      goodflow = true;//update variable to let device know the timer has played 
    }       
  }
  if (IR<970){//Threshold of high flow - hold puck at the top and adjust the value to whatever is shown on serial monitor
    CircuitPlayground.setPixelColor(0, 255, 111, 234);//set all neopixels to pink 
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
    if (highflow == false){ //check if high flow alarm has played 
      CircuitPlayground.playTone(1000, 100);//play high flow alarm
      delay(100);
      CircuitPlayground.playTone(1000, 100);
      delay(100);
      CircuitPlayground.playTone(1000, 100);
      delay(100);
      CircuitPlayground.playTone(1000, 100);
      highflow = true;//let device know high flow alarm has played
    }
  } 
}
