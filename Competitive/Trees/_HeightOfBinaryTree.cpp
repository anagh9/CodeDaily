#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node {
	int data;
	Node*left;
	Node*right;
	Node(int d) {
		data = d;
		left = right = NULL;
	}
};

int HeightOfTree(Node *head) {
	if (head == NULL)
		return 0;
	else
		return max(HeightOfTree(head->left), HeightOfTree(head->right)) + 1;
}

// TimeComplexity => O(n)
// Auxilary Space => O(heightOfTree + 1)

int main() {
	Node*temp = new Node(12);
	temp ->left = new Node(43);
	temp ->right = new Node(46);
	temp ->left ->left = new Node(413);
	temp ->left ->right = new Node(4);
	cout << HeightOfTree(temp);

	return 0;
}