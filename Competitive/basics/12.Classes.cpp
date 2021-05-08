#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Vector {
public:
	Vector(int s): elem{new double[s]}, sz{s} {} //Construct a vector
	double& operator[](int i) {return elem[i];} //element access: subscripting
	int size() {return sz;}
private:
	double*elem; //pointer to element
	int sz; // the number of element

};

double readAndSum(int s) {
	Vector v(s);  //make a vector of s elements
	for (int i = 0; i != v.size(); ++i)
		cin >> v[i]; // read into elements

	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
		sum += v[i]; // take the sum of the elements
	return sum;
}

int main() {

	cout << readAndSum(5);


	return 0;
}