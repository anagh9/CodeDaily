#include<bits/stdc++.h>
#define ll long long
using namespace std;



void RangeBasedLoop() {
	int nums[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};

	// For each member called number of array numbers - read only
	for (int num : nums)
		cout << num << " ";

	// To modify members, need to use reference (&)
	for (int &num : nums) {
		num = 99;
	}
	cout << endl;

	for (int num : nums) {
		cout << num << " ";
	}
}



int main() {

	RangeBasedLoop();


	return 0;
}