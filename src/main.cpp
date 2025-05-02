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

void frenar(){
  PORTD&=~0xF0;
}
void avanzar(){
  PORTD&=~0xF0;
  PORTD|=0x50;
}
void retroceder(){
  PORTD&=~0xF0;
  PORTD|=0xA0;
}
void giro_largo_izquierda(){
  PORTD&=~0xF0;
  PORTD|=0x40;
}
void giro_corto_izquierda(){
  PORTD&=~0xF0;
  PORTD|=0x60;
}
void giro_largo_derecha(){
  PORTD&=~0xF0;
  PORTD|=0x10;
}
void giro_corto_derecha(){
  PORTD&=~0xF0;
  PORTD|=0x90;
}

int main(void){
  config();
  while (1){
  }
}