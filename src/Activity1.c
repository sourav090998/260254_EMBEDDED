#include"avr/io.h"
#include"util/delay.h"

#define LED PB2                 // Using PB2 for LED
#define SW1 PB0                 // Using PB0 for SW1
#define SW2 PB1                 // Using PB1 for SW2

/** \brief Configure the GPIO as INPUT & OUTPUT
 *
 * \return null
 *
 */
void conf()
{
    DDRB|=(1<<LED);             //Set PB2 as LED Indicator
    DDRB&=~(1<<SW1);            //Set SW1 as Switch_1 Input;
    DDRB&=~(1<<SW2);            //Set SW2 as Switch_2 Input;
    PORTB|=(1<<SW1);            //Set SW1 as Internal Pull Up;
    PORTB|=(1<<SW2);            //Set SW2 as Internal Pull Up;
}


/** \brief To check the state of switch SW1 and SW2 and change the state of LED accordingly.
 *
 * \param LED_STATUS
 * \return LED STATUS
 *
 */
int Activity1(int LED_STATUS)                   // Function for checking the state of switches and Turn On/Off the LED.
{

    conf();
    if((!(PINB&(1<<SW1)))&&(!(PINB&(1<<SW2))))  // If SW1 is '0' and SW2 is '0'
    {
        PORTB|=(1<<LED);                        // Setting LED pin as 'HIGH' (LED ON)
        LED_STATUS=1;                           // Setting 'LED_STATUS' flag 'HIGH'
        _delay_ms(200);
    }
    else                                        //Any other configuration of SW1 and SW2
    {
        PORTB&=~(1<<LED);                       // Setting LED pin as 'LOW' (LED OFF)
        LED_STATUS=0;                           // Setting 'LED_STATUS' flag 'LOW'
        _delay_ms(200);
    }
    return LED_STATUS;                          // Return LED_STATUS (FLAG STATUS)
}
