#include <stdio.h>
#include <stdlib.h>

int orderSearch(int *arr, int size, int value);

int main(void){
  int arr[] = {1, 2, 3, 4, 6, 7, 8};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  int index = orderSearch(arr, size, 4);
  if(index == -1){
    printf("The number %d was not found.\n", 4);
  }else{
    printf("The element %d was found at [%d].\n", 4, index);
  }

  index = orderSearch(arr, size, 5);
  if(index == -1){
    printf("The number %d was not found.\n", 5);
  }else{
    printf("The element %d was found at [%d].\n", 5, index);
  }

  return 0;
}

int orderSearch(int *arr, int size, int value){
  
  for(int i = 0; i < size; i++){
    if(arr[i] == value) return i;
    else if(arr[i] > value) return -1;
  }

  return -1;
}