/** File:   Level.c
    Author: J. ZHU (jzh208), G. ROSEMERGY (gro66)
    Date:   12 OCT 2021
    Descr:  Player movement and position module
*/

#include "system.h"
#include "navswitch.h"
#include "playermove.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "pacer.h"
#include "button.h"
#include "pio.h"

#define BUTTON_PIO PIO_DEFINE (PORT_D, 7)
static tinygl_point_t player;
static tinygl_point_t playerlast;

// Initialises player starting position at beginning of the game
void playerstart(void) {
    // set player to start position
    player.x = 2;
    player.y = 0;
}

// Updates and displays position of player on LED screen
void playerdisp(void) {
    // turn on led at player position
    tinygl_draw_point(playerlast, 0);
    tinygl_draw_point(player, 1);
}

// Updates player position according to nav switch movement
int playermove(void)
{
    // Record player's previous position
    playerlast.x = player.x;
    playerlast.y = player.y;
    int playerdead = 0;

    // Changes player's position on screen for each direction
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        // move right
        if (player.y > 0) {
            player.y--;
        }
        //else playerrow stays the same
    } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        // move left
        if (player.y < 6) {
            player.y++;
        }
        //else playerrow stays the same
    } else if (navswitch_push_event_p (NAVSWITCH_EAST)) {
        // move down
        if (player.x == 4) {
            player.x = 0;
        } else {
            player.x++;
        }
    } else if (navswitch_push_event_p (NAVSWITCH_WEST)) {
        // move up
        if (player.x == 0) {
            player.x = 4;
        } else {
            player.x--;
        }
    }

    // Check if player is being pushed off screen by wall; therefore, game over
    if (player.y < 0) {
        playerdead = 1;
        tinygl_clear();
    }
    return playerdead;
}

// Player position minus 1 each time wall pushes player back
void hitwall(int array[5][33], int window)
{
    if (array[player.x][player.y + window]) {
        player.y--;
    }
}

// Game over sequence when player is pushed off screen
void gameover(void)
{
    button_init();
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text("GAME OVER");
    while (1) {
        pacer_wait();
        tinygl_update();
        if (button_pressed_p()) {
          break;
        }
    }
}

// Return non-zero if button pressed; returns to main menu
int button_pressed_p (void)
{
    return (PIND & (1<<7));
}
