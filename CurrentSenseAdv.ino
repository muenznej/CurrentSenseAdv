#define BRZO
#define BRZO_I2C_DISABLE_INTERRUPTS 0

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

#include <Encoder.h>
#define CH_A D6
#define CH_B D5
Encoder myEnc(CH_A, CH_B);
long oldPosition  = -999;
long newPosition = -999;

#include <Button.h>
Button ScaleButton = Button(D3, BUTTON_PULLUP_INTERNAL, true, 50); 
Button OverlayButton = Button(D4, BUTTON_PULLUP_INTERNAL, true, 50);  // also led built in

#define numScaleModes 3
uint8_t stateScale = 0;

#define numOverlayModes 3
uint8_t stateOverlay = 0;

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
#define MAX_VOLTAGE 5.00 // V
unsigned long t1;
unsigned long t2;

#define READ_LIMIT 128
float cur_buf[128];
float bus_buf[128];

byte bf_cnt = 0;
float scl_y_current = 64 / MAX_CURRENT;
float scl_y_bus = 64 / MAX_VOLTAGE;
float scl_x_time = 0;
uint16_t tx = 0;
float scl_x = 1;

typedef struct {
  float val = 0.0;
  uint32_t factor = 1;
  String unit = "";
} scl;


scl GetScale( float val) {
  scl Scaling;

  Scaling.factor = 1;
  Scaling.unit = "";
  Scaling.val = val;

  if ( val * 10 >= 1) {
    Scaling.unit = "";
    Scaling.factor = 1;
  }
  else if ( val * 10000 >= 1) {
    Scaling.unit = "m";
    Scaling.factor = 1000;
  }
  else if ( val * 10000000 >= 1) {
    Scaling.unit = "µ";
    Scaling.factor = 1000000;
  }
  Scaling.val *= Scaling.factor;

  return Scaling;
}

void ScalerOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  if (stateScale == 1) {
    display->drawFastImage(64, 32, arrow_lr_width, arrow_lr_height, arrow_lr);
  }
  else if (stateScale == 2) {
    display->drawFastImage(64, 32, arrow_ud_width, arrow_ud_height, arrow_ud);
  }
}
void StatusOverlay(OLEDDisplay * display, OLEDDisplayUiState * state) {
  scl cur_scale  =  GetScale( 1. / scl_y_current * 8);
  scl bus_scale  =  GetScale( 1. / scl_y_bus * 8);
  scl time_scale =  GetScale( scl_x_time * 8);

  float mean_cur = 0;
  float mean_bus = 0;
  for ( int ii = 0; ii <= 127; ii++)  {
    mean_cur += cur_buf[ ii ];
    mean_bus += bus_buf[ ii ];
  }
  mean_cur /= 64;
  mean_bus /= 64;

  scl mean_cur_scale =  GetScale( mean_cur);
  scl mean_bus_scale =  GetScale( mean_bus);

  if (stateOverlay >= 1) {
    display->setFont(ArialMT_Plain_10);
    display->setTextAlignment(TEXT_ALIGN_RIGHT);
    display->drawString(126, 0,  String(cur_scale.val) + " " + cur_scale.unit  + "A/div");
    display->drawString(126, 12, String(bus_scale.val) + " " + bus_scale.unit  + "V/div");
    display->drawString(126, 53, String(time_scale.val) + " " + time_scale.unit + "s/div");
  }
  if (stateOverlay >= 2) {
    display->setTextAlignment(TEXT_ALIGN_LEFT);
    display->drawString(2, 0, String(mean_cur_scale.val) + " " + mean_cur_scale.unit  + "A");
    display->drawString(2, 12, String(mean_bus_scale.val) + " " + mean_bus_scale.unit  + "V");
  }

  //GRID and FRAME
  for (uint8_t xx = 8; xx <= 127; xx += 8) {
    for (uint8_t yy = 8; yy <= 63; yy += 8) {
      display->setPixel(xx, yy);
    }
  }
  display->drawRect(0, 0, 128, 64);
}

void drawFrameMy(OLEDDisplay * display, OLEDDisplayUiState * state, int16_t x, int16_t y) {
  long yOffset = newPosition;

  for ( int ii = 0; ii <= 127; ii++) {
    if (!(ii % 2)) {
      int8_t cur_y_pos = yOffset + 63 - (byte)(cur_buf[ ii ] * scl_y_current);
      display->setPixel(ii, cur_y_pos);
    } else {
      display->setPixel(ii, 63 - (byte)(bus_buf[ ii ]*scl_y_bus));
    }

  }
}
FrameCallback frames[] = { drawFrameMy};
int frameCount = 1;

OverlayCallback overlays[] = { StatusOverlay, ScalerOverlay };
int overlaysCount = 2;

void setup() {
//  pinMode(LED_BUILTIN, INPUT_PULLUP);
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
  ui.disableAllIndicators();
  ui.init();
  display.clear();

  display.flipScreenVertically();
}

void loop() {
  // Manuell Controll
  //void nextFrame();
  //void previousFrame();
  int8_t dt = ui.update();
  if (dt > 0) {
    if (OverlayButton.uniquePress()) {
      stateOverlay += 1;
      stateOverlay %= numOverlayModes;
      Serial.println("Overlay Pressed");
      Serial.println(stateOverlay);
      digitalWrite(LED_BUILTIN,LOW);
    }

    if (ScaleButton.uniquePress()) {
      stateScale += 1;
      stateScale %= numScaleModes;
      Serial.println("Scale Pressed");
      Serial.println(stateScale);
    }

    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;
      // Serial.println(newPosition);
    }
    if (bf_cnt == 0) {
      t1 = micros();
    }
    if (!(bf_cnt % 2)) {
      cur_buf[ bf_cnt ] = ina.readShuntCurrent();
    } else {
      bus_buf[ bf_cnt ] = ina.readBusVoltage();
    }

    if (bf_cnt == 127) {
      bf_cnt = 0;
      t2 = micros();
      scl_x_time = (float)(t2 - t1) / 128 / 1000000.0;
    }
    else {
      bf_cnt++;
    }
  }
}
