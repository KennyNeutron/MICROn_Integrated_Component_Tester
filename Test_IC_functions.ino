/*
    Electronic Component Tester on TFT Display
    Test IC Functions
    Version 1.0.0

    by: MICROn Technology

    Environment: Arduino Mega 2560

    Date Started: 10-27-2023
    Date Finished: N/A
*/

bool LG1_Result00 = false;
bool LG1_Result01 = false;
bool LG1_Result10 = false;
bool LG1_Result11 = false;

bool LG2_Result00 = false;
bool LG2_Result01 = false;
bool LG2_Result10 = false;
bool LG2_Result11 = false;

bool LG3_Result00 = false;
bool LG3_Result01 = false;
bool LG3_Result10 = false;
bool LG3_Result11 = false;

bool LG4_Result00 = false;
bool LG4_Result01 = false;
bool LG4_Result10 = false;
bool LG4_Result11 = false;

void IC14_pinMode_init() {
  pinMode(IC14_Pin1, OUTPUT);
  pinMode(IC14_Pin2, OUTPUT);
  pinMode(IC14_Pin3, INPUT);

  pinMode(IC14_Pin4, OUTPUT);
  pinMode(IC14_Pin5, OUTPUT);
  pinMode(IC14_Pin6, INPUT);

  pinMode(IC14_Pin7, OUTPUT);  //GND pin

  pinMode(IC14_Pin8, INPUT);
  pinMode(IC14_Pin9, OUTPUT);
  pinMode(IC14_Pin10, OUTPUT);

  pinMode(IC14_Pin11, INPUT);
  pinMode(IC14_Pin12, OUTPUT);
  pinMode(IC14_Pin13, OUTPUT);

  pinMode(IC14_Pin14, OUTPUT);  //VCC;

  if (IC_tested == IC_74LS02) {
    digitalWrite(IC14_Pin7, 1);   //VCC
    digitalWrite(IC14_Pin14, 0);  //GND
  } else {
    digitalWrite(IC14_Pin7, 0);   //GND
    digitalWrite(IC14_Pin14, 1);  //VCC
  }


  digitalWrite(IC14_Pin1, 0);
  digitalWrite(IC14_Pin2, 0);

  digitalWrite(IC14_Pin4, 0);
  digitalWrite(IC14_Pin5, 0);

  digitalWrite(IC14_Pin9, 0);
  digitalWrite(IC14_Pin10, 0);

  digitalWrite(IC14_Pin12, 0);
  digitalWrite(IC14_Pin13, 0);

  Serial.println("IC POWER ON!");
}

void IC14_pinMode_exit() {
  pinMode(IC14_Pin1, INPUT);
  pinMode(IC14_Pin2, INPUT);
  pinMode(IC14_Pin3, INPUT);
  pinMode(IC14_Pin4, INPUT);
  pinMode(IC14_Pin5, INPUT);
  pinMode(IC14_Pin6, INPUT);
  pinMode(IC14_Pin7, INPUT);
  pinMode(IC14_Pin8, INPUT);
  pinMode(IC14_Pin9, INPUT);
  pinMode(IC14_Pin10, INPUT);
  pinMode(IC14_Pin11, INPUT);
  pinMode(IC14_Pin12, INPUT);
  pinMode(IC14_Pin13, INPUT);
  pinMode(IC14_Pin14, INPUT);
  Serial.println("IC POWER OFF!");
}


void test_IC14() {

  Serial.print("\n############################################################################\n");
  test_LogicGate1();
  test_LogicGate2();
  test_LogicGate3();
  test_LogicGate4();
  Serial.print("\n############################################################################\n");
}

void test_LogicGate4() {
  bool IC_pin11 = 0;

  Serial.print("\n");

  //Logic Gate #4 INPUT: 00
  digitalWrite(IC14_Pin12, 0);
  digitalWrite(IC14_Pin13, 0);
  delayMicroseconds(10);
  IC_pin11 = digitalRead(IC14_Pin11);
  LG4_Result00 = IC_pin11;
  Serial.println("Logic Gate4: \t Pin12:0 \t Pin13:0 \t Pin11:" + String(LG4_Result00) + "\tLG4_R00:" + String(get_LG4_Result00()));
  delayMicroseconds(10);

  //Logic Gate #4 INPUT: 01
  digitalWrite(IC14_Pin12, 0);
  digitalWrite(IC14_Pin13, 1);
  delayMicroseconds(10);
  IC_pin11 = digitalRead(IC14_Pin11);
  LG4_Result01 = IC_pin11;
  Serial.println("Logic Gate4: \t Pin12:0 \t Pin13:1 \t Pin11:" + String(LG4_Result01) + "\tLG4_R01:" + String(get_LG4_Result01()));
  delayMicroseconds(10);

  //Logic Gate #4 INPUT: 10
  digitalWrite(IC14_Pin12, 1);
  digitalWrite(IC14_Pin13, 0);
  delayMicroseconds(10);
  IC_pin11 = digitalRead(IC14_Pin11);
  LG4_Result10 = IC_pin11;
  Serial.println("Logic Gate4: \t Pin12:1 \t Pin13:0 \t Pin11:" + String(LG4_Result10) + "\tLG4_R10:" + String(get_LG4_Result10()));
  delayMicroseconds(10);

  //Logic Gate #4 INPUT: 11
  digitalWrite(IC14_Pin12, 1);
  digitalWrite(IC14_Pin13, 1);
  delayMicroseconds(10);
  IC_pin11 = digitalRead(IC14_Pin11);
  LG4_Result11 = IC_pin11;
  Serial.println("Logic Gate4: \t Pin12:1 \t Pin13:1 \t Pin11:" + String(LG4_Result11) + "\tLG4_R11:" + String(get_LG4_Result11()));
  delayMicroseconds(10);
}

void test_LogicGate3() {
  bool IC_pin8 = 0;

  Serial.print("\n");

  //Logic Gate #3 INPUT: 00
  digitalWrite(IC14_Pin9, 0);
  digitalWrite(IC14_Pin10, 0);
  delayMicroseconds(10);
  IC_pin8 = digitalRead(IC14_Pin8);
  LG3_Result00 = IC_pin8;
  Serial.println("Logic Gate3: \t Pin9:0 \t Pin10:0 \t Pin8:" + String(LG3_Result00) + "\t\tLG3_R00:" + String(get_LG3_Result00()));
  delayMicroseconds(10);

  //Logic Gate #3 INPUT: 01
  digitalWrite(IC14_Pin9, 0);
  digitalWrite(IC14_Pin10, 1);
  delayMicroseconds(10);
  IC_pin8 = digitalRead(IC14_Pin8);
  LG3_Result01 = IC_pin8;
  Serial.println("Logic Gate3: \t Pin9:0 \t Pin10:1 \t Pin8:" + String(LG3_Result01) + "\t\tLG3_R01:" + String(get_LG3_Result01()));
  delayMicroseconds(10);

  //Logic Gate #3 INPUT: 10
  digitalWrite(IC14_Pin9, 1);
  digitalWrite(IC14_Pin10, 0);
  delayMicroseconds(10);
  IC_pin8 = digitalRead(IC14_Pin8);
  LG3_Result10 = IC_pin8;
  Serial.println("Logic Gate3: \t Pin9:1 \t Pin10:0 \t Pin8:" + String(LG3_Result10) + "\t\tLG3_R10:" + String(get_LG3_Result10()));
  delayMicroseconds(10);

  //Logic Gate #3 INPUT: 11
  digitalWrite(IC14_Pin9, 1);
  digitalWrite(IC14_Pin10, 1);
  delayMicroseconds(10);
  IC_pin8 = digitalRead(IC14_Pin8);
  LG3_Result11 = IC_pin8;
  Serial.println("Logic Gate3: \t Pin9:1 \t Pin10:1 \t Pin8:" + String(LG3_Result11) + "\t\tLG3_R11:" + String(get_LG3_Result11()));
  delayMicroseconds(10);
}

void test_LogicGate2() {
  bool IC_pin6 = 0;

  Serial.print("\n");

  //Logic Gate #2 INPUT: 00
  digitalWrite(IC14_Pin4, 0);
  digitalWrite(IC14_Pin5, 0);
  delayMicroseconds(10);
  IC_pin6 = digitalRead(IC14_Pin6);
  LG2_Result00 = IC_pin6;
  Serial.println("Logic Gate2: \t Pin4:0 \t Pin5:0 \t Pin6:" + String(LG2_Result00) + "\t\tLG2_R00:" + String(get_LG2_Result00()));
  delayMicroseconds(10);

  //Logic Gate #2 INPUT: 01
  digitalWrite(IC14_Pin4, 0);
  digitalWrite(IC14_Pin5, 1);
  delayMicroseconds(10);
  IC_pin6 = digitalRead(IC14_Pin6);
  LG2_Result01 = IC_pin6;
  Serial.println("Logic Gate2: \t Pin4:0 \t Pin5:1 \t Pin6:" + String(LG2_Result01) + "\t\tLG2_R01:" + String(get_LG2_Result01()));
  delayMicroseconds(10);

  //Logic Gate #2 INPUT: 10
  digitalWrite(IC14_Pin4, 1);
  digitalWrite(IC14_Pin5, 0);
  delayMicroseconds(10);
  IC_pin6 = digitalRead(IC14_Pin6);
  LG2_Result10 = IC_pin6;
  Serial.println("Logic Gate2: \t Pin4:1 \t Pin5:0 \t Pin6:" + String(LG2_Result10) + "\t\tLG2_R10:" + String(get_LG2_Result10()));
  delayMicroseconds(10);

  //Logic Gate #2 INPUT: 11
  digitalWrite(IC14_Pin4, 1);
  digitalWrite(IC14_Pin5, 1);
  delayMicroseconds(10);
  IC_pin6 = digitalRead(IC14_Pin6);
  LG2_Result11 = IC_pin6;
  Serial.println("Logic Gate2: \t Pin4:1 \t Pin5:1 \t Pin6:" + String(LG2_Result11) + "\t\tLG2_R11:" + String(get_LG2_Result11()));
  delayMicroseconds(10);
}

void test_LogicGate1() {
  bool IC_pin3 = 0;

  Serial.print("\n");

  //Logic Gate #1 INPUT: 00
  digitalWrite(IC14_Pin1, 0);
  digitalWrite(IC14_Pin2, 0);
  delayMicroseconds(10);
  IC_pin3 = digitalRead(IC14_Pin3);
  LG1_Result00 = IC_pin3;
  Serial.println("Logic Gate1: \t Pin1:0 \t Pin2:0 \t Pin3:" + String(LG1_Result00) + "\t\tLG1_R00:" + String(get_LG1_Result00()));
  delayMicroseconds(10);

  //Logic Gate #1 INPUT: 01
  digitalWrite(IC14_Pin1, 0);
  digitalWrite(IC14_Pin2, 1);
  delayMicroseconds(10);
  IC_pin3 = digitalRead(IC14_Pin3);
  LG1_Result01 = IC_pin3;
  Serial.println("Logic Gate1: \t Pin1:0 \t Pin2:1 \t Pin3:" + String(LG1_Result01) + "\t\tLG1_R01:" + String(get_LG1_Result01()));
  delayMicroseconds(10);

  //Logic Gate #1 INPUT: 10
  digitalWrite(IC14_Pin1, 1);
  digitalWrite(IC14_Pin2, 0);
  delayMicroseconds(10);
  IC_pin3 = digitalRead(IC14_Pin3);
  LG1_Result10 = IC_pin3;
  Serial.println("Logic Gate1: \t Pin1:1 \t Pin2:0 \t Pin3:" + String(LG1_Result10) + "\t\tLG1_R10:" + String(get_LG1_Result10()));
  delayMicroseconds(10);

  //Logic Gate #1 INPUT: 11
  digitalWrite(IC14_Pin1, 1);
  digitalWrite(IC14_Pin2, 1);
  delayMicroseconds(10);
  IC_pin3 = digitalRead(IC14_Pin3);
  LG1_Result11 = IC_pin3;
  Serial.println("Logic Gate1: \t Pin1:1 \t Pin2:1 \t Pin3:" + String(LG1_Result11) + "\t\tLG1_R11:" + String(get_LG1_Result11()));
  delayMicroseconds(10);
}

//Return Result Logic Gate #1
bool get_LG1_Result00() {
  return LG1_Result00;
}
bool get_LG1_Result01() {
  return LG1_Result01;
}
bool get_LG1_Result10() {
  return LG1_Result10;
}
bool get_LG1_Result11() {
  return LG1_Result11;
}

//Return Result Logic Gate #2
bool get_LG2_Result00() {
  return LG2_Result00;
}
bool get_LG2_Result01() {
  return LG2_Result01;
}
bool get_LG2_Result10() {
  return LG2_Result10;
}
bool get_LG2_Result11() {
  return LG2_Result11;
}

//Return Result Logic Gate #3
bool get_LG3_Result00() {
  return LG3_Result00;
}
bool get_LG3_Result01() {
  return LG3_Result01;
}
bool get_LG3_Result10() {
  return LG3_Result10;
}
bool get_LG3_Result11() {
  return LG3_Result11;
}

//Return Result Logic Gate #4
bool get_LG4_Result00() {
  return LG4_Result00;
}
bool get_LG4_Result01() {
  return LG4_Result01;
}
bool get_LG4_Result10() {
  return LG4_Result10;
}
bool get_LG4_Result11() {
  return LG4_Result11;
}
