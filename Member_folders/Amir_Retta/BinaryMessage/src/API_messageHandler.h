/*
 * API_messageHandler.h
 *
 *  Created on: Apr 01, 2012
 */

#ifndef API_MESSAGEHANDLER_H_
#define API_MESSAGEHANDLER_H_


/**
 * API function which is called by scheduler
 * Basically when this function is called the bluetooth gets the resources of CPU and
 * it shoud check if there is anything sent to the bluetooth
 */
unsigned char bluetooth_working();

/**
 * API function to create fan forward speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_forward_speed(unsigned char message);

/**
 * API function to create fan hovering speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_hovering_speed(unsigned char message);

/**
 * API function to create ruder direction message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char ruder_direction(unsigned char message);

/**
 * API function to create hovercraft speed (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_speed(unsigned char message) ;

/**
 * API function to create hovercraft pressure (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_pressure(unsigned char message) ;

/**
 * API function to create hovercraft battery level (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char battery_level(unsigned char message);
#endif /* API_MESSAGEHANDLER_H_ */
