#include <stdio.h>
#include <stdlib.h>
#include "dynamicListWithDescriptorNode.h"

struct node{
  struct student data;
  struct node* next;
};

typedef struct node Node;

struct descriptor{
  struct node* head;
  struct node* tail;
  int size;
};

List* create(){
  List* li = (List*) malloc(sizeof(List));
  if(li != NULL){
    li->head = NULL;
    li->tail = NULL;
    li->size = 0;
  }
  return li;
}

void release(List* list){
  if(list != NULL){
    Node* n;
    while((list->head) != NULL){
      n = list->head;
      list->head = list->head->next;
      free(n);
    }
    free(list);
  }
}

int size(List* list){
  if(list == NULL) return 0;
  return list->size;
}

int pushfront(List* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));
  if(n == NULL) return 0;

  n->data = student;
  n->next = list->head;

  if(list->head == NULL){
    list->tail = n;
  }

  list->head = n;
  list->size++;
  return 1;
}

int pushback(List* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));
  if(n == NULL) return 0;

  n->data = student;
  n->next = NULL;

  if(list->head == NULL){
    list->head = n;
  }else{
    list->tail->next = n;
  }

  list->tail = n;
  list->size++;
  return 1;
}

int removefront(List* list){
  if(list == NULL) return 0;

  if(list->head == NULL) return 0;

  Node* n = list->head;
  list->head = n->next;
  free(n);

  if(list->head == NULL){
    list->tail = NULL;
  }
  list->size--;
  return 1;
}

int removeback(List* list){
  if(list == NULL) return 0;

  if(list->head == NULL) return 0;

  Node *prev, *n = list->head;
  while(n->next != NULL){
    prev = n;
    n = n->next;
  }

  if(n == list->head){
    list->head = NULL;
    list->tail = NULL;
  }else{
    prev->next = n->next;
    list->tail = prev;
  }

  free(n);
  list->size--;
  return 1;
}

int show(List* list){
  if(list == NULL) return 0;
  if(list->head == NULL) return 0;
  Node* current = list->head;
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