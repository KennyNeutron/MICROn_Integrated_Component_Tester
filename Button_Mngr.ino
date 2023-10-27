//Button Displays

void print_button_test() {
  //TEST Button
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
  show_string("TEST", CENTER, 390, 4, BLACK, GREEN, 0);
}

void print_button_test_pressed() {
  tft.Set_Draw_color(BLUE);
  tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
  show_string("TEST", CENTER, 390, 4, WHITE, BLUE, 0);
}