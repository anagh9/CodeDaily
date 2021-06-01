
/*
Prices of a Stock On N consecutive days
Our Task Is to find out span of stock on every days

i/p: 13, 15 , 12 , 14, 16, 8, 6, 4, 10, 30
o/p: 1 ,  1 ,  1 ,  2,  5, 1, 1, 1,  4, 10

i/p: 10, 20, 30, 40
o/p  1 ,  2,  3,  4

i/p: 40, 30, 20, 10
o/p: 1,   1,  1,  1

*/

#include <bits/stdc++.h>
using namespace std;

/* Naive Solution */

// Iterating From Last Everytime
// for i = 3 we are go back j = 2 j = 1
// Checking From Span

void NaiveprintSpan(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int span = 1;
		for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
			span++;
		cout << span << " ";
	}
}



/* Efficient Solution */
// We need to store element we just processsed
// We need to store prev greater of that element
// We always store greater element in stack while iterating


void printSpan(int arr[], int n) {

	stack<int> s ;
	s.push(0);
	cout << 1 << " ";
	for (int i = 1; i < n; i++) {
		while (s.empty() == false && arr[s.top()] <= arr[i]) {
			s.pop();
		}
		int span = s.empty() ? i + 1 : i - s.top();
		cout << span << " ";
		s.push(i);
	}
}
// TC - O(n) AS- O(n)

int main()
{
	int arr[] = {18, 12, 13, 14, 11, 16};
	int n = 6;
	NaiveprintSpan(arr, n);
	printSpan(arr, n);
	return 0;
}
