//Screen: TRANSISTOR TEST SCREEN
//Screen ID: 0x3000
#include "TransistorTest.h"

#define tPin1 A1
#define tPin2 A2
#define tPin3 A3
#define tPin1_res A8
#define tPin2_res A9
#define tPin3_res A10

TRANSISTORTEST transistor;

bool disp_transistor_test_init = false;

bool transistor_orientation = false;  //false --> C.B.E.   true --> E.B.C.

bool btn_TestTransistor_pressed = false;

unsigned int baseResistor = 10000;
unsigned int collectorResistor = 1000;


void disp_Transistor_test() {
  if (!disp_transistor_test_init) {
    disp_Transistor_test_INIT();
  }

  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    long cx = map(p.x, 130, 4000, 0, 800);
    long cy = map(p.y, 216, 3820, 0, 480);

    if (cx > 10 && cx < 70 && cy > 10 && cy < 70) {
      //Home Button
      tft.Set_Draw_color(WHITE);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = true;
      touch_IsTouched();
    } else if (cx > 320 && cx < 475 && cy > 380 && cy < 430) {
      print_button_test_pressed();
      btn_TestTransistor_pressed = true;
    }
  } else {
    if (btn_Home_pressed && !touch_toggle && !touch_toggle) {
      //Home Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = false;
      btn_pressed = 255;
    } else if (btn_TestTransistor_pressed && !touch_toggle) {
      //Test (Transistor) Button
      print_button_test();

      btn_TestTransistor_pressed = false;
      //tft.Set_Draw_color(BLACK);
      //tft.Fill_Rectangle(0, 80, 800, 350);
      run_TestTransistor();
    }
  }

  //CONDITION based on the btn_pressed
  if (!btn_Home_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        currentScreen = 0x0000;
        break;
    }
    disp_Transistor_test_exit();
  }
}


void disp_Transistor_test_exit() {


  btn_pressed = 0;
  disp_transistor_test_init = false;
  btn_TestTransistor_pressed = false;
}

void disp_Transistor_test_INIT() {
  analogReference(INTERNAL2V56);

  transistor.begin(tPin1, tPin2, tPin3, tPin1_res, tPin2_res, tPin3_res);

  tft.Fill_Screen(BLACK);



  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 10);
  bmp_file.close();

  display_TitleBar("Transistor TESTER", " ");

  print_button_test();
  disp_transistor_test_init = true;
}

void run_TestTransistor() {
  Serial.println("test transistor");

  tft.Set_Draw_color(BLACK);
  tft.Fill_Rectangle(0, 100, 800, 350);
  show_string("TESTING...", CENTER, 200, 4, WHITE, WHITE, 0);

  transistor.test();
  bool ThisIsNPN = transistor.isNPN();
  bool ThisIsPNP = transistor.isPNP();
  Serial.println("NPN:" + String(ThisIsNPN));
  Serial.println("PNP:" + String(ThisIsPNP));

  if (ThisIsNPN == ThisIsPNP) {
    tft.Set_Draw_color(BLACK);
    tft.Fill_Rectangle(0, 100, 800, 350);
    show_string("BROKEN or NO Transistor", CENTER, 200, 4, WHITE, WHITE, 0);
  } else if (ThisIsNPN &&  !ThisIsPNP) {
    Serial.println("NPN transistor detected");

    tft.Set_Draw_color(BLACK);
    tft.Fill_Rectangle(0, 100, 800, 350);

    show_string("NPN Transistor", CENTER, 100, 6, WHITE, WHITE, 0);

    bool Tpinout = transistor.pinout();
    Serial.println("Vf:" + String(transistor.getVF()) + "mV");;
    Serial.println("GAIN:" + String(transistor.getGAIN()));
    Serial.println("PINOUT:" + String(Tpinout));
    if (Tpinout == true) {
      if (transistor.getGAIN() == 0 && transistor.getVF() == 0) {
        tft.Set_Draw_color(BLACK);
        tft.Fill_Rectangle(0, 100, 800, 350);
        show_string("Invalid Ratings", CENTER, 200, 4, WHITE, WHITE, 0);
      } else {
        Serial.println("Orientation: C.-B.-E.");
        show_string("Pinout: 1-2-3 = C.-B.-E.", 400, 190, 2, WHITE, WHITE, 0);
        File bmp_file;
        bmp_file = SD.open(file_name[9]);
        draw_bmp_picture(bmp_file, 240, 180);
        bmp_file.close();
        show_string("B= " + String(transistor.getGAIN()), 400, 220, 2, WHITE, WHITE, 0);
        show_string("Vf= " + String(transistor.getVF()) + "mV", 400, 250, 2, WHITE, WHITE, 0);
      }

    } else {
      if (transistor.getGAIN() == 0 && transistor.getVF() == 0) {
        tft.Set_Draw_color(BLACK);
        tft.Fill_Rectangle(0, 100, 800, 350);
        show_string("Invalid Ratings", CENTER, 200, 4, WHITE, WHITE, 0);
      } else {
        Serial.println("Orientation: E.-B.-C.");
        show_string("Pinout: 1-2-3 = E.-B.-C.", 400, 190, 2, WHITE, WHITE, 0);
        File bmp_file;
        bmp_file = SD.open(file_name[10]);
        draw_bmp_picture(bmp_file, 240, 180);
        bmp_file.close();
        show_string("B= " + String(transistor.getGAIN()), 400, 220, 2, WHITE, WHITE, 0);
        show_string("Vf= " + String(transistor.getVF()) + "mV", 400, 250, 2, WHITE, WHITE, 0);
      }
    }



  }


  // tft.Fill_Screen(BLACK);
  // File bmp_file;
  // bmp_file = SD.open(file_name[0]);
  // draw_bmp_picture(bmp_file, 10, 10);
  // bmp_file.close();

  // display_TitleBar("Transistor TESTER", " ");
  // btn_TestTransistor_pressed = false;
  // tft.Set_Draw_color(BLACK);
  // tft.Fill_Rectangle(0, 80, 800, 350);
  // //Test (Transistor) Button
  // print_button_test();
}
