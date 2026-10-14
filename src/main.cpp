#include <Arduino.h>
#include <FastLED.h>
#include <WS35_index.h>
#include <WS35_index.cpp>
#include <cmath>

CRGB LEDsLeftBack[WholePanelLEDCount];
CRGB LEDsRightBack[WholePanelLEDCount]; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  InitLEDsAndCRGBIndex(LEDsLeftBack, LEDsRightBack);  
}

void loop() {
  // put your main code here, to run repeatedly:

  /* TESTING
  Address1 = FindAddress(Coord1);

  printf("Coordinate{%i, %i}\n", Coord1.x, Coord1.y);
  printf("Address:{%p, %i}\n\n", (void *)Address1.LEDstring, Address1.index );
  printf("ref:\n back left: %p\n front left: %p\n front right: %p\n back right: %p\n\n", (void *)getCRGBForPin(WS35LeftBackPin), (void *)getCRGBForPin(WS35LeftFrontPin), (void *)getCRGBForPin(WS35RightFrontPin), (void *)getCRGBForPin(WS35RightBackPin));

  delay(2000);
  */
  

    LEDCoordinate coord1 = {0 , 0};
    LEDAddress Address1 = {nullptr, OUTBOUND_LED};


    for(int i = 7; i < 20;i++){
      for(int j = 5; j < 11; j++){

        coord1 = {i, j};
        Address1 = FindAddress(coord1);
        Address1.LEDstring[Address1.index].setHSV(0, 255, 64);
        
      }
    }

     FastLED.show();





  /*
  for(int i = 0; i < Num_LED; i++ ){

    for(int j = 0; j < Num_LED; j++ ){
      leds[j].setHSV(j,255,64);
    }

    leds[i].setHSV(i,0,64);
    FastLED.show();
    delay(100);
  }
    */
  
  
  
}



