#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)


/* Write a recursive function that takes a number and returns the sum of all the numbers from zero to that number. */
int cumulative(int n){
	if(n==0 || n==1) return n;
	else
		return n + cumulative(n-1);
}


/* Recursive function that takes a number as an input and returns the factorial of that number */
int factorial(int n){
	if(n==0 || n==1) return n;
	return n*factorial(n-1);
}

/* Fibonacci Number */
int fib(int n){
	if(n==0||n==1)
		return n;
	else return fib(n-1) + fib(n-2);
}

/* Recursive function that takes a list of numbers as an input and returns the product of all the numbers in the list */
int productOfArray(vector<int> v,int n){
	if(n==0) return 0;
	if(n==1) return v[0];
	return v[n-1]*productOfArray(v,n-1);
}

/* Write a function that takes a string and returns if the string is a palindrome. */

bool isPalindrome(string s,int n){
	if(n == 0)
		return true;
	if(s[0]!=s[s.length()-1]) return false;
	return isPalindrome(s,n-1);
}

/*Reverse a String */

string reverse(string s,int n){
	if(n==0 || n==1) return s;
	else 
		return s[n-1] + reverse(s,n-1);
}

int main(){
	// int n = 5;
	vector<int> v{3,4,5};
	string s = "Raone";
	int n = sizeof(s)/sizeof(string);
	cout<< reverse(s,n);
	// isPalindrome("HeHeH",5)? cout<<"true":cout<<"False";
	// cout<< productOfArray(v,3);
	// cout<<fib(n);	
	// cout<<factorial(5);
	// cout<<cumulative(n);
	// vector<int> v;
	return 0;
}