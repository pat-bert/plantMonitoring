/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/power/power.h"
#include "mcc_generated_files/system/utils/utils_assert.h"

/*
    Main application
 */

#define NUMBER_PLANTS (3)
#define DRY_THRESHOLD (500)

void set_gpio(int i) {
    switch (i) {
        case 0:
        {
            IO_PD2_SetHigh();
            break;
        }
        case 1:
        {
            IO_PD3_SetHigh();
            break;
        }
        case 2:
        {
            IO_PD4_SetHigh();
            break;
        }
        default:
        {
            ASSERT(false);
            break;
        }
    }
}

void clear_gpio(int i) {
    switch (i) {
        case 0:
        {
            IO_PD2_SetLow();
            break;
        }
        case 1:
        {
            IO_PD3_SetLow();
            break;
        }
        case 2:
        {
            IO_PD4_SetLow();
            break;
        }
        default:
        {
            ASSERT(false);
            break;
        }
    }
}

int main(void) {
    SYSTEM_Initialize();
    ASSERT(!POWER_PeripheralEnable(POWER_TIM1));

    while (1) {
        ASSERT(!POWER_PeripheralEnable(POWER_ADC));
        ADC_Enable();

        for (int i = 0; i < NUMBER_PLANTS; ++i) {
            ADC_ChannelSelect(ADC0 + i);
            ADC_ConversionStart();
            while (!ADC_IsConversionDone()) {
                __asm("nop;");
            }
            const volatile adc_result_t adc = ADC_ConversionResultGet();
            const uint16_t mask = (1 << ADC_ResolutionGet()) - 1;
            const uint16_t humidity = adc & mask;

            if (humidity > DRY_THRESHOLD) {
                set_gpio(i);
            } else {
                clear_gpio(i);
            }
        }

        ADC_Disable();
        ASSERT(!POWER_PeripheralDisable(POWER_ADC));
        ASSERT(!POWER_LowPowerModeEnter(POWER_IDLE_MODE));
    }
}