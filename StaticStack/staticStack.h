#define MAX 100

struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct stack staticStack;

staticStack* create();

void release(staticStack* s);

int size(staticStack* s);

int full(staticStack* s);

int empty(staticStack* s);

int push(staticStack* s, struct student student);

int pop(staticStack* s);

int top(staticStack* s, struct student* student);

int show(staticStack* s);