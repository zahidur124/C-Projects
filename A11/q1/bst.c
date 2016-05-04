#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"

// IMPORTANT: DO NOT CHANGE THESE VALUES
const int PRE_ORDER = 0;
const int IN_ORDER = 1;
const int POST_ORDER = 2;

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name:
// login ID:

// implementation:

struct bst *bst_create(void) {
  struct bst *new = malloc(sizeof(struct bst));
  
  new->root = NULL;
  
  return new;
}

void bstnode_destroy(struct bstnode *t) {
  if(t == NULL) {
    return;
  }
  
  bstnode_destroy(t->left);
  bstnode_destroy(t->right);
  free(t);
}

void bst_destroy(struct bst *t) {
  bstnode_destroy(t->root);
  free(t);
}

int bst_node_size(struct bstnode *t) {
  if(t == NULL) {
    return 0;
  }
  return t->size;
}

int bst_size(struct bst *t) {
    return bst_node_size(t->root);
}

void bst_insert(int i, struct bst *t) {
  
  if(bst_find(i,t) == true) {
    return;
  }
  
  struct bstnode *new = malloc(sizeof(struct bstnode));
  struct bstnode *temp = t->root;
  new->item = i;
  new->left = NULL;
  new->right = NULL;
  new->size = 1;
  
  if(temp == NULL) {
    t->root = new;
    return;
  }
  
  while(true) {
    ++temp->size;
    
    if(temp->item > i) {
      if(temp->left != NULL) {
        temp = temp->left;
      }
      
     else { 
      temp->left = new;
       break;
     }
    }
    
    else {
      if(temp->right != NULL) {
        temp = temp->right;
      }
      
      else {
        temp->right = new;
        break;
      }
    }
  }
}

 
bool bst_find(int i, struct bst *t) {
  struct bstnode *temp = t->root;
  
  while(true) {
    if(temp == NULL) {
      return false;
    }
    
    if(temp->item == i) {
      return true;
    }
    
    if(temp->item > i) {
      if(temp->left == NULL) {
        break;
      }
      
      else {
        temp = temp->left;
      }
      
    }
    
    else {
      if(temp->right == NULL) {
        break;
      }
      
      else {
        temp = temp->right;
      }
    }
  }
  
  return false;
}

int finder(int k, struct bstnode *t) {
  
 
  if(bst_node_size(t->left)>=k+1) {
    return finder(k, t->left);
  }
  
  if(bst_node_size(t->left) == k) {
    return t->item;
  }
  
  return finder(k-1-bst_node_size(t->left),t->right);
}
  
  

int bst_select(int k, struct bst *t) {
  return finder(k,t->root);
}

void bst_remove (int i, struct bst *t) {
  if(bst_find(i,t) == false) {
    return;
  }
  
  struct bstnode *temp = t->root;
  struct bstnode *prev = NULL;
  
  while(true) {
    --temp->size;
    
    if(temp->item > i) {
      prev = temp;
      temp = temp->left;
    }
    
    else if(temp->item < i) {
      prev = temp;
      temp = temp->right;
    }
    
    else {
      break;
    }
  }
  
  struct bstnode **temp2 = NULL;
  
  if(prev == NULL) {
    temp2 = &t->root;
  }
  
  else if(prev->left == temp) {
    temp2 = &prev->left;
  }
  
  else {
    temp2 = &prev->right;
   }
  
  if(temp->right == NULL) {
    *temp2 = temp->left;
    free(temp);
    return;
  }
  
  else if(temp->left == NULL) {
    *temp2 = temp->right;
    free(temp);
    return;
  }
  
  *temp2 = temp->right;
  
  struct bstnode *temp3 = temp->left;
  
  while(temp3->left != NULL) {
    temp3->size += temp->left->size;
    temp3 = temp3->left;
  }
  
  temp3->left = temp->left;
  temp3->size += temp->left->size;
  free(temp);
}

int bst_range(int start, int end, struct bst *t) {
  int count = 0;
  struct bstnode *cur = t->root;
  
  while(cur != NULL) {
    if(cur->item == start) {
       
      if(cur->right != NULL) {
        count += cur->right->size;
      }
     
      ++count;
      break;
    }
    
    else if(cur->item > start) {
      
      if(cur->right != NULL) {
        count += cur->right->size;
      }
     
      ++count;
      cur = cur->left;
    }
    
    else {
      cur = cur->right;
    }
  }
  
  cur = t->root;
  
  while(cur != NULL) {
    if(cur->item == end) {
       
      if(cur->left != NULL) {
        count += cur->left->size;
      }
     
      ++count;
      break;
    }
    
    else if(cur->item < end) {
      
      if(cur->left != NULL) {
        count += cur->left->size;
      }
     
      ++count;
      cur = cur->right;
    }
    
    else {
      cur = cur->left;
    }
  }
  
  if(t->root != NULL) {
   return count - t->root->size;
  }
  
  return 0;

}

void printer(int o, struct bstnode *t,bool *val) {
  if (t == NULL) {
    return;
  }

  if(o == PRE_ORDER) {
      
   if(*val == true) {
    *val = false;
  }
 
    else {
          printf(",");
    }

  printf("%d",t->item);
  printer(o,t->left,val);
  printer(o,t->right,val);
  }
  
    
  if(o == IN_ORDER) {
  printer(o,t->left,val);
    
   if(*val == true) {
    *val = false;
  }

    else {
          printf(",");
    }
  
  printf("%d",t->item);
  printer(o,t->right,val);
  }
  
    
  if(o == POST_ORDER) {
    printer(o,t->left,val);
    printer(o,t->right,val);
    
 if(*val == true) {
    *val = false;
  }
    else {
          printf(",");
    }
   
  printf("%d",t->item);
  }
}
  
void bst_print (int o, struct bst *t) {
  bool isfirst = true;
  
  printf("[");
  printer(o,t->root,&isfirst);
  printf("]\n");
}

void array_builder(int *arr, struct bstnode *t, int counter) {
  if(t == NULL) {
    return;
  }
  
  array_builder(arr,t->left,counter);
  counter += bst_node_size(t->left); 
  arr[counter] = t->item;
  array_builder(arr,t->right,counter+1);
}


int *bst_to_sorted_array(struct bst *t) {
  
  if(t->root == NULL) {
    return NULL;
  }
  
  int *arr = malloc(sizeof(int) * t->root->size);
  
  array_builder(arr,t->root,0);
  return arr;
}

struct bstnode *tree_builder(int *arr, int start, int end) {
  if(start == end) {
    return NULL;
  }
  
  struct bstnode *new = malloc(sizeof(struct bstnode));
  
  int mid = (start+end)/2;
  
  new->item = arr[mid];
  new->left = tree_builder(arr, start, mid);
  new->right = tree_builder(arr, mid + 1, end);
  new->size = bst_node_size(new->left) + bst_node_size(new->right) + 1;
  return new;
}

struct bst *sorted_array_to_bst(int *arr, int len) {
  struct bst *new_tree = malloc(sizeof(struct bst));
  
  new_tree->root = tree_builder(arr,0,len);
  
  return new_tree;

}

void bst_rebalance(struct bst *t) {
  if (t->root == NULL) {
    return;
  }

 int *arr = bst_to_sorted_array(t);
 struct bst *new = sorted_array_to_bst(arr,t->root->size);
  free(arr);
  bstnode_destroy(t->root);
  t->root = new->root;
  free(new);
}