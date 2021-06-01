#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
	int data;
public:
	Node*next;
	Node(int x) {
		data = x;
		next = NULL;
	}

	void display(Node*);
	Node* addbegin(int , Node*);
	Node* push(int , Node*);
	Node* insertBetween(int , int, Node*);
};

void Node::display(Node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head ->next;
	}
}

Node* Node::addbegin(int data, Node*head) {
	Node*curr ;
	curr = new Node(data);

	if (head == NULL) {
		return curr;
	}

	curr->next = head;
	head = curr;
	return head;
}

Node* Node::push(int data, Node*head) {
	Node*curr;
	curr = new Node(data);
	if (head == NULL) {
		return curr;
	}

	Node*temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp ->next = curr;
	return head;
}

Node* Node::insertBetween(int data, int pos, Node*head) {
	Node*curr = new Node(data);
	Node*temp = head;
	if (head == NULL) {
		return curr;
	}
	while (pos--) {
		if (pos == 0) {
			curr->next = temp->next;
			temp->next = curr;
		}
		temp = temp ->next;
	}

	return head;
}

int main() {

	Node* list;
	Node*head = new Node(31);
	// Node*head = NULL;
	head ->next = new Node(13);
	list -> display(head);
	cout << endl;
	head = list->addbegin(53, head);
	head = list->addbegin(83, head);
	head = list->addbegin(23, head);
	head = list->push(90, head);
	head = list->push(190, head);
	head = list->insertBetween(390, 3 , head);
	list -> display(head);
	return 0;
}