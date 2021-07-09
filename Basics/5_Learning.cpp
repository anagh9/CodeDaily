/******  {Mathematics , Recursion , Matrixes } ******/


/* Count Digits */

int countDigits(int x)
{
	int res = 0;
	while (x > 0)
	{
		x = x / 10;
		res++;
	}
	return res;
}

/* Palindrome Numbers */

bool isPal(int n)
{
	int rev = 0;

	int temp = n;
	while (temp != 0)
	{
		int ld = temp % 10;
		rev = rev * 10 + ld;
		temp = temp / 10;
	}

	return rev == n;
}

/* Factorial of a Number */

// Recursive

int fact(int n)
{
	if (n == 0)
		return 1;

	return n * fact(n - 1);
}

// Iterative

int fact(int n)
{
	int res = 1;

	for (int i = 2; i <= n; i++)
	{
		res = res * i;
	}

	return res;
}

/* Trailing Zeros in Factorial */

int countTrailingZeros(int n)
{
	int res = 0;

	for (int i = 5; i <= n; i = i * 5)
	{
		res = res + (n / i);
	}

	return res;
}

/* GCD and HCF of two Numbers */

// Euclidean Algorithm Code
int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

// Optimized Euclidean Algorithm Code

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

/* LCM of Two Numbers */

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}



/* Check for Prime */

// Efficient
bool isPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

// More Efficient
bool isPrime(int n)
{
	if (n == 1)
		return false;

	if (n == 2 || n == 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}

	return true;
}


/* Prime Factors */

// Efficient

void printPrimeFactors(int n)
{
	if (n <= 1)
		return;

	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			cout << i << " ";

			n = n / i;
		}
	}

	if (n > 1)
		cout << n << " ";

	cout << endl;
}


// More Efficient

void printPrimeFactors(int n)
{
	if (n <= 1)
		return;

	while (n % 2 == 0)
	{
		cout << 2 << " ";

		n = n / 2;
	}

	while (n % 3 == 0)
	{
		cout << 3 << " ";

		n = n / 3;
	}

	for (int i = 5; i * i <= n; i = i + 6)
	{
		while (n % i == 0)
		{
			cout << i << " ";

			n = n / i;
		}

		while (n % (i + 2) == 0)
		{
			cout << (i + 2) << " ";

			n = n / (i + 2);
		}
	}

	if (n > 3)
		cout << n << " ";

	cout << endl;
}

/* All Divisors of a Number */
// Efficient Code with Sorted Order
void printDivisors(int n)
{
	int i = 1;
	for (i = 1; i * i < n; i++)
	{
		if (n % i == 0)
		{
			cout << i << " ";
		}
	}

	for (; i >= 1; i--)
	{
		if (n % i == 0)
		{
			cout << (n / i) << " ";
		}
	}
}

// Efficient Code
void printDivisors(int n)
{
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << i << " ";


			if (i != (n / i))
				cout << (n / i) << " ";
		}
	}
}

/* Sieve of Eratosthenes */

void sieve(int n)
{
	if (n <= 1)
		return;

	bool isPrime[n + 1];

	fill(isPrime, isPrime + n + 1, true);

	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = 2 * i; j <= n; j = j + i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i])
			cout << i << " ";
	}
}

/* Computing Power */

int power(int x, int n)
{
	if (n == 0)
		return 1;

	int temp = power(x, n / 2);

	temp = temp * temp;

	if (n % 2 == 0)
		return temp;
	else
		return temp * x;
}



/**************** Recursion *************/

void fun1(int n)
{
	if (n == 0)
		return;

	cout << "GFG" << endl;

	fun1(n - 1);
}

static void fun1()
{
	cout << "fun1" << endl;
}

static void fun2()
{
	cout << "Before fun1" << endl;

	fun1();

	cout << "After fun1" << endl;
}


/* Rough Recursion */
void fun(int n)
{
	if (n == 0)
		return;

	fun(n - 1);

	cout << n << endl;

	fun(n - 1);
}

void fun(int n)
{
	if (n == 0)
		return;

	cout << n << endl;

	fun(n - 1);

	cout << n << endl;
}

// Example 2(Binary Representation)

void fun(int n)
{
	if (n == 0)
		return;

	fun(n / 2);

	cout << (n % 2) << endl;
}

// Example 1(logN with base 2)

int fun(int n)
{
	if (n == 1)
		return 0;
	else
		return 1 + fun(n / 2);
}


/* Print N to 1 Using Recursion */
void printToN(int n)
{
	if (n == 0)
		return;

	printToN(n - 1);

	cout << n << " ";

}

/* Tail REcursion */

// example 1

int fact(int n, int k)
{
	if (n == 0 || n == 1)
		return k;

	return fact(n - 1, k * n);

}

// example 2

void fun(int n, int k)
{
	if (n == 0)
		return;

	cout << k << " ";

	fun(n - 1, k + 1);

}

// example 3

void fun(int n)
{
	if (n == 0)
		return;

	cout << n << " ";

	fun(n - 1);

}

/* Natural Number Sum using Recursion */

int getSum(int n)
{
	if (n == 0)
		return 0;

	return n + getSum(n - 1);

}

/* Palidrome Check using Recursion */
bool isPalindrome(string str, int start, int end)
{
	if (start >= end)
		return true;

	return ((str[start] == str[end]) &&
	        isPalindrome(str, start + 1, end - 1));
}

/* Sum of Digits Using Recursion */

int fun(int n)
{
	if (n < 10)
		return n;

	return fun(n / 10) + n % 10;
}

/* Rope Cutting Problem */

int maxCuts(int n, int a, int b, int c)
{
	if (n == 0)
		return 0;
	if (n <= -1)
		return -1;

	int res = max(maxCuts(n - a, a, b, c),
	              max(maxCuts(n - b, a, b, c),
	                  maxCuts(n - c, a, b, c)));

	if (res == -1)
		return -1;

	return res + 1;
}

/* Generate Subsets */
void printSub(string str, string curr, int index)
{
	if (index == str.length())
	{
		cout << curr << " ";
		return;
	}

	printSub(str, curr, index + 1);
	printSub(str, curr + str[index], index + 1);
}

/* Tower Of Hanoi */
void ToH(int n, char A, char B, char C)
{
	if (n == 1)
	{
		cout << "Move 1 from " <<  A << " to " << C << endl;
		return;
	}
	ToH(n - 1, A, C, B);
	cout << "Move " << n << " from " <<  A << " to " << C << endl;
	ToH(n - 1, B, A, C);
}

/* Josephus Problem */

int jos(int n, int k)
{
	if (n == 1)
		return 0;
	else
		return (jos(n - 1, k) + k) % n;
}

int myJos(int n, int k)
{
	return jos(n, k) + 1;
}

/* Subset Sum Problem */
int countSubsets(int arr[], int n, int sum)
{
	if (n == 0)
		return sum == 0 ? 1 : 0;

	return countSubsets(arr, n - 1, sum) + countSubsets(arr, n - 1, sum - arr[n - 1]);
}

/* Multidimensional Array in Cpp */
// Vectors of Vector
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


int main()
{
	int m = 3, n = 2;

	vector<vector<int>> arr;

	for (int i = 0; i < m; i++)
	{
		vector<int> v;

		for (int j = 0; j < n; j++)
		{
			v.push_back(10);
		}

		arr.push_back(v);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
	}


	return 0;
}

// -----------------------------------
// Array of Vectors
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


int main()
{
	int m = 3, n = 2;

	vector<int> arr[m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i].push_back(10);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
	}


	return 0;
}
// -----------------------------------
// Array of Pointer

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


int main()
{
	int m = 3, n = 2;

	int *arr[m];

	for (int i = 0; i < m; i++)
		arr[i] = new int[n];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			arr[i][j] = 10;

			cout << arr[i][j] << " ";
		}
	}


	return 0;
}

// -----------------------------
// Double Pointer
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


int main()
{
	int m = 3, n = 2;
	int **arr;

	arr = new int* [m];

	for (int i = 0; i < m; i++)
		arr[i] = new int[n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 10;

			cout << arr[i][j] << " ";
		}
	}


	return 0;
}
// ---------------------------------
// Variable Sized Arrays
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;


int main()
{
	int m = 3, n = 2;
	int arr[m][n];


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = i + j;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
	}


	return 0;
}

// --------------------------------
// Fixed Size Arrays

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
using namespace std;


int main()
{
	int arr[3][2] = {

		{10, 20},
		{30, 40},
		{50, 60}

	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr[i][j] << " ";
		}
	}


	return 0;
}

// -------------------------------

/* Passing Two D array as Argument in CPP */


#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

void print(vector<vector<int>> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int	j = 0; j < arr[i].size(); j++)
			cout << arr[i][j] << " ";
	}
}

int main()
{
	int m = 3, n = 2;

	vector<vector<int>> arr;

	for (int i = 0; i < m; i++)
	{
		vector<int> v;

		for (int j = 0; j < n; j++)
		{
			v.push_back(i);
		}

		arr.push_back(v);
	}

	print(arr);

	return 0;
}



//-------------------------------

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

void print(vector<int> arr[], int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int	j = 0; j < arr[i].size(); j++)
			cout << arr[i][j] << " ";
	}
}

int main()
{
	int m = 3, n = 2;

	vector<int> arr[m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i].push_back(i);
		}
	}

	print(arr, m);

	return 0;
}

//------------------------------
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

void print(int **arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int	j = 0; j < n; j++)
			cout << arr[i][j] << " ";
	}
}

int main()
{
	int m = 3, n = 2;

	int *arr[m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = i;

			cout << arr[i][j] << " ";
		}
	}


	return 0;
}
//---------------------------------
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int R = 3;
const int C = 2;

void print(int mat[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int	j = 0; j < C; j++)
			cout << mat[i][j] << " ";
	}
}

int main()
{

	int mat[R][C] = {
		{10, 20},
		{30, 40},
		{50, 60}
	};

	print(mat);

	return 0;
}

//----------------------------------
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

void print(int mat[][2], int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int	j = 0; j < 2; j++)
			cout << mat[i][j] << " ";
	}
}

int main()
{

	int mat[3][2] = {{10, 20},
		{30, 40},
		{50, 60}
	};

	print(mat, 3);

	return 0;
}
//-----------------------------------
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

void print(int mat[3][2])
{
	for (int i = 0; i < 3; i++)
	{
		for (int	j = 0; j < 2; j++)
			cout << mat[i][j] << " ";
	}
}

int main()
{
	int m = 3, n = 2;

	int mat[3][2] = {
		{10, 20},
		{30, 40},
		{50, 60}
	};

	print(mat);

	return 0;
}

//---------------------------------

/* Matrix in Snake Problem */

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int R = 4, C = 4;
void printSnake(int mat[R][C])
{
	for (int i = 0; i < R; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < C; j++)
				cout << mat[i][j] << " ";
		}
		else
		{
			for (int j = C - 1; j >= 0; j--)
				cout << mat[i][j] << " ";
		}

	}
}

int main()
{
	int arr[R][C] = {{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	printSnake(arr);

	return 0;
}

//-------------------------------------

/* Matrix Boundary Traversal */

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int R = 4, C = 4;
void bTraversal(int mat[R][C])
{
	if (R == 1)
	{
		for (int i = 0; i < C; i++)
			cout << mat[0][i] << " ";
	}
	else if (C == 1)
	{
		for (int i = 0; i < R; i++)
			cout << mat[i][0] << " ";
	}
	else
	{
		for (int i = 0; i < C; i++)
			cout << mat[0][i] << " ";
		for (int i = 1; i < R; i++)
			cout << mat[i][C - 1] << " ";
		for (int i = C - 2; i >= 0; i--)
			cout << mat[R - 1][i] << " ";
		for (int i = R - 2; i >= 1; i--)
			cout << mat[i][0] << " ";
	}

}

int main()
{
	int arr[R][C] = {{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	bTraversal(arr);

	return 0;
}

// --------------------------------
/* Transpose of Matrix */

//Efficient

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int n = 4;

void transpose(int mat[n][n])
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			swap(mat[i][j], mat[j][i]);
}

int main()
{
	int arr[n][n] = {{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	transpose(arr);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}


// Naive
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int n = 4;
void transpose(int mat[n][n])
{
	int temp[n][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = mat[j][i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = temp[i][j];

}

int main()
{
	int arr[n][n] = {{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	transpose(arr);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}

//-----------------------------------
/* Rotate Matrix AntiClock-Wise by 90 */

// Efficient
const int n = 4;

void transpose(int mat[n][n])
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			swap(mat[i][j], mat[j][i]);

	for (int i = 0; i < n; i++)
	{
		int low = 0, high = n - 1;

		while (low < high)
		{
			swap(mat[low][i], mat[high][i]);

			low++;
			high--;
		}
	}
}


// Naive
const int n = 4;
void transpose(int mat[n][n])
{
	int temp[n][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[n - j - 1][i] = mat[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = temp[i][j];

}

int main()
{
	int arr[n][n] = {{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	transpose(arr);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}
//----------------------------------

/* Spiral Traversal of Matrix */
const int R = 4, C = 4;

void printSpiral(int mat[4][4], int R, int C)
{
	int top = 0, left = 0, bottom = R - 1, right = C - 1;

	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++)
			cout << mat[top][i] << " ";

		top++;

		for (int i = top; i <= bottom; i++)
			cout << mat[i][right] << " " ;

		right--;

		if (top <= bottom) {
			for (int i = right; i >= left; i--)
				cout << mat[bottom][i] << " ";

			bottom--;
		}

		if (left <= right) {
			for (int i = bottom; i >= top; i--)
				cout << mat[i][left] << " ";

			left++;
		}
	}
}

//---------------------------------
/* Search in Row-wise and Column-wise sorted matrix */

// Efficient

const int R = 4, C = 4;

void search(int mat[R][C], int x)
{
	int i  = 0, j = C - 1;

	while (i < R && j >= 0)
	{
		if (mat[i][j] == x)
		{
			cout << "Found at (" << i << ", " << j << ")";

			return;
		}
		else if (mat[i][j] > x)
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	cout << "Not Found";
}


int main()
{
	int arr[][C] = {{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 35, 45},
		{32, 33, 39, 50}
	};

	int x = 29;

	search(arr, x);

	return 0;
}


// Naive


const int R = 4, C = 4;

void search(int mat[R][C], int x)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (mat[i][j] == x)
			{
				cout << "Found at (" << i << ", " << j << ")";

				return;
			}
		}
	}

	cout << "Not Found";
}

int main()
{
	int arr[][C] = {{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 35, 45},
		{32, 33, 39, 50}
	};

	int x = 29;

	search(arr, x);

	return 0;
}

/***** Median of Row wise Sorted Matrix C++ ******/

const int MAX = 100;

int matMed(int mat[][MAX], int r , int c)
{
	int min = mat[0][0], max = mat[0][c - 1];
	for (int i = 1; i < r; i++)
	{
		if (mat[i][0] < min)
			min = mat[i][0];

		if (mat[i][c - 1] > max)
			max = mat[i][c - 1];
	}

	int medPos = (r * c + 1) / 2;
	while (min < max)
	{
		int mid = (min + max) / 2;
		int midPos = 0;

		for (int i = 0; i < r; ++i)
			midPos += upper_bound(mat[i], mat[i] + c, mid) - mat[i];
		if (midPos < medPos)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}

int main()
{
	int r = 3, c = 5;
	int m[][MAX] = { {5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19} };
	cout << "Median is " << matMed(m, r, c) << endl;
	return 0;
}








































