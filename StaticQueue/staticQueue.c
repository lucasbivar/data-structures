#include <stdlib.h>
#include <stdio.h>
#include "staticQueue.h"

struct queue{
  struct student data[MAX];
  int size, begin, end;
};

staticQueue* create(){
  staticQueue* ptr = (staticQueue*) malloc(sizeof(struct queue));
  if(ptr != NULL){
    ptr->size = 0;
    ptr->begin = 0;
    ptr->end = 0;
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

int push(staticQueue*q, struct student student){
  if(q == NULL) return 0;
  if(full(q)) return 0;

  q->data[q->end] = student;
  q->end = (q->end+1)%MAX;
  q->size++;
  return 1;
}

int pop(staticQueue* q){
  if(q == NULL) return 0;
  if(empty(q)) return 0;

  q->begin = (q->begin+1)%MAX;
  q->size--;
  return 1;
}

int front(staticQueue* q, struct student* student){
  if(q == NULL) return 0;
  if(empty(q)) return 0;

  *student = q->data[q->begin];

  return 1;
}

int back(staticQueue* q, struct student* student){
  if(q == NULL) return 0;
  if(empty(q)) return 0;

  *student = q->data[q->end];
  
  return 1;
}
