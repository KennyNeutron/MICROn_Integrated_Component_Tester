void disp_LoadingScreen() {
  tft.Fill_Screen(BLACK);
  show_string("MICROn Technology", CENTER, 200, 6, WHITE, WHITE, 0);
  show_string("STARTING...", CENTER, 350, 3, WHITE, WHITE, 0);
}

void display_TitleBar(String str_TitleBar, String str_Header) {
  show_string(str_TitleBar, CENTER, 30, 4, WHITE, WHITE, 0);
  show_string(str_Header, CENTER, 80, 3, WHITE, WHITE, 0);
  tft.Set_Draw_color(RED);
  tft.Draw_Line(50, 70, 750, 70);
}