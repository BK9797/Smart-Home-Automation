/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the DC Motor driver.
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include "dc_motor.h"

/**********************************Functions************************************/

/*
 * Description :
 * Initializes the DC motor by setting control pins as output and ensuring the motor is off.
 */
void DcMotor_Init(void)
{
    /* Set motor control pins as output */
    GPIO_setupPinDirection(MOTOR_PORT, MOTOR_PIN1, PIN_OUTPUT);
    GPIO_setupPinDirection(MOTOR_PORT, MOTOR_PIN2, PIN_OUTPUT);

    /* Set IN1 and IN2 to low (motor off) */
    GPIO_writePin(MOTOR_PORT, MOTOR_PIN1, LOGIC_LOW);
    GPIO_writePin(MOTOR_PORT, MOTOR_PIN2, LOGIC_LOW);
}

/*
 * Description :
 * Controls the DC motor's state and speed.
 * The motor can rotate clockwise (CW), anti-clockwise (A_CW), or stop.
 * Speed is given as a percentage (0-100%).
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
    /* Ensure the speed is capped to 100% */
    if (speed > 100) {
        speed = 100; /* Limit speed to 100% */
    }

    /* Set the motor speed using PWM (ranges from 0 to 100%) */
    PWM_Timer0_Start(speed);

    /* Control motor based on the desired state */
    switch (state) {
    case DC_MOTOR_CW:
        /* Rotate clockwise: IN1 high, IN2 low */
        GPIO_writePin(MOTOR_PORT, MOTOR_PIN1, LOGIC_HIGH);
        GPIO_writePin(MOTOR_PORT, MOTOR_PIN2, LOGIC_LOW);
        break;

    case DC_MOTOR_A_CW:
        /* Rotate anti-clockwise: IN1 low, IN2 high */
        GPIO_writePin(MOTOR_PORT, MOTOR_PIN1, LOGIC_LOW);
        GPIO_writePin(MOTOR_PORT, MOTOR_PIN2, LOGIC_HIGH);
        break;

    case DC_MOTOR_STOP:
    default:
        /* Stop the motor: IN1 low, IN2 low */
        GPIO_writePin(MOTOR_PORT, MOTOR_PIN1, LOGIC_LOW);
        GPIO_writePin(MOTOR_PORT, MOTOR_PIN2, LOGIC_LOW);
        break;
    }
}
