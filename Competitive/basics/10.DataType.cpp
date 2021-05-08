#include<bits/stdc++.h>
#include <typeinfo>
#define ll long long
using namespace std;

template <typename T>
void print(T x) {cout << "#x: "  << x << endl;}

constexpr double square(const int x) {
	return x * x;
}

void definingConst() {
	// C++ supports two notions of immutability:
	// const
	// constexpr

	const int dmv = 17; // dmv is a named constant
	constexpr double max1 = 1.4 * square(dmv); // OK if square(17) is a constant expression
	// cout << dmv << " " << max1 << endl;
	print(dmv);
	print(max1);
}

void ComplexDefination() {
	complex<double> z(1);
	complex<double> z2{2.1, 3.4};
	complex<double> z3 = {2.1, 3.4};
	cout << z << " " << z2 << " " << z3 << endl;
}

void AutoDefination() {
	int y = 8.31;
	auto b = true; // a bool
	auto ch = 'x'; // a char
	auto i = 123; // an int
	auto d = 1.2; // a double
	auto ss = sqrt(y); // z has the type of whatever sqr t(y) retur ns

	print(b);
	print(ch);
	print(i);
	print(d);
	print(ss);
}

int main() {
	definingConst();
	return 0;
}