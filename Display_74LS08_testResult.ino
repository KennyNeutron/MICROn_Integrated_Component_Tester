//Screen: TEST IC 74LS08
//Screen ID: 0x1110

bool disp_74LS08_TestResult_init = false;

void disp_74LS08_TestResult() {
  if (!disp_74LS08_TestResult_init) {
    disp_74LS08_TestResult_INIT();
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
    }
  } else {
    if (btn_Home_pressed && !touch_toggle) {
      //Home Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = false;
      btn_pressed = 255;
    }
  }

  //CONDITION based on the btn_pressed
  if (!btn_Home_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        currentScreen = 0x0000;
        break;
      default:
        currentScreen = 0x0000;
        break;
    }
    disp_74LS08_TestResult_exit();
  }
}

void disp_74LS08_TestResult_exit() {
  disp_74LS08_TestResult_init = false;
  ICtest_74LS08_done = false;

  disp_74LS08_TestResult_init = false;
  btn_pressed = 0;
}

void disp_74LS08_TestResult_INIT() {
  bool bad_ic = false;

  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  
  bmp_file = SD.open(file_name[3]);
  draw_bmp_picture(bmp_file, 50, 150);
  bmp_file.close();
  

  show_string("Integrated Circuit TESTER", CENTER, 30, 4, WHITE, WHITE, 0);
  show_string("S74LS08 TEST RESULT", CENTER, 80, 3, WHITE, WHITE, 0);
  tft.Set_Draw_color(RED);
  tft.Draw_Line(50, 70, 750, 70);

  //REPORT MESSAGE
  if (bad_ic) {
    tft.Set_Draw_color(RED);
    tft.Fill_Round_Rectangle(390, 150, 660, 210, 12);
    tft.Set_Draw_color(WHITE);
    tft.Draw_Round_Rectangle(390, 150, 660, 210, 12);
    show_string("BAD IC", 420, 160, 6, WHITE, RED, 0);
  } else {
    tft.Set_Draw_color(GREEN);
    tft.Fill_Round_Rectangle(390, 150, 660, 210, 12);
    tft.Set_Draw_color(WHITE);
    tft.Draw_Round_Rectangle(390, 150, 660, 210, 12);
    show_string("GOOD IC", 400, 160, 6, BLACK, GREEN, 0);
  }

  uint8_t NumOf_ErrorGate = 3;

  String str_NumOf_ErrorGate = "# Of BAD Logic Gate(s): ";
  String str_ErrorGate = "Bad Logic Gate(s): ";

  show_string(str_NumOf_ErrorGate + String(NumOf_ErrorGate), 380, 230, 2, WHITE, BLACK, 0);
  show_string(str_ErrorGate, 380, 270, 2, WHITE, BLACK, 0);


  //Truth Table Button
  tft.Set_Draw_color(CYAN);
  tft.Fill_Round_Rectangle(290, 340, 510, 380, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(290, 340, 510, 380, 6);
  show_string("TRUTH Table", CENTER, 350, 3, BLACK, CYAN, 0);


  //IC Details
  tft.Set_Draw_color(CYAN);
  tft.Fill_Round_Rectangle(590, 340, 790, 380, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 340, 790, 380, 6);
  show_string("IC Details", 600, 350, 3, BLACK, CYAN, 0);

  //TEST report
  tft.Set_Draw_color(MAGENTA);
  tft.Fill_Round_Rectangle(440, 400, 660, 440, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(440, 400, 660, 440, 6);
  show_string("TEST REPORT", 450, 410, 3, BLACK, MAGENTA, 0);


  ICtest_74LS08_done = true;

  disp_74LS08_TestResult_init = true;
}