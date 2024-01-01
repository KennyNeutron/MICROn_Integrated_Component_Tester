//Screen: Test IC 74LS83
//Screen ID: 0x1710

bool disp_74LS83_TestResult_init = false;
bool ICtest_74LS83_done = false;


void disp_74LS83_TestResult() {
  if (!disp_74LS83_TestResult_init) {
    disp_74LS83_TestResult_INIT();
  }
}

void disp_74LS83_TestResult_INIT() {
  Serial.println("74LS83 Test Result");

  bad_ic=false;
  for(int a=0; a<16; a++){
    Serial.println("SUM["+String(a)+"]:"+String(Add_Sum[a]));
    if(Add_Sum[a]!=(a*2)){
      bad_ic=true;
    }
  }

  tft.Fill_Screen(BLACK);

  File bmp_file;
  bmp_file = SD.open(file_name[0]);
  draw_bmp_picture(bmp_file, 10, 5);
  bmp_file.close();

  display_TitleBar("Integrated Circuit TESTER", "74LS83 TEST RESULT");

  //REPORT MESSAGE
  if (bad_ic) {
    tft.Set_Draw_color(RED);
    tft.Fill_Round_Rectangle(390, 150, 660, 210, 12);
    tft.Set_Draw_color(WHITE);
    tft.Draw_Round_Rectangle(390, 150, 660, 210, 12);
    show_string("BAD IC", 420, 160, 6, WHITE, RED, 0);
  } else {
    bad_ic = false;
    tft.Set_Draw_color(GREEN);
    tft.Fill_Round_Rectangle(390, 150, 660, 210, 12);
    tft.Set_Draw_color(WHITE);
    tft.Draw_Round_Rectangle(390, 150, 660, 210, 12);
    show_string("GOOD IC", 400, 160, 6, BLACK, GREEN, 0);
  }



  //Truth Table Button
  print_button_TruthTable();


  //IC Details
  print_button_ICDetails();


  //Test Another IC
  print_button_TestAnotherIC();

  //TEST report
  print_button_TestReport();


  bmp_file = SD.open(file_name[16]);
  draw_bmp_picture(bmp_file, 50, 110);
  bmp_file.close();

  disp_74LS83_TestResult_init = true;
}