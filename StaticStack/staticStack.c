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
  free(s);
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

int push(staticStack* s, struct student student){
  if(s == NULL) return 0;
  if(full(s)) return 0;

  s->data[s->size] = student;
  s->size++;
  return 1;
}

int pop(staticStack* s){
  if(s == NULL) return 0;
  if(empty(s)) return 0;

  s->size--;
  return 1;
}

int top(staticStack* s, struct student* student){
  if(s == NULL) return 0;
  if(empty(s)) return 0;
  *student = s->data[s->size-1];
  return 1;
}

int show(staticStack* s){
  if(s == NULL) return 0;
  if(empty(s)) return 0;
  printf("\n=-=-=-=-=-=-=-=-=-Queue of Students-=-=-=-=-=-=-=-=-=\n");
  for(int i = s->size-1; i >= 0; i--){
    printf("Name: %s", s->data[i].name);
    printf("Enrollment: %d\n", s->data[i].enrollment);
    printf("Pontuation 1: %.2f\n", s->data[i].p1);
    printf("Pontuation 2: %.2f\n", s->data[i].p2);
    printf("Pontuation 3: %.2f\n\n", s->data[i].p3);
  }

  return 1;
}