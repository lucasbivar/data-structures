typedef struct matrix sparseMatrix;

sparseMatrix* create(int rows, int columns);

int assign(sparseMatrix* matrix, int row, int column, float data);

int getData(sparseMatrix* matrix, int row, int column, float* data);