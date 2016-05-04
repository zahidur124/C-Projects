#include "set.h"
#include <stdio.h>
#include <assert.h>

const int NUM_NUMBERS = 6;
int LOST_NUMBERS[NUM_NUMBERS] = {4,8,15,16,23,42};

const int NUM_SERIES = 8;

int main(void) {
	struct Set *lost = set_create();
	for (int i = 0; i < NUM_NUMBERS; ++i) {
       set_add(lost,LOST_NUMBERS[i]);
	}
	assert(set_size(lost) == NUM_NUMBERS);
	set_print(lost);
	
	struct Set *series = set_create();
	for (int i =1  ; i <= NUM_SERIES; ++i) {
      set_add(series, i);
	}	
	
	struct Set *u = set_union(lost,series);
	struct Set *i = set_intersect(lost,series);
	
	set_print(u);
	set_print(i);
	set_remove(i,4);
	set_print(i);

	set_destroy(lost);
	set_destroy(series);
	set_destroy(u);
	set_destroy(i);
}