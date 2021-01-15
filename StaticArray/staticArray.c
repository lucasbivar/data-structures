struct array{
  int quantity;
  struct student data[MAX];
}

Array* create(){
  Array* arr;
  arr = (Array*) malloc(sizeof(struct array));
  if(arr != NULL){
    arr->quantity = 0;
  }
  return arr;
}

void release(Array* arr){
  free(arr);
}