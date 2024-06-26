//Screen: IC Details
//Screen ID: 0x1112
bool disp_ICDetails_init = false;

void disp_ICDetails() {
  if (!disp_ICDetails_init) {
    disp_ICDetails_INIT();
  }

  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    long cx = map(p.x, 130, 4000, 0, 800);
    long cy = map(p.y, 216, 3820, 0, 480);

    if (cx > 10 && cx < 70 && cy > 10 && cy < 70) {
      //Back Button
      tft.Set_Draw_color(WHITE);
      tft.Draw_Circle(40, 35, 35);

      btn_Back_pressed = true;
    }
  } else {
    if (btn_Back_pressed && !touch_toggle) {
      //Back Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Circle(40, 35, 35);

      btn_Back_pressed = false;
      btn_pressed = 255;
    }
  }

  //CONDITION based on the btn_pressed
  if (!btn_Back_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        switch (IC_tested) {
          case IC_74LS08:
            currentScreen = 0x1110;
            break;
          case IC_74LS04:
            currentScreen = 0x1210;
            break;
          case IC_74LS32:
            currentScreen = 0x1310;
            break;
          case IC_74LS00:
            currentScreen = 0x1410;
            break;
          case IC_74LS02:
            currentScreen = 0x1510;
            break;
          case IC_74LS86:
            currentScreen = 0x1610;
            break;
          case IC_74LS47:
            currentScreen = 0x1810;
            break;
          case IC_74LS48:
            currentScreen = 0x1910;
            break;
          default:
            currentScreen = 0x0000;
            break;
        }
    }
    disp_ICDetails_exit();
  }
}

void disp_ICDetails_exit() {
  disp_ICDetails_init = false;
  btn_pressed = 0;
}

void disp_ICDetails_INIT() {
  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[2]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  switch (IC_tested) {
    case IC_74LS08:
      //74LS08-AND
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS08 IC Details");
      ICDetails_74LS08();
      break;
    case IC_74LS04:
      //74LS04-NOT
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS04 IC Details");
      ICDetails_74LS04();
      break;
    case IC_74LS32:
      //74LS32-OR
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS32 IC Details");
      ICDetails_74LS32();
      break;
    case IC_74LS00:
      //74LS00-NAND
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS00 IC Details");
      ICDetails_74LS00();
      break;
    case IC_74LS02:
      //74LS02-NOR
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS02 IC Details");
      ICDetails_74LS02();
      break;
    case IC_74LS86:
      //74LS86-XOR
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS86 IC Details");
      ICDetails_74LS86();
      break;
    case IC_74LS47:
      //74LS47- BCD to 7Segement Decoder Common Anode
      display_TitleBar("Integrared Circuit TESTER", "IC: 74LS47 IC Details");
      ICDetails_74LS47();
      break;
    case IC_74LS48:
      //74LS48- BCD to 7Segment Decoder Common Cathode
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS48 IC Details");
      ICDetails_74LS48();
      break;
    case IC_74LS83:
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS83 IC Details");
      ICDetails_74LS83();
      break;
  }


  disp_ICDetails_init = true;
}

void ICDetails_74LS08() {
  //show_string("The 74LS08 is a quad 2-input AND gate\nintegrated circuit. It has four separate AND\ngates that perform logical AND operations on\ntwo binary inputs, producing a binary output \nbased on the inputs' logical states.", 0, 150, 3, WHITE, WHITE, 0);
  File bmp_file;
  bmp_file = SD.open("ICDand.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS04() {
  //show_string("The 74LS04 is a hex inverter integrated\ncircuit. It contains six individual\ninverters, each taking a single input\nsignal and producing the logical\ncomplement of that signal as the\noutput.", 0, 150, 3, WHITE, WHITE, 0);
  File bmp_file;
  bmp_file = SD.open("ICDnot.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS32() {
  //show_string("The 74LS32 is a quad 2-input OR gate\nintegrated circuit. It contains four\nindependent OR gates, each with two input\npins.", 0, 150, 3, WHITE, WHITE, 0);
  File bmp_file;
  bmp_file = SD.open("ICDor.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS00() {
  //show_string("The 74LS00 is a quad 2-input NAND gate\nintegrated circuit. It contains four\nseparate NAND gates, each with two input\npins.", 0, 150, 3, WHITE, WHITE, 0);
  File bmp_file;
  bmp_file = SD.open("ICDnand.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS02() {
  //show_string("The 74LS02 is a quad 2-input NOR gate\nintegrated circuit. It includes four\nindependent NOR gates, each with two\ninput pins. ", 0, 150, 3, WHITE, WHITE, 0);
  File bmp_file;
  bmp_file = SD.open("ICDnor.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS86() {
  //show_string("The 74LS86 is a quad 2-input XOR gate\nintegrated circuit. It features four\nseparate XOR gates, each with two\ninput pins.", 0, 150, 3, WHITE, WHITE, 0);
  File bmp_file;
  bmp_file = SD.open("ICDxor.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS83() {
  //ADDER
  File bmp_file;
  bmp_file = SD.open("ICDadder.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS47() {
  //BCD CA
  File bmp_file;
  bmp_file = SD.open("ICDbcdA.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}

void ICDetails_74LS48() {
  //BCD CC
  File bmp_file;
  bmp_file = SD.open("ICDbcdC.bmp");
  draw_bmp_picture(bmp_file, 100, 150);
  bmp_file.close();
}