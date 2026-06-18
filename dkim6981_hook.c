/*
 *	C to assembler menu hook
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "common.h"

int dkim6981_add_test(int x, int y, int delay);

void AddTest(int action)
{

  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("Addition Test\n\n"
	   "This command tests new addition function by dkim6981\n"
	   );

    return;
  }
  
  uint32_t delay;         // Declare the variable called "delay"

  int fetch_status;       // Declare the variable called "fetch_status"

  fetch_status = fetch_uint32_arg(&delay); // Get input from user through minicom

  if(fetch_status) 
  {
  	// Use a default delay value
  	delay = 0xFFFFFF;
  }

  // When we call our function, pass the delay value.
  // printf(“<<< here is where we call add_test – can you add a third parameter? >>>”);

  printf("dkim6981_add_test returned: %d\n", dkim6981_add_test(99, 87, delay) );
}

ADD_CMD("dkim6981_add", AddTest,"Test the new add function")

int dkim6981_string_test(char *p);

void dkim6981_StringTest(int action)
{

  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("String Test\n\n"
	   "This command tests new string function by dkim6981\n"
	   );

    return;
  }

  int fetch_status;
  char *destptr;

  fetch_status = fetch_string_arg(&destptr);

  if (fetch_status) {
    // Default logic goes here
    destptr = "TESTING";
  }

  printf("string_test returned: %d\n", dkim6981_string_test(destptr) );
}

ADD_CMD("dkim6981_string", dkim6981_StringTest,"Test the new string function")

// Assignment 2 Prototype
int dkim6981_a2(int num, int wait);

// Assignment 2 C Function
void _dkim6981_Assignment2(int action)
{

  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("Assignment 2\n\n"
	   "This command triggers assignment 2 by dkim6981\n"
	   );

    return;
  }

  // Retrieve user inputs for count and delay here
  uint32_t user_input;
  int fetch_status;

  uint32_t num; // Stores how many times the full LED toggle cycle will repeat.

  fetch_status = fetch_uint32_arg(&user_input); // Read the first argument from minicom as user input.

  if(fetch_status) {
    num = 1; // Default cycle count. One full cycle toggles all 8 LEDs once.
  } 
  else {
    num = user_input;
  }

  uint32_t wait; // Stores the delay value between each LED toggle.

  fetch_status = fetch_uint32_arg(&user_input); // Read the second argument from minicom as user input.

  if(fetch_status){
    wait = 0xFFFFEF; // Default delay value between each LED toggle.
  }
  else {
    wait = user_input;
  }

  printf("dkim6981_a2 returned: %d\n", dkim6981_a2 ((int)num, (int)wait) );
}

ADD_CMD("dkim6981_a2", _dkim6981_Assignment2, "Assignment 2")