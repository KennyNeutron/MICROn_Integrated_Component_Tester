
/*
    Electronic Component Tester on TFT Display
    Main Code
    Version 1.0.0

    by: MICROn Technology

    Environment: Arduino Mega 2560

    TFT DISPLAY: MAR4018
    SCREEN SIZE: 4.0"
    RESOLUTION: 800*480 Pixels
    DRIVER: MAR4018
    TOUCH IC: XPT2046

    Date Started: 10-17-2023
    Date Finished: N/A
*/
#include "Arduino.h"
#include <SPI.h>
#include <SD.h>           // SD Card Library
#include <LCDWIKI_GUI.h>  //Core graphics library
#include <LCDWIKI_KBV.h>  //Hardware-specific library
#include <XPT2046_Touchscreen.h>

#include "IntegratedCircuitPinout.h"

#define TCS_PIN 53

XPT2046_Touchscreen ts(TCS_PIN);
//#define TIRQ_PIN 44
//XPT2046_Touchscreen ts(CS_PIN);  // Param 2 - NULL - No interrupts
//XPT2046_Touchscreen ts(CS_PIN, 255);  // Param 2 - 255 - No interrupts
//XPT2046_Touchscreen ts(TCS_PIN, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling
//the definiens of 8bit mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_KBV tft(NT35510, 40, 38, 39, 43, 41);  //model,cs,cd,wr,rd,reset

/*  r     g    b */
#define BLACK 0x0000       /*   0,   0,   0 */
#define BLUE 0x001F        /*   0,   0, 255 */
#define RED 0xF800         /* 255,   0,   0 */
#define GREEN 0x07E0       /*   0, 255,   0 */
#define CYAN 0x07FF        /*   0, 255, 255 */
#define MAGENTA 0xF81F     /* 255,   0, 255 */
#define YELLOW 0xFFE0      /* 255, 255,   0 */
#define WHITE 0xFFFF       /* 255, 255, 255 */
#define NAVY 0x000F        /*   0,   0, 128 */
#define DARKGREEN 0x03E0   /*   0, 128,   0 */
#define DARKCYAN 0x03EF    /*   0, 128, 128 */
#define MAROON 0x7800      /* 128,   0,   0 */
#define PURPLE 0x780F      /* 128,   0, 128 */
#define OLIVE 0x7BE0       /* 128, 128,   0 */
#define LIGHTGREY 0xC618   /* 192, 192, 192 */
#define DARKGREY 0x7BEF    /* 128, 128, 128 */
#define ORANGE 0xFD20      /* 255, 165,   0 */
#define GREENYELLOW 0xAFE5 /* 173, 255,  47 */
#define PINK 0xF81F        /* 255,   0, 255 */


//ICs
#define IC_74LS08 0x01  //AND Gate
#define IC_74LS04 0x02  //NOT Gate
#define IC_74LS32 0x03  //OR Gate

#define IC_74LS00 0x04  //NAND Gate
#define IC_74LS02 0x05  //NOR Gate
#define IC_74LS86 0x06  //XOR Gate

#define IC_74LS83 0x07  //BINARY ADDER
#define IC_74LS47 0x08  //BCD
#define IC_74LS48 0x09  //BCD

#define IC_74LS147 0x0A  //Reverse BCD to 9L
#define IC_74LS42 0x0B   //BCD to 10L
#define IC_NE555 0x0C    //NE555 :D

//#define PIXEL_NUMBER  (tft.Get_Display_Width()/4)
#define FILE_NUMBER 17
#define FILE_NAME_SIZE_MAX 20

uint32_t bmp_offset = 0;
uint16_t s_width = tft.Get_Display_Width();
uint16_t s_heigh = tft.Get_Display_Height();
uint32_t BMP_WIDTH, BMP_HEIGHT;
int32_t PIXEL_NUMBER;

char file_name[FILE_NUMBER][FILE_NAME_SIZE_MAX];

bool touch_toggle = false;
uint32_t touch_last_millis = 0;
uint32_t blink_last_millis = 0;
bool blink = false;

uint16_t currentScreen = 0x0000;
uint8_t btn_pressed = 0;

bool btn_Home_pressed = false;
bool btn_Back_pressed = false;
bool btn_testIC_pressed = false;

bool btn_TruthTable_pressed = false;
bool btn_ICDetails_pressed = false;
bool btn_TestAnotherIC_pressed = false;
bool btn_TestReport_pressed = false;

bool bad_ic = false;
bool errorLG1 = false;
bool errorLG2 = false;
bool errorLG3 = false;
bool errorLG4 = false;

bool errorNG1 = false;
bool errorNG2 = false;
bool errorNG3 = false;
bool errorNG4 = false;
bool errorNG5 = false;
bool errorNG6 = false;

uint8_t IC_tested = 0x00;
uint32_t ICtest_last_millis = 0;

uint8_t Add_Sum[16];  //used for 74LS83 Sums

uint8_t BCD_7Segment_Out[10];

uint16_t previous_ScreenID = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("System Starting...\nMICROn Component Tester V1.0");

  tft.Init_LCD();
  tft.Set_Rotation(1);

  ts.begin();
  ts.setRotation(3);


  if (PIXEL_NUMBER == 60) {
    strcpy(file_name[0], "BHome.bmp");
    strcpy(file_name[1], "IconRes.bmp");
    strcpy(file_name[2], "BBack.bmp");
    strcpy(file_name[3], "gateAND.bmp");
    strcpy(file_name[4], "gateOR.bmp");
    strcpy(file_name[5], "gateNAND.bmp");
    strcpy(file_name[6], "gateNOR.bmp");
    strcpy(file_name[7], "gateXOR.bmp");
    strcpy(file_name[8], "gateNOT.bmp");
    strcpy(file_name[9], "npnCBE.bmp");
    strcpy(file_name[10], "npnEBC.bmp");
    strcpy(file_name[11], "pnpCBE.bmp");
    strcpy(file_name[12], "pnpEBC.bmp");
    strcpy(file_name[13], "BCDcc.bmp");
    strcpy(file_name[14], "BCDca.bmp");
    strcpy(file_name[15], "svnSeg.bmp");
    strcpy(file_name[16], "BinADD.bmp");
  } else {
    strcpy(file_name[0], "BHome.bmp");
    strcpy(file_name[1], "IconRes.bmp");
    strcpy(file_name[2], "BBack.bmp");
    strcpy(file_name[3], "gateAND.bmp");
    strcpy(file_name[4], "gateOR.bmp");
    strcpy(file_name[5], "gateNAND.bmp");
    strcpy(file_name[6], "gateNOR.bmp");
    strcpy(file_name[7], "gateXOR.bmp");
    strcpy(file_name[8], "gateNOT.bmp");
    strcpy(file_name[9], "npnCBE.bmp");
    strcpy(file_name[10], "npnEBC.bmp");
    strcpy(file_name[11], "pnpCBE.bmp");
    strcpy(file_name[12], "pnpEBC.bmp");
    strcpy(file_name[13], "BCDcc.bmp");
    strcpy(file_name[14], "BCDca.bmp");
    strcpy(file_name[15], "svnSeg.bmp");
    strcpy(file_name[16], "BinADD.bmp");
  }
  //Init SD_Card
  pinMode(48, OUTPUT);

  if (!SD.begin(48)) {
    tft.Set_Text_Back_colour(BLUE);
    tft.Set_Text_colour(WHITE);
    tft.Set_Text_Size(1);
    tft.Print_String("SD Card Init fail!", 0, 0);
  }

  //tft.Fill_Screen(RED);
  //tft.Fill_Screen(GREEN);
  //tft.Fill_Screen(BLUE);

  //disp_LoadingScreen();
  //delay(2000);
  //tft.Fill_Screen(BLACK);
}

void loop() {

  switch (currentScreen) {
    case 0x0000:
      disp_Home();
      break;
    case 0x1000:
      disp_IC_select();
      break;
    case 0x1100:
      disp_74LSXX();
      break;
    case 0x1110:
      disp_74LS08_TestResult();
      break;
    case 0x1111:
      disp_TruthTable();
      break;
    case 0x1112:
      disp_ICDetails();
      break;
    case 0x1114:
      disp_TestReport();
      break;
    case 0x1115:
      disp_TestReport_74LS47_74LS48();
      break;
    case 0x1116:
      disp_TestReport_74LS83();
      break;
    case 0x1210:
      disp_74LS04_TestResult();
      break;
    case 0x1310:
      disp_74LS32_TestResult();
      break;
    case 0x1410:
      disp_74LS00_TestResult();
      break;
    case 0x1510:
      disp_74LS02_TestResult();
      break;
    case 0x1610:
      disp_74LS86_TestResult();
      break;
    case 0x1710:
      disp_74LS83_TestResult();
      break;
    case 0x1810:
      disp_74LS47_TestResult();
      break;
    case 0x1910:
      disp_74LS48_TestResult();
      break;
    case 0x2000:
      disp_Resistor_test();
      break;
    case 0x3000:
      disp_Transistor_test();
      break;
    case 0xFFFF:
      testScreen();
      break;
    default:
      disp_Home();
      break;
  }

  if (touch_toggle && millis() - touch_last_millis >= 100) {
    touch_toggle = false;
  }

  if (currentScreen != previous_ScreenID) {
    Serial.println("Current Screen:" + String(currentScreen, HEX));
    previous_ScreenID = currentScreen;
  }

  //Serial.print("CurrentScreen: ");
  //Serial.println(currentScreen, HEX);
}

//This is the function for printing any string on the TFT LCD ofcourse any string will disp_Home


void show_string(String str, int16_t x, int16_t y, uint8_t csize, uint16_t fc, uint16_t bc, boolean mode) {
  tft.Set_Text_Mode(mode);
  tft.Set_Text_Size(csize);
  tft.Set_Text_colour(fc);
  tft.Set_Text_Back_colour(bc);
  tft.Print_String(str, x, y);
}
