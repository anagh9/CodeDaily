// Problem Statement => sum of child = parent
/*
	20
	/\
   8  12
  /\
 3  5

Sumof(3,5) = 8
Sumof(8,12) = 20

So it will return true;
 */
class Node {
public:
	int data;
	Node*left, *right;
	Node(int d) {
		data = d;
		left = right = NULL;
	}
};

bool isCSum(Node *root) {
	if (root == NULL) return true;
	if (root->left == NULL && root->right == NULL) return true;

	int sum = 0;
	if (root->left != NULL) {sum += root->left->data;}
	if (root->right != NULL) {sum += root->right->data;}

	return (root->data == sum && isCSum(root->left) && isCSum(root->right));
}






