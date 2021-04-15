#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b);
void bubbleSort(int* arr, int size);
void showArray(int* arr, int size);

int main(void){
  int arr[] = {3, 5, 6, 4, 7, 8, 1};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Unsorted Array: ");
  showArray(arr, size);

  bubbleSort(arr, size);

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

void bubbleSort(int* arr, int size){
  int keep;

    for(int i = 0; i < size-1; i++){
      keep = 0;

      for(int j = 0; j < size-i-1; j++){
        if(arr[j] > arr[j+1]){
          swap(&arr[j], &arr[j+1]);
          keep = 1;
        }
      }
      // If no two elements were swapped by inner loop, then break (is sorted)
      if(!keep) break;
    }
}

void showArray(int* arr, int size){
  printf("[");
  for(int i = 0; i < size; i++){
    printf("%d\t", arr[i]);
  }
  printf("]\n");
}