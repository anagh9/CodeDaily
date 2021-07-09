// Trees and Binary Trees In 45 Min (90 min)

/*Binary Tree All Operations (Balanced)*

Search           O(log n)
Insert 		 O(log n)
Delete           O(log n)
Find Closest     O(log n)
Sorted Traversal O(n)


*********/
/*

        root
        /  \
  root>LT   RT>root

Implemented in C++ as map,set , multimap

*/

// Create an empty BST
// Insert 20 15 30 40 50 12 18 35 80 7


bool searchInBst(node *root, int x) {
	if (root == NULL)
		return false;
	else if (root->key == x)
		return true;
	else if (root->key > x)
		return searchInBst(root->left, x);
	else
		return searchInBst(root->right, x);

	return false;
}

// Iterative implementation

bool searchInBst(node *root, int x) {
	while (root != NULL) {
		if (root->key == x)
			return true;
		else if (root->key < x)
			root = root->right;
		else
			root = root->left;
	}
	return false;
}

// Time Complexity : O(logn) => Height of Binary Tree

// Insertion In Binary Search Tree

// Something Already exist we do not modify
// Insertion always done at bottom
// compare from root and the according left or right we add it


Node *insert(node*root, int x) {
	if (root == NULL)
		return new Node(x);
	else if (root->key < x)
		root->right = insert(root->right, x);
	else if (root->key > x)
		root->left = insert(root->left, x);

	return root;
}


/** Deletion In BST **/

// If Leaf node => It's Done simple
// If one child => Delete and put the closest value
// If two value =>  Replace with closest smallest or highest value

Node *delNode(Node *root, int x) {
	if (root == NULL) return root;
	if (root->key > x)
		root->left = delNode(root->left, x);
	else if (root->key < x)
		root->right = delNode(root->right, x);
	else {
		if (root->left == NULL) {
			Node *temp = root->right;
			delete temp;
			return temp;
		} else if {
		Node *temp = root->left;
		delete temp;
		return temp;
	}
	else {
		Node *succ = getSuccessor(root);
			root->key = succ->key;
			root->right = delNode(root->right, succ->key);
		}
	}
}

Node *getSuccessor(Node*curr) {
	curr = curr->right;
	while (curr != NULL && curr->left != NULL)
		curr = curr->left;
	return curr;
}


// Floor Of a BST = > Closest Smallest value than the given value or if not present print NULL

// i/p : x = 14 BST: 10 5 15 12 30
// o/p : 12

Node *floor(Node *root, int x) {
	Node *res = NULL;
	while (root != NULL) {
		if (root->key == x)
			return root;
		else if (root->key > x)
			root = root->left;
		else {
			res = root;
			root = root->right;
		}
	}
	return res;
}


// Ceil of BST => Highest Closest Value the given value or if not present print NULL

// i/p : x = 14 BST: 10 5 15 12 30
// o/p : 15

Node *ceil(Node *root, int x) {
	Node *res = NULL;
	while (root != NULL) {
		if (root->key == x)
			return root;
		else if (root->key < x)
			root = root->right;
		else {
			res = root;
			root = root->left;
		}
	}
	return res;
}

// TIme Complexity : O(n)



// Self Balancing Binary Tree : while doing left and right rotation . Without violating The tree Structure .

// 7 10 11 15 30 35

/*
 \
  \
   \
    \
     \
      \
       \

*/

// AVL Tree  => Concept of Balance Factor <=1 either -1, 0 , 1
// It Has All properties of BST
// Always done rotation After Insertion





// Applications of BST
/*
* To maintain sorted stream of data (or sorted set of data)
* To implement Doubly ended priority queue
* To Solve Problem Like
 	- Count smaller/greater in a stream
 	- Floor/Ceil/Greater/Smaller of the stream
*/




// SET in C++ STL
// -> It uses Red Black Tree .

set<int>s;
set<int , greater<int>>s; // reverse
// insert() , begin() ,end() , rbegin() , rend() , find() => return iterator of the element, clear() ,erase() => range of iteraator or any specific iterator , size() , count() => return ony 1 or 0;

auto it = s.find(10);
if (it == s.end())
	cout << "Not Found" << endl;
else
	cout << "Found" << endl;

s.lower_bound(10);  // Points to Iterator to the element or the element which is just greater than it.

s.upper_bound(10);  // Points to Iterator to the which is just greater than it.


auto it = s.lower_bound(25);
if (it != s.end())
	cout << (*it) << " ";
else
	cout << "given element is grater than the largest"


// insert,find,count,lowerbound,upperbound,erase => TC : O(log n)



// MAP in C++ STL
// -> It uses Red Black Tree .

	main() {
	map<int, int> mp;
	mp.insert(10, 200);
	mp[10] = 200;
	mp.at(10) = 300; // It only allocate when key is already present
	m.insert({3, 300});
	for (auto &x : mp)
		cout << x.first << " "
		     << x.second << " ";

}


/********* Ceilin on left side***********/
// i/p : {2,8,30,15,25,12}
// 0/p : -1 -1 -1 30 30 15

/*** Find K-th Smallest ***/
// i/p: insert(10) ,insert(5),insert(15),insert(20),insert(2)
// KthSmallest(3)  // K = 3
// o/p : KthSmalleste (3) = 10














