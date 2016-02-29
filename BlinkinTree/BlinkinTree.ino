/**********************************************************  
Code for blinkinlabs led dots for Christmas tree
December 2015
note: warm white = 110, 255, 10
**********************************************************/

#include <Adafruit_NeoPixel.h>
#define PIN 13

int numPix = 50;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPix, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  yellowFadeUpExpand(2);
  delay(10000);
  fullStringRev(255,255,255,10);
  treeFive(10);
  delay(10000);
  fullString(255, 50, 0, 10);
  fullString(0, 0, 255, 10);
  fullString(0, 255, 0, 10);
  fullString(65, 255, 0, 10);
  fullString(120, 220, 0, 10);     
  fullString(0, 0, 0, 10);
  delay(500);
  for (int i=0; i<256; i++){
    strip.setBrightness(i);
    fullFade(110, 255, 10);
    delay(30);
  }
  delay(10000);
  yellowFadeDownConverge(0);
  delay(500);
  for (int m = 0; m<6; m++) {
    dotChase(0, 255, 0, 3);
    dotChaseRev(255, 0, 0, 3);
  }
  fullString(20, 255, 70, 50);
  delay(10000);
  converge(0, 0, 255, 0, 0, 255, 100);
  delay(1000);
}

void fullString(int g, int r, int b, int del) {
  for (int p = 0; p < numPix; p++) {
    strip.setPixelColor(p, g, r, b);
    strip.show();
    delay(del);
  }
}

void fullStringRev(int g, int r, int b, int del) {
  for (int p = (numPix-1); p>=0; p--) {
    strip.setPixelColor(p, g, r, b);
    strip.show();
    delay(del);
  }
}

void fullFade(int g, int r, int b) {
  for (int p = 0; p < numPix; p++) {
    strip.setPixelColor(p, g, r, b);
  }
  strip.show();
}

void treeFive(int del) {
  for (int i = 0; i < numPix; i+=5) {
    strip.setPixelColor(i, 255, 50, 0);
    strip.show();
    delay(del);
    strip.setPixelColor(i+1, 0, 0, 255);
    strip.show();
    delay(del);
    strip.setPixelColor(i+2, 0, 255, 0);
    strip.show();
    delay(del);
    strip.setPixelColor(i+3, 65, 255, 0);
    strip.show();
    delay(del);
    strip.setPixelColor(i+4, 120, 220, 0);
    strip.show();
    delay(del);
  }
}

void dotChase (int g, int r, int b, int del) {
    strip.setPixelColor(0, g, r, b);
    strip.show();
    delay(del); 
  for (int p = 0; p < numPix; p++) {
    strip.setPixelColor(p, 0, 0, 0);
    strip.setPixelColor(p+1, g, r, b);
    strip.show();
    delay(del);  
  }
}

void dotChaseRev (int g, int r, int b, int del) {
    strip.setPixelColor((numPix-1), g, r, b);
    strip.show();
    delay(del); 
  for (int p = (numPix-1); p >= 0; p--) {
    strip.setPixelColor(p, 0, 0, 0);
    strip.setPixelColor(p-1, g, r, b);
    strip.show();
    delay(del);  
  }
}

void converge (int g1, int r1, int b1, int g2, int r2, int b2, int del) {
  for (int i=0; i<numPix; i++) {
    strip.setPixelColor(i, g1, r1, b1);
    strip.setPixelColor(((numPix-1)-i), g2, r2, b2);
    strip.show();
    delay(del);
    strip.setPixelColor(i, 0, 0, 0);
    strip.setPixelColor(((numPix-1)-i), 0, 0, 0);
  }
  strip.show();  
}

void yellowFadeUp(int del) {
  for (int p = 0; p < numPix; p++){
    for (int f = 0; f<256; f++){
      strip.setPixelColor(p, (f/2), f, 0);
      strip.show();
      delay(del);
    }
  }
}

void yellowFadeDown(int del) {
  for (int p = 0; p < numPix; p++){
    for (int f = 255; f>=0; f--){
      strip.setPixelColor(p, (f/2), f, 0);
      strip.show();
      delay(del);
    }
  }
}

void yellowFadeDownConverge(int del) {
  for (int p = 0; p <= (numPix/2); p++){
    for (int f = 255; f>=0; f--){
      strip.setPixelColor(p, (f/2), f, 0);
      strip.setPixelColor((numPix-p), (f/2), f, 0);
      strip.show();
      delay(del);
    }
  }
}

void yellowFadeUpExpand(int del) {
  for (int p = (numPix/2); p >=0; p--){
    for (int f=0; f<256; f++){
      strip.setPixelColor(p, (f/2), f, 0);
      strip.setPixelColor((numPix-p), (f/2), f, 0);
      strip.show();
      delay(del);
    }
  }
}
