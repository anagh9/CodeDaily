#include<bits/stdc++.h>
#define ll long long
using namespace std;

namespace Hello {
void getFunction() {
	cout << "Meow Meow" << endl;
}

string s = "Name is Anythings";

class x {
public:
	string newname = "Declared name";
};
}

int main() {

	Hello::getFunction();
	cout << Hello::s << endl;
	Hello:: x x1;
	cout << x1.newname;


	return 0;
}