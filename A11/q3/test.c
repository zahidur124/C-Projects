/**
 File: test.c
Enter a description for this file.
*/
#include "rexp.h"
#include <stdio.h>

int main(void) {
 struct rexp *r = string_to_rexp("1");
  print_rexp(r);
  printf("%p\n",r);
  printf("%p\n",r->root);
  printf("%c\n",r->root->type);
  rexp_destroy(r);
}