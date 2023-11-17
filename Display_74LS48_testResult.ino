//Screen: Test IC 74LS48
//Screen ID: 0x1910

bool disp_74LS48_TestResult_init = false;
bool ICtest_74LS48_done = false;


void disp_74LS48_TestResult() {
  if (!disp_74LS48_TestResult_init) {
    disp_74LS48_TestResult_INIT();
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
    } else if (cx > 290 && cx < 510 && cy > 340 && cy < 380) {
      print_button_TruthTable_pressed();
      btn_TruthTable_pressed = true;
      touch_IsTouched();
    } else if (cx > 590 && cx < 790 && cy > 340 && cy < 380) {
      print_button_ICDetails_pressed();
      btn_ICDetails_pressed = true;
      touch_IsTouched();
    } else if (cx > 290 && cx < 510 && cy > 400 && cy < 440) {
      print_button_TestAnotherIC_pressed();
      btn_TestAnotherIC_pressed = true;
      touch_IsTouched();
    } else if (cx > 590 && cx < 790 && cy > 400 && cy < 440) {
      print_button_TestReport_pressed();
      btn_TestReport_pressed = true;
      touch_IsTouched();
    }

  } else {
    if (btn_Home_pressed && !touch_toggle) {
      //Home Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = false;
      btn_pressed = 255;
    } else if (btn_TruthTable_pressed && !touch_toggle) {
      print_button_TruthTable();
      btn_TruthTable_pressed = false;
      btn_pressed = 1;
    } else if (btn_ICDetails_pressed && !touch_toggle) {
      print_button_ICDetails();
      btn_ICDetails_pressed = false;
      btn_pressed = 2;
    } else if (btn_TestAnotherIC_pressed && !touch_toggle) {
      print_button_TestAnotherIC();
      btn_TestAnotherIC_pressed = false;
      btn_pressed = 3;
    } else if (btn_TestReport_pressed && !touch_toggle) {
      print_button_TestReport();
      btn_TestReport_pressed = false;
      btn_pressed = 4;
    }
  }


  //CONDITION based on the btn_pressed
  if (!btn_Home_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        currentScreen = 0x0000;
        break;
      case 1:
        currentScreen = 0x1111;
        break;
      case 2:
        currentScreen = 0x1112;
        break;
      case 3:
        currentScreen = 0x1000;
        break;
      case 4:
        currentScreen = 0x1115;
        break;
      default:
        currentScreen = 0x0000;
        break;
    }
    disp_74LS48_TestResult_exit();
  }
}


void disp_74LS48_TestResult_exit() {
  disp_74LS48_TestResult_init = false;
  ICtest_74LS48_done = false;

  btn_pressed = 0;
  IC_tested = IC_74LS48;
}

void disp_74LS48_TestResult_INIT() {
  Serial.println("74LS48 IC test Result");

  for (int i = 0; i < 10; i++) {
    Serial.print("INPUT:");
    Serial.print(i);
    Serial.print("\tOUTPUT:");
    Serial.println(BCD_7Segment_Out[i]);
  }

  if (BCD_7Segment_Out[0] == 126 && BCD_7Segment_Out[1] == 48 && BCD_7Segment_Out[2] == 109 && BCD_7Segment_Out[3] == 121 && BCD_7Segment_Out[4] == 51 && BCD_7Segment_Out[5] == 91 && BCD_7Segment_Out[6] == 31 && BCD_7Segment_Out[7] == 112 && BCD_7Segment_Out[8] == 127 && BCD_7Segment_Out[9] == 115) {
    bad_ic = false;
  } else {
    bad_ic = true;
  }


  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  display_TitleBar("Integrated Circuit TESTER", "74LS48 TEST RESULT");

  //REPORT MESSAGE
  if (bad_ic) {
    tft.Set_Draw_color(RED);
    tft.Fill_Round_Rectangle(390, 150, 660, 210, 12);
    tft.Set_Draw_color(WHITE);
    tft.Draw_Round_Rectangle(390, 150, 660, 210, 12);
    show_string("BAD IC", 420, 160, 6, WHITE, RED, 0);
  } else {
    bad_ic = false;
    tft.Set_Draw_color(GREEN);
    tft.Fill_Round_Rectangle(390, 150, 660, 210, 12);
    tft.Set_Draw_color(WHITE);
    tft.Draw_Round_Rectangle(390, 150, 660, 210, 12);
    show_string("GOOD IC", 400, 160, 6, BLACK, GREEN, 0);
  }



  //Truth Table Button
  print_button_TruthTable();


  //IC Details
  print_button_ICDetails();


  //Test Another IC
  print_button_TestAnotherIC();

  //TEST report
  print_button_TestReport();


  bmp_file = SD.open(file_name[13]);
  draw_bmp_picture(bmp_file, 50, 110);
  bmp_file.close();


  disp_74LS48_TestResult_init = true;
}