#pragma once
#include <WS35_index.h>
#include <Arduino.h>
#include <cmath>

struct CRGBindexTEMPLATE CRGBindex = {nullptr, nullptr};

void InitLEDsAndCRGBIndex (CRGB* LEDsLeftback, CRGB* LEDsRightBack){

    FastLED.addLeds<WS2812,WS35LeftBackPin,GRB>(LEDsLeftback,WholePanelLEDCount);
    FastLED.addLeds<WS2812,WS35RightBackPin,GRB>(LEDsRightBack,WholePanelLEDCount);

    CRGBindex.LEDsLeftback = LEDsLeftback;
    CRGBindex.LEDsRightback = LEDsRightBack;
}


LEDAddress FindAddress (LEDCoordinate Coordinate){

    LEDAddress Address = { nullptr, OUTBOUND_LED};

    // If the coordinate is not in bounds, return an error.
    if(Coordinate.x == 0 || Coordinate.x <= -35 || Coordinate.x  >= 35 || Coordinate.y <= 0 || Coordinate.y >= 24){
        return Address; 
    }

    // picks the pin based on x position.
    if(Coordinate.x > 0){
        Address.LEDstring = CRGBindex.LEDsLeftback;
    } else {
        Address.LEDstring = CRGBindex.LEDsRightback;
        Coordinate.x *= -1;
    }

    // fixs coordinate to match array index, then returns the LEDs index number.
    Address.index = WS35Left_chain[Coordinate.x - 1][Coordinate.y - 1];
    return Address;
    
} 



