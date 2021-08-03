#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)

class Humans{
public:
	void sayMyName(string s);
};

class Men : public Humans{
public:
	void sayMyGender();
};

void Humans::sayMyName(string s){
	cout<<s<<endl;
}

void Men::sayMyGender(){
	cout<<"I am Male"<<endl;
}

// TimeComplexity => O(n^2)

void bubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

// TimeComplexity => O(n^2)

void selectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int miin = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[miin])
				miin = j;
		}
		swap(arr[i],arr[miin]);
	}
}

// TimeComplexity of insertionSort
// BestCase => O(n)
// Worst & AvgCase => O(n^2)

void insertionSort(int arr[],int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = arr[i];
		j = i-1;

		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j= j-1;
		}
		arr[j+1] = key;
	}
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortBuilder(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSortBuilder(arr, low, pi - 1);
        quickSortBuilder(arr, pi + 1, high);
    }
}

// BestCase => O(nlogn)
// WorstCase => When Array is already Sorted => O(n^2)

void quickSort(int arr[],int n){
	quickSortBuilder(arr,0,n);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSortBuilder(int arr[],int l,int r){
	if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSortBuilder(arr, l, m);
        mergeSortBuilder(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// TimeComplexity => O(nlogn) for all cases

void mergeSort(int arr[],int n){
	mergeSortBuilder(arr,0,n-1);
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// TimeComplexity => overall time complexity of Heap Sort is O(N*LogN) where N is the number of elements in the list or array.


// Main function for heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main(){
	Humans Me;
	Humans Women;
	Men Shivam;

	// Me.sayMyName("Shivam");
	// Women.sayMyName("Shreya");
	// Women.sayMyGender();
	// Shivam.sayMyGender();
	// Shivam.sayMyName("Shivam");
	std::vector<int> v{1,4,5,6,43};
	// int res =accumulate(v.begin(),v.end(),0);
	// cout<<"Res : "<<res;
	int arr[] = {3,9,8,7,6,5,4,1,2};
	int n= sizeof(arr)/sizeof(int);
	sort(arr, arr+3, greater<int>());
	sort(arr+3, arr+n);
	// mergeSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}