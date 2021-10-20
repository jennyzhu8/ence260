/** File:   Level.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   12 OCT 2021
    Descr:  Maze layout support
*/

#ifndef MAZE_H
#define MAZE_H

#include "system.h"
#include "pacer.h"
#include "ledmat.h"
#include "display.h"
#include "tinygl.h"

// draw maze array
void draw_array(int maze_array[5][33], int x_window);

#endif
