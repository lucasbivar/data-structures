struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct node* circularLinkedList;

circularLinkedList* create();

void release(circularLinkedList* list);

int size(circularLinkedList* list);

int empty(circularLinkedList* list);