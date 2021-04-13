struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct node* dynamicStack;

dynamicStack* create();

void release(dynamicStack* s);

int size(dynamicStack* s);

int full(dynamicStack* s);

int empty(dynamicStack* s);

int push(dynamicStack* s, struct student student);

int pop(dynamicStack* s);

int top(dynamicStack* s, struct student* student);
