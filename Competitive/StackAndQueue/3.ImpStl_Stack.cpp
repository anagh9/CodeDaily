#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << s.size() << endl;
	while (s.empty() == false) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
// TC = O(1)
// We can Implement Stack from list , vector , deque
// By Default Implemented In deque