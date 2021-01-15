#define MAX 100

struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct array Array; 

Array* create();

void release(Array* arr);