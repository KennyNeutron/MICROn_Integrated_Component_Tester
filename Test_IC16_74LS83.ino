/*
    Electronic Component Tester on TFT Display
    Test IC16 for 74LS83 Functions
    Version 1.0.0

    by: MICROn Technology

    Environment: Arduino Mega 2560

    Date Started: 11-17-2023
    Date Finished: N/A
*/

//INPUT A pinouts
uint8_t Add_A1 = IC16_Pin10;
uint8_t Add_A2 = IC16_Pin8;
uint8_t Add_A3 = IC16_Pin3;
uint8_t Add_A4 = IC16_Pin1;

//INPUT B pinouts
uint8_t Add_B1 = IC16_Pin11;
uint8_t Add_B2 = IC16_Pin7;
uint8_t Add_B3 = IC16_Pin4;
uint8_t Add_B4 = IC16_Pin16;

//Carry
uint8_t Add_Cin = IC16_Pin13;
uint8_t Add_Cout = IC16_Pin14;

//SUM Pinouts
uint8_t Add_S1 = IC16_Pin9;
uint8_t Add_S2 = IC16_Pin6;
uint8_t Add_S3 = IC16_Pin2;
uint8_t Add_S4 = IC16_Pin15;

uint8_t Add_Sum[16];




void IC16_74LS83_pinMode_init() {
  Serial.println("Test 74LS83 Initialize...");

  pinMode(IC16_Pin5, OUTPUT);   //VCC
  pinMode(IC16_Pin12, OUTPUT);  //GND

  pinMode(Add_A1, OUTPUT);
  pinMode(Add_A2, OUTPUT);
  pinMode(Add_A3, OUTPUT);
  pinMode(Add_A4, OUTPUT);

  pinMode(Add_B1, OUTPUT);
  pinMode(Add_B2, OUTPUT);
  pinMode(Add_B3, OUTPUT);
  pinMode(Add_B4, OUTPUT);

  pinMode(Add_S1, INPUT);
  pinMode(Add_S2, INPUT);
  pinMode(Add_S3, INPUT);
  pinMode(Add_S4, INPUT);

  pinMode(Add_Cin, OUTPUT);
  pinMode(Add_Cout, INPUT);

  //Initialize PinState
  digitalWrite(Add_A1, 0);
  digitalWrite(Add_A2, 0);
  digitalWrite(Add_A3, 0);
  digitalWrite(Add_A4, 0);

  digitalWrite(Add_B1, 0);
  digitalWrite(Add_B2, 0);
  digitalWrite(Add_B3, 0);
  digitalWrite(Add_B4, 0);

  digitalWrite(IC16_Pin5, 1);   //VCC
  digitalWrite(IC16_Pin12, 0);  //GND

  digitalWrite(Add_Cin, 0);
}

void test_74LS83() {
  Serial.println("test_74LS83 FUNCTION...");

  for (int i = 0; i <= 0x0F; i++) {
    test_74LS83_WriteInput(i, i, false);
  }
}

void test_74LS83_WriteInput(uint8_t InputA, uint8_t InputB, bool InputCin) {
  Serial.print("Input A:");
  Serial.print(bitRead(InputA, 3));
  Serial.print(bitRead(InputA, 2));
  Serial.print(bitRead(InputA, 1));
  Serial.print(bitRead(InputA, 0));
  Serial.print("\tInput B:");
  Serial.print(bitRead(InputB, 3));
  Serial.print(bitRead(InputB, 2));
  Serial.print(bitRead(InputB, 1));
  Serial.print(bitRead(InputB, 0));

  digitalWrite(Add_Cin, InputCin);

  digitalWrite(Add_A1, bitRead(InputA, 0));
  digitalWrite(Add_A2, bitRead(InputA, 1));
  digitalWrite(Add_A3, bitRead(InputA, 2));
  digitalWrite(Add_A4, bitRead(InputA, 3));


  digitalWrite(Add_B1, bitRead(InputB, 0));
  digitalWrite(Add_B2, bitRead(InputB, 1));
  digitalWrite(Add_B3, bitRead(InputB, 2));
  digitalWrite(Add_B4, bitRead(InputB, 3));


  Serial.print("\tSUM:");
  Serial.print(digitalRead(Add_S4));
  Serial.print(digitalRead(Add_S3));
  Serial.print(digitalRead(Add_S2));
  Serial.print(digitalRead(Add_S1));

  Serial.print("\tCarry:");
  Serial.print(digitalRead(Add_Cout));

  uint8_t Summ = 0;
  bitWrite(Summ, 3, digitalRead(Add_S4));
  bitWrite(Summ, 2, digitalRead(Add_S3));
  bitWrite(Summ, 1, digitalRead(Add_S2));
  bitWrite(Summ, 0, digitalRead(Add_S1));

  if (digitalRead(Add_Cout)) {
    Summ = Summ + 0x10;
  }

  Serial.println("\t| A:" + String(InputA) + "  +  B:" + String(InputB) + "\tSUM:" + String(Summ));
}
