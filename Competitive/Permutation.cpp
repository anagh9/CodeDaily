#include<bits/stdc++.h>
#define ll long long
#define Ints vector<int>
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

void solve() {
	int n;
	cin >> n;

	int p = n;
	if (n == 1) cout << 1;
	else if (n == 4) cout << "2 4 1 3" << endl;
	if (n < 5)
		cout << "NO SOLUTION" << endl;

	else if (n % 2 == 0) {
		while (n != 1) {

			cout << n  << " ";
			n = n - 2;
			if (n == 2) {
				cout << n << " ";
				n = p - 1;
			}
		}
		cout << 1 << endl;
	}

	else {
		while (n != 2) {

			cout << n  << " ";
			n = n - 2;
			if (n == 1) {
				cout << n << " ";
				n = p - 1;
			}
		}
		cout << 2 << endl;
	}

}



int main() {
	// FastI();
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
