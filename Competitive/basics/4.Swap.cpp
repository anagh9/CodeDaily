#include<bits/stdc++.h>
#define ll long long
using namespace std;


void swap(int x , int y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap2(int &x, int&y) {
	//x and y are references...call by reference
	int temp = x;
	x = y;
	y = temp;
}

int main() {

	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << a << " " << b << endl; // No Swaping

	swap2(a, b);
	cout << a << " " << b << endl; // Values Actually Swapped


	return 0;
}