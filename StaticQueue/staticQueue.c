#include <stdlib.h>
#include <stdio.h>
#include "staticQueue.h"

struct queue{
  struct student data[MAX];
  int size, front, back;
};

staticQueue* create(){
  staticQueue* ptr = (staticQueue*) malloc(sizeof(struct queue));
  if(ptr != NULL){
    ptr->size = 0;
    ptr->front = 0;
    ptr->back = 0;
  }
}

void release(staticQueue* q){
  free(q);
}

int size(staticQueue* q){
  if(q == NULL) return -1;
  return q->size;
}

int empty(staticQueue* q){
  if(q == NULL) return -1;

  return (q->size == 0);
}

int full(staticQueue* q){
  if(q == NULL) return -1;

  return (q->size == MAX);
}