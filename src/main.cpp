#include <Arduino.h>
#include <FastLED.h>

/*****************
 *    OUTPUTS    *
 *****************/
//RGB Pins
#define RED_PIN   2
#define GREEN_PIN 3
#define BLUE_PIN  4

//Drums
#define SNARE     5
#define TOM1      6
#define TOM2      7
#define TOM3      8
#define BASS      9

/*****************
 *     INPUTS    *
 *****************/
#define SNARE_IN  A0
#define TOM1_IN   A1
#define TOM2_IN   A2
#define TOM3_IN   A3
#define BASS_IN   A4

/*****************
 *   PARAMETERS  *
 *****************/
#define SNARE_THRESHOLD 255     //Adjustable between 0-1023 depending on how hard hit
#define TOM1_THRESHOLD  255
#define TOM2_THRESHOLD  255
#define TOM3_THRESHOLD  255
#define BASS_THRESHOLD  255


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}