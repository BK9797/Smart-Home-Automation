/******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.c
 *
 * Description: Source file for the Flame Sensor driver.
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include "flame_sensor.h"

/**********************************Functions************************************/

/*
 * Description :
 * A function to initialize the flame sensor by setting its pin as input.
 */
void FlameSensor_init(void) {
    /* Set the flame sensor pin as input */
    GPIO_setupPinDirection(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN, PIN_INPUT);
}

/*
 * Description :
 * A function to read the value from the flame sensor.
 * Returns 1 if fire is detected (logic high), otherwise 0 (logic low).
 */
uint8 FlameSensor_getValue(void) {
    /* Read the flame sensor value (high for fire detection, low otherwise) */
    return GPIO_readPin(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN);
}
