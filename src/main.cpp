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

ISR(PCINT0_vect){
  _delay_ms(50);
  char estado=PINB&0x07;
  char p0=(!(estado&0x01));
  char p1=(!(estado&0x02));
  char p2=(!(estado&0x04));

  if(p1&&p2){
    retroceder();
  }
  else if(p0&&p1){
    giro_corto_izquierda();
  }
  else if(p0&&p2){
    giro_corto_derecha();
  }
  else if(p1){
    giro_largo_izquierda();
  }
  else if(p2){
    giro_largo_derecha();
  }
  else if(p0){
    if((PORTD&0xF0)!=0x00&&(PORTD&0xF0)!=0x50){
      frenar();
    }
    else{
      avanzar();
    }
  }
  else{
    frenar();
  }
}

int main(void){
  config();
  while (1){
  }
}