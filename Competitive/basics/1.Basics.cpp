#include<bits/stdc++.h>
#define ll long long
#define pi 3.14
using namespace std;

// Area and Circumfrence of Circle
int Circumfrence(int num) {
	return 2 * pi * num;
}
int Area(int num) {
	return num * num;
}


// Write a program to add N numbers taken from user.
int sumN(int n) {
	int test(0), sum(0);
	while (n--) {
		cin >> test;
		sum += test;
	}
	return sum;
}

// Check If Number is Prime or Not
bool CheckPrimme(int num) {
	bool x = true;
	int div = 2;
	while (div < num) {
		if (num % div == 0 )
			x = false;
		div = div + 1;
	}
	return x;
}

// Understanding Array
void UnderstandingArray() {
	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(arr1) / sizeof(int);
	cout << size << endl;
	int arr2[size] = {0};
	for (int i = 0; i < size; i++) {
		cout << arr2[i] << " ";
	}
}

// Finding SquareRoot and Mean
void SqrtAndMean() {

	int SIZE = 7;
	int marks[] = {74, 43, 58, 60, 90, 64, 70};
	int sum = 0;
	int sumSq = 0;
	double mean, stdDev;
	for (int i = 0; i < SIZE; ++i) {
		sum += marks[i];
		sumSq += marks[i] * marks[i];
	}
	mean = (double)sum / SIZE;
	cout << fixed << "Mean is " << setprecision(2) << mean << endl;
	stdDev = sqrt((double)sumSq / SIZE - mean * mean);
	cout << fixed << "Std dev is " << setprecision(5) << stdDev << endl;
}

int main() {
	// cout << Circumfrence(3) << endl;
	// cout << Area(4) << endl;
	// cout << "Sum of Three No. is : " << sumN(3) << endl;
	// CheckPrimme(52) == 1 ? cout << "Prime" << endl : cout << "Not Prime" << endl;
	// SqrtAndMean();
	// int x = 43;
	// cout << sqrt(4) << " " << fixed << setprecision(3) << double(x);
	// UnderstandingArray();
	return 0;
}