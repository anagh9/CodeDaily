/**
 * Application of Tree
 * > To Represent Hierarchical Data
 * >> Organisational Structure
 * >> Folder Structure
 * >> XML/HTML Content (JSON Objects)
 * >> IN OOP (Inheritence)
 *
 * > Binary Search Trees
 * > Binary Heap
 * > B and B+ trees
 * > Spanning and Shortest Path tree in computer Networks .
 *
 * > Trie
 * > Suffix Tree
 * > Binary Index Tree
 * > Segment Tree
 *
 * */

//    _(30)_
//     /  \
//   (40) (50) null both sides
//   /  \
// (70) (80)

#include <bits/stdc++.h>
using namespace std;

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

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
}
