/*
 * @ Module name:  propulsion_api.c
 * @ Description:  control fan speed api.
 *
 * @ Author names : Xinran He, Khatereh Khosravianarab
 * @ Release      : 25 March 2012
 * @ Version      : 2.0
 */


#include <stdio.h>

#include <propulsion.h>
#include <propulsion_api.h>

/* increase propulsion fan speed */
int increase_speed(){
  int speed = getSpeedLevel();
  if(speed >= MAXSPEED - 3){
    change_pro_speed(PERSPEED*3);
     return PERSPEED*3;
  }
  if( speed < MAXSPEED){
    change_pro_speed(speed + PERSPEED);
     return speed+PERSPEED;
  }
  return -1;
}

/* decrease propulsion fan speed */
int decrease_speed(){
  int speed = getSpeedLevel();
  if(speed <= 0){
    stop_pro_fan();
    return 0;
  }
  if(speed > 4){
    change_pro_speed(speed - PERSPEED);
    return speed - PERSPEED;
  }
  return -1;
}

/* stop propulsion fan speed*/
int stop_speed(){
  stop_pro_fan();
  return 0;
}

/* specify the propulsion fan level*/
int get_fan_level(){
  int speed = getSpeedLevel();
  if(speed == 0){
    printf("get_fan_level() ========= 0\n");
    return 0;
  }
  if(speed > 0 && speed <= PERSPEED){
    printf("get_fan_level() ========= 1\n");
    return 1;
  }
  if(speed > PERSPEED && speed <= PERSPEED * 2){
    printf("get_fan_level() ========= 2\n");
    return 2;
  }
  if(speed >PERSPEED *2 ){
    printf("get_fan_level() ========= 3\n");
    return 3;
  }  
  return -1;
}


