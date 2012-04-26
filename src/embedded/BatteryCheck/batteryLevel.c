/*
 ============================================================================
 Name        : batteryLevel.c
 Author      : Kuhan Loh, Aran Gerami, Denir Leric
 Version     : v 0.2
 Copyright   : Copyright (C) 2011, 2012 Denir Leric
 Description : Battery Check in C
 ============================================================================
 */


#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"


uint8_t check(uint8_t LED_PIN) {

		const static uint8_t SENSOR_PIN = 19;
		uint8_t SENSOR_VALUE = 0;
		uint8_t PERCENTAGE = 0;

		SENSOR_VALUE = analogRead(SENSOR_PIN);
		PERCENTAGE = (SENSOR_VALUE/1023*100) - 16.67;			//Trying to subtract a double variable from a integer, that is wrong.

		  if (SENSOR_VALUE >  0 && SENSOR_VALUE < 204.7){
		   /* digitalWrite(LED_PIN, 1);
		    delay(1000);
		    digitalWrite(LED_PIN, 0);
		    delay(1000);*/
		        //1Volt Remaining
		  } else if (SENSOR_VALUE >  204.6 && SENSOR_VALUE < 409.3){
		   /* digitalWrite(LED_PIN, 1);
		    delay(2000);
		    digitalWrite(LED_PIN, 0);
		    delay(2000);*/
		        //2Volts Remaining
		  } else if (SENSOR_VALUE >  409.2 && SENSOR_VALUE < 613.9){
		    /*digitalWrite(LED_PIN, 1);
		    delay(3000);
		    digitalWrite(LED_PIN, 0);
		    delay(3000);*/
		        //3Volts Remaining
		  } else if (SENSOR_VALUE >  613.8 && SENSOR_VALUE < 818.5){
		    /*digitalWrite(LED_PIN, 1);
		    delay(4000);
		    digitalWrite(LED_PIN, 0);
		    delay(4000);*/
		        //4Volts Remaining
		  } else if (SENSOR_VALUE > 818.4){
		    /*digitalWrite(LED_PIN, 1);*/
		        //5Volts remaining
		  }

	return 0;
}