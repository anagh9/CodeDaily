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
	ll n;
	cin >> n;
	ll sum = n * (n + 1) / 2;
	ll a, total = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		total += a;
	}
	cout << (sum - total) << endl ;
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
