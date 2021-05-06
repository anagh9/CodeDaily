#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<int> Ints;

void printV2(int s) {
	cout << s * 2 << endl;
}

int main() {
	Ints v{1, 5, 2, 3, 7, 8};
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), printV2);
	cout << endl;





	return 0;
}

