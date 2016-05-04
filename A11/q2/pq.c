#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur
// login ID: zabedin

// implementation:

struct node {
  int val;
  int prio;
};

struct pq {
  struct node **node;
  int index;
  int total;
};

struct pq *pq_create(void) {
  struct pq *new = malloc(sizeof(struct pq));
  new->node = malloc(sizeof(struct node *) * 4);
  new->total = 0;
  new->index = 4;
  return new;
}

void pq_destroy(struct pq *pqueue) {
  for(int i = 0; i<pqueue->total;++i) {
    free(pqueue->node[i]);
  }
  free(pqueue->node);
  free(pqueue);
}

int find_parent(int index) {
  return (index-1)/2;
}
  
void pq_add(struct pq *pqueue, int item, int priority) {
  struct node *new = malloc(sizeof(struct node));
  new->val = item;
  new->prio = priority;
  
  if(pqueue->index == pqueue->total) {
    pqueue->index *= 2;
    pqueue->node= realloc(pqueue->node,sizeof(struct node *) 
                          *(pqueue->index));
  }
  
  pqueue->node[pqueue->total] = new;
  
  for(int i=pqueue->total;;i = find_parent(i)) {
    int parent = find_parent(i);
    
    if(i == 0) {
      break;
    }
    
    
    if(priority<pqueue->node[parent]->prio) {
      struct node *temp = pqueue->node[parent];
      pqueue->node[parent] = pqueue->node[i];
      pqueue->node[i] = temp;
    }
    else {
      break;
    }
  }
  ++pqueue->total;
}

void swapnode(struct node **node, int i, int j) {
  struct node *temp = node[i];
  node[i] = node[j];
  node[j] = temp;
}

int pq_remove(struct pq *pqueue) {
  struct node *temp = pqueue->node[0];
  pqueue->node[0] = pqueue->node[pqueue->total-1];
  --pqueue->total;
  
  for(int i=0;;) {
    
    if(i >= pqueue->total) {
      break;
    }
    
    int left = (i*2) + 1;
    if(pqueue->total <= left) {
      break;
    }
    
    else if(pqueue->total == left + 1) {
     
      if(pqueue->node[i]->prio > pqueue->node[left]->prio) {
        swapnode(pqueue->node, i, left);
      }
      break;
    }
    
    int small_child = left;
    
    if(pqueue->node[left]->prio > pqueue->node[left+1]->prio) {
      small_child = left +1;
    }
    
    if(pqueue->node[small_child]->prio < pqueue->node[i]->prio) {
      swapnode(pqueue->node, i, small_child);
      i = small_child;
    }
  
    else {
      break;
    }
  }
  int val = temp->val;
  free(temp);
  return val;
}
  
          


bool pq_is_empty(const struct pq *pqueue) {
  return pqueue == NULL || pqueue->total == 0;
  }
  
void pq_print(const struct pq *pqueue) {
  printf("[");
  for(int i=0;i<pqueue->total;++i) {
   
    if(i>0) {
    printf(",");
    }
    
    printf("(%d,%d)",pqueue->node[i]->val,pqueue->node[i]->prio);
  }
  
  printf("]\n");
}
  
int pq_length(const struct pq *pqueue) {
  return pqueue->total;
}

int pq_front_priority(const struct pq *pqueue) {
  return pqueue->node[0]->prio;
}

int pq_front_item(const struct pq *pqueue) {
  return pqueue->node[0]->val;
}


  