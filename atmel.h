// Global default values
#ifndef F_CPU
    #define F_CPU 8000000UL
#endif

// Attribute pin numbers of MCUs currently used
#ifndef MCU
    #error "You must define MCU in atmel.h in your Libraries"
#endif

#ifndef BAUD
    #define BAUD 9600
#endif

#ifndef UBRR
    #define UBRR (((F_CPU / (BAUD * 16UL))) - 1)
#endif

#ifndef OUTPUT
    #define OUTPUT 1
#endif

#ifndef INPUT
    #define INPUT 0
#endif

#ifndef HIGH
    #define HIGH 1
#endif

#ifndef LOW
    #define LOW 0
#endif

#ifdef ATMEGA328P
    #define DD_MOSI     PB5
    #define DD_MISO     PB4
    #define DD_SCK      PB5
    #define DDR_SPI     DDRB
    #define PORT_SPI    PORTB
    #define ADC0        PC0
    #define ADC1        PC1
    #define ADC2        PC2
    #define ADC3        PC3
    #define ADC4        PC4
    #define ADC5        PC5
    #define TX          PD1
    #define RX          PD0
    #define RESET       PC6
    #define
#ifdef ATTINY85
    //TODO: Define ATTINY85 pins
#ifdef ATTINY45
    //TODO: Define ATTINY85 pins
#endif
    //TODO: Add more MCU pin definitions

#define BIT(x) (1 << (x))
#define SETBITS(x,y) ((x) |= (y))
#define CLEARBITS(x,y) ((x) &= (~(y)))
#define SETBIT(x,y) SETBITS((x), (BIT((y))))
#define CLEARBIT(x,y) CLEARBITS((x), (BIT((y))))
#define BITSET(x,y) ((x) & (BIT(y)))
#define BITCLEAR(x,y) !BITSET((x), (y))
#define BITSSET(x,y) (((x) & (y)) == (y))
#define BITSCLEAR(x,y) (((x) & (y)) == 0)
#define BITVAL(x,y) (((x)>>(y)) & 1)
// Ex: SETBIT(PORTA,3)
