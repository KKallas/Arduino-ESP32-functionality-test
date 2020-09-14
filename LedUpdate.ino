#include <FastLED.h>

#define NUM_LEDS 10

CRGB leds[NUM_LEDS];

void setupLedUpdate() {
  
}

void LedUpdateTaskCode( void * pvParameters ){
  // Setup of the task, run once before main loop
  int color = 0;
  //even the error of bitbanging is there: https://github.com/FastLED/FastLED/issues/923
  FastLED.addLeds<APA102, 2, 14, BGR>(leds, NUM_LEDS);
  // main loop for the task
  for( ;;) {
    for(int i=0;i<NUM_LEDS/2;i++) {
      leds[i*2] = CRGB(color,0,0);
      leds[i*2+1] = CRGB(color,color,color);
    }
    FastLED.show();
    delay(20);
    if(color == 255) color = 0;
    else color++;

  }
}
