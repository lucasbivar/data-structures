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

int size(dynamicStack* s){
  if(s == NULL) return -1;

  int s = 0;
  Node* temp = *s;
  while(temp != NULL){
    temp = temp->next;
    s++;
  }
  return size;
}

int full(dynamicStack* s){
  if(s == NULL) return -1;
  return 0;
}

int empty(dynamicStack* s){
  if(s == NULL) return -1;
  
  return ((*s) == NULL);
}

int push(dynamicStack* s, struct student student){
  if(s == NULL) return 0;

  Node *newNode = (Node*) malloc(sizeof(Node));
  if(newNode == NULL) return 0;
  
  newNode->data = student;
  newNode->next = (*s);
  (*s) = newNode;
  return 1;
}

int pop(dynamicStack* s){
  if(s == NULL) return 0;
  if(empty(s)) return 0;

  Node *temp = *s;
  *s = temp->next;
  free(temp);
  return 1;
}

int top(dynamicStack* s, struct student* student){
  if(s == NULL) return 0;
  if(empty(s)) return 0;

  *student = (*s)->data;
  return 1;
}