#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"


#define PACER_RATE 500
#define MESSAGE_RATE 10

int main (void)
{
    system_init();

    /* TODO: Initialise tinygl. */
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    /* TODO: Set the message using tinygl_text().  */
    tinygl_text("Jenny is the boss");


    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();

        /* TODO: Call the tinygl update function. */
        tinygl_update();


    }
    return 0;
}

//byte image[5][27] = {
  {1,0,0,1,1},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,1,1,1,0},
  {0,0,0,0,0  {0,0,0,0,0},
  {1,1,0,1,1},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {1,0,1,0,1},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {1,1,1,1,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {1,0,1,1,1},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,1,0,1,1},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {1,1,1,1,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {1,0,1,1,1},
  {0,0,0,0,0},
  {0,0,0,0,0},
}};