/** File:   game.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   21 OCT 2021
    Descr:  implementation of maze game
*/

#include "system.h"
#include "navswitch.h"
#include "playermove.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "level.h"
#include "../fonts/font5x7_1.h"
#include "maze.h"
#include "button.h"
#include "pio.h"
#include "pacer.h"

#define PACER_RATE 500
#define MESSAGE_RATE 25
#define EASY 1500
#define MEDIUM 1000
#define HARD 500


int main(void)
{
    system_init();
    navswitch_init();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    pacer_init (PACER_RATE);

    int maze_array[5][33] = {
      {0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
      {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
      {0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1},
      {0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1},
      {0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
    };

    //
    while (1) {
      uint16_t maze_speed = 0;
      while (maze_speed == 0) {
          uint8_t index = chooselevel();
          if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
              if (index == 0) {
                maze_speed = EASY;
              } else if (index == 1) {
                maze_speed = MEDIUM;
              } else if (index == 2) {
                maze_speed = HARD;
              }
          }
      }
      tinygl_clear();


      playerstart();
      int playerdead = 0;
      int x_window = 0;
      uint16_t x_window_tick = 0;

      while (playerdead == 0) {

          // update player
          tinygl_update();
          playerdisp();
          navswitch_update();
          playerdead = playermove();
          hitwall(maze_array, x_window);

          // update maze
          tinygl_update();
          x_window_tick++;
          draw_array(maze_array, x_window);

          if (x_window_tick >= maze_speed) {
            x_window++;
            x_window_tick = 0;

            // increase maze speed as you play
            if (maze_speed > 450) {
                maze_speed -= maze_speed / 50;
            }

          }

          if (x_window > 26) {
              x_window = 0;
          }
      }

      tinygl_clear();
      gameover();

    }
}
