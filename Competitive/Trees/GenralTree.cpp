#include<bits/stdc++.h>
#include"ChildrenSumProperty.cpp"

using namespace	std;




int main() {
	Node*root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(12);
	root->right->left = new Node(3);
	root->right->right = new Node(9);
	cout << isCSum(root);

}

