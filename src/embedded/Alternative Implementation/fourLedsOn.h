/*
 * @ Module name:  fourLedsOn.h
 * @ Description:  Header file for fourLedsOn.c
 * @ Author names :Nahid Vafaie
 * @ Release      :13 April 2012
 * @ Version      : 2
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#ifndef FOUR_LEDS_ON_H
#define FOUR_LEDS_ON_H
#define ledPin1 2
#define ledPin2  4
#define ledPin3  7
#define ledPin4  8


void init_leds(void);
void run_leds(void);
void display_percentage(int); //added by bruce


#endif