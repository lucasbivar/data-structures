#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(){
  float d;
  Point *p, *q;
  p = create(10, 5);
  q = create(5, 10);

  d = distance(p, q);

  printf("Distance between the two points: %f\n",d);

  release(p);
  release(q);
  
  return 0;
}