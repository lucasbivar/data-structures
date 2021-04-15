#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int size, int value);

int main(void){
  int arr[] = {3, 5, 6, 4, 7, 8, 1};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  int index = linearSearch(arr, size, 7);
  if(index == -1){
    printf("The number %d was not found.\n", 7);
  }else{
    printf("The element %d was found at [%d].\n", 7, index);
  }

  index = linearSearch(arr, size, 10);
  if(index == -1){
    printf("The number %d was not found.\n", 10);
  }else{
    printf("The element %d was found at [%d].\n", 10, index);
  }
  return 0;
}

int linearSearch(int *arr, int size, int value){
  
  for(int i = 0; i < size; i++){
    if(arr[i] == value) return i;
  }

  return -1;
}