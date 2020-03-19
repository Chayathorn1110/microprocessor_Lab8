#include <SPI.h>
bool toggle;
volatile int timer1 = 3200;
int clk_pin = 13; //SHCP 
int ss_pin = 10; //STCP 
int data_pin = 11; //DS 
int map7seg[10] = 
{
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111, //9
};
int i = 1;

void setup()
{
  noInterrupts(); 
  TCCR1A = 0;
  TCCR1B = 0; 
  TCNT1 = timer1;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  interrupts();
  pinMode(clk_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(ss_pin, OUTPUT);
}

void loop()
{
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = timer1;
  spi_write1(map7seg[i]);
  i++; 
  if(i>9)
    i = 0;
}

void spi_write1(unsigned char cData)
{
  shiftOut(data_pin, clk_pin, MSBFIRST, cData);
  digitalWrite(ss_pin, HIGH);
  digitalWrite(ss_pin, LOW);
}
