//Screen: IC SELECT SCREEN
//Screen ID: 0x1000

bool disp_ic_select_init = false;

//ROW 1
bool btn_74LS08_pressed = false;
bool btn_74LS04_pressed = false;
bool btn_74LS32_pressed = false;

//ROW 2
bool btn_74LS00_pressed = false;
bool btn_74LS02_pressed = false;
bool btn_74LS86_pressed = false;

//ROW 3
bool btn_74LS83_pressed = false;
bool btn_74LS47_pressed = false;
bool btn_74LS48_pressed = false;

//ROW 4
bool btn_74LS147_pressed = false;
bool btn_74LS42_pressed = false;
bool btn_NE555_pressed = false;

void disp_IC_select() {
  if (!disp_ic_select_init) {
    disp_IC_select_init();
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
    } else if (cx > 45 && cx < 200 && cy > 140 && cy < 190) {
      //74LS08 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(45, 140, 200, 190, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(45, 140, 200, 190, 9);
      show_string("74LS08", 50, 150, 4, WHITE, BLUE, 0);

      btn_74LS08_pressed = true;
      touch_IsTouched();
    } else if (cx > 320 && cx < 475 && cy > 140 && cy < 190) {
      //74LS04 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(320, 140, 475, 190, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 140, 475, 190, 9);
      show_string("74LS04", CENTER, 150, 4, WHITE, BLUE, 0);

      btn_74LS04_pressed = true;
      touch_IsTouched();
    } else if (cx > 590 && cx < 745 && cy > 140 && cy < 190) {
      //74LS32 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(590, 140, 745, 190, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(590, 140, 745, 190, 9);
      show_string("74LS32", 600, 150, 4, WHITE, BLUE, 0);

      btn_74LS32_pressed = true;
      touch_IsTouched();
    } else if (cx > 45 && cx < 200 && cy > 220 && cy < 270) {
      //74LS00 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(45, 220, 200, 270, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(45, 220, 200, 270, 9);
      show_string("74LS00", 50, 230, 4, WHITE, BLUE, 0);

      btn_74LS00_pressed = true;
      touch_IsTouched();
    } else if (cx > 320 && cx < 475 && cy > 220 && cy < 270) {
      //74LS02 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(320, 220, 475, 270, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 220, 475, 270, 9);
      show_string("74LS02", CENTER, 230, 4, WHITE, BLUE, 0);

      btn_74LS02_pressed = true;
      touch_IsTouched();
    } else if (cx > 590 && cx < 745 && cy > 220 && cy < 270) {
      //74LS86 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(590, 220, 745, 270, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(590, 220, 745, 270, 9);
      show_string("74LS86", 600, 230, 4, WHITE, BLUE, 0);

      btn_74LS86_pressed = true;
      touch_IsTouched();
    } else if (cx > 45 && cx < 200 && cy > 300 && cy < 350) {
      //74LS83 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(45, 300, 200, 350, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(45, 300, 200, 350, 9);
      show_string("74LS83", 50, 310, 4, WHITE, BLUE, 0);

      btn_74LS83_pressed = true;
      touch_IsTouched();
    } else if (cx > 320 && cx < 475 && cy > 300 && cy < 350) {
      //74LS47 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(320, 300, 475, 350, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 300, 475, 350, 9);
      show_string("74LS47", CENTER, 310, 4, WHITE, BLUE, 0);

      btn_74LS47_pressed = true;
      touch_IsTouched();
    } else if (cx > 590 && cx < 745 && cy > 300 && cy < 350) {
      //74LS48 Button
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(590, 300, 745, 350, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(590, 300, 745, 350, 9);
      show_string("74LS48", 600, 310, 4, WHITE, BLUE, 0);

      btn_74LS48_pressed = true;
      touch_IsTouched();
    }
    //    else if (cx > 45 && cx < 200 && cy > 380 && cy < 430) {
    //      //74LS147 Button
    //      tft.Set_Draw_color(BLUE);
    //      tft.Fill_Round_Rectangle(45, 380, 200, 430, 9);
    //      tft.Set_Draw_color(WHITE);
    //      tft.Draw_Round_Rectangle(45, 380, 200, 430, 9);
    //      show_string("74LS147", 65, 395, 3, WHITE, BLUE, 0);
    //
    //      btn_74LS147_pressed = true;
    //      touch_IsTouched();
    //    } else if (cx > 320 && cx < 475 && cy > 380 && cy < 430) {
    //      //74LS42 Button
    //      tft.Set_Draw_color(BLUE);
    //      tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
    //      tft.Set_Draw_color(WHITE);
    //      tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
    //      show_string("74LS42", CENTER, 390, 4, WHITE, BLUE, 0);
    //
    //      btn_74LS42_pressed = true;
    //      touch_IsTouched();
    //    } else if (cx > 590 && cx < 745 && cy > 380 && cy < 430) {
    //      //NE555 Button
    //      tft.Set_Draw_color(BLUE);
    //      tft.Fill_Round_Rectangle(590, 380, 745, 430, 9);
    //      tft.Set_Draw_color(WHITE);
    //      tft.Draw_Round_Rectangle(590, 380, 745, 430, 9);
    //      show_string("NE555", 610, 390, 4, WHITE, BLUE, 0);
    //
    //      btn_NE555_pressed = true;
    //      touch_IsTouched();
    //    }
  } else {
    if (btn_Home_pressed && !touch_toggle) {
      //Home Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = false;
      btn_pressed = 255;
    } else if (btn_74LS08_pressed && !touch_toggle) {
      //74LS08 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(45, 140, 200, 190, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(45, 140, 200, 190, 9);
      show_string("74LS08", 50, 150, 4, BLACK, GREEN, 0);

      btn_74LS08_pressed = false;
      btn_pressed = 1;
      IC_tested = IC_74LS08;
    } else if (btn_74LS04_pressed && !touch_toggle) {
      //74LS04 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(320, 140, 475, 190, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 140, 475, 190, 9);
      show_string("74LS04", CENTER, 150, 4, BLACK, GREEN, 0);

      btn_74LS04_pressed = false;
      btn_pressed = 2;
      IC_tested = IC_74LS04;
    } else if (btn_74LS32_pressed && !touch_toggle) {
      //74LS32 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(590, 140, 745, 190, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(590, 140, 745, 190, 9);
      show_string("74LS32", 600, 150, 4, BLACK, GREEN, 0);

      btn_74LS32_pressed = false;
      btn_pressed = 3;
      IC_tested = IC_74LS32;
    } else if (btn_74LS00_pressed && !touch_toggle) {
      //74LS00 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(45, 220, 200, 270, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(45, 220, 200, 270, 9);
      show_string("74LS00", 50, 230, 4, BLACK, GREEN, 0);

      btn_74LS00_pressed = false;
      btn_pressed = 4;
      IC_tested = IC_74LS00;
    } else if (btn_74LS02_pressed && !touch_toggle) {
      //74LS02 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(320, 220, 475, 270, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 220, 475, 270, 9);
      show_string("74LS02", CENTER, 230, 4, BLACK, GREEN, 0);

      btn_74LS02_pressed = false;
      btn_pressed = 5;
      IC_tested = IC_74LS02;
    } else if (btn_74LS86_pressed && !touch_toggle) {
      //74LS86 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(590, 220, 745, 270, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(590, 220, 745, 270, 9);
      show_string("74LS86", 600, 230, 4, BLACK, GREEN, 0);

      btn_74LS86_pressed = false;
      btn_pressed = 6;
      IC_tested = IC_74LS86;
    } else if (btn_74LS83_pressed && !touch_toggle) {
      //74LS83 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(45, 300, 200, 350, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(45, 300, 200, 350, 9);
      show_string("74LS83", 50, 310, 4, BLACK, GREEN, 0);

      btn_74LS83_pressed = false;
      btn_pressed = 7;
      IC_tested = IC_74LS83;
    } else if (btn_74LS47_pressed && !touch_toggle) {
      //74LS47 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(320, 300, 475, 350, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 300, 475, 350, 9);
      show_string("74LS47", CENTER, 310, 4, BLACK, GREEN, 0);

      btn_74LS47_pressed = false;
      btn_pressed = 8;
      IC_tested = IC_74LS47;
    } else if (btn_74LS48_pressed && !touch_toggle) {
      //74LS48 Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(590, 300, 745, 350, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(590, 300, 745, 350, 9);
      show_string("74LS48", 600, 310, 4, BLACK, GREEN, 0);

      btn_74LS48_pressed = false;
      btn_pressed = 9;
      IC_tested = IC_74LS48;
    }
    //     else if (btn_74LS147_pressed && !touch_toggle) {
    //      //74LS147 Button
    //      tft.Set_Draw_color(GREEN);
    //      tft.Fill_Round_Rectangle(45, 380, 200, 430, 9);
    //      tft.Set_Draw_color(WHITE);
    //      tft.Draw_Round_Rectangle(45, 380, 200, 430, 9);
    //      show_string("74LS147", 65, 395, 3, BLACK, GREEN, 0);
    //
    //      btn_74LS147_pressed = false;
    //    } else if (btn_74LS42_pressed && !touch_toggle) {
    //      //74LS42 Button
    //      tft.Set_Draw_color(GREEN);
    //      tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
    //      tft.Set_Draw_color(WHITE);
    //      tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
    //      show_string("74LS42", CENTER, 390, 4, BLACK, GREEN, 0);
    //
    //      btn_74LS42_pressed = false;
    //    } else if (btn_NE555_pressed && !touch_toggle) {
    //      //NE555 Button
    //      tft.Set_Draw_color(GREEN);
    //      tft.Fill_Round_Rectangle(590, 380, 745, 430, 9);
    //      tft.Set_Draw_color(WHITE);
    //      tft.Draw_Round_Rectangle(590, 380, 745, 430, 9);
    //      show_string("NE555", 610, 390, 4, BLACK, GREEN, 0);
    //
    //      btn_NE555_pressed = false;
    //    }
  }

  //CONDITION based on the btn_pressed
  if (!btn_Home_pressed && !btn_74LS08_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        currentScreen = 0x0000;
        break;
      case 1:
        currentScreen = 0x1100;
        break;
      case 2:
        currentScreen = 0x1100;
        break;
      case 3:
        currentScreen = 0x1100;
        break;
      case 4:
        currentScreen = 0x1100;
      case 5:
        currentScreen = 0x1100;
        break;
      case 6:
        currentScreen = 0x1100;
        break;
      case 7:
        currentScreen = 0x1100;
        break;
      case 8:
        currentScreen = 0x1100;
        break;
      case 9:
        currentScreen = 0x1100;
        break;
    }
    disp_IC_select_exit();
  }
}

void disp_IC_select_exit() {
  disp_ic_select_init = false;
  btn_Home_pressed = false;
  btn_74LS08_pressed = false;

  btn_pressed = 0;
}



void disp_IC_select_init() {

  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 10);
  bmp_file.close();

  display_TitleBar("Integrated Circuit TESTER", "Select IC");


  //=========== ROW 1 ==================================
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(45, 140, 200, 190, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(45, 140, 200, 190, 9);
  show_string("74LS08", 50, 150, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 140, 475, 190, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 140, 475, 190, 9);
  show_string("74LS04", CENTER, 150, 4, BLACK, GREEN, 0);


  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(590, 140, 745, 190, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 140, 745, 190, 9);
  show_string("74LS32", 600, 150, 4, BLACK, GREEN, 0);
  //====================================================


  //=========== ROW 2 ==================================
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(45, 220, 200, 270, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(45, 220, 200, 270, 9);
  show_string("74LS00", 50, 230, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 220, 475, 270, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 220, 475, 270, 9);
  show_string("74LS02", CENTER, 230, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(590, 220, 745, 270, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 220, 745, 270, 9);
  show_string("74LS86", 600, 230, 4, BLACK, GREEN, 0);
  //====================================================

  //=========== ROW 3 ==================================
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(45, 300, 200, 350, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(45, 300, 200, 350, 9);
  show_string("74LS83", 50, 310, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 300, 475, 350, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 300, 475, 350, 9);
  show_string("74LS47", CENTER, 310, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(590, 300, 745, 350, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 300, 745, 350, 9);
  show_string("74LS48", 600, 310, 4, BLACK, GREEN, 0);
  //====================================================

  //  //=========== ROW 4 ==================================
  //  tft.Set_Draw_color(GREEN);
  //  tft.Fill_Round_Rectangle(45, 380, 200, 430, 9);
  //  tft.Set_Draw_color(WHITE);
  //  tft.Draw_Round_Rectangle(45, 380, 200, 430, 9);
  //  show_string("74LS147", 65, 395, 3, BLACK, GREEN, 0);
  //
  //  tft.Set_Draw_color(GREEN);
  //  tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
  //  tft.Set_Draw_color(WHITE);
  //  tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
  //  show_string("74LS42", CENTER, 390, 4, BLACK, GREEN, 0);
  //
  //  tft.Set_Draw_color(GREEN);
  //  tft.Fill_Round_Rectangle(590, 380, 745, 430, 9);
  //  tft.Set_Draw_color(WHITE);
  //  tft.Draw_Round_Rectangle(590, 380, 745, 430, 9);
  //  show_string("NE555", 610, 390, 4, BLACK, GREEN, 0);
  //  //====================================================




  disp_ic_select_init = true;
}
