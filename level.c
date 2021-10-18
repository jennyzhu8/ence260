/** File:   Level.c
    Author: J. ZHU, G. ROSEMERGY
    Date:   12 OCT 2021
    Descr:  Choose difficulty level (speed of maze)
*/

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "pacer.h"


static char message[] = "EMH";
static uint16_t index = 0;

void display_level (char mode)
{
    char buffer[2];

    buffer[0] = mode;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

uint16_t chooselevel(void) {

    pacer_wait ();
    tinygl_update ();
    navswitch_update();

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
    char mode = message[index];
    display_level (mode);

    /*
    if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
        if (index == 0) {
          freq = EASY;
        } else if (index == 1) {
          freq = MEDIUM;
        } else if (index == 2) {
          freq = HARD;
        }
    }
    */
    return index;
}
