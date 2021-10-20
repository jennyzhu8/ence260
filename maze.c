/** File:   Level.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   12 OCT 2021
    Descr:  Maze layout module
*/

#include "system.h"
#include "pacer.h"
#include "ledmat.h"
#include "display.h"
#include "tinygl.h"


//Draws maze array according to maze shift
void draw_array(int maze_array[5][33], int x_window) {
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
