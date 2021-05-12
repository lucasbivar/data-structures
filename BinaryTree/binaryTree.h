typedef struct NODE* binaryTree;

binaryTree* create();

void releaseNode(struct NODE* node);

void releaseTree(binaryTree* root);

int empty(binaryTree* root);

int heightOfTree(binaryTree* root);

int numberOfNodes(binaryTree* root);

void preorder(binaryTree* root);

void inorder(binaryTree* root);

void postorder(binaryTree* root);

int insert(binaryTree* root, int value);