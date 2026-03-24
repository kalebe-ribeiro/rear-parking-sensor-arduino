#include <Arduino.h>

int pinBuzzer = 11;
int pinLedG = 10;
int pinLedY = 9;
int pinLedR = 8;
int pinSensorTrig = 7;
int pinSensorEcho = 6;

int LedG, LedY, LedR = 0;

// fórmula >>> d = (vt)/2
float d, v, t;

void setup(){
  	Serial.begin(9600);
  
	  pinMode(pinBuzzer, OUTPUT);
  	pinMode(pinLedG, OUTPUT);
  	pinMode(pinLedY, OUTPUT);
  	pinMode(pinLedR, OUTPUT);
  	pinMode(pinSensorTrig, OUTPUT);
  	pinMode(pinSensorEcho, INPUT);
  
}


void loop(){
  	digitalWrite(pinSensorTrig, LOW);
  	delayMicroseconds(2);
  	digitalWrite(pinSensorTrig, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(pinSensorTrig, LOW);
	
  	t = pulseIn(pinSensorEcho, HIGH) / 1e6;
  	// v = d/t, d = v.t
  	d = (340 * t) / 2;
  	Serial.println(d, 2);
  	
  	if (d >= 2){
      	noTone(pinBuzzer);
      
  		  digitalWrite(pinLedY, LOW);
  		  digitalWrite(pinLedR, LOW);
    	  digitalWrite(pinLedG, HIGH);
    } 
  	else if (2 > d && d >= 1){
      	tone(pinBuzzer, 1000, 100);
      	delay(500);
      	noTone(pinBuzzer);
      
    	  digitalWrite(pinLedG, LOW);
  		  digitalWrite(pinLedR, LOW);
      	digitalWrite(pinLedY, HIGH);
    }
  	else if (d < 1 && d > 0.5){
      	tone(pinBuzzer, 1000, 100);
      	delay(125);
      	noTone(pinBuzzer);
      
      	digitalWrite(pinLedG, LOW);
  		  digitalWrite(pinLedY, LOW);
  		  digitalWrite(pinLedR, HIGH);
    }
    else if (d <= 0.5){
      	tone(pinBuzzer, 1000);
      
      	digitalWrite(pinLedG, LOW);
  		  digitalWrite(pinLedY, LOW);
  	  	digitalWrite(pinLedR, HIGH);
    }
}