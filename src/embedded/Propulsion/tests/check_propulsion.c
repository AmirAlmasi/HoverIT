/*
AUTHORS: Yohanes Kuma, Xinran He, Khatereh Khosravianarab
DATA :2012-04-05
DESCRIPTION: This file is the unit tests for the propulsion and propulsion API
functions. check libraries are used as a tool for the unit tests. check their manual for details.
http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
*/
#include <check.h>
#include <propulsion.h>
#include <propulsion_api.h>


void setup (void) {
  //nothing for the moment
}

void teardown (void) {
  //nothing for the moment
}

/* PROPULSION API UNIT TESTS */
START_TEST(Test_Pro){
	fail_if(increase_propulsion() != PERSPEED , "Expected 41");
	fail_if(increase_propulsion() != PERSPEED*2 , "Expected 82");
	fail_if(increase_propulsion() != PERSPEED*3 , "Expected 123");
	fail_if(increase_propulsion() != PERSPEED*3 , "Expected 123");
	 
}END_TEST


START_TEST(test_dec){
	increase_propulsion();
	fail_if(decrease_propulsion(), "Expected 0");
	increase_propulsion();
	increase_propulsion();
	fail_if(decrease_propulsion() != PERSPEED , "Expected 41");
	
}END_TEST


START_TEST(test_fanlevel){
	increase_propulsion();
    fail_if(get_propulsion_level() != 1 ,"Expected 1");
	increase_propulsion();
	increase_propulsion();
	fail_if(get_propulsion_level() != 3 ,"Expected 1");
	decrease_propulsion();
	fail_if(get_propulsion_level() != 2 ,"Expected 2");
}END_TEST


START_TEST(test_stop){
    increase_propulsion();
    fail_if(stop_propulsion_fan() != 0, "Expected 0");
    increase_propulsion();
    increase_propulsion();
    fail_if(stop_propulsion_fan() != 0, "Expected 0");
}END_TEST
 /* END OF PROPULSION API UNIT TESTS */


/* PROPULSION UNIT TESTS */

/* id: 
   purpose: tests init() function of searduino and setting PIN as output
   prerequisites: none
   expected results: 0 will be returned
*/
START_TEST(test_init) {
  fail_unless((initialise_propulsion() == 0),NULL);
 
}END_TEST

/* id: 
   purpose: tests the initialising/preparation state of the propulsion
   prerequisites: the searduino init() function is called
   expected results: 0 will be returned
*/
START_TEST(test_prepare_motor) {
  init_motor();  
  fail_unless((manage_motor() == 0),NULL);
}END_TEST

/* id: 
   purpose: tests the stopped state of the propulsion
   prerequisites: 1. the searduino init() function is called
                  2. the propulsion is in another state
   expected results: 0 will be returned
*/
START_TEST(test_stop_motor) {
  init_motor(); 
  stop_pro_fan();
  fail_unless((manage_motor() == 1),NULL);
}END_TEST

/* id: 
   purpose: tests the boundary speed level of the propulsion
   prerequisites: 1. the searduino init() function is called
                  2. the propulsion is aleardy initialized
		  3. a speed level of 1 is declared
   expected results:1. 2 will be returned from the manage_motor() function
                       showing the propulsion is now in rotating state
		    2. 1 is returned from get_speed_level() showing the speed
		       is now at level 1(Minimum boundary)
*/
START_TEST(test_minimum_speed) {
  int level = 1;
  init_motor(); 
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((get_speed_level() == 1),NULL);  
}END_TEST

/* id: 
   purpose: tests the boundary speed level of the propulsion
   prerequisites: 1. the searduino init() function is called
                  2. the propulsion is aleardy initialized
		  3. a speed level of MAX_SPEED_LEVEL is declared
   expected results:1. 2 will be returned from the manage_motor() function
                       showing the propulsion is now in rotating state
		    2. MAX_SPEED_LEVEL is returned from get_speed_level()
		       showing the speed is now at level MAX_SPEED_LEVEL
		       (Maximum boundary)
*/
START_TEST(test_maximum_speed) {
  int level = MAX_SPEED_LEVEL;
  init_motor(); 
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((get_speed_level() == MAX_SPEED_LEVEL),NULL);  
}END_TEST
/* END OF PROPULSION UNIT TESTS*/


/* Creates test suit for check. see check manual for details
    http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
*/
Suite * propulsion_suite(void) {
  Suite *s = suite_create("Propulsion_fan");
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init);
  tcase_add_test(tc,test_prepare_motor);
  tcase_add_test(tc,test_stop_motor);
  tcase_add_test(tc,test_minimum_speed);
  tcase_add_test(tc,test_maximum_speed);
  tcase_add_test(tc, Test_Pro);
  tcase_add_test(tc, test_dec);
  tcase_add_test(tc, test_fanlevel);
  tcase_add_test(tc, test_stop);
  suite_add_tcase(s,tc);
  return s;
}
