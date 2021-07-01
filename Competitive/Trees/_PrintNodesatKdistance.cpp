#include <bits/stdc++.h>
using namespace std;

/**
 * i/p : k  = 2 {We need to print k+1 level Elements}
 * Tree => {10}
 * 				 /  \
 * 			{20}  {30}
 *      /  \     \
 *    {40}{50}   {70}
 *
 * o/p : 40 50 70
 *
 *
 *
 * */

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	Node(int k) {
		key = k;
		left = right = NULL;
	}
};

void printKDist(Node *root, int k) {
	if (root == NULL)return;

	if (k == 0) {cout << root->key << " ";}
	else {
		printKDist(root->left, k - 1);
		printKDist(root->right, k - 1);
	}
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->right = new Node(70);
	root->right->right->right = new Node(80);
	int k = 2;

	printKDist(root, k);
}