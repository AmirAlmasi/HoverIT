/* 
 * @ Module name:  hovering_motor.c
 * @ Description:  Contains the functions that controls the hovering fan speed.
 *               
 * @ Author names :Seyed Ehsan Mohajerani - Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      :
 * @ Refrences    :
 */


// Includes
#include "hovering_motor.h"

// Variables
int throttle_stick_level=100;
boolean start_check=true;

// Main
int main(void){	
	hovering_motor(start);
	#ifdef STUB_TEST
		printf("			Test Main L: %d \n",
	throttle_stick_level);
	#endif	
	return 1;
}

// Internal functions

int hovering_motor_func(int (*f)(void)){
	// Initialize the Arduino
	init();
	// Assign using pin to output	
	pinMode(using_pin,OUTPUT);
	#ifdef STUB_TEST
		printf("			Test output \n");
	#endif
	// Start the motor

	/* Set the throttle stick is in the buttom position if the motor 
	   has not been started */
	
	turbo();
	#ifdef STUB_TEST
		printf("			Test function \n");
	#endif
	delay(1000);
	
	// Loop for Arduino
	#ifdef STUB_TEST
		printf("			Test TSL: %d \n",
		throttle_stick_level);
	#endif
	/* for(;;){
	decrease(10);
	delay(1000);
	#ifdef STUB_TEST
		printf("			Test Loop \n");
	#endif	
	}
	return 0;*/	
}	

int pin_program(int level) {
	analogWrite(using_pin,level);
	#ifdef STUB_TEST
		printf("			Test an. wr. \n");
	#endif
return 0;
}

int start(void){
	if (start_check||(throttle_stick_level<100)){
		throttle_stick_bottom();
	}
	else {
	#ifdef STUB_TEST
		printf("			Test motor started before \n");
	#endif
	}
return 0;
}

int throttle_stick_bottom(){
	pin_program(throttle_stick_bottom_level);
	delay(1000);
	start_check=false;
	#ifdef STUB_TEST
		printf("			Test T S L bottom \n");
	#endif
return 0;
}

int normal(void){
	throttle_stick_level=133;
	pin_program(throttle_stick_level);
	#ifdef STUB_TEST
		printf("			Test normal \n");
	#endif
return 0;
}

int turbo(void){
	throttle_stick_level=254;
	pin_program(throttle_stick_level);
	#ifdef STUB_TEST
		printf("			Test turbo \n");
	#endif
return 0;
}

int stop(void){
	throttle_stick_level=100;
	pin_program(throttle_stick_level);
	#ifdef STUB_TEST
		printf("			Test stop \n");
	#endif
return 0;
}

int increase(int level){
	throttle_stick_level=throttle_stick_level+level;
	check_and_fix_level();
	pin_program(throttle_stick_level);
	#ifdef STUB_TEST
		printf("			Test INC New L: %d \n",
		throttle_stick_level);
	#endif
return 0;
}

int decrease(int level){
	throttle_stick_level=throttle_stick_level-level;		
	check_and_fix_level();
	pin_program(throttle_stick_level);
	#ifdef STUB_TEST
		printf("			Test DEC New L: %d \n",
		throttle_stick_level);
	#endif
return 0;
}

int climb(int level){
	throttle_stick_level=level;
	check_and_fix_level();
	pin_program(throttle_stick_level);
	#ifdef STUB_TEST
		printf("			Test climb New L: %d \n",
	throttle_stick_level);
	#endif
return 0;
}

int descend(int level){
	throttle_stick_level=level;
	check_and_fix_level();
	pin_program(throttle_stick_level);
	#ifdef STUB_TEST
		printf("			Test Des New L: %d \n",
	throttle_stick_level);
	#endif
return 0;
}

// This function never lets the motor to stop
int check_and_fix_level(){
	if (throttle_stick_bottom_level<133){
		normal();
	#ifdef STUB_TEST
		printf("			Test Too low New L: %d \n",
	throttle_stick_level);
	#endif
	}
	if (throttle_stick_bottom_level>254){
		turbo();
	#ifdef STUB_TEST
		printf("			Test Too high New L: %d \n",
	throttle_stick_level);
	#endif
	}
return 0;
}

/////refrence user guide motor
