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

int push(dynamicQueue* q, struct student student){
  if(q == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));
  if(n == NULL) return 0;
  n->data = student;
  n->next = NULL;

  if(empty(q)){
    q->begin = n;
  }else{
    q->end->next = n;
  }

  q->end = n;
  q->size++;
  return 1;
}

int pop(dynamicQueue* q){
  if(q == NULL) return 0;
  if(empty(q)) return 0;

  Node* aux = q->begin;
  q->begin = q->begin->next;

  if(q->begin == NULL) q->end = NULL;
  
  free(aux);
  q->size--;
  return 1;
}

int front(dynamicQueue* q, struct student* student){
  if(q == NULL) return 0;
  if(empty(q)) return 0;

  *student = q->begin->data;

  return 1;
}

int back(dynamicQueue* q, struct student* student){
  if(q == NULL) return 0;
  if(empty(q)) return 0;

  *student = q->end->data;

  return 1;
}

int show(dynamicQueue* q){
  if(q == NULL) return 0;
  if(empty(q)) return 0;
  
  Node* current = q->begin;
  printf("\n=-=-=-=-=-=-=-=-=-Queue of Students-=-=-=-=-=-=-=-=-=\n");
  while(current != NULL){
    printf("Name: %s", current->data.name);
    printf("Enrollment: %d\n", current->data.enrollment);
    printf("Pontuation 1: %.2f\n", current->data.p1);
    printf("Pontuation 2: %.2f\n", current->data.p2);
    printf("Pontuation 3: %.2f\n\n", current->data.p3);
    current = current->next;
  }
  return 1;
}
