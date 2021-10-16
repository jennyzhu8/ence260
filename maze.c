// Assignment Maze Game
#include "system.h"
#include "pacer.h"
#include "ledmat.h"
#include "display.h"
#include "tinygl.h"

#define MAZE_SPEED_VALUE 1500

void draw_array(int maze_array[5][27], int x_window) {
  for (int col=0; col<5; col++) {
    tinygl_coord_t x = col;
    for (int row=x_window; row<x_window+7; row++) {
      tinygl_coord_t y = row - x_window;
      tinygl_point_t position = tinygl_point(x,y);
      uint8_t value = maze_array[col][row];
      tinygl_pixel_value_t pixel_value = value;
      tinygl_draw_point(position, pixel_value);
    }
  }
}
/*
int get_maze_array(void) {
  int maze_array[5][27] = {
  {1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0},
  {1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0},
  {1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0},
  {1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0},
  };
  return maze_array;
} */

/*int main(void) {

  system_init();
  tinygl_init(100);

  int x_window = 0;
  uint16_t x_window_tick = 0;
  int maze_array[5][27] = {
  {1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0},
  {1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0},
  {1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0},
  {1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0},
  };

  while(1) {
    tinygl_update();
    x_window_tick++;
    draw_array(maze_array, x_window);
    if (x_window_tick >= MAZE_SPEED_VALUE) {
      x_window++;
      x_window_tick = 0;
    }
    //int num_rows = sizeof(maze_array[0]) / sizeof(maze_array[0][0]); //=27
    if (x_window >= 20) {
      x_window = 0;
      x_window_tick = 0;
    }
  }
}*/
/*defining game levels
typedef enum {
  EASY,
  MEDIUM,
  HARD
} level_t;

//map
static const uint8_t bitmap[] =
{
    0x41, 0x49, 0x48, 0x9, 0x9
    //0x30, 0x80, 0x00, 0x80, 0x30

};

//player chooses level from menu

int main(void) {
  uint16_t pattern = 0x41;
  uint16_t new_pattern;
  uint8_t col = 1;
  ledmat_init();
  system_init();
  pacer_init(1);
  while (1) {
    pacer_wait();
    if (new_pattern < (pattern<<6)) {
      ledmat_display_column(pattern, col);
      new_pattern = (pattern<<1);
    } else {
      new_pattern = pattern;
    }
  }
}


  uint8_t message_rate;
  level_t level;
  tinygl_init(PACER_RATE);
  tinygl_font_set(&font5x7_1);
  tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

  if (level == EASY) {
    message_rate = 10;
  } else if (level == MEDIUM) {
    message_rate = 20;
  } else if (level == HARD) {
    message_rate = 30;
  }
  tinygl_text_speed_set(message_rate);


}
*/
