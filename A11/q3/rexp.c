#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
#include "rexp.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur
// login ID: zabedin

// implementation:

void eat_space(const char *s, int *tracker) {
  while(s[*tracker] == ' ') {
    ++(*tracker);
  }
}

void eat_word(const char *s, int *tracker) {
  while((s[*tracker] >= 'A' && s[*tracker] <= 'Z') ||
        (s[*tracker] >= 'a' && s[*tracker] <= 'z')) {
    ++*tracker;
  }
}

void eat_num(const char *s, int *tracker) {
  while(s[*tracker] == '-' || (s[*tracker] >= '0' && s[*tracker] <= '9')) {
    ++*tracker;
  }
}

struct enode *string_to_enode(const char *s, int *tracker) {
  eat_space(s,tracker);
  
  char op = s[*tracker];
  if(op == '\n' || op == '\0') {
    return NULL;
  }
  
  if(op == '-' || (op >= '0' && op <= '9')) {
    struct enode *new = malloc(sizeof(struct enode));
    new->type = 'n';
    new->left = NULL;
    new->right = NULL;
    sscanf(s+*tracker,"%d", &(new->number));
    eat_num(s,tracker);
    return new;
  }
  
  if(op == '(') {
    struct enode *new = malloc(sizeof(struct enode));
    ++*tracker;
    eat_space(s,tracker);
    new->type = s[*tracker];
    ++*tracker;
    new->left = string_to_enode(s,tracker);
    new->right = string_to_enode(s,tracker);
    eat_space(s,tracker);
    ++*tracker;
    return new;
  }
  
  struct enode *new = malloc(sizeof(struct enode));
  eat_space(s,tracker);
  new->type = 'v';
  int temp = *tracker;
  eat_word(s,tracker);
  strncpy(new->id,s+temp,*tracker-temp);
  new->id[*tracker-temp] = '\0';
  return new;  
}

struct rexp *string_to_rexp(const char *s) {
  int offset = 0;
  struct enode *temp = string_to_enode(s, &offset);
  
  if(temp == NULL) {
    return NULL;
  }
  
  struct rexp *new = malloc(sizeof(struct rexp *));
  new->root = temp;
  return new;
}

int eval(const struct enode *r, const struct dictionary *constants) {
  if(r->type == 'v') {
    return dict_lookup(r->id,constants);
  }
  
  if(r->type == 'n') {
    return r->number;
  }
  
  int temp = eval(r->left,constants);
  int temp2 = eval(r->right,constants);
  
  if(r->type == '+') {
    return temp + temp2;
  }
  
  if(r->type == '-') {
    return temp - temp2;
  }
  
  if(r->type == '/') {
    return temp / temp2;
  }
  
  if(r->type == '*') {
    return temp * temp2;
  }
  return 0;
}
  

int rexp_eval(const struct rexp *r, const struct dictionary *constants) {
  return eval(r->root,constants);
}

void free_node(struct enode *n) {
  if(n->type == '+' || n->type == '-' || n->type == '*' || 
     n->type == '/') {
    free_node(n->left);
    free_node(n->right);
  }
  
  free(n);
}

void rexp_destroy(struct rexp *r) {
  free_node(r->root);
  free(r);
}


void add_constant(const char *s, struct dictionary *constants) {
  int counter = 0;
  eat_space(s,&counter);
  ++counter;
  eat_space(s,&counter);
  eat_word(s,&counter);
  eat_space(s,&counter);
  
  int temp = counter;
  eat_word(s,&counter);
  char arr[21];
  strncpy(arr,s+temp,counter-temp);
  arr[counter-temp] = '\0';
  struct enode *new = string_to_enode(s,&counter);
  int store = eval(new,constants);
  free_node(new);
  dict_add(arr,store,constants);
}


///////////////////////////////////////////////////////////////////////
// do NOT modify these functions: they are used for marmoset testing //
// (you may find them useful for your own testing)                   //
///////////////////////////////////////////////////////////////////////

void print_enode(const struct enode *e) {
  assert(e);
  if (e->type == 'n') {
    printf("%d", e->number);
  } else if (e->type == 'v') {
    printf("%s", e->id);
  } else {
    printf("(%c ", e->type);
    print_enode(e->left);
    printf(" ");
    print_enode(e->right);
    printf(")");
  }
}

void print_rexp(const struct rexp *r) {
  assert(r);
  print_enode(r->root);
  printf("\n");
}
