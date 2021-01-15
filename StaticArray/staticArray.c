struct array{
  int size;
  struct student data[MAX];
}

Array* create(){
  Array* arr;
  arr = (Array*) malloc(sizeof(struct array));
  if(arr != NULL){
    arr->size = 0;
  }
  return arr;
}

void release(Array* arr){
  free(arr);
}

int size(Array* arr){
  if(arr == NULL){
    return -1;
  }
  return arr->size;
}

int full(Array* arr){
  if(arr == NULL){
    return -1;
  }
  return (arr->size == MAX);
}

int empty(Array* arr){
  if(arr == NULL){
    return -1;
  }
  return (arr->size == 0);
}