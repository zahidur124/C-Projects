#include "sequence.h"
#include <stdio.h>
#include <stdlib.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur  
// login ID: zabedin

// implementation:

struct Sequence {
  int length;
  struct node *first;
  struct node *last;
};

struct node {
  int val;
  struct node *next;
};

struct Sequence *Sequence_create(void) {
  struct Sequence *new = malloc(sizeof(struct Sequence));
  
  new->length = 0;
  new->first = NULL;
  new->last = NULL;
  
  return new;
}

void Sequence_destroy(struct Sequence *seq) {
  struct node *temp = seq->first;

  while(temp != NULL) {
    struct node *temp2 = temp;
    temp = temp->next;
    free(temp2);
  }
  
  free(seq);
}
    
int Sequence_length(const struct Sequence *seq) {
  return seq->length;
}

int Sequence_item_at(const struct Sequence *seq, int pos) {
  int i;
  struct node *temp = seq->first;
  
  for(i=1;i<=pos;++i)  {
    temp = temp->next;
  }
  
  return temp->val;
}
    
void Sequence_insert_at(struct Sequence *seq, int pos, int val) {
  int i;
  
  struct node *new = malloc(sizeof(struct node));
  struct node *temp = seq->first;
  
  new->val = val;
  
  if(pos == 0) {
    new->next = seq->first;
    seq->first = new;
    ++seq->length;
    return;
  }
  
  for(i=1;i<pos;++i) {
    temp = temp->next;
  }

  new->next = temp->next;
  temp->next = new;
  ++seq->length;
}
  
int Sequence_remove_at(struct Sequence *seq, int pos) {
  int i;
  struct node *temp = seq->first;
  
  if(pos == 0) {
    struct node *remove = seq->first;
    int x = remove->val;
    seq->first = seq->first->next;
    --seq->length;
    free(remove);
    return x;
  }
  
  for(i=1;i<pos;++i) {
    temp = temp->next;
  }
  
  struct node *remove = temp->next;
  int x = remove -> val;
  temp->next = temp->next->next;
  free(remove);
  --seq->length;
  return x;
}

void Sequence_print(const struct Sequence *seq) {
  int i;
  struct node *temp = seq->first;
  
  printf("[%d]",seq->length);
  
  for(i=0;i<seq->length;++i) {
    printf(" %d",temp->val);
    temp = temp->next;
  }
  
  printf("\n");

}



  




