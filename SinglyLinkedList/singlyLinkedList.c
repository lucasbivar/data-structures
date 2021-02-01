#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

struct node{
  struct student data;
  struct node *next;
}

typedef struct node Node;


singlyLinkedList* create(){
  singlyLinkedList* list = (singlyLinkedList*) malloc(sizeof(singlyLinkedList));
  if(list != NULL){
    *list = NULL;
  }
  return list;
}

void release(singlyLinkedList* list){
  if(list != NULL){
    Node* n;
    while((*list) != NULL){
      n = *list;
      *list = (*list)->next;
      free(n);
    }
    free(list);
  }
}

int size(singlyLinkedList* list){
  if(list != NULL) return 0;
  int s = 0;
  Node* n = *list;
  while(n != NULL){
    s++;
    n = n->prox;
  }
  return s;
}

int empty(singlyLinkedList* list){
  if(list == NULL) return 1;
  if(*list == NULL) return 1;
  return 0;
}

int pushfront(singlyLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->next = (*list);
  n->data = student;
  *list = n;
  
  return 1;
}