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

int insert(binaryTree* root, int value){
  if(root == NULL) return 0;

  struct NODE* newNode;
  newNode = (struct NODE*) malloc(sizeof(struct NODE));
  if(newNode == NULL) return 0;
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  if(*root == NULL){
    *root = newNode;
  }else{
    struct NODE* current = *root;
    struct NODE* prev = NULL;
    while (current != NULL){
      prev = current;
      if(value == current->data){
        free(newNode);
        return 0;
      }
      if(value > current->data){
        current = current->right;
      }else{
        current = current->left;
      }
    }
    if(value > prev->data){
      prev->right = newNode;
    }else{
      prev->left = newNode;
    }
  }
  return 1;
}

int erase(binaryTree* root, int value){
  if(root == NULL) return 0;
  struct NODE* prev = NULL;
  struct NODE* current =  *root;

  while(current != NULL){
    if(value == current->data){
      if(current == *root){
        *root = erase_current(current);
      }else{
        if(prev->right == current){
          prev->right = erase_current(current);
        }else{
          prev->left = erase_current(current);
        }
      }
      return 1;
    }
    //keep searching
      prev = current;
      if(value > current->data){
        current = current->right;
      }else{
        current = current->left;
      }
  }
  return 0;
}

struct NODE* erase_current(struct NODE* current){
  struct NODE *node1, *node2;
  if(current->left == NULL){
    node2 = current->right;
    free(current);
    return node2;
  }
  node1 = current;
  node2 = current->left;
  while(node2->right != NULL){
    node1 = node2;
    node2 = node2->right;
  }

  if(node1 != current){
    node1->right = node2->left;
    node2->left = current->left;
  }
  node2->right = current->right;
  free(current);
  return node2;
}

int find(binaryTree* root, int value){
  if(root == NULL){
    return 0;
  }
  struct NODE* current = *root;
  while(current != NULL){
    if(value == current->data){
      return 1;
    }
    if(value > current->data){
      current = current->right;
    }else{
      current = current->left;
    }
  }
  return 0;
}