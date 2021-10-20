/** File:   Level.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   12 OCT 2021
    Descr:  Maze layout update support
*/

#ifndef MAZE_H
#define MAZE_H

#include "system.h"
#include "pacer.h"
#include "ledmat.h"
#include "display.h"
#include "tinygl.h"

// Draw segment of maze layout on LED screen
void draw_array(int maze_array[5][33], int x_window);

#endif
