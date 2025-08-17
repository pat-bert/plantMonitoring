/**
 * Generated Pins Header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This file contains the API prototypes and function macros for the Pins driver.
 *
 * @version Driver Version  1.0.0
*/ 

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"
/**  
 * @ingroup  pinsdriver
 * @name Pin Function Macros
 * Macros for the individual pin functions.
 * @note These sets of macros are generated for all the selected pins in the Pins module.
 */
 ///@{

//get/set ADC0 aliases
#define ADC0_SetHigh() do { PORTC |= 0x1; } while(0)
#define ADC0_SetLow() do { PORTC &= ~0x1; } while(0)
#define ADC0_Toggle() do { PINC |= 0x1; } while(0)
#define ADC0_GetValue() (PINC & (0x1 << 0))
#define ADC0_SetDigitalInput() do { DDRC &= ~0x1; } while(0)
#define ADC0_SetDigitalOutput() do { DDRC |= 0x1; } while(0)
#define ADC0_SetPullUp() do { PORTC |= 0x1; } while(0)
#define ADC0_ResetPullUp() do { PORTC &= ~0x1; } while(0)

//get/set ADC1 aliases
#define ADC1_SetHigh() do { PORTC |= 0x2; } while(0)
#define ADC1_SetLow() do { PORTC &= ~0x2; } while(0)
#define ADC1_Toggle() do { PINC |= 0x2; } while(0)
#define ADC1_GetValue() (PINC & (0x1 << 1))
#define ADC1_SetDigitalInput() do { DDRC &= ~0x2; } while(0)
#define ADC1_SetDigitalOutput() do { DDRC |= 0x2; } while(0)
#define ADC1_SetPullUp() do { PORTC |= 0x2; } while(0)
#define ADC1_ResetPullUp() do { PORTC &= ~0x2; } while(0)

//get/set ADC2 aliases
#define ADC2_SetHigh() do { PORTC |= 0x4; } while(0)
#define ADC2_SetLow() do { PORTC &= ~0x4; } while(0)
#define ADC2_Toggle() do { PINC |= 0x4; } while(0)
#define ADC2_GetValue() (PINC & (0x1 << 2))
#define ADC2_SetDigitalInput() do { DDRC &= ~0x4; } while(0)
#define ADC2_SetDigitalOutput() do { DDRC |= 0x4; } while(0)
#define ADC2_SetPullUp() do { PORTC |= 0x4; } while(0)
#define ADC2_ResetPullUp() do { PORTC &= ~0x4; } while(0)

//get/set IO_PD2 aliases
#define IO_PD2_SetHigh() do { PORTD |= 0x4; } while(0)
#define IO_PD2_SetLow() do { PORTD &= ~0x4; } while(0)
#define IO_PD2_Toggle() do { PIND |= 0x4; } while(0)
#define IO_PD2_GetValue() (PIND & (0x1 << 2))
#define IO_PD2_SetDigitalInput() do { DDRD &= ~0x4; } while(0)
#define IO_PD2_SetDigitalOutput() do { DDRD |= 0x4; } while(0)
#define IO_PD2_SetPullUp() do { PORTD |= 0x4; } while(0)
#define IO_PD2_ResetPullUp() do { PORTD &= ~0x4; } while(0)

//get/set IO_PD3 aliases
#define IO_PD3_SetHigh() do { PORTD |= 0x8; } while(0)
#define IO_PD3_SetLow() do { PORTD &= ~0x8; } while(0)
#define IO_PD3_Toggle() do { PIND |= 0x8; } while(0)
#define IO_PD3_GetValue() (PIND & (0x1 << 3))
#define IO_PD3_SetDigitalInput() do { DDRD &= ~0x8; } while(0)
#define IO_PD3_SetDigitalOutput() do { DDRD |= 0x8; } while(0)
#define IO_PD3_SetPullUp() do { PORTD |= 0x8; } while(0)
#define IO_PD3_ResetPullUp() do { PORTD &= ~0x8; } while(0)

//get/set IO_PD4 aliases
#define IO_PD4_SetHigh() do { PORTD |= 0x10; } while(0)
#define IO_PD4_SetLow() do { PORTD &= ~0x10; } while(0)
#define IO_PD4_Toggle() do { PIND |= 0x10; } while(0)
#define IO_PD4_GetValue() (PIND & (0x1 << 4))
#define IO_PD4_SetDigitalInput() do { DDRD &= ~0x10; } while(0)
#define IO_PD4_SetDigitalOutput() do { DDRD |= 0x10; } while(0)
#define IO_PD4_SetPullUp() do { PORTD |= 0x10; } while(0)
#define IO_PD4_ResetPullUp() do { PORTD &= ~0x10; } while(0)
///@}

/**
 * @ingroup  pinsdriver
 * @brief Initializes the General Purpose Input/Output (GPIO), peripheral I/O pins and related registers.
 * @param None.
 * @return None.
 */
void PIN_MANAGER_Initialize();

#endif /* PINS_H_INCLUDED */
