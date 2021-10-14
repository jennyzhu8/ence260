// Move player around the board. //

#include "system.h"
#include "navswitch.h"
#include "pio.h"

static uint16_t playerrow;
static uint16_t playercol;

void playerstart(void)
{
    // set player to start position
    playercol = 3;
    playerrow = 7;
}

pio_t playerrowled(uint16_t playerrow)
{
    pio_t playerrowled;
    switch (playerrow)
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
        default:
            playerrowled = LEDMAT_ROW7_PIO;
            break;
    }
    return playerrowled;
}


pio_t playercolled(uint16_t playercol)
{
    pio_t playercolled;
    switch (playercol)
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
        default:
            playercolled = LEDMAT_COL3_PIO;
            break;
    }
    return playercolled;
}

void playerdisp(uint16_t playerrow, uint16_t playercol)
{
    // turn off all leds

    // turn on led at player position
    pio_t col = playercolled(playercol);
    pio_t row = playerrowled(playerrow);
    pio_output_low(col);
    pio_output_low(row);

    for (uint16_t row = 1; row < 8; row++) {
        if (row != playerrow) {
            pio_output_high(playerrowled(row));
        }
    }

    for (uint16_t col = 1; col < 6; col++) {
        if (col != playercol) {
            pio_output_high(playercolled(col));
        }
    }

}



void playermove(void)
{
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        // move right
        //if playerrow-- != (lit led in map)
        playerrow--;
        //else playerrow stays the same

    } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        // move left
        //if playerrow++ != (lit led in map)
        playerrow++;
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


int main(void)
{
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
        playerdisp(playerrow, playercol);
        navswitch_update();
        playermove();
    }
}

