#ifndef PLAYERMOVE_H
#define PLAYERMOVE_H

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"

// define start position
void playerstart(void);

// display player position
void playerdisp(void);

// change player position
int playermove(void);

// check if player has hit wall
void hitwall(int array[5][27], int window);

// display end game message
void gameover(void);

#endif
