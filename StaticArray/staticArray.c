#include "staticArray.h"
#include <stdlib.h>
#include <stdio.h>

struct array{
  int size;
  struct student data[MAX];
};

Array* create(){
  Array* arr;
  arr = (Array*) malloc(sizeof(struct array));
  if(arr != NULL){
    arr->size = 0;
  }
  return arr;
}

void release(Array* arr){
  free(arr);
}

int size(Array* arr){
  if(arr == NULL){
    return -1;
  }
  return arr->size;
}

int full(Array* arr){
  if(arr == NULL){
    return -1;
  }
  return (arr->size == MAX);
}

int empty(Array* arr){
  if(arr == NULL){
    return -1;
  }
  return (arr->size == 0);
}

int pushback(Array* arr, struct student student){
  if(arr == NULL) return 0;
  if(full(arr)) return 0;
  arr->data[arr->size] = student;
  arr->size++;
  return 1;
}

int pushfront(Array* arr, struct student student){
  if(arr == NULL) return 0;
  if(full(arr)) return 0;
  int i;
  for(i = arr->size-1; i >=0 ;i--){
    arr->data[i+1] = arr->data[i];
  }
  arr->data[0] = student;
  arr->size++;
  return 1; 
}

int pushorder(Array* arr, struct student student){
  if(arr == NULL) return 0;
  if(full(arr)) return 0;
  int k, i =0;
  while(i < arr->size && arr->data[i].enrollment < student.enrollment) i++;

  for(k = arr->size-1; k >= i; k--){
    arr->data[k+1] = arr->data[k];
  }

  arr->data[i] = student;
  arr->size++;
  return 1;
}

int removeback(Array* arr){
  if(arr == NULL) return 0;
  if(arr->size == 0) return 0;
  arr->size--;
  return 1;
}

int removefront(Array* arr){
  if(arr == NULL) return 0;
  if(arr->size == 0) return 0;
  int i;
  for(i = 0; i < arr->size-1; i++){
    arr->data[i] = arr->data[i+1];
  }
  arr->size--;
  return 1;
}

int removestudent(Array* arr, int enrollment){
  if(arr == NULL) return 0;
  if(arr->size == 0) return 0;
  int k, i = 0;
  while (i < arr->size && arr->data[i].enrollment != enrollment) i++;

  if(i == arr->size) return 0;

  for(k = i; k < arr->size-1; k++){
    arr->data[i] = arr->data[i+1];
  }
  arr->size--;
  return 1;
}

int get(Array* arr, int index, struct student *student){
  if(arr == NULL || index < 0 || index >= arr->size) return 0;
  
  *student = arr->data[index];

  return 1;
}

int find(Array* arr, int enrollment, struct student *student){
  if(arr == NULL) return 0;

  int i = 0;
  while(i < arr->size && arr->data[i].enrollment != enrollment) i++;

  if(i == arr->size) return 0;
  *student = arr->data[i];

  return 1;
}

int show(Array* arr){
  if(arr == NULL) return 0;
  if(arr->size == 0) return 0;
  int i;
  printf("\n=-=-=-=-=-=-=-=-=-All Students-=-=-=-=-=-=-=-=-=\n");
  for(i = 0; i < arr->size; i++){
    printf("Name: %s\n", arr->data[i].name);
    printf("Enrollment: %d\n", arr->data[i].enrollment);
    printf("Pontuation 1: %f\n", arr->data[i].p1);
    printf("Pontuation 2: %f\n", arr->data[i].p2);
    printf("Pontuation 3: %f\n", arr->data[i].p3);
  }
  return 1;
}
