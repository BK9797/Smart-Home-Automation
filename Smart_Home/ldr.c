/******************************************************************************
 *
 * Module: LDR Sensor
 *
 * File Name: ldr.h
 *
 * Description: Source file for the LDR Sensor driver.
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#include "ldr.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculating the Light Intensity from the ADC digital value.
 */
uint16 LDR_getLightIntensity(void)
{
    uint16 Light_value = 0;
    uint16 adc_value = 0;

    /* Read ADC channel where the LDR sensor is connected */
    adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    /* Calculate the Light Intensity from the ADC value */
    Light_value = (uint16)(((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE) /
                           (ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));

    return Light_value;
}
