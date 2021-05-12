#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

struct NODE{
  int data;
  struct NODE* left;
  struct NODE* right;
};

binaryTree* create(){
  binaryTree* root = (binaryTree*) malloc(sizeof(binaryTree));
  if(root != NULL){
    *root = NULL;
  }
  return root;
}

void releaseNode(struct NODE* node){
  if(node == NULL) return;
  releaseNode(node->left);
  releaseNode(node->right);
  free(node);
  node = NULL;
}

void releaseTree(binaryTree* root){
  if(root == NULL) return;
  releaseNode(*root);
  free(root);
}

int empty(binaryTree* root){
  if(root == NULL) return 1;
  return (*root == NULL);
}

int heightOfTree(binaryTree* root){
  if(root == NULL) return 0;
  if(*root == NULL) return 0;
  int left_height = heightOfTree(&((*root)->left));
  int right_height = heightOfTree(&((*root)->right));
  if(left_height > right_height){
    return (left_height+1);
  }else{
    return (right_height+1);
  }
}

int numberOfNodes(binaryTree* root){
  if(root == NULL) return 0;
  if(*root == NULL) return 0;
  int left_size = numberOfNodes(&((*root)->left));
  int right_size = numberOfNodes(&((*root)->right));
  return (left_size + right_size + 1);
}

void preorder(binaryTree* root){
  if(root == NULL) return;
  if(*root != NULL){
    printf("%d\n", (*root)->data);
    preorder(&((*root)->left));
    preorder(&((*root)->right));
  }
}

void inorder(binaryTree* root){
  if(root == NULL) return;
  if(*root != NULL){
    inorder(&((*root)->left));
    printf("%d\n", (*root)->data);
    inorder(&((*root)->right));
  }
}

void postorder(binaryTree* root){
  if(root == NULL) return;
  if(*root != NULL){
    postorder(&((*root)->left));
    postorder(&((*root)->right));
    printf("%d\n", (*root)->data);
  } 
}