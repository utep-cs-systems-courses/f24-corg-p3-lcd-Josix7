#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "notes.h"
#include "statemachines.h"
#include "led.h"

void buzzer_init() {
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) {
  CCR0 = cycles; 
  CCR1 = cycles >> 1;	
}

void playTune(const int *notes, const int*tempo, int noteAmt) {
  for(int i = 0; i < noteAmt; i++) {
    if((i % 2) == 0 ) {
      red_led_on();
    }
    else {
      green_led_on();
    }
    buzzer_set_period(1000000 / notes[i]);
    int dur = tempo[i];
    while(dur--) {
	__delay_cycles(10000);
    }
    leds_off();
  }
  // reset the buzzer state
  buzzer_set_period(0);                 // turn off buzzer CHANGED FROM bk TO 0
  leds_off();                           // endsure leds are off
}



void desertSong() {
  // Notes for the Desert Song (simple rising and falling pattern)
  const int notes[] = {E3, F3, G3, A3, G3, F3, E3, D3, C3, D3, E3};

  // Tempo for each note (longer durations for a reflective feel)
  const int tempo[] = {800, 800, 600, 600, 800, 800, 600, 600, 800, 800, 1000};

  // Calculate the number of notes
  int noteAmt = sizeof(notes) / sizeof(notes[0]);

  // Play the song
  playTune(notes, tempo, noteAmt);

  // Reset the buzzer state
  buzzer_set_period(0); // Turn off the buzzer
}
void californiaSong() {
  // Notes for the California Song (bright and upbeat melody)
  const int notes[] = {C4, E4, G4, A4, G4, E4, F4, G4, A4, C5, G4, E4};

  // Tempo for each note (moderate durations for a relaxed feel)
  const int tempo[] = {600, 600, 600, 800, 600, 600, 600, 600, 800, 1000, 600, 600};

  // Calculate the number of notes
  int noteAmt = sizeof(notes) / sizeof(notes[0]);

  // Play the song
  playTune(notes, tempo, noteAmt);

  // Reset the buzzer state
  buzzer_set_period(0); // Turn off the buzzer
}
void coldSong() {
  // Notes for the Cold Song (descending icy melody)
  const int notes[] = {G5, F5, E5, D5, C5, D5, E5, F5, G5};

  // Tempo for each note (longer durations for a frosty feel)
  const int tempo[] = {1000, 800, 600, 600, 1000, 600, 800, 600, 1200};

  // Calculate the number of notes
  int noteAmt = sizeof(notes) / sizeof(notes[0]);

  // Play the song
  playTune(notes, tempo, noteAmt);

  // Reset the buzzer state
  buzzer_set_period(0); // Turn off the buzzer
}
void twinkleTwinkle() {
  // Define the notes for Twinkle Twinkle
  const int notes[] = {C4, C4, G4, G4, A4, A4, G4, F4, F4, E4, E4, D4, D4, C4};

  // Define the tempo for each note
  const int tempo[] = {500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000};

  // Calculate the number of notes
  int noteAmt = sizeof(notes) / sizeof(notes[0]);

  // Play the song
  playTune(notes, tempo, noteAmt);

  // Reset the buzzer state
  buzzer_set_period(0); // Turn off the buzzer
}
