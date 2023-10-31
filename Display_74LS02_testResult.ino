//Screen: TEST IC 74LS02
//Screen ID: 0x1510

bool disp_74LS02_TestResult_init = false;
bool ICtest_74LS02_done = false;

void disp_74LS02_TestResult() {
  if (!disp_74LS02_TestResult_init) {
    disp_74LS02_TestResult_INIT();
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
    disp_74LS02_TestResult_exit();
  }

  //Hightlight the ERRORS by BLINKING
  if (errorLG1) {
    if (!blink) {
      tft.Set_Draw_color(RED);
      tft.Draw_Rectangle(65, 173, 145, 236);
      tft.Draw_Rectangle(64, 172, 146, 237);
    } else {
      tft.Set_Draw_color(GREEN);
      tft.Draw_Rectangle(65, 173, 145, 236);
      tft.Draw_Rectangle(64, 172, 146, 237);
    }
  }
  if (errorLG2) {
    if (!blink) {
      tft.Set_Draw_color(RED);
      tft.Draw_Rectangle(65, 243, 145, 306);  //Error on LG2
      tft.Draw_Rectangle(64, 242, 146, 307);  //Error on LG2
    } else {
      tft.Set_Draw_color(GREEN);
      tft.Draw_Rectangle(65, 243, 145, 306);  //Error on LG2
      tft.Draw_Rectangle(64, 242, 146, 307);  //Error on LG2
    }
  }
  if (errorLG3) {
    if (!blink) {
      tft.Set_Draw_color(RED);
      tft.Draw_Rectangle(155, 268, 225, 332);  //Error on LG3
      tft.Draw_Rectangle(154, 267, 226, 333);  //Error on LG3
    } else {
      tft.Set_Draw_color(GREEN);
      tft.Draw_Rectangle(155, 268, 225, 332);  //Error on LG3
      tft.Draw_Rectangle(154, 267, 226, 333);  //Error on LG3
    }
  }
  if (errorLG4) {
    if (!blink) {
      tft.Set_Draw_color(RED);
      tft.Draw_Rectangle(155, 195, 225, 262);  //Error on LG4
      tft.Draw_Rectangle(154, 194, 226, 263);  //Error on LG4
    } else {
      tft.Set_Draw_color(GREEN);
      tft.Draw_Rectangle(155, 195, 225, 262);  //Error on LG4
      tft.Draw_Rectangle(154, 194, 226, 263);  //Error on LG4
    }
  }


  if (millis() - blink_last_millis > 200) {
    blink = !blink;
    blink_last_millis = millis();
  }
}

void disp_74LS02_TestResult_exit() {
  disp_74LS02_TestResult_init = false;
  ICtest_74LS02_done = false;

  disp_74LS02_TestResult_init = false;
  btn_pressed = 0;

  errorLG1 = false;
  errorLG2 = false;
  errorLG3 = false;
  errorLG4 = false;

  IC_tested = IC_74LS02;
}

bool get_TestResult_74LS02_LG1() {
  if (!get_LG3_Result00() || get_LG3_Result01() || get_LG3_Result10() || get_LG3_Result11()) {
    return false;
  } else {
    return true;
  }
}
bool get_TestResult_74LS02_LG2() {
  if (!get_LG4_Result00() || get_LG4_Result01() || get_LG4_Result10() || get_LG4_Result11()) {
    return false;
  } else {
    return true;
  }
}
bool get_TestResult_74LS02_LG3() {
  if (!get_LG1_Result00() || get_LG1_Result01() || get_LG1_Result10() || get_LG1_Result11()) {
    return false;
  } else {
    return true;
  }
}
bool get_TestResult_74LS02_LG4() {
  if (!get_LG2_Result00() || get_LG2_Result01() || get_LG2_Result10() || get_LG2_Result11()) {
    return false;
  } else {
    return true;
  }
}




void disp_74LS02_TestResult_INIT() {
  uint8_t NumOf_ErrorGate = 0;

  String str_NumOf_ErrorGate = "# Of BAD Logic Gate(s): ";
  String str_ErrorGate = "Bad Logic Gate(s): ";

  Serial.println("\n\n\nLooking For ERRORS");
  //TEST LG1
  if (!get_TestResult_74LS02_LG1()) {
    Serial.println("LG1 ERROR");
    str_ErrorGate = str_ErrorGate + " LG1";
    errorLG1 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS02_LG2()) {
    Serial.println("LG2 ERROR");
    if (errorLG1) {
      str_ErrorGate = str_ErrorGate + ", LG2";
    } else {
      str_ErrorGate = str_ErrorGate + " LG2";
    }
    errorLG2 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS02_LG3()) {
    Serial.println("LG3 ERROR");

    if (errorLG1 || errorLG2) {
      str_ErrorGate = str_ErrorGate + ", LG3";
    } else {
      str_ErrorGate = str_ErrorGate + " LG3";
    }
    errorLG3 = true;
    NumOf_ErrorGate++;
  }
  if (!get_TestResult_74LS02_LG4()) {
    Serial.println("LG4 ERROR");
    if (errorLG1 || errorLG2 || errorLG3) {
      str_ErrorGate = str_ErrorGate + ", LG4";
    } else {
      str_ErrorGate = str_ErrorGate + " LG4";
    }
    NumOf_ErrorGate++;
    errorLG4 = true;
  }

  if (NumOf_ErrorGate > 0) {
    bad_ic = true;
  } else {
    bad_ic = false;
  }

  Serial.println("\n\n\n******74LS02 Test Results******");
  Serial.println("\nLogic Gate #1: " + String(get_TestResult_74LS02_LG1()));
  Serial.println("Logic Gate #2: " + String(get_TestResult_74LS02_LG2()));
  Serial.println("Logic Gate #3: " + String(get_TestResult_74LS02_LG3()));
  Serial.println("Logic Gate #4: " + String(get_TestResult_74LS02_LG4()));

  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  display_TitleBar("Integrated Circuit TESTER", "74LS02 TEST RESULT");

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



  show_string(str_NumOf_ErrorGate + String(NumOf_ErrorGate), 320, 230, 2, WHITE, BLACK, 0);
  show_string(str_ErrorGate, 320, 270, 2, WHITE, BLACK, 0);

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



  bmp_file = SD.open(file_name[6]);
  draw_bmp_picture(bmp_file, 50, 150);
  bmp_file.close();

  /*
  tft.Set_Draw_color(RED);
  tft.Draw_Rectangle(65, 173, 145, 236);  //Error on LG1
  tft.Draw_Rectangle(64, 172, 146, 237);  //Error on LG1

  tft.Draw_Rectangle(65, 243, 145, 306);  //Error on LG2
  tft.Draw_Rectangle(64, 242, 146, 307);  //Error on LG2

  tft.Draw_Rectangle(155, 195, 225, 262);  //Error on LG4
  tft.Draw_Rectangle(154, 194, 226, 263);  //Error on LG4

  tft.Draw_Rectangle(155, 268, 225, 332);  //Error on LG3
  tft.Draw_Rectangle(154, 267, 226, 333);  //Error on LG3
  */


  ICtest_74LS02_done = true;

  disp_74LS02_TestResult_init = true;
  blink_last_millis = millis();
}