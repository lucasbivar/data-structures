typedef struct point Point;

Point* create(float x, float y);

void release(Point* p);

void access(Point* p, float* x, float* y);

void assign(Point* p, float x, float y);

float distance(Point* p1, Point* p2);