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
          case IC_74LS32:
            currentScreen = 0x1310;
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
    case IC_74LS32:
      //74LS32-OR
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS32 IC Details");
      ICDetails_74LS32();
      break;
  }


  disp_ICDetails_init = true;
}

void ICDetails_74LS08() {
  show_string("The 74LS08 is a quad 2-input AND gate\nintegrated circuit. It has four separate AND\ngates that perform logical AND operations on\ntwo binary inputs, producing a binary output \nbased on the inputs' logical states. This IC\nis commonly used in digital logic circuits \nfor tasks like signal processing and\ndecoding.", 0, 150, 3, WHITE, WHITE, 0);
}

void ICDetails_74LS32() {
  show_string("The 74LS32 is a quad 2-input OR gate\nintegrated circuit. It contains four\nindependent OR gates, each with two input\npins. These gates perform logical OR\noperations on binary inputs, resulting\nin a binary output based on the logical\nstates of the inputs. The 74LS32 is\ncommonly utilized in digital logic circuits\nfor tasks such as combining or \nselecting signals.", 0, 150, 3, WHITE, WHITE, 0);
}