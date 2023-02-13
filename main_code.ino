//code by Joshua Olaknala jossytech
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "Font_Data.h"
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 8

#define CLK_PIN   5
#define DATA_PIN  0
#define CS_PIN    4

MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  Serial.begin(115200);
  P.begin(2);
  P.setZone(0, 0, 3);
  P.setZone(1, 4, 7);

  P.setFont(0, BigFontUpper);
  P.setFont(1, BigFontLower);

  P.displayZoneText(0, "Jossytech", PA_CENTER, 80, 10, PA_SCROLL_LEFT, PA_SCROLL_UP);
  P.displayZoneText(1, "Jossytech", PA_CENTER, 80, 10, PA_SCROLL_LEFT, PA_SCROLL_UP);
  

  
      
}

void loop(void)
{
  P.displayAnimate();
  if (P.getZoneStatus(0) && P.getZoneStatus(1)){
    P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_UP);
    P.setTextEffect(1, PA_SCROLL_LEFT, PA_SCROLL_UP);
    P.displayReset(0);
    P.displayReset(1);


  }
  
    }
