#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your namwe
// Name:Zahidur  
// login ID: zabedin

char *readline(void) {
  char *c;
  if (scanf("%c", &c) != 1) return NULL;
  char *str = malloc(1 * sizeof(char));
  int len = 0;
  do {
    str[len] = c;
    printf("%c\n", str[len]);
    ++len;
    str = realloc(str, (len + 1) * sizeof(char));
    if (c=readline() != NULL) break;
  } while (c != -1);
  str[len] = '\0';
  return str;
}

int main() {
  char *x = readline();
  printf("%s",x);
  free(x);
}