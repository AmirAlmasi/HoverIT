/*
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-19
Description: the main to execute pressure_loop
*/

/* Includes */
#include <Arduino.h>
#include <searduino.h>
#include <hover_api.h>

int main(void) {
        init();
	//for (;;) {	
		start_hover();
		increase_hover();
		stop_hover();
	//}
	return 0;
}
