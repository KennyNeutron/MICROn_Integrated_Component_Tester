/*
    Electronic Component Tester on TFT Display
    Test IC16 Functions
    Version 1.0.0

    by: MICROn Technology

    Environment: Arduino Mega 2560

    Date Started: 11-01-2023
    Date Finished: N/A
*/

uint8_t BCD_A = IC16_Pin7;
uint8_t BCD_B = IC16_Pin1;
uint8_t BCD_C = IC16_Pin2;
uint8_t BCD_D = IC16_Pin6;

uint8_t BCD_outA = IC16_Pin13;
uint8_t BCD_outB = IC16_Pin12;
uint8_t BCD_outC = IC16_Pin11;
uint8_t BCD_outD = IC16_Pin10;
uint8_t BCD_outE = IC16_Pin9;
uint8_t BCD_outF = IC16_Pin15;
uint8_t BCD_outG = IC16_Pin14;

uint8_t BCD_IN = 0x00;



void IC16_74LS4X_pinMode_init() {
  pinMode(IC16_Pin3, INPUT);  //floating
  pinMode(IC16_Pin4, INPUT);  //floating
  pinMode(IC16_Pin5, INPUT);  //floating

  pinMode(BCD_A, OUTPUT);
  pinMode(BCD_B, OUTPUT);
  pinMode(BCD_C, OUTPUT);
  pinMode(BCD_D, OUTPUT);

  pinMode(BCD_outA, INPUT);
  pinMode(BCD_outB, INPUT);
  pinMode(BCD_outC, INPUT);
  pinMode(BCD_outD, INPUT);
  pinMode(BCD_outE, INPUT);
  pinMode(BCD_outF, INPUT);
  pinMode(BCD_outG, INPUT);

  pinMode(IC16_Pin8, OUTPUT);   //GND
  pinMode(IC16_Pin16, OUTPUT);  //VCC


  digitalWrite(BCD_A, 0);
  digitalWrite(BCD_B, 0);
  digitalWrite(BCD_C, 0);
  digitalWrite(BCD_D, 0);
  digitalWrite(IC16_Pin8, 0);   //GND
  digitalWrite(IC16_Pin16, 1);  //VCC
  Serial.println("IC16 POWER ON!");
}

void test_IC16_74LS4X() {
  reset_BCD_7Segment_Out();
  Serial.print("\n############################################################################\n");
  Serial.print("|BCD Input |\t| A |\t| B |\t| C |\t| D |\t| E |\t| F |\t| G |\t|OUTPUT");

  Serial.print("\n|   0000   |\t");
  read_BCD_7Segment_Out(0x00);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[0], BIN);
  Serial.print("\t\t0<--->" + String(BCD_7Segment_Out[0]));

  Serial.print("\n|   0001   |\t");
  read_BCD_7Segment_Out(0x01);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[1], BIN);
  Serial.print("\t\t1<--->" + String(BCD_7Segment_Out[1]));

  Serial.print("\n|   0010   |\t");
  read_BCD_7Segment_Out(0x02);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[2], BIN);
  Serial.print("\t\t2<--->" + String(BCD_7Segment_Out[2]));

  Serial.print("\n|   0011   |\t");
  read_BCD_7Segment_Out(0x03);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[3], BIN);
  Serial.print("\t\t3<--->" + String(BCD_7Segment_Out[3]));

  Serial.print("\n|   0100   |\t");
  read_BCD_7Segment_Out(0x04);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[4], BIN);
  Serial.print("\t\t4<--->" + String(BCD_7Segment_Out[4]));

  Serial.print("\n|   0101   |\t");
  read_BCD_7Segment_Out(0x05);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[4], BIN);
  Serial.print("\t\t5<--->" + String(BCD_7Segment_Out[5]));

  Serial.print("\n|   0110   |\t");
  read_BCD_7Segment_Out(0x06);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[6], BIN);
  Serial.print("\t\t6<--->" + String(BCD_7Segment_Out[6]));

  Serial.print("\n|   0111   |\t");
  read_BCD_7Segment_Out(0x07);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[7], BIN);
  Serial.print("\t\t7<--->" + String(BCD_7Segment_Out[7]));

  Serial.print("\n|   1000   |\t");
  read_BCD_7Segment_Out(0x08);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[7], BIN);
  Serial.print("\t\t8<--->" + String(BCD_7Segment_Out[8]));

  Serial.print("\n|   1001   |\t");
  read_BCD_7Segment_Out(0x09);
  Serial.print("|");
  Serial.print(BCD_7Segment_Out[9], BIN);
  Serial.print("\t\t9<--->" + String(BCD_7Segment_Out[9]));

  Serial.print("\n############################################################################\n");
}

void read_BCD_7Segment_Out(uint8_t iter) {
  digitalWrite(BCD_A, bitRead(iter, 0));
  digitalWrite(BCD_B, bitRead(iter, 1));
  digitalWrite(BCD_C, bitRead(iter, 2));
  digitalWrite(BCD_D, bitRead(iter, 3));
  delayMicroseconds(100);
  uint8_t b = 6;
  for (uint8_t c = 0; c < 7; c++) {
    bitWrite(BCD_7Segment_Out[iter], b, read_BCD_out(c));
    Serial.print("| " + String(read_BCD_out(c)) + " |\t");
    //Serial.println("TestPin:" + String(c) + "\tOUT:" + String(read_BCD_out(c)) + "\tBCDseg[" + String(iter) + "]=" + String(BCD_7Segment_Out[iter]));
    b--;
  }
}

bool read_BCD_out(uint8_t BCD_segment) {
  switch (BCD_segment) {
    case 0:
      return digitalRead(BCD_outA);
      break;
    case 1:
      return digitalRead(BCD_outB);
      break;
    case 2:
      return digitalRead(BCD_outC);
      break;
    case 3:
      return digitalRead(BCD_outD);
      break;
    case 4:
      return digitalRead(BCD_outE);
      break;
    case 5:
      return digitalRead(BCD_outF);
      break;
    case 6:
      return digitalRead(BCD_outG);
      break;
    default:
      return false;
  }
}

void reset_BCD_7Segment_Out() {
  for (uint8_t a = 0; a < 16; a++) {
    BCD_7Segment_Out[a] = 0x00;
  }
}