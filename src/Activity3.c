#include <avr/io.h>

int Activity3(uint16_t temp)
{
    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B|=(1<<CS01)|(1<<CS00);
    DDRD|=(1<<PD6);
    volatile int temp_out=0;

    if(temp>=0 && temp<= 200)
    {
        OCR0A=50;
        temp_out=20;
    }
    if(temp>=201 && temp<= 500)
    {
       OCR0A=101;
       temp_out=25;
    }
    if(temp>=501 && temp<= 700)
    {
       OCR0A=178;
       temp_out=29;
    }
    if(temp>=710 && temp<= 1024)
    {
        OCR0A=242;
        temp_out=33;
    }

    return temp_out;

}
