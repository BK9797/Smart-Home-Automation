/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the DC Motor driver.
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H
#define DC_MOTOR_H

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

// Configuration for the motor pins
#define MOTOR_PORT       PORTB_ID  // Change as needed
#define MOTOR_PIN1      PIN0_ID    // Motor direction pin 1
#define MOTOR_PIN2      PIN1_ID    // Motor direction pin 2
#define MOTOR_ENABLE_PIN PIN3_ID    // Motor enable pin (PWM pin)

#include "std_types.h"
#include "pwm.h"
#include "gpio.h"

/*******************************************************************************
 *                              Types Definitions                              *
 *******************************************************************************/

// Enum for DC Motor state
typedef enum {
    DC_MOTOR_STOP,
    DC_MOTOR_CW,    // Clockwise
    DC_MOTOR_A_CW   // Anti-clockwise
} DcMotor_State;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * A function to initialize the DC motor
 */
void DcMotor_Init(void);

/*
 * Description :
 * A function to control the DC motor state and speed
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H */
