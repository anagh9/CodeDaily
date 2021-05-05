#include<bits/stdc++.h>
#define ll long long
using namespace std;

int power(int x, int n)
{
	if (n == 1)
	{
		return x;
	}
	int smallPow = power(x, n / 2);
	if (n % 2 == 0) {
		return smallPow * smallPow;
	}
	else {
		return smallPow * smallPow * x;
	}
}

void printID(int n)
{
	if (n == 0)
		return;
	cout << n << endl;
	printID(n - 1);
	cout << n << endl;
}

int main() {
	cout << power(21, 12) << endl << endl;
	printID(40);
	return 0;
}