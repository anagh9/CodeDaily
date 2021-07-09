// All About Linked List

// Simple LinkedList Implementation

struct Node {
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

int main()
{
	Node *head = new Node(10);
	Node *temp1 = new Node(20);
	Node *temp2 = new Node(30);
	head->next = temp1;
	temp1->next = temp2;
	cout << head->data << "-->" << temp1->data << "-->" << temp2->data;
	return 0;
}

/* Traversing To a Linked List*/

void printlist(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
}


/* Insert At Begin Of Linked LIst */

Node *insertBegin(Node *head, int x) {
	Node *temp = new Node(x);
	temp->next = head;
	return temp;

}

/* Insert At End Of Linked LIst */

Node *insertEnd(Node *head, int x) {
	Node *temp = new Node(x);
	if (head == NULL)return temp;
	Node *curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = temp;
	return head;

}

/* Delete First Node of Linked List*/

Node *delHead(Node *head) {
	if (head == NULL)return NULL;
	else {
		Node *temp = head->next;
		delete(head);
		return temp;
	}
}

/* Delete Last Node of Linked List*/
Node *delTail(Node *head) {
	if (head == NULL)return NULL;
	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	Node *curr = head;
	while (curr->next->next != NULL)
		curr = curr->next;
	delete (curr->next);
	curr->next = NULL;
	return head;
}

/* Search In a Linked List */
// Iterative

int search(Node * head, int x) {
	int pos = 1;
	Node *curr = head;
	while (curr != NULL) {
		if (curr->data == x)
			return pos;
		else {
			pos++;
			curr = curr->next;
		}
	}
	return -1;
}


// Recursive

int search(Node * head, int x) {
	if (head == NULL)return -1;
	if (head->data == x)return 1;
	else {
		int res = search(head->next, x);
		if (res == -1)return -1;
		else return res + 1;
	}
}


/* Doubly Linked List */

struct Node {
	int data;
	Node* prev;
	Node* next;
	Node(int d) {
		data = d;
		prev = NULL;
		next = NULL;
	}
};

void printlist(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	} cout << endl;
}

int main()
{
	Node *head = new Node(10);
	Node *temp1 = new Node(20);
	Node *temp2 = new Node(30);
	head->next = temp1;
	temp1->prev = head;
	temp1->next = temp2;
	temp2->prev = temp1;
	printlist(head);
	return 0;
}

/* Insert at Begin of DLL */

Node *insertBegin(Node *head, int data) {
	Node *temp = new Node(data);
	temp->next = head;
	if (head != NULL)head->prev = temp;
	return temp;

}

/* Insert at End of DLL */

Node *insertEnd(Node *head, int data) {
	Node *temp = new Node(data);
	if (head == NULL)return temp;
	Node *curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = temp;
	temp->prev = curr;
	return head;
}

/* Delete Head of DLL */

Node *delHead(Node *head) {
	if (head == NULL)return NULL;
	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	else {
		Node *temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
		return head;
	}
}

/* Delete Last of a Doubly Linked List */

Node *delLast(Node *head) {
	if (head == NULL)return NULL;
	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	Node *curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->prev->next = NULL;
	delete curr;
	return head;

}

/* Circular Linked List */


struct Node {
	int data;
	Node* next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};

int main()
{
	Node *head = new Node(10);
	head->next = new Node(5);
	head->next->next = new Node(20);
	head->next->next->next = new Node(15);
	head->next->next->next->next = head;
	return 0;
}

/* Circular LL traversal */

void printlist(Node *head) {
	if (head == NULL)return;
	cout << head->data << " ";
	for (Node *p = head->next; p != head; p = p->next)
		cout << p->data << " ";
}

// Using Do while
void printlist(Node *head) {
	if (head == NULL)return;
	Node *p = head;
	do {
		cout << p->data << " ";
		p = p->next;
	} while (p != head);
}

/* Insert at begin in CLL*/
Node *insertBegin(Node * head, int x) {
	Node *temp = new Node(x);
	if (head == NULL) {
		temp->next = temp;
		return temp;
	}
	else {
		temp->next = head->next;
		head->next = temp;
		int t = head->data;
		head->data = temp->data;
		temp->data = t;
		return head;
	}
}

// Naive
Node *insertBegin(Node * head, int x) {
	Node *temp = new Node(x);
	if (head == NULL)
		temp->next = temp;
	else {
		Node *curr = head;
		while (curr->next != head)
			curr = curr->next;
		curr->next = temp;
		temp->next = head;
	}
	return temp;
}

/*Insert at End Of LL*/

// Efficient => o(1)
Node *insertEnd(Node *head, int x) {
	Node *temp = new Node(x);
	if (head == NULL) {
		temp->next = temp;
		return temp;
	}
	else {
		temp->next = head->next;
		head->next = temp;
		int t = head->data;
		head->data = temp->data;
		temp->data = t;
		return temp;
	}
}


//Naive => o(n)
Node *insertEnd(Node *head, int x) {
	Node *temp = new Node(x);
	if (head == NULL) {
		temp->next = temp;
		return temp;
	}
	else {
		Node *curr = head;
		while (curr->next != head)
			curr = curr->next;
		curr->next = temp;
		temp->next = head;
		return head;
	}
}

/* Delete Head of Circular Linked List */

// Naive
Node *delHead(Node *head) {
	if (head == NULL)return NULL;
	if (head->next == head) {
		delete head;
		return NULL;
	}
	Node *curr = head;
	while (curr->next != head)
		curr = curr->next;
	curr->next = head->next;
	delete head;
	return (curr->next);
}


// Efficient

Node *delHead(Node *head) {
	if (head == NULL)return NULL;
	if (head->next == head) {
		delete head;
		return NULL;
	}
	head->data = head->next->data;
	Node *temp = head->next;
	head->next = head->next->next;
	delete temp;
	return head;
}

/* Delete Kth of a Circular Linked List */

Node *deleteHead(Node *head) {
	if (head == NULL)return NULL;
	if (head->next == head) {
		delete head;
		return NULL;
	}
	head->data = head->next->data;
	Node *temp = head->next;
	head->next = head->next->next;
	delete temp;
	return head;
}

/* Middle of Linked List */

// Naive
void printMiddle(Node * head) {
	if (head == NULL)return;
	int count = 0;
	Node *curr;
	for (curr = head; curr != NULL; curr = curr->next)
		count++;
	curr = head;
	for (int i = 0; i < count / 2; i++)
		curr = curr->next;
	cout << curr->data;
}

//Efficient
void printMiddle(Node * head) {
	if (head == NULL)return;
	Node *slow = head, *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << slow->data;
}

/* Nth Node from end of Linked List */

//Method 1(Using length of Linked List)

void printNthFromEnd(Node * head, int n) {
	int len = 0;
	for (Node *curr = head; curr != NULL; curr = curr->next)
		len++;
	if (len < n)
		return;
	Node *curr = head;
	for (int i = 1; i < len - n + 1; i++)
		curr = curr->next;
	cout << (curr->data) << " ";
}

// Method 2(Using Two Pointers/References)

void printNthFromEnd(Node * head, int n) {
	if (head == NULL)return;
	Node *first = head;
	for (int i = 0; i < n; i++) {
		if (first == NULL)return;
		first = first->next;
	}
	Node *second = head;
	while (first != NULL) {
		second = second->next;
		first = first->next;
	}
	cout << (second->data);
}

/* Reverse a Linked List Iterative */

// Naive
Node *revList(Node *head) {
	vector<int> arr;
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		arr.push_back(curr->data);
	}
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		curr->data = arr.back();
		arr.pop_back();
	}
	return head;
}

//Efficient
Node *reverse(Node *head) {
	Node *curr = head;
	Node *prev = NULL;
	while (curr != NULL) {
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

/* Recursive reverse a Linked List */

Node *recRevL(Node *head) {
	if (head == NULL || head->next == NULL)return head;
	Node *rest_head = recRevL(head->next);
	Node *rest_tail = head->next;
	rest_tail->next = head;
	head->next = NULL;
	return rest_head;
}

/* Recursive reverse a Linked List */

Node *recRevL(Node *curr, Node *prev) {
	if (curr == NULL)return prev;
	Node *next = curr->next;
	curr->next = prev;
	return recRevL(next, curr);
}

/* Remove duplicates from a sorted Singly LinkedList*/

void removeDuplicates(Node* head)
{
	Node* current = head;
	Node* next_next;
	if (current == NULL)
		return;

	while (current->next != NULL) {
		if (current->data == current->next->data) {
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		}
		else {
			current = current->next;
		}
	}
}

/* Reverse a Linked List in groups of size k*/

// Recursive Solution
Node *reverseK(Node *head, int k) {
	Node *curr = head, *next = NULL, *prev = NULL;
	int count = 0;
	while (curr != NULL && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if (next != NULL) {
		Node *rest_head = reverseK(next, k);
		head->next = rest_head;
	}
	return prev;
}

// Iterative Solution
Node *reverseK(Node *head, int k) {
	Node *curr = head, *prevFirst = NULL;
	bool isFirstPass = true;
	while (curr != NULL) {
		Node *first = curr, *prev = NULL;
		int count = 0;
		while (curr != NULL && count < k) {
			Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		if (isFirstPass) {head = prev; isFirstPass = false;}
		else {prevFirst->next = prev;}
		prevFirst = first;
	}
	return head;
}

/* Detecting Loop */

// Method 3(Changes References/Pointers)

bool isLoop(Node* head)
{	Node* temp = new Node(0);
	Node *curr = head;
	while (curr != NULL) {
		if (curr->next == NULL)
			return false;
		if (curr->next == temp)
			return true;
		Node *curr_next = curr->next;
		curr->next = temp;
		curr = curr_next;
	}
	return false;
}

// Hashing

bool isLoop(Node* head)
{
	unordered_set<Node*> s;
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		if (s.find(curr) != s.end())
			return true;
		s.insert(curr);
	}
	return false;
}

/* Detect Loop using Floyd cycle detection */

bool isLoop(Node* head)
{
	Node *slow_p = head, *fast_p = head;

	while (fast_p != NULL && fast_p->next != NULL) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) {
			return true;
		}
	}
	return false;
}

/* Detect and remove loop in Linked List */

void detectRemoveLoop(Node* head)
{
	Node *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}
	if (slow != fast)
		return;
	slow = head;
	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
}

/* Delete node with only pointer given to it*/

void deleteNode(Node *ptr) {
	Node *temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;
	delete(temp);
}

/* Segregate even odd nodes of Linked List */

Node *segregate(Node *head) {
	Node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		int x = curr->data;
		if (x % 2 == 0) {
			if (eS == NULL) {
				eS = curr;
				eE = eS;
			} else {
				eE->next = curr;
				eE = eE->next;
			}
		} else {
			if (oS == NULL) {
				oS = curr;
				oE = oS;
			} else {
				oE->next = curr;
				oE = oE->next;
			}
		}
	}
	if (oS == NULL || eS == NULL)
		return head;
	eE->next = oS;
	oE->next = NULL;
	return eS;
}

/* Intersection of Linked List */
// Hashing

int getIntersection(Node* head1, Node* head2)
{
	unordered_set<Node*> s;
	Node* curr = head1;
	while (curr != NULL) {
		s.insert(curr);
		curr = curr->next;
	}
	curr = head2;
	while (curr != NULL) {
		if (s.find(curr) != s.end())
			return curr->data;
		curr = curr->next;
	}
	return -1;
}

//=> New Method
int getCount(Node* head)
{
	Node* curr = head;
	int count = 0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

int _getIntersection(int d, Node* head1, Node* head2)
{
	Node* current1 = head1;
	Node* current2 = head2;

	for (int i = 0; i < d; i++) {
		if (current1 == NULL) {
			return -1;
		}
		current1 = current1->next;
	}

	while (current1 != NULL && current2 != NULL) {
		if (current1 == current2)
			return current1->data;

		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}

int getIntersection(Node* head1, Node* head2)
{
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;

	if (c1 > c2) {
		d = c1 - c2;
		return _getIntersection(d, head1, head2);
	}
	else {
		d = c2 - c1;
		return _getIntersection(d, head2, head1);
	}
}

/* Pairwise swap nodes of Linked List */
// Swapping Data

void pairwiseSwap(Node *head) {
	Node *curr = head;
	while (curr != NULL && curr->next != NULL) {
		swap(curr->data, curr->next->data);
		curr = curr->next->next;
	}
}

// Changing Pointer/Reference
Node *pairwiseSwap(Node *head) {
	if (head == NULL || head->next == NULL)
		return head;
	Node *curr = head->next->next;
	Node *prev = head;
	head = head->next;
	head->next = prev;
	while (curr != NULL && curr->next != NULL) {
		prev->next = curr->next;
		prev = curr;
		Node *next = curr->next->next;
		curr->next->next = curr;
		curr = next;
	}
	prev->next = curr;
	return head;
}


/* Clone a Linked List using a random pointer */
// Hashing

struct Node
{
	int data;
	Node *next, *random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};

void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
		ptr = ptr->next;
	}
}

Node* clone(Node *head)
{
	unordered_map<Node*, Node*> hm;
	for (Node *curr = head; curr != NULL; curr = curr->next)
		hm[curr] = new Node(curr->data);

	for (Node *curr = head; curr != NULL; curr = curr->next) {
		Node *cloneCurr = hm[curr];
		cloneCurr->next = hm[curr->next];
		cloneCurr->random = hm[curr->random];
	}
	Node *head2 = hm[head];

	return head2;
}

int main()
{
	Node* head = new Node(10);
	head->next = new Node(5);
	head->next->next = new Node(20);
	head->next->next->next = new Node(15);
	head->next->next->next->next = new Node(20);

	head->random = head->next->next;
	head->next->random = head->next->next->next;
	head->next->next->random = head;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = head->next->next->next;

	cout << "Original list : \n";
	print(head);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(head);
	print(cloned_list);

	return 0;
}

// Next Method
Node* clone(Node *head)
{
	Node *next, *temp;
	for (Node *curr = head; curr != NULL;) {
		next = curr->next;
		curr->next = new Node(curr->data);
		curr->next->next = next;
		curr = next;
	}
	for (Node *curr = head; curr != NULL; curr = curr->next->next) {
		curr->next->random = (curr->random != NULL) ? (curr->random->next) : NULL;
	}

	Node* original = head, *copy = head->next;

	temp = copy;

	while (original && copy)
	{
		original->next =
		    original->next ? original->next->next : original->next;

		copy->next = copy->next ? copy->next->next : copy->next;
		original = original->next;
		copy = copy->next;
	}

	return temp;
}

/* LRU Cacke Design */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int key;
	int value;
	Node *pre;
	Node *next;


	Node(int k, int v)
	{
		key = k;
		value = v;
		pre = NULL; next = NULL;
	}
};

class LRUCache {
public:
	unordered_map<int, Node*> map;
	int capacity, count;
	Node *head, *tail;


	LRUCache(int c)
	{
		capacity = c;
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		tail->pre = head;
		head->pre = NULL;
		tail->next = NULL;
		count = 0;
	}

	void deleteNode(Node *node)
	{
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}

	void addToHead(Node *node)
	{
		node->next = head->next;
		node->next->pre = node;
		node->pre = head;
		head->next = node;
	}

	int get(int key)
	{
		if (map[key] != NULL) {
			Node *node = map[key];
			int result = node->value;
			deleteNode(node);
			addToHead(node);
			cout << "Got the value : " <<
			     result << " for the key: " << key << endl;
			return result;
		}
		cout << "Did not get any value" <<
		     " for the key: " << key << endl;
		return -1;
	}

	void set(int key, int value)
	{
		cout << "Going to set the (key, " <<
		     "value) : (" << key << ", " << value << ")" << endl;
		if (map[key] != NULL) {
			Node *node = map[key];
			node->value = value;
			deleteNode(node);
			addToHead(node);
		}
		else {
			Node *node = new Node(key, value);
			map[key] = node;
			if (count < capacity) {
				count++;
				addToHead(node);
			}
			else {
				map.erase(tail->pre->key);
				deleteNode(tail->pre);
				addToHead(node);
			}
		}
	}
};

int main() {
	{

		LRUCache cache(2);

		// it will store a key (1) with value
		// 10 in the cache.
		cache.set(1, 10);

		// it will store a key (2) with value 20 in the cache.
		cache.set(2, 20);
		cout << "Value for the key: 1 is " << cache.get(1) << endl; // returns 10

		// removing key 2 and store a key (3) with value 30 in the cache.
		cache.set(3, 30);

		cout << "Value for the key: 2 is " <<
		     cache.get(2) << endl; // returns -1 (not found)

		// removing key 1 and store a key (4) with value 40 in the cache.
		cache.set(4, 40);
		cout << "Value for the key: 1 is " <<
		     cache.get(1) << endl; // returns -1 (not found)
		cout << "Value for the key: 3 is " <<
		     cache.get(3) << endl; // returns 30
		cout << "Value for the key: 4 is " <<
		     cache.get(4) << endl; // return 40

		return 0;
	}
}

/* Merge Two Sorted Linked List */

Node *sortedMerge(Node *a, Node *b) {
	if (a == NULL)return b;
	if (b == NULL)return a;
	Node *head = NULL, *tail = NULL;
	if (a->data <= b->data) {
		head = tail = a; a = a->next;
	}
	else {
		head = tail = b; b = b->next;
	}
	while (a != NULL && b != NULL) {
		if (a->data <= b->data) {
			tail->next = a; tail = a; a = a->next;
		}
		else {
			tail->next = b; tail = b; b = b->next;
		}
	}
	if (a == NULL) {tail->next = b;}
	else {
		tail->next = a;
	}
	return head;
}

/* Palindrome Linked List */

// Naive
bool isPalindrome(Node *head) {
	stack<char> st;
	for (Node *curr = head; curr != NULL; curr = curr->next)
		st.push(curr->data);
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		if (st.top() != curr->data)
			return false;
		st.pop();
	}
	return true;
}

// Efficient

Node *reverseList(Node *head) {
	if (head == NULL || head->next == NULL)return head;
	Node *rest_head = reverseList(head->next);
	Node *rest_tail = head->next;
	rest_tail->next = head;
	head->next = NULL;
	return rest_head;
}

bool isPalindrome(Node *head) {
	if (head == NULL)return true;
	Node *slow = head, *fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	Node *rev = reverseList(slow->next);
	Node *curr = head;
	while (rev != NULL) {
		if (rev->data != curr->data)
			return false;
		rev = rev->next;
		curr = curr->next;
	}
	return true;
}
