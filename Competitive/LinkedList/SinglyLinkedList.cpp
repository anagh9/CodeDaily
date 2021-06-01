#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int x) {
		data = x;
		next = nullptr;
	}
};


Node* pushAtBeg(int data, Node* head) {
	Node*temp = new Node(data);
	temp ->next = head;
	return temp;
}

Node* pushAtEnd(int data, Node* head) {
	Node*temp = new Node(data);
	if (head == NULL)
		return temp;

	Node*curr = head;
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	curr->next = temp;
	return head;
}

Node* insertPos(Node* head, int pos, int data)
{
	Node *curr = head;
	if (pos < 1)
		return nullptr;
	for (int i = 0; i < pos && curr->next != nullptr; i++) {
		curr = curr ->next;
	}

	Node*temp = new Node(data);
	curr ->next = temp;
	return head;
}

Node* delFirst(Node*head) {
	if (head == nullptr) return nullptr;
	else {

		Node* temp = head;
		temp = temp->next;
		head = temp;
	}
	return head;
}

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

int ListLength(Node *head) {
	Node *temp = head;
	int count = 0;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

void Traverse(Node *head) {
	Node *temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void RecursiveTraversal(Node *head) {
	if (head == nullptr) return;
	cout << (head->data) << " ";
	RecursiveTraversal(head->next);
}


int main() {

	Node *temp = new Node(12);
	temp = pushAtBeg(10, temp);
	temp = pushAtBeg(11, temp);
	temp = pushAtBeg(14, temp);
	temp = pushAtEnd(514, temp);
	temp = pushAtEnd(5414, temp);
	temp = pushAtBeg(90, temp);
	Traverse(temp);
	cout << "\n" <<  ListLength(temp) << endl;

	// temp = delFirst(temp);
	// temp = delFirst(temp);
	// temp = delFirst(temp);
	cout << "\n" <<  ListLength(temp) << endl;
	RecursiveTraversal(temp); cout << endl;
	temp = delTail(temp);
	// temp = delTail(temp);
	// temp = delTail(temp);
	RecursiveTraversal(temp);
	cout << endl;
	temp = insertPos(temp, 1, 43);
	temp = insertPos(temp, 2, 143);
	temp = insertPos(temp, 3, 473);
	RecursiveTraversal(temp);

	return 0;
}