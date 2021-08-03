#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)

void rectangle(int r=3,int c=5){
	for(int i=0;i<r;i++){
		for(int i=0;i<c;i++){
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
}

void hollowrectangle(int r=3,int c=5){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==0||j==0||i==r-1||j==c-1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}
}

void rectanglePattern(){
	// rectangle();
	// hollowrectangle();
}

void halfPyramid(int r=6,int c=6){
	for(int i=0;i<r;i++){
		for(int j=0;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
}

void invertedPyramid(int r=6,int c=6){
	for(int i=r;i>0;i--){
		for(int j=i;j>0;j--){
			cout<<"*";
		}
		cout<<endl;
	}
}

void fullPyramid(int r=6){
	int k=0;
	for(int i=0;i<r;i++,k){
		for(int j=0;j<r-i;j++){
			cout<<" ";
		}
		while(k!=2*i-1){
			cout<<"* ";
			++k;
		}
		cout<<endl;
	}
}

void pyramidPattern(){
	// halfPyramid();
	// invertedPyramid();
	fullPyramid();
}


int main(){
	int n;
	vector<int> v;
	pyramidPattern();
	// rectanglePattern();
	return 0;
}