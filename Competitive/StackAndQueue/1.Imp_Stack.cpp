// Stack DataStructure
// Functions:

// s.isEmpty()
// s.push()
// s.pop()
// s.peek()
// s.size()


// UnderFLow Condition :
// When pop() or peek() on empty stack

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct mystack {
	int *arr;
	int cap;
	int top;
	mystack(int c) {
		cap = c;
		arr = new int[cap];
		top = 01;
	}
	void push(int x) {
		top++;
		arr[top] = x;
	}
	int pop() {
		int res = arr[top];
		top--;
		return res;
	}
	int peek() {
		return arr[top];
	}

	int size() {
		return (top + 1);
	}

	bool isEmpty() {
		return (top == -1);
	}
};


// We need To Include Underflow and Overflow

int main() {

	mystack s(5);
	s.push(5);
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << endl;
	cout << s.peek() << endl;
	cout << s.isEmpty() << endl;
	return 0;
}