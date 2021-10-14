// Move player around the board. //

#include "system.h"
#include "navswitch.h"
#include "pio.h"

static uint16_t playerrow;
static uint16_t playercol;

void playerdisp(uint16_t playerrow, uint16_t playercol)
{
    // turn off all leds

    // turn on led at player position
    pio_t col = playercolled(playercol);
    pio_t row = playerrowled(playerrow);
    pio_output_low(col);
    pio_output_low(row);

}

void playerstart(void)
{
    // set player to start position
    uint16_t playercol = 3;
    uint16_t playerrow = 7;
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

pio_t playerrowled(uint16_t playerrow)
{
    pio_t playerrowled
    switch (row)
    {
        case 1:
            playerrowled = LEDMAT_ROW1_PIO;
            break;
        case 2:
            playerrowled = LEDMAT_ROW2_PIO;
            break;
        case 3:
            playerrowled = LEDMAT_ROW3_PIO;
            break;
        case 4:
            playerrowled = LEDMAT_ROW4_PIO;
            break;
        case 5:
            playerrowled = LEDMAT_ROW5_PIO;
            break;
        case 6:
            playerrowled = LEDMAT_ROW6_PIO;
            break;
        case 7:
            playerrowled = LEDMAT_ROW7_PIO;
            break;
    }
    return playerrowled;
}


pio_t playercolled(uint16_t playercol)
{
    pio_t playercolled
    switch (col)
    {
        case 1:
            playercolled = LEDMAT_COL1_PIO;
            break;
        case 2:
            playercolled = LEDMAT_COL2_PIO;
            break;
        case 3:
            playercolled = LEDMAT_COL3_PIO;
            break;
        case 4:
            playercolled = LEDMAT_COL4_PIO;
            break;
        case 5:
            playercolled = LEDMAT_COL5_PIO;
            break;
    }
    return playercolled;
}

