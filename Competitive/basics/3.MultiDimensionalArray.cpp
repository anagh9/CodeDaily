#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Print the contents of rows-by-3 array (columns is fixed)
void printArray(const int array[][3], int rows) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

// Working With Strings
void WorkingString() {
	char msg[256];
	cout << "Enter a message (with space)" << endl;
	cin.getline(msg, 256); // Read up to 255 characters into msg
	// cout << msg << endl;

	// Access via null-terminated character array
	for (int i = 0; msg[i] != '\0'; ++i) {
		cout << msg[i];
	}
	cout << endl;
}

void WorkingString2() {
	char msg[256];
	cout << "Enter a word (without space)" << endl;
	cin >> msg;
	cout << msg << endl;
	// Access via null-terminated character array
	for (int i = 0; msg[i] != '\0'; ++i) {
		cout << msg[i];
	}
	cout << endl;
}

int main() {

	int myArray[][3] = {{8, 2, 4}, {7, 5, 2}, {9, 4, 1}}; // 2x3 initialized

	// Only the first index can be omitted and implied
	// printArray(myArray, 3);
	WorkingString2();


	return 0;
}