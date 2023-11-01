//Screen: TEST Report
//Screen ID: 0x1114

bool disp_TestReport_init = false;

void disp_TestReport() {
  if (!disp_TestReport_init) {
    disp_TestReport_INIT();
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
          default:
            currentScreen = 0x0000;
            break;
        }
        break;
    }
    disp_TestReport_exit();
  }
}

void disp_TestReport_exit() {
  btn_pressed = 0;
  disp_TestReport_init = false;
}

void disp_TestReport_INIT() {
  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[2]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  display_TitleBar("Integrated Circuit TESTER", "IC- Test Report");

  if (IC_tested == IC_74LS04) {
    disp_DrawTableNG(275, 150, RED, GREEN, BLUE, 1, get_NG1_Result0(), get_NG1_Result1());
    disp_DrawTableNG(275, 250, RED, GREEN, BLUE, 2, get_NG2_Result0(), get_NG2_Result1());
    disp_DrawTableNG(275, 350, RED, GREEN, BLUE, 3, get_NG3_Result0(), get_NG3_Result1());

    disp_DrawTableNG(425, 150, RED, GREEN, BLUE, 4, get_NG1_Result0(), get_NG4_Result1());
    disp_DrawTableNG(425, 250, RED, GREEN, BLUE, 5, get_NG2_Result0(), get_NG5_Result1());
    disp_DrawTableNG(425, 350, RED, GREEN, BLUE, 6, get_NG3_Result0(), get_NG6_Result1());
  } else {
    disp_DrawTable(230, 140, WHITE, BLUE, WHITE, 1, get_LG1_Result00(), get_LG1_Result01(), get_LG1_Result10(), get_LG1_Result11());

    disp_DrawTable(420, 140, WHITE, BLUE, WHITE, 2, get_LG2_Result00(), get_LG2_Result01(), get_LG2_Result10(), get_LG2_Result11());

    disp_DrawTable(230, 300, WHITE, BLUE, WHITE, 3, get_LG3_Result00(), get_LG3_Result01(), get_LG3_Result10(), get_LG3_Result11());

    disp_DrawTable(420, 300, WHITE, BLUE, WHITE, 4, get_LG4_Result00(), get_LG4_Result01(), get_LG4_Result10(), get_LG4_Result11());
  }


  disp_TestReport_init = true;
}

void disp_DrawTable(uint16_t csrX, uint16_t csrY, uint16_t fontColor, uint16_t bgColor, uint16_t lineColor, uint8_t numLG, bool R00, bool R01, bool R10, bool R11) {
  tft.Set_Draw_color(bgColor);
  tft.Fill_Rectangle(csrX, csrY, csrX + 150, csrY + 120);

  show_string("Logic Gate " + String(numLG), csrX + 5, csrY + 3, 2, fontColor, bgColor, 0);
  show_string("IN1", csrX + 2, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("IN2", csrX + 52, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("OUT", csrX + 102, csrY + 23, 2, fontColor, bgColor, 0);

  //LG-00
  show_string("0", csrX + 10, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("0", csrX + 60, csrY + 43, 2, fontColor, bgColor, 0);
  show_string(String(R00), csrX + 110, csrY + 43, 2, fontColor, bgColor, 0);

  //LG-01
  show_string("0", csrX + 10, csrY + 63, 2, fontColor, bgColor, 0);
  show_string("1", csrX + 60, csrY + 63, 2, fontColor, bgColor, 0);
  show_string(String(R01), csrX + 110, csrY + 63, 2, fontColor, bgColor, 0);

  //LG-10
  show_string("1", csrX + 10, csrY + 83, 2, fontColor, bgColor, 0);
  show_string("0", csrX + 60, csrY + 83, 2, fontColor, bgColor, 0);
  show_string(String(R10), csrX + 110, csrY + 83, 2, fontColor, bgColor, 0);

  //LG-11
  show_string("1", csrX + 10, csrY + 103, 2, fontColor, bgColor, 0);
  show_string("1", csrX + 60, csrY + 103, 2, fontColor, bgColor, 0);
  show_string(String(R11), csrX + 110, csrY + 103, 2, fontColor, bgColor, 0);


  tft.Set_Draw_color(lineColor);
  tft.Draw_Line(csrX, csrY, csrX + 150, csrY);              //H
  tft.Draw_Line(csrX, csrY + 20, csrX + 150, csrY + 20);    //H
  tft.Draw_Line(csrX, csrY + 40, csrX + 150, csrY + 40);    //H
  tft.Draw_Line(csrX, csrY + 60, csrX + 150, csrY + 60);    //H
  tft.Draw_Line(csrX, csrY + 80, csrX + 150, csrY + 80);    //H
  tft.Draw_Line(csrX, csrY + 100, csrX + 150, csrY + 100);  //H
  tft.Draw_Line(csrX, csrY + 120, csrX + 150, csrY + 120);  //H

  tft.Draw_Line(csrX, csrY, csrX, csrY + 120);                   //V
  tft.Draw_Line(csrX + 50, csrY + 20, csrX + 50, csrY + 120);    //V
  tft.Draw_Line(csrX + 100, csrY + 20, csrX + 100, csrY + 120);  //V
  tft.Draw_Line(csrX + 150, csrY, csrX + 150, csrY + 120);       //V
}


void disp_DrawTableNG(uint16_t csrX, uint16_t csrY, uint16_t fontColor, uint16_t bgColor, uint16_t lineColor, uint8_t numNG, bool R0, bool R1) {
  tft.Set_Draw_color(bgColor);
  tft.Fill_Rectangle(csrX, csrY, csrX + 100, csrY + 80);

  tft.Set_Draw_color(lineColor);
  tft.Draw_Line(csrX, csrY, csrX + 100, csrY);            //H
  tft.Draw_Line(csrX, csrY + 20, csrX + 100, csrY + 20);  //H
  tft.Draw_Line(csrX, csrY + 40, csrX + 100, csrY + 40);  //H
  tft.Draw_Line(csrX, csrY + 60, csrX + 100, csrY + 60);  //H
  tft.Draw_Line(csrX, csrY + 80, csrX + 100, csrY + 80);  //H

  tft.Draw_Line(csrX, csrY, csrX, csrY + 80);              //V
  tft.Draw_Line(csrX + 100, csrY, csrX + 100, csrY + 80);  //V

  tft.Draw_Line(csrX + 50, csrY + 20, csrX + 50, csrY + 80);  //V

  show_string(" GATE " + String(numNG), csrX + 5, csrY + 3, 2, fontColor, bgColor, 0);
  show_string("IN", csrX + 5, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("OUT", csrX + 55, csrY + 23, 2, fontColor, bgColor, 0);
  show_string(" 0", csrX + 5, csrY + 43, 2, fontColor, bgColor, 0);
  show_string(" 1", csrX + 5, csrY + 63, 2, fontColor, bgColor, 0);

  show_string(" " + String(R0), csrX + 55, csrY + 43, 2, fontColor, bgColor, 0);
  show_string(" " + String(R1), csrX + 55, csrY + 63, 2, fontColor, bgColor, 0);
}