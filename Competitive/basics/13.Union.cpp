/*
A union is a struct in which all members are allocated at the same address so that the union occupies
only as much space as its largest member. Naturally, a union can hold a value for only one
member at a time.
*/

#include<bits/stdc++.h>
using namespace  std;

enum Type {str, num};
enum Meal {Breakfast, Lunch, Dinner};

// It uses Only One at a time , It Share memory it only allocates maximum memory among all data

union Money {
	int rice;
	char car;
	float pounds;
};



int main() {
	union Money m1;
	m1.rice = 34;
	cout << m1.rice << endl;

	//Using Enum

	cout << Breakfast << endl; //0
	cout << Lunch << endl; //1
	cout << Dinner << endl;//2
}
