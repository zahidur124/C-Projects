#include "pantry.h"
#include <stdlib.h>
#include <string.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur    
// login ID: zabedin

// implementation:

struct PantryItem {
  char *elem;
  int val;
  struct PantryItem *next;
};

struct Pantry {
  struct PantryItem *list;
};

struct Pantry *pantry_create(void) {
  struct Pantry *new = malloc(sizeof(struct Pantry));
  new->list = NULL;
  return new;
}

char *strduplicate(const char *s) {
  int len = strlen(s);
  char *new = malloc(len +1);
  int i;
  
  for(i=0;i<=len;++i) {
    new[i] = s[i];
  }
  
  return new;
}

void pantry_add(struct Pantry *p, const char *ing, int amt) {
  struct PantryItem *current = p->list;
  
  while(current) {
    
    if (strcmp(current->elem,ing) == 0) {
      current->val += amt;
      return;
    }
    
    current = current->next;
  }
  
  struct PantryItem *new = malloc(sizeof(struct PantryItem));
  
  
  new->elem = strduplicate(ing);
  new->val = amt;
  new->next = p->list;
  p->list = new;
}

int pantry_count(struct Pantry *p, const char *ing) {
  struct PantryItem *current = p->list;
  
  while(current) {
    
    if (strcmp(current->elem,ing) == 0) {
      return current->val;
    
    }
    
    current = current->next;
  }
  
  return 0;
}

void pantry_remove(struct Pantry *p, const char *ing, int amt) {
  
  struct PantryItem *current = p->list;
  
  while(current) {
    
    if (strcmp(current->elem,ing) == 0) {
      current->val -= amt;
      return;
    }
    
    current = current->next;
  }
}

void pantry_destroy(struct Pantry *p) {
  struct PantryItem *current = p->list;
  struct PantryItem *next = NULL;
  
  while(current) {
    
    next = current->next;
    free(current->elem);
    free(current);
    current = next;
    
  }
  
  free(p);
}
  
  