/*
 * sensors.c
 *
 *  Created on: May 11, 2018
 *      Author: Poornachander
 */

#include "stm32f0xx.h"
#include "sensors.h"
#include "ADC.h"

//ADC is 12-bit right aligned
//Defines for calculations
#define ADC_TO_PIN_VOLTAGE (3.3/4095)

#define ADC_TO_BAT_VOLTAGE	(10090 * ADC_TO_PIN_VOLTAGE)

#define ADC_TO_CURRENT	(((float)121000/4096) * ADC_TO_PIN_VOLTAGE) //121000mA of current when pin is at 3.3V

// Returns value in mV
extern uint16_t Get_Battery_Voltage(battery_t battery) {
	//It would be nice to have decimal places
	uint8_t voltage = 0;

	if(battery == Left_Battery) {
		voltage = Get_ADC_Channel(ADC_Left_Bat_Voltage);
	} else if (battery == Right_Battery) {
		voltage = Get_ADC_Channel(ADC_Right_Bat_Voltage);
	}

	voltage = ADC_TO_BAT_VOLTAGE * voltage;
	return voltage;
}

//Returns value in mA
extern uint16_t Get_Battery_Current(battery_t battery) {
	//It would be nice to have decimal places
	uint8_t current = 0;

	if(battery == Left_Battery) {
		current = Get_ADC_Channel(ADC_Left_Bat_Current);
	} else if (battery == Right_Battery) {
		current = Get_ADC_Channel(ADC_Right_Bat_Current);
	}

	current = ADC_TO_CURRENT * current;
	return current;
}

//Returns value in mA
extern uint16_t Get_System_Current() {
	//This uses an I2C device
}

//Returns value in mA
extern uint16_t Get_Motors_Current() {
	//This uses an I2C device
}

extern uint16_t Get_External_Pressure() {
	//This uses ADC
}

extern uint16_t Get_Internal_Pressure() {
	//This uses an I2C device
}

extern uint16_t Get_Temperature() {
	//This uses an I2C device
}

extern uint16_t Get_Humidity() {
	//This uses an I2C device
}

extern uint16_t Get_Water_Sensor_Value() {
	return Get_ADC_Channel(ADC_Water_Sensor); //Very simple return for now. Functionality can be expanded later as needed.
}