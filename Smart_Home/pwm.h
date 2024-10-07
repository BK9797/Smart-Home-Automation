 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: header file for the ATmega16 PWM driver
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#include "pwm.h"

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
