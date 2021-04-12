#include<stdio.h>
#include<stdlib.h>
// #include<Windows.h>
#include "staticQueue.h"


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
  printf("\n=-=-=-=-=-=-=-=-=-Static Queue-=-=-=-=-=-=-=-=-=\n");
  printf("[1] Push\n");
  printf("[2] Pop\n");
  printf("[3] Size\n");
  printf("[4] Empty\n");
  printf("[5] Full\n");
  printf("[6] Front\n");
  printf("[7] Back\n");
  printf("[8] Show All\n");
  printf("[0] EXIT\n");
}

void menu(){
  staticQueue* q = NULL;
  int option;
  int loop = 1;
  struct student Student;
  q = create();
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
      release(q);
      loop = 0;
      break;
    case 1:
      if(push(q, newStudent())){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 2:
      if(pop(q)){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 3:
      if(size(q) != -1){
        printf("\nThe size of array is %d!\n", size(q));
      }else{
        printf("\nError\n");
      }
      break;
    case 4:
     if(empty(q) != -1){
       if(empty(q)){
        printf("\nThe array is empty!\n");
       }else{
        printf("\nThe array is not empty!\n");
       }
      }else{
        printf("\nError\n");
      }
      break;
    case 5:
      if(full(q) != -1){
       if(full(q)){
        printf("\nThe array is full!\n");
       }else{
        printf("\nThe array is not full!\n");
       }
      }else{
        printf("\nError\n");
      }
      break;
    case 6:
      printf("Front:\n");
      if(front(q, &Student)){
        show_student(&Student);
      }else{
        printf("\nError\n");
      }
      break;
    case 7:
      printf("Back:\n");
      if(back(q, &Student)){
        show_student(&Student);
      }else{
        printf("\nError\n");
      }
      break;
    case 8:
      if(!show(q)){
        printf("\nFailed!\n");
      }
      break;
    default:
      break;
    }
    // Sleep(2000);
  }

}

int main(){
  menu();
  return 0;
}