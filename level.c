/** File:   Level.c
    Author: J. ZHU (jzh208), G. ROSEMERGY (gro66)
    Date:   12 OCT 2021
    Descr:  Choose difficulty level (speed of maze) module
*/

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "pacer.h"

// Initialise static variables
static char message[] = "EMH";
static uint16_t index = 0;

// Displays level selection menu
void display_level (char mode) {
    char buffer[2];
    buffer[0] = mode;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

// Returns index of level chosen according to navigation switch selection
uint16_t chooselevel(void) {
    pacer_wait ();
    tinygl_update ();
    navswitch_update();

    // Nav switch can be pushed left and right to scroll through levels
    if (navswitch_push_event_p (NAVSWITCH_EAST)) {
        if (index >= 2) {
            index = 0;
        } else {
            index++;
        }
    } else if (navswitch_push_event_p (NAVSWITCH_WEST)) {
        if (index == 0) {
            index = 2;
        } else {
            index--;
        }
    }

    // Chooses from E, M, or H and the respective index
    char mode = message[index];
    display_level (mode);
    return index;
}
