//CSES ProblemSet - Weird Algorithm

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
	long long n;
	cin >> n;
	cout << n << " ";
	while (n != 1) {
		if (n % 2 == 0) {

			cout << n / 2 << " ";
			n = n / 2;
		}
		else {

			cout << n * 3 + 1 << " ";
			n = n * 3 + 1;
		}

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
