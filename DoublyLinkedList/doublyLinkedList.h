struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct node* doublyLinkedList;

doublyLinkedList* create();

void release(doublyLinkedList* list);

int size(doublyLinkedList* list);

int empty(doublyLinkedList* list);