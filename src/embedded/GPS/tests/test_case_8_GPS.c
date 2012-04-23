
/**
  Author: Fangzhou Cao
  Date: 23-04-2012     Version:0.1
**/


#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "gps.h"

#define LINEMA 300

/**
 ID:8
 Purpose: to test get_time(char*) and get_position(char*).
 Preparation: Get fake GPS data from GPS simulator.
 Action: pass the fake GPS data to those two functions and check the return values.
 Expected outcome: time != NULL, position != NULL.
  
**/




START_TEST(GPS_test_1) {

char* linema;
char* time;
struct position* position;

linema  = malloc(LINEMA*sizeof(char));
linema = read_rmc_data(); 


time = get_time(linema);
printf("TIME: %s\n", time);

position = get_position(linema);
printf("POSITION: %f, %f, %c, %c\n", position->longitude, position->latitude, position->ns, position->ew);
        
fail_if(time == NULL,"time is null");
fail_if(position == NULL," position is null");


free(time);
free(position);      



}END_TEST


Suite * new_suite(void) { 

   Suite *suite = suite_create("GPS_test_suite");	 
   TCase *tcase = tcase_create("GPS_test_case_8"); 
   tcase_add_test(tcase, GPS_test_1); 
   suite_add_tcase(suite,tcase); 
   return suite; 
 } 


 int main(void) { 

   int number_failed; 
   Suite *suite = new_suite(); 
   SRunner *suiter = srunner_create(suite); 
   srunner_run_all(suiter,CK_NORMAL); 
   number_failed = srunner_ntests_failed(suiter); 
   srunner_free(suiter); 
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; 
 }  
