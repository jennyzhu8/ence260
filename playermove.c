// Move player around the board. //

#include "system.h"
#include "navswitch.h"
#include "pio.h"
#include "playermove.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"


static tinygl_point_t player;
static tinygl_point_t playerlast;


void playerstart(void)
{
    // set player to start position
    player.x = 2;
    player.y = 6;
}


void playerdisp(void)
{
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
    
    while (1) {
        tinygl_update();
        playerdisp();
        navswitch_update();
        playermove();
    }
}
*/

