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

int assign(sparseMatrix* matrix, int row, int column, float data){
  if(row < 0 || row >= matrix->rows 
  || column < 0 || column >= matrix->columns) return 0;

  PONT previous = NULL, current = matrix->arrangement[row];
  while(current != NULL && current->column < column){
    previous = current;
    current = current->next;
  }

  // Node exists?
  if(current != NULL && current->column == column){
    if(data == 0){
      //First element?
      if(previous == NULL){
        matrix->arrangement[row] = current->next;
      }else{
        previous->next = current->next;
      }
      free(current);
    }else{
      current->data = data;
    }
  }else{
    //We need storage the node?
    if(data != 0){
      PONT newNode = (PONT) malloc(sizeof(Node));
      if(newNode == NULL) return 0;

      newNode->column = column;
      newNode->data = data;
      newNode->next = current;

      //Will the node be in the first position or the row is empty or ?
      if(previous == NULL){
        matrix->arrangement[row] = newNode;
      }else{
        previous->next = newNode;
      }
    }
  }
  return 1;
}

int getData(sparseMatrix* matrix, int row, int column, float* data){
  if(row < 0 || row >= matrix->rows 
  || column < 0 || column >= matrix->columns) return 0;

  PONT current = matrix->arrangement[row];
  while(current != NULL && current->column < column){
    current = current->next;
  }
  
  if(current != NULL && current->column == column){
    *data = current->data;
  }else{
    *data = 0;
  }
  return 1;
}