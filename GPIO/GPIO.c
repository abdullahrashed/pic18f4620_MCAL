#include <pic18lf4620.h>

#include"GPIO.h"

volatile uint8* TRIS[5]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8* LAT[5]={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8* PORT[5]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

standard_return gpio_pin_setup(uint8 port_,uint8 pin_,uint8 direction)
{
    standard_return ret= ok;
    if(port_ >5 || pin_ >7)
    {
        ret=n_ok;
    }
    else
    {
        switch(port_)
        {
            case porta_:
                if(gpio_output==direction)
                {
                    CLEAR_BIT(*TRIS[0],pin_);
                }
                else
                {
                    SET_BIT(*TRIS[0],pin_);
                }    
                break;
            case portb_:
                 if(gpio_output==direction)
                {
                    CLEAR_BIT(*TRIS[1],pin_);
                }
                else
                {
                    SET_BIT(*TRIS[1],pin_);
                }    
                break;
            case portc_:
                 if(gpio_output==direction)
                {
                    CLEAR_BIT(*TRIS[2],pin_);
                }
                else
                {
                    SET_BIT(*TRIS[2],pin_);
                }    
                break;
            case portd_:
                 if(gpio_output==direction)
                {
                    CLEAR_BIT(*TRIS[3],pin_);
                }
                else
                {
                    SET_BIT(*TRIS[3],pin_);
                }    
                break;
            case porte_:
                 if(gpio_output==direction)
                {
                    CLEAR_BIT(*TRIS[4],pin_);
                }
                else
                {
                    SET_BIT(*TRIS[4],pin_);
                }    
                break;
        }
    }
    return ret;
}
standard_return gpio_pin_write(uint8 port_,uint8 pin_,uint8 state)
{
    standard_return ret= ok;
    if(port_ >5 || pin_ >7)
    {
        ret=n_ok;
    }
    else
    {
      switch(port_)
        {
            case porta_:
                if(gpio_high==state)
                {
                    SET_BIT(*LAT[0],pin_);
                }
                else
                {
                    CLEAR_BIT(*LAT[0],pin_);
                }    
                break;
            case portb_:
                 if(gpio_high==state)
                {
                      SET_BIT(*LAT[1],pin_);
                }
                else
                {
                    CLEAR_BIT(*LAT[1],pin_);
                }    
                break;
            case portc_:
                 if(gpio_high==state)
                {
                      SET_BIT(*LAT[2],pin_);
                }
                else
                {
                    CLEAR_BIT(*LAT[2],pin_);
                }    
                break;
            case portd_:
                 if(gpio_high==state)
                {
                       SET_BIT(*LAT[3],pin_);
                }
                else
                {
                    CLEAR_BIT(*LAT[3],pin_);
                }    
                break;
            case porte_:
                 if(gpio_high==state)
                {
                       SET_BIT(*LAT[4],pin_);
                }
                else
                {
                    CLEAR_BIT(*LAT[4],pin_);
                }    
                break;
        }
    }
    return ret;
}
standard_return gpio_pin_toggle(uint8 port_,uint8 pin_)
{
    standard_return ret= ok;
    if(port_ >5 || pin_ >7)
    {
        ret=n_ok;
    }
    else
    {
        switch(port_)
        {
                case porta_:
                    TOGGLE_BIT(*LAT[0],pin_);
                break;
                case portb_:
                    TOGGLE_BIT(*LAT[1],pin_);
                break;
                case portc_:
                    TOGGLE_BIT(*LAT[2],pin_);
                break;
                case portd_:
                    TOGGLE_BIT(*LAT[3],pin_);
                break;
                case porte_:
                    TOGGLE_BIT(*LAT[4],pin_);
                break;
        }                
    }
    return ret;
}
standard_return gpio_pin_read(uint8 port_,uint8 pin_,uint8 *return_value)
{
    standard_return ret= ok;
    if(port_ >5 || pin_ >7 || NULL==return_value)
    {
        ret=n_ok;
    }
    else
    {
      switch(port_)
        {
                case porta_:
                    *return_value=READ_BIT(*PORT[0],pin_);
                break;
                case portb_:
                    *return_value=READ_BIT(*PORT[1],pin_);
                break;
                case portc_:
                   *return_value=READ_BIT(*PORT[2],pin_);
                break;
                case portd_:
                   *return_value=READ_BIT(*PORT[3],pin_);
                break;
                case porte_:
                    *return_value=READ_BIT(*PORT[4],pin_);
                break;
        }                   
    }
    return ret;
}
standard_return gpio_port_setup(uint8 port_,uint8 direction)
{
    standard_return ret=ok;
    if(port_>5)
    {
       ret=n_ok; 
    }
    else
    {
        switch(port_)
        {
            case porta_:
                *TRIS[0]=direction;
                break;
            case portb_:
                *TRIS[1]=direction;
                break;
            case portc_:
                *TRIS[2]=direction;
                break;
            case portd_:
                *TRIS[3]=direction;
                break;
            case porte_:
                *TRIS[4]=direction;
                break;
        }
    }
    return ret;
}
standard_return gpio_port_write(uint8 port_,uint8 state)
{
    standard_return ret=ok;
    if(port_>5)
    {
       ret=n_ok; 
    }
    else
    {
       switch(port_)
        {
            case porta_:
               *LAT[0]=state;
                break;
            case portb_:
                *LAT[1]=state;
                break;
            case portc_:
                *LAT[2]=state;
                break;
            case portd_:
                *LAT[3]=state;
                break;
            case porte_:
                *LAT[4]=state;
                break;
        } 
    }
    return ret;
}
standard_return gpio_port_toggle(uint8 port_)
{
    standard_return ret=ok;
    if(port_>5)
    {
       ret=n_ok; 
    }
    else
    {
      switch(port_)
        {
            case porta_:
               *LAT[0]^=0xff;
                break;
            case portb_:
                *LAT[1]^=0xff;
                break;
            case portc_:
                *LAT[2]^=0xff;
                break;
            case portd_:
                *LAT[3]^=0xff;
                break;
            case porte_:
                *LAT[4]^=0xff;
                break;
        }   
    }
    return ret;
}
standard_return gpio_port_read(uint8 port_,uint8 *return_value)
{
    standard_return ret=ok;
    if(port_>5)
    {
       ret=n_ok; 
    }
    else
    {
        switch(port_)
        {
            case porta_:
               *return_value=*PORT[0];
                break;
            case portb_:
               *return_value=*PORT[1];
                break;
            case portc_:
                *return_value=*PORT[2];
                break;
            case portd_:
                *return_value=*PORT[3];
                break;
            case porte_:
                *return_value=*PORT[4];
                break;
        } 
    }
    return ret;
}
