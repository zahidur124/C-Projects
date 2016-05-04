#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur
// login ID: zabedin

/*
struct Set {
  char *str;
  int count;
  int size;
};

struct Set *set_create(void) {
  struct Set *new = malloc(sizeof(struct Set));
  
  new->str = malloc(sizeof (char)*4);
  new->count = 0;
  new->size = 4;
  
  return new;
}

void set_destroy(struct Set *s) {
  free(s->str);
  free(s);
}

char *readline(void) {
  char c;
  // get the first char
  if (scanf("%c", &c) != 1) return NULL;
  
  char *str = malloc(1 * sizeof(char));
  int len = 0;
  
  do {
    str[len] = c;
    ++len;
    str = realloc(str, (len + 1) * sizeof(char));
    if (scanf("%c", &c) != 1) break;
  } while (c != -1);
  
  str[len] = '\0';
  return str;
}

int main() {
  char *str = readline();
  printf("%s\n",str);
  free(str);
}
*/


