TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Bluetooth

# Add your source files here
SRC_C= bluetooth_command.c communication_controler.c message_handler.c
SRC_CXX= serial_interface.cpp
MAIN_SRC = main.c
ARDUINO = mega2560
SHLIB = bluetooth.so

LIB = libbluetooth.a
LIB_H = pin.h communication_controler.h conventions.h message_handler.h serial_interface.h API_communication_controler.h
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
