#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
public:
	int data;
	Node*next;
	Node(int s) {
		data = s;
		next = NULL;
	}
};

typedef struct SinglyLinkedList {
	int data;
	SinglyLinkedList* next;
	SinglyLinkedList(int x) {
		data = x;
		next = NULL;
	}
} Nodee;

void Traverse(SinglyLinkedList* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	// 12 21 31 41
}

void Traversex(SinglyLinkedList* head) {
	while (head->next != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	// 12 21 31
}

void Understanding(Nodee*head) {
	cout << head->data << endl; // 12
	cout << head->next->data << endl; // 21

}

int main() {

	SinglyLinkedList* head = new SinglyLinkedList(12);
	head->next = new SinglyLinkedList(21);
	head->next->next = new SinglyLinkedList(31);
	head->next->next->next = new SinglyLinkedList(41);
	Traverse(head);
	Traversex(head);
	Understanding(head);

	/*Class Defination*/
	Node*newNode = new Node(3);
	newNode ->next = new Node(56);
	newNode ->next ->next = new Node(16);
	while (newNode != NULL) {
		cout << newNode ->data << " -> ";
		newNode = newNode->next;
	} cout << "NULL"; //3 -> 56 -> 16 -> NULL
	return 0;
}