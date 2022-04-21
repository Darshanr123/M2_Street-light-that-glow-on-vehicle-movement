#define F_CPU 1000000UL
    
    #include<avr/io.h>
    #include<util/delay.h>
    #include <avr/interrupt.h>
    int main()
    {
        DDRB=0x00; //configuring PortB as input
        PORTB=0x00;
        DDRA=0x00; //configuring PortB as input
        PORTA=0x00;
        DDRD=0x00; //configuring PortD as input
        PORTD=0x00;
        DDRC=0xFF; // configuring PortC as output
        PORTC=0x00; // initially off
        
        GICR |= (1<<INT0)| (1<<INT0);
        MCUCR |= (1<<ISC10) | (1<<ISC11);
        
        sei();
        
        while(1)
        {
            if(!(PIND&(1<<0))) // In presence of darkness (When there is darkness pin goes low)
        {
            if((PINB&(1<<1))|(PINB&(1<<2)))            // check for sensor pin PB.1 and PB.2  using bit. The 2 switches.
            {
                PORTC = 0x03;           // buzzer /LED on
                
                _delay_ms(1000);
                
                PORTC = 0x00;
            }
            else
            PORTC=0x00;  // buzzer/LED off
        }
        }
        return 0;
    }
