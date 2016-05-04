#include "set.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur
// login ID: zabedin

// implementation:


struct Set {
  int *elem;
  int count;
  int size;
};

struct Set *set_create(void) {
  struct Set *new = malloc(sizeof(struct Set));
  
  new->elem = malloc(sizeof (int)*4);
  new->count = 0;
  new->size = 4;
  
  return new;
}

void set_destroy(struct Set *s) {
  free(s->elem);
  free(s);
}
  
int set_size(const struct Set *s) {
  return s->count;
}

void set_add(struct Set *s, int i) {
  int j;
  
  if(s->size == s->count) {
    s->size *= 2;
    s->elem = realloc(s->elem,s->size*sizeof(int));
  }
  
  for(j=0;j<s->count;++j) {
    
    if(s->elem[j] == i) {
    return;
    }
    
    if(s->elem[j] > i) {
      int temp = s->elem[j];
      s->elem[j] = i;
      i = temp;
    }
    
  }
  
  s->elem[j] = i;
  ++s->count;
}

void set_remove(struct Set *s, int i) {
  int j;
  int len = s->count;
  
  for(j=0;j<len;++j) {
    if(s->elem[j] == i) {
      break;
    }
  }
  
  if(j == len) {
    return;
  }
  
  --s->count;
  
  for(;j<s->count;++j) {
    s->elem[j] = s->elem[j+1];
  }
}
  
  
struct Set *set_union(const struct Set *s1, const struct Set *s2) {
  int i=0;
  int j=0;
  int len1 = s1->count;
  int len2 = s2->count;
  
  struct Set *new = malloc(sizeof(struct Set));
  new->size = len1+len2;
  new->elem = malloc(sizeof(int)*new->size);
  new->count = 0;
  
  while(i<len1 || j<len2) {
    
    if(i == len1) {
      new->elem[new->count] = s2->elem[j];
      ++new->count;
      ++j;
    } 
    
    else if(j == len2) {
      new->elem[new->count] = s1->elem[i];
      ++new->count;
      ++i;
    }
    
    else if(s1->elem[i] == s2->elem[j]) {
      new->elem[new->count] = s1->elem[i];
      ++new->count;
      ++i;
      ++j;
    }
    
    else if(s1->elem[i] < s2->elem[j]) {
      new->elem[new->count] = s1->elem[i];
      ++new->count;
      ++i;
    }
    
    else if(s1->elem[i] > s2->elem[j]) {
      new->elem[new->count] = s2->elem[j];
      ++new->count;
      ++j;
    }
  }
  
  return new;
}


struct Set *set_intersect(const struct Set *s1, const struct Set *s2) {
  int i=0;
  int j=0;
  int len1 = s1->count;
  int len2 = s2->count;
  
  struct Set *new = malloc(sizeof(struct Set));
  new->size = len1;
  new->elem = malloc(sizeof (int)*new->size);
  new->count = 0;
  
  while(i<len1 && j<len2) {

    if(s1->elem[i] == s2->elem[j]) {
      new->elem[new->count] = s1->elem[i];
      ++new->count;
      ++i;
      ++j;
    }
    
    else if(s1->elem[i] < s2->elem[j]) {
      ++i;
    }
    
    else if(s1->elem[i] > s2->elem[j]) {
      ++j;
    }
  }
  
  return new;
}  

void set_print(const struct Set *s) {
  // [1,2,3]
  int i;
  int len = s->count;
  
  printf("[");
  
  for(i=0;i<len;++i) {
    printf("%d",s->elem[i]);
    
    if(i<len-1) {
      printf(",");
    }
    
  }
  
  
  printf("]\n");
}


