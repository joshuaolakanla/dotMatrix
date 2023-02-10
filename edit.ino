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
#define MAX_DEVICES 16
#define CLK_PIN   4
#define DATA_PIN  12
#define CS_PIN    16
String a,b,c,d,e,f;
String aD,bD,cD,dD,eD,fD;
char aOut[6];
char bOut[6];
char cOut[6];
char dOut[6];
char eOut[6];
char fOut[6];

const char WiFiPassword[] = "";
const char AP_NameChar[] = "Hymn" ;
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
WiFiServer server(80);
String request = "";
String proRequest;
int length1;
char *strings[39];
char str[100];
int pro;
void setup(void)
{
  Serial.begin(115200);
  EEPROM.begin(512);
  
  P.begin(4);
  P.setZone(0, 0, 3);
  P.setZone(1, 4, 7);
  P.setZone(2, 8, 11);
  P.setZone(3, 12, 15);
  
  WiFi.disconnect();
  boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
  server.begin();

  aD = aR(0);
  bD = bR(10);
  cD = cR(20);
  dD = dR(30);
  eD = eR(40);
  fD = fR(50);


  aD.toCharArray(aOut, 6);
  bD.toCharArray(bOut, 6);
  cD.toCharArray(cOut, 6);
  dD.toCharArray(dOut, 6);
  eD.toCharArray(eOut, 6);
  fD.toCharArray(fOut, 6);

      
}

void loop(void)
{
  P.setFont(0, BigFontUpper);
  P.setFont(1, BigFontLower);
  P.setFont(2, BigFontUpper);
  P.setFont(3, BigFontLower);
  P.displayZoneText(0, aOut, PA_CENTER, 30, 30000, PA_PRINT, PA_PRINT);
  P.displayZoneText(1, aOut, PA_CENTER, 30, 30000, PA_PRINT, PA_PRINT);
  P.displayZoneText(2, "301", PA_CENTER, 30, 30000, PA_PRINT, PA_PRINT);
  P.displayZoneText(3, "301", PA_CENTER, 30, 30000, PA_PRINT, PA_PRINT);
  P.displayAnimate();


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
  
  aW(0, a);
  bW(10, b);
  cW(20, c);
  dW(30, d);
  eW(40, e);
  fW(50, f);

  aD = aR(0);
  bD = bR(10);
  cD = cR(20);
  dD = dR(30);
  eD = eR(40);
  fD = fR(50);


  aD.toCharArray(aOut, 6);
  bD.toCharArray(bOut, 6);
  cD.toCharArray(cOut, 6);
  dD.toCharArray(dOut, 6);
  eD.toCharArray(eOut, 6);
  fD.toCharArray(fOut, 6);


  
  

  Serial.print("the final data is ");
  Serial.println(aD + " " + bD + " "+ cD + " "+ dD + " " + eD + " "+ fD); 



      }



void aW(int add1, const String &aS){
  Serial.println(aS);
  byte aLen = aS.length();
  EEPROM.put(add1, aLen);
  for (int i=0; i<aLen; i++){
    EEPROM.put(add1 + 1 + i, aS[i]);
  }
  
}


void bW(int add2, const String &bS){
  byte bLen = bS.length();
  EEPROM.put(add2, bLen);
  for (int i=0; i<bLen; i++){
    EEPROM.put(add2+1+i, bS[i]);
  }
  
}


void cW(int add3, const String &cS){
  byte cLen = cS.length();
  EEPROM.put(add3, cLen);
  for (int i=0; i<cLen; i++){
    EEPROM.put(add3+1+i, cS[i]);
  }
  
}


void dW(int add4, const String &dS){
  byte dLen = dS.length();
  EEPROM.put(add4, dLen);
  for (int i=0; i<dLen; i++){
    EEPROM.put(add4+1+i, dS[i]);
  }
  
}


void eW(int add5, const String &eS){
  byte eLen = eS.length();
  EEPROM.put(add5, eLen);
  for (int i=0; i<eLen; i++){
    EEPROM.put(add5+1+i, eS[i]);
  }
  
}


void fW(int add6, const String &fS){
  byte fLen = fS.length();
  EEPROM.put(add6, fLen);
  for (int i=0; i<fLen; i++){
    EEPROM.put(add6+1+i, fS[i]);
  }
  
}









String aR(int add1){
  int aLen = EEPROM.read(add1);
  Serial.println(aLen);
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


