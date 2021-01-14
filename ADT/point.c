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

void access(Point* p, float* x, float* y){
  *x = p->x;
  *y = p->y;
}

void assign(Point* p, float x, float y){
  p->x = x;
  p->y = y;
}

float distance(Point* p1, Point* p2){
  float dx = p1->x - p2->x;
  float dy = p1->y - p2->y;

  return sqrt(dx*dx + dy*dy);
}