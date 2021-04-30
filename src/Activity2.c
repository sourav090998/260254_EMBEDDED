#include <avr/io.h>
#include<util/delay.h>


/** \brief To read the ADC value of the channel given.
 *
 * \param ch uint8_t
 * \return uint16_t
 *
 */
uint16_t readADC(uint8_t ch)
{
    ADMUX&=0xf8;                                // Anding ADMUX with F8 Hex
    ch=ch&0b00000111;                           // Anding ch with 00000111 binary
    ADMUX|=ch;                                  // Setting Channel in ADMUX

    ADCSRA|=(1<<ADSC);                          // Setting up ADSC=1
    while(!(ADCSRA&(1<<ADIF)));                 // Until ADC coversion is complete
    ADCSRA|=(1<<ADIF);                          // Setting up ADIF=1
    return(ADC);                                // Return 'ADC'
}

/** \brief To configure the ADC Registers.
 *
 * \return void
 *
 */
void enbladc()
{
    ADCSRA=(1<<ADEN)|(7<<ADPS0);                // Setting up ADEN=1 & ADPS0=1
    ADMUX|=(1<<REFS0);                          // Setting up REFS0=1
}


/** \brief Fuction for Calculating the ADC value at A0 and return the binary value.
 *
 * \return uint16_t
 *
 */
uint16_t Activity2()
{   enbladc();                                  // Configure ADC Registers
    uint16_t temp;                              // Initializing Temp Variable
    temp=readADC(0);                            // Store ADC value to temp variable
    _delay_ms(200);
    return temp;                                // Return 'temp'
}
