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