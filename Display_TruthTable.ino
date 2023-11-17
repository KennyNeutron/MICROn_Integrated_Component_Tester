//Screen: Truth Table
//Screen ID: 0x1111

bool disp_TruthTable_init = false;

void disp_TruthTable() {
  if (!disp_TruthTable_init) {
    disp_TruthTable_INIT();
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
    disp_TruthTable_exit();
  }
}


void disp_TruthTable_exit() {
  disp_TruthTable_init = false;
  btn_pressed = 0;
}


void disp_TruthTable_INIT() {
  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[2]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  switch (IC_tested) {
    case IC_74LS08:
      //74LS08-AND
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS08 TRUTH TABLE");
      disp_DrawTruthTable(320, 150, WHITE, BLUE, WHITE, "AND gate", 0, 0, 0, 1);
      break;
    case IC_74LS04:
      //74LS04-NOT
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS04 TRUTH TABLE");
      disp_DrawTableNG(350, 200, RED, GREEN, BLUE, 0, 1, 0);
      break;
    case IC_74LS32:
      //74LS32-OR
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS32 TRUTH TABLE");
      disp_DrawTruthTable(320, 150, WHITE, BLUE, WHITE, "OR gate", 0, 1, 1, 1);
      break;
    case IC_74LS00:
      //74LS00-NAND
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS00 TRUTH TABLE");
      disp_DrawTruthTable(320, 150, WHITE, BLUE, WHITE, "NAND gate", 1, 1, 1, 0);
      break;
    case IC_74LS02:
      //74LS02-NOR
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS02 TRUTH TABLE");
      disp_DrawTruthTable(320, 150, WHITE, BLUE, WHITE, "NOR gate", 1, 0, 0, 0);
      break;
    case IC_74LS86:
      //74LS86-XOR
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS86 TRUTH TABLE");
      disp_DrawTruthTable(320, 150, WHITE, BLUE, WHITE, "XOR gate", 0, 1, 1, 0);
      break;
    case IC_74LS47:
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS47 TRUTH TABLE");
      disp_DrawTableBCD(180, 150, WHITE, RED, MAROON, 1, 79, 18, 6, 76, 36, 96, 15, 0, 12);
      break;
    case IC_74LS48:
      //74LS48- BCD Common Cathode
      display_TitleBar("Integrated Circuit TESTER", "IC: 74LS48 TRUTH TABLE");
      disp_DrawTableBCD(180, 150, WHITE, RED, MAROON, 126, 48, 109, 121, 51, 91, 31, 112, 127, 115);
      break;
  }


  disp_TruthTable_init = true;
}





void disp_DrawTruthTable(uint16_t csrX, uint16_t csrY, uint16_t fontColor, uint16_t bgColor, uint16_t lineColor, String nameLG, bool R00, bool R01, bool R10, bool R11) {
  tft.Set_Draw_color(bgColor);
  tft.Fill_Rectangle(csrX, csrY, csrX + 150, csrY + 120);

  show_string(nameLG, csrX + 5, csrY + 3, 2, fontColor, bgColor, 0);
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