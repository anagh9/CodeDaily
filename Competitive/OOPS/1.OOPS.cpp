#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Vehicle {
	double price;
	int numWheels;
	int yearofManufacture;

public:
	string brand;
	string model;


	void getDetails(double price,
	                int numWheels ,
	                int yearofManufacture
	               ) {
		this->price = price;
		this->numWheels = numWheels ;
		this->yearofManufacture = yearofManufacture ;
	}

	double getPrice() {
		return price;
	}



	void printDescription() {
		cout << brand << " " << model << " " << price << " " << yearofManufacture << endl;
	}
};


int main() {

	Vehicle v1, v2;
	v1.getDetails(25.64, 4, 2002);
	v2.getDetails(30.64, 4, 2010);
	v1.brand = "Toyoto"; v2.brand = "Mercedes";
	v1.model = "S2V"; v2.model = "S4";

	cout << v1.getPrice() << endl;
	cout << v2.getPrice() << endl;
	v1.printDescription();
	v2.printDescription();


	return 0;
}