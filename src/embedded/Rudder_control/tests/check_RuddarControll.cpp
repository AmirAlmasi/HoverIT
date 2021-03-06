/*
 * @file check_RuddarControll.cpp
 * @brief: Test cases to test rudder control module.
 * @author: Paulius Vysniauskas, David Giorgidze.
 * @date: 2012-04-04.
 */

#include <check.h>
#include "../RuddarControll.h"
#include "check_RuddarControll.h"

/*
 * ID: 1. 
 * Purpose: check if rudder setup succeeds.
 * Prerequisites: none.
 * Action: hovercraft is started.
 * Expected outcomes: 0 is returned, rudders centered and ready.
 */
START_TEST (test_setup)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
}
END_TEST

/*
 * ID: 2. 
 * Purpose: test hard right turn.
 * Prerequisites: rudders should be centered.
 * Action: command "2" received.
 * Expected outcomes: 2 is returned, rudders turned right to 30 deg position.
 */
START_TEST (test_hard_right)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_unless(r->setHardRight()== 2, "FAILED: Set Hard Right");
}
END_TEST

/*
 * ID: 3.
 * Purpose: test hard left turn.
 * Prerequisites: rudders should be centered.
 * Action: command "1" received.
 * Expected outcomes: 3 is returned, rudders turned left to 150 deg position.
 */
START_TEST (test_hard_left)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_unless(r->setHardLeft()== 3, "FAILED: Set Hard Left");
}
END_TEST

/*
 * ID: 4.
 * Purpose: test setting current rudder position.
 * Prerequisites: none.
 * Action: command, other that defined ones, is received.
 * Expected outcomes: 4 is returned, rudders keep same position.
 */
START_TEST (test_set_current)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_unless(r->setCurrent()== 4, "FAILED: Set Current direction");
}
END_TEST

/*
 * ID: 5.
 * Purpose: test centering rudders.
 * Prerequisites: preferably rudders not centered.
 * Action: command "0" received.
 * Expected outcomes: 5 is returned, rudders are centered to initial position.
 */
START_TEST (test_set_straight)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_unless(r->setStraight()== 5, "FAILED: Set Straight");
}
END_TEST

/*
 * ID: 6.
 * Purpose: test braking.
 * Prerequisites: rudders not in brake position.
 * Action: command "5" received.
 * Expected outcomes: 6 is returned, rudders are "closed" to stop hovercraft.
 */
START_TEST (test_set_brake)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_unless(r->setBrake()== 6, "FAILED: Set Brake fault");
}
END_TEST

/*
 * ID: 7.
 * Purpose: test soft left turn.
 * Prerequisites: rudders should be preferably centered.
 * Action: command "4" received.
 * Expected outcomes: a) 7 is returned and rudders turned left by 15 deg
 * 		      when rudders are not on left side boundary.
 *		      b) 8 is returned and rudders keep same position
 *		      when rudders are on left side boundary.
 */
START_TEST (test_soft_left)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_unless(r->setSoftLeft()== 7, "FAILED: Set Soft Left");
  r->setHardLeft();
  fail_unless(r->setSoftLeft()== 8, "FAILED: Crossing boundary, 150 deg left limit");
}
END_TEST

/*
 * ID: 8.
 * Purpose: test soft right turn.
 * Prerequisites: rudders should be preferably centered.
 * Action: command "3" received.
 * Expected outcomes: a) 9 is returned and rudders turned right by 15 deg
 * 		      when rudders are not on right side boundary.
 *		      b) 10 is returned and rudders keep same position
 *		      when rudders are on right side boundary.
 */
START_TEST (test_soft_right)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_unless(r->setSoftRight()== 9, "FAILED: Set Soft Right");
  r->setHardRight();
  fail_unless(r->setSoftRight()== 10, "FAILED: Crossing boundary, 30 deg right limit");
}
END_TEST

/*
 * ID: 9.
 * Purpose: test handling wrong command inputs, others than predefined.
 * Prerequisites: none.
 * Action: not predefined command received.
 * Expected outcomes: 11 returned, rudders keep same position.
 */
START_TEST (test_wrong_command)
{
  RuddarControll *r = new RuddarControll();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
  fail_if(r->controllRuddar(-1) != 11, "FAILED: Wrong command input(-1) not handled");
  r->setStraight();
  fail_if(r->controllRuddar(6) != 11, "FAILED: Wrong command input(6) not handled");
  r->setStraight();
  fail_if(r->controllRuddar(111) != 11, "FAILED: Wrong command(111) input not handled");
}
END_TEST

Suite * rudder_suite(void) {
  Suite *s = suite_create("Rudder Control RC");
  TCase *tc = tcase_create("RC test case");
  tcase_add_test(tc, test_setup);
  tcase_add_test(tc, test_hard_right);
  tcase_add_test(tc, test_hard_left);
  tcase_add_test(tc, test_set_current);
  tcase_add_test(tc, test_set_straight);
  tcase_add_test(tc, test_set_brake);
  tcase_add_test(tc, test_soft_left);
  tcase_add_test(tc, test_soft_right);
  tcase_add_test(tc, test_wrong_command);
  suite_add_tcase(s, tc);
  return s;
}
