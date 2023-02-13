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
  P.begin(2);
  P.setZone(0, 0, 3);
  P.setZone(1, 4, 7);
  
  
      
}

void loop(void)
{
  P.setFont(1, BigFontLower);
  P.setFont(0, BigFontUpper);
  P.displayZoneText(0, "612", PA_CENTER, 30, 30000, PA_PRINT, PA_PRINT);
  P.displayZoneText(1, "612", PA_CENTER, 30, 30000, PA_PRINT, PA_PRINT);
  P.displayAnimate();
    }
