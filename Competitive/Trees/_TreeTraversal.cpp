#include<bits/stdc++.h>
#define ll long long
using namespace std;

// TWO TRAVERSAL
// > DFS (Inorder,Preorder,Postorder)
// > BFS (Level Order Traversal)
// > Inorder (Left Root Right)
// > Preorder (Root Left Right)
// > Postorder (Left Right Root)

/**
 * Order => Traverse Root , Traverse Left Subtree , Traverse Right Subtree
 * */

typedef struct Node {
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = right = NULL;
	}
} Node;

void Inorder(Node*head) {
	if (head != NULL) {
		Inorder(head->left);
		cout << head->data << " ";
		Inorder(head->right);
	}
}

void Preorder(Node*head) {
	if (head != NULL) {
		cout << head->data << " ";
		Preorder(head ->left);
		Preorder(head ->right);
	}
}

void Postorder(Node *head) {
	if (head != NULL) {
		Postorder(head->left);
		Postorder(head->right);
		cout << head ->data << " ";
	}
}

void LevelOrderTraversal(Node *root) {
	if (root == NULL)return;
	queue<Node *>q;
	q.push(root);
	while (q.empty() == false) {
		Node *curr = q.front();
		q.pop();
		cout << curr->data << " ";
		if (curr->left != NULL)
			q.push(curr->left);
		if (curr->right != NULL)
			q.push(curr->right);
	}
}
// For LevelOrder Only
// TimeComplexity  => O(N)
// Auxiliary Space => O(N)

void LevelOrderTraversalLineByLine(Node*root) {
	if (root == NULL)return;
	queue<Node *>q;
	q.push(root);
	q.push(NULL);
	while (q.size() > 1) {
		Node *curr = q.front();
		q.pop();
		if (curr == NULL) {
			cout << "\n";
			q.push(NULL);
			continue;
		}
		cout << curr->data << " ";
		if (curr->left != NULL)
			q.push(curr->left);
		if (curr->right != NULL)
			q.push(curr->right);
	}
}

void printLevel(Node *root) {
	if (root == NULL)return;
	queue<Node *>q;
	q.push(root);
	while (q.empty() == false) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			Node *curr = q.front();
			q.pop();
			cout << curr->data << " ";
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
		cout << "\n";
	}
}

int main() {

	Node*temp = new Node(12);
	temp ->left = new Node(43);
	temp ->right = new Node(46);
	temp ->left ->left = new Node(413);
	temp ->left ->right = new Node(4);
	Inorder(temp);
	cout << endl;
	Preorder(temp);
	cout << endl;
	Postorder(temp);
	cout << endl;
	LevelOrderTraversal(temp);
	cout << endl;
	cout << "Level Order Traversal LevelWise" << endl;
	LevelOrderTraversalLineByLine(temp);
	cout << "\nLevel Order Traversal LevelWise" << endl;
	printLevel(temp);
	return 0;
}