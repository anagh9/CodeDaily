#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)

const int R=3,C=13;
void printSpiral(int mat[R][C])
{
	int top = 0, left = 0, bottom = R - 1, right = C - 1;

	while(top <= bottom && left <= right)
	{
		for(int i = left; i <= right; i++)
			cout << mat[top][i] << " ";

		top++;

		for(int i = top; i <= bottom; i++)
			cout << mat[i][right] << " " ;
		
		right--;

		if(top <= bottom){
		for(int i = right; i >= left; i--)
			cout << mat[bottom][i] << " ";

		bottom--;
		}

		if(left <= right){
		for(int i = bottom; i >= top; i--)
			cout << mat[i][left] << " ";

		left++;
		}			
	}
}

void printSpiralx(int mat[R][C]){
	int top(0),left(0),bottom(R-1),right(C-1);

	while(top<=bottom && left<=right){
		for(int i=left;i<=right;i++)
			cout<<mat[top][i]<<" ";
		top++;

		for(int i=top;i<=bottom;i++)
			cout<<mat[i][right]<<" ";
		right--;

		if(top<=bottom){
			for(int i=right;i>=left;i--)
				cout<<mat[bottom][i]<<" ";
			bottom--;
		}

		if(left<=right){
			for(int i=bottom;i>=top;i--){
				cout<<mat[i][left]<<" ";
			}
			left++;

		}
	}
}



void roughPart1(int mat[R][C]){
	int t(0),l(0),r(C-1),b(R-1);
	while(t<=b&&l<=r){
		for(int i=l;i<=r;i++){
			cout<<mat[t][i]<<" ";
		}
		t++;

		for(int i=t;i<=b;i++)
			cout<<mat[i][r]<<" ";
		r--;

		if(t<=b){
			for(int i=r;i>=l;i--)
				cout<<mat[b][i]<<" ";
		b--;
		}

		if(l<=r){
			for(int i=b;i>=t;i--)
				cout<<mat[i][l]<<" ";
		l++;
		}
	}
}

void roughPart2(int mat[R][C]){
	int t(0),l(0),r(C-1),b(R-1);
	while(t<=b&&l<=r){
		for(int i=l;i<=r;i++)
			cout<<mat[t][i]<<" ";
		t++;

		for(int i=t;i<=b;i++)
			cout<<mat[i][r]<<" ";
		r--;

		if(t<=b){
			for(int i=r;i>=l;i--)
				cout<<mat[b][i]<<" ";
			b--;
		}

		if(l<=r){
			for(int i=b;i>=t;i--)
				cout<<mat[i][l];
			l++;
		}
	}
}

void roughPart3(int m[R][C]){
	int t=0,l=0,r=C-1,b=R-1;
	while(t<=b&&l<=r){
		for(int i=l;i<=r;i++)
			cout<<m[t][i]<<" ";
		t++;

		for(int i=t;i<=b;i++)
			cout<<m[i][r]<<" ";
		r--;

		if(t<=b){
			for(int i=r;i>=l;i--)
				cout<<m[b][i]<<" ";
			b--;
		}

		if(l<=r){
			for(int i=b;i>=t;i--){
				cout<<m[i][l]<<" ";
			}
			l++;
		}
	}
}

void roughPart4(int m[R][C]){
	int t=0,l=0,r=C-1,b=R-1;
	while(t<=b&&l<=r){
		for(int i=l;i<=r;i++)
			cout<<m[t][i]<<" ";
		t++;
		for(int i=t;i<=b;i++)
			cout<<m[i][r]<<" ";
		r--;

		if(t<=b){
			for(int i=r;i>=l;i--)
				cout<<m[b][i]<<" ";
			b--;
		}

		if(l<=r){
			for(int i=b;i>=t;i--)
				cout<<m[i][l]<<" ";
			l++;
		}

	}
}

void rotate(int mat[R][C]){
	 // Transpose the matrix
    for (int i = 0; i < R; i++)
    {
    	deb(i); 
        for (int j = 0; j < i; j++) {
            deb(j);
            swap(mat[i][j], mat[j][i]);
        }
    }

	cout<<"\n \n ";
	 
    // swap columns
    for (int i = 0; i < C; i++)
    {
    	deb(i);
        for (int j = 0; j < C/2; j++) {
            deb(j);
            swap(mat[i][j], mat[i][C - j - 1]);
        }
    }
}

int main(){
	int mat[R][C] = {
		  {133, 241, 22, 258, 187, 150, 79, 207, 196, 401, 366, 335, 198},
		  {401, 55, 260, 363, 14, 318, 178, 296, 333, 296, 45, 37, 10},
		  {112, 374, 79, 12, 97, 39, 310, 223, 139, 91, 171, 95, 126},
	};
	printSpiral(mat);
	// rotate(mat);
	// roughPart4(mat);
	return 0;
}