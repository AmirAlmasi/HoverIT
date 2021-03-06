/*!
 @file pc_log.c 
 @headerfile pc_log.h
 @details This module is to provide logfile APIs for recoding the log info in .text file on PC side during execution.
 @author Jianfeng Xie
 @author Siyang Suo
 @version 0.3
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include "pc_log.h"



FILE *g_ptr= NULL;
char *g_file = "log.txt";

/*!
 @brief A function is called to initilize .txt file, which stores log information.
 Before starting to record log information.
 It creats a .txt file named "log.txt", if it didn't exist; or reopen "log.txt" file, if it existed.
 @param void
 @return void
 */
void init_log_file(){	
	
	g_ptr = fopen(g_file, "a");
	if (g_ptr == NULL) printf("Error in opening a file..",g_file); /* if opening file failed, print error info */
}

/*!
 @brief A function is called to close and save .txt file, which stores log information.
 When log recording finished
 @param void
 @return void
 */
void close_log_file(){
		
    fclose(g_ptr);
}

/*!
 @brief A function is called to delet .txt file, which stores log information.
 @param void
 @return void
 */
void delet_log_file(){
	remove(g_file);
}

/*!
 @brief A function is called to get the currently local time.
 @param void
 @return A pointer to char, which contains 
 */
char* get_time(){
	char *str = malloc(sizeof(char*));	/*string to contain time */
	time_t the_time;
    struct tm *tp;
    the_time = time(NULL);
 	tp = localtime(&the_time);  /*get the pointer of curret time*/
	sprintf(str, "%2.2d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d", tp->tm_year+1900, 
	tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);  /* convert tiime into string formate */
	//printf("Time: %s \n", str);
	return str;

	free(str);	
}

/*!
 @brief A function is called to write one line of string in .txt file.
 @param A pointer to char, which contains one line of log information.
 @return void
 */
void log_file_writer(char *buf){
	size_t len = 0;
  	len = strlen(buf);
	fwrite(buf, len, 1, g_ptr);      /*wirte one line in file*/
	//printf("\n Written Successfuly in the file.\n");

}

/*!
 @brief A function is externally called to send a log message to .txt file.
 @param A pointer to char, which contains tag
 @param A pointer to char, which contains message
 @param A pointer to char, which contains function name
 @return void
 */

void log_to_file(char* tag, char* message, char *function ){	
	
	char temp[100]; /*one line of log information*/			
	log_obj log = {tag, message,function};  /*add log information in log object*/
	//printf("log_level: %s, info: %s, function: %s \n",log.tag, log.info, log.function);
	sprintf(temp,"%s, %s, %s, %s  \n",get_time(),log.tag, log.info, log.function);	/*constaract the strings*/	
	log_file_writer(temp); /* wirte one line in file*/
}

void main(){
	
	init_log_file();
	sleep(1);		
	log_to_file("Info","turn off","moter");
	sleep(1);
	log_to_file("Error","Connection fail","scheduel");
	sleep(1);
	log_to_file("Warning","wtf","fan");
	close_log_file();
	//delet_log_file();
}
