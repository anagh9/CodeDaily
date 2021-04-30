#include<bits/stdc++.h>
#define ll long long
#define vi  vector<int>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fo(i,a,b) for(int i = a; i <b; i++)
#define fv(it,a)  for(auto it = a.begin() ; it!=a.end(); it++)
#define PI 3.1415926535897932384626
using namespace std;
const int mod = 1000000007;
const int N = 3e5, M = N;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve() {
	char c[] = {'*', '3', '*', '1'};
	int n = sizeof(c) / sizeof(c[0]);
	sort(c, c + n);

	fo(i, 0, n)	cout << c[i] << " ";

}

int main() {
	c_p_c();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
3
5 2
*a*b*
5 2
*a**b
5 1
abcde
*/