struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct node* singlyLinkedList;

singlyLinkedList* create();

void release(singlyLinkedList* list);

int size(singlyLinkedList* list);

int empty(singlyLinkedList* list);

int pushfront(singlyLinkedList* list, struct student student);

int pushback(singlyLinkedList* list, struct student student);

int pushorder(singlyLinkedList* list, struct student student);

int removefront(singlyLinkedList* list);