struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct descriptor dynamicQueue;

dynamicQueue* create();

void release(dynamicQueue* q);

int size(dynamicQueue* q);

int empty(dynamicQueue* q);

int full(dynamicQueue* q);

int push(dynamicQueue* q, struct student student);

int pop(dynamicQueue* q);

int front(dynamicQueue* q, struct student* student);

int back(dynamicQueue* q, struct student* student);

int show(dynamicQueue* q);
