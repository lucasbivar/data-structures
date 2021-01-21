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
