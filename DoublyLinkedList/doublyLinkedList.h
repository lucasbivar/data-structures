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

int pushfront(doublyLinkedList* list, struct student student);

int pushback(doublyLinkedList* list, struct student student);

int pushorder(doublyLinkedList* list, struct student student);

int removefront(doublyLinkedList* list);

int removeback(doublyLinkedList* list);

int removestudent(doublyLinkedList* list, int enrollment);

int get(doublyLinkedList* list, int index, struct student* student);

int find(doublyLinkedList* list, int enrollment, struct student* student);

int show(doublyLinkedList* list);