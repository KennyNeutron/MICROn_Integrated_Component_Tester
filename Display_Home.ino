//Screen: HOME SCREEN
//Screen ID: 0x0000

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
      tft.Set_Draw_color(BLACK);
      tft.Draw_Round_Rectangle(150, 390, 690, 450, 15);
      show_string("Transistor", CENTER, 400, 6, BLACK, GREEN, 0);

      btn_Transistor_pressed = true;
      touch_toggle = true;
      touch_last_millis = millis();
    }

    touch_toggle = true;
  } else {

    if (btn_IC_pressed && !touch_toggle) {
      //Button IC Tester
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(150, 190, 690, 250, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 190, 690, 250, 15);
      show_string("Integrated Circuit", CENTER, 205, 4, WHITE, GREEN, 0);

      btn_IC_pressed = false;
      btn_pressed = 1;
    } else if (btn_Resistor_pressed && !touch_toggle) {
      //Button Resistor
      tft.Set_Draw_color(RED);
      tft.Fill_Round_Rectangle(150, 290, 690, 350, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 290, 690, 350, 15);
      show_string("Resistor", CENTER, 300, 6, WHITE, RED, 0);

      btn_Resistor_pressed = false;
      btn_pressed = 2;
    } else if (btn_Transistor_pressed && !touch_toggle) {
      //Button Transistor
      tft.Set_Draw_color(RED);
      tft.Fill_Round_Rectangle(150, 390, 690, 450, 15);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(150, 390, 690, 450, 15);
      show_string("Transistor", CENTER, 400, 6, WHITE, RED, 0);

      btn_Transistor_pressed = false;
      btn_pressed = 3;
    }
  }

  //CONDITION based on the btn_pressed
  if (!btn_IC_pressed && !btn_Resistor_pressed && !btn_Transistor_pressed && !touch_toggle && btn_pressed > 0) {
    switch (btn_pressed) {
      case 1:
        currentScreen = 0x1000;
        break;
      case 2:
        currentScreen = 0x2000;
        break;
      case 3:
        currentScreen = 0x3000;
        break;
    }
    disp_Home_exit();
  }
}


void disp_Home_exit() {
  disp_home_init = false;
  btn_IC_pressed = false;
  btn_Resistor_pressed = false;
  btn_Transistor_pressed = false;

  btn_pressed = 0;
}


void disp_Home_init() {
  tft.Fill_Screen(BLACK);
  show_string("ELECTRONIC COMPONENT TESTER", CENTER, 30, 4, WHITE, WHITE, 0);
  show_string("by MICROn Technology", CENTER, 80, 2, WHITE, WHITE, 0);
  tft.Set_Draw_color(RED);
  tft.Draw_Line(50, 70, 750, 70);

  show_string("Select Component:", CENTER, 130, 3, WHITE, WHITE, 0);


  tft.Set_Draw_color(RED);
  tft.Fill_Round_Rectangle(150, 190, 690, 250, 15);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(150, 190, 690, 250, 15);
  //tft.Set_Draw_color(BLUE);
  //tft.Fill_Circle(150, 190, 5);
  //tft.Fill_Circle(690, 250, 5);
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