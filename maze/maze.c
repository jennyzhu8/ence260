// Assignment Maze Game
#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "ledmat.h"

/*defining game levels
typedef enum {
  EASY,
  MEDIUM,
  HARD
} level_t;
*/

/*map
static const uint8_t bitmap[] =
{
    0x41, 0x49, 0x48, 0x9, 0x9
    //0x30, 0x80, 0x00, 0x80, 0x30

}; */

// player chooses level from menu

int main(void) {
  uint16_t pattern = 0x41;
  uint16_t new_pattern;
  uint8_t col = 1;
  ledmat_init();
  system_init();
  pacer_init(1);
  while (1) {
    pacer_wait();
    if (new_pattern < (pattern<<6)) {
      ledmat_display_column(pattern, col);
      new_pattern = (pattern<<1);
    } else {
      new_pattern = pattern;
    }
  }
}


  /* TODO: Initialise tinygl. */
  /*
  uint8_t message_rate;
  level_t level;
  tinygl_init(PACER_RATE);
  tinygl_font_set(&font5x7_1);
  tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

  if (level == EASY) {
    message_rate = 10;
  } else if (level == MEDIUM) {
    message_rate = 20;
  } else if (level == HARD) {
    message_rate = 30;
  }
  tinygl_text_speed_set(message_rate);


}
*/
