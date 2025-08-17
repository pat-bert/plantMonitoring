/**
 * POWER Generated API Header File
 * 
 * @file power.h
 * 
 * @defgroup  power POWER
 * 
 * @brief This is the generated header file for the POWER driver.
 *
 * @version POWER Driver Version 1.1.0
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

#ifndef POWER_H
#define POWER_H

/**
  Section: Included Files
 */

#include <stdbool.h>
#include <stdint.h>

/**
  Section: POWER Enumerations
 */

/**
 * @ingroup power
 * @enum power_mode_t
 * @brief Contains the available power modes.
 */
typedef enum
{
    POWER_IDLE_MODE = 0 ,/** Sleep mode: IDLE */
    POWER_ADC_MODE = 1 ,/** Sleep mode: ADC */
    POWER_PDOWN_MODE = 2 ,/** Sleep mode: PDOWN */
    POWER_PSAVE_MODE = 3 ,/** Sleep mode: PSAVE */
    POWER_VAL_0X04_MODE = 4 ,/** Sleep mode: VAL_0x04 */
    POWER_VAL_0X05_MODE = 5 ,/** Sleep mode: VAL_0x05 */
    POWER_STDBY_MODE = 6 ,/** Sleep mode: STDBY */
    POWER_ESTDBY_MODE = 7 
} power_mode_t;


/**
 * @ingroup power
 * @enum power_peripheral_t
 * @brief Contains a list of all the PLIBs available for Power Reduction Registers (PRR).
 */
typedef enum
{
    // Register = PRR =  ,
    POWER_ADC = 0x0001 ,// ADC Module
    POWER_SPI = 0x0004 ,// SPI Module
    POWER_TIM0 = 0x0020 ,// TIM0 Module
    POWER_TIM1 = 0x0008 ,// TIM1 Module
    POWER_TIM2 = 0x0040 ,// TIM2 Module
    POWER_TWI = 0x0080 ,// TWI Module
    POWER_USART0 = 0x0002 
} power_peripheral_t;

/**
  Section: POWER APIs
 */
/**
 * @ingroup power
 * @brief  Enters and sets the mode in the Power module and puts the device in Sleep mode, depending on the enum entered.
 * @param powerMode - Selected power mode as specified by an enum of the type power_mode_t
 * @retval True Enum is invalid
 * @retval False Enum is valid
 */ 
bool POWER_LowPowerModeEnter(power_mode_t powerMode);


/**
 * @ingroup power
 * @brief  This routine enables the Peripheral depending on the enum entered.
 * @param peripheral enable, specified as an enum of the type power_peripheral_t.
 * @retval True Enum is invalid
 * @retval False Enum is valid
 */ 
bool POWER_PeripheralEnable(power_peripheral_t peripheral);

/**
 * @ingroup power
 * @brief  This routine disables the Peripheral depending on the enum entered.
 * @param peripheral disable, specified as an enum of the type power_peripheral_t.
 * @retval True Enum is invalid
 * @retval False Enum is valid
 */ 
bool POWER_PeripheralDisable(power_peripheral_t peripheral);

/**
 * @ingroup power
 * @brief  Disables all the Peripherals to save power.
 * @param None.
 * @return None.
 */ 
void POWER_PeripheralDisableAll(void);
#endif // POWER_H
/**
 End of File
 */
