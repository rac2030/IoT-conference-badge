#include "qrcode.h"
#include "qrencode.h"

int offsetsX = 5;
int offsetsY = 5;
bool QRDEBUG = false;

QRcode::QRcode(GxEPD_Class *display){
	this->display = display;
}

void QRcode::debug(){
	QRDEBUG = true;
}

void QRcode::render(int x, int y, int color){
  x=(x*2)+offsetsX;
  y=(y*2)+offsetsY;
  if(color==1) {
    display->drawPixel(x, y, GxEPD_BLACK);
    display->drawPixel(x+1, y, GxEPD_BLACK);
    display->drawPixel(x, y+1, GxEPD_BLACK);
    display->drawPixel(x+1, y+1, GxEPD_BLACK);
  } else {
    display->drawPixel(x, y, GxEPD_WHITE);
    display->drawPixel(x+1, y, GxEPD_WHITE);
    display->drawPixel(x, y+1, GxEPD_WHITE);
    display->drawPixel(x+1, y+1, GxEPD_WHITE);
  }
}

void QRcode::generate(String message) {
  if(QRDEBUG) {
    Serial.print("Generate QRcode for ");
    Serial.println(message);
  }
   // create QR code
  message.toCharArray((char *)strinbuf,260);
  qrencode();
}

void QRcode::writeToDisplayBuffer(int x, int y) {
  // Set offset as starting point
  offsetsX = x;
  offsetsY = y;

  if(QRDEBUG) Serial.println("QRcode render\n");
  // print QR Code
  for (byte x = 0; x < WD; x+=2) {
    for (byte y = 0; y < WD; y++) {
      if ( QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // black square on top of black square
        if(QRDEBUG) Serial.print("@");
        render(x, y, 1);
        render((x+1), y, 1);
      }
      if (!QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // white square on top of black square
        if(QRDEBUG) Serial.print(" ");
        render(x, y, 0);
        render((x+1), y, 1);
      }
      if ( QRBIT(x,y) && !QRBIT((x+1),y)) {
        // black square on top of white square
        if(QRDEBUG)	Serial.print("@");
        render(x, y, 1);
        render((x+1), y, 0);
      }
      if (!QRBIT(x,y) && !QRBIT((x+1),y)) {
        // white square on top of white square
        if(QRDEBUG)	Serial.print(" ");
        render(x, y, 0);
        render((x+1), y, 0);
      }
    }
    if(QRDEBUG)	Serial.println();
  }
  if(QRDEBUG)	Serial.println();

}

void QRcode::create(String message) {

  // create QR code
  message.toCharArray((char *)strinbuf,260);
  qrencode();

  if(QRDEBUG){
	Serial.println("QRcode render");
	Serial.println();
  }
  // print QR Code
  for (byte x = 0; x < WD; x+=2) {
    for (byte y = 0; y < WD; y++) {
      if ( QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // black square on top of black square
        if(QRDEBUG)
			Serial.print("@");
        render(x, y, 1);
        render((x+1), y, 1);
      }
      if (!QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // white square on top of black square
        if(QRDEBUG)
			Serial.print(" ");
        render(x, y, 0);
        render((x+1), y, 1);
      }
      if ( QRBIT(x,y) && !QRBIT((x+1),y)) {
        // black square on top of white square
        if(QRDEBUG)
			Serial.print("@");
        render(x, y, 1);
        render((x+1), y, 0);
      }
      if (!QRBIT(x,y) && !QRBIT((x+1),y)) {
        // white square on top of white square
        if(QRDEBUG)
			Serial.print(" ");
        render(x, y, 0);
        render((x+1), y, 0);
      }
    }
    Serial.println();
  }
  Serial.println();
  display->update();
  delay(5000);
}

