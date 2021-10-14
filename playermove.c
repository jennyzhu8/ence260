// Move player around the board. //

#include "system.h"
#include "navswitch.h"
#include "pio.h"

void playerdisp(void)
{
    // turn on led at player position
    pio_output_low(playercol);
    pio_output_low(playerrow);
    //do we need to make sure that all the other leds are off? 
}

void playerstart(void)
{
    // set player to start position
    pio_t playercol = 3;
    pio_t playerrow = 7;
}

void playermove(void)
{
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        // move right
        //if playerrow++ != (lit led in map)
        playerrow++;
        //else playerrow stays the same

    } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        // move left
        //if playerrow-- != (lit led in map)
        playerrow--;
        //else playerrow stays the same

    } else if (navswitch_push_event_p (NAVSWITCH_EAST)) {
        // move down
        if (playercol == 5) {
            playercol = 1;
        } else {
            playercol++;
        }

    } else if (navswitch_push_event_p (NAVSWITCH_WEST)) {
        // move up
        if (playercol == 1) {
            playercol = 5;
        } else {
            playercol--;
        }
    }
}


