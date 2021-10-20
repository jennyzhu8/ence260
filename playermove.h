/** File:   Level.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   12 OCT 2021
    Descr:  Player movement and position support
*/

#ifndef PLAYERMOVE_H
#define PLAYERMOVE_H

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "button.h"
#include "pio.h"
#include "pacer.h"

// Initialise player start position
void playerstart(void);

// Display player position
void playerdisp(void);

// Change player position
int playermove(void);

// Check if player has hit wall; if so, player position -1
void hitwall(int array[5][33], int window);

// Display game end message
void gameover(void);

// Checks if button pressed to return to main menu
int button_pressed_p (void);

#endif
