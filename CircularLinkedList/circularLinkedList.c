#include "circularLinkedList.h"
#include <stdio.h>
#include <stdlib.h>


struct node{
  struct student data;
  struct node* next;
};
  
typedef struct node Node;

circularLinkedList* create(){
  circularLinkedList * list = (circularLinkedList*) malloc(sizeof(circularLinkedList));
  if(list != NULL){
    *list = NULL;
  }
  return list;
}

void release(circularLinkedList* list){
  
  if(list != NULL && (*list) != NULL){
    Node *aux, *n = *list;
    while((*list)!= n->next){
      aux = n;
      n = n->next;
      free(aux);
    }
    free(n);
    free(list);
  }
}