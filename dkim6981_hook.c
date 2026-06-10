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