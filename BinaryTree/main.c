#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"

void show_options(){
  printf("\n=-=-=-=-=-=-=-=-=-Binary Tree-=-=-=-=-=-=-=-=-=\n");
  printf("[1] Insert\n");
  printf("[2] Erase\n");
  printf("[3] Height of Tree\n");
  printf("[4] Empty\n");
  printf("[5] Number of Nodes\n");
  printf("[6] Find\n");
  printf("[7] Preorder\n");
  printf("[8] Inorder\n");
  printf("[9] Postorder\n");
  printf("[0] EXIT\n");
}

void menu(){
  binaryTree* tree = NULL;
  int option;
  int aux;
  int loop = 1;
  tree = create();
  while(loop){
    show_options();
    while(1){
      printf("\nType: ");
      scanf("%d", &option);
      getchar();
      if (option >= 0 && option <= 9) break; 
      else{
        printf("\nError: Invalid Option\n");
      }
    }
    switch (option){
    case 0:
      releaseTree(tree);
      loop = 0;
      break;
    case 1:
      printf("Type the number to be inserted:\n");
      scanf("%d",&aux);
      if(insert(tree, aux)){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 2:
      printf("Type the number to be erased:\n");
      scanf("%d", &aux);
      if(erase(tree, aux)){
        printf("\nSuccess!\n");
      }else{
        printf("\nFailed!\n");
      }
      break;
    case 3:
      aux = heightOfTree(tree);
      printf("\nThe height of tree is %d!\n", aux);
      break;
    case 4:
      if(empty(tree)){
      printf("\nThe tree is empty!\n");
      }else{
      printf("\nThe tree is not empty!\n");
      }
      break;
    case 5:
      aux = numberOfNodes(tree);
      printf("\nThe number of nodes is %d!\n", aux);
      break;
    case 6:
      printf("Type the number to be finded:\n");
      scanf("%d", &aux);
      if(find(tree, aux)){
        printf("\nThe number was found!\n");
      }else{
        printf("\nThe number was not found!\n");
      }
      break;
    case 7:
      printf("Printing the tree:\n");
      preorder(tree);
      break;
    case 8:
      printf("Printing the tree:\n");
      inorder(tree);
      break;
    case 9:
      printf("Printing the tree:\n");
      postorder(tree);
      break;
    default:
      break;
    }
  }

}

int main(void){
  menu();
  return 0;
}