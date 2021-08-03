#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)


// 0-1 KnapSack Problem

int zeroOneKnapSackRecursive(vector<int> weight,vector<int> value,int TotalWeight,int n){
	int maxProfit(0);
// Base Condition
	if(n==0 || TotalWeight == 0)
		return 0;

	if(weight[n-1]<=TotalWeight)
		return max(value[n-1] + zeroOneKnapSackRecursive(weight,value,TotalWeight-weight[n-1],n-1),
			zeroOneKnapSackRecursive(weight,value,TotalWeight,n-1));
	else if(weight[n-1] > TotalWeight)
		return zeroOneKnapSackRecursive(weight,value,TotalWeight,n-1);
}

int state[101][102];
memset( state, -1,sizeof(state) );
int zeroOneKnapSack(vector<int> weight,vector<int> value,int TotalWeight,int n){
	

	if(n==0 || TotalWeight == 0)
		return 0;

	if(state[n][TotalWeight]!=-1){
		return state[n][TotalWeight];
	}

	if(weight[n-1]<=TotalWeight)
		return state[n][TotalWeight] = max(value[n-1] + zeroOneKnapSackRecursive(weight,value,TotalWeight-weight[n-1],n-1),
			zeroOneKnapSackRecursive(weight,value,TotalWeight,n-1));
	else if(weight[n-1] > TotalWeight)
		return state[n][TotalWeight] = zeroOneKnapSackRecursive(weight,value,TotalWeight,n-1);

}



int main(){
	int n;
	vector<int> v{2,5,4,2,7,8};
	vector<int> w{1,2,4,2,3,3};
	int TotalWeight =43;

	cout<< zeroOneKnapSack(v,w,TotalWeight,v.size());

	return 0;
}