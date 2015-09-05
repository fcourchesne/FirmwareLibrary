// Global default values
#ifndef F_CPU
    #define F_CPU 8000000UL
#endif

// Attribute pin numbers of MCUs currently used
//#ifndef MCU
    //#error "You must define MCU in atmel.h in your Libraries"
//#endif

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
#endif

#ifdef ATMEGA168P
    #define DD_MOSI     PB3
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
#endif

#ifdef ATTINY85
    //TODO: Define ATTINY85 pins
#endif

#ifdef ATTINY45
    //TODO: Define ATTINY85 pins
#endif
    //TODO: Add more MCU pin definitions

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define FLIPBIT(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define SETBITMASK(x,y) (x |= (y))
#define CLEARBITMASK(x,y) (x &= (~y))
#define FLIPBITMASK(x,y) (x ^= (y))
#define CHECKBITMASK(x,y) (x & (y))

#define VARFROMCOMB(x, y) x
#define BITFROMCOMB(x, y) y

#define C_SETBIT(comb) SETBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CLEARBIT(comb) CLEARBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_FLIPBIT(comb) FLIPBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CHECKBIT(comb) CHECKBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
// Ex: SETBIT(PORTA,3)
