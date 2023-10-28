//Button Displays


//########################## TEST BUTTON ##############################
void print_button_test() {
  //TEST Button
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
  show_string("TEST", CENTER, 390, 4, BLACK, GREEN, 0);
}

void print_button_test_pressed() {
  tft.Set_Draw_color(BLUE);
  tft.Fill_Round_Rectangle(320, 380, 475, 430, 9);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(320, 380, 475, 430, 9);
  show_string("TEST", CENTER, 390, 4, WHITE, BLUE, 0);
}
//#####################################################################


//########################## TRUTH TABLE BUTTON ##############################
void print_button_TruthTable() {
  //Truth Table Button
  tft.Set_Draw_color(CYAN);
  tft.Fill_Round_Rectangle(290, 340, 510, 380, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(290, 340, 510, 380, 6);
  show_string("TRUTH Table", CENTER, 350, 3, BLACK, CYAN, 0);
}

void print_button_TruthTable_pressed() {
  //Truth Table Button
  tft.Set_Draw_color(BLUE);
  tft.Fill_Round_Rectangle(290, 340, 510, 380, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(290, 340, 510, 380, 6);
  show_string("TRUTH Table", CENTER, 350, 3, WHITE, BLUE, 0);
}

//############################################################################


//########################## IC DETAILS BUTTON ##############################
void print_button_ICDetails() {
  //IC Details
  tft.Set_Draw_color(CYAN);
  tft.Fill_Round_Rectangle(590, 340, 790, 380, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 340, 790, 380, 6);
  show_string("IC Details", 600, 350, 3, BLACK, CYAN, 0);
}

void print_button_ICDetails_pressed() {
  //IC Details
  tft.Set_Draw_color(BLUE);
  tft.Fill_Round_Rectangle(590, 340, 790, 380, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 340, 790, 380, 6);
  show_string("IC Details", 600, 350, 3, WHITE, BLUE, 0);
}
//###########################################################################


//########################## TEST REPORT BUTTON ##############################
void print_button_TestReport() {
  //TEST report
  tft.Set_Draw_color(MAGENTA);
  tft.Fill_Round_Rectangle(590, 400, 790, 440, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 400, 790, 440, 6);
  show_string("VIEW TEST REPORT", 595, 415, 2, BLACK, MAGENTA, 0);
}

void print_button_TestReport_pressed() {
  //TEST report
  tft.Set_Draw_color(BLUE);
  tft.Fill_Round_Rectangle(590, 400, 790, 440, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(590, 400, 790, 440, 6);
  show_string("VIEW TEST REPORT", 595, 415, 2, WHITE, BLUE, 0);
}
//############################################################################

//########################## TEST ANOTHER IC BUTTON ##############################
void print_button_TestAnotherIC() {
  //Test Another IC
  tft.Set_Draw_color(GREEN);
  tft.Fill_Round_Rectangle(290, 400, 510, 440, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(290, 400, 510, 440, 6);
  show_string("TEST ANOTHER IC", 310, 415, 2, BLACK, GREEN, 0);
}

void print_button_TestAnotherIC_pressed() {
  //Test Another IC
  tft.Set_Draw_color(BLUE);
  tft.Fill_Round_Rectangle(290, 400, 510, 440, 6);
  tft.Set_Draw_color(WHITE);
  tft.Draw_Round_Rectangle(290, 400, 510, 440, 6);
  show_string("TEST ANOTHER IC", 310, 415, 2, WHITE, BLUE, 0);
}
//################################################################################