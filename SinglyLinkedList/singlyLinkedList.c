#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

struct node{
  struct student data;
  struct node *next;
};

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
    n = n->next;
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

int pushback(singlyLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->next = NULL;
  n->data = student;

  if((*list) == NULL){
    *list = n;
  }else{
    Node* aux = *list;
    while(aux->next != NULL){
      aux = aux->next;
    }
    aux->next = n;
  }
  return 1;
}

int pushorder(singlyLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->data = student;

  if(empty(list)){
    n->next = (*list);
    *list = n;
  }else{

    Node* previous, *current = *list;

    while(current != NULL && current->data.enrollment < student.enrollment){
      previous = current;
      current = current->next;
    }

    if(current == *list){

      n->next = (*list);
      *list = n;

    }else{

      n->next = previous->next;
      previous->next = n;

    }
  }
  
  return 1;
}


int removefront(singlyLinkedList* list){
  if(list == NULL) return 0;
  if((*list) == NULL) return 0;
  
  Node* n = *list;
  *list = n->next;

  free(n);

  return 1;
}
