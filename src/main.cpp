#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

char pulsadores=0;
void config(void){
  DDRD|=0xF0;//motores
  PCICR|=0x01;//interrupciones B
  PCMSK0|=0x07;//pin 0,1 y 2
  DDRB&=~0x07;//pulsadores
  PORTB|=0x07;//pull ups
  sei();
}

int main(void){
  config();
  while (1){
  }
}