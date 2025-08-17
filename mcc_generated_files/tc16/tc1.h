/**
 * TC1 Generated Driver API Header File
 *
 * @file tc1.h
 *
 * @defgroup tc1 TC1
 *
 * @brief This file contains the API prototypes for the TC1 driver.
 *
 * @version TC1 Driver Version 1.0.0
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
  
#ifndef TC1_H
#define TC1_H

#include "../system/utils/compiler.h"
#include <stdint.h>
#include <stdbool.h>

/**
 * @ingroup tc1
 * @brief Initializes the TC1 module
 * @param None.
 * @return 0 - The TC1 initialization was successful.
 * @return 1 - The TC1 initialization was not successful.
 */
int8_t TC1_Initialize(void);

/**
 * @ingroup tc1
 * @brief Checks the Overflow Interrupt flag status of the TC1 module
 * @param None.
 * @return True  - Overflow interrupt was detected
 * @return False - No overflow interrupt was detected
 */
bool TC1_Get_Overflow_InterruptFlagStatus(void);

/**
 * @ingroup tc1
 * @brief Checks the Compare A flag status of the TC1 module
 * @param None.
 * @return True  - The counter value matches the Output Compare Register A.
 * @return False - The counter value not matches the Output Compare Register A.
 */
bool TC1_Get_CompareA_InterruptFlagStatus(void);

/**
 * @ingroup tc1
 * @brief Checks the Compare B flag status of the TC1 module
 * @param None.
 * @return True  - The counter value matches the Output Compare Register B.
 * @return False - The counter value not matches the Output Compare Register B.
 */

bool TC1_Get_CompareB_InterruptFlagStatus(void);

/**
 * @ingroup tc1
 * @brief Enables the Overflow interrupt of the TC1 module
 * @param None.
 * @return None.
 */
void TC1_Enable_Overflow_Interrupt(void);

/**
 * @ingroup tc1
 * @brief Disables the Overflow interrupt of the TC1 module
 * @param None.
 * @return None.
 */
void TC1_Disable_Overflow_Interrupt(void);

/**
 * @ingroup tc1
 * @brief Enables the Compare A interrupt of the TC1 module
 * @param None.
 * @return None.
 */
void TC1_Enable_CompareA_Interrupt(void);

/**
 * @ingroup tc1
 * @brief Disables the Compare A interrupt of the TC1 module
 * @param None.
 * @return None.
 */
void TC1_Disable_CompareA_Interrupt(void);

/**
 * @ingroup tc1
 * @brief Enables the Compare B interrupt of the TC1 module
 * @param None.
 * @return None.
 */
void TC1_Enable_CompareB_Interrupt(void);

/**
 * @ingroup tc1
 * @brief Disables the Compare B interrupt of the TC1 module
 * @param None.
 * @return None.
 */
void TC1_Disable_CompareB_Interrupt(void);

/**
 * @ingroup tc1
 * @brief Writes the timer value of the TC1 module
 * @param uint16_t - TimerValue
 * @return None.
 */
void TC1_WriteTimer(uint16_t timerValue);

/**
 * @ingroup tc1
 * @brief Reads the timer value of the TC1 module
 * @param None.
 * @return uint16_t - Timer register value
 */
uint16_t TC1_ReadTimer(void);

#endif    //TC1_H
