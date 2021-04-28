#include<avr/io.h>
#include"Activity1.h"      //Header file for Activity_1
#include"Activity2.h"      //Header file for Activity_2
#include"Activity3.h"      //Header file for Activity_3
#include"Activity4.h"      //Header file for Activity_4

volatile int LED_STATUS=0; //Variable storing LED status
volatile int temp_out=0;   //Variable storing Temp Out
uint16_t temp=0xFFFF;      //Variable storing Temp Input

int main(void)             // Main Funclion
{

    while(1)               // Infinite Loop
    {
       LED_STATUS=Activity1(LED_STATUS);// Function for checking the GPIO Status
       if(LED_STATUS==1)                // If LED_Status in "TRUE"
       {
           temp=Activity2();            //Function for Reading the Analog value from ADC Pin.
           temp_out=Activity3(temp);    //Function for setting the PWM according to 'temp' value.
           Activity4(temp_out);         //Send the tempout value using UART

       }
       else                             // If LED_Status in "FALSE"
       {
           temp=0x0000;                 // Initialize 'temp' to 0.
           temp_out=0;                  // Initialize 'temp' to 0.
           Activity4(temp_out);         //Send the tempout value using UART
        }

    }
    return 0;
}
