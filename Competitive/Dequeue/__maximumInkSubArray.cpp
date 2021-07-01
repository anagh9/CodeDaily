
/**
 * Given Aray and k
 * i/p : arr[] = {10,8,5,12,15,7,6}
 * k =3
 *
 * o/p : 10 12 15 15 15
 *
 * Explanation : maximum of 1st 3 then next 3 then so on ..
 * {10,8,5} {8,5,12} {5,12,15} {12,15,7} {15,7,6}
 *
 * i/p : 20 5 3 8 6 15
 * k = 4
 *
 * o/p : 20 8 15
 *
 * */

void NaiveSolution(int arr[], int n, int k) {
	for (int i = 0; i < n - k + 1; i++) {
		int mx = arr[i];
		for (int j = i + 1; j < i + k; j++) {
			mx = max(arr[j], mx);
		}
		cout << mx << endl;
	}
}


#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


void printMax(int arr[], int n, int k)
{

	deque<int> dq;



	for (int i = 0; i < k; ++i) {

		while (!dq.empty() && arr[i] >= arr[dq.back()])
			dq.pop_back();


		dq.push_back(i);
	}


	for (int i = k; i < n; ++i) {

		cout << arr[dq.front()] << " ";


		while ((!dq.empty()) && dq.front() <= i - k)
			dq.pop_front();


		while ((!dq.empty()) && arr[i] >= arr[dq.back()])
			dq.pop_back();


		dq.push_back(i);
	}


	cout << arr[dq.front()];
}

int main()
{
	int arr[] = { 20, 40, 30, 10, 60}, n = 5;
	int k = 3;

	printMax(arr, n, k);

	return 0;
}