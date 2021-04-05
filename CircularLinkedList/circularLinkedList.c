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

int size(circularLinkedList* list){
  if(list == NULL || (*list) == NULL) return 0;

  int s = 0;
  Node* n = *list;
  do{
    s++;
    n = n->next;
  }while(n != (*list));

  return s;
}

int empty(circularLinkedList* list){
  if(list == NULL && (*list) == NULL) return 1;
  return 0;
}

int pushback(circularLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->data = student;

  if((*list) == NULL){

    *list = n;
    n->next = n;

  }else{

    Node* aux = *list;
    while (aux->next != (*list)){
      aux = aux->next;
    }

    aux->next = n;
    n->next = *list;

  }

  return 1;
}

int pushfront(circularLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node* n =  (Node*) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->data = student;

  if((*list) == NULL){

    *list = n;
    n->next = n;

  }else{

    Node* aux = *list;
    while(aux->next != (*list)){
      aux = aux->next;
    }

    aux->next = n;
    n->next = *list;
    *list = n;
  }

  return 1;
}

int pushorder(circularLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));

  if(n == NULL) return 0;
  
  n->data = student;

  if((*list) == NULL){

    *list = n;
    n->next = n;

  }else{

    if((*list)->data.enrollment > student.enrollment){

      Node* current = *list;
      while (current->next != (*list)){
        current = current->next;
      }

      n->next = *list;
      current->next =  n;
      *list = n;

    }else{
      
      Node *prev = *list, *current = (*list)->next;
      while (current != (*list) && current->data.enrollment < student.enrollment){
        prev = current;
        current = current->next;
      }

      prev->next = n;
      n->next = current;
    
    }
  }

  return 1;
}