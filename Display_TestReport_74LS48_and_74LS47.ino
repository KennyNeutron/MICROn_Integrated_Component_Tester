//Screen: TEST Report for 74LS47 and 74LS48
//Screen ID: 0x1115

bool disp_TestReport_74LS47_74LS48_init = false;


void disp_TestReport_74LS47_74LS48() {
  if (!disp_TestReport_74LS47_74LS48_init) {
    disp_TestReport_74LS47_74LS48_INIT();
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
        break;
    }
    disp_TestReport_74LS47_74LS48_exit();
  }
}

void disp_TestReport_74LS47_74LS48_exit() {
  btn_pressed = 0;
  disp_TestReport_74LS47_74LS48_init = false;
}


void disp_TestReport_74LS47_74LS48_INIT() {
  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[2]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();


  if (IC_tested == IC_74LS47) {
    display_TitleBar("Integrated Circuit TESTER", "IC- 74LS47 Test Report");
  } else {
    display_TitleBar("Integrated Circuit TESTER", "IC- 74LS48 Test Report");
  }


  disp_DrawTableBCD(50, 150, WHITE, RED, MAROON, BCD_7Segment_Out[0], BCD_7Segment_Out[1], BCD_7Segment_Out[2], BCD_7Segment_Out[3], BCD_7Segment_Out[4], BCD_7Segment_Out[5], BCD_7Segment_Out[6], BCD_7Segment_Out[7], BCD_7Segment_Out[8], BCD_7Segment_Out[9]);

  disp_TestReport_74LS47_74LS48_init = true;

  bmp_file = SD.open(file_name[15]);
  draw_bmp_picture(bmp_file, 550, 150);
  bmp_file.close();
}

void disp_DrawTableBCD(uint16_t csrX, uint16_t csrY, uint16_t fontColor, uint16_t bgColor, uint16_t lineColor, uint8_t OData0, uint8_t OData1, uint8_t OData2, uint8_t OData3, uint8_t OData4, uint8_t OData5, uint8_t OData6, uint8_t OData7, uint8_t OData8, uint8_t OData9) {
  tft.Set_Draw_color(bgColor);
  tft.Fill_Rectangle(csrX, csrY, csrX + 470, csrY + 240);

  tft.Set_Draw_color(lineColor);  //Line Color

  tft.Draw_Line(csrX, csrY, csrX + 470, csrY);                  //H1
  tft.Draw_Line(csrX + 200, csrY + 20, csrX + 470, csrY + 20);  //H2
  tft.Draw_Line(csrX, csrY + 40, csrX + 470, csrY + 40);        //H3
  tft.Draw_Line(csrX, csrY + 60, csrX + 470, csrY + 60);        //H4
  tft.Draw_Line(csrX, csrY + 80, csrX + 470, csrY + 80);        //H5
  tft.Draw_Line(csrX, csrY + 100, csrX + 470, csrY + 100);      //H6
  tft.Draw_Line(csrX, csrY + 120, csrX + 470, csrY + 120);      //H7
  tft.Draw_Line(csrX, csrY + 140, csrX + 470, csrY + 140);      //H8
  tft.Draw_Line(csrX, csrY + 160, csrX + 470, csrY + 160);      //H9
  tft.Draw_Line(csrX, csrY + 180, csrX + 470, csrY + 180);      //H10
  tft.Draw_Line(csrX, csrY + 200, csrX + 470, csrY + 200);      //H11
  tft.Draw_Line(csrX, csrY + 220, csrX + 470, csrY + 220);      //H12
  tft.Draw_Line(csrX, csrY + 240, csrX + 470, csrY + 240);      //H13


  show_string(" INPUT ", csrX + 5, csrY + 13, 2, fontColor, bgColor, 0);

  show_string(" 0000 ", csrX + 5, csrY + 43, 2, fontColor, bgColor, 0);   //0x00
  show_string(" 0001 ", csrX + 5, csrY + 63, 2, fontColor, bgColor, 0);   //0x01
  show_string(" 0010 ", csrX + 5, csrY + 83, 2, fontColor, bgColor, 0);   //0x02
  show_string(" 0011 ", csrX + 5, csrY + 103, 2, fontColor, bgColor, 0);  //0x03
  show_string(" 0100 ", csrX + 5, csrY + 123, 2, fontColor, bgColor, 0);  //0x04
  show_string(" 0101 ", csrX + 5, csrY + 143, 2, fontColor, bgColor, 0);  //0x05
  show_string(" 0110 ", csrX + 5, csrY + 163, 2, fontColor, bgColor, 0);  //0x06
  show_string(" 0111 ", csrX + 5, csrY + 183, 2, fontColor, bgColor, 0);  //0x07
  show_string(" 1000 ", csrX + 5, csrY + 203, 2, fontColor, bgColor, 0);  //0x08
  show_string(" 1001 ", csrX + 5, csrY + 223, 2, fontColor, bgColor, 0);  //0x09

  show_string(" FUNCT ", csrX + 105, csrY + 13, 2, fontColor, bgColor, 0);
  show_string(" OUTPUT ", csrX + 290, csrY + 3, 2, fontColor, bgColor, 0);

  show_string(" 0 ", csrX + 125, csrY + 43, 2, fontColor, bgColor, 0);
  show_string(" 1 ", csrX + 125, csrY + 63, 2, fontColor, bgColor, 0);
  show_string(" 2 ", csrX + 125, csrY + 83, 2, fontColor, bgColor, 0);
  show_string(" 3 ", csrX + 125, csrY + 103, 2, fontColor, bgColor, 0);
  show_string(" 4 ", csrX + 125, csrY + 123, 2, fontColor, bgColor, 0);
  show_string(" 5 ", csrX + 125, csrY + 143, 2, fontColor, bgColor, 0);
  show_string(" 6 ", csrX + 125, csrY + 163, 2, fontColor, bgColor, 0);
  show_string(" 7 ", csrX + 125, csrY + 183, 2, fontColor, bgColor, 0);
  show_string(" 8 ", csrX + 125, csrY + 203, 2, fontColor, bgColor, 0);
  show_string(" 9 ", csrX + 125, csrY + 223, 2, fontColor, bgColor, 0);

  tft.Draw_Line(csrX, csrY, csrX, csrY + 240);              //V1
  tft.Draw_Line(csrX + 100, csrY, csrX + 100, csrY + 240);  //V2
  tft.Draw_Line(csrX + 200, csrY, csrX + 200, csrY + 240);  //V3

  tft.Draw_Line(csrX + 230, csrY + 20, csrX + 230, csrY + 240);  //V4
  tft.Draw_Line(csrX + 260, csrY + 20, csrX + 260, csrY + 240);  //V5
  tft.Draw_Line(csrX + 290, csrY + 20, csrX + 290, csrY + 240);  //V6
  tft.Draw_Line(csrX + 320, csrY + 20, csrX + 320, csrY + 240);  //V7
  tft.Draw_Line(csrX + 350, csrY + 20, csrX + 350, csrY + 240);  //V8
  tft.Draw_Line(csrX + 380, csrY + 20, csrX + 380, csrY + 240);  //V9
  tft.Draw_Line(csrX + 410, csrY + 20, csrX + 410, csrY + 240);  //V10
  tft.Draw_Line(csrX + 470, csrY, csrX + 470, csrY + 240);       //V11

  show_string("a", csrX + 210, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("b", csrX + 240, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("c", csrX + 270, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("d", csrX + 300, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("e", csrX + 330, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("f", csrX + 360, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("g", csrX + 390, csrY + 23, 2, fontColor, bgColor, 0);

  show_string("DEC", csrX + 420, csrY + 23, 2, fontColor, bgColor, 0);
  show_string(String(OData0), csrX + 420, csrY + 43, 2, fontColor, bgColor, 0);   //OUTPUT DATA 0x00
  show_string(String(OData1), csrX + 420, csrY + 63, 2, fontColor, bgColor, 0);   //OUTPUT DATA 0x01
  show_string(String(OData2), csrX + 420, csrY + 83, 2, fontColor, bgColor, 0);   //OUTPUT DATA 0x02
  show_string(String(OData3), csrX + 420, csrY + 103, 2, fontColor, bgColor, 0);  //OUTPUT DATA 0x03
  show_string(String(OData4), csrX + 420, csrY + 123, 2, fontColor, bgColor, 0);  //OUTPUT DATA 0x04
  show_string(String(OData5), csrX + 420, csrY + 143, 2, fontColor, bgColor, 0);  //OUTPUT DATA 0x05
  show_string(String(OData6), csrX + 420, csrY + 163, 2, fontColor, bgColor, 0);  //OUTPUT DATA 0x06
  show_string(String(OData7), csrX + 420, csrY + 183, 2, fontColor, bgColor, 0);  //OUTPUT DATA 0x07
  show_string(String(OData8), csrX + 420, csrY + 203, 2, fontColor, bgColor, 0);  //OUTPUT DATA 0x08
  show_string(String(OData9), csrX + 420, csrY + 223, 2, fontColor, bgColor, 0);  //OUTPUT DATA 0x09


  //BINARY 0x00
  show_string(String(bitRead(OData0, 6)), csrX + 210, csrY + 43, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData0, 5)), csrX + 240, csrY + 43, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData0, 4)), csrX + 270, csrY + 43, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData0, 3)), csrX + 300, csrY + 43, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData0, 2)), csrX + 330, csrY + 43, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData0, 1)), csrX + 360, csrY + 43, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData0, 0)), csrX + 390, csrY + 43, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x01
  show_string(String(bitRead(OData1, 6)), csrX + 210, csrY + 63, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData1, 5)), csrX + 240, csrY + 63, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData1, 4)), csrX + 270, csrY + 63, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData1, 3)), csrX + 300, csrY + 63, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData1, 2)), csrX + 330, csrY + 63, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData1, 1)), csrX + 360, csrY + 63, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData1, 0)), csrX + 390, csrY + 63, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x02
  show_string(String(bitRead(OData2, 6)), csrX + 210, csrY + 83, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData2, 5)), csrX + 240, csrY + 83, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData2, 4)), csrX + 270, csrY + 83, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData2, 3)), csrX + 300, csrY + 83, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData2, 2)), csrX + 330, csrY + 83, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData2, 1)), csrX + 360, csrY + 83, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData2, 0)), csrX + 390, csrY + 83, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x03
  show_string(String(bitRead(OData3, 6)), csrX + 210, csrY + 103, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData3, 5)), csrX + 240, csrY + 103, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData3, 4)), csrX + 270, csrY + 103, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData3, 3)), csrX + 300, csrY + 103, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData3, 2)), csrX + 330, csrY + 103, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData3, 1)), csrX + 360, csrY + 103, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData3, 0)), csrX + 390, csrY + 103, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x04
  show_string(String(bitRead(OData4, 6)), csrX + 210, csrY + 123, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData4, 5)), csrX + 240, csrY + 123, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData4, 4)), csrX + 270, csrY + 123, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData4, 3)), csrX + 300, csrY + 123, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData4, 2)), csrX + 330, csrY + 123, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData4, 1)), csrX + 360, csrY + 123, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData4, 0)), csrX + 390, csrY + 123, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x05
  show_string(String(bitRead(OData5, 6)), csrX + 210, csrY + 143, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData5, 5)), csrX + 240, csrY + 143, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData5, 4)), csrX + 270, csrY + 143, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData5, 3)), csrX + 300, csrY + 143, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData5, 2)), csrX + 330, csrY + 143, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData5, 1)), csrX + 360, csrY + 143, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData5, 0)), csrX + 390, csrY + 143, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x06
  show_string(String(bitRead(OData6, 6)), csrX + 210, csrY + 163, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData6, 5)), csrX + 240, csrY + 163, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData6, 4)), csrX + 270, csrY + 163, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData6, 3)), csrX + 300, csrY + 163, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData6, 2)), csrX + 330, csrY + 163, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData6, 1)), csrX + 360, csrY + 163, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData6, 0)), csrX + 390, csrY + 163, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x07
  show_string(String(bitRead(OData7, 6)), csrX + 210, csrY + 183, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData7, 5)), csrX + 240, csrY + 183, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData7, 4)), csrX + 270, csrY + 183, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData7, 3)), csrX + 300, csrY + 183, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData7, 2)), csrX + 330, csrY + 183, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData7, 1)), csrX + 360, csrY + 183, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData7, 0)), csrX + 390, csrY + 183, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x08
  show_string(String(bitRead(OData8, 6)), csrX + 210, csrY + 203, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData8, 5)), csrX + 240, csrY + 203, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData8, 4)), csrX + 270, csrY + 203, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData8, 3)), csrX + 300, csrY + 203, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData8, 2)), csrX + 330, csrY + 203, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData8, 1)), csrX + 360, csrY + 203, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData8, 0)), csrX + 390, csrY + 203, 2, fontColor, bgColor, 0);  //Segment G

  //BINARY 0x09
  show_string(String(bitRead(OData9, 6)), csrX + 210, csrY + 223, 2, fontColor, bgColor, 0);  //Segment A
  show_string(String(bitRead(OData9, 5)), csrX + 240, csrY + 223, 2, fontColor, bgColor, 0);  //Segment B
  show_string(String(bitRead(OData9, 4)), csrX + 270, csrY + 223, 2, fontColor, bgColor, 0);  //Segment C
  show_string(String(bitRead(OData9, 3)), csrX + 300, csrY + 223, 2, fontColor, bgColor, 0);  //Segment D
  show_string(String(bitRead(OData9, 2)), csrX + 330, csrY + 223, 2, fontColor, bgColor, 0);  //Segment E
  show_string(String(bitRead(OData9, 1)), csrX + 360, csrY + 223, 2, fontColor, bgColor, 0);  //Segment F
  show_string(String(bitRead(OData9, 0)), csrX + 390, csrY + 223, 2, fontColor, bgColor, 0);  //Segment G
}