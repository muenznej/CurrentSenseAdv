//#define BRZO

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

#define OLED_SCL D4
#define OLED_SDA D3
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

float ina_current = 0.;
float ina_bus = 0.;
unsigned short cnt = 0;
unsigned long t1;
unsigned long t2;

void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, String(millis()));
}

void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Demonstrates the 3 included default sizes. The fonts come from SSD1306Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Arial 10");

  display->setFont(ArialMT_Plain_16);
  display->drawString(0 + x, 20 + y, "Arial 16");

  display->setFont(ArialMT_Plain_24);
  display->drawString(0 + x, 34 + y, "Arial 24");
}


// This array keeps function pointers to all frames
// frames are the single views that slide in
FrameCallback frames[] = {  drawFrame2 };

// how many frames are there?
int frameCount = 1;

// Overlays are statically drawn on top of a frame eg. a clock
OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;

void setup() {
  delay(2000);
  unsigned long BAUDRATE = 500000;
  Serial.begin(BAUDRATE);
  Serial.println("Initialize INA219");
  Serial.println("-----------------------------------------------");
  ina.begin(0x40, CLK_SPEED);
  ina.configure(INA219_RANGE_16V, INA219_GAIN_40MV, INA219_BUS_RES_9BIT, INA219_SHUNT_RES_9BIT_1S, INA219_MODE_SHUNT_BUS_CONT);
  ina.calibrate(0.1, 0.5); // 0.1ohm, 500mA
  ina.checkConfig();
  delay(2000);

  ui.setTargetFPS(30); // target frames per second
  ui.setActiveSymbol(activeSymbol); // pic for active Sym
  ui.setInactiveSymbol(inactiveSymbol);  // pic for inactive Sym
  ui.setIndicatorPosition(BOTTOM); // location
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);

  // Add frames
  ui.setFrames(frames, frameCount);
  ui.setOverlays(overlays, overlaysCount);

 // ui.init();

  display.flipScreenVertically();

}
#define READ_LIMIT 1000
void loop() {
  //int remainingTimeBudget = ui.update();

  cnt++;
  if (cnt == 1) {
    t1 = micros();
  }
  ina_current = ina.readShuntCurrent();

  if (cnt == READ_LIMIT) {
    t2 = micros();
    Serial.print((float)(t2 - t1) / READ_LIMIT, 1);
    Serial.print(" µs/READ; ");
    Serial.print(ina_current * 1000.0, 2);
    Serial.print(" mA;");
    Serial.println("");
    Serial.println("");
    cnt = 0;
  }

}

