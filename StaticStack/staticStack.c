#include <stdio.h>
#include <stdlib.h>
#include "staticStack.h"

struct stack{
  int size;
  struct student data[MAX];
};

staticStack* create(){
  staticStack* ptr = (staticStack*) malloc(sizeof(struct stack));
  if(ptr != NULL){
    ptr->size = 0;
  }
  return ptr;
}

void release(staticStack* s){
  free(q);
}

int size(staticStack* s){
  if(s == NULL) return -1;
  return s->size;
}

int full(staticStack* s){
  if(s == NULL) return -1;

  return (s->size == MAX);
}

int empty(staticStack* s){
  if(s == NULL) return -1;
  
  return (s->size == 0);
}
