
bool disp_home_init = false;

bool btn_IC_pressed = false;
bool btn_Resistor_pressed = false;
bool btn_Transistor_pressed = false;

void disp_Home() {
  if (!disp_home_init) {
    disp_Home_init();
  }

  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    long cx = map(p.x, 130, 4000, 0, 800);
    long cy = map(p.y, 216, 3820, 0, 480);

    if (cx > 150 && cx < 690 && cy > 190 && cy < 240) {
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(150, 190, 690, 250, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 190, 690, 250, 15);
      show_string("Integrated Circuit", CENTER, 205, 4, BLACK, GREEN, 0);

      btn_IC_pressed = true;
      touch_toggle = true;
      touch_last_millis = millis();
    } else if (cx > 150 && cx < 690 && cy > 290 && cy < 350) {
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(150, 290, 690, 350, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 290, 690, 350, 15);
      show_string("Resistor", CENTER, 300, 6, BLACK, GREEN, 0);

      btn_Resistor_pressed = true;
      touch_toggle = true;
      touch_last_millis = millis();
    } else if (cx > 150 && cx < 690 && cy > 390 && cy < 450) {
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(150, 390, 690, 450, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 390, 690, 450, 15);
      show_string("Transistor", CENTER, 400, 6, BLACK, GREEN, 0);

      btn_Transistor_pressed = true;
      touch_toggle = true;
      touch_last_millis = millis();
    }

    touch_toggle = true;
  } else {
    //Button IC
    if (btn_IC_pressed && !touch_toggle) {
      tft.Set_Draw_color(RED);
      tft.Fill_Round_Rectangle(150, 190, 690, 250, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 190, 690, 250, 15);
      show_string("Integrated Circuit", CENTER, 205, 4, WHITE, RED, 0);

      btn_IC_pressed = false;
    } else if (btn_Resistor_pressed && !touch_toggle) {
      tft.Set_Draw_color(RED);
      tft.Fill_Round_Rectangle(150, 290, 690, 350, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 290, 690, 350, 15);
      show_string("Resistor", CENTER, 300, 6, WHITE, RED, 0);

      btn_Resistor_pressed = false;
    } else if (btn_Transistor_pressed && !touch_toggle) {
      tft.Set_Draw_color(RED);
      tft.Fill_Round_Rectangle(150, 390, 690, 450, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 390, 690, 450, 15);
      show_string("Transistor", CENTER, 400, 6, WHITE, RED, 0);
      
      btn_Transistor_pressed=false;
    }
  }
}


void disp_Home_init() {
  show_string("ELECTRONIC COMPONENT TESTER", CENTER, 30, 4, WHITE, WHITE, 0);
  show_string("by MICROn Technology", CENTER, 80, 2, WHITE, WHITE, 0);
  tft.Draw_Line(50, 70, 750, 70);

  show_string("Select Component:", CENTER, 130, 3, WHITE, WHITE, 0);


  tft.Set_Draw_color(RED);
  tft.Fill_Round_Rectangle(150, 190, 690, 250, 15);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(150, 190, 690, 250, 15);
  show_string("Integrated Circuit", CENTER, 205, 4, WHITE, RED, 0);


  tft.Set_Draw_color(RED);
  tft.Fill_Round_Rectangle(150, 290, 690, 350, 15);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(150, 290, 690, 350, 15);
  show_string("Resistor", CENTER, 300, 6, WHITE, RED, 0);

  tft.Set_Draw_color(RED);
  tft.Fill_Round_Rectangle(150, 390, 690, 450, 15);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(150, 390, 690, 450, 15);
  show_string("Transistor", CENTER, 400, 6, WHITE, RED, 0);

  disp_home_init = true;
}