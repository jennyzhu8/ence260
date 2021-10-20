/** File:   Level.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   12 OCT 2021
    Descr:  Player movement module
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

/** Return non-zero if button pressed.  */
int button_pressed_p (void)
{
    return (PIND & (1<<7));
}


static tinygl_point_t player;
static tinygl_point_t playerlast;

void playerstart(void) {
    // set player to start position
    player.x = 2;
    player.y = 0;
}

void playerdisp(void) {
    // turn on led at player position
    tinygl_draw_point(playerlast, 0);
    tinygl_draw_point(player, 1);
}

int playermove(void)
{
    // record previous position
    playerlast.x = player.x;
    playerlast.y = player.y;
    int playerdead = 0;

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

    if (player.y < 0) {
        playerdead = 1;
        tinygl_clear();
    }
    return playerdead;
}

void hitwall(int array[5][33], int window)
{
    if (array[player.x][player.y + window]) {
        player.y--;
    }
}

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
