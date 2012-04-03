#include <Arduino.h>
#include <searduino.h>
#include <messageHandler.h>

void enableTimeInterrupts() {
  /* Deactivate interrupts during inititation */
  noInterrupts();
  
  TCCR1A=0;
  TCCR1B=0;
  
  TCNT1=0;
  
  /* Set the compare register value to 3000 */
  CR1A=3000;
  TCCR1B |= (1<<WGM12);

/* Setting the prescaler */
  TCCR1B |= (1<<CS12) | (1<<CS10);
  TIMSK1 |= (1<<OCIE1A);

  interrupts();
}

ISR(TIMER1_COMP_vect) {
  findMessage();
}
