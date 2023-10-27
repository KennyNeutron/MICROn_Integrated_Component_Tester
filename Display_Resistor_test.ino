//Screen: RESISTOR TEST SCREEN
//Screen ID: 0x2000

#define resistor_read_pin A0

bool disp_resistor_test_init = false;

bool btn_TestResistor_pressed = false;

void disp_Resistor_test() {
  if (!disp_resistor_test_init) {
    disp_Resistor_test_init();
  }

  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    long cx = map(p.x, 130, 4000, 0, 800);
    long cy = map(p.y, 216, 3820, 0, 480);

    if (cx > 10 && cx < 70 && cy > 10 && cy < 70) {
      //Home Button
      tft.Set_Draw_color(WHITE);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = true;
      touch_IsTouched();
    } else if (cx > 320 && cx < 475 && cy > 380 && cy < 430) {
      tft.Set_Draw_color(BLUE);
      tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
      show_string("TEST", CENTER, 390, 4, WHITE, BLUE, 0);
      btn_TestResistor_pressed = true;
    }
  } else {
    if (btn_Home_pressed && !touch_toggle) {
      //Home Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = false;
      btn_pressed = 255;
    } else if (btn_TestResistor_pressed && !touch_toggle) {
      //Test (Resistor) Button
      tft.Set_Draw_color(GREEN);
      tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
      tft.Set_Draw_color(WHITE);
      tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
      show_string("TEST", CENTER, 390, 4, BLACK, GREEN, 0);

      btn_TestResistor_pressed = false;
      test_resistor();
    }
  }

  //CONDITION based on the btn_pressed
  if (!btn_Home_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        currentScreen = 0x0000;
        break;
    }
    disp_Resistor_test_exit();
  }
}

void test_resistor() {
  float R1 = 0;
  float R2 = 10000;
  float Vi = 5.02;
  int analogValue = analogRead(resistor_read_pin);
  float Vo = analogValue * (5.02 / 1023.0);

  R1 = ((Vi * R2) - (Vo * R2)) / Vo;

  Serial.print("Analog Value:");
  Serial.println(analogValue);
  Serial.print("Voltage at A0:");
  Serial.println(Vo);

  int disp_resistance = R1;
  Serial.print("Resistance:");
  Serial.println(disp_resistance);

  String str_tested_resistance = String(disp_resistance) + " Ohms";

  tft.Set_Draw_color(BLACK);
  tft.Fill_Rectangle(0, 240, 800, 360);
  show_string(str_tested_resistance, CENTER, 250, 6, WHITE, BLACK, 0);
}

void disp_Resistor_test_exit() {
  btn_pressed = 0;
  disp_resistor_test_init = false;
}


void disp_Resistor_test_init() {
  pinMode(resistor_read_pin, INPUT);
  analogReference(EXTERNAL);

  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 10);
  bmp_file.close();

  bmp_file = SD.open(file_name[1]);
  draw_bmp_picture(bmp_file, 350, 90);
  bmp_file.close();


  show_string("Resistor TESTER", CENTER, 30, 4, WHITE, WHITE, 0);
  tft.Set_Draw_color(RED);
  tft.Draw_Line(50, 70, 750, 70);


  //TEST Button
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
  show_string("TEST", CENTER, 390, 4, BLACK, GREEN, 0);





  disp_resistor_test_init = true;
}