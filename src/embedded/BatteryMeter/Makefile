TEST_DIR=tests
SEARDUINO_PATH = /opt/searduino
PROG = batterymeter

# Add your source files here
SRC_C= alarm.c battery_meter.c four_leds.c percentage.c
SRC_CXX= toneWrapper.cpp
MAIN_SRC = main.c
ARDUINO = mega2560
SHLIB = leds.so

LIB = libleds.a
LIB_H = alarm.h battery_meter.h four_leds.h percentage.h toneWrapper.h
USER_LIB_INSTALL_PATH = ../../../bin

export SRC_FILES= $(SRC_C) $(SRC_CXX)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check:
	$(MAKE) check -C $(TEST_DIR)

gcovcheck:
	$(MAKE) gcovcheck -C $(TEST_DIR)

gcovbcheck:
	$(MAKE) gcovbcheck -C $(TEST_DIR)

memcheck:
	$(MAKE) memcheck -C $(TEST_DIR)

clean-tests:
	$(MAKE) clean-tests -C $(TEST_DIR)

.PHONY: check
