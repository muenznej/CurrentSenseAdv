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

const char arrow_up[] PROGMEM = {
    B00100,
    B00110,
    B11111,
    B00110,
    B00100
};
// will be rotated 90° CCW !!
const char arrow_right[] PROGMEM = {
    B00100,
    B00100,
    B11111,
    B01110,
    B00100
};

// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const char Lato_Light_10[] PROGMEM = {
  0x0A, // Width: 10
  0x0D, // Height: 13
  0x20, // First Char: 32
  0xE0, // Numbers of Chars: 224

  // Jump Table:
  0xFF, 0xFF, 0x00, 0x03,  // 32:65535
  0x00, 0x00, 0x04, 0x03,  // 33:0
  0x00, 0x04, 0x05, 0x03,  // 34:4
  0x00, 0x09, 0x09, 0x06,  // 35:9
  0x00, 0x12, 0x0A, 0x06,  // 36:18
  0x00, 0x1C, 0x0E, 0x08,  // 37:28
  0x00, 0x2A, 0x0E, 0x07,  // 38:42
  0x00, 0x38, 0x01, 0x02,  // 39:56
  0x00, 0x39, 0x04, 0x03,  // 40:57
  0x00, 0x3D, 0x04, 0x03,  // 41:61
  0x00, 0x41, 0x07, 0x04,  // 42:65
  0x00, 0x48, 0x09, 0x06,  // 43:72
  0x00, 0x51, 0x04, 0x02,  // 44:81
  0x00, 0x55, 0x05, 0x04,  // 45:85
  0x00, 0x5A, 0x04, 0x02,  // 46:90
  0x00, 0x5E, 0x07, 0x04,  // 47:94
  0x00, 0x65, 0x0A, 0x06,  // 48:101
  0x00, 0x6F, 0x0A, 0x06,  // 49:111
  0x00, 0x79, 0x0A, 0x06,  // 50:121
  0x00, 0x83, 0x0A, 0x06,  // 51:131
  0x00, 0x8D, 0x09, 0x06,  // 52:141
  0x00, 0x96, 0x0A, 0x06,  // 53:150
  0x00, 0xA0, 0x0A, 0x06,  // 54:160
  0x00, 0xAA, 0x09, 0x06,  // 55:170
  0x00, 0xB3, 0x0A, 0x06,  // 56:179
  0x00, 0xBD, 0x09, 0x06,  // 57:189
  0x00, 0xC6, 0x04, 0x02,  // 58:198
  0x00, 0xCA, 0x04, 0x03,  // 59:202
  0x00, 0xCE, 0x0A, 0x06,  // 60:206
  0x00, 0xD8, 0x09, 0x06,  // 61:216
  0x00, 0xE1, 0x09, 0x06,  // 62:225
  0x00, 0xEA, 0x07, 0x04,  // 63:234
  0x00, 0xF1, 0x10, 0x08,  // 64:241
  0x01, 0x01, 0x0C, 0x07,  // 65:257
  0x01, 0x0D, 0x0C, 0x06,  // 66:269
  0x01, 0x19, 0x0C, 0x07,  // 67:281
  0x01, 0x25, 0x0E, 0x08,  // 68:293
  0x01, 0x33, 0x0A, 0x06,  // 69:307
  0x01, 0x3D, 0x09, 0x06,  // 70:317
  0x01, 0x46, 0x0E, 0x07,  // 71:326
  0x01, 0x54, 0x0E, 0x08,  // 72:340
  0x01, 0x62, 0x04, 0x03,  // 73:354
  0x01, 0x66, 0x06, 0x04,  // 74:358
  0x01, 0x6C, 0x0C, 0x06,  // 75:364
  0x01, 0x78, 0x0A, 0x05,  // 76:376
  0x01, 0x82, 0x10, 0x09,  // 77:386
  0x01, 0x92, 0x0E, 0x08,  // 78:402
  0x01, 0xA0, 0x0E, 0x08,  // 79:416
  0x01, 0xAE, 0x09, 0x06,  // 80:430
  0x01, 0xB7, 0x10, 0x08,  // 81:439
  0x01, 0xC7, 0x0C, 0x06,  // 82:455
  0x01, 0xD3, 0x0A, 0x05,  // 83:467
  0x01, 0xDD, 0x0B, 0x06,  // 84:477
  0x01, 0xE8, 0x0C, 0x07,  // 85:488
  0x01, 0xF4, 0x0B, 0x07,  // 86:500
  0x01, 0xFF, 0x13, 0x0A,  // 87:511
  0x02, 0x12, 0x0C, 0x06,  // 88:530
  0x02, 0x1E, 0x0B, 0x06,  // 89:542
  0x02, 0x29, 0x0C, 0x06,  // 90:553
  0x02, 0x35, 0x06, 0x03,  // 91:565
  0x02, 0x3B, 0x08, 0x04,  // 92:571
  0x02, 0x43, 0x04, 0x03,  // 93:579
  0x02, 0x47, 0x09, 0x06,  // 94:583
  0x02, 0x50, 0x08, 0x05,  // 95:592
  0x02, 0x58, 0x05, 0x04,  // 96:600
  0x02, 0x5D, 0x08, 0x05,  // 97:605
  0x02, 0x65, 0x0A, 0x06,  // 98:613
  0x02, 0x6F, 0x08, 0x05,  // 99:623
  0x02, 0x77, 0x0A, 0x06,  // 100:631
  0x02, 0x81, 0x0A, 0x05,  // 101:641
  0x02, 0x8B, 0x05, 0x03,  // 102:651
  0x02, 0x90, 0x0A, 0x05,  // 103:656
  0x02, 0x9A, 0x0A, 0x06,  // 104:666
  0x02, 0xA4, 0x04, 0x02,  // 105:676
  0x02, 0xA8, 0x04, 0x02,  // 106:680
  0x02, 0xAC, 0x0A, 0x05,  // 107:684
  0x02, 0xB6, 0x04, 0x02,  // 108:694
  0x02, 0xBA, 0x0E, 0x08,  // 109:698
  0x02, 0xC8, 0x0A, 0x06,  // 110:712
  0x02, 0xD2, 0x0A, 0x06,  // 111:722
  0x02, 0xDC, 0x0A, 0x06,  // 112:732
  0x02, 0xE6, 0x0A, 0x06,  // 113:742
  0x02, 0xF0, 0x05, 0x04,  // 114:752
  0x02, 0xF5, 0x08, 0x04,  // 115:757
  0x02, 0xFD, 0x06, 0x03,  // 116:765
  0x03, 0x03, 0x0A, 0x06,  // 117:771
  0x03, 0x0D, 0x09, 0x05,  // 118:781
  0x03, 0x16, 0x0D, 0x08,  // 119:790
  0x03, 0x23, 0x08, 0x05,  // 120:803
  0x03, 0x2B, 0x09, 0x05,  // 121:811
  0x03, 0x34, 0x08, 0x04,  // 122:820
  0x03, 0x3C, 0x06, 0x03,  // 123:828
  0x03, 0x42, 0x04, 0x02,  // 124:834
  0x03, 0x46, 0x05, 0x03,  // 125:838
  0x03, 0x4B, 0x09, 0x06,  // 126:843
  0x03, 0x54, 0x0A, 0x05,  // 127:852
  0x03, 0x5E, 0x0A, 0x05,  // 128:862
  0x03, 0x68, 0x0A, 0x05,  // 129:872
  0x03, 0x72, 0x0A, 0x05,  // 130:882
  0x03, 0x7C, 0x0A, 0x05,  // 131:892
  0x03, 0x86, 0x0A, 0x05,  // 132:902
  0x03, 0x90, 0x0A, 0x05,  // 133:912
  0x03, 0x9A, 0x0A, 0x05,  // 134:922
  0x03, 0xA4, 0x0A, 0x05,  // 135:932
  0x03, 0xAE, 0x0A, 0x05,  // 136:942
  0x03, 0xB8, 0x0A, 0x05,  // 137:952
  0x03, 0xC2, 0x0A, 0x05,  // 138:962
  0x03, 0xCC, 0x0A, 0x05,  // 139:972
  0x03, 0xD6, 0x0A, 0x05,  // 140:982
  0x03, 0xE0, 0x0A, 0x05,  // 141:992
  0x03, 0xEA, 0x0A, 0x05,  // 142:1002
  0x03, 0xF4, 0x0A, 0x05,  // 143:1012
  0x03, 0xFE, 0x0A, 0x05,  // 144:1022
  0x04, 0x08, 0x0A, 0x05,  // 145:1032
  0x04, 0x12, 0x0A, 0x05,  // 146:1042
  0x04, 0x1C, 0x0A, 0x05,  // 147:1052
  0x04, 0x26, 0x0A, 0x05,  // 148:1062
  0x04, 0x30, 0x0A, 0x05,  // 149:1072
  0x04, 0x3A, 0x0A, 0x05,  // 150:1082
  0x04, 0x44, 0x0A, 0x05,  // 151:1092
  0x04, 0x4E, 0x0A, 0x05,  // 152:1102
  0x04, 0x58, 0x0A, 0x05,  // 153:1112
  0x04, 0x62, 0x0A, 0x05,  // 154:1122
  0x04, 0x6C, 0x0A, 0x05,  // 155:1132
  0x04, 0x76, 0x0A, 0x05,  // 156:1142
  0x04, 0x80, 0x0A, 0x05,  // 157:1152
  0x04, 0x8A, 0x0A, 0x05,  // 158:1162
  0x04, 0x94, 0x0A, 0x05,  // 159:1172
  0xFF, 0xFF, 0x00, 0x03,  // 160:65535
  0x04, 0x9E, 0x04, 0x02,  // 161:1182
  0x04, 0xA2, 0x0A, 0x06,  // 162:1186
  0x04, 0xAC, 0x0C, 0x06,  // 163:1196
  0x04, 0xB8, 0x0A, 0x06,  // 164:1208
  0x04, 0xC2, 0x09, 0x06,  // 165:1218
  0x04, 0xCB, 0x04, 0x02,  // 166:1227
  0x04, 0xCF, 0x08, 0x05,  // 167:1231
  0x04, 0xD7, 0x05, 0x04,  // 168:1239
  0x04, 0xDC, 0x0F, 0x08,  // 169:1244
  0x04, 0xEB, 0x05, 0x04,  // 170:1259
  0x04, 0xF0, 0x06, 0x04,  // 171:1264
  0x04, 0xF6, 0x09, 0x06,  // 172:1270
  0x04, 0xFF, 0x05, 0x04,  // 173:1279
  0x05, 0x04, 0x0F, 0x08,  // 174:1284
  0x05, 0x13, 0x05, 0x04,  // 175:1299
  0x05, 0x18, 0x07, 0x04,  // 176:1304
  0x05, 0x1F, 0x0A, 0x06,  // 177:1311
  0x05, 0x29, 0x05, 0x03,  // 178:1321
  0x05, 0x2E, 0x05, 0x03,  // 179:1326
  0x05, 0x33, 0x05, 0x04,  // 180:1331
  0x05, 0x38, 0x0C, 0x06,  // 181:1336
  0x05, 0x44, 0x0B, 0x07,  // 182:1348
  0x05, 0x4F, 0x03, 0x02,  // 183:1359
  0x05, 0x52, 0x06, 0x04,  // 184:1362
  0x05, 0x58, 0x05, 0x03,  // 185:1368
  0x05, 0x5D, 0x05, 0x04,  // 186:1373
  0x05, 0x62, 0x06, 0x04,  // 187:1378
  0x05, 0x68, 0x0E, 0x07,  // 188:1384
  0x05, 0x76, 0x0E, 0x07,  // 189:1398
  0x05, 0x84, 0x0E, 0x07,  // 190:1412
  0x05, 0x92, 0x08, 0x04,  // 191:1426
  0x05, 0x9A, 0x0C, 0x07,  // 192:1434
  0x05, 0xA6, 0x0C, 0x07,  // 193:1446
  0x05, 0xB2, 0x0C, 0x07,  // 194:1458
  0x05, 0xBE, 0x0C, 0x07,  // 195:1470
  0x05, 0xCA, 0x0C, 0x07,  // 196:1482
  0x05, 0xD6, 0x0C, 0x07,  // 197:1494
  0x05, 0xE2, 0x12, 0x09,  // 198:1506
  0x05, 0xF4, 0x0C, 0x07,  // 199:1524
  0x06, 0x00, 0x0A, 0x06,  // 200:1536
  0x06, 0x0A, 0x0A, 0x06,  // 201:1546
  0x06, 0x14, 0x0A, 0x06,  // 202:1556
  0x06, 0x1E, 0x0A, 0x06,  // 203:1566
  0x06, 0x28, 0x04, 0x03,  // 204:1576
  0x06, 0x2C, 0x05, 0x03,  // 205:1580
  0x06, 0x31, 0x05, 0x03,  // 206:1585
  0x06, 0x36, 0x05, 0x03,  // 207:1590
  0x06, 0x3B, 0x0E, 0x08,  // 208:1595
  0x06, 0x49, 0x0E, 0x08,  // 209:1609
  0x06, 0x57, 0x0E, 0x08,  // 210:1623
  0x06, 0x65, 0x0E, 0x08,  // 211:1637
  0x06, 0x73, 0x0E, 0x08,  // 212:1651
  0x06, 0x81, 0x0E, 0x08,  // 213:1665
  0x06, 0x8F, 0x0E, 0x08,  // 214:1679
  0x06, 0x9D, 0x0A, 0x06,  // 215:1693
  0x06, 0xA7, 0x0E, 0x08,  // 216:1703
  0x06, 0xB5, 0x0C, 0x07,  // 217:1717
  0x06, 0xC1, 0x0C, 0x07,  // 218:1729
  0x06, 0xCD, 0x0C, 0x07,  // 219:1741
  0x06, 0xD9, 0x0C, 0x07,  // 220:1753
  0x06, 0xE5, 0x0B, 0x06,  // 221:1765
  0x06, 0xF0, 0x09, 0x06,  // 222:1776
  0x06, 0xF9, 0x0A, 0x06,  // 223:1785
  0x07, 0x03, 0x08, 0x05,  // 224:1795
  0x07, 0x0B, 0x08, 0x05,  // 225:1803
  0x07, 0x13, 0x08, 0x05,  // 226:1811
  0x07, 0x1B, 0x08, 0x05,  // 227:1819
  0x07, 0x23, 0x08, 0x05,  // 228:1827
  0x07, 0x2B, 0x08, 0x05,  // 229:1835
  0x07, 0x33, 0x0F, 0x08,  // 230:1843
  0x07, 0x42, 0x08, 0x05,  // 231:1858
  0x07, 0x4A, 0x0A, 0x05,  // 232:1866
  0x07, 0x54, 0x0A, 0x05,  // 233:1876
  0x07, 0x5E, 0x0A, 0x05,  // 234:1886
  0x07, 0x68, 0x0A, 0x05,  // 235:1896
  0x07, 0x72, 0x04, 0x02,  // 236:1906
  0x07, 0x76, 0x04, 0x02,  // 237:1910
  0x07, 0x7A, 0x04, 0x02,  // 238:1914
  0x07, 0x7E, 0x04, 0x02,  // 239:1918
  0x07, 0x82, 0x0A, 0x06,  // 240:1922
  0x07, 0x8C, 0x0A, 0x06,  // 241:1932
  0x07, 0x96, 0x0A, 0x06,  // 242:1942
  0x07, 0xA0, 0x0A, 0x06,  // 243:1952
  0x07, 0xAA, 0x0A, 0x06,  // 244:1962
  0x07, 0xB4, 0x0A, 0x06,  // 245:1972
  0x07, 0xBE, 0x0A, 0x06,  // 246:1982
  0x07, 0xC8, 0x09, 0x06,  // 247:1992
  0x07, 0xD1, 0x0A, 0x06,  // 248:2001
  0x07, 0xDB, 0x0A, 0x06,  // 249:2011
  0x07, 0xE5, 0x0A, 0x06,  // 250:2021
  0x07, 0xEF, 0x0A, 0x06,  // 251:2031
  0x07, 0xF9, 0x0A, 0x06,  // 252:2041
  0x08, 0x03, 0x09, 0x05,  // 253:2051
  0x08, 0x0C, 0x0A, 0x06,  // 254:2060
  0x08, 0x16, 0x09, 0x05,  // 255:2070

  // Font Data:
  0x00,0x00,0xF8,0x02,  // 33
  0x00,0x00,0x18,0x00,0x18, // 34
  0x80,0x00,0xE0,0x03,0xB8,0x00,0xE0,0x03,0x98, // 35
  0x00,0x00,0x38,0x02,0xC8,0x07,0x7C,0x02,0x88,0x03,  // 36
  0x00,0x00,0x38,0x02,0x48,0x01,0xF0,0x00,0xA0,0x03,0x50,0x02,0x88,0x03,  // 37
  0x00,0x00,0xD0,0x03,0x68,0x02,0x88,0x02,0x08,0x03,0x80,0x01,0x00,0x02,  // 38
  0x18, // 39
  0x00,0x00,0xFC,0x07,  // 40
  0x04,0x04,0xF8,0x03,  // 41
  0x00,0x00,0x10,0x00,0x38,0x00,0x28, // 42
  0x00,0x00,0x40,0x00,0xF0,0x01,0x40,0x00,0x40, // 43
  0x00,0x00,0x00,0x06,  // 44
  0x00,0x00,0x80,0x00,0x80, // 45
  0x00,0x00,0x00,0x02,  // 46
  0x00,0x02,0x80,0x01,0x60,0x00,0x18, // 47
  0xF0,0x01,0x08,0x02,0x08,0x02,0x08,0x02,0xF0,0x01,  // 48
  0x00,0x00,0x10,0x02,0x08,0x02,0xF0,0x03,0x00,0x02,  // 49
  0x00,0x00,0x18,0x02,0x08,0x03,0x88,0x02,0x70,0x02,  // 50
  0x00,0x00,0x18,0x03,0x08,0x02,0x48,0x02,0xB0,0x01,  // 51
  0x80,0x00,0xE0,0x00,0x90,0x00,0xF8,0x03,0x80, // 52
  0x00,0x00,0x38,0x02,0x28,0x02,0x28,0x02,0xC8,0x01,  // 53
  0x00,0x00,0xC0,0x03,0x30,0x02,0x28,0x02,0xC0,0x03,  // 54
  0x00,0x00,0x08,0x02,0x88,0x01,0x68,0x00,0x18, // 55
  0x00,0x00,0xB8,0x03,0x48,0x02,0x48,0x02,0xB0,0x03,  // 56
  0x00,0x00,0x38,0x00,0x48,0x03,0xC8,0x00,0x70, // 57
  0x00,0x00,0x20,0x02,  // 58
  0x00,0x00,0x20,0x06,  // 59
  0x00,0x00,0x40,0x00,0xA0,0x00,0xA0,0x00,0x20,0x01,  // 60
  0x00,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0, // 61
  0x00,0x00,0x20,0x01,0xA0,0x00,0xC0,0x00,0x40, // 62
  0x08,0x00,0x88,0x02,0x48,0x00,0x38, // 63
  0x00,0x00,0xE0,0x07,0x10,0x09,0x90,0x0A,0x50,0x0A,0xD0,0x0B,0x20,0x0A,0xC0,0x01,  // 64
  0x00,0x03,0xC0,0x00,0xB0,0x00,0x98,0x00,0xE0,0x00,0x00,0x03,  // 65
  0x00,0x00,0xF8,0x03,0x48,0x02,0x48,0x02,0x48,0x02,0xB0,0x01,  // 66
  0x00,0x00,0xF0,0x01,0x08,0x02,0x08,0x02,0x08,0x02,0x08,0x02,  // 67
  0x00,0x00,0xF8,0x03,0x08,0x02,0x08,0x02,0x08,0x02,0x08,0x02,0xF0,0x01,  // 68
  0x00,0x00,0xF8,0x03,0x48,0x02,0x48,0x02,0x48,0x02,  // 69
  0x00,0x00,0xF8,0x03,0x48,0x00,0x48,0x00,0x48, // 70
  0x00,0x00,0xF0,0x01,0x08,0x02,0x08,0x02,0x08,0x02,0x48,0x02,0xC8,0x01,  // 71
  0x00,0x00,0xF8,0x03,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0xF8,0x03,  // 72
  0x00,0x00,0xF8,0x03,  // 73
  0x00,0x02,0x00,0x02,0xF8,0x03,  // 74
  0x00,0x00,0xF8,0x03,0x40,0x00,0xA0,0x00,0x10,0x01,0x08,0x02,  // 75
  0x00,0x00,0xF8,0x03,0x00,0x02,0x00,0x02,0x00,0x02,  // 76
  0x00,0x00,0xF8,0x03,0x20,0x00,0xC0,0x00,0x00,0x01,0xC0,0x00,0x30,0x00,0xF8,0x03,  // 77
  0x00,0x00,0xF8,0x03,0x10,0x00,0x60,0x00,0x80,0x00,0x00,0x01,0xF8,0x03,  // 78
  0x00,0x00,0xF0,0x01,0x08,0x02,0x08,0x02,0x08,0x02,0x08,0x02,0xF0,0x01,  // 79
  0x00,0x00,0xF8,0x03,0x48,0x00,0x48,0x00,0x38, // 80
  0x00,0x00,0xF0,0x01,0x08,0x02,0x08,0x02,0x08,0x02,0x08,0x02,0xB0,0x0D,0x40,0x08,  // 81
  0x00,0x00,0xF8,0x03,0x48,0x00,0xC8,0x00,0x28,0x01,0x10,0x02,  // 82
  0x00,0x02,0x38,0x02,0x48,0x02,0x48,0x02,0x88,0x01,  // 83
  0x08,0x00,0x08,0x00,0xF8,0x03,0x08,0x00,0x08,0x00,0x08, // 84
  0x00,0x00,0xF8,0x01,0x00,0x02,0x00,0x02,0x00,0x02,0xF8,0x01,  // 85
  0x08,0x00,0x70,0x00,0x80,0x01,0x00,0x03,0xC0,0x00,0x38, // 86
  0x18,0x00,0xE0,0x00,0x00,0x03,0xC0,0x00,0x30,0x00,0x38,0x00,0xC0,0x01,0x00,0x03,0xE0,0x00,0x18, // 87
  0x08,0x02,0x10,0x01,0xA0,0x00,0xE0,0x00,0x10,0x01,0x08,0x02,  // 88
  0x08,0x00,0x30,0x00,0xC0,0x03,0x60,0x00,0x10,0x00,0x08, // 89
  0x08,0x02,0x08,0x03,0xC8,0x02,0x28,0x02,0x18,0x02,0x08,0x02,  // 90
  0x00,0x00,0xF8,0x0F,0x08,0x08,  // 91
  0x08,0x00,0x30,0x00,0xC0,0x01,0x00,0x02,  // 92
  0x08,0x08,0xF8,0x0F,  // 93
  0x00,0x00,0x20,0x00,0x18,0x00,0x10,0x00,0x20, // 94
  0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,  // 95
  0x00,0x00,0x08,0x00,0x08, // 96
  0x00,0x03,0xA0,0x02,0xA0,0x02,0xE0,0x03,  // 97
  0x00,0x00,0xF8,0x03,0x20,0x02,0x20,0x02,0xC0,0x01,  // 98
  0x00,0x00,0xE0,0x03,0x20,0x02,0x20,0x02,  // 99
  0x00,0x00,0xE0,0x03,0x20,0x02,0x20,0x02,0xF8,0x03,  // 100
  0x00,0x00,0xE0,0x03,0xA0,0x02,0xA0,0x02,0xC0,0x02,  // 101
  0x20,0x00,0xF8,0x03,0x28, // 102
  0xC0,0x04,0x20,0x0B,0x20,0x0B,0xE0,0x0A,0x20,0x04,  // 103
  0x00,0x00,0xF8,0x03,0x20,0x00,0x20,0x00,0xC0,0x03,  // 104
  0x00,0x00,0xE8,0x03,  // 105
  0x00,0x08,0xE8,0x07,  // 106
  0x00,0x00,0xF8,0x03,0x40,0x01,0x20,0x02,0x00,0x02,  // 107
  0x00,0x00,0xF8,0x03,  // 108
  0x00,0x00,0xE0,0x03,0x20,0x00,0x20,0x00,0xE0,0x03,0x20,0x00,0xE0,0x03,  // 109
  0x00,0x00,0xE0,0x03,0x20,0x00,0x20,0x00,0xC0,0x03,  // 110
  0x00,0x00,0xE0,0x03,0x20,0x02,0x20,0x02,0xC0,0x01,  // 111
  0x00,0x00,0xE0,0x0F,0x20,0x02,0x20,0x02,0xC0,0x01,  // 112
  0x00,0x00,0xE0,0x03,0x20,0x02,0x20,0x02,0xE0,0x0F,  // 113
  0x00,0x00,0xE0,0x03,0x20, // 114
  0x40,0x02,0xA0,0x02,0xA0,0x02,0x20,0x03,  // 115
  0x20,0x00,0xF8,0x03,0x20,0x02,  // 116
  0x00,0x00,0xE0,0x03,0x00,0x02,0x00,0x02,0xE0,0x03,  // 117
  0x20,0x00,0xC0,0x01,0x00,0x02,0xC0,0x01,0x20, // 118
  0x60,0x00,0x80,0x01,0x80,0x03,0x60,0x00,0xC0,0x00,0x00,0x03,0xE0, // 119
  0x20,0x02,0x40,0x01,0x80,0x00,0x60,0x03,  // 120
  0x20,0x00,0xC0,0x09,0x00,0x06,0xC0,0x01,0x20, // 121
  0x20,0x02,0x20,0x03,0xE0,0x02,0x20,0x02,  // 122
  0x80,0x00,0x70,0x07,0x08,0x08,  // 123
  0x00,0x00,0xF8,0x0F,  // 124
  0x08,0x08,0x70,0x07,0x80, // 125
  0x00,0x00,0xC0,0x00,0x40,0x00,0x80,0x00,0xC0, // 126
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 127
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 128
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 129
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 130
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 131
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 132
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 133
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 134
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 135
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 136
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 137
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 138
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 139
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 140
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 141
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 142
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 143
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 144
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 145
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 146
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 147
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 148
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 149
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 150
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 151
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 152
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 153
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 154
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 155
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 156
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 157
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 158
  0xF8,0x03,0x18,0x02,0x58,0x03,0x38,0x02,0xF8,0x03,  // 159
  0x00,0x00,0x20,0x0F,  // 161
  0x00,0x00,0xC0,0x03,0x20,0x02,0xF0,0x07,0x20,0x02,  // 162
  0x40,0x02,0xF0,0x03,0x48,0x02,0x48,0x02,0x08,0x02,0x00,0x02,  // 163
  0x00,0x00,0xE0,0x01,0x20,0x01,0x20,0x01,0xE0,0x01,  // 164
  0x08,0x00,0xB0,0x00,0xC0,0x03,0xE0,0x00,0x98, // 165
  0x00,0x00,0x78,0x0F,  // 166
  0x00,0x00,0xF8,0x04,0xA8,0x04,0xC8,0x03,  // 167
  0x00,0x00,0x08,0x00,0x08, // 168
  0x00,0x00,0xF0,0x01,0xE8,0x02,0x18,0x03,0x18,0x03,0x18,0x03,0x10,0x01,0xE0, // 169
  0x00,0x00,0x38,0x00,0x38, // 170
  0x00,0x00,0xC0,0x01,0x40,0x01,  // 171
  0x00,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0xC0, // 172
  0x00,0x00,0x80,0x00,0x80, // 173
  0x00,0x00,0xF0,0x01,0x08,0x02,0xF8,0x03,0xD8,0x02,0x28,0x03,0x10,0x01,0xE0, // 174
  0x00,0x00,0x08,0x00,0x08, // 175
  0x00,0x00,0x38,0x00,0x28,0x00,0x10, // 176
  0x00,0x00,0x40,0x02,0xE0,0x03,0x40,0x02,0x40,0x02,  // 177
  0x10,0x00,0x12,0x00,0x1C, // 178
  0x14,0x00,0x2A,0x00,0x14, // 179
  0x00,0x00,0x00,0x00,0x08, // 180
  0x00,0x00,0xE0,0x0F,0x00,0x02,0x00,0x02,0xE0,0x03,0x00,0x02,  // 181
  0x10,0x00,0x38,0x00,0xF8,0x07,0x08,0x00,0xF8,0x07,0x08, // 182
  0x00,0x00,0x80, // 183
  0x00,0x00,0x00,0x0C,0x00,0x08,  // 184
  0x00,0x00,0x1C,0x00,0x10, // 185
  0x00,0x00,0x38,0x00,0x38, // 186
  0x00,0x00,0xC0,0x01,0xC0,0x01,  // 187
  0x00,0x00,0x78,0x02,0x40,0x01,0xC0,0x00,0x30,0x01,0xC8,0x01,0x00,0x03,  // 188
  0x00,0x00,0x78,0x02,0xC0,0x01,0x40,0x00,0xB0,0x02,0x48,0x03,0x80,0x02,  // 189
  0x00,0x00,0x58,0x00,0x28,0x03,0xC0,0x00,0x30,0x01,0x88,0x01,0x40,0x03,  // 190
  0x00,0x04,0x00,0x0A,0xA0,0x09,0x00,0x08,  // 191
  0x00,0x03,0xC0,0x00,0xB2,0x00,0x9C,0x00,0xE0,0x00,0x00,0x03,  // 192
  0x00,0x03,0xC0,0x00,0xB4,0x00,0x9A,0x00,0xE2,0x00,0x00,0x03,  // 193
  0x00,0x03,0xC0,0x00,0xB4,0x00,0x9A,0x00,0xE4,0x00,0x00,0x03,  // 194
  0x00,0x03,0xC0,0x00,0xB6,0x00,0x9C,0x00,0xE2,0x00,0x00,0x03,  // 195
  0x00,0x03,0xC0,0x00,0xB2,0x00,0x98,0x00,0xE2,0x00,0x00,0x03,  // 196
  0x00,0x03,0xC0,0x00,0xB2,0x00,0x9F,0x00,0xE0,0x00,0x00,0x03,  // 197
  0x00,0x02,0x80,0x01,0xE0,0x00,0x90,0x00,0xB8,0x00,0x48,0x03,0x48,0x02,0x48,0x02,0x08,0x02,  // 198
  0x00,0x00,0xF0,0x01,0x08,0x02,0x08,0x0C,0x08,0x0A,0x08,0x02,  // 199
  0x00,0x00,0xF8,0x03,0x4A,0x02,0x44,0x02,0x48,0x02,  // 200
  0x00,0x00,0xF8,0x03,0x44,0x02,0x4A,0x02,0x4A,0x02,  // 201
  0x00,0x00,0xF8,0x03,0x44,0x02,0x4A,0x02,0x44,0x02,  // 202
  0x00,0x00,0xF8,0x03,0x4A,0x02,0x48,0x02,0x4A,0x02,  // 203
  0x02,0x00,0xFC,0x03,  // 204
  0x00,0x00,0xFC,0x03,0x02, // 205
  0x04,0x00,0xFA,0x03,0x04, // 206
  0x02,0x00,0xF8,0x03,0x02, // 207
  0x40,0x00,0xF8,0x03,0x48,0x02,0x08,0x02,0x08,0x02,0x08,0x02,0xF0,0x01,  // 208
  0x00,0x00,0xF8,0x03,0x14,0x00,0x62,0x00,0x84,0x00,0x02,0x01,0xF8,0x03,  // 209
  0x00,0x00,0xF0,0x01,0x0A,0x02,0x0A,0x02,0x04,0x02,0x08,0x02,0xF0,0x01,  // 210
  0x00,0x00,0xF0,0x01,0x08,0x02,0x04,0x02,0x0A,0x02,0x0A,0x02,0xF0,0x01,  // 211
  0x00,0x00,0xF0,0x01,0x0C,0x02,0x0A,0x02,0x0A,0x02,0x0C,0x02,0xF0,0x01,  // 212
  0x00,0x00,0xF0,0x01,0x0C,0x02,0x0A,0x02,0x04,0x02,0x0A,0x02,0xF0,0x01,  // 213
  0x00,0x00,0xF0,0x01,0x0A,0x02,0x08,0x02,0x0A,0x02,0x08,0x02,0xF0,0x01,  // 214
  0x00,0x00,0x20,0x01,0xC0,0x00,0xC0,0x00,0x20,0x01,  // 215
  0x00,0x00,0xF0,0x03,0x08,0x03,0x88,0x02,0x68,0x02,0x18,0x02,0xF8,0x01,  // 216
  0x00,0x00,0xF8,0x01,0x02,0x02,0x04,0x02,0x04,0x02,0xF8,0x01,  // 217
  0x00,0x00,0xF8,0x01,0x00,0x02,0x04,0x02,0x02,0x02,0xF8,0x01,  // 218
  0x00,0x00,0xF8,0x01,0x04,0x02,0x02,0x02,0x04,0x02,0xF8,0x01,  // 219
  0x00,0x00,0xF8,0x01,0x02,0x02,0x00,0x02,0x02,0x02,0xF8,0x01,  // 220
  0x08,0x00,0x30,0x00,0xC4,0x03,0x62,0x00,0x12,0x00,0x08, // 221
  0x00,0x00,0xF8,0x03,0x10,0x01,0x10,0x01,0xE0, // 222
  0x00,0x00,0xF8,0x03,0x48,0x02,0xA8,0x02,0x98,0x03,  // 223
  0x00,0x03,0xA8,0x02,0xA8,0x02,0xE0,0x03,  // 224
  0x00,0x03,0xA0,0x02,0xA8,0x02,0xE8,0x03,  // 225
  0x00,0x03,0xA8,0x02,0xA8,0x02,0xF0,0x03,  // 226
  0x00,0x03,0xA8,0x02,0xA8,0x02,0xE8,0x03,  // 227
  0x00,0x03,0xA8,0x02,0xA0,0x02,0xE8,0x03,  // 228
  0x00,0x03,0xA8,0x02,0x98,0x02,0xE8,0x03,  // 229
  0x00,0x01,0xA0,0x02,0xA0,0x02,0xE0,0x03,0xA0,0x02,0xA0,0x02,0xA0,0x02,0x40, // 230
  0x00,0x00,0xE0,0x03,0x20,0x0C,0x20,0x0A,  // 231
  0x00,0x00,0xE0,0x03,0xA8,0x02,0xA0,0x02,0xC0,0x02,  // 232
  0x00,0x00,0xE0,0x03,0xB0,0x02,0xA8,0x02,0xC0,0x02,  // 233
  0x00,0x00,0xF0,0x03,0xA8,0x02,0xA8,0x02,0xC0,0x02,  // 234
  0x00,0x00,0xE8,0x03,0xA0,0x02,0xA8,0x02,0xC0,0x02,  // 235
  0x08,0x00,0xF0,0x03,  // 236
  0x00,0x00,0xE8,0x03,  // 237
  0x08,0x00,0xE8,0x03,  // 238
  0x08,0x00,0xE8,0x03,  // 239
  0x00,0x00,0xC0,0x03,0x38,0x02,0x28,0x02,0xF0,0x01,  // 240
  0x00,0x00,0xE8,0x03,0x28,0x00,0x28,0x00,0xC0,0x03,  // 241
  0x00,0x00,0xE0,0x03,0x28,0x02,0x20,0x02,0xC0,0x01,  // 242
  0x00,0x00,0xE0,0x03,0x30,0x02,0x28,0x02,0xC0,0x01,  // 243
  0x00,0x00,0xF0,0x03,0x28,0x02,0x28,0x02,0xC0,0x01,  // 244
  0x00,0x00,0xE8,0x03,0x28,0x02,0x28,0x02,0xC0,0x01,  // 245
  0x00,0x00,0xE8,0x03,0x20,0x02,0x28,0x02,0xC0,0x01,  // 246
  0x00,0x00,0x40,0x00,0x50,0x01,0x40,0x00,0x40, // 247
  0x00,0x00,0xE0,0x03,0xA0,0x02,0x60,0x02,0xF0,0x01,  // 248
  0x00,0x00,0xE0,0x03,0x08,0x02,0x00,0x02,0xE0,0x03,  // 249
  0x00,0x00,0xE0,0x03,0x10,0x02,0x08,0x02,0xE0,0x03,  // 250
  0x00,0x00,0xF0,0x03,0x08,0x02,0x08,0x02,0xE0,0x03,  // 251
  0x00,0x00,0xE8,0x03,0x00,0x02,0x08,0x02,0xE0,0x03,  // 252
  0x20,0x00,0xC0,0x09,0x10,0x06,0xC8,0x01,0x20, // 253
  0x00,0x00,0xF8,0x0F,0x20,0x02,0x20,0x02,0xC0,0x01,  // 254
  0x20,0x00,0xC8,0x09,0x00,0x06,0xC8,0x01,0x20  // 255
};

