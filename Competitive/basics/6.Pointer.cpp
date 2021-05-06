#include<bits/stdc++.h>
#define ll long long
using namespace std;


void Pointer() {
	int *iPtr;
	double *dPtr;
	//	cout << iPtr << " " << *iPtr << endl; // cannot Access *iPtr right Now
	int num = 8;
	iPtr = &num;
	cout << iPtr << " " << &num << " " << num << " " << *iPtr << endl;

	// Indirection or Dereferencing Operator (*)
	*iPtr = 99;
	cout << iPtr << " " << &num << " " << num << " " << *iPtr << endl;
}

void Pointer1() {
	int number = 88;
	int * pNumber = &number;
	// Declare and assign the address of variable number to pointer pNumber (0x22ccec)
	cout << pNumber << endl ;
	// Print the content of the pointer variable, which contain an address (0x22ccec)
	cout << *pNumber << endl;
	// Print the value “pointed to” by the pointer, which is an int (88)
	*pNumber = 99;
	// Assign a value to where the pointer is pointed to, NOT to the pointer variable
	cout << *pNumber << endl;
	// Print the new value “pointed to” by the pointer (99)
	cout << number << endl;
	// The value of variable number changes as well (99)
}

void Pointer2() {
	//Uninitialized Pointer Serious Logical Error
	int *iPtr;
	*iPtr = 55;
	cout << *iPtr << endl;
}

void Pointer3() {
	int x = 43;
	int *ptr;
	ptr = &x;
	int** dptr;
	dptr = &ptr;
	int ***tptr;
	tptr = &dptr;
	cout << *ptr << " : " << ptr << endl;
	cout << **dptr << " : " << *dptr << endl;
	cout << ***tptr << " : " << **tptr << endl;
	cout << "&ptr : " << &ptr << endl;
	cout << "dptr : " << dptr << endl;
	cout << "*tptr : " << *tptr << endl;

	cout << "&ptr : " << &ptr << endl;
	cout << "&dptr : " << &dptr << endl;
	cout << "tptr : " << tptr << endl;
}
void Pointer4() {
	int x = 32;
	int*ptr = &x;
	cout << *ptr << endl; // We Cannot Access
	cout << ptr;  // We Cannot Access
}

int main() {
	Pointer4();
	return 0;
}