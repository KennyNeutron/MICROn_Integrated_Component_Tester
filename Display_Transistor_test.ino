//Screen: TRANSISTOR TEST SCREEN
//Screen ID: 0x3000

#define tPin1 A1
#define tPin2 A2
#define tPin3 A3
#define tPin1_res A4
#define tPin2_res A5
#define tPin3_res A6

bool disp_transistor_test_init = false;



void disp_Transistor_test() {
  if (!disp_transistor_test_init) {
    disp_Transistor_test_init();
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
    }
  } else {
    if (btn_Home_pressed && !touch_toggle && !touch_toggle) {
      //Home Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = false;
      btn_pressed = 255;
    }
  }

  //CONDITION based on the btn_pressed
  if (!btn_Home_pressed && btn_pressed > 0) {
    switch (btn_pressed) {
      case 255:
        currentScreen = 0x0000;
        break;
    }
    disp_Transistor_test_exit();
  }
}


void disp_Transistor_test_exit() {
  pinMode(tPin1, INPUT);
  pinMode(tPin2, INPUT);
  pinMode(tPin3, INPUT);
  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, INPUT);
  pinMode(tPin2_res, INPUT);

  btn_pressed = 0;
  disp_transistor_test_init = false;
}

void disp_Transistor_test_init() {

  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 10);
  bmp_file.close();

  display_TitleBar("Transistor TESTER", " ");

  disp_transistor_test_init = true;
  transistor_orientation1();
}


void transistor_orientation1() {
  pinMode(tPin1, INPUT);
  pinMode(tPin2, INPUT);
  pinMode(tPin3, OUTPUT);
  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, OUTPUT);
  pinMode(tPin2_res, INPUT);

  digitalWrite(tPin2_res, 0);  //EMITTER PIN --> GND
  digitalWrite(tPin2, 1);      //BASE PIN --> VCC

  Serial.println("TRANSISTOR ORIENTATION #1 : 1-2-3 C-B-E");

  delay(100);

  Serial.println("Collector ADC Read: " + String(analogRead(tPin1)));

  if (analogRead(tPin1) > 0) {
    Serial.println("This transistor is PNP");
  } else {
    Serial.println("This transistor is NPN");
  }
}
