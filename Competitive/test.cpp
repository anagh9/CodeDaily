// #include<bits/stdc++.h>
// #define ll long long
// #define Ints vector<int>
// #define pb push_back
// #define mp make_pair
// #define fo(i,a,b) for(int i = a; i <b; i++)
// #define fv(it,a)  for(auto it = a.begin() ; it!=a.end(); it++)
// #define PI 3.1415926535897932384626
// using namespace std;
// const int mod = 1000000007;
// const int N = 3e5, M = N;
// #include"./basics/0.GenralLib.cpp"

// void FastI()
// {
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// }

// ostream_iterator<string> oo{cout};
// int main() {
// 	FastI();
// 	*oo = "Hello, ";
// 	++oo;
// 	*oo = "World\n";

// 	print("Hello Bhaiya");
// 	print(10);
// 	print(10.32);
// 	// int x{12};
// 	// int y(12);
// 	// cout << x << "\n" << y;
// 	// vector<int> v{1, 2, 3, 4, 5, 6};
// 	// sort(v.begin(), v.end());
// 	// // find(1, v.begin(), v, end());
// 	// cout << ~(32);
// 	// cerr << ~(32);
// 	// return 0;
// }


#include "t1.cpp"

int main() {
	FastI();
	Ints v{1, 2, 3, 4, 5, 6, 7};
	int ser = 4;
	std::vector<int>::iterator it = find(v.begin(), v.end(), 6);
	if (it != v.end())
	{
		std::cout << "Element " << ser << " found at position : " ;
		std::cout << it - v.begin() << " (counting from zero) \n" ;
	}
	// print(p);
	// find(v.begin(), v.end(), 6) ? cout << "Found\n" : "Not Found\n" ;
	print("Hello") ;
}