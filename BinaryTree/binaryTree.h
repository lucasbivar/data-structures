typedef struct NODE* binaryTree;

binaryTree* create();

void releaseNode(struct NODE* node);

void releaseTree(binaryTree* root);
