
/***************************************************************************
 * Copyright (C) 2012  Seyed Ehsan Mohajerani
 *                     Navid Amiriarshad
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
 @file hovering_control.c
 @headerfile hovering_control.h
 @brief This module contains the functions that control the hovering fan
 speed.
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @version 0.9
 @date 20 March 2012
 @see Arduino.cc
 @see sandklef.com
 @see hoveritu.com
 @see dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @see Turnigy_Plush_and_Sentry_ESC user manual
 @see reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard
 .html
 @see reference for commenting stack.nl/~dimitri/doxygen/commands
 .html#cmdparam
 */

#include <Arduino.h>
#include <hovering_motor.h>
#include <hovering_control.h>
#include <hovering_init_fix.h>
#include <print_audible_test.h>

/* The minimum PWM value that is possible to send to ESC from Arduino pin
 and it is for initiating the motor */
#define THROTTLE_STICK_BOTTOM_LEVEL 100

/* The PWM value which is sent to ESC from Arduino and represents the motor
 rotating power it can be between 143 (for lowest rotating speed) and 254
(for the highest rotating speed */
int g_throttle_stick_level = 0;

/* Start the motor */
int start(int using_pin, int test_pin) {
	/* Set the level to 100 or Start the hovering motor*/
	if (g_throttle_stick_level < THROTTLE_STICK_BOTTOM_LEVEL){
		throttle_stick_bottom(using_pin, test_pin);
		/* Test code */	
		test_start (test_pin);
		return 0;	
	} else {
		/* Test code */
		test_motor_already_started (test_pin);
		return 0;
	}
}

/* Set the level to 100 or start the motor \
if the motor has not been started (The minimum acceptable value for ESC) */
int throttle_stick_bottom (int using_pin, int test_pin) {
	g_throttle_stick_level = THROTTLE_STICK_BOTTOM_LEVEL;
	set_level (using_pin, test_pin, g_throttle_stick_level);
	delay (1000);
	/* Test code */
	#if defined STUB_TEST
		test_throttle_Stick_is_bottom (test_pin);
	#endif
	return 0;
}

/* Set the level to 143 or set the motor to lowest rotating speed */
int normal (int using_pin,int test_pin){
	g_throttle_stick_level = LOWEST_LEVEL;
	set_level (using_pin, test_pin, g_throttle_stick_level);
	/* Test code */
	test_normal (test_pin);
	return 0;
}

/* Set the level to 254 or set the motor to highest rotating speed */
int turbo (int using_pin,int test_pin){
	g_throttle_stick_level = HIGHEST_LEVEL;
	set_level (using_pin, test_pin, g_throttle_stick_level);
	/* Test code */
	test_turbo (test_pin);
	return 0;
}

/* Set the level to 120 or stop the motor */
int stop (int using_pin, int test_pin){
	g_throttle_stick_level = STOP_LEVEL;
	set_level (using_pin, test_pin, g_throttle_stick_level);
	/* Test code */
	test_stop (test_pin);
	return 0;
}

/* Increase the motor rotating speed level times */
int increase (int using_pin, int test_pin, int level){
	g_throttle_stick_level = check_and_fix_level_increase(using_pin, \
	test_pin, g_throttle_stick_level, level);
	//set_fixed_level (using_pin, test_pin, g_throttle_stick_level);
	/* Test code */
	#if defined STUB_TEST
		test_increase (g_throttle_stick_level);
	#endif
	return 0;
}

/* decrease the motor rotating speed level times */
int decrease (int using_pin, int test_pin, int level){
	g_throttle_stick_level = check_and_fix_level_decrease (using_pin, \
	test_pin, g_throttle_stick_level, level);
	/* Test code */
	#if defined STUB_TEST
		test_decrease (g_throttle_stick_level);
	#endif
	return 0;
}

/* set the motor rotating speed to specified level */
int set_level(int using_pin, int test_pin, int level){
	pin_program (using_pin, test_pin, g_throttle_stick_level);
	/* Test code */
	#if defined STUB_TEST
		test_set_level (g_throttle_stick_level);
	#endif
	return 0;
}

/* set the motor rotating speed to specified to the level which
	fixed to be no higher than 254 and no lower than 143*/
int set_fixed_level (int using_pin, int test_pin, int level){
	g_throttle_stick_level = level;
	check_and_fix_level (using_pin, test_pin, g_throttle_stick_level);
	set_level (using_pin, test_pin, g_throttle_stick_level);
	/* Test code */
	#if defined STUB_TEST
		test_set_level (g_throttle_stick_level);
	#endif
	return 0;
}
