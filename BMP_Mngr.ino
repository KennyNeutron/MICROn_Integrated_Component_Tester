uint16_t read_16(File fp) {
  uint8_t low;
  uint16_t high;
  low = fp.read();
  high = fp.read();
  return (high << 8) | low;
}

uint32_t read_32(File fp) {
  uint16_t low;
  uint32_t high;
  low = read_16(fp);
  high = read_16(fp);
  return (high << 8) | low;
}

bool analysis_bpm_header(File fp) {
  if (read_16(fp) != 0x4D42) {
    return false;
  }
  //get bpm size
  read_32(fp);
  //get creator information
  read_32(fp);
  //get offset information
  bmp_offset = read_32(fp);
  //get DIB infomation
  read_32(fp);
  //get width and heigh information
  uint32_t bpm_width = read_32(fp);
  uint32_t bpm_heigh = read_32(fp);
  BMP_WIDTH = bpm_width;
  BMP_HEIGHT = bpm_heigh;

  if (read_16(fp) != 1) {
    return false;
  }
  read_16(fp);
  if (read_32(fp) != 0) {
    return false;
  }
  return true;
}


void draw_bmp_picture(File fp, uint16_t cursorX, uint16_t cursorY) {
  if (!fp) {
    tft.Set_Text_Back_colour(BLUE);
    tft.Set_Text_colour(WHITE);
    tft.Set_Text_Size(1);
    tft.Print_String("didnt find BMPimage!", 0, 10);
    while (1);
  }
  if (!analysis_bpm_header(fp)) {
    tft.Set_Text_Back_colour(BLUE);
    tft.Set_Text_colour(WHITE);
    tft.Set_Text_Size(1);
    tft.Print_String("bad bmp picture!", 0, 0);
    return;
  }

  PIXEL_NUMBER = BMP_WIDTH / 4;
  uint16_t i, j, k, l, m = 0;
  uint8_t bpm_data[PIXEL_NUMBER * 3] = { 0 };
  uint16_t bpm_color[PIXEL_NUMBER];
  fp.seek(bmp_offset);
  for (i = cursorY; i < BMP_HEIGHT + cursorY; i++) {
    for (j = 0; j < BMP_WIDTH / PIXEL_NUMBER; j++) {
      m = 0;
      fp.read(bpm_data, PIXEL_NUMBER * 3);
      for (k = 0; k < PIXEL_NUMBER; k++) {
        bpm_color[k] = tft.Color_To_565(bpm_data[m + 2], bpm_data[m + 1], bpm_data[m + 0]);
        m += 3;
      }
      for (l = 0; l < PIXEL_NUMBER; l++) {
        tft.Set_Draw_color(bpm_color[l]);
        tft.Draw_Pixel(j * PIXEL_NUMBER + l + cursorX, i);
      }
    }
  }
}