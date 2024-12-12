#include "lcdutils.h"
#include "lcddraw.h"
#include "song_images.h"

void drawJoshuaTree(u_char colStart, u_char rowStart) {
  // Desert background
  fillRectangle(0, 0, screenWidth, screenHeight, COLOR_YELLOW);

  // Tree trunk
  fillRectangle(colStart + 10, rowStart + 50, 10, 30, COLOR_BROWN);

  // Tree foliage
  fillRectangle(colStart, rowStart + 40, 30, 20, COLOR_GREEN);

    drawString5x7(10, 10, "Joshua Tree", COLOR_BLACK, COLOR_YELLOW);

}

void drawRockyMountains(u_char colStart, u_char rowStart) {
  // Define the height of the grass and sky
  u_char grassHeight = 20;
  u_char skyHeight = 40;

  // Sky background
  fillRectangle(0, 0, screenWidth, skyHeight, COLOR_SKY_BLUE);

  // Draw mountains
  for (int i = 0; i < 3; i++) {
    int xStart = colStart + i * 40; // Adjust spacing between mountains
    for (int row = 0; row < 40; row++) {
      for (int col = -row; col <= row; col++) {
        drawPixel(xStart + col, rowStart + row, COLOR_GRAY);
      }
    }
  }

  // Grass background
  fillRectangle(0, rowStart + 40, screenWidth, grassHeight, COLOR_GREEN);
  drawString5x7(10, 10, "Rocky Mountains", COLOR_BLACK, COLOR_SKY_BLUE);

}

void drawPyramids(u_char colStart, u_char rowStart) {
  // Desert background
  fillRectangle(0, 0, screenWidth, screenHeight, COLOR_YELLOW);

  // Pyramids
  for (int row = 0; row < 40; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(colStart + col, rowStart + row, COLOR_BROWN);
      drawPixel(colStart + 50 + col, rowStart + row + 20, COLOR_BROWN);
    }
    drawString5x7(10, 10, "Pyramids", COLOR_BLACK, COLOR_YELLOW);

  }
}

void drawSpace(u_char colStart, u_char rowStart) {
  // Black background
  fillRectangle(0, 0, screenWidth, screenHeight, COLOR_BLACK);

  // Stars
  for (int i = 0; i < 50; i++) {
    u_char x = colStart + (rand() % screenWidth);
    u_char y = rowStart + (rand() % screenHeight);
    drawPixel(x, y, COLOR_WHITE);
  }
  drawString5x7(10, 10, "Space", COLOR_WHITE, COLOR_BLACK);

}
