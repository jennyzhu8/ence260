#include "system.h"
#include "navswitch.h"
#include "playermove.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "level.h"
#include "../fonts/font5x7_1.h"
#include "maze.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10
#define EASY 2000
#define MEDIUM 1500
#define HARD 1000

int main(void)
{
    system_init();
    navswitch_init();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);

    pacer_init (PACER_RATE);

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

    /*
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_HIGH);

    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_HIGH);
    */

    playerstart();

    int x_window = 0;
    uint16_t x_window_tick = 0;
    int maze_array[5][27] = {
    {0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
    {0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1},
    {0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1},
    {0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
    };

    //uint8_t loop = 1;
    while (1) {
      tinygl_update();
      playerdisp();
      navswitch_update();
      playermove();
      //loop = 2;
      tinygl_update();
      x_window_tick++;
      draw_array(maze_array, x_window);
      if (x_window_tick >= maze_speed) {
        x_window++;
        x_window_tick = 0;
      }
      //int num_rows = sizeof(maze_array[0]) / sizeof(maze_array[0][0]); //=27
      if (x_window >= 20) {
        x_window = 0;
        //x_window_tick = 0;
      }
      //loop = 1;
    }
}
