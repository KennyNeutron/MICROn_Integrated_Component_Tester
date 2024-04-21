//Screen: TRANSISTOR TEST SCREEN
//Screen ID: 0x3000

#define tPin1 A1
#define tPin2 A2
#define tPin3 A3
#define tPin1_res A8
#define tPin2_res A9
#define tPin3_res A10

bool disp_transistor_test_init = false;

bool transistor_isNPN = false;
bool transistor_isPNP = false;
bool transistor_orientation = false;  //false --> C.B.E.   true --> E.B.C.

bool btn_TestTransistor_pressed = false;

unsigned int baseResistor = 10000;
unsigned int collectorResistor = 1000;


void disp_Transistor_test() {
  if (!disp_transistor_test_init) {
    disp_Transistor_test_INIT();
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
      print_button_test_pressed();
      btn_TestTransistor_pressed = true;
    }
  } else {
    if (btn_Home_pressed && !touch_toggle && !touch_toggle) {
      //Home Button
      tft.Set_Draw_color(BLACK);
      tft.Draw_Rectangle(10, 10, 70, 70);
      btn_Home_pressed = false;
      btn_pressed = 255;
    } else if (btn_TestTransistor_pressed && !touch_toggle) {
      //Test (Transistor) Button
      print_button_test();

      btn_TestTransistor_pressed = false;
      //tft.Set_Draw_color(BLACK);
      //tft.Fill_Rectangle(0, 80, 800, 350);
      run_TestTransistor();
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
  pinMode(tPin3_res, INPUT);

  transistor_isNPN = false;
  transistor_isPNP = false;

  btn_pressed = 0;
  disp_transistor_test_init = false;
  btn_TestTransistor_pressed = false;
}

void disp_Transistor_test_INIT() {
  analogReference(INTERNAL2V56);
  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 10);
  bmp_file.close();

  display_TitleBar("Transistor TESTER", " ");

  print_button_test();
  disp_transistor_test_init = true;
}

void run_TestTransistor() {
  Serial.println("test transistor");
  pinMode(tPin1, OUTPUT);
  pinMode(tPin2, OUTPUT);
  pinMode(tPin3, INPUT);
  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, INPUT);
  pinMode(tPin3_res, INPUT);

  digitalWrite(tPin1, 0);
  digitalWrite(tPin2, 1);
  delay(1000);
  Serial.println("1an1:" + String(analogRead(tPin3)));
  Serial.println("1anR1:" + String(analogRead(tPin3_res)));

  digitalWrite(tPin1, 1);
  digitalWrite(tPin2, 0);
  delay(1000);
  Serial.println("1an2:" + String(analogRead(tPin3)));
  Serial.println("1anR2:" + String(analogRead(tPin3_res)));

  transistor_resetallpins();



  // tft.Fill_Screen(BLACK);
  // File bmp_file;
  // bmp_file = SD.open(file_name[0]);
  // draw_bmp_picture(bmp_file, 10, 10);
  // bmp_file.close();

  // display_TitleBar("Transistor TESTER", " ");
  // btn_TestTransistor_pressed = false;
  // tft.Set_Draw_color(BLACK);
  // tft.Fill_Rectangle(0, 80, 800, 350);
  // //Test (Transistor) Button
  // print_button_test();
}

void transistor_resetallpins() {
  pinMode(tPin1, INPUT);
  pinMode(tPin2, INPUT);
  pinMode(tPin3, INPUT);
  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, INPUT);
  pinMode(tPin3_res, INPUT);
}
