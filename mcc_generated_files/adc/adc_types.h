/**
 * ADC Type Definitions Header File
 *
 * @file adc_types.h
 *
 * @defgroup adc ADC
 *
 * @brief This header file provides the type definitions for the ADC module.
 *
 * @version ADC Driver Version 2.0.0
 *
 * @version ADC Module Version 2.0.0
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

#ifndef ADC_TYPES_H
#define ADC_TYPES_H

#include <stdint.h>

/**
 @ingroup adc
 @brief ADC 10-bit resolution value.
*/
#define ADC_RESOLUTION 10U

/**
 @ingroup adc
 @typedef adc_result_t
 @brief ADC conversion result type.
*/
typedef int16_t adc_result_t;

/**
 * @ingroup adc
 * @enum adc_channel_t
 * @brief All available analog channels for the ADC conversion.
*/
typedef enum
{
    ADC_CHANNEL_ADC0 = 0x0, /**< ADC Single Ended Input pin 0*/  
    ADC_CHANNEL_ADC1 = 0x1, /**< ADC Single Ended Input pin 1*/  
    ADC_CHANNEL_ADC2 = 0x2, /**< ADC Single Ended Input pin 2*/  
    ADC_CHANNEL_ADC3 = 0x3, /**< ADC Single Ended Input pin 3*/  
    ADC_CHANNEL_ADC4 = 0x4, /**< ADC Single Ended Input pin 4*/  
    ADC_CHANNEL_ADC5 = 0x5, /**< ADC Single Ended Input pin 5*/  
    ADC_CHANNEL_ADC6 = 0x6, /**< ADC Single Ended Input pin 6*/  
    ADC_CHANNEL_ADC7 = 0x7, /**< ADC Single Ended Input pin 7*/  
    ADC_CHANNEL_TEMPSENS = 0x8, /**< Temperature sensor*/  
    ADC_CHANNEL_ADC_VBG = 0xe, /**< Internal Reference (VBG)*/  
    ADC_CHANNEL_ADC_GND = 0xf /**< 0V (GND)*/  
} adc_channel_t;

/**
 * @ingroup adc
 * @typedef adc_trigger_source_t 
 * @brief Enumeration for the ADC auto-trigger sources.
 */
typedef enum
{
    ADC_FREE_RUNNING_MODE = 0x0, /**< Free Running mode*/  
    ADC_ANALOG_COMPARATOR = 0x1, /**< Analog Comparator*/  
    ADC_EXTERNAL_INTERRUPT_REQUEST_0 = 0x2, /**< External Interrupt Request 0*/  
    ADC_TIMER_COUNTER0_COMPARE_MATCH_A = 0x3, /**< Timer/Counter0 Compare Match A*/  
    ADC_TIMER_COUNTER0_OVERFLOW = 0x4, /**< Timer/Counter0 Overflow*/  
    ADC_TIMER_COUNTER1_COMPARE_MATCH_B = 0x5, /**< Timer/Counter1 Compare Match B*/  
    ADC_TIMER_COUNTER1_OVERFLOW = 0x6, /**< Timer/Counter1 Overflow*/  
    ADC_TIMER_COUNTER1_CAPTURE_EVENT = 0x7 /**< Timer/Counter1 Capture Event*/  
} adc_trigger_source_t;

#endif // ADC_TYPES_H