/*

i/p : 15 , 10 , 18 , 12 , 4, 5  , 2, 8
o/p : -1 , 15 , -1 , 18 , 12, 12, 6, 12

i/p : 8, 10, 12
o/p : -1, -1, -1

i/p : 12 10 8
o/p : -1 12 10

*/

#include <bits/stdc++.h>
using namespace std;


// Naive Solution
void NaiveprintPrevGreater(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				cout << arr[j] << " ";
				break;
			}
		}
		if (j == -1)
			cout << -1 << " ";
	}
}
// TC - O(n^2)

/* Efficient Solution */
// We are pushing element while iterating
// And Comparing looping item with stack top if stack top is smaller than it then popping it and pushing the looping item

void printPrevGreater(int arr[], int n) {
	stack<int>s;
	s.push(arr[0]);
	for (int i = 0; i < n; i++) {
		while (s.empty() == false && s.top() <= arr[i])
			s.pop();
		int pg = s.empty() ? -1 : s.top();
		cout << pg << " ";
		s.push(arr[i]);
	}
}

int main()
{
	int arr[] = {20, 30, 10, 5, 15};
	int n = 5;
	NaiveprintPrevGreater(arr, n);
	printPrevGreater(arr, n);
	return 0;
}
