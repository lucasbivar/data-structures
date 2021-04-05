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

int pushfront(circularLinkedList* list, struct student student);

int pushback(circularLinkedList* list, struct student student);

int pushorder(circularLinkedList* list, struct student student);

int removefront(circularLinkedList* list);

int removeback(circularLinkedList* list);

int removestudent(circularLinkedList* list, int enrollment);