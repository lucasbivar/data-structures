#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void showArray(int* arr, int size);
void quickSort(int *V, int begin, int end);
int partition(int *V, int begin, int end);


int main(void){
  int arr[] = {3, 5, 6, 4, 7, 8, 1, 0};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Unsorted Array: ");
  showArray(arr, size);

  quickSort(arr, 0, size-1);

  printf("Sorted Array  : ");
  showArray(arr, size);

  return 0;
}

void quickSort(int *V, int begin, int end){
  int pivot;
  if(end > begin){
    pivot = partition(V, begin, end);
    quickSort(V, begin, pivot-1);
    quickSort(V, pivot+1, end);
  }
}

int partition(int *V, int begin, int end){
  int left, right, pivot, aux;
  left = begin;
  right = end;
  pivot = V[begin];

  while(left < right){
    while(left <= end && V[left] <= pivot) left++;
    while (right >= 0 && V[right] > pivot) right--;

    if(left < right){
      aux = V[left];
      V[left] = V[right];
      V[right] =  aux;
    }
  }

  V[begin] = V[right];
  V[right] = pivot;

  return right;
}

void showArray(int* arr, int size){
  printf("[");
  for(int i = 0; i < size; i++){
    printf("%d\t", arr[i]);
  }
  printf("]\n");
}