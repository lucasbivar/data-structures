#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include "singlyLinkedList.h"


struct student newStudent(){
  struct student Student;
  printf("=-=-=-=-=-=-=-=-=-New Student-=-=-=-=-=-=-=-=-=\n");
  printf("Name:\n");
  fgets(Student.name, sizeof(Student.name), stdin);
  printf("Enrollment (int):\n");
  scanf("%d", &Student.enrollment);
 
  printf("Insert the first pontuation:\n");
  scanf("%f", &Student.p1);

  printf("Insert the second pontuation:\n");
  scanf("%f", &Student.p2);

  printf("Insert the third pontuation:\n");
  scanf("%f", &Student.p3);
   
  return Student;
}

void show_student(struct student *student){
  printf("\nName: %s", student->name);
  printf("Enrollment: %d\n", student->enrollment);
  printf("Pontuation 1: %.2f\n", student->p1);
  printf("Pontuation 2: %.2f\n", student->p2);
  printf("Pontuation 3: %.2f\n",student->p3);
}

void show_options(){
  printf("\n=-=-=-=-=-=-=-=-=-Static Array-=-=-=-=-=-=-=-=-=\n");
  printf("[1] Push Back\n");
  printf("[2] Push Front\n");
  printf("[3] Push Order\n");
  printf("[4] Remove Front\n");
  printf("[5] Remove Back\n");
  printf("[6] Remove By Enrollment\n");
  printf("[7] Size\n");
  printf("[8] Empty\n");
  printf("[9] Get\n");
  printf("[10] Find\n");
  printf("[11] Show All\n");
  printf("[0] EXIT\n");
}

void menu(){
  singlyLinkedList* arr;
  arr = create();
  int option, aux;
  int loop = 1;
  struct student Student;
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
    case 7:
      if(size(arr) != -1){
        printf("\nThe size of array is %d!\n", size(arr));
      }else{
        printf("\nError\n");
      }
      break;
    case 8:
     if(empty(arr) != -1){
       if(empty(arr)){
        printf("\nThe array is empty!\n");
       }else{
        printf("\nThe array is not empty!\n");
       }
      }else{
        printf("\nError\n");
      }
      break;
    case 9:
      printf("Student Position (>=0): ");
      scanf("%d", &aux);
      if(get(arr, aux, &Student)){
        show_student(&Student);
      }else{
        printf("\nError\n");
      }
      break;
    case 10:
      printf("Student Enrollment: ");
      scanf("%d", &aux);
      if(find(arr, aux, &Student)){
        show_student(&Student);
      }else{
        printf("\nError\n");
      }
      break;
    case 11:
      if(!show(arr)){
        printf("\nFailed!\n");
      }
      break;
    default:
      break;
    }
    Sleep(2000);
  }

}

int main(){
  menu();
  return 0;
}