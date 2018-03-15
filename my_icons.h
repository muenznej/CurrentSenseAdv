const char activeSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00011000,
    B00100100,
    B01000010,
    B01000010,
    B00100100,
    B00011000
};

const char inactiveSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000
};

#define arrow_ud_width 5
#define arrow_ud_height 11
static char arrow_ud[]  = {
  0x04, 0x01, 0x06, 0x03, 0xFF, 0x07, 0x06, 0x03, 0x04, 0x01, };

#define arrow_lr_width 11
#define arrow_lr_height 5
static char arrow_lr[]   = {
  0x04, 0x0E, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1F, 0x0E, 0x04, };

