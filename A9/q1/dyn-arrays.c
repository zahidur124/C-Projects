#include "dyn-arrays.h"
#include <string.h>
#include <stdlib.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zabedin  
// login ID: zabedin

// implementation:

char *my_strappend(const char *s1, const char *s2) {
  int s1_length = strlen(s1);
  int s2_length = strlen(s2);
  int new_length = s1_length + s2_length;
  int i;
  int j = 0;
  
  char *new_str = malloc(s2_length+s1_length+1);
  
  for(i=0;i<s1_length;++i) { 
    new_str[i] = s1[i];
  }
  
  for(;i<new_length;++i,++j) {
    new_str[i] = s2[j];
    
  }
  
  new_str[i] = '\0';
  return new_str;
}

int hex_to_dec(const char h) {
  if(h >= '0' && h<='9') {
    return h-'0';
  }
  
  else {
    return h - 'A' + 10;
  }
}
    
char *hex_to_bin(const char *h) {
  int len = strlen(h);
  char *new_str = malloc(len*4+1);
  int k = 0;
  int j;
  int i;
  
  for(i=0;i<len;++i) {
    int new = hex_to_dec(h[i]);
    int current = 8;
    
    for(j=0;j<4;++j) {
      
      if(new>=current) {
        new_str[k] = '1';
        new-=current;
      }

      else { 
        new_str[k] = '0';
      }
      ++k;
      current /= 2;
    }
  }
  new_str[k] = '\0';
  return new_str;
}

char *hex_to_bin_short(const char *h) {
  int len = strlen(h);
  char *new_str = malloc(len*4+1);
  int k = 0;
  int j;
  int i;
  
  for(i=0;i<len;++i) {
    int new = hex_to_dec(h[i]);
    int current = 8;
    
    for(j=0;j<4;++j) {
      
      if(new>=current) {
        new_str[k] = '1';
        new-=current;
        ++k;
      }

      else { 
        
        if(k != 0) {
          new_str[k] = '0';
          ++k;
        }
      }
      
      current /= 2;
    }
  }
  
  if( k == 0 && len >0) {
    new_str[k] = '0';
    ++k;
  }
  
  new_str[k] = '\0';
  return new_str;
}


    
  
  