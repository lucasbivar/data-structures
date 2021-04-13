#include <stdlib.h>
#include <stdio.h>
#include "dynamicStack.h"

struct node{
  struct student data;
  struct node* next;
};

typedef struct node Node;

dynamicStack* create(){
  dynamicStack* ptr = (dynamicStack*) malloc(sizeof(dynamicStack));
  if(ptr != NULL){
    *ptr = NULL;
  }
  return NULL;
}

void release(dynamicStack* s){
  if(s != NULL){
    Node* temp;
    while((*s) != NULL){
      temp = *s;
      *s = (*s)->next;
      free(temp);
    }
    free(s);
  }
}