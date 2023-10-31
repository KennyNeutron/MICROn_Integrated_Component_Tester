//Screen: TEST IC 74LSXX
//Screen ID: 0x1100

bool disp_74LSXX_init = false;

bool ICtest_74LSXX_started = false;
bool ICtest_74LSXX_done = false;

void disp_74LSXX() {
  if (!disp_74LSXX_init) {
    disp_74LSXX_INIT();
  }

  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    long cx = map(p.x, 130, 4000, 0, 800);
    long cy = map(p.y, 216, 3820, 0, 480);

    if (cx > 10 && cx < 70 && cy > 5 && cy < 65) {
      //Back Button
      tft.Set_Draw_color(WHITE);
      tft.Draw_Circle(40, 35, 35);

      btn_Back_pressed = true;
      touch_IsTouched();
    } else if (cx > 320 && cx < 475 && cy > 380 && cy < 430) {
      print_button_test_pressed();

      btn_testIC_pressed = true;
    }
  } else {
    if (btn_Back_pressed && !touch_toggle) {
      tft.Set_Draw_color(BLACK);
      tft.Draw_Circle(40, 35, 35);

      btn_Back_pressed = false;
      btn_pressed = 255;
    } else if (btn_testIC_pressed && !touch_toggle) {
      //Test (74LSXX) Button
      print_button_test();
      test_74LSXX();

      ICtest_last_millis = millis();
      btn_testIC_pressed = false;
    }
  }

  if (ICtest_74LSXX_started && (millis() - ICtest_last_millis) > 1000 && !ICtest_74LSXX_done) {
    show_string("Getting Result", CENTER, 210, 6, WHITE, BLACK, 0);
    ICtest_74LSXX_done = true;
  }

  if (ICtest_74LSXX_started && ICtest_74LSXX_done && (millis() - ICtest_last_millis) > 2000) {
    switch (IC_tested) {
      case IC_74LS08:
        currentScreen = 0x1110;
        break;
      case IC_74LS32:
        currentScreen = 0x1310;
        break;
      case IC_74LS00:
        currentScreen = 0x1410;
        break;
    }
    disp_74LSXX_exit();
  }

  //CONDITION based on the btn_pressed
  if (!btn_Back_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        currentScreen = 0x1000;
        break;
    }
    disp_74LSXX_exit();
  }
}

void test_74LSXX() {

  test_IC14();

  show_string("TESTING IC", CENTER, 210, 6, WHITE, BLACK, 0);
  ICtest_74LSXX_started = true;
}

void disp_74LSXX_exit() {
  IC14_pinMode_exit();

  disp_74LSXX_init = false;
  btn_Back_pressed = false;

  ICtest_74LSXX_started = false;
  ICtest_74LSXX_done = false;

  ICtest_last_millis = 0;

  btn_pressed = 0;
}


void disp_74LSXX_INIT() {
  tft.Fill_Screen(BLACK);

  IC14_pinMode_init();

  File bmp_file;
  bmp_file = SD.open(file_name[2]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  switch (IC_tested) {
    case IC_74LS08:
      display_TitleBar("Integrated Circuit TESTER", "74LS08- AND Gate");
      break;
    case IC_74LS32:
      display_TitleBar("Integrated Circuit TESTER", "74LS32- OR Gate");
      break;
    case IC_74LS00:
      display_TitleBar("Integrated Circuit TESTER", "74LS00- NAND Gate");
      break;
  }


  //TEST Button
  print_button_test();

  disp_74LSXX_init = true;
}