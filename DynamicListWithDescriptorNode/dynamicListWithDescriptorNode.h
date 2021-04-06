struct student{
  int enrollment;
  char name[20];
  float p1, p2, p3; 
};

typedef struct descriptor List;

List* create();

void release(List* list);

int size(List* list);

int pushfront(List* list, struct student student);

int pushback(List* list, struct student student);

int removefront(List* list);

int removeback(List* list);

int show(List* list);