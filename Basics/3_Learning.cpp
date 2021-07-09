/******************* Arrays All Operations *****************************************/
/* Intersection of Two Array */

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	int i = 0, j = 0;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int> temp;
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] > nums2[j])
			j++;
		else if (nums2[j] > nums1[i])
			i++;
		else {
			temp.push_back(nums1[i]);
			i++;
			j++;
		}
	}
	return temp;
}


vector<int> intersect(vector<int>& a, vector<int>& b) {
	unordered_map<int, int> ctr;
	for (int i : a)
		ctr[i]++;
	vector<int> out;
	for (int i : b)
		if (ctr[i]-- > 0)
			out.push_back(i);
	return out;
}

vector<int> intersect(vector<int>& a, vector<int>& b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
	return a;
}

/* Insertion In Array*/

int insert(int arr[], int n, int x, int cap, int pos)
{
	if (n == cap)
		return n;

	int idx = pos - 1;

	for (int i = n - 1; i >= idx; i--)
	{
		arr[i + 1] = arr[i];
	}

	arr[idx] = x;

	return n + 1;
}

/* Search Unsorted Array */

int search(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
			return i;
	}

	// for(auto item:arr)
	// if(item == x)
	// return item;

	return -1;
}

/* Deletion In Array */

int deleteEle(int arr[], int n, int x)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		if (arr[i] == x)
			break;
	}

	if (i == n)
		return n;

	for (int j = i; j < n - 1; j++)
	{
		arr[j] = arr[j + 1];
	}

	return n - 1;
}

/* Check if an Array is Sorted */

// Efficient

bool isSorted(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
			return false;
	}

	return true;
}

// Naive

bool isSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
				return false;
		}
	}

	return true;
}

/* Reverse an Array */

void reverse(int arr[], int n)
{
	int low = 0, high = n - 1;

	while (low < high)
	{
		int temp = arr[low];

		arr[low] = arr[high];

		arr[high] = temp;

		low++;
		high--;
	}
}


/* Remove Duplicates from a sorted Array **/

// Naive
int remDups(int arr[], int n)
{
	int temp[n];

	temp[0] = arr[0];

	int res = 1;

	for (int i = 1; i < n; i++)
	{
		if (temp[res - 1] != arr[i])
		{
			temp[res] = arr[i];
			res++;
		}
	}

	for (int i = 0; i < res; i++)
	{
		arr[i] = temp[i];
	}

	return res;
}

// Efficient


int remDups(int arr[], int n)
{
	int res = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[res - 1] != arr[i])
		{
			arr[res] = arr[i];
			res++;
		}
	}

	return res;
}

/* Left Rotate Array by One */

void lRotateOne(int arr[], int n)
{
	int temp = arr[0];

	for (int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}

	arr[n - 1] = temp;
}

/* Left Rotate an Array by D places */

// Reversal Method

void reverse(int arr[], int low, int high)
{
	while (low < high)
	{
		swap(arr[high], arr[low]);

		low++;
		high--;
	}
}


void leftRotate(int arr[], int d, int n)
{
	// 1 2 3 4 5 6 7 8  i/p
	// 4 5 6 7 8 1 2 3  o/p
	reverse(arr, 0, d - 1);
	// 3 2 1 4 5 6 7 8  r1
	reverse(arr, d, n - 1);
	// 3 2 1 8 7 6 5 4  r2
	reverse(arr, 0, n - 1);
	// 4 5 6 7 8 1 2 3  fr
}


void rotate(vector<int>& nums, int k) {
	// -Right Rotation
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k % nums.size());
	reverse(nums.begin() + k % nums.size(), nums.end());

	// -Left Rotation
	// reverse(nums.begin(),nums.begin()+k-1);
	// reverse(nums.begin()+k,nums.end());
	// reverse(nums.begin(),nums.end());
}

// Efficient Solution

void leftRotate(int arr[], int d, int n)
{
	int temp[d];

	for (int i = 0; i  < d; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = d; i  < n; i++)
	{
		arr[i - d] = arr[i];
	}

	for (int i = 0; i  < d; i++)
	{
		arr[n - d + i] = temp[i];
	}
}

// Naive Solution

void lRotateOne(int arr[], int n)
{
	int temp = arr[0];

	for (int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}

	arr[n - 1] = temp;
}

void leftRotate(int arr[], int d, int n)
{
	for (int i = 0; i < d; i++)
	{
		lRotateOne(arr, n);
	}
}

/* Leaders in an Array Problems */

// Efficient
void leaders(int arr[], int n)
{
	int curr_ldr = arr[n - 1];

	cout << curr_ldr << " ";

	for (int i = n - 2; i >= 0; i--)
	{
		if (curr_ldr < arr[i])
		{
			curr_ldr = arr[i];

			cout << curr_ldr << " ";
		}
	}
}

// Naive

void leaders(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bool flag = false;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] <= arr[j])
			{
				flag = true;
				break;
			}
		}

		if (flag == false)
		{
			cout << arr[i] << " ";
		}
	}
}

/* Maximum Difference Problem with Order*/


// Efficient

int maxDiff(int arr[], int n)
{
	int res = arr[1] - arr[0], minVal = arr[0];

	for (int i = 1; i < n; i++)
	{

		res = max(res, arr[i] - minVal);
		minVal = min(minVal, arr[i]);
	}
	return res;
}

int maxDifff(vector<int>v) {
	int temp1 = INT_MAX;
	int temp2 = INT_MIN;
	int res1 = v[0]; int res2 = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < temp1) {
			temp1 = v[i];
		}
		if (v[i] > temp2) {
			temp2 = v[i];
		}
	}

	return {abs(temp2 - temp1)};

}

// Naive

int maxDiff(int arr[], int n)
{
	int res = arr[1] - arr[0];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			res = max(res, arr[j] - arr[i]);
		}
	}

	return res;
}

// 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2
// 1 ->  8
// 2 ->  8
// Frequencies in a Sorted Array

void printFreq(int arr[], int n)
{
	int freq = 1, i = 1;

	while (i < n)
	{
		while (i < n && arr[i] == arr[i - 1])
		{
			freq++;
			i++;
		}

		cout << arr[i - 1] << " " << freq << endl;

		i++;
		freq = 1;
	}
}

// Stock Buy and Sell Problem (Part 1)

int maxProfit(int price[], int start, int end)
{
	if (end <= start)
		return 0;

	int profit = 0;

	for (int i = start; i < end; i++)
	{
		for (int j = i + 1; j <= end; j++)
		{
			if (price[j] > price[i])
			{
				int curr_profit = price[j] - price[i]
				                  + maxProfit(price, start, i - 1)
				                  + maxProfit(price, j + 1, end);

				profit = max(profit, curr_profit);
			}
		}
	}

	return profit;
}

/* Stock Buy and Sell Problem (Part 2)*/

int maxProfit(int price[], int n)
{
	int profit = 0;

	for (int i = 1; i < n; i++)
	{
		if (price[i] > price[i - 1])
			profit += price[i] - price[i - 1];
	}

	return profit;

}

/* Trapping Rain Water **/

// Efficient

int getWater(int arr[], int n)
{
	int res = 0;

	for (int i = 1; i < n - 1; i++)
	{
		int res = 0;

		int lMax[n];
		int rMax[n];

		lMax[0] = arr[0];
		for (int i = 1; i < n; i++)
			lMax[i] = max(arr[i], lMax[i - 1]);


		rMax[n - 1] = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
			rMax[i] = max(arr[i], rMax[i + 1]);

		for (int i = 1; i < n - 1; i++)
			res = res + (min(lMax[i], rMax[i]) - arr[i]);

		return res;
	}

	return res;
}

// Naive

int getWater(int arr[], int n)
{
	int res = 0;

	for (int i = 1; i < n - 1; i++)
	{
		int lMax = arr[i];

		for (int j = 0; j < i; j++)
			lMax = max(lMax, arr[j]);

		int rMax = arr[i];

		for (int j = i + 1; j < n; j++)
			rMax = max(rMax, arr[j]);

		res = res + (min(lMax, rMax) - arr[i]);
	}

	return res;
}

/* Maximum consecutive 1s */
// Efficient
int maxConsecutiveOnes(int arr[], int n)
{
	int res = 0, curr = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			curr = 0;
		else
		{
			curr++;

			res = max(res, curr);
		}
	}

	return res;
}

// Naive

int maxConsecutiveOnes(int arr[], int n)
{
	int res = 0;

	for (int i = 0; i < n; i++)
	{
		int curr = 0;

		for (int j = i; j < n; j++)
		{
			if (arr[j] == 1) curr++;
			else break;
		}

		res = max(res, curr);
	}

	return res;
}

/** Maximum subarray Sum **/

// Efficient
int maxSum(int arr[], int n)
{
	int res = arr[0];
	int maxEnding = arr[0];

	for (int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);
		res = max(maxEnding, res);
	}

	return res;
}

// Naive
int maxSum(int arr[], int n)
{
	int res = arr[0];

	for (int i = 0; i < n; i++)
	{
		int curr = 0;

		for (int j = i; j < n; j++)
		{
			curr = curr + arr[j];

			res = max(res, curr);
		}
	}

	return res;
}

/** Longest Even Odd Subarray */

// Efficient

int maxEvenOdd(int arr[], int n)
{
	int res = 1;
	int curr = 1;

	for (int i = 1; i < n; i++)
	{
		if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0)
		        || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
		{
			curr++;

			res = max(res, curr);
		}
		else
			curr = 1;
	}

	return res;
}

// Naive
int maxEvenOdd(int arr[], int n)
{
	int res = 1;

	for (int i = 0; i < n; i++)
	{
		int curr = 1;

		for (int j = i + 1; j < n; j++)
		{
			if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0)
			        || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
				curr++;
			else
				break;
		}

		res = max(res, curr);
	}

	return res;
}

/** Maximum Circular Sum Subarray **/

// Efficient Solution


int normalMaxSum(int arr[], int n)
{
	int res = arr[0];

	int maxEnding = arr[0];

	for (int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}

	return res;
}

int overallMaxSum(int arr[], int n)
{
	int max_normal = normalMaxSum(arr, n);

	if (max_normal < 0)
		return max_normal;

	int arr_sum = 0;

	for (int i = 0; i < n; i++)
	{
		arr_sum += arr[i];

		arr[i] = -arr[i];
	}

	int max_circular = arr_sum + normalMaxSum(arr, n);

	return max(max_circular, max_normal);
}

// Naive Solution


int maxCircularSum(int arr[], int n)
{
	int res = arr[0];

	for (int i = 0; i < n; i++)
	{
		int curr_max = arr[i];
		int curr_sum = arr[i];

		for (int j = 1; j < n; j++)
		{
			int index = (i + j) % n;

			curr_sum += arr[index];

			curr_max = max(curr_max, curr_sum);
		}

		res = max(res, curr_max);
	}
	return res;
}

/** Majority Element **/

// Efficient Soltution

int findMajority(int arr[], int n)
{
	int res = 0, count = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[res] == arr[i])
			count++;
		else
			count --;

		if (count == 0)
		{
			res = i; count = 1;
		}
	}

	count = 0;

	for (int i = 0; i < n; i++)
		if (arr[res] == arr[i])
			count++;

	if (count <= n / 2)
		res = -1;

	return res;
}

// Naive Solution


int findMajority(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int count = 1;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}

		if (count > n / 2)
			return i;
	}

	return -1;
}

/** Two Sum **/

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> imap;

	for (int i = 0;; ++i) {
		auto it = imap.find(target - nums[i]);

		if (it != imap.end())
			return vector<int> {i, it->second};

		imap[nums[i]] = i;
	}

}

/** Moving zeroes to the End **/

void moveZeroes(vector<int>& nums) {
	int n = nums.size();
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] != 0)
			nums[count++] = nums[i];
	}

	while (count < n)
		nums[count++] = 0;
}

/**  Minimum Consecutive Flips **/

void printGroups(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			if (arr[i] != arr[0])
				cout << "From " << i << " to ";
			else
				cout << i - 1 << endl;
		}
	}

	if (arr[n - 1] != arr[0])
		cout << n - 1 << endl;
}

/** Sliding Window Technique  **/

// Maximum Sum of K Consecutive elements Efficient

int maxSum(int arr[], int n, int k)
{
	int curr_sum = 0;

	for (int i = 0; i < k; i++)
		curr_sum += arr[i];

	int max_sum = curr_sum;

	for (int i = k; i < n; i++)
	{
		curr_sum += (arr[i] - arr[i - k]);

		max_sum = max(max_sum, curr_sum);
	}

	return max_sum;
}

// Maximum Sum of K Consecutive elements Naive

int maxSum(int arr[], int n, int k)
{
	int max_sum = INT_MIN;
	for (int i = 0; i + k - 1 < n; i++)
	{
		int sum = 0;

		for (int j = 0; j < k; j++)
		{
			sum += arr[i + j];
		}

		max_sum = max(max_sum, sum);
	}

	return max_sum;

}

// Find Subarray with given Sum
/* Returns true if the there is a subarray of arr[] with a sum equal to 'sum'
otherwise returns false. Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
	/* Initialize curr_sum as value of first element
	and starting point as 0 */
	int curr_sum = arr[0], start = 0, i;

	/* Add elements one by one to curr_sum and if the curr_sum exceeds the
	sum, then remove starting element */
	for (i = 1; i <= n; i++)
	{
		// If curr_sum exceeds the sum, then remove the starting elements
		while (curr_sum > sum && start < i - 1)
		{
			curr_sum = curr_sum - arr[start];
			start++;
		}

		// If curr_sum becomes equal to sum, then return true
		if (curr_sum == sum)
		{
			printf ("Sum found between indexes %d and %d", start, i - 1);
			return 1;
		}

		// Add this element to curr_sum
		if (i < n)
			curr_sum = curr_sum + arr[i];
	}

	// If we reach here, then no subarray
	printf("No subarray found");
	return 0;
}

// N-bonacci Series
// Function to print bonacci series
void bonacciseries(long n, int m)
{

	// Assuming m > n.
	int a[m] = { 0 };
	a[n - 1] = 1;
	a[n] = 1;

	// Uses sliding window
	for (int i = n + 1; i < m; i++)
		a[i] = 2 * a[i - 1] - a[i - n - 1];

	// Printing result
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
}


/**** Prefix Sum Technique (Part 1) ****/

// Equilibrium Point (Efficient Method)

bool checkEquilibrium(int arr[], int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	int l_sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (l_sum == sum - arr[i])
			return true;

		l_sum += arr[i];

		sum -= arr[i];
	}

	return false;
}

// Equilibrium Point (Naive Method)

bool checkEquilibrium(int arr[], int n)
{
	for (int i  = 0; i < n; i++)
	{
		int l_sum = 0, r_sum = 0;

		for (int j = 0; j < i; j++)
			l_sum += arr[j];

		for (int j = i + 1; j < n; j++)
			r_sum += arr[j];

		if (l_sum == r_sum)
			return true;
	}

	return false;
}

// Prefix Sum Array

int prefix_sum[10000];

void preSum(int arr[], int n)
{


	prefix_sum[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}


}

int getSum(int prefix_sum[], int l, int r)
{
	if (l != 0)
		return prefix_sum[r] - prefix_sum[l - 1];
	else
		return prefix_sum[r];
}


/**** Prefix Sum Technique (Part 2)*****/

int maxOcc(int L[], int R[], int n)
{
	int arr[1000];

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++)
	{
		arr[L[i]]++;

		arr[R[i] + 1]--;
	}

	int maxm = arr[0], res = 0;

	for (int i = 1; i < 1000; i++)
	{
		arr[i] += arr[i - 1];

		if (maxm < arr[i])
		{
			maxm = arr[i];

			res = i;
		}
	}

	return res;
}


















































































































































































































































































































































































