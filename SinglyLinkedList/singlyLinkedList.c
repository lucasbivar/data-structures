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

  if(list == NULL) return -1;

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

int removeback(singlyLinkedList* list){
  if(list == NULL) return 0;
  if((*list) == NULL) return 0;

  Node *previous, *current = *list;
  while (current->next != NULL){
    previous = current;
    current = current->next;
  }

  if(current == (*list)){
    *list = current->next;
  }else{
    previous->next = current->next;
    free(current);
  } 

  return 1;
}

int removestudent(singlyLinkedList* list, int enrollment){
  if(list == NULL) return 0;

  Node *previous, *current = *list;
  while (current != NULL && current->data.enrollment != enrollment){
    previous = current;
    current = current->next;
  }

  if(current == NULL) return 0;

  if((*list) == current){
    *list = current->next;
  }else{
    previous->next = current->next;
    free(current);
  }

  return 1;
}

int get(singlyLinkedList* list, int index, struct student* student){
  if(list == NULL || index < 0) return 0;

  Node *n = *list;
  int count = 0;
  while (n != NULL && count < index){
    n = n->next;
    count++;
  }

  if(n == NULL){
    return 0;
  }else{
    *student = n->data;
    return 1;
  }

}

int find(singlyLinkedList* list, int enrollment, struct student* student){
  if(list == NULL) return 0;

  Node *current= *list;
  while (current->data.enrollment != enrollment && current != NULL){
    current = current->next;
  }

  if(current == NULL){
    return 0;
  }else{
    *student = current->data;
    return 1;
  }
}

int show(singlyLinkedList* list){
  if(list == NULL) return 0;
  if((*list) == 0) return 0;
  Node* current = *list;
  printf("\n=-=-=-=-=-=-=-=-=-All Students-=-=-=-=-=-=-=-=-=\n");
  while (current != NULL){
    printf("Name: %s", current->data.name);
    printf("Enrollment: %d\n", current->data.enrollment);
    printf("Pontuation 1: %.2f\n", current->data.p1);
    printf("Pontuation 2: %.2f\n", current->data.p2);
    printf("Pontuation 3: %.2f\n\n", current->data.p3);
    current = current->next;
  }
  return 1;
}