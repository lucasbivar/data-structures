#include <stdlib.h>
#include <stdio.h>
#include "dynamicQueue.h"

struct node{
  struct student data;
  struct node *next;
};

typedef struct node Node;

struct descriptor{
  struct node *begin ,*end; 
  int size;
};

dynamicQueue* create(){
  dynamicQueue* ptr = (dynamicQueue*) malloc(sizeof(dynamicQueue));
  if(ptr != NULL){
    ptr->begin = NULL;
    ptr->end = NULL;
    ptr->size = 0;
  }
  return ptr;
}

void release(dynamicQueue* q){
  if(q != NULL){
    Node* n;
    while(q->begin != NULL){
      n = q->begin;
      q->begin = q->begin->next;
      free(n);
    }
    free(q);
  }
}


int size(dynamicQueue* q){
  if(q == NULL) return -1;
  return q->size;
}

int empty(dynamicQueue* q){
  if(q == NULL) return -1;
  return (q->size == 0);
}

int full(dynamicQueue* q){
  if(q == NULL) return -1;
  return 0;
}
