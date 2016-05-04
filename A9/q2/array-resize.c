#include "array-resize.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur  
// login ID: zabedin

// implementation:


char *replace(char *s, const char *find, const char *rep){
  int i = 0;
  int len1 = strlen(find);
  int len2 = strlen(rep);
  int len3 = strlen(s);
  
  for(;i<len3;++i) {
    if(strncmp(find,s+i,len1) == 0) {
      if(len2 > len1) {
        len3 += len2 - len1;
        s = realloc(s, len3+1);
        
        int j = i + len1;
        int k = i + len2;
        for(; k <= len3; ++k, ++j) {
          s[k] = s[j];
        }
      }
        
      strncpy(s + i, rep, len2);
      i += len2;
    }
  }
  return s;
}  





int *filter(bool (*f)(int), int *a, int *len) {
  int i = 0;
  int j = 0;
  
  for(;i<*len;++i) {
    if(f(a[i])) {
      a[j] = a[i];
      ++j;
    }
  }
  
  if(j == 0) {
    free(a);
    return NULL;
  }
  
  a = realloc(a,j*sizeof(int));
  *len = j;
  return a;
}
    