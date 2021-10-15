// Choose difficulty level (speed of maze)

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "display.h"
#include "font.h"
#include "pacer.h"

#define EASY 1
#define MEDIUM 2
#define HARD 3

static uint8_t freq = 0;
static char message[] = "EMH";
static uint16_t index = 0;

void display_level (char mode)
{
    char buffer[2];

    buffer[0] = mode;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

uint8_t chooselevel(void)
{

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
        if (index <= 0) {
            index = 2;
        } else {
            index--;
        }

    }

    if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
        switch (index) {
            case 0:
                freq = EASY;
                break;
            case 1:
                freq = MEDIUM;
                break;
            case 2:
                freq = HARD;
                break;
        }
    }
    
    char mode = message[index];
    display_level (mode);

    return freq;

}
