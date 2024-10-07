/******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.h
 *
 * Description: Header file for the Flame Sensor driver.
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

// Configuration for the flame sensor pin
#define FLAME_SENSOR_PORT  PORTD_ID   // Define the port connected to the sensor
#define FLAME_SENSOR_PIN   PIN2_ID    // Define the pin connected to the sensor

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * A function to initialize the flame sensor by setting up its pin direction.
 */
void FlameSensor_init(void);

/*
 * Description :
 * A function to read the value from the flame sensor and return it.
 * Returns 1 if fire is detected, 0 otherwise.
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H */
