#include<stdio.h>
#include<stdlib.h>
#include "staticArray.h"

void menu(){
  Array* arr = NULL;
  int option;
  int loop = 1;
  arr = create();
  while(loop){
    printf("=-=-=-=-=-=-=-=-=-Static Array-=-=-=-=-=-=-=-=-=\n");
    printf("[1] Push Back\n");
    printf("[2] Push Front\n");
    printf("[3] Push Order\n");
    printf("[4] Remove Front\n");
    printf("[5] Remove Back\n");
    printf("[6] Remove By Enrollment\n");
    printf("[7] Size\n");
    printf("[8] Empty\n");
    printf("[9] Full\n");
    printf("[10] Get\n");
    printf("[11] Find\n");
    printf("[0] EXIT\n");
    while(1){
      printf("\nType: ");
      scanf("%d", &option);
      if (option >= 0 && option <= 11) break; 
      else{
        printf("\nError: Invalid Option\n");
      }
    }
    switch (option){
    case 0:
      release(arr);
      loop = 0;
      break;
    
    default:
      break;
    }

    


  }

}

int main(){
  menu();
  return 0;
}