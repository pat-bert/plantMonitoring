/**
 * ADC Generated Driver File
 * 
 * @file adc.c
 * 
 * @ingroup  adc
 * 
 * @brief This file contains the API implementations for the ADC driver.
 *
 * @version ADC Driver Version 2.0.0
 * 
 * @version ADC Package Version 2.0.0
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

#include "../adc.h"

static void (*ADC_ConversionDoneCallback)(void) = NULL;

void ADC_Initialize(void)
{
    ADCSRA &= ~(ADEN);                     /* ADEN (disabled) */
    ADC = 0x0;                               /* ADC (0x0) */
    ADCSRB = (0 << ACME)                        /* ACME (disabled) */
			|(0x0);                             /* ADTS (Free Running mode) */
    ADMUX = (0 << ADLAR)                       /* ADLAR (disabled) */
			|(0x0)                              /* MUX (ADC Single Ended Input pin 0) */
			|(0x1 << REFS0);                    /* REFS (AVCC with external capacitor at AREF pin) */
    DIDR0 = (0 << ADC0D)                       /* ADC0D (disabled) */
			|(0 << ADC1D)                       /* ADC1D (disabled) */
			|(0 << ADC2D)                       /* ADC2D (disabled) */
			|(0 << ADC3D)                       /* ADC3D (disabled) */
			|(0 << ADC4D)                       /* ADC4D (disabled) */
			|(0 << ADC5D);                      /* ADC5D (disabled) */
    ADC_ConversionDoneCallbackRegister(NULL);
    ADCSRA = (0 << ADATE)                       /* ADATE (disabled) */
			|(1 << ADEN)                        /* ADEN (enabled) */
			|(0 << ADIE)                        /* ADIE (disabled) */
			|(0 << ADIF)                        /* ADIF (disabled) */
			|(0x6)                              /* ADPS (64) */
			|(0 << ADSC);                       /* ADSC (disabled) */
}

void ADC_Deinitialize(void)
{
    ADCSRA = 0x0;
    ADCSRB = 0x0;
    ADC = 0x0;
    ADMUX = 0x0;
    DIDR0 = 0x0;
}

void ADC_Enable(void)
{
    ADCSRA |= (1 << ADEN);
}

void ADC_Disable(void)
{
    ADCSRA &= ~(1 << ADEN);
}

void ADC_ChannelSelect(adc_channel_t channel)
{
    ADMUX &=  ~0x1F;
    ADMUX |= channel;
}

void ADC_ConversionStart(void)
{
    ADCSRA |= (1 << ADSC);
}

bool ADC_IsConversionDone(void)
{
    return !(ADCSRA & (1 << ADSC));
}

adc_result_t ADC_ConversionResultGet(void)
{
    return (adc_result_t)ADC;
}

void ADC_ConversionDoneCallbackRegister(void (*callback)(void))
{
    ADC_ConversionDoneCallback = callback;
}

adc_result_t ADC_ChannelSelectAndConvert(adc_channel_t channel)
{
    adc_result_t result;
    ADMUX &=  ~0x1F;
    ADMUX |= channel;
    ADCSRA |= (1 << ADSC);
    while (true == (ADCSRA & (1 << ADSC)))
    {
        //wait for conversion to finish. 
    }
    result = ADC;
    return result;
}

uint8_t ADC_ResolutionGet(void)
{
    return ADC_RESOLUTION;
}

void ADC_AutoTriggerEnable(void)
{
    ADCSRA |= (1 << ADATE);
}

void ADC_AutoTriggerDisable(void)
{
    ADCSRA &= ~(1 << ADATE);
}

void ADC_AutoTriggerSourceSet(adc_trigger_source_t triggerSource)
{
    ADCSRB &=  ~0x7;
    ADCSRB |= triggerSource;
}

bool ADC_IsConversionDoneInterruptFlagSet(void)
{
    return (bool)(ADCSRA & (1 << ADIF));
}

void ADC_ConversionDoneInterruptFlagClear(void)
{
    ADCSRA |= (1 << ADIF);
}

void ADC_DigitalInputDisable(uint8_t disableValue)
{
    DIDR0 = disableValue;
}

void ADC_Tasks(void)
{
    if(false != (ADCSRA & (1 << ADIF))) 
    {
        //Clear the interrupt flag
        ADCSRA |= (1 << ADIF);

        if(NULL != ADC_ConversionDoneCallback)
        {
            ADC_ConversionDoneCallback();
        } 
    }
}
