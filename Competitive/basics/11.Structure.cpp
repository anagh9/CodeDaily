#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Vector {
	int size; // number of elements
	double* elem; // pointer to elements
};

void init(Vector &v, int s) {
	v.elem = new double[s];
	v.size = s;
}

double readAndSum(int s) {
	Vector v;
	init(v, s);
	for (int i = 0; i != s; ++i)
		cin >> v.elem[i];

	double sum = 0;
	for (int i = 0; i != s; ++i)
		sum += v.elem[i];
	return sum;
}


void f(Vector v, Vector& rv, Vector* pv)
{
	int i1 = v.size; // access through name
	int i2 = rv.size;// access through reference
	int i4 = pv-> size; // access through pointer
}

int main() {

	cout << readAndSum(5) << endl;


	return 0;
}