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

int removeback(singlyLinkedList* list);

int removestudent(singlyLinkedList* list, int enrollment);

int get(singlyLinkedList* list, int index, struct student* student);

int find(singlyLinkedList* list, int enrollment, struct student* student);

int show(singlyLinkedList* list);