#include <avr/io.h>
#define PWMOUT PD6

/** \brief Read the 'temp' value and output PWN as per the preset value
 *
 * \param temp uint16_t
 * \return int
 *
 */
int Activity3(uint16_t temp)
{
    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);  // Setting up NON INVERTING PWM,
    TCCR0B|=(1<<CS01)|(1<<CS00);                // Setting up registers for 64 Prescaler
    DDRD|=(1<<PWMOUT);                          // Setting PWMOUT as OUTPUT
    volatile int temp_out=0;                    // Variable to store the temprature data

    if(temp<= 200)                              // If analog value is less than 200
    {
        OCR0A=50;                               // Output 20% PWM i.e 50
        temp_out=20;                            // Store temprature 20 degree.
    }
    if(temp>=201 && temp<= 500)                 // If analog value is greater than 201 less than 500
    {
       OCR0A=101;                               // Output 40% PWM i.e 101
       temp_out=25;                             // Store temprature 25 degree.
    }
    if(temp>=501 && temp<= 700)                 // If analog value is greater than 501 less than 700
    {
       OCR0A=178;                               // Output 70% PWM i.e 178
       temp_out=29;                             // Store temprature 29 degree.
    }
    if(temp>=710 && temp<= 1024)                // If analog value is greater than 701 less than 1024
    {
        OCR0A=242;                              // Output 95% PWM i.e 242
        temp_out=33;                            // Store temprature 33 degree.
    }

    return temp_out;                            // Return 'temp_out'
}
