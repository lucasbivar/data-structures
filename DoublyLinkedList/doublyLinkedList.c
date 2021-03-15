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