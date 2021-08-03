// Logic Of Array with Dp and Recursion 

// Start with Recursion

// > Factorial Sum


#include<bits/stdc++.h>
#define long long ll
using namespace std;

int fact(int n){
	if(n==0 || n==1)
		return n;
	else
		return n*fact(n-1);
}

int factIterative(int n){
	// vector<int> v(5);
	// 1 2 3 4 5
	int res(1);
	for(int i=2;i<=n;i++){
		res *=i;
	}
	return res;
}

int fiboncci(int n){
	if(n<=1)
		return n;
	return fiboncci(n-1)+fiboncci(n-2);
}

int fibNew(int n){
 	if(n==0||n==1) return n;
 	int dp1(0),dp2(1);
 	for(int i=2;i<=n;i++){
 		int dp3 = dp2%10;
 		dp2 = (dp1+dp2)%10;
 		dp1 = dp3%10;
 	}
 	return dp2;
}

void printNtoOne(int n){
	if(n==0) return;
	cout<< n<<" ";
	printNtoOne(n-1);
}

int NaturalNoSum(int n){
	if(n==1) return 1;
	int res = n + NaturalNoSum(n-1);
	// cout<<res<<endl;
	return res;
}

/* Check for Palindrome */
bool isPalindrome(string s,int start,int end){
	if(start>=end) return true;
	return (s[start]==s[end])&&isPalindrome(s,start+1,end-1);
}

/* Rope Cutting Problem*/
// We are Given a Rope of Length N our task is to cut this rope in maximum number of pieces such that every piece has length either as {a,b,c} 
// @return ->int

int maxPieces(int n,int a,int b,int c){
	if(n==0) return 0;
	if(n < 0) return -1;

	int res = max(
				max(
					maxPieces(n-a,a,b,c),
					maxPieces(n-b,a,b,c)
					),
				maxPieces(n-c,a,b,c)
			);

	if(res== -1) return -1;
	return res+1;
}
 
/* Generate Subsets of a Strings*/

void generateSubsets(string s,string curr,int i){
		if(i == s.length()){
			cout<<curr<<", ";
			return;
		}

		generateSubsets(s,curr,i+1);
		generateSubsets(s,curr+s[i],i+1);

}

void ToH(int n, char A, char B, char C) 
{ 
    if (n == 1) 
    { 
        cout<<"Move 1 from " <<  A << " to " << C << endl; 
        return; 
    } 
    ToH(n-1, A, C, B); 
    cout<<"Move " << n << " from " <<  A << " to " << C << endl; 
    ToH(n-1, B, A, C); 
}

/*Joseph Problem*/
// People are standing in circular path the starting from 0 and every i kill i+k and give gun to i+k+1 and we need to find last man survived 

int jos(int n, int k)
{
	if(n == 1)
		return 0;
	else
		return (jos(n - 1, k) + k) % n;
}

int myJos(int n, int k)
{
	return jos(n, k) + 1;
}


/* Count Subset Problem */

int countSubsets(int arr[], int n, int sum)
{
	if(n==0)
		return sum==0? 1 : 0;

	return countSubsets(arr, n-1, sum) + countSubsets(arr, n-1, sum - arr[n-1]);
}

void printPermutationString(string s,int i=0){
	if(i==s.length()-1){
		cout<<s<<" ";
		return;
	}
	for(int j=i;j<s.length();j++){
		swap(s[i],s[j]);
		printPermutationString(s,i+1);
		swap(s[i],s[j]);
	}
}

int main(){
	int n = 5;
	int arr[] = {1,2,3,4,5,6,1,1,1,1};
	cout<< fibNew(51);
	// cout<<fact(n)<<endl;
	// cout<<factIterative(n)<<endl;
	// cout<<fiboncci(6)<<endl;
	// printNtoOne(7);
	// cout<<NaturalNoSum(7);
	// cout<< maxPieces(5,1,2,5);
	// generateSubsets("ABCD"," ",0);
	// ToH(2,'A','B','C');
	// cout<< myJos(7,2);
	// cout<<countSubsets(arr,5,5);
	// printPermutationString("abcd");
	return 0;
}