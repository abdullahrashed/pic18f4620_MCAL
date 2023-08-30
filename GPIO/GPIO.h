/* 
 * File:   GPIO.h
 * Author: abdul
 *
 * Created on August 19, 2023, 3:39 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include <pic18lf4620.h>
#include"../DATA_TYPES.h"
#include"../DEVICE_CONFG.h"

#define SET_BIT(REGISTER,BIT_POSITION) (REGISTER|=(1<<BIT_POSITION))
#define CLEAR_BIT(REGISTER,BIT_POSITION) (REGISTER &= ~(1<<BIT_POSITION))
#define TOGGLE_BIT(REGISTER,BIT_POSITION) (REGISTER ^= (1<<BIT_POSITION))
#define READ_BIT(REGISTER,BIT_POSITION) ((REGISTER >>BIT_POSITION) && 1)
/*
 * ports
 */
#define porta_ 0
#define portb_ 1
#define portc_ 2
#define portd_ 3
#define porte_ 4
/*
 *pins
 */
#define pin0   0
#define pin1   1
#define pin2   2
#define pin3   3
#define pin4   4
#define pin5   5
#define pin6   6
#define pin7   7
/*
 * pin direction
 */
#define gpio_low 0
#define gpio_high 1
/*
 * pin state
 */

#define gpio_input 0
#define gpio_output 1
/*
 *functions
 */

standard_return gpio_pin_setup(uint8 port_,uint8 pin_,uint8 direction);
standard_return gpio_pin_write(uint8 port_,uint8 pin_,uint8 state);
standard_return gpio_pin_toggle(uint8 port_,uint8 pin_);
standard_return gpio_pin_read(uint8 port_,uint8 pin_,uint8 *return_value);
standard_return gpio_port_setup(uint8 port_,uint8 direction);
standard_return gpio_port_write(uint8 port_,uint8 state);
standard_return gpio_port_toggle(uint8 port_);
standard_return gpio_port_read(uint8 port_,uint8 *return_value);




#endif	/* GPIO_H */

