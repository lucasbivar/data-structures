#define MAX 100

struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct queue staticQueue;

staticQueue* create();

void release(staticQueue* q);

int size(staticQueue* q);

int empty(staticQueue* q);

int full(staticQueue* q);