//Code by Joshua Olakanla Ayoola (jossytech)
//192.168.4.1/ nodemcu address
//http://192.168.4.1/421,428,89,120,987,977,301
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include "Font_Data.h"
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 24
#define CLK_PIN   4 //D2
#define DATA_PIN  12 //D6
#define CS_PIN    16 //D0

#define CLK_PIN2   5 //D1
#define DATA_PIN2  0 //D3
#define CS_PIN2    14 //D5

#define CLK_PIN3   2 //D4
#define DATA_PIN3  13 //D7
#define CS_PIN3    15 //D8


String a,b,c,d,e,f,g;
String aD,bD,cD,dD,eD,fD,gD;
char aOut[6];
char bOut[6];
char cOut[6];
char dOut[6];
char eOut[6];
char fOut[6];
char gOut[30];

const char WiFiPassword[] = "";
const char AP_NameChar[] = "Hymn" ;
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
MD_Parola P1 = MD_Parola(HARDWARE_TYPE, DATA_PIN2, CLK_PIN2, CS_PIN2, 8);
MD_Parola P2 = MD_Parola(HARDWARE_TYPE, DATA_PIN3, CLK_PIN3, CS_PIN3, MAX_DEVICES);
WiFiServer server(80);
String request = "";
String proRequest;
int length1;
char *strings[39];
char str[100];
int pro;


String aR(int add1){
  int aLen = EEPROM.read(add1);
  char aData[aLen + 1];
  for (int i=0; i<aLen; i++){
    aData[i]=EEPROM.read(add1 + 1 +i);
  }
  aData[aLen] = '\0';
  return String(aData);
}



String bR(int add2){
  int bLen = EEPROM.read(add2);
  Serial.println(bLen);

  char bData[bLen + 1];
  for (int j=0; j<bLen; j++){
    bData[j]=EEPROM.read(add2 + 1 +j);
  }
  bData[bLen] = '\0';
  return String(bData);
  
}

String cR(int add3){
  int cLen = EEPROM.read(add3);
  char cData[cLen + 1];
  for (int j=0; j<cLen; j++){
    cData[j]=EEPROM.read(add3 + 1 +j);
  }
  cData[cLen] = '\0';
  return String(cData);

}

String dR(int add4){
  int dLen = EEPROM.read(add4);
  char dData[dLen + 1];
  for (int j=0; j<dLen; j++){
    dData[j]=EEPROM.read(add4 + 1 +j);
  }
  dData[dLen] = '\0';
  return String(dData);

}


String eR(int add5){
  int eLen = EEPROM.read(add5);
  char eData[eLen + 1];
  for (int j=0; j<eLen; j++){
    eData[j]=EEPROM.read(add5 + 1 +j);
  }
  eData[eLen] = '\0';
  return String(eData);
  
}


String fR(int add6){
  int fLen = EEPROM.read(add6);
  char fData[fLen + 1];
  for (int j=0; j<fLen; j++){
    fData[j]=EEPROM.read(add6 + 1 +j);
  }
  fData[fLen] = '\0';
  return String(fData);
  
}

String gR(int add7){
  int gLen = EEPROM.read(add7);
  char gData[gLen + 1];
  for (int j=0; j<gLen; j++){
    gData[j]=EEPROM.read(add7 + 1 +j);
  }
  gData[gLen] = '\0';
  return String(gData);
  
}

void setup(void)
{
  Serial.begin(115200);
  EEPROM.begin(512);
  
  P.begin(12);
  P1.begin(2);
  P2.begin(12);
  
  P.setZone(0, 0, 3);
  P.setZone(1, 4, 7);
  P.setZone(2, 8, 11);
  P.setZone(3, 12, 15);
  P.setZone(4, 16, 19);
  P.setZone(5, 20, 23);
  //P.setZone(6, 24, 27);
  //P.setZone(7, 28, 31);
  //P.setZone(8, 32, 35);
  //P.setZone(9, 36, 39);
  //P.setZone(10, 40, 43);
  //P.setZone(11, 44, 47);
  
  P1.setZone(0, 0, 3);
  P1.setZone(1, 4, 7);

  P2.setZone(0, 0, 3);
  P2.setZone(1, 4, 7);
  P2.setZone(2, 8, 11);
  P2.setZone(3, 12, 15);
  P2.setZone(4, 16, 19);
  P2.setZone(5, 20, 23);


  P.setIntensity(8);
  P1.setIntensity(8);
  P2.setIntensity(8);
  
  P.setFont(0, BigFontUpper);
  P.setFont(1, BigFontLower);
  P.setFont(2, BigFontUpper);
  P.setFont(3, BigFontLower);
  P.setFont(4, BigFontUpper);
  P.setFont(5, BigFontLower);
  /*P.setFont(6, BigFontUpper);
  P.setFont(7, BigFontLower);
  P.setFont(8, BigFontUpper);
  P.setFont(9, BigFontLower);
  P.setFont(10, BigFontUpper);
  P.setFont(11, BigFontLower); */

  P1.setFont(0, BigFontUpper);
  P1.setFont(1, BigFontLower);

  P2.setFont(0, BigFontUpper);
  P2.setFont(1, BigFontLower);
  P2.setFont(2, BigFontUpper);
  P2.setFont(3, BigFontLower);
  P2.setFont(4, BigFontUpper);
  P2.setFont(5, BigFontLower);


  WiFi.disconnect();
  boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
  server.begin();

  aD = aR(0);
  bD = bR(10);
  cD = cR(20);
  dD = dR(30);
  eD = eR(40);
  fD = fR(50);
  gD = gR(60);


  aD.toCharArray(aOut, 6);
  bD.toCharArray(bOut, 6);
  cD.toCharArray(cOut, 6);
  dD.toCharArray(dOut, 6);
  eD.toCharArray(eOut, 6);
  fD.toCharArray(fOut, 6);
  gD.toCharArray(gOut, 30);

  Serial.print("generated data...");
  Serial.println(gOut);


  P1.displayZoneText(0, gOut, PA_CENTER, 60, 20, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  P1.displayZoneText(1, gOut, PA_CENTER, 60, 20, PA_SCROLL_LEFT, PA_SCROLL_LEFT); 

      
}



void display(){
  aD = aR(0);
  bD = bR(10);
  cD = cR(20);
  dD = dR(30);
  eD = eR(40);
  fD = fR(50);
  gD = gR(60);


  aD.toCharArray(aOut, 6);
  bD.toCharArray(bOut, 6);
  cD.toCharArray(cOut, 6);
  dD.toCharArray(dOut, 6);
  eD.toCharArray(eOut, 6);
  fD.toCharArray(fOut, 6);
  gD.toCharArray(gOut, 30);

  P.displayZoneText(0, aOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(1, aOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(2, bOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(3, bOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(4, cOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(5, cOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  /*P.displayZoneText(6, dOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(7, dOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(8, eOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(9, eOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P.displayZoneText(10, fOut, PA_CENTER, 30,300, PA_PRINT, PA_PRINT);
  P.displayZoneText(11, fOut, PA_CENTER, 30,300, PA_PRINT, PA_PRINT); */
  P2.displayZoneText(0, dOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P2.displayZoneText(1, dOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P2.displayZoneText(2, eOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P2.displayZoneText(3, eOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P2.displayZoneText(4, fOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);
  P2.displayZoneText(5, fOut, PA_CENTER, 30, 300, PA_PRINT, PA_PRINT);

  


}


void loop(void)
{
  aD = aR(0);
  bD = bR(10);
  cD = cR(20);
  dD = dR(30);
  eD = eR(40);
  fD = fR(50);
  gD = gR(60);


  aD.toCharArray(aOut, 6);
  bD.toCharArray(bOut, 6);
  cD.toCharArray(cOut, 6);
  dD.toCharArray(dOut, 6);
  eD.toCharArray(eOut, 6);
  fD.toCharArray(fOut, 6);
  gD.toCharArray(gOut, 30);

  display();
  P.displayAnimate();
  P1.displayAnimate();
  P2.displayAnimate();

  if (P1.getZoneStatus(0) && P1.getZoneStatus(1)){
    P1.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    P1.setTextEffect(1, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    P1.displayReset(0);
    P1.displayReset(1);
  }


  WiFiClient client = server.available();
  if (!client)  {
    return;
  }
  request = client.readStringUntil('\r');
  length1 = request.length();
  proRequest = request.substring(5,length1-9);
  proRequest.toCharArray(str,100);
  char *token = strtok(str, ",");
  int index = 0;
  while (token != nullptr) {
    strings[index] = token;
    index++;
    token = strtok(nullptr, ",");
  }
  for (int i=0; i<index; i++){
    Serial.print("the value is: ");
    Serial.println(strings[i]);

  }
  
  a = strings[0];
  b = strings[1];
  c = strings[2];
  d = strings[3];
  e = strings[4];
  f = strings[5];
  g = strings[6];
  
  aW(0, a);
  bW(10, b);
  cW(20, c);
  dW(30, d);
  eW(40, e);
  fW(50, f);
  gW(60, g);


  aD = aR(0);
  bD = bR(10);
  cD = cR(20);
  dD = dR(30);
  eD = eR(40);
  fD = fR(50);
  gD = gR(60);


  aD.toCharArray(aOut, 6);
  bD.toCharArray(bOut, 6);
  cD.toCharArray(cOut, 6);
  dD.toCharArray(dOut, 6);
  eD.toCharArray(eOut, 6);
  fD.toCharArray(fOut, 6);
  gD.toCharArray(gOut, 30);


  
  

  Serial.print("the final data is ");
  Serial.println(aD + " " + bD + " "+ cD + " "+ dD + " " + eD + " "+ fD); 



      }



void aW(int add1, const String &aS){
  byte aLen = aS.length();
  EEPROM.put(add1, aLen);
  for (int i=0; i<aLen; i++){
    EEPROM.put(add1 + 1 + i, aS[i]);
    EEPROM.commit();
  }
  
}


void bW(int add2, const String &bS){
  byte bLen = bS.length();
  EEPROM.put(add2, bLen);
  for (int i=0; i<bLen; i++){
    EEPROM.put(add2+1+i, bS[i]);
    EEPROM.commit();
  }
  
}


void cW(int add3, const String &cS){
  byte cLen = cS.length();
  EEPROM.put(add3, cLen);
  for (int i=0; i<cLen; i++){
    EEPROM.put(add3+1+i, cS[i]);
    EEPROM.commit();
  }
  
}


void dW(int add4, const String &dS){
  byte dLen = dS.length();
  EEPROM.put(add4, dLen);
  for (int i=0; i<dLen; i++){
    EEPROM.put(add4+1+i, dS[i]);
    EEPROM.commit();
  }
  
}


void eW(int add5, const String &eS){
  byte eLen = eS.length();
  EEPROM.put(add5, eLen);
  for (int i=0; i<eLen; i++){
    EEPROM.put(add5+1+i, eS[i]);
    EEPROM.commit();
  }
  
}


void fW(int add6, const String &fS){
  byte fLen = fS.length();
  EEPROM.put(add6, fLen);
  for (int i=0; i<fLen; i++){
    EEPROM.put(add6+1+i, fS[i]);
    EEPROM.commit();
  }
  
}

void gW(int add7, const String &gS){
  byte gLen = gS.length();
  EEPROM.put(add7, gLen);
  for (int i=0; i<gLen; i++){
    EEPROM.put(add7+1+i, gS[i]);
    EEPROM.commit();
  }
  
}
