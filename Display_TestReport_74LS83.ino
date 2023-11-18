//Screen: Test Report for 74LS83
//Screen ID: 0x1116

bool disp_TestReport_74LS83_init = false;

void disp_TestReport_74LS83() {
  if (!disp_TestReport_74LS83_init) {
    disp_TestReport_74LS83_INIT();
  }
}



void disp_TestReport_74LS83_INIT() {
  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[2]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  show_string("Integrated Circuit TESTER", CENTER, 15, 4, WHITE, WHITE, 0);
  show_string("IC- 74LS83 Test Report", CENTER, 65, 3, WHITE, WHITE, 0);
  tft.Set_Draw_color(RED);
  tft.Draw_Line(50, 55, 750, 55);


  dispDrawTable_BinaryAdder(10, 95, WHITE, BLUE, WHITE, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);

  disp_TestReport_74LS83_init = true;
}



void dispDrawTable_BinaryAdder(uint16_t csrX, uint16_t csrY, uint16_t fontColor, uint16_t bgColor, uint16_t lineColor, uint8_t Sum0, uint8_t Sum1, uint8_t Sum2, uint8_t Sum3, uint8_t Sum4, uint8_t Sum5, uint8_t Sum6, uint8_t Sum7, uint8_t Sum8, uint8_t Sum9, uint8_t SumA, uint8_t SumB, uint8_t SumC, uint8_t SumD, uint8_t SumE, uint8_t SumF) {
  tft.Set_Draw_color(bgColor);  //BG Color

  tft.Set_Draw_color(lineColor);  //Line Color

  tft.Draw_Line(csrX, csrY, csrX + 500, csrY);              //H1
  tft.Draw_Line(csrX, csrY + 20, csrX + 500, csrY + 20);    //H2
  tft.Draw_Line(csrX, csrY + 40, csrX + 500, csrY + 40);    //H3
  tft.Draw_Line(csrX, csrY + 60, csrX + 500, csrY + 60);    //H4
  tft.Draw_Line(csrX, csrY + 80, csrX + 500, csrY + 80);    //H5
  tft.Draw_Line(csrX, csrY + 100, csrX + 500, csrY + 100);  //H6
  tft.Draw_Line(csrX, csrY + 120, csrX + 500, csrY + 120);  //H7
  tft.Draw_Line(csrX, csrY + 140, csrX + 500, csrY + 140);  //H8
  tft.Draw_Line(csrX, csrY + 160, csrX + 500, csrY + 160);  //H9
  tft.Draw_Line(csrX, csrY + 180, csrX + 500, csrY + 180);  //H10
  tft.Draw_Line(csrX, csrY + 200, csrX + 500, csrY + 200);  //H11
  tft.Draw_Line(csrX, csrY + 220, csrX + 500, csrY + 220);  //H12
  tft.Draw_Line(csrX, csrY + 240, csrX + 500, csrY + 240);  //H13
  tft.Draw_Line(csrX, csrY + 260, csrX + 500, csrY + 260);  //H14
  tft.Draw_Line(csrX, csrY + 280, csrX + 500, csrY + 280);  //H15
  tft.Draw_Line(csrX, csrY + 300, csrX + 500, csrY + 300);  //H16
  tft.Draw_Line(csrX, csrY + 320, csrX + 500, csrY + 320);  //H17
  tft.Draw_Line(csrX, csrY + 340, csrX + 500, csrY + 340);  //H18
  tft.Draw_Line(csrX, csrY + 360, csrX + 500, csrY + 360);  //H19
  tft.Draw_Line(csrX, csrY + 380, csrX + 500, csrY + 380);  //H20



  tft.Draw_Line(csrX, csrY, csrX, csrY + 380);                   //V1
  tft.Draw_Line(csrX + 30, csrY + 40, csrX + 30, csrY + 380);    //V2
  tft.Draw_Line(csrX + 60, csrY + 40, csrX + 60, csrY + 380);    //V3
  tft.Draw_Line(csrX + 90, csrY + 40, csrX + 90, csrY + 380);    //V4
  tft.Draw_Line(csrX + 120, csrY + 20, csrX + 120, csrY + 380);  //V5

  tft.Draw_Line(csrX + 150, csrY + 40, csrX + 150, csrY + 380);  //V6
  tft.Draw_Line(csrX + 180, csrY + 40, csrX + 180, csrY + 380);  //V7
  tft.Draw_Line(csrX + 210, csrY + 40, csrX + 210, csrY + 380);  //V8
  tft.Draw_Line(csrX + 240, csrY + 20, csrX + 240, csrY + 380);  //V9

  tft.Draw_Line(csrX + 270, csrY + 40, csrX + 270, csrY + 380);  //V10
  tft.Draw_Line(csrX + 300, csrY + 40, csrX + 300, csrY + 380);  //V11
  tft.Draw_Line(csrX + 330, csrY + 40, csrX + 330, csrY + 380);  //V12
  tft.Draw_Line(csrX + 360, csrY + 20, csrX + 360, csrY + 380);  //V13


  show_string(" BINARY ", csrX + 130, csrY + 3, 2, fontColor, bgColor, 0);
  show_string(" INPUT A", csrX + 5, csrY + 23, 2, fontColor, bgColor, 0);
  show_string(" INPUT B", csrX + 125, csrY + 23, 2, fontColor, bgColor, 0);
  show_string("   SUM   ", csrX + 245, csrY + 23, 2, fontColor, bgColor, 0);

  show_string("A4", csrX + 5, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("A3", csrX + 35, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("A2", csrX + 65, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("A1", csrX + 95, csrY + 43, 2, fontColor, bgColor, 0);

  show_string("B4", csrX + 125, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("B3", csrX + 155, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("B2", csrX + 185, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("B1", csrX + 215, csrY + 43, 2, fontColor, bgColor, 0);

  show_string("S4", csrX + 245, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("S3", csrX + 275, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("S2", csrX + 305, csrY + 43, 2, fontColor, bgColor, 0);
  show_string("S1", csrX + 335, csrY + 43, 2, fontColor, bgColor, 0);

  //INPUT A
  show_string(String(bitRead(0x00, 3)), csrX + 8, csrY + 63, 2, fontColor, bgColor, 0);   //0x00
  show_string(String(bitRead(0x00, 2)), csrX + 38, csrY + 63, 2, fontColor, bgColor, 0);  //0x00
  show_string(String(bitRead(0x00, 1)), csrX + 68, csrY + 63, 2, fontColor, bgColor, 0);  //0x00
  show_string(String(bitRead(0x00, 0)), csrX + 98, csrY + 63, 2, fontColor, bgColor, 0);  //0x00

  show_string(String(bitRead(0x01, 3)), csrX + 8, csrY + 83, 2, fontColor, bgColor, 0);   //0x01
  show_string(String(bitRead(0x01, 2)), csrX + 38, csrY + 83, 2, fontColor, bgColor, 0);  //0x01
  show_string(String(bitRead(0x01, 1)), csrX + 68, csrY + 83, 2, fontColor, bgColor, 0);  //0x01
  show_string(String(bitRead(0x01, 0)), csrX + 98, csrY + 83, 2, fontColor, bgColor, 0);  //0x01

  show_string(String(bitRead(0x02, 3)), csrX + 8, csrY + 103, 2, fontColor, bgColor, 0);   //0x02
  show_string(String(bitRead(0x02, 2)), csrX + 38, csrY + 103, 2, fontColor, bgColor, 0);  //0x02
  show_string(String(bitRead(0x02, 1)), csrX + 68, csrY + 103, 2, fontColor, bgColor, 0);  //0x02
  show_string(String(bitRead(0x02, 0)), csrX + 98, csrY + 103, 2, fontColor, bgColor, 0);  //0x02

  show_string(String(bitRead(0x03, 3)), csrX + 8, csrY + 123, 2, fontColor, bgColor, 0);   //0x03
  show_string(String(bitRead(0x03, 2)), csrX + 38, csrY + 123, 2, fontColor, bgColor, 0);  //0x03
  show_string(String(bitRead(0x03, 1)), csrX + 68, csrY + 123, 2, fontColor, bgColor, 0);  //0x03
  show_string(String(bitRead(0x03, 0)), csrX + 98, csrY + 123, 2, fontColor, bgColor, 0);  //0x03

  show_string(String(bitRead(0x04, 3)), csrX + 8, csrY + 143, 2, fontColor, bgColor, 0);   //0x04
  show_string(String(bitRead(0x04, 2)), csrX + 38, csrY + 143, 2, fontColor, bgColor, 0);  //0x04
  show_string(String(bitRead(0x04, 1)), csrX + 68, csrY + 143, 2, fontColor, bgColor, 0);  //0x04
  show_string(String(bitRead(0x04, 0)), csrX + 98, csrY + 143, 2, fontColor, bgColor, 0);  //0x04

  show_string(String(bitRead(0x05, 3)), csrX + 8, csrY + 163, 2, fontColor, bgColor, 0);   //0x05
  show_string(String(bitRead(0x05, 2)), csrX + 38, csrY + 163, 2, fontColor, bgColor, 0);  //0x05
  show_string(String(bitRead(0x05, 1)), csrX + 68, csrY + 163, 2, fontColor, bgColor, 0);  //0x05
  show_string(String(bitRead(0x05, 0)), csrX + 98, csrY + 163, 2, fontColor, bgColor, 0);  //0x05

  show_string(String(bitRead(0x06, 3)), csrX + 8, csrY + 183, 2, fontColor, bgColor, 0);   //0x06
  show_string(String(bitRead(0x06, 2)), csrX + 38, csrY + 183, 2, fontColor, bgColor, 0);  //0x06
  show_string(String(bitRead(0x06, 1)), csrX + 68, csrY + 183, 2, fontColor, bgColor, 0);  //0x06
  show_string(String(bitRead(0x06, 0)), csrX + 98, csrY + 183, 2, fontColor, bgColor, 0);  //0x06

  show_string(String(bitRead(0x07, 3)), csrX + 8, csrY + 203, 2, fontColor, bgColor, 0);   //0x07
  show_string(String(bitRead(0x07, 2)), csrX + 38, csrY + 203, 2, fontColor, bgColor, 0);  //0x07
  show_string(String(bitRead(0x07, 1)), csrX + 68, csrY + 203, 2, fontColor, bgColor, 0);  //0x07
  show_string(String(bitRead(0x07, 0)), csrX + 98, csrY + 203, 2, fontColor, bgColor, 0);  //0x07

  show_string(String(bitRead(0x08, 3)), csrX + 8, csrY + 223, 2, fontColor, bgColor, 0);   //0x08
  show_string(String(bitRead(0x08, 2)), csrX + 38, csrY + 223, 2, fontColor, bgColor, 0);  //0x08
  show_string(String(bitRead(0x08, 1)), csrX + 68, csrY + 223, 2, fontColor, bgColor, 0);  //0x08
  show_string(String(bitRead(0x08, 0)), csrX + 98, csrY + 223, 2, fontColor, bgColor, 0);  //0x08

  show_string(String(bitRead(0x09, 3)), csrX + 8, csrY + 243, 2, fontColor, bgColor, 0);   //0x09
  show_string(String(bitRead(0x09, 2)), csrX + 38, csrY + 243, 2, fontColor, bgColor, 0);  //0x09
  show_string(String(bitRead(0x09, 1)), csrX + 68, csrY + 243, 2, fontColor, bgColor, 0);  //0x09
  show_string(String(bitRead(0x09, 0)), csrX + 98, csrY + 243, 2, fontColor, bgColor, 0);  //0x09

  show_string(String(bitRead(0x0A, 3)), csrX + 8, csrY + 263, 2, fontColor, bgColor, 0);   //0x0A
  show_string(String(bitRead(0x0A, 2)), csrX + 38, csrY + 263, 2, fontColor, bgColor, 0);  //0x0A
  show_string(String(bitRead(0x0A, 1)), csrX + 68, csrY + 263, 2, fontColor, bgColor, 0);  //0x0A
  show_string(String(bitRead(0x0A, 0)), csrX + 98, csrY + 263, 2, fontColor, bgColor, 0);  //0x0A

  show_string(String(bitRead(0x0B, 3)), csrX + 8, csrY + 283, 2, fontColor, bgColor, 0);   //0x0B
  show_string(String(bitRead(0x0B, 2)), csrX + 38, csrY + 283, 2, fontColor, bgColor, 0);  //0x0B
  show_string(String(bitRead(0x0B, 1)), csrX + 68, csrY + 283, 2, fontColor, bgColor, 0);  //0x0B
  show_string(String(bitRead(0x0B, 0)), csrX + 98, csrY + 283, 2, fontColor, bgColor, 0);  //0x0B

  show_string(String(bitRead(0x0C, 3)), csrX + 8, csrY + 303, 2, fontColor, bgColor, 0);   //0x0C
  show_string(String(bitRead(0x0C, 2)), csrX + 38, csrY + 303, 2, fontColor, bgColor, 0);  //0x0C
  show_string(String(bitRead(0x0C, 1)), csrX + 68, csrY + 303, 2, fontColor, bgColor, 0);  //0x0C
  show_string(String(bitRead(0x0C, 0)), csrX + 98, csrY + 303, 2, fontColor, bgColor, 0);  //0x0C

  show_string(String(bitRead(0x0D, 3)), csrX + 8, csrY + 323, 2, fontColor, bgColor, 0);   //0x0D
  show_string(String(bitRead(0x0D, 2)), csrX + 38, csrY + 323, 2, fontColor, bgColor, 0);  //0x0D
  show_string(String(bitRead(0x0D, 1)), csrX + 68, csrY + 323, 2, fontColor, bgColor, 0);  //0x0D
  show_string(String(bitRead(0x0D, 0)), csrX + 98, csrY + 323, 2, fontColor, bgColor, 0);  //0x0D

  show_string(String(bitRead(0x0E, 3)), csrX + 8, csrY + 343, 2, fontColor, bgColor, 0);   //0x0E
  show_string(String(bitRead(0x0E, 2)), csrX + 38, csrY + 343, 2, fontColor, bgColor, 0);  //0x0E
  show_string(String(bitRead(0x0E, 1)), csrX + 68, csrY + 343, 2, fontColor, bgColor, 0);  //0x0E
  show_string(String(bitRead(0x0E, 0)), csrX + 98, csrY + 343, 2, fontColor, bgColor, 0);  //0x0E

  show_string(String(bitRead(0x0F, 3)), csrX + 8, csrY + 363, 2, fontColor, bgColor, 0);   //0x0F
  show_string(String(bitRead(0x0F, 2)), csrX + 38, csrY + 363, 2, fontColor, bgColor, 0);  //0x0F
  show_string(String(bitRead(0x0F, 1)), csrX + 68, csrY + 363, 2, fontColor, bgColor, 0);  //0x0F
  show_string(String(bitRead(0x0F, 0)), csrX + 98, csrY + 363, 2, fontColor, bgColor, 0);  //0x0F

  //INPUT B
  show_string(String(bitRead(0x00, 3)), csrX + 128, csrY + 63, 2, fontColor, bgColor, 0);  //0x00
  show_string(String(bitRead(0x00, 2)), csrX + 158, csrY + 63, 2, fontColor, bgColor, 0);  //0x00
  show_string(String(bitRead(0x00, 1)), csrX + 188, csrY + 63, 2, fontColor, bgColor, 0);  //0x00
  show_string(String(bitRead(0x00, 0)), csrX + 218, csrY + 63, 2, fontColor, bgColor, 0);  //0x00

  show_string(String(bitRead(0x01, 3)), csrX + 128, csrY + 83, 2, fontColor, bgColor, 0);  //0x01
  show_string(String(bitRead(0x01, 2)), csrX + 158, csrY + 83, 2, fontColor, bgColor, 0);  //0x01
  show_string(String(bitRead(0x01, 1)), csrX + 188, csrY + 83, 2, fontColor, bgColor, 0);  //0x01
  show_string(String(bitRead(0x01, 0)), csrX + 218, csrY + 83, 2, fontColor, bgColor, 0);  //0x01

  show_string(String(bitRead(0x02, 3)), csrX + 128, csrY + 103, 2, fontColor, bgColor, 0);  //0x02
  show_string(String(bitRead(0x02, 2)), csrX + 158, csrY + 103, 2, fontColor, bgColor, 0);  //0x02
  show_string(String(bitRead(0x02, 1)), csrX + 188, csrY + 103, 2, fontColor, bgColor, 0);  //0x02
  show_string(String(bitRead(0x02, 0)), csrX + 218, csrY + 103, 2, fontColor, bgColor, 0);  //0x02

  show_string(String(bitRead(0x03, 3)), csrX + 128, csrY + 123, 2, fontColor, bgColor, 0);  //0x03
  show_string(String(bitRead(0x03, 2)), csrX + 158, csrY + 123, 2, fontColor, bgColor, 0);  //0x03
  show_string(String(bitRead(0x03, 1)), csrX + 188, csrY + 123, 2, fontColor, bgColor, 0);  //0x03
  show_string(String(bitRead(0x03, 0)), csrX + 218, csrY + 123, 2, fontColor, bgColor, 0);  //0x03

  show_string(String(bitRead(0x04, 3)), csrX + 128, csrY + 143, 2, fontColor, bgColor, 0);  //0x04
  show_string(String(bitRead(0x04, 2)), csrX + 158, csrY + 143, 2, fontColor, bgColor, 0);  //0x04
  show_string(String(bitRead(0x04, 1)), csrX + 188, csrY + 143, 2, fontColor, bgColor, 0);  //0x04
  show_string(String(bitRead(0x04, 0)), csrX + 218, csrY + 143, 2, fontColor, bgColor, 0);  //0x04

  show_string(String(bitRead(0x05, 3)), csrX + 128, csrY + 163, 2, fontColor, bgColor, 0);  //0x05
  show_string(String(bitRead(0x05, 2)), csrX + 158, csrY + 163, 2, fontColor, bgColor, 0);  //0x05
  show_string(String(bitRead(0x05, 1)), csrX + 188, csrY + 163, 2, fontColor, bgColor, 0);  //0x05
  show_string(String(bitRead(0x05, 0)), csrX + 218, csrY + 163, 2, fontColor, bgColor, 0);  //0x05

  show_string(String(bitRead(0x06, 3)), csrX + 128, csrY + 183, 2, fontColor, bgColor, 0);  //0x06
  show_string(String(bitRead(0x06, 2)), csrX + 158, csrY + 183, 2, fontColor, bgColor, 0);  //0x06
  show_string(String(bitRead(0x06, 1)), csrX + 188, csrY + 183, 2, fontColor, bgColor, 0);  //0x06
  show_string(String(bitRead(0x06, 0)), csrX + 218, csrY + 183, 2, fontColor, bgColor, 0);  //0x06

  show_string(String(bitRead(0x07, 3)), csrX + 128, csrY + 203, 2, fontColor, bgColor, 0);  //0x07
  show_string(String(bitRead(0x07, 2)), csrX + 158, csrY + 203, 2, fontColor, bgColor, 0);  //0x07
  show_string(String(bitRead(0x07, 1)), csrX + 188, csrY + 203, 2, fontColor, bgColor, 0);  //0x07
  show_string(String(bitRead(0x07, 0)), csrX + 218, csrY + 203, 2, fontColor, bgColor, 0);  //0x07

  show_string(String(bitRead(0x08, 3)), csrX + 128, csrY + 223, 2, fontColor, bgColor, 0);  //0x08
  show_string(String(bitRead(0x08, 2)), csrX + 158, csrY + 223, 2, fontColor, bgColor, 0);  //0x08
  show_string(String(bitRead(0x08, 1)), csrX + 188, csrY + 223, 2, fontColor, bgColor, 0);  //0x08
  show_string(String(bitRead(0x08, 0)), csrX + 218, csrY + 223, 2, fontColor, bgColor, 0);  //0x08

  show_string(String(bitRead(0x09, 3)), csrX + 128, csrY + 243, 2, fontColor, bgColor, 0);  //0x09
  show_string(String(bitRead(0x09, 2)), csrX + 158, csrY + 243, 2, fontColor, bgColor, 0);  //0x09
  show_string(String(bitRead(0x09, 1)), csrX + 188, csrY + 243, 2, fontColor, bgColor, 0);  //0x09
  show_string(String(bitRead(0x09, 0)), csrX + 218, csrY + 243, 2, fontColor, bgColor, 0);  //0x09

  show_string(String(bitRead(0x0A, 3)), csrX + 128, csrY + 263, 2, fontColor, bgColor, 0);  //0x0A
  show_string(String(bitRead(0x0A, 2)), csrX + 158, csrY + 263, 2, fontColor, bgColor, 0);  //0x0A
  show_string(String(bitRead(0x0A, 1)), csrX + 188, csrY + 263, 2, fontColor, bgColor, 0);  //0x0A
  show_string(String(bitRead(0x0A, 0)), csrX + 218, csrY + 263, 2, fontColor, bgColor, 0);  //0x0A

  show_string(String(bitRead(0x0B, 3)), csrX + 128, csrY + 283, 2, fontColor, bgColor, 0);  //0x0B
  show_string(String(bitRead(0x0B, 2)), csrX + 158, csrY + 283, 2, fontColor, bgColor, 0);  //0x0B
  show_string(String(bitRead(0x0B, 1)), csrX + 188, csrY + 283, 2, fontColor, bgColor, 0);  //0x0B
  show_string(String(bitRead(0x0B, 0)), csrX + 218, csrY + 283, 2, fontColor, bgColor, 0);  //0x0B

  show_string(String(bitRead(0x0C, 3)), csrX + 128, csrY + 303, 2, fontColor, bgColor, 0);  //0x0C
  show_string(String(bitRead(0x0C, 2)), csrX + 158, csrY + 303, 2, fontColor, bgColor, 0);  //0x0C
  show_string(String(bitRead(0x0C, 1)), csrX + 188, csrY + 303, 2, fontColor, bgColor, 0);  //0x0C
  show_string(String(bitRead(0x0C, 0)), csrX + 218, csrY + 303, 2, fontColor, bgColor, 0);  //0x0C

  show_string(String(bitRead(0x0D, 3)), csrX + 128, csrY + 323, 2, fontColor, bgColor, 0);  //0x0D
  show_string(String(bitRead(0x0D, 2)), csrX + 158, csrY + 323, 2, fontColor, bgColor, 0);  //0x0D
  show_string(String(bitRead(0x0D, 1)), csrX + 188, csrY + 323, 2, fontColor, bgColor, 0);  //0x0D
  show_string(String(bitRead(0x0D, 0)), csrX + 218, csrY + 323, 2, fontColor, bgColor, 0);  //0x0D

  show_string(String(bitRead(0x0E, 3)), csrX + 128, csrY + 343, 2, fontColor, bgColor, 0);  //0x0E
  show_string(String(bitRead(0x0E, 2)), csrX + 158, csrY + 343, 2, fontColor, bgColor, 0);  //0x0E
  show_string(String(bitRead(0x0E, 1)), csrX + 188, csrY + 343, 2, fontColor, bgColor, 0);  //0x0E
  show_string(String(bitRead(0x0E, 0)), csrX + 218, csrY + 343, 2, fontColor, bgColor, 0);  //0x0E

  show_string(String(bitRead(0x0F, 3)), csrX + 128, csrY + 363, 2, fontColor, bgColor, 0);  //0x0F
  show_string(String(bitRead(0x0F, 2)), csrX + 158, csrY + 363, 2, fontColor, bgColor, 0);  //0x0F
  show_string(String(bitRead(0x0F, 1)), csrX + 188, csrY + 363, 2, fontColor, bgColor, 0);  //0x0F
  show_string(String(bitRead(0x0F, 0)), csrX + 218, csrY + 363, 2, fontColor, bgColor, 0);  //0x0F

  //SUM
  show_string(String(bitRead(Sum0, 3)), csrX + 248, csrY + 63, 2, fontColor, bgColor, 0);  //Sum0
  show_string(String(bitRead(Sum0, 2)), csrX + 278, csrY + 63, 2, fontColor, bgColor, 0);  //Sum0
  show_string(String(bitRead(Sum0, 1)), csrX + 308, csrY + 63, 2, fontColor, bgColor, 0);  //Sum0
  show_string(String(bitRead(Sum0, 0)), csrX + 338, csrY + 63, 2, fontColor, bgColor, 0);  //Sum0

  show_string(String(bitRead(Sum1, 3)), csrX + 248, csrY + 83, 2, fontColor, bgColor, 0);  //Sum1
  show_string(String(bitRead(Sum1, 2)), csrX + 278, csrY + 83, 2, fontColor, bgColor, 0);  //Sum1
  show_string(String(bitRead(Sum1, 1)), csrX + 308, csrY + 83, 2, fontColor, bgColor, 0);  //Sum1
  show_string(String(bitRead(Sum1, 0)), csrX + 338, csrY + 83, 2, fontColor, bgColor, 0);  //Sum1

  show_string(String(bitRead(Sum2, 3)), csrX + 248, csrY + 103, 2, fontColor, bgColor, 0);  //Sum2
  show_string(String(bitRead(Sum2, 2)), csrX + 278, csrY + 103, 2, fontColor, bgColor, 0);  //Sum2
  show_string(String(bitRead(Sum2, 1)), csrX + 308, csrY + 103, 2, fontColor, bgColor, 0);  //Sum2
  show_string(String(bitRead(Sum2, 0)), csrX + 338, csrY + 103, 2, fontColor, bgColor, 0);  //Sum2

  show_string(String(bitRead(Sum3, 3)), csrX + 248, csrY + 123, 2, fontColor, bgColor, 0);  //Sum3
  show_string(String(bitRead(Sum3, 2)), csrX + 278, csrY + 123, 2, fontColor, bgColor, 0);  //Sum3
  show_string(String(bitRead(Sum3, 1)), csrX + 308, csrY + 123, 2, fontColor, bgColor, 0);  //Sum3
  show_string(String(bitRead(Sum3, 0)), csrX + 338, csrY + 123, 2, fontColor, bgColor, 0);  //Sum3

  show_string(String(bitRead(Sum4, 3)), csrX + 248, csrY + 143, 2, fontColor, bgColor, 0);  //Sum4
  show_string(String(bitRead(Sum4, 2)), csrX + 278, csrY + 143, 2, fontColor, bgColor, 0);  //Sum4
  show_string(String(bitRead(Sum4, 1)), csrX + 308, csrY + 143, 2, fontColor, bgColor, 0);  //Sum4
  show_string(String(bitRead(Sum4, 0)), csrX + 338, csrY + 143, 2, fontColor, bgColor, 0);  //Sum4

  show_string(String(bitRead(Sum5, 3)), csrX + 248, csrY + 163, 2, fontColor, bgColor, 0);  //Sum5
  show_string(String(bitRead(Sum5, 2)), csrX + 278, csrY + 163, 2, fontColor, bgColor, 0);  //Sum5
  show_string(String(bitRead(Sum5, 1)), csrX + 308, csrY + 163, 2, fontColor, bgColor, 0);  //Sum5
  show_string(String(bitRead(Sum5, 0)), csrX + 338, csrY + 163, 2, fontColor, bgColor, 0);  //Sum5

  show_string(String(bitRead(Sum6, 3)), csrX + 248, csrY + 183, 2, fontColor, bgColor, 0);  //Sum6
  show_string(String(bitRead(Sum6, 2)), csrX + 278, csrY + 183, 2, fontColor, bgColor, 0);  //Sum6
  show_string(String(bitRead(Sum6, 1)), csrX + 308, csrY + 183, 2, fontColor, bgColor, 0);  //Sum6
  show_string(String(bitRead(Sum6, 0)), csrX + 338, csrY + 183, 2, fontColor, bgColor, 0);  //Sum6

  show_string(String(bitRead(Sum7, 3)), csrX + 248, csrY + 203, 2, fontColor, bgColor, 0);  //Sum7
  show_string(String(bitRead(Sum7, 2)), csrX + 278, csrY + 203, 2, fontColor, bgColor, 0);  //Sum7
  show_string(String(bitRead(Sum7, 1)), csrX + 308, csrY + 203, 2, fontColor, bgColor, 0);  //Sum7
  show_string(String(bitRead(Sum7, 0)), csrX + 338, csrY + 203, 2, fontColor, bgColor, 0);  //Sum7

  show_string(String(bitRead(Sum8, 3)), csrX + 248, csrY + 223, 2, fontColor, bgColor, 0);  //Sum8
  show_string(String(bitRead(Sum8, 2)), csrX + 278, csrY + 223, 2, fontColor, bgColor, 0);  //Sum8
  show_string(String(bitRead(Sum8, 1)), csrX + 308, csrY + 223, 2, fontColor, bgColor, 0);  //Sum8
  show_string(String(bitRead(Sum8, 0)), csrX + 338, csrY + 223, 2, fontColor, bgColor, 0);  //Sum8

  show_string(String(bitRead(Sum9, 3)), csrX + 248, csrY + 243, 2, fontColor, bgColor, 0);  //Sum9
  show_string(String(bitRead(Sum9, 2)), csrX + 278, csrY + 243, 2, fontColor, bgColor, 0);  //Sum9
  show_string(String(bitRead(Sum9, 1)), csrX + 308, csrY + 243, 2, fontColor, bgColor, 0);  //Sum9
  show_string(String(bitRead(Sum9, 0)), csrX + 338, csrY + 243, 2, fontColor, bgColor, 0);  //Sum9

  show_string(String(bitRead(SumA, 3)), csrX + 248, csrY + 263, 2, fontColor, bgColor, 0);  //SumA
  show_string(String(bitRead(SumA, 2)), csrX + 278, csrY + 263, 2, fontColor, bgColor, 0);  //SumA
  show_string(String(bitRead(SumA, 1)), csrX + 308, csrY + 263, 2, fontColor, bgColor, 0);  //SumA
  show_string(String(bitRead(SumA, 0)), csrX + 338, csrY + 263, 2, fontColor, bgColor, 0);  //SumA

  show_string(String(bitRead(SumB, 3)), csrX + 248, csrY + 283, 2, fontColor, bgColor, 0);  //SumB
  show_string(String(bitRead(SumB, 2)), csrX + 278, csrY + 283, 2, fontColor, bgColor, 0);  //SumB
  show_string(String(bitRead(SumB, 1)), csrX + 308, csrY + 283, 2, fontColor, bgColor, 0);  //SumB
  show_string(String(bitRead(SumB, 0)), csrX + 338, csrY + 283, 2, fontColor, bgColor, 0);  //SumB

  show_string(String(bitRead(SumC, 3)), csrX + 248, csrY + 303, 2, fontColor, bgColor, 0);  //SumC
  show_string(String(bitRead(SumC, 2)), csrX + 278, csrY + 303, 2, fontColor, bgColor, 0);  //SumC
  show_string(String(bitRead(SumC, 1)), csrX + 308, csrY + 303, 2, fontColor, bgColor, 0);  //SumC
  show_string(String(bitRead(SumC, 0)), csrX + 338, csrY + 303, 2, fontColor, bgColor, 0);  //SumC

  show_string(String(bitRead(SumD, 3)), csrX + 248, csrY + 323, 2, fontColor, bgColor, 0);  //SumD
  show_string(String(bitRead(SumD, 2)), csrX + 278, csrY + 323, 2, fontColor, bgColor, 0);  //SumD
  show_string(String(bitRead(SumD, 1)), csrX + 308, csrY + 323, 2, fontColor, bgColor, 0);  //SumD
  show_string(String(bitRead(SumD, 0)), csrX + 338, csrY + 323, 2, fontColor, bgColor, 0);  //SumD

  show_string(String(bitRead(SumE, 3)), csrX + 248, csrY + 343, 2, fontColor, bgColor, 0);  //SumE
  show_string(String(bitRead(SumE, 2)), csrX + 278, csrY + 343, 2, fontColor, bgColor, 0);  //SumE
  show_string(String(bitRead(SumE, 1)), csrX + 308, csrY + 343, 2, fontColor, bgColor, 0);  //SumE
  show_string(String(bitRead(SumE, 0)), csrX + 338, csrY + 343, 2, fontColor, bgColor, 0);  //SumE

  show_string(String(bitRead(SumF, 3)), csrX + 248, csrY + 363, 2, fontColor, bgColor, 0);  //SumF
  show_string(String(bitRead(SumF, 2)), csrX + 278, csrY + 363, 2, fontColor, bgColor, 0);  //SumF
  show_string(String(bitRead(SumF, 1)), csrX + 308, csrY + 363, 2, fontColor, bgColor, 0);  //SumF
  show_string(String(bitRead(SumF, 0)), csrX + 338, csrY + 363, 2, fontColor, bgColor, 0);  //SumF
}
