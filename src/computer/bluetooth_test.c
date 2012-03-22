// bluetooth_test.c -
//
// Created By: 	Yavor Paunov
// Time:	Tuesday, March 20 2012
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
  inquiry_info *devices = NULL;
  int sel_dev, max_rsp, len;
  char addr[19] = { 0 };

  devices = (inquiry_info*)malloc(255 * sizeof(inquiry_info));
  
  max_rsp = 255;
  len = 6;
  
  list_devices(max_rsp, len, devices);
  printf("Select device to connect:");
  scanf("%d", &sel_dev);
  // Read device number from command linex E.g. 0
  sel_dev = 0;
  
  // Get device address
  ba2str(&(devices+sel_dev)->bdaddr, addr);
  printf("Connecting to %s... \n", addr);
  connect_to_device(addr);
  
  return 0;
}

void init () {
  
}

int list_devices(int max_rsp, int len, inquiry_info *ii) {
  int num_rsp;
  int dev_id, sock, flags;
  int i;
  
  char addr[19] = { 0 };
  char name[248] = { 0 };

  // Assign id of the bt adapter.
  dev_id = hci_get_route(NULL);
  printf("dev id %d \n", dev_id);

  // Assign and open socket.
  sock = hci_open_dev( dev_id );
  if (dev_id < 0 || sock < 0) {
    // Opening socket has failed; exit.
    perror("opening socket");
    exit(1);
  }
  printf("sock %d \n", sock);

  // Flushes the cache of previously detected devices.
  flags = IREQ_CACHE_FLUSH;
    
  // Look for devices and assign to pointer ii. Return number of found devices.
  num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);

  // If number of found devices is less than 0, crash with error.
  if( num_rsp < 0 ) perror("hci_inquiry");

  // Loop through found devices.
  for (i = 0; i < num_rsp; i++) {

    // Convert the bdaddr_t structure of the device to a readable string of the format XX:XX:XX:XX:XX:XX
    ba2str(&(ii+i)->bdaddr, addr);
	
    memset(name, 0, sizeof(name));

    // Get the user friendly name of the device.
    if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), 
			     name, 0) < 0)

      // If name is empty, set to [unknown]
      strcpy(name, "[unknown]");
    printf("%d. %s  %s\n", i, addr, name);
  }
  return 0;
}

int connect_to_device(char dest[18]){
  struct sockaddr_rc addr = { 0 };
  int s, status;
  
  // allocate a socket
  s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

  // set the connection parameters (who to connect to)
  addr.rc_family = AF_BLUETOOTH;
  addr.rc_channel = (uint8_t) 1;
  // str2ba( dest, &addr.rc_bdaddr );

  // connect to server
  status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

  // send a message
  if( status == 0 ) {
    status = write(s, "hello!", 6);
  }

  if( status < 0 ) perror("uh oh");

  return s;
}
