#include<bits/stdc++.h>
#define ll long long
using namespace std;


void PrintDetails(char y_name[100], char y_address[100], char about_y[100]) {
	cout << "\nEntered details are:\n" << '\n';
	cout << "Name: " << y_name << endl;
	cout << "Address: " << y_address << endl;
	cout << "Profession is: " << about_y << endl;
}

void GetDetails() {
	char y_name[100], y_address[100], about_y[100];
	cout << "Enter Name: ";
	cin.getline(y_name, 100);

	cout << "Enter Address: ";
	cin.getline(y_address, 100);

	cout << "Enter Profession : ";
	cout << "Enter your profession (press $ to complete): ";
	cin.getline (about_y, 100, '$');

	PrintDetails(y_name, y_address, about_y);
}

void WorkingWithString() {
	string name;
	getline(cin, name);
	cout << name << endl << endl;
}



int main() {
	// GetDetails();
	WorkingWithString();

	return 0;
}