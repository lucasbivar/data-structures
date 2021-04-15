#include <stdlib.h>
#include <stdio.h>

void insertionSort(int* arr, int size);
void showArray(int* arr, int size);

int main(void){
  int arr[] = {3, 5, 6, 4, 7, 8, 1};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Unsorted Array: ");
  showArray(arr, size);

  insertionSort(arr, size);

  printf("Sorted Array  : ");
  showArray(arr, size);

  return 0;
}


void insertionSort(int* arr, int size){
  int temp, i, j;
  for(i = 1; i < size; i++){
    temp = arr[i];
    for(j = i; (j > 0) && (temp < arr[j-1]); j--){
      arr[j] = arr[j-1];
    }
    arr[j] = temp;
  }
}

void showArray(int* arr, int size){
  printf("[");
  for(int i = 0; i < size; i++){
    printf("%d\t", arr[i]);
  }
  printf("]\n");
}