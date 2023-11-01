//Screen: TEST SCREEN
//Screen ID: 0xFFFF

bool testScreen_init = false;

void testScreen() {
  if (!testScreen_init) {
    testScreen_INIT();
  }
}

void testScreen_INIT() {

  testScreen_init = true;
}


