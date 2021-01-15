#define MAX 100

struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct array Array; 

Array* create();

void release(Array* arr);

int size(Array* arr);

int full(Array* arr);

int empty(Array* arr);

int pushback(Array* arr, struct student student);

int pushfront(Array* arr, struct student student);

int pushorder(Array* arr, struct student student);

int removeback(Array* arr);

int removefront(Array* arr);

int removestudent(Array* arr, int enrollment);

int get(Array* arr, int index, struct student *student);

int find(Array* arr, int enrollment, struct student *student);