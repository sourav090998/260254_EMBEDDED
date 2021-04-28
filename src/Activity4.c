#include<avr/io.h>
#include<util/delay.h>

/** \ UART Configuration block
 *
 * \param ubrr_value uint16_t
 * \return void
 *
 */
void USARTConfig(uint16_t ubrr_value)
{
    // SET BAUD RATE
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>0)&0x00ff;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    // Enable TX and RX
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<TXCIE0);
}

/** \brief UART transmitter block
 *
 * \param data char
 * \return void
 *
 */
void USARTWriteChar(char data)
{

    while(!(UCSR0A&(1<<UDRE0)))             // Wait until TX is ready
    {
        //Do nothing
    }
    UDR0=data;                              // Sending DATA to UDR0 Register
}

/** \brief To send the temprature value using USART
 *
 * \param temp_out int
 * \return void
 *
 */
void Activity4(int temp_out)
{
    USARTConfig(103);                       // USART Configure
    USARTWriteChar(temp_out);               // Sent the 'temp_out' over USART
}


