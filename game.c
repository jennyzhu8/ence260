/** File:   game.c
    Author: J. ZHU (jzh208), G. ROSEMERGY (gro66)
    Date:   21 OCT 2021
    Descr:  implementation of MAZERUNNER game
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

// Define variables
#define PACER_RATE 500
#define MESSAGE_RATE 25
#define EASY 1500
#define MEDIUM 1000
#define HARD 500
#define MAX_MAZE_SPEED 450
#define WINDOW_LENGTH 26

// main game loop
int main(void) {
    // Initialise system, pacer, navigation switch and tinygl module
    system_init();
    navswitch_init();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    pacer_init (PACER_RATE);

    // Initialise maze layout as a 5x33 array
    int maze_array[5][33] = {
      {0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
      {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
      {0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1},
      {0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1},
      {0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
    };

    // Main while loop
    while (1) {
      // Use the main menu to choose maze speed depending on desired level
      uint16_t maze_speed = 0; // Set intial maze speed to 0
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

      // Initialise player starting position
      tinygl_clear();
      playerstart();
      int playerdead = 0;
      int x_window = 0;
      uint16_t x_window_tick = 0;

      // Player and maze are displayed and game begins
      while (playerdead == 0) {

        // Update player position
        tinygl_update();
        playerdisp();
        navswitch_update();
        playerdead = playermove();
        hitwall(maze_array, x_window); // If player hits wall, player is pushed back

        // Update maze position
        tinygl_update();
        x_window_tick++;
        draw_array(maze_array, x_window);

        // Times the updates of the maze postion based on number of times through the while loop
        if (x_window_tick >= maze_speed) {
          x_window++;
          x_window_tick = 0;
          // Increase maze speed as player continues
          if (maze_speed > MAX_MAZE_SPEED) {
              maze_speed -= maze_speed / 50;
          }
        }
        // Maze loops back to beginning once end of maze layout is reached
        if (x_window > WINDOW_LENGTH) {
          x_window = 0;
        }
      }
      // Clear game screen and display game over sequence
      tinygl_clear();
      gameover();
      /*
      gameover() function ends when button is pressed; therefore, ending one
      cycle of the main while loop and returning back to the main menu again.
      */
    }
}
