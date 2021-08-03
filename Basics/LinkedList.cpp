#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)

class Node{
public:
	int data;
	Node*next;
	Node(int data){
		this->data = data;
		next = NULL;
	}

};

class DoubleLinkedList{
public:
	int data;
	Node*prev;
	Node*next;

	DoubleLinkedList(int data){
		this->data = data;
		prev = next = NULL;
	}
};

Node *insertAtTail(Node* head,int d){
	Node*curr = head;
	Node*temp = new Node(d);
	
	if(curr == NULL)
		return temp;
	else{
		while(curr->next!=NULL){
			curr=curr->next;
		}

		curr->next = temp;
	}
	return curr;
}

Node *insertAtBegin(Node* head,int data){
	Node*temp = new Node(data);
	temp->next = head;
	return temp;
}

Node* delHead(Node *head){
	if(head == NULL) return NULL;
	else{
		Node* temp = head ->next;
		delete(head);
		return temp;
	}
}

void printList(Node*head){
	Node*curr = head;
	while(curr){
		cout<<curr->data<<" -> ";
		curr=curr->next;
	}
	cout<<"Null";
}

void singleLinkedList(){
	Node*head = new Node(12);
	head->next = new Node(43);
	head->next->next = new Node(433);
	head->next->next->next = new Node(143);

	insertAtTail(head,32);
	insertAtTail(head,62);
	insertAtTail(head,321);
	insertAtTail(head,312);
	insertAtTail(head,132);
	insertAtTail(head,1342);
	head = insertAtBegin(head,554);
	printList(head);
	delHead(head);cout<<"\n\n";
	printList(head);
}

void doublyLinkedList(){

}

int main(){
	singleLinkedList();
	// doublyLinkedList();
	return 0;
}