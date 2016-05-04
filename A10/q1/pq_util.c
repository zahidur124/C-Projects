#include "pq.h"
#include "pq_util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur
// login ID: zabedin

// implementation:

void to_array(struct pq *pqueue, int **arr_ptr, int *len) {
  *len = pq_length(pqueue);
  int i;
  
  
  if(pq_is_empty(pqueue) == true) {
    pq_destroy(pqueue);
    return;
  }
  
  *arr_ptr = malloc(sizeof (int)* *len);
  
  for(i=0;i<*len;++i) {
    int temp = pq_remove(pqueue);
    (*arr_ptr)[i] = temp;
  }
  pq_destroy(pqueue);
}
    
struct pq **k_way_split(struct pq *pqueue, const int k) {
  int len = pq_length(pqueue);
  struct pq **arr = malloc(sizeof(struct pq*)*k);
  int i;
  
  for(i=0;i<k;++i) {
    arr[i] = pq_create();
  }
  
  for(i=0;i<len;++i) {
    int temp = pq_front_priority(pqueue);
    pq_add(arr[i%k], pq_remove(pqueue), temp);
  }
  
  pq_destroy(pqueue);
  
  return arr;
}
  
  
  
    
