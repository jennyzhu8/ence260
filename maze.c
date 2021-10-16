// Assignment Maze Game
#include "system.h"
#include "pacer.h"
#include "ledmat.h"
#include "display.h"
#include "tinygl.h"

//#define MAZE_SPEED_VALUE 1500

//Draws maze array according to maze shift
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

//Put maze shifting function back into this module

/*int main(void) {

  system_init();
  tinygl_init(100);

  int x_window = 0;
  uint16_t x_window_tick = 0;
  int maze_array[5][27] = {
  {0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
  {0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1},
  {0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1},
  {0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
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
}
*/
