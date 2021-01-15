#include<stdio.h>
#include<stdlib.h>
#include "staticArray.h"


struct student newStudent(){
  struct student Student;
  printf("=-=-=-=-=-=-=-=-=-New Student-=-=-=-=-=-=-=-=-=\n");
  printf("Name:\n");
  fgets(Student.name, sizeof(Student.name), stdin);
  printf("Enrollment (int):\n");
  scanf("%d", &Student.enrollment);
  getchar();
  printf("Insert the first pontuation:\n");
  getchar();
  scanf("%d", &Student.p1);
  getchar();
  printf("Insert the second pontuation:\n");
  scanf("%d", &Student.p1);
  getchar();
  printf("Insert the third pontuation:\n");
  scanf("%d", &Student.p1);
  getchar();
   
  return Student;
}

void show_options(){
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
  printf("[12] Show All\n");
  printf("[0] EXIT\n");
}

void menu(){
  Array* arr = NULL;
  int option, aux;
  int loop = 1;
  arr = create();
  while(loop){
    show_options();
    while(1){
      printf("\nType: ");
      scanf("%d", &option);
      getchar();
      if (option >= 0 && option <= 12) break; 
      else{
        printf("\nError: Invalid Option\n");
      }
    }
    switch (option){
    case 0:
      release(arr);
      loop = 0;
      break;
    case 1:
      if(pushback(arr, newStudent())){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 2:
      if(pushfront(arr, newStudent())){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 3:
      if(pushorder(arr, newStudent())){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 4:
      if(removefront(arr)){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 5:
      if(removeback(arr)){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 6:
      printf("Student Enrollment: ");
      scanf("%d", &aux);
      if(removestudent(arr, aux)){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 12:
      if(!show(arr)){
        printf("\nFailed!\n");
      }
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