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