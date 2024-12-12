#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "song_images.h"

void next_state(int state) {
  leds_off();
  
  switch(state) {
  case 1:
    led_flash(5);
    leds_off();
    red_led_on();
    drawJoshuaTree(30, 30);
    californiaSong();
    leds_off();
    break;
  case 2:
    led_flash(3);
    leds_off();
    red_led_on();
    drawRockyMountains(30, 30);
    coldSong();
    leds_off();
    break;
  case 3:
    led_flash(2);
    leds_off();
    red_led_on();
    drawPyramids(30, 30);
    desertSong();
    leds_off();
    break;
  case 4:
    led_flash(1);
    leds_off();
    red_led_on();
    drawSpace(30, 30);
    twinkleTwinkle();
    leds_off();
    break;
  default:
    green_led_on();
    break;
  }
  // turn on the green led to indicate that the MSP ready for the next step.
  green_led_on();
  clearScreen(COLOR_WHITE); // Default to a blank screen

}
