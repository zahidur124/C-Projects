#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Zahidur
// login ID: zabedin  

// implementation:

void reverser(struct llist *list) {
  struct llnode *prev=NULL;
  struct llnode *cur =list->front;
  struct llnode *next =NULL;
  
  while(cur != NULL) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  
  list->front = prev;
}
    

void merge(struct llist *dest, struct llist *src1, struct llist *src2) {
  if(src1->front == NULL && src2->front == NULL) {
    reverser(dest);
  }
  
  else if(src1->front == NULL || (src2->front != NULL &&
          src1->front->item > src2->front->item)) {
    struct llnode *temp = dest->front;
    dest->front = src2->front;
    src2->front = src2->front->next;
    dest->front->next = temp;
    merge(dest,src1,src2);
  }
  
   else {
    struct llnode *temp = dest->front;
    dest->front = src1->front;
    src1->front = src1->front->next;
    dest->front->next = temp;
    merge(dest,src1,src2);
  }
}


void split_list(struct llist *list1, struct llist *list2) {
  struct llnode *first = list1->front;
  struct llnode *second = list1->front;
  struct llnode *prev = NULL;
  
  while(first != NULL && first->next != NULL) {
    first = first->next->next;
    prev = second;
    second = second->next;
  }
  
  if(prev != NULL) {
    prev->next = NULL;
  }
  
  list2->front = second;
}

void merge_sort(struct llist *lst) {
  if(lst->front == NULL || lst->front->next == NULL) {
    return;
  }
 
  struct llist temp;
  struct llist new;
 
  split_list(lst,&temp);
  
  merge_sort(lst);
  merge_sort(&temp);
  
  merge(&new,lst,&temp);
  lst->front = new.front;
}
  

  
  
  
  
  
  



  
  
  
  
  
  

  



