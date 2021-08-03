// #include<bits/stdc++.h>
// #define long long ll
// using namespace std;
// #define deb(x) cout<<#x <<": "<<x<<endl;  
// #define fo(i,a,b) for(int i = a; i <b; i++)

// int maxSum(vector<int> e){
// 	int n=e.size();
// 	int res = e[0];
// 	int minE = e[0];
// 	for(int i=0;i<n;i++){
// 		minE = max(minE+e[i],e[i]);
// 		res = max(res,minE);
// 	}
// 	return res;
// }

// void selectionSort(vector<int> &res){
// 	int n=res.size();
// 	for(int i=0;i<n;i++){
// 		int m = i;
// 		for(int j=i+1;j<n;j++){
// 			if(res[j]<res[i])
// 				m = j;
// 		}
// 		swap(res[i],res[m]);
// 	}
// }

// int naiveMaxSum(vector<int> nums){
// 	int n= nums.size();
// int res(nums[0]);
// 	for(int i=0;i<n;i++){
// 		int curr(0);
// 		for(int j=i;j<n;j++){
// 			curr +=nums[j];
// 			res = max(res,curr);
// 		}
// 	}
// 	return res;
// }

// int factorial(int n){
	
// 	int res(1);
// 	for(int i=1;i<=n;i++){
// 		res *=i;
// 	}
// 	return res;
// }

// int factorialR(int n){
// 	if(n<=1)
// 		return n;
// 	return n*factorialR(n-1);

// }

// int fib(int n){
// 	if(n==0)
// 		return 0;
// 	if(n==1)
// 		return 1;
// 	return fib(n-1)+fib(n-2);
// }

// int main(){
// 	// cout<<"Hello";
// 	int n;
// 	vector<int> v{-1,-4,-9,0,4,6,7};
// 	// selectionSort(v);
// 	// for(auto it:v) cout<<it<<" "; 
// 	// cout<<endl;
// 	// cout<< naiveMaxSum(v);
// 	cout<<fib(5)<<endl;
// 	// cout<<factorialR(12);
// 	return 0;
// }



// #include<bits/stdc++.h>
// #define long long ll
// using namespace std;
// #define deb(x) cout<<#x <<": "<<x<<endl;  
// #define fo(i,a,b) for(int i = a; i <b; i++)

//     bool isSorted(int arr[],int n){
//         int res = arr[0] - arr[n-1];
//         if(res>0){
//             for(int i=0;i<n;i++){
//                 if(arr[i+1]>arr[i])
//                     return false;
//             }
//         }else{
//             for(int i=0;i<n-1;i++){
//                 if(arr[i]>arr[i+1])
//                     return false;
//             }
//             // cout<<"exit";
//         }
//         return true;
//     }

//     void reverseRotate(int *arr,int &num,int res){
//         int temp[num];
//         int p =0;
//         for(int i=res+1;i<num;i++){
//             temp[p] = arr[i];
//             p++;
//         }
        
//         for(int i=0;i<=res;i++){
//             temp[p] = arr[i];
//             p++;
//         }
//         for(int i=0;i<num;i++){
//             arr[i] = temp[i];
//         }
//         // for(int i=0;i<num;i++){
//         // 	cout<<temp[i]<<" ";
//         // }
//     }

//     bool isRotated(int arr[],int n){
//        int maxx  = *max_element(arr,arr+n); //deb(maxx)
//         int minn  = *min_element(arr,arr+n);//deb(minn)
//         int res(0);bool flag = false;
//         for(int i=0;i<n;i++){
//         	// deb(arr[i+1])
//             if(arr[i] == maxx && arr[i+1] == minn || arr[i] == minn &&arr[i+1] == maxx ){
//                 res = i; flag=true; //deb(res);
//                 break;
//             }
//         }
//         if(res ==0 && flag ==false) return false; 
//         reverseRotate(arr,n,res);
//         // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
//         // return false;
//         return isSorted(arr,n);
//     }

//     bool checkRotatedAndSorted(int arr[], int num){
//         //Check 1st Array is rotated or Not
//   	     if(isRotated(arr,num))
//   	     	return true;
//   	     else
//   	     	return false;
        
//         //Check 2nd: If rotated reverse rotate
        
//         //Check 3rd: Check if its sorted or not
//     }


// 	int main()
// 	{
// 		int v[] = {37,13,15,17,23,27};
// 		int n = sizeof(v)/sizeof(int);
// 		checkRotatedAndSorted(v,n) ? cout<<"True":cout<<"False";
// 		return 0;
// 	}


#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)

int repeatedNumber(const vector<int> &A) {
  int slow = A[0];
  int fast = A[A[0]];
  while (slow != fast) {
    slow = A[slow];
    fast = A[A[fast]];
  }

  fast = 0;
  while (slow != fast) {
    slow = A[slow];
    fast = A[fast];
  }
  if(slow==0) return -1;
  return slow;
}

int main(){
	// int n;
	// vector<int> v;
	string s = "Hello Boodskd sdsdsdmsld smdlksdls dskmdlsld sdklsmmdsld sdl sdklmsds dsdmsd sdsmlds dsmds d";
	cout<< sizeof(int)<<" "<<sizeof(char)<<" "<<sizeof(s);
	return 0;
}

