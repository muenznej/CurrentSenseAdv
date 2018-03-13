#define BRZO

#ifdef BRZO
#include <brzo_i2c.h>
#else
#include <Wire.h>
#endif

#define INA_SCL D2
#define INA_SDA D1

#ifdef BRZO
#if F_CPU == 160000000L
#define CLK_SPEED 1000
#else
#define CLK_SPEED 800
#endif
#include <INA219_brzo.h>
INA219_brzo ina(INA_SCL, INA_SDA); //INA219_brzo ina(D2,D1)
#else
#define CLK_SPEED 700
#include <INA219.h>
INA219 ina(INA_SCL, INA_SDA); //INA219 ina(D2,D1)
#endif

//#define OLED_SCL D4
//#define OLED_SDA D3

#define OLED_SCL D2
#define OLED_SDA D1
#ifdef BRZO
#include "SSD1306Brzo.h"
SSD1306Brzo display(0x3c, OLED_SDA, OLED_SCL );
#else
#include "SSD1306.h"
SSD1306 display(0x3c, OLED_SDA, OLED_SCL);
#endif

#include "OLEDDisplayUi.h"
OLEDDisplayUi ui     ( &display );
#include "my_icons.h"

#define MAX_CURRENT 0.01 // A
float ina_current = 0.;
float ina_bus = 0.;
unsigned short cnt = 0;
unsigned long t1;
unsigned long t2;

#define READ_LIMIT 1000
#define wpx 128
#define hpx 64
#define pad_px 8
float val_buf[wpx];

byte scl_exp[3] = {0,-3,-6}; // A, mA, µA
byte scl_div[3] = {1,10,100};
byte bf_cnt=0;
float scl_y = 64/(MAX_CURRENT);
uint16_t tx = 0;
float scl_x = 1;

void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  byte val = 0;
  float str_scl = 1/scl_y*8;
  String str_leg = "";
  uint32_t i_fact = 1;
  if( str_scl * 1 > 1){
    str_leg = " A";
    i_fact = 1;
  }
  else if ( str_scl * 1000 > 1) {
    str_leg = " mA";
    i_fact = 1000;
  }
  else if ( str_scl * 1000000 > 1){
    str_leg = " µA";
    i_fact = 1000000;
  }

    float mean_val = 0;
  for ( int ii = 0; ii <= 127; ii++) {
    mean_val += val_buf[ ii ];
  }
  mean_val /= 128;
  
  
  display->setFont(ArialMT_Plain_10);
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->drawString(128, 0, String(1/scl_y*8*i_fact)+str_leg+"/div");
  display->drawString(128, 12, String(tx*8)+"µs/div");
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(0, 0, String(mean_val*i_fact)+str_leg);

  
  
  for (byte xx = 0; xx<(128-8); xx+=8){
    for (byte yy = 7; yy<64; yy+=8){
      display->setPixel(xx,yy);
//      if((xx-8)%16==0 && (yy-8)%16==0){
//      display->setPixel(xx-1,yy);
//      display->setPixel(xx+1,yy);
//      display->setPixel(xx,yy+1);
//      display->setPixel(xx,yy-1);
//      }
    }
}

}

void drawFrameMy(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  for ( int ii = 0; ii < wpx; ii++) {
    display->setPixel(ii, 63-(byte)(val_buf[ ii ]*scl_y));
  }
}
FrameCallback frames[] = { drawFrameMy};
int frameCount = 1;

OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;

void setup() {
  unsigned long BAUDRATE = 500000;
  Serial.begin(BAUDRATE);
  Serial.println("Initialize INA219");
  Serial.println("-----------------------------------------------");
  ina.begin(0x40, CLK_SPEED);
  ina.configure(INA219_RANGE_16V, INA219_GAIN_40MV, INA219_BUS_RES_9BIT, INA219_SHUNT_RES_9BIT_1S, INA219_MODE_SHUNT_BUS_CONT);
  ina.calibrate(0.1, MAX_CURRENT); // 0.1ohm, 500mA
  ina.checkConfig();

  ui.setTargetFPS(10); // target frames per second
  //ui.setActiveSymbol(activeSymbol); // pic for active Sym
  //ui.setInactiveSymbol(inactiveSymbol);  // pic for inactive Sym
  ui.setIndicatorPosition(RIGHT); // location
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setTimePerFrame(0); // whatever unit this is
  ui.setTimePerTransition(0); // weuti

  // Add frames
  ui.setFrames(frames, frameCount);
  ui.setOverlays(overlays, overlaysCount);
  
  ui.disableAutoTransition();
  ui.init();
  display.clear();

  display.flipScreenVertically();

}

void loop() {
  cnt++;
  if (cnt == 1) {
    t1 = micros();
  }

  if (bf_cnt == 128) {
    bf_cnt = 0;
  }
  ina_current = ina.readShuntCurrent();
  bf_cnt++;
  val_buf[ bf_cnt ] = ina_current;
  ui.update();

  
  if (cnt == READ_LIMIT) {
    t2 = micros();
    tx +=(float)(t2 - t1) / READ_LIMIT;
    tx /=2;
//    Serial.print((float)(t2 - t1) / READ_LIMIT, 1);
//    Serial.print(" µs/READ; ");
//    Serial.print(ina_current, 1);
//    Serial.print(" mA;");
//    Serial.println("");
//    Serial.println("");
    cnt = 0;
  }
}

