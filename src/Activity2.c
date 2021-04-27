#include <avr/io.h>
#include<util/delay.h>

uint16_t readADC(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;

    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

void enbladc()
{
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
    ADMUX|=(1<<REFS0);
}


uint16_t Activity2()
{   enbladc();
    uint16_t temp;
    temp=readADC(0);
    _delay_ms(200);
    return temp;
}
