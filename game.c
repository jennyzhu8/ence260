#include "system.h"
#include "playermove.h"
#include "navswitch.h"
#include "pio.h"

int main (void)
{
    system_init ();
    navswitch_init();

    playerstart();
    playerdisp();

    while (1)
    {

        navswitch_update();
        playermove();
        if (loops == 1) {
            playerdisp();
            loops = 2;
        } else if (loops == 2) {
            mapdisp();
            loops = 1;
        }

    }
}
