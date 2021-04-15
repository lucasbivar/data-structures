#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b);
void selectionSort(int* arr, int size);
void showArray(int* arr, int size);

int main(void){
  int arr[] = {3, 5, 6, 4, 7, 8, 1};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Unsorted Array: ");
  showArray(arr, size);

  selectionSort(arr, size);

  printf("Sorted Array  : ");
  showArray(arr, size);

  return 0;
}

void swap(int* a, int* b){
  int temp;
  temp = *b;
  *b = *a;
  *a = temp;
}

void selectionSort(int* arr, int size){
  int min;
  for(int i = 0; i < size; i++){
    min = i;
    for(int j = i+1; j < size; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }

    if(i != min){
      swap(&arr[i], &arr[min]);
    }
  }
}

void showArray(int* arr, int size){
  printf("[");
  for(int i = 0; i < size; i++){
    printf("%d\t", arr[i]);
  }
  printf("]\n");
}