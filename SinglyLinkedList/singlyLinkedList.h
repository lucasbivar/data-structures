struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct node* singlyLinkedList;

singlyLinkedList* create();

void release(singlyLinkedList* list);