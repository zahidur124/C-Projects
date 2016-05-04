#include "dyn-arrays.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
	
	// Basic test for 1(a)
	char *test = my_strappend("Hello", ", World!");
	assert(strcmp(test, "Hello, World!") == 0);
	free(test);
	
	// Basic test for 1(b)
	
	test = hex_to_bin("01E");
	assert(strcmp(test,"000000011110") == 0);
	free(test);
	
	// Basic test for 1(c)
	
	test = hex_to_bin_short("01E");
	assert(strcmp(test,"11110") == 0);
	free(test);
	test = hex_to_bin_short("0");
	assert(strcmp(test,"0") == 0);
	free(test);
}
