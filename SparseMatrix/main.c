#include <stdlib.h>
#include <stdio.h>
#include "sparseMatrix.h"

void show_options(int isQuadratic){
  printf("\n=-=-=-=-=-=-=-=-=-Sparse Matrix-=-=-=-=-=-=-=-=-=\n");
  printf("[1] Assign\n");
  printf("[2] Get\n");
  printf("[3] Show\n");
  if(isQuadratic){
    printf("[4] Primary Diagonal\n");
    printf("[5] Secondary Diagonal\n");
  }
  printf("[0] EXIT\n");
}

void clear_buffer(){
  int ch;
  while((ch = getchar()) != EOF && ch != '\n' );
}

int main(void){
  sparseMatrix* matrix = NULL;
  int option;
  int loop = 1;
  int row, column, data, max_option = 5;
  printf("Let's build the Sparse Matrix\n");
  printf("Insert the row size of matrix:\n");
  scanf("%d", &row);
  clear_buffer();
  printf("Insert the column size of matrix:\n");
  scanf("%d", &column);
  clear_buffer();
  printf("\n");
  int isQuadratic = 1;
  if(row != column){
    isQuadratic = 0;
    max_option = 3;
  }
  matrix = create(row, column);
  if(matrix != NULL){
    show(matrix);
  }else{
    printf("Error creating matrix\n");
    return 0;
  }
  while(loop){
    show_options(isQuadratic);
    while(1){
      printf("\nType: ");
      scanf("%d", &option);
      clear_buffer();
      if (option >= 0 && option <= max_option) break; 
      else{
        printf("\nError: Invalid Option\n");
      }
    }
    switch (option){
      case 0:
        release(matrix);
        loop = 0;
        break;
      case 1:
        printf("Insert the row:\n");
        scanf("%d", &row);
        clear_buffer();
        printf("Insert the column:\n");
        scanf("%d", &column);
        clear_buffer();
        printf("Insert the value (int):\n");
        scanf("%d", &data);
        clear_buffer();
        if(assign(matrix,row, column, data)){
          printf("The data [%d] was assigned at [%d][%d].", data, row, column);
        }else{
          printf("Invalid postion");
        }
        break;
      case 2:
        printf("Insert the row:\n");
        scanf("%d", &row);
        clear_buffer();
        printf("Insert the column:\n");
        scanf("%d", &column);
        clear_buffer();
        if(getData(matrix,row, column, &data)){
          printf("The element at the position [%d][%d] is %d!\n", row, column, data);
        }else{
          printf("Invalid postion");
        }
        break;
      case 3:
        if(!show(matrix)){
          printf("Error\n\n");
        }
        break;
      case 4:
        if(!getPrimaryDiagonal(matrix)){
          printf("Error\n");
        }
        break;
      case 5:
        if(!getSecondaryDiagonal(matrix)){
          printf("Error\n");
        }
        break;
      default:
        break;
    }
  }
  return 0;
}
