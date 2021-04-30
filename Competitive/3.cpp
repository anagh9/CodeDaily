// sum of all submatrix of a given matrix

#include<iostream>
#define MAX 100
#define fo(i,n) for(int(i);i<n;i++)
using namespace std;
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int main() {
	c_p_c();
	int row, column, sum = 0;
	// cout << "Enter number of rows: ";
	cin >> row;
	// cout << "Enter number of columns: ";
	cin >> column;
	int arr[MAX][MAX];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> arr[i][j];
		}
	}



	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << i << " " << j << " ";
			sum += arr[i][j] * (i + 1) * (j + 1) * (row - i) * (column - j);
			cout << sum << " ";
		}
		cout << endl;
	}

	cout << sum;
}

