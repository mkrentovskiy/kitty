
#include <Adafruit_GFX.h>
#include <SharpMemoryLcd.h>

#include "catBmps.h"

SHARPMEMORYLCD lcd;

#define SPEED 8
#define DELAY 150

void setup() {                
  Serial.begin(9600);
  lcd.LcdInitialize();
  lcd.LcdAllClearMode();
  lcd.LcdStartEXTC();
}

void frame(int x, int y, const uint8_t* bm, int d) {
   lcd.LcdClearBuffer();
   lcd.drawBitmap(x, y, bm, 32, 32, 0);
   lcd.LcdPrintBuffer();
   delay(d); 
}

void loop() {
    unsigned char bmp = 0;
    int i,x,y; 
        
    for(x=64;x>=0;x-=SPEED) frame(x,  0, (bmp++ & 1) ? left1 : left2, DELAY);
    for(y=0;y<=64;y+=SPEED) frame(0,  y, (bmp++ & 1) ? down1 : down2, DELAY);
    for(x=0;x<=64;x+=SPEED) frame(x, 64, (bmp++ & 1) ? right1 : right2, DELAY);
    for(x=64, y=64; x>=32; x=-SPEED, y-=SPEED) frame(x, y, (bmp++ & 1) ? upLeft1 : upLeft2, DELAY);
   
    frame(32, 32, yawn2, 10 * DELAY);
    frame(32, 32, yawn3, 10 * DELAY);
    frame(32, 32, yawn2, 10 * DELAY);

    for(i=0;i<=6;i++) frame(32,  32, (bmp++ & 1) ? sleep1 : sleep2, 10 * DELAY);
    frame(32, 32, awake, 10 * DELAY);
    for(x=32,y=32;x<=64;x+=SPEED,y-=SPEED) frame(x, y, (bmp++ & 1) ? upRight1 : upRight2, DELAY);
}

