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
#define SNARE_THRESHOLD 255     //Adjustable between 0-1023 depending on how hard the drum is hit
#define TOM1_THRESHOLD  255
#define TOM2_THRESHOLD  255
#define TOM3_THRESHOLD  255
#define BASS_THRESHOLD  255

void checkAndLight(uint8_t inputPin, uint8_t outputPin, int threshold);
void showAnalogRGB( const CRGB& rgb);

void setup() {
  //PWM Pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(SNARE, OUTPUT);
  pinMode(TOM1, OUTPUT);
  pinMode(TOM2, OUTPUT);
  pinMode(TOM3, OUTPUT);
  pinMode(BASS, OUTPUT);

  //Analog Inputs
  pinMode(SNARE_IN, INPUT);
  pinMode(TOM1_IN, INPUT);
  pinMode(TOM2_IN, INPUT);
  pinMode(TOM3_IN, INPUT);
  pinMode(BASS_IN, INPUT);
}

void loop() {
  CRGB colour = CRGB::Red;   //Change as required, expansion to get this to work with a remote

  showAnalogRGB(colour);

  //Check each drum in turn
  checkAndLight(SNARE_IN, SNARE, SNARE_THRESHOLD);
  checkAndLight(TOM1_IN, TOM1, TOM1_THRESHOLD);
  checkAndLight(TOM2_IN, TOM2, TOM2_THRESHOLD);
  checkAndLight(TOM3_IN, TOM3, TOM3_THRESHOLD);
  checkAndLight(BASS_IN, BASS, BASS_THRESHOLD);
}

void checkAndLight(uint8_t inputPin, uint8_t outputPin, int threshold) {
  int inputValue = analogRead(inputPin);
  int outputValue;
  if (inputValue >= threshold)
  {
    //Maps input to brightness, with threshold being the minimum
    outputValue = map(inputValue, threshold, 1023, 0, 255);
  }
  else
  {
    //Too small a vibration to trigger
    outputValue = 0;
  }

  analogWrite(outputPin, outputValue);
}

//From FastLED analog example
void showAnalogRGB( const CRGB& rgb)
{
  analogWrite(RED_PIN,   rgb.r );
  analogWrite(GREEN_PIN, rgb.g );
  analogWrite(BLUE_PIN,  rgb.b );
}