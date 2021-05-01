#include<bits/stdc++.h>
#define ll long long
#define Ints vector<int>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define fo(i,a,b) for(int i = a; i <b; i++)
#define fv(it,a)  for(auto it = a.begin() ; it!=a.end(); it++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define PI 3.1415926535897932384626
using namespace std;

const int mod = 1000000007;
const int N = 3e5, M = N;

void FastI()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {

	int i = 0, j = 0, k = 0;
	int n1 = arr1.size();
	int n2 = arr2.size();
	int n3 = n1 + n2;

	Ints arr3(n3);
	while (i < n1 && j < n2)
	{
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	while (i < n1)
		arr3[k++] = arr1[i++];

	while (j < n2)
		arr3[k++] = arr2[j++];

	int mean;
	double result = 0;

	if (n3 % 2 == 0) {
		mean = n3 / 2;
		result = ( float(arr3[mean - 1]) + float(arr3[mean])) / 2.000;
	}

	else {
		mean = (n3 + 1) / 2;
		result = arr3[mean - 1] ;
	}

	cout << result << endl;
	return result;

}

void solve() {
	int n, m;
	cin >> n >> m;

	Ints v1(n);
	Ints v2(m);

	for (int i = 0; i < n; i++) cin >> v1[i];
	for (int i = 0; i < m; i++) cin >> v2[i];
	std::cout << std::fixed;
	std::cout << std::setprecision(5) << findMedianSortedArrays(v1, v2) << endl;

}

int main() {
	FastI();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
