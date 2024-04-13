//Screen: TRANSISTOR TEST SCREEN
//Screen ID: 0x3000

#define tPin1 A1
#define tPin2 A2
#define tPin3 A3
#define tPin1_res A4
#define tPin2_res A5
#define tPin3_res A6

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
      tft.Set_Draw_color(BLACK);
      tft.Fill_Rectangle(0, 80, 800, 350);
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
  pinMode(tPin2_res, INPUT);

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
  uint8_t testrun = 0;

  disp_transistor_test_init = true;
  Serial.println("\n\nTest Transistor Orientation");
  pinMode(tPin1, INPUT);
  pinMode(tPin2, OUTPUT);
  pinMode(tPin3, INPUT);

  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, INPUT);
  pinMode(tPin2_res, INPUT);

  int AP1_1, AP3_1, AP1_2, AP3_2, AP1_3, AP3_3, AP1_4, AP3_4, AP1_5, AP3_5;
  int AnalogPin1, AnalogPin3;

transistor_runTest:

  digitalWrite(tPin2, 1);
  delayMicroseconds(100);

  AP1_1 = analogRead(tPin1);
  AP3_1 = analogRead(tPin3);
  delay(100);
  AP1_2 = analogRead(tPin1);
  AP3_2 = analogRead(tPin3);
  delay(100);
  AP1_3 = analogRead(tPin1);
  AP3_3 = analogRead(tPin3);
  delay(100);
  AP1_4 = analogRead(tPin1);
  AP3_4 = analogRead(tPin3);
  delay(100);
  AP1_5 = analogRead(tPin1);
  AP3_5 = analogRead(tPin3);

  AnalogPin1 = (AP1_1 + AP1_2 + AP1_3 + AP1_4 + AP1_5) / 5;
  AnalogPin3 = (AP3_1 + AP3_2 + AP3_3 + AP3_4 + AP3_5) / 5;
  int diff = abs(AnalogPin1 - AnalogPin3);

  Serial.println("Analog Pin1:" + String(AnalogPin1));
  Serial.println("Analog Pin3:" + String(AnalogPin3));
  Serial.println("Diff:" + String(diff));

  if (AnalogPin1 > 100 && AnalogPin3 > 100 && diff < 20) {
    Serial.println("***this is probably NPN");
    show_string("NPN Transistor", CENTER, 100, 6, WHITE, WHITE, 0);

    transistor_isNPN = true;
    if (AnalogPin1 > AnalogPin3) {
      Serial.println("C-B-E orientation");
      show_string("Pinout: 1-2-3 = C.-B.-E.", 400, 190, 2, WHITE, WHITE, 0);
      transistor_orientation = false;
      File bmp_file;
      bmp_file = SD.open(file_name[9]);
      draw_bmp_picture(bmp_file, 240, 180);
      bmp_file.close();
    } else if (AnalogPin3 > AnalogPin1) {
      Serial.println("E-B-C orientation");
      show_string("Pinout: 1-2-3 = E.-B.-C.", 400, 190, 2, WHITE, WHITE, 0);
      transistor_orientation = true;
      File bmp_file;
      bmp_file = SD.open(file_name[10]);
      draw_bmp_picture(bmp_file, 240, 180);
      bmp_file.close();
    } else {
      Serial.println("******Transistor Orientation couldn't be determined!");
    }
  } else {
    digitalWrite(tPin2, 1);
    delayMicroseconds(100);

    AP1_1 = analogRead(tPin1);
    AP3_1 = analogRead(tPin3);
    delay(100);
    AP1_2 = analogRead(tPin1);
    AP3_2 = analogRead(tPin3);
    delay(100);
    AP1_3 = analogRead(tPin1);
    AP3_3 = analogRead(tPin3);
    delay(100);
    AP1_4 = analogRead(tPin1);
    AP3_4 = analogRead(tPin3);
    delay(100);
    AP1_5 = analogRead(tPin1);
    AP3_5 = analogRead(tPin3);

    AnalogPin1 = (AP1_1 + AP1_2 + AP1_3 + AP1_4 + AP1_5) / 5;
    AnalogPin3 = (AP3_1 + AP3_2 + AP3_3 + AP3_4 + AP3_5) / 5;

    Serial.println("***this is probably PNP");
    Serial.println("Analog Pin1:" + String(AnalogPin1));
    Serial.println("Analog Pin3:" + String(AnalogPin3));
    show_string("PNP Transistor", CENTER, 100, 6, WHITE, WHITE, 0);
    transistor_isPNP = true;
    if (AnalogPin3 > AnalogPin1) {
      Serial.println("C-B-E orientation");
      show_string("Pinout: 1-2-3 = C.-B.-E.", 400, 190, 2, WHITE, WHITE, 0);
      transistor_orientation = false;
      File bmp_file;
      bmp_file = SD.open(file_name[11]);
      draw_bmp_picture(bmp_file, 240, 180);
      bmp_file.close();
    } else if (AnalogPin1 > AnalogPin3) {
      Serial.println("E-B-C orientation");
      show_string("Pinout: 1-2-3 = E.-B.-C.", 400, 190, 2, WHITE, WHITE, 0);
      transistor_orientation = true;
      File bmp_file;
      bmp_file = SD.open(file_name[12]);
      draw_bmp_picture(bmp_file, 240, 180);
      bmp_file.close();
    } else {
      Serial.println("******Transistor Orientation couldn't be determined!");
      Serial.println("\n\nRUNNING TEST AGAIN...");
      testrun++;
      if (testrun > 3) {
        goto TransistorTest_conclude;
      } else {
        goto transistor_runTest;
      }
    }
  }


  goto TransistorTest_InitExit;



TransistorTest_conclude:
  delay(100);
  Serial.println("\n couldn't detect Transistor, it may be damaged...");
TransistorTest_InitExit:
  delay(10);
  testTransistorParameters();
  pinMode(tPin1, INPUT);
  pinMode(tPin2, INPUT);
  pinMode(tPin3, INPUT);
  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, INPUT);
  pinMode(tPin2_res, INPUT);
}


void testTransistorParameters() {
  /*
    pinMode(tPin1, INPUT);
    pinMode(tPin2, INPUT);
    pinMode(tPin3, OUTPUT);
    pinMode(tPin1_res, INPUT);
    pinMode(tPin2_res, OUTPUT);
    pinMode(tPin2_res, INPUT);
  */

  Serial.println("=============================================");
  if (!transistor_orientation) {
    Serial.println("TRANSISTOR ORIENTATION #1 : 1-2-3 C-B-E");
  } else {
    Serial.println("TRANSISTOR ORIENTATION #2 : 1-2-3 E-B-C");
  }




  if (transistor_isNPN) {
    Serial.println("TESTING NPN.........");

    if (!transistor_orientation) {
      pinMode(tPin1, INPUT);   //COLLECTOR
      pinMode(tPin2, INPUT);   //BASE
      pinMode(tPin3, OUTPUT);  //EMITTER

      pinMode(tPin1_res, OUTPUT);  //COLLECTOR-RESISTOR

      digitalWrite(tPin1_res, 1);
      digitalWrite(tPin3, 0);
    } else {
      pinMode(tPin3, INPUT);   //COLLECTOR
      pinMode(tPin2, INPUT);   //BASE
      pinMode(tPin1, OUTPUT);  //EMITTER

      pinMode(tPin3_res, OUTPUT);  //COLLECTOR-RESISTOR

      digitalWrite(tPin3_res, 1);
      digitalWrite(tPin1, 0);
    }




    unsigned int AnalogBase = analogRead(tPin2);
    Serial.println("\Base Analog: " + String(AnalogBase));
    float Uf = (AnalogBase / 204.6) * 1000;
    float BaseCurrent = (Uf * 1000) / baseResistor;
    Serial.println("Vf= " + String(Uf) + "mV");
    Serial.println("Base Current:" + String(BaseCurrent) + "mA");

    pinMode(tPin2, OUTPUT);
    digitalWrite(tPin2, 1);
    delay(100);
    unsigned int AnalogCollector = 0;
    if (transistor_orientation) {
      AnalogCollector = analogRead(tPin1);
    } else {
      AnalogCollector = analogRead(tPin3);
    }

    Serial.println("\n\nCollector Analog: " + String(AnalogCollector));
    float LeakageVoltageC = (1023 - AnalogCollector) / 204.6;
    Serial.println("Leakage Voltage:" + String(LeakageVoltageC) + "mV");
    //float LeakageCurrentC = LeakageVoltageC / collectorResistor;
    //Serial.println("Leakage Current:" + String(LeakageCurrentC) + "mA");
    unsigned int GAIN = (LeakageVoltageC * 1000) / collectorResistor / (BaseCurrent / 1000);
    Serial.println("GAIN:" + String(GAIN - 150));
    show_string("B= " + String(GAIN - 150), 400, 220, 2, WHITE, WHITE, 0);
    show_string("Vf= " + String(Uf) + "mV", 400, 250, 2, WHITE, WHITE, 0);
    if (GAIN > 165 && GAIN < 175) {
      //Serial.println("BROKEN OR NO TRANSISTOR");
      tft.Fill_Screen(BLACK);

      File bmp_file;
      bmp_file = SD.open(file_name[0]);
      draw_bmp_picture(bmp_file, 10, 10);
      bmp_file.close();

      display_TitleBar("Transistor TESTER", " ");

      show_string("BROKEN or NO Transistor", CENTER, 200, 4, WHITE, WHITE, 0);

      print_button_test();
    } else if (Uf == 5000.00 || Uf == 2920.77) {
      //Serial.println("BROKEN OR NO TRANSISTOR");
      tft.Fill_Screen(BLACK);

      File bmp_file;
      bmp_file = SD.open(file_name[0]);
      draw_bmp_picture(bmp_file, 10, 10);
      bmp_file.close();

      display_TitleBar("Transistor TESTER", " ");

      show_string("BROKEN or NO Transistor", CENTER, 200, 4, WHITE, WHITE, 0);

      print_button_test();
    }

  } else if (transistor_isPNP) {
    Serial.println("TESTING PNP.........");

    if (transistor_orientation) {
      pinMode(tPin1, INPUT);   //COLLECTOR
      pinMode(tPin2, INPUT);   //BASE
      pinMode(tPin3, OUTPUT);  //EMITTER

      pinMode(tPin1_res, OUTPUT);  //COLLECTOR-RESISTOR


      digitalWrite(tPin1_res, 0);
      digitalWrite(tPin3, 1);

    } else {
      pinMode(tPin3, INPUT);   //COLLECTOR
      pinMode(tPin2, INPUT);   //BASE
      pinMode(tPin1, OUTPUT);  //EMITTER

      pinMode(tPin3_res, OUTPUT);  //COLLECTOR-RESISTOR


      digitalWrite(tPin3_res, 0);
      digitalWrite(tPin1, 1);
    }




    unsigned int AnalogBase = analogRead(tPin2);
    Serial.println("\Base Analog: " + String(AnalogBase));
    float Uf = (AnalogBase / 204.6) * 100;
    float BaseCurrent = (Uf * 1000) / baseResistor;
    Serial.println("Vf= " + String(Uf) + "mV");
    Serial.println("Base Current:" + String(BaseCurrent) + "mA");


    pinMode(tPin2, OUTPUT);
    digitalWrite(tPin2, 0);
    delay(100);

    unsigned int AnalogCollector = 0;
    if (transistor_orientation) {
      AnalogCollector = analogRead(tPin1);
    } else {
      AnalogCollector = analogRead(tPin3);
    }
    Serial.println("\n\nCollector Analog: " + String(AnalogCollector));
    float LeakageVoltageC = ((1023 - AnalogCollector) / 204.6) * 1000;
    Serial.println("Leakage Voltage:" + String(LeakageVoltageC) + "mV");
    float LeakageCurrentC = LeakageVoltageC / collectorResistor;
    Serial.println("Leakage Current:" + String(LeakageCurrentC) + "mA");
    unsigned int GAIN = (LeakageVoltageC) / collectorResistor / (BaseCurrent / 1000) * 10;
    Serial.println("GAIN:" + String(GAIN - 150));

    show_string("B= " + String(GAIN - 150), 400, 220, 2, WHITE, WHITE, 0);
    show_string("Vf= " + String(Uf) + "mV", 400, 250, 2, WHITE, WHITE, 0);

    if (GAIN > 165 && GAIN < 175) {
      //Serial.println("BROKEN OR NO TRANSISTOR");
      tft.Fill_Screen(BLACK);

      File bmp_file;
      bmp_file = SD.open(file_name[0]);
      draw_bmp_picture(bmp_file, 10, 10);
      bmp_file.close();

      display_TitleBar("Transistor TESTER", " ");

      show_string("BROKEN or NO Transistor", CENTER, 200, 4, WHITE, WHITE, 0);

      print_button_test();
    } else if (Uf == 500.00 || Uf == 292.77) {
      //Serial.println("BROKEN OR NO TRANSISTOR");
      tft.Fill_Screen(BLACK);

      File bmp_file;
      bmp_file = SD.open(file_name[0]);
      draw_bmp_picture(bmp_file, 10, 10);
      bmp_file.close();

      display_TitleBar("Transistor TESTER", " ");

      show_string("BROKEN or NO Transistor", CENTER, 200, 4, WHITE, WHITE, 0);

      print_button_test();
    }
  }
  Serial.println("=============================================");
}
