#include<bits/stdc++.h>
#define ll long long
#include"0.GenralLib.cpp"
using namespace std;
typedef vector<int> Ints;



int main() {


//Using Lambdas

	Ints t{1, 2, 3, 4, 5, 6, 7};
	for_each(t.begin(), t.end(), [](int &a) {
		a = a * 5;
	});

	for_each(t.begin(), t.end(), [](int &a) {
		cout << a << " " << endl;
	});

	return 0;
}