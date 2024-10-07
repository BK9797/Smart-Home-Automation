/*
 ============================================================================
 Name        : app.c
 Author      : BISHOY KAMEL
 Date        : 3-10-2024
 Description : Smart Home Automation
 Author		    : BISHOY KAMEL
 ============================================================================
 */
/*******************************************************************************
 *                             Main Function definition                         *
 *******************************************************************************/

#include "adc.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lcd.h"
#include "ldr.h"
#include "leds.h"
#include "lm35_sensor.h"
#include <util/delay.h>

int main(void) {
    /* Variable to store the temperature value read from the sensor */
    uint8 Temp_Value = 0;
    volatile uint8 Flame_detect = 0;
    uint16 Light_value = 0;

    /* Initialize all necessary peripherals */
    ADC_init();          /* Initialize ADC to read analog values from sensors */
    DcMotor_Init();      /* Initialize DC Motor for fan control */
    LCD_init();          /* Initialize LCD display */
    LEDS_init();         /* Initialize LED driver */
    FlameSensor_init();  /* Initialize FLAME_SENSOR driver */
    Buzzer_init();       /* Initialize Buzzer driver */

    /* Clear the LCD screen before starting */
    LCD_clearScreen();

    /* Infinite loop to continuously monitor temperature, flame detection, and control fan & LEDs */
    while (1) {
        /* Get the temperature value from the LM35 sensor */
        Temp_Value = LM35_getTemperature();

        /* Get the light value from the LDR sensor */
        Light_value = LDR_getLightIntensity();

        /* Read the value from the flame sensor */
        Flame_detect = FlameSensor_getValue();

        /* Handle flame detection */
        if (Flame_detect) {
            /* Raise alarm and display alert on the LCD */
            LCD_moveCursor(0, 0);
            LCD_clearScreen();
            LCD_displayString("Critical alert!"); /* Display alert message */

            /* Trigger alarm (buzzer) */
            Buzzer_on();

            /* Stay in the loop until the flame is no longer detected */
            while (Flame_detect) {
                Flame_detect = FlameSensor_getValue();
            }

            /* Once flame is no longer detected, turn off the alarm and clear the alert */
            Buzzer_off();
            LCD_clearScreen();
        }

        /* Control the fan based on the temperature value */
        if (Temp_Value < 25) {
            DcMotor_Rotate(DC_MOTOR_STOP, 0); /* Stop the motor (fan) */
            LCD_moveCursor(0, 3);
            LCD_displayString("FAN is OFF   ");
        }
        else if (Temp_Value < 30) {
            DcMotor_Rotate(DC_MOTOR_CW, 25); /* Fan at 25% speed */
            LCD_moveCursor(0, 3);
            LCD_displayString("FAN is ON    ");
        }
        else if (Temp_Value < 35) {
            DcMotor_Rotate(DC_MOTOR_CW, 50); /* Fan at 50% speed */
            LCD_moveCursor(0, 3);
            LCD_displayString("FAN is ON    ");
        }
        else if (Temp_Value < 40) {
            DcMotor_Rotate(DC_MOTOR_CW, 75); /* Fan at 75% speed */
            LCD_moveCursor(0, 3);
            LCD_displayString("FAN is ON    ");
        }
        else {
            DcMotor_Rotate(DC_MOTOR_CW, 100); /* Fan at 100% speed */
            LCD_moveCursor(0, 3);
            LCD_displayString("FAN is ON    ");
        }

        /* Control LEDs based on light intensity */
        if (Light_value <= 15) {
            LED_on(0);  /* Turn on red LED */
            LED_on(1);  /* Turn on green LED */
            LED_on(2);  /* Turn on blue LED */
        }
        else if (Light_value <= 50) {
            LED_on(0);  /* Red LED ON */
            LED_on(1);  /* Green LED ON */
            LED_off(2); /* Blue LED OFF */
        }
        else if (Light_value <= 70) {
            LED_on(0);  /* Red LED ON */
            LED_off(1); /* Green LED OFF */
            LED_off(2); /* Blue LED OFF */
        }
        else {
            LED_off(0); /* Red LED OFF */
            LED_off(1); /* Green LED OFF */
            LED_off(2); /* Blue LED OFF */
        }

        /* Display temperature on LCD */
        LCD_moveCursor(1, 0);
        LCD_displayString("Temp=");
        LCD_intgerToString(Temp_Value);

        /* Clear any extra characters if Temp_Value has fewer digits */
        if (Temp_Value < 100) {
            LCD_displayCharacter(' '); /* Clears leftover digits */
        }

        /* Display light intensity on LCD */
        LCD_displayString("LDR=");
        LCD_intgerToString(Light_value);
        LCD_displayString("% ");
    }
}
