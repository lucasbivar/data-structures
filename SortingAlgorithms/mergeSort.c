#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int *V, int begin, int end);
void merge(int *V, int begin, int middle, int end);
void showArray(int* arr, int size);

int main(void){
  int arr[] = {3, 5, 6, 4, 7, 8, 1, 0};
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("Unsorted Array: ");
  showArray(arr, size);

  mergeSort(arr, 0, size-1);

  printf("Sorted Array  : ");
  showArray(arr, size);

  return 0;
}

void mergeSort(int *V, int begin, int end){
  int middle;
  if(begin < end){
    middle = floor((begin+end)/2);
    mergeSort(V, begin, middle);
    mergeSort(V, middle+1, end);
    merge(V, begin, middle, end);
  }
}

void merge(int *V, int begin, int middle, int end){
  int *temp, p1, p2, size, i, j, k;
  int end1 = 0, end2 = 0;
  size = end-begin+1;
  p1 = begin;
  p2 = middle+1;
  temp = (int*) malloc(size*sizeof(int));

  if(temp != NULL){

    for(i = 0; i < size; i++){

      if(!end1 && !end2){
        //combine sorted
        if(V[p1] < V[p2]){
          temp[i] = V[p1++];
        }else{
          temp[i] = V[p2++];
        }
        //the vector is over?
        if(p1 > middle) end1 = 1;
        if(p2 > end) end2 = 1;

      }else{
        //copy what's left
        if(!end1){
          temp[i] = V[p1++];
        }else{
          temp[i] = V[p2++];
        }
      }
    }


    for(j = 0, k = begin; j < size; j++, k++){
      V[k] = temp[j];
    }
  }

  free(temp);
}


void showArray(int* arr, int size){
  printf("[");
  for(int i = 0; i < size; i++){
    printf("%d\t", arr[i]);
  }
  printf("]\n");
}