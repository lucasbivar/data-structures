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