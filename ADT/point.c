#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include "point.h"

struct point{
  float x;
  float y;
};

Point* create(float x, float y){
  Point* p = (Point *)malloc(sizeof(Point));
  if(p != NULL){
    p->x = x;
    p->y = y;
  }
  return p;
}

void release(Point* p){
  free(p);
}