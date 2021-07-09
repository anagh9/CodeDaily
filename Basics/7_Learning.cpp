/** Tree **/

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

/** Tree Traversal **/

// Inorder Traversal

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

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->right->left = new Node(40);
	root->right->right = new Node(50);

	inorder(root);
}

/** Preorder **/

void preorder(Node *root) {
	if (root != NULL) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

/** PostOrder **/

void postorder(Node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->key << " ";
	}
}

/** Height of Binary Tree **/

int height(Node *root) {
	if (root == NULL)
		return 0;
	else
		return (1 + max(height(root->left), height(root->right)));
}

/** Print Nodes at K distance **/

void printKDist(Node *root, int k) {
	if (root == NULL)return;

	if (k == 0) {cout << root->key << " ";}
	else {
		printKDist(root->left, k - 1);
		printKDist(root->right, k - 1);
	}
}

/** Level Order Traversal **/

void printLevel(Node *root) {
	if (root == NULL)return;
	queue<Node *>q;
	q.push(root);
	while (q.empty() == false) {
		Node *curr = q.front();
		q.pop();
		cout << curr->key << " ";
		if (curr->left != NULL)
			q.push(curr->left);
		if (curr->right != NULL)
			q.push(curr->right);
	}
}

/** Level Order Traversal Part-1 **/
void printLevel(Node *root) {
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
		cout << curr->key << " ";
		if (curr->left != NULL)
			q.push(curr->left);
		if (curr->right != NULL)
			q.push(curr->right);
	}
}
/** Level Order Traversal Part-2 **/
void printLevel(Node *root) {
	if (root == NULL)return;
	queue<Node *>q;
	q.push(root);
	while (q.empty() == false) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			Node *curr = q.front();
			q.pop();
			cout << curr->key << " ";
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
		cout << "\n";
	}
}

/** Size of Binary Tree **/
int getSize(Node *root) {
	if (root == NULL)
		return 0;
	else
		return 1 + getSize(root->left) + getSize(root->right);
}

/** Maximum in Binary Tree **/

int getMax(Node *root) {
	if (root == NULL)
		return INT_MIN;
	else
		return max(root->key, max(getMax(root->left), getMax(root->right)));
}

/** Print Left View of Binary Tree **/

// Recursive

int maxLevel = 0;
void printLeft(Node *root, int level) {
	if (root == NULL)
		return;
	if (maxLevel < level) {
		cout << root->key << " ";
		maxLevel = level;
	}
	printLeft(root->left, level + 1);
	printLeft(root->right, level + 1);
}

void printLeftView(Node *root) {
	printLeft(root, 1);
}

// Iterative
void printLeft(Node *root) {
	if (root == NULL)
		return;
	queue<Node *> q; q.push(root);
	while (q.empty() == false) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			Node *curr = q.front();
			q.pop();
			if (i == 0)
				cout << curr->key << " ";
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
	}
}

/** Children Sum Property **/
bool isCSum(Node *root) {
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	int sum = 0;
	if (root->left != NULL)sum += root->left->key;
	if (root->right != NULL)sum += root->right->key;

	return (root->key == sum && isCSum(root->left) && isCSum(root->right));
}

/** Check for Balanced Binary Tree **/

// Naive

int height(Node *root) {
	if (root == NULL)
		return 0;
	else
		return (1 + max(height(root->left), height(root->right)));
}

bool isBalanced(Node *root) {
	if (root == NULL)
		return true;
	int lh = height(root->left);
	int rh = height(root->right);
	return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

// Efficient

int isBalanced(Node *root) {
	if (root == NULL)
		return 0;
	int lh = isBalanced(root->left);
	if (lh == -1)return -1;
	int rh = isBalanced(root->right);
	if (rh == -1)return -1;

	if (abs(lh - rh) > 1)
		return -1;
	else
		return max(lh, rh) + 1;
}

/** Maximum Width of Binary Tree **/
int maxWidth(Node *root) {
	if (root == NULL)return 0;
	queue<Node *>q;
	q.push(root);
	int res = 0;
	while (q.empty() == false) {
		int count = q.size();
		res = max(res, count);
		for (int i = 0; i < count; i++) {
			Node *curr = q.front();
			q.pop();
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
	}
	return res;
}

/** Convert Binary Tree To Doubly Linked List **/

void printlist(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->key << " ";
		curr = curr->right;
	} cout << endl;
}



Node *BTToDLL(Node *root) {
	if (root == NULL)return root;
	static Node* prev = NULL;
	Node *head = BTToDLL(root->left);
	if (prev == NULL) {head = root;}
	else {
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	BTToDLL(root->right);
	return head;
}

/** Construct Binary Tree from Inorder and Preorder **/

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

int preIndex = 0;
Node *cTree(int in[], int pre[], int is, int ie) {
	if (is > ie)return NULL;
	Node *root = new Node(pre[preIndex++]);

	int inIndex;
	for (int i = is; i <= ie; i++) {
		if (in[i] == root->key) {
			inIndex = i;
			break;
		}
	}
	root->left = cTree(in, pre, is, inIndex - 1);
	root->right = cTree(in, pre, inIndex + 1, ie);
	return root;
}

/** Tree Traversal in Spiral Form **/

// Method 1

void printSpiral(Node *root) {
	if (root == NULL)return;
	queue<Node *>q;
	stack<int> s;
	bool reverse = false;
	q.push(root);
	while (q.empty() == false) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			Node *curr = q.front();
			q.pop();
			if (reverse)
				s.push(curr->key);
			else
				cout << curr->key << " ";
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
		if (reverse) {
			while (s.empty() == false) {
				cout << s.top() << " ";
				s.pop();
			}
		}
		reverse = !reverse;
	}
}

// Method 2

void printSpiral(Node *root) {
	if (root == NULL)
		return;

	stack<Node*> s1;
	stack<Node*> s2;

	s1.push(root);

	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty()) {
			Node* temp = s1.top();
			s1.pop();
			cout << temp->key << " ";

			if (temp->right)
				s2.push(temp->right);
			if (temp->left)
				s2.push(temp->left);
		}

		while (!s2.empty()) {
			Node* temp = s2.top();
			s2.pop();
			cout << temp->key << " ";

			if (temp->left)
				s1.push(temp->left);
			if (temp->right)
				s1.push(temp->right);
		}
	}
}


/** Diameter of a Binary Tree **/
// Naive
int height(Node *root) {
	if (root == NULL)
		return 0;
	else
		return (1 + max(height(root->left), height(root->right)));
}

int diameter(Node *root) {
	if (root == NULL)return 0;
	int d1 = 1 + height(root->left) + height(root->right);
	int d2 = diameter(root->left);
	int d3 = diameter(root->right);

	return max(d1, max(d2, d3));
}

// Efficient
int res = 0;
int height(Node *root) {
	if (root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	res = max(res, 1 + lh + rh);

	return 1 + max(lh, rh);
}

/** LCA of Binary Tree (Part 1) **/


bool findPath(Node *root, vector<Node *> &p, int n) {
	if (root == NULL)return false;
	p.push_back(root);
	if (root->key == n)return true;

	if (findPath(root->left, p, n) || findPath(root->right, p, n))return true;

	p.pop_back();
	return false;
}

Node *lca(Node *root, int n1, int n2) {
	vector <Node *> path1, path2;
	if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false)
		return NULL;
	for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
		if (path1[i + 1] != path2[i + 1])
			return path1[i];
	return NULL;
}

/** LCA Binary Tree (Part-2) **/

Node *lca(Node *root, int n1, int n2) {
	if (root == NULL)return NULL;
	if (root->key == n1 || root->key == n2)
		return root;

	Node *lca1 = lca(root->left, n1, n2);
	Node *lca2 = lca(root->right, n1, n2);

	if (lca1 != NULL && lca2 != NULL)
		return root;
	if (lca1 != NULL)
		return lca1;
	else
		return lca2;
}

/** Burn a Binary Tree From a Leaf **/

int res = 0;
int burnTime(Node *root, int leaf, int &dist) {
	if (root == NULL)return 0;
	if (root->key == leaf) {dist = 0; return 1;}
	int ldist = -1, rdist = -1;
	int lh = burnTime(root->left, leaf, ldist);
	int rh = burnTime(root->right, leaf, rdist);

	if (ldist != -1) {
		dist = ldist + 1;
		res = max(res, dist + rh);
	}
	else if (rdist != -1) {
		dist = rdist + 1;
		res = max(res, dist + lh);
	}
	return max(lh, rh) + 1;
}

/** Count Nodes in a Complete Binary Tree **/
// Naive

int countNode(Node *root) {
	if (root == NULL)return 0;
	else
		return 1 + countNode(root->left) + countNode(root->right);
}

// Efficient

int countNode(Node *root) {
	int lh = 0, rh = 0;
	Node *curr = root;
	while (curr != NULL) {
		lh++;
		curr = curr->left;
	}
	curr = root;
	while (curr != NULL) {
		rh++;
		curr = curr->right;
	}
	if (lh == rh) {
		return pow(2, lh) - 1;
	} else {
		return 1 + countNode(root->left) + countNode(root->right);
	}
}

/** Serialize and Deserialize a Binary Tree **/

// Serialize

const int EMPTY = -1;
void serialize(Node *root, vector<int> &arr) {
	if (root == NULL) {
		arr.push_back(EMPTY);
		return;
	}
	arr.push_back(root->key);
	serialize(root->left, arr);
	serialize(root->right, arr);
}

// DeSerialize

const int EMPTY = -1;
void serialize(Node *root, vector<int> &arr) {
	if (root == NULL) {
		arr.push_back(EMPTY);
		return;
	}
	arr.push_back(root->key);
	serialize(root->left, arr);
	serialize(root->right, arr);
}

Node *deSerialize(vector<int> &arr, int &index) {
	if (index == arr.size())
		return NULL;
	int val = arr[index];
	index++;
	if (val == EMPTY)return NULL;
	Node *root = new Node(val);
	root->left = deSerialize(arr, index);
	root->right = deSerialize(arr, index);
	return root;
}

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}



/***** Binary Search Tree *****/

// Recursive

bool search(Node *root, int x) {
	if (root == NULL)
		return false;
	if (root->key == x)
		return true;
	else if (root->key > x) {
		return search(root->left, x);
	} else {
		return search(root->right, x);
	}
}


// Iterative

bool search(Node *root, int x) {
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

/** Insert in BST in C++ **/

// Recursive
Node *insert(Node *root, int x) {
	if (root == NULL)
		return new Node(x);
	if (root->key < x)
		root->right = insert(root->right, x);
	else if (root->key > x)
		root->left = insert(root->left, x);
	return root;
}

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

// Iterative

Node *insert(Node *root, int x) {
	Node *temp = new Node(x);
	Node *parent = NULL, *curr = root;
	while (curr != NULL) {
		parent = curr;
		if (curr->key > x)
			curr = curr->left;
		else if (curr->key < x)
			curr = curr->right;
		else
			return root;
	}
	if (parent == NULL)
		return temp;
	if (parent->key > x)
		parent->left = temp;
	else
		parent->right = temp;
	return root;
}

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}


/** Deletion in BST **/

Node *getSuccessor(Node *curr) {
	curr = curr->right;
	while (curr != NULL && curr->left != NULL)
		curr = curr->left;
	return curr;
}

Node *delNode(Node *root, int x) {
	if (root == NULL)
		return root;
	if (root->key > x)
		root->left = delNode(root->left, x);
	else if (root->key < x)
		root->right = delNode(root->right, x);
	else {
		if (root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else {
			Node *succ = getSuccessor(root);
			root->key = succ->key;
			root->right = delNode(root->right, succ->key);
		}
	}
	return root;
}

void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

/** Floor in BST **/

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

/** Ceil in BST **/

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

/** Set in C++ in STL **/

main() {
	set<int> s;
	s.insert(10);
	s.insert(5);
	s.insert(20);
	for (int x : s) {
		cout << x << " ";
	} cout << endl;

	set<int, greater<int>> s1; //Decreasing order
	s1.insert(10);
	s1.insert(5);
	s1.insert(20);
	for (auto it = s1.begin(); it != s1.end(); it++) {
		cout << (*it) << " ";
	} cout << endl;

	// -------------------------
	set<int, greater<int>> s; //Decreasing order
	s.insert(10);
	s.insert(5);
	s.insert(20);
	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << (*it) << " ";
	} cout << endl;

	auto it = s.find(10);
	if (it == s.end())
		cout << "Not found" << endl;
	else
		cout << "Found" << endl;

	s.clear();
	cout << "Size: " << s.size() << endl;

	//----------------------------
	set<int> s;
	s.insert(10);
	s.insert(5);
	s.insert(20);
	s.insert(7);

	if (s.count(10))
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;

	s.erase(5);
	for (int x : s) {
		cout << x << " ";
	} cout << endl;

	auto it = s.find(7);
	s.erase(it);
	for (int x : s) {
		cout << x << " ";
	} cout << endl;

	//------------------------

	set<int> s;
	s.insert(10);
	s.insert(5);
	s.insert(20);

	auto it = s.lower_bound(5);
	if (it != s.end())
		cout << (*it) << endl;
	else
		cout << "Given element is greater than the largest" << endl;

	it = s.upper_bound(5);
	if (it != s.end())
		cout << (*it) << endl;
	else
		cout << "Given element is greater than the largest" << endl;
}


/** Map in C++ STL **/

main() {
	map<int, int> m;
	m.insert({10, 200});
	m[5] = 100;
	m.insert({3, 300});

	for (auto &x : m)
		cout << x.first << " " << x.second << endl;

	cout << "Size: " << m.size() << endl;

	m.at(10) = 300;
}

main() {
	// Beign() + end() + clear() + empty()
	map<int, int> m;
	m.insert({10, 200});
	m[5] = 100;
	m.insert({3, 300});

	for (auto it = m.begin(); it != m.end(); it++)
		cout << (*it).first << " " << (*it).second << endl;

	m.clear();
	cout << "Size: " << m.size() << endl;
	cout << "Empty: " << (m.empty() ? "Yes" : "No") << endl;
}

main() {
	// Find() + count() + lower_bound()
	map<int, string> m;
	m.insert({5, "gfg"});
	m.insert({2, "ide"});
	m.insert({1, "practice"});

	if (m.find(5) == m.end())
		cout << "Not found";
	else
		cout << "Found";
	cout << endl;
	if (m.count(2) == 0)
		cout << "Not found";
	else
		cout << "Found";
	cout << endl;
	auto it = m.lower_bound(7);
	if (it != m.end())
		cout << (*it).first << " ";
	else
		cout << "No Equal or Greater Value";
}

main() {
	// Upper_bound() + erase()
	map<int, string> m;
	m.insert({5, "gfg"});
	m.insert({2, "ide"});
	m.insert({1, "practice"});

	auto it = m.upper_bound(2);
	if (it != m.end())
		cout << (*it).first << endl;
	else
		cout << "Greater Value" << endl;

	m.erase(5);
	cout << "Size: " << m.size() << endl;

	m.erase(m.find(2), m.end());
	cout << "Size: " << m.size() << endl;
}

/** Ceiling on left side in an array **/
// Naive
void printCeiling(int arr[], int n) {
	cout << "-1" << " ";
	for (int i = 1; i < n; i++) {
		int diff = INT_MAX;
		for (int j = 0; j < i; j++) {
			if (arr[j] >= arr[i])
				diff = min(diff, arr[j] - arr[i]);
		}
		if (diff == INT_MAX)
			cout << "-1" << " ";
		else
			cout << (arr[i] + diff) << " ";
	}
}

// Efficient
void printCeiling(int arr[], int n) {
	cout << "-1" << " ";
	set<int> s;
	s.insert(arr[0]);
	for (int i = 1; i < n; i++) {
		if (s.lower_bound(arr[i]) != s.end())
			cout << *(s.lower_bound(arr[i])) << " ";
		else
			cout << "-1" << " ";
		s.insert(arr[i]);
	}
}

/** Find Kth Smallest in BST **/

// Naive
void printKth(Node *root, int k, int &count) {
	if (root != NULL) {
		printKth(root->left, k, count);
		count++;
		if (count == k)
		{cout << root->key; return;}
		printKth(root->right, k, count);
	}
}


// Efficient
Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);

	if (x < root->key) {
		root->left = insert(root->left, x);
		root->lCount++;
	}

	else if (x > root->key)
		root->right = insert(root->right, x);
	return root;
}

Node* kthSmallest(Node* root, int k)
{
	if (root == NULL)
		return NULL;

	int count = root->lCount + 1;
	if (count == k)
		return root;

	if (count > k)
		return kthSmallest(root->left, k);

	return kthSmallest(root->right, k - count);
}

main() {

	Node* root = NULL;
	int keys[] = { 20, 8, 22, 4, 12, 10, 14 };

	for (int x : keys)
		root = insert(root, x);

	int k = 4;
	Node* res = kthSmallest(root, k);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout << "K-th Smallest Element is " << res->key;
	return 0;
}

/** Check for BST **/

// Method 2(Correct but not efficient)
int maxValue(Node *root) {
	if (root == NULL)
		return INT_MIN;

	int res = root->key;
	int lres = maxValue(root->left);
	int rres = maxValue(root->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return res;
}

int minValue(Node* root)
{
	if (root == NULL)
		return INT_MAX;

	int res = root->key;
	int lres = minValue(root->left);
	int rres = minValue(root->right);
	if (lres < res)
		res = lres;
	if (rres < res)
		res = rres;
	return res;
}
int isBST(Node* root)
{
	if (root == NULL)
		return 1;

	if (root->left != NULL && maxValue(root->left) > root->key)
		return 0;

	if (root->right != NULL && minValue(root->right) < root->key)
		return 0;

	if (!isBST(root->left) || !isBST(root->right))
		return 0;

	return 1;
}

main() {

	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);

	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;

}

// Method 3 (Correct and Efficient)
bool isBST(Node* root, int min, int max)
{
	if (root == NULL)
		return true;

	return ( root->key > min && root->key < max &&
	         isBST(root->left, min, root->key) && isBST(root->right, root->key, max));
}

main() {

	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);

	if (isBST(root, INT_MIN, INT_MAX))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;

}

// Method 4 (Efficient Solution)

int prevv = INT_MIN;
bool isBST(Node* root)
{
	if (root == NULL)
		return true;

	if (isBST(root->left) == false)return false;

	if (root->key <= prevv)return false;
	prevv = root->key;

	return isBST(root->right);
}

main() {

	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);

	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;

}

/** Fix BST with Two Nodes Swapped **/
void inorder(Node *root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

Node *prevv = NULL, *first = NULL, *second = NULL;
void fixBST(Node* root)
{
	if (root == NULL)
		return;
	fixBST(root->left);
	if (prevv != NULL && root->key < prevv->key) {
		if (first == NULL)
			first = prevv;
		second = root;
	}
	prevv = root;

	fixBST(root->right);
}

int main() {

	Node *root = new Node(18);
	root->left = new Node(60);
	root->right = new Node(70);
	root->left->left = new Node(4);
	root->right->left = new Node(8);
	root->right->right = new Node(80);

	inorder(root);
	cout << endl;
	fixBST(root);
	int temp = first->key;
	first->key = second->key;
	second->key = temp;
	inorder(root);

	return 0;

}

/** Pair Sum with given BST **/

// Method 1(Inorder Traversal)
void treeToList(Node *root, vector<int> &list)
{
	if (root == NULL)
		return;

	treeToList(root->left, list);
	list.push_back(root->key);
	treeToList(root->right, list);
}

bool isPairPresent(Node *root, int target)
{
	vector<int> a2;

	treeToList(root, a2);

	int start = 0;

	int end = a2.size() - 1;

	while (start < end) {

		if (a2[start] + a2[end] == target)
		{
			cout << "Pair Found: " << a2[start] << " + " << a2[end] << " "
			     << "= " << target;
			return true;
		}

		if (a2[start] + a2[end] > target) // decrements end
		{
			end--;
		}

		if (a2[start] + a2[end] < target) // increments start
		{
			start++;
		}
	}

	cout << "No such values are found!";
	return false;
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(8);
	root->right = new Node(20);
	root->left->left = new Node(4);
	root->left->right = new Node(9);
	root->right->left = new Node(11);
	root->right->right = new Node(30);
	root->right->right->left = new Node(25);

	int sum = 33;

	isPairPresent(root, sum);

	return 0;

}

// Method 2 (Hashing)

bool isPairSum(Node *root, int sum, unordered_set<int> &s)
{
	if (root == NULL)return false;

	if (isPairSum(root->left, sum, s) == true)
		return true;

	if (s.find(sum - root->key) != s.end())
		return true;
	else
		s.insert(root->key);
	return isPairSum(root->right, sum, s);
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(8);
	root->right = new Node(20);
	root->left->left = new Node(4);
	root->left->right = new Node(9);
	root->right->left = new Node(11);
	root->right->right = new Node(30);
	root->right->right->left = new Node(25);

	int sum = 33;
	unordered_set<int> s;
	cout << isPairSum(root, sum, s);

	return 0;
}

/** Vertical Sum in a Binary Tree **/

void vSumR(Node *root, int hd, map<int, int> &mp) {
	if (root == NULL)return;
	vSumR(root->left, hd - 1, mp);
	mp[hd] += root->key;
	vSumR(root->right, hd + 1, mp);
}

void vSum(Node *root) {
	map<int, int> mp;
	vSumR(root, 0, mp);
	for (auto sum : mp)
		cout << sum.second << " ";
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(50);
	root->left->left = new Node(30);
	root->left->right = new Node(40);

	vSum(root);

	return 0;

}

/** Vertical Traversal of Binary Tree **/

void vTraversal(Node *root) {
	map<int, vector<int>> mp;
	queue<pair<Node*, int>> q;
	q.push({root, 0});
	while (q.empty() == false) {
		auto p = q.front();
		Node *curr = p.first;
		int hd = p.second;
		mp[hd].push_back(curr->key);
		q.pop();
		if (curr->left != NULL)
			q.push({curr->left, hd - 1});
		if (curr->right != NULL)
			q.push({curr->right, hd + 1});
	}
	for (auto x : mp) {
		for (int y : x.second)
			cout << y << " ";
		cout << endl;
	}
}

/** Top View of a Binary Tree **/
void topView(Node *root) {
	map<int, int> mp;
	queue<pair<Node*, int>> q;
	q.push({root, 0});
	while (q.empty() == false) {
		auto p = q.front();
		Node *curr = p.first;
		int hd = p.second;
		if (mp.find(hd) == mp.end())
			mp[hd] = (curr->key);
		q.pop();
		if (curr->left != NULL)
			q.push({curr->left, hd - 1});
		if (curr->right != NULL)
			q.push({curr->right, hd + 1});
	}
	for (auto x : mp) {
		cout << x.second << " ";
	}
}




/** Bottom View of Binary Tree **/

void bottomView(Node *root) {
	map<int, int> mp;
	queue<pair<Node*, int>> q;
	q.push({root, 0});
	while (q.empty() == false) {
		auto p = q.front();
		Node *curr = p.first;
		int hd = p.second;
		mp[hd] = (curr->key);
		q.pop();
		if (curr->left != NULL)
			q.push({curr->left, hd - 1});
		if (curr->right != NULL)
			q.push({curr->right, hd + 1});
	}
	for (auto x : mp) {
		cout << x.second << " ";
	}
}


































































