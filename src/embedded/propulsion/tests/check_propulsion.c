#include <check.h>
#include <stdlib.h>
#include <propulsion.h>

//CalcStatePtr calc = NULL;

void setup (void) {
  //initialise_propulsion();
}

void teardown (void) {
}

START_TEST(test_init) {
  fail_unless((initialise_propulsion() == 0),NULL);
 
}END_TEST

START_TEST(test_prepare_motor) {
  init_motor();  
  fail_unless((manage_motor() == 0),NULL);
}END_TEST

START_TEST(test_stop_motor) {
  init_motor(); 
  stop_pro_fan();
  fail_unless((manage_motor() == 1),NULL);
}END_TEST

START_TEST(test_minimum_speed) {
  int level = 1;
  init_motor(); 
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((getSpeedLevel() == 1),NULL);  
}END_TEST

START_TEST(test_maximum_speed) {
  int level = MAX_SPEED_LEVEL;
  init_motor(); 
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((getSpeedLevel() == MAX_SPEED_LEVEL),NULL);  
}END_TEST

Suite * propulsion_suite(void) {
  Suite *s = suite_create("Propulsion_fan");
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init);
  tcase_add_test(tc,test_prepare_motor);
  tcase_add_test(tc,test_stop_motor);
  tcase_add_test(tc,test_minimum_speed);
  tcase_add_test(tc,test_maximum_speed);
  suite_add_tcase(s,tc);
  return s;
}
main(void) {
  int number_failed;
  Suite *s = propulsion_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
