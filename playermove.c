// Move player around the board. //

#include "system.h"
#include "navswitch.h"
#include "playermove.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"

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

void playermove(void)
{
    playerlast.x = player.x;
    playerlast.y = player.y;

    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        // move right
        //eventually change to if playerrow-- != (lit led in map), else if...
        if (player.y > 0) {
            player.y--;
        }
        //else playerrow stays the same
    } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        // move left
        //change to if playerrow++ != (lit led in map), else if...
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
}

/*
int main(void)
{
    system_init();
    navswitch_init();
    tinygl_init(100);
    playerstart();

    while (1) {
        tinygl_update();
        playerdisp();
        navswitch_update();
        playermove();
    }
}
*/
