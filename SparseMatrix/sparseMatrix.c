#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

struct node{
  float data;
  int column;
  struct node* next;
};

typedef struct node Node;

typedef Node* PONT;

struct matrix{
  int columns;
  int rows;
  PONT* arrangement;
};

sparseMatrix* create(int rows, int columns){
  sparseMatrix* ptr = (sparseMatrix*) malloc(sizeof(sparseMatrix));
  if(ptr != NULL){
    ptr->rows = rows;
    ptr->columns = columns;

    ptr->arrangement = (PONT*) malloc(rows*sizeof(PONT));
    if(ptr->arrangement != NULL){
      for(int i = 0; i < rows; i++){
        ptr->arrangement[i] = NULL;
      }

    }
  }
  return ptr;
}