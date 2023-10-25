//Screen ID: 0x1000

bool disp_ic_select_init = false;

void disp_IC_select() {
  if (!disp_ic_select_init) {
    disp_IC_select_init();
  }
}



void disp_IC_select_init() {
  tft.Fill_Screen(BLACK);
  show_string("Integrated Circuit TESTER", CENTER, 30, 4, WHITE, WHITE, 0);
  show_string("Select IC", CENTER, 80, 3, WHITE, WHITE, 0);
  tft.Set_Draw_color(RED);
  tft.Draw_Line(50, 70, 750, 70);
  //=========== ROW 1 ==================================
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(45, 140, 200, 190, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(45, 140, 200, 190, 9);
  show_string("74LS08", 50, 150, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 140, 475, 190, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 140, 475, 190, 9);
  show_string("74LS04", CENTER, 150, 4, BLACK, GREEN, 0);


  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(590, 140, 745, 190, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 140, 745, 190, 9);
  show_string("74LS32", 600, 150, 4, BLACK, GREEN, 0);
  //====================================================


  //=========== ROW 2 ==================================
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(45, 220, 200, 270, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(45, 220, 200, 270, 9);
  show_string("74LS00", 50, 230, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 220, 475, 270, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 220, 475, 270, 9);
  show_string("74LS02", CENTER, 230, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(590, 220, 745, 270, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 220, 745, 270, 9);
  show_string("74LS86", 600, 230, 4, BLACK, GREEN, 0);
  //====================================================

  //=========== ROW 3 ==================================
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(45, 300, 200, 350, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(45, 300, 200, 350, 9);
  show_string("74LS83", 50, 310, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 300, 475, 350, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 300, 475, 350, 9);
  show_string("74LS47", CENTER, 310, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(590, 300, 745, 350, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 300, 745, 350, 9);
  show_string("74LS48", 600, 310, 4, BLACK, GREEN, 0);
  //====================================================

  //=========== ROW 4 ==================================
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(45, 380, 200, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(45, 380, 200, 430, 9);
  show_string("74LS147", 65, 395, 3, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
  show_string("74LS42", CENTER, 390, 4, BLACK, GREEN, 0);

  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(590, 380, 745, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 380, 745, 430, 9);
  show_string("NE555", 610, 390, 4, BLACK, GREEN, 0);
  //====================================================

  disp_ic_select_init = true;
}