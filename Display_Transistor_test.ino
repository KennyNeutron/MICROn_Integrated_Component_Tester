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

unsigned int baseResistor = 10000;
unsigned int collectorResistor = 1000;


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

  transistor_isNPN = false;
  transistor_isPNP = false;

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

  uint8_t testrun = 0;

  disp_transistor_test_init = true;
  Serial.println("\n\nTest Transistor Orientation");
  pinMode(tPin1, INPUT);
  pinMode(tPin2, OUTPUT);
  pinMode(tPin3, INPUT);

  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, INPUT);
  pinMode(tPin2_res, INPUT);

  unsigned int AP1_1, AP3_1, AP1_2, AP3_2, AP1_3, AP3_3, AP1_4, AP3_4, AP1_5, AP3_5;
  unsigned int AnalogPin1, AnalogPin3;

transistor_runTest:

  digitalWrite(tPin2, 0);
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

  if (AnalogPin1 > 200 && AnalogPin3 > 200) {
    Serial.println("***this is probably NPN");
    Serial.println("Analog Pin1:" + String(AnalogPin1));
    Serial.println("Analog Pin3:" + String(AnalogPin3));
    if (AnalogPin1 > AnalogPin3) {
      Serial.println("C-B-E orientation");
      testTransistorParameters_Orientation1();
    } else if (AnalogPin3 > AnalogPin1) {
      Serial.println("E-B-C orientation");
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

    if (AnalogPin1 > AnalogPin3) {
      Serial.println("C-B-E orientation");
      testTransistorParameters_Orientation1();
    } else if (AnalogPin3 > AnalogPin1) {
      Serial.println("E-B-C orientation");
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
}


void testTransistorParameters_Orientation1() {
  pinMode(tPin1, INPUT);
  pinMode(tPin2, INPUT);
  pinMode(tPin3, OUTPUT);
  pinMode(tPin1_res, INPUT);
  pinMode(tPin2_res, OUTPUT);
  pinMode(tPin2_res, INPUT);

  digitalWrite(tPin2_res, 0);  //EMITTER PIN --> GND
  digitalWrite(tPin2, 1);      //BASE PIN --> VCC
  Serial.println("=============================================");
  Serial.println("TRANSISTOR ORIENTATION #1 : 1-2-3 C-B-E");

  delay(100);

  Serial.println("Collector ADC Read: " + String(analogRead(tPin1)));

  if (analogRead(tPin1) > 0) {
    Serial.println("This transistor is PNP");
    transistor_isPNP = true;
  } else {
    Serial.println("This transistor is NPN");
    transistor_isNPN = true;
  }

  if (transistor_isNPN) {
    Serial.println("TESTING NPN.........");
    pinMode(tPin1, INPUT);   //COLLECTOR
    pinMode(tPin2, INPUT);   //BASE
    pinMode(tPin3, OUTPUT);  //EMITTER

    pinMode(tPin1_res, OUTPUT);  //COLLECTOR-RESISTOR

    digitalWrite(tPin1_res, 1);
    digitalWrite(tPin3, 0);

    unsigned int AnalogBase = analogRead(tPin2);
    Serial.println("\Base Analog: " + String(AnalogBase));
    float Uf = (AnalogBase / 204.6) * 100;
    Serial.println("Uf= " + String(Uf) + "mV");

    unsigned int AnalogCollector = analogRead(tPin1);
    Serial.println("\n\nCollector Analog: " + String(AnalogCollector));
    float LeakageVoltageC = ((1023 - AnalogCollector) / 204.6) * 10000;
    Serial.println("Leakage Voltage:" + String(LeakageVoltageC) + "mV");
    float LeakageCurrentC = LeakageVoltageC / collectorResistor;
    Serial.println("Leakage Current:" + String(LeakageCurrentC) + "mA");
  } else if (transistor_isPNP) {
    Serial.println("TESTING PNP.........");
    pinMode(tPin1, INPUT);   //COLLECTOR
    pinMode(tPin2, INPUT);   //BASE
    pinMode(tPin3, OUTPUT);  //EMITTER

    pinMode(tPin1_res, OUTPUT);  //COLLECTOR-RESISTOR


    digitalWrite(tPin1_res, 0);
    digitalWrite(tPin3, 1);

    unsigned int AnalogBase = analogRead(tPin2);
    Serial.println("\nBase Analog: " + String(AnalogBase));
    float Uf = (AnalogBase / 204.6) * 100;
    Serial.println("Uf= " + String(Uf) + "mV");

    unsigned int AnalogCollector = analogRead(tPin1);
    Serial.println("\n\nCollector Analog: " + String(AnalogCollector));
    float LeakageVoltageC = ((1023 - AnalogCollector) / 204.6) * 100;
    Serial.println("Leakage Voltage:" + String(LeakageVoltageC) + "mV");
    float LeakageCurrentC = LeakageVoltageC / collectorResistor;
    Serial.println("Leakage Current:" + String(LeakageCurrentC) + "mA");
  }
  Serial.println("=============================================");
}
