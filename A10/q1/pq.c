#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name
// Name: Zahidur
// login ID: zabedin

// implementation:

struct pq {
  struct prioq *pqlist;
  int length;
};

struct prioq {
  int val;
  int prio;
  struct prioq *next;
};


struct pq *pq_create(void) {
  struct pq *new = malloc(sizeof(struct pq));
  
  new->pqlist = NULL;
  new->length = 0;
  
  return new;
}

void pq_destroy(struct pq *pqueue) {
  struct prioq *new = pqueue->pqlist;
  
  while(new != NULL) {
    struct prioq *temp = new->next;
    free(new);
    new = temp;
  }
  
  free(pqueue);
}

struct prioq *prioq_add(struct prioq *pq, int item, int priority) {
  
  if(pq == NULL || pq->prio > priority) {
    struct prioq *new = malloc(sizeof(struct prioq));
    new->val = item;
    new->prio = priority;
    new->next = pq;
    return new;
  }
  
  pq->next = prioq_add(pq->next, item, priority);
  return pq;
}

void pq_add(struct pq *pqueue, int item, int priority) {
  pqueue->pqlist = prioq_add(pqueue->pqlist,item,priority);
  ++pqueue->length;  
}

int pq_remove(struct pq *pqueue) {
  int val = pqueue->pqlist->val;
  struct prioq *new = pqueue->pqlist;
  pqueue->pqlist = pqueue->pqlist->next;
  free(new);
  return val;
}

bool pq_is_empty(const struct pq *pqueue) {
  return pqueue->length == 0;
}

void prioq_print(const struct prioq *pqueue) {
  
  if(pqueue == NULL) {
    return;
  }
  
  int temp = pqueue->prio;
  printf("[%d]", temp);
  
  while(pqueue != NULL && pqueue->prio == temp) {
    printf(" %d", pqueue->val);
    pqueue = pqueue->next;
  }
  
  printf("\n");
  prioq_print(pqueue);
}

void pq_print(const struct pq *pqueue) {
  prioq_print(pqueue->pqlist);
}

int pq_length(const struct pq *pqueue) {
  return pqueue->length;
}

int pq_front_priority(const struct pq *pqueue) {
  return pqueue->pqlist->prio;
}

int pq_front_item(const struct pq *pqueue) {
  return pqueue->pqlist->val;
}

  
  
  
  
  







