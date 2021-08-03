#include<stdio.h>

void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

void swap(int &a,int &b){
	int temp;
	temp = a;
	a= b;
	b=temp;
}

void selectionSort(int arr[],int n){
	int i,j,minEle;
	for(i=0;i<n;i++){
		minEle=i;
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j])
				minEle = j;
		}
		swap(arr[i],arr[minEle]);
	}
	printArray(arr,n);
}

int main(){
	int j=90,i;
	float k = 4.56;

	int a,b,c;
	// scanf("%d %d %d",&a,&b,&c);
	// printf("A is : %d\n",a);
	// printf("B is : %d\n",b);
	// printf("C is : %d\n",c);
	// printf("%d %d %f\n",j,i,k);
	// printf("%s\n", "Hello World");
	// printf("%s\n", "Hello World");

	// for(i=0;i<j;j++){
	// 	printf("%d ",j);
	// }
	int arr[] = {1,2,8,7,6,5,4,3};
	selectionSort(arr,7);
	return 0;
}