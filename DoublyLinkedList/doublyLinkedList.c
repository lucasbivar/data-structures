#include <stdlib.h>
#include <stdio.h>
#include "doublyLinkedList.h"

struct node{
  struct student data;
  struct node* next;
  struct node* prev;
};

typedef struct node Node;

doublyLinkedList* create(){
  doublyLinkedList * li = (doublyLinkedList *) malloc(sizeof(doublyLinkedList));
  if(li != NULL){
    *li = NULL;
  }
  return li;
}

void release(doublyLinkedList* list){
  if(list != NULL){
    Node *n;
    while ((*list) != NULL){
      n = list;
      *list = (*list)->next;
      free(n);
    }
    free(list);
  }
}

int size(doublyLinkedList* list){
  if(list == NULL) return 0;

  int s = 0;
  Node* n = *list;
  while(n != NULL){
    *n = *n->next;
    s++;
  }

  return s;
}

int empty(doublyLinkedList* list){
  if(list == NULL) return 1;
  if(*list == NULL) return 1;
  return 0;
}

int pushfront(doublyLinkedList* list, struct student student){
  if(list == NULL) return 0;
  
  Node *n = (Node *) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->data = student;
  n->next = *list;
  n->prev = NULL;

  if(*list != NULL){
    (*list)->prev = n;
  }

  *list = n;
  return 1;
}


int pushback(doublyLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node *n = (Node *) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->data = student;
  n->next = NULL;

  if(*list == NULL){
    n->prev = NULL;
    *list = n;
  }else{
    Node* aux = *list;
    while (aux->next != NULL){
      aux = aux->next;
    }
    aux->next = n;
    n->prev = aux;
  }
  return 1;
}

int pushorder(doublyLinkedList* list, struct student student){
  if(list == NULL) return 0;

  Node* n = (Node*) malloc(sizeof(Node));

  if(n == NULL) return 0;

  n->data = student;

  if(empty(list)){

    n->prev = NULL;
    n->next = NULL;
    *list = n;

  }else{
    Node *prev, *current = *list;

    while((current != NULL) && (current->data.enrollment < student.enrollment)){
      prev = current;
      current = current->next;
    }

    if(current == *list){
      n->prev = NULL;
      (*list)->prev = n;
      n->next = *list;
      *list = n;

    }else{
      n->next = prev->next;
      n->prev = prev;
      prev->next = n;

      if(current != NULL){
        current->prev = n;
      }
    }
  }
  return 1;
}

int removefront(doublyLinkedList* list){
  if(list == NULL) return 0;
  if(*list == NULL) return 0;

  Node *n = *list;
  *list = n->next;
  if(n->next != NULL){
    n->next->prev = NULL;
  }

  free(n);
  return 1;
}

int removeback(doublyLinkedList* list){
  if(list == NULL) return 0;
  if((*list) == NULL) return 0;

  Node* n = *list;
  while(n->next != NULL){
    n = n->next;
  }

  if(n->prev == NULL){
    *list = n->next;
  }else{
    n->prev->next = NULL;
  }

  free(n);
  return 1;
}

int removestudent(doublyLinkedList* list, int enrollment){
  if(list == NULL) return 0;
  if((*list) == NULL) return 0;

  Node *n = *list;
  while((n != NULL) && (n->data.enrollment != enrollment)){
    n = n->next;
  }

  if(n == NULL) return 0;

  if(n->prev == NULL){
    *list = n->next;
  }else{
    n->prev->next = n->next;
  }

  if(n->next != NULL){
    n->next->prev = n->prev;
  }
  free(n);
  return 1;
}