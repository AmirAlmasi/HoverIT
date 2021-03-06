/*
   This file is part of Hoverit.

   Hoverit is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hoverit is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Hoverit.  If not, see <http://www.gnu.org/licenses/>.
*/
/*!
 @file main.c
 @headerfile stdio.h
 @headerfile Arduino.h
 @headerfile searduino.h
 @headerfile API_communication_controler.h
 @headerfile Theta-API.h
 @headerfile hover_api_stub.h
 @headerfile propulsion_api.h
 @headerfile steering.h
 @details This module is the main module to run the program. The way it is written it should work for arduino board as well.
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.3
 @note putting pins to high and low is only for implementing simple scheduler
 @see for more information about searduino and implementation of this main file
 check the following link: http://itupw185.itu.chalmers.se/searduino/?page_id=16
 */
#include <stdio.h>
#include <Arduino.h>
#include <searduino.h>
#include <API_communication_controler.h>
//#include <Theta-API.h>
//#include <hover_api_stub.h>
//#include <propulsion_api.h>
//#include <steering.h>

int main(int argc, char** argv) {
	init(); // init of the arduino
	pinMode(13, OUTPUT); // This is for testing to simulate small scheduler
	communication_serial_setup();
	//        start_propulsion_fan();
	//        start_hover();
	//        control_rudder(0);

	for (;;) {
//		control();
		check_serial_input();
		digitalWrite(13, HIGH);
		delay(500);
		digitalWrite(13, LOW);
		delay(500);
	}
	return 0;
}
