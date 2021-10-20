/** File:   Level.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   12 OCT 2021
    Descr:  Player movement support
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

// define start position
void playerstart(void);

// display player position
void playerdisp(void);

// change player position
int playermove(void);

// check if player has hit wall
void hitwall(int array[5][33], int window);

// display end game message
void gameover(void);

// checks if button pressed
int button_pressed_p (void);

#endif
