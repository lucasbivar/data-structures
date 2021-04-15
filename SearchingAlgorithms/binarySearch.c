#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int size, int value);

int main(void){
  int arr[] = {1, 2, 3, 4, 6, 7, 8};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  int index = binarySearch(arr, size, 4);
  if(index == -1){
    printf("The number %d was not found.\n", 4);
  }else{
    printf("The element %d was found at [%d].\n", 4, index);
  }

  index = binarySearch(arr, size, 5);
  if(index == -1){
    printf("The number %d was not found.\n", 5);
  }else{
    printf("The element %d was found at [%d].\n", 5, index);
  }

  return 0;
}

int binarySearch(int *arr, int size, int value){
  int begin, end, middle;
  begin = 0;
  end = size-1;
  
  while(begin <= end){
    middle = (begin+end)/2;
    if(arr[middle] > value){
      end = middle-1;
    }else if(arr[middle] < value){
      begin = middle+1;

    }else return middle;
  }

  return -1;
}