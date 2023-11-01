//Screen: TEST IC 74LS04
//Screen ID: 0x1210

bool disp_74LS04_TestResult_init = false;
bool ICtest_74LS04_done = false;

void disp_74LS04_TestResult() {
  if (!disp_74LS04_TestResult_init) {
    disp_74LS04_TestResult_INIT();
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
    } else if (bad_ic && cx > 590 && cx < 790 && cy > 400 && cy < 440) {
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
    } else if (bad_ic && btn_TestReport_pressed && !touch_toggle) {
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
        currentScreen = 0x1114;
        break;

      default:
        currentScreen = 0x0000;
        break;
    }

    disp_74LS04_TestResult_exit();
  }
}

void disp_74LS04_TestResult_exit() {
  errorNG1 = false;
  errorNG2 = false;
  errorNG3 = false;
  errorNG4 = false;
  errorNG5 = false;
  errorNG6 = false;

  btn_pressed = 0;
  disp_74LS04_TestResult_init = false;
}


void disp_74LS04_TestResult_INIT() {
  uint8_t NumOf_ErrorGate = 0;

  String str_NumOf_ErrorGate = "# Of BAD Logic Gate(s): ";
  String str_ErrorGate = "Bad Logic Gate(s): ";

  Serial.println("\n\n\nLooking For ERRORS");

  //test NG1
  if (!get_TestResult_74LS04_NG1()) {
    Serial.println("NG1 ERROR");
    str_ErrorGate = str_ErrorGate + " LG1";
    errorNG1 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS04_NG2()) {
    Serial.println("NG2 ERROR");
    if (errorNG1) {
      str_ErrorGate = str_ErrorGate + ", NG2";
    } else {
      str_ErrorGate = str_ErrorGate + " NG2";
    }
    errorNG2 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS04_NG3()) {
    Serial.println("NG3 ERROR");
    if (errorNG1) {
      str_ErrorGate = str_ErrorGate + ", NG3";
    } else {
      str_ErrorGate = str_ErrorGate + " NG3";
    }
    errorNG3 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS04_NG4()) {
    Serial.println("NG4 ERROR");
    if (errorNG1) {
      str_ErrorGate = str_ErrorGate + ", NG4";
    } else {
      str_ErrorGate = str_ErrorGate + " NG4";
    }
    errorNG4 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS04_NG5()) {
    Serial.println("NG5 ERROR");
    if (errorNG1) {
      str_ErrorGate = str_ErrorGate + ", NG5";
    } else {
      str_ErrorGate = str_ErrorGate + " NG5";
    }
    errorNG5 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS04_NG6()) {
    Serial.println("NG6 ERROR");
    if (errorNG1) {
      str_ErrorGate = str_ErrorGate + ", NG6";
    } else {
      str_ErrorGate = str_ErrorGate + " NG6";
    }
    errorNG6 = true;
    NumOf_ErrorGate++;
  }


  if (NumOf_ErrorGate > 0) {
    bad_ic = true;
  } else {
    bad_ic = false;
  }

  Serial.println("\n\n\n******74LS04 Test Results******");
  Serial.println("\nLogic NOT Gate #1: " + String(get_TestResult_74LS04_NG1()));
  Serial.println("\nLogic NOT Gate #2: " + String(get_TestResult_74LS04_NG2()));
  Serial.println("\nLogic NOT Gate #3: " + String(get_TestResult_74LS04_NG3()));
  Serial.println("\nLogic NOT Gate #4: " + String(get_TestResult_74LS04_NG4()));
  Serial.println("\nLogic NOT Gate #5: " + String(get_TestResult_74LS04_NG5()));
  Serial.println("\nLogic NOT Gate #6: " + String(get_TestResult_74LS04_NG6()));

  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  display_TitleBar("Integrated Circuit TESTER", "74LS04 TEST RESULT");

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
  if (bad_ic) {
    print_button_TestReport();
  }


  disp_74LS04_TestResult_init = true;
}

bool get_TestResult_74LS04_NG1() {
  if (!get_NG1_Result0() || get_NG1_Result1()) {
    return false;
  } else {
    return true;
  }
}

bool get_TestResult_74LS04_NG2() {
  if (!get_NG2_Result0() || get_NG2_Result1()) {
    return false;
  } else {
    return true;
  }
}

bool get_TestResult_74LS04_NG3() {
  if (!get_NG3_Result0() || get_NG3_Result1()) {
    return false;
  } else {
    return true;
  }
}

bool get_TestResult_74LS04_NG4() {
  if (!get_NG4_Result0() || get_NG4_Result1()) {
    return false;
  } else {
    return true;
  }
}

bool get_TestResult_74LS04_NG5() {
  if (!get_NG5_Result0() || get_NG5_Result1()) {
    return false;
  } else {
    return true;
  }
}

bool get_TestResult_74LS04_NG6() {
  if (!get_NG6_Result0() || get_NG6_Result1()) {
    return false;
  } else {
    return true;
  }
}