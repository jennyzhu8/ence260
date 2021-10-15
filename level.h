#ifndef LEVEL_H
#define LEVEL_H

#include "system.h"
#include "navswitch.h"
#include "pio.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "pacer.h"


// display level options
void display_level (char mode);

// choose level of difficulty
uint8_t chooselevel(void);

#endif
