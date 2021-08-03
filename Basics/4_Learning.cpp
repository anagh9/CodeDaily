/*****Mapping Hashing********/

// Direct Address Table

struct DAT {
	int table[1000] = {0};

	void insert(int i) {
		table[i] = 1;
	}

	void del(int i) {
		table[i] = 0;
	}

	int search(int i) {
		return table[i];
	}
};


int main()
{
	DAT dat;
	dat.insert(10);
	dat.insert(20);
	dat.insert(119);
	cout << dat.search(10) << endl;
	cout << dat.search(20) << endl;
	dat.del(119);
	cout << dat.search(119) << endl;

	return 0;
}

/***** Implementation of Chaining *****/

struct MyHash
{
	int BUCKET;
	list<int> *table;
	MyHash(int b)
	{
		BUCKET = b;
		table = new list<int>[BUCKET];
	}

	void insert(int k)
	{
		int i = k % BUCKET;
		table[i].push_back(k);
	}

	bool search(int k)
	{
		int i = k % BUCKET;
		for (auto x : table[i])
			if (x == k)
				return true;
		return false;
	}
	void remove(int k)
	{
		int i = k % BUCKET;
		table[i].remove(k);
	}
};

// Driver method to test Map class
int main()
{
	MyHash mh(7);
	mh.insert(10);
	mh.insert(20);
	mh.insert(15);
	mh.insert(7);
	cout << mh.search(10) << endl;
	mh.remove(15);
	cout << mh.search(15);
}

/*** Implementation of Open Addressing ***/

struct MyHash
{
	int *arr;
	int cap, size;

	MyHash(int c)
	{
		cap = c;
		size = 0;
		arr = new int[cap];
		for (int i = 0; i < cap; i++)
			arr[i] = -1;
	}

	int hash(int key) {
		return key % cap;
	}
	bool insert(int key)
	{
		if (size == cap)
			return false;
		int i = hash(key);
		while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
			i = (i + 1) % cap;
		if (arr[i] == key)
			return false;
		else {
			arr[i] = key;
			size++;
			return true;
		}
	}
	bool search(int key)
	{
		int h = hash(key);
		int i = h;
		while (arr[i] != -1) {
			if (arr[i] == key)
				return true;
			i = (i + 1) % cap;
			if (i == h)
				return false;
		}
		return false;
	}
	bool erase(int key)
	{
		int h = hash(key);
		int i = h;
		while (arr[i] != -1) {
			if (arr[i] == key) {
				arr[i] = -2;
				return true;
			}
			i = (i + 1) % cap;
			if (i == h)
				return false;
		}
		return false;
	}
};

int main()
{
	MyHash mh(7);
	mh.insert(49);
	mh.insert(56);
	mh.insert(72);
	if (mh.search(56) == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	mh.erase(56);
	if (mh.search(56) == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

/**** Unordered Set*****/

int main() {

	unordered_set <int> s;
	s.insert(10);
	s.insert(5);
	s.insert(15);
	s.insert(20);
	for (int x : s)
		cout << x << " ";

	cout << endl;
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << s.size() << endl;
	s.clear();
	cout << s.size() << endl;

	s.insert(10);
	s.insert(5);
	s.insert(15);
	s.insert(20);
	cout << s.size() << endl;

	if (s.find(15) == s.end())
		cout << "Not Found";
	else
		cout << "Found " << (*s.find(15));

	cout << endl;
	if (s.count(15))
		cout << "Found";
	else
		cout << "Not Found";
	cout << endl;

	cout << s.size() << endl;
	s.erase(15);
	cout << s.size() << endl;
	auto it = s.find(10);
	s.erase(it);
	cout << s.size() << endl;

	s.erase(s.begin(), s.end());

	return 0;
}

/***Unordered Map ***/

int main() {

	unordered_map <string, int> m;
	m["gfg"] = 20;
	m["ide"] = 30;
	m.insert({"courses", 15});

	if (m.find("ide") != m.end())
		cout << "Found";
	else
		cout << "Not Found ";

	cout << endl;

	for (auto it = m.begin(); it != m.end(); it++)
		cout << (it->first) << " " << (it->second) << endl;

	if (m.count("ide") > 0)
		cout << "Found";
	else
		cout << "Not Found";
	cout << endl;

	cout << m.size() << endl;
	m.erase("ide");
	m.erase(m.begin());
	cout << m.size() << endl;
	m.erase(m.begin(), m.end());

	return 0;
}

/**** Count Distinct Elements ***/
int countDistinct(int arr[], int n)
{
	unordered_set<int> us;
	for (int i = 0; i < n; i++)
		us.insert(arr[i]);

	return us.size();
}

/** Frequencies of Array Elements **/

class GFG {
	public static void main (String[] args) throws IOException{
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		String s[] = inp.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int w = Integer.parseInt(s[1]);
		int l = Integer.parseInt(s[2]);
		int h[] = new int[n];
		int r[] = new int[n];
		int index = 0;
		int n1 = n;
		while (n-- > 0)
		{
			String s1[] = inp.readLine().split(" ");
			h[index] = Integer.parseInt(s1[0]);
			r[index] = Integer.parseInt(s1[1]);
			index++;
		}
		long mon = 0;

		while (mon >= 0)
		{
			//  System.out.println(mon);
			long sum = 0;
			long height = 0;
			for (long i = 0; i < n1; i = i + 1) {
				height = h[i] + r[i] * mon;
				if (height >= l)
				{
					sum += height;
					//  System.out.println(sum);
				}
			}
			if (sum >= w) {
				System.out.println(mon);
				break;
			}
			mon = mon + 1;
		}
	}
}

/***** Insertion of Two Arrays  ******/
int intersection(int arr1[], int m, int arr2[], int n)
{
	unordered_set<int> us;
	for (int i = 0; i < m; i++)
		us.insert(arr1[i]);

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (us.find(arr2[i]) != us.end())
		{
			res++;
			us.erase(arr2[i]);
		}
	}
	return res;
}

/******* Union of Two Unsorted Arrays ********/

int unionSize(int arr1[], int m, int arr2[], int n)
{
	unordered_set<int> us;
	for (int i = 0; i < m; i++)
		us.insert(arr1[i]);
	for (int i = 0; i < n; i++)
		us.insert(arr2[i]);

	return us.size();
}

/** Pair with Given Sum in Unsorted Array **/

int pairWithSumX(int arr[], int n, int X)
{
	unordered_set<int> us;
	for (int i = 0; i < n; i++)
	{
		if (us.find(X - arr[i]) != us.end())
			return 1;

		us.insert(arr[i]);
	}
	return 0;

}

/*** Subarray with zero sum **/
int ZeroSumSubarray(int arr[], int n)
{
	unordered_set<int> us;
	int prefix_sum = 0;
	us.insert(0);
	for (int i = 0; i < n; i++)
	{
		prefix_sum += arr[i];
		if (us.find(prefix_sum) != us.end())
			return 1;
		us.insert(prefix_sum);
	}
	return 0;

}

/***** Subarray with given Sum  *****/

// Naive
bool isSum(int arr[], int n, int sum)
{
	for (int i = 0; i < n; i++) {
		int curr_sum = 0;
		for (int j = i; j < n; j++) {
			curr_sum += arr[j];
			if (curr_sum == sum)
				return true;
		}
	}
	return false;
}

// Efficient

bool isSum(int arr[], int n, int sum)
{
	unordered_set<int> s;
	int pre_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (pre_sum == sum)
			return true;
		pre_sum += arr[i];
		if (s.find(pre_sum - sum) != s.end())
			return true;
		s.insert(pre_sum);
	}
	return false;
}

/****** Longest Subarray with given Sum ******/

int largestSubarrayWithSumX(int arr[], int n, int sum)
{
	int prefix_sum = 0;
	unordered_set<int> us;
	us.insert(0);
	for (int i = 0; i < n; i++)
	{
		prefix_sum += arr[i];
		if (us.find(prefix_sum - sum) != us.end())
			return 1;
		us.insert(prefix_sum);
	}
	return 0;
}

/******** Longest Subarrray with equal number of 0s and 1s **********/

int largestZeroSubarray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = (arr[i] == 0) ? -1 : 1;

	unordered_map<int, int> ump;
	int sum = 0, maxLen = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum == 0)
			maxLen = i + 1;

		if (ump.find(sum + n) != ump.end())
		{
			if (maxLen < i - ump[sum + n])
				maxLen = i - ump[sum + n];

		}
		else ump[sum + n] = i;
	}

	return maxLen;
}

/****** Longest Common span with same sum in binary array *******/

int longestCommonSum(bool arr1[], bool arr2[], int n)
{
	// Find difference between the two
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = arr1[i] - arr2[i];

	// Creates an empty hashMap hM
	unordered_map<int, int> hM;

	int sum = 0;	 // Initialize sum of elements
	int max_len = 0; // Initialize result

	// Traverse through the given array
	for (int i = 0; i < n; i++)
	{
		// Add current element to sum
		sum += arr[i];

		// To handle sum=0 at last index
		if (sum == 0)
			max_len = i + 1;

		// If this sum is seen before,
		// then update max_len if required
		if (hM.find(sum) != hM.end())
			max_len = max(max_len, i - hM[sum]);

		else // Else put this sum in hash table
			hM[sum] = i;
	}

	return max_len;
}

/**** Longest Consecutive Subsequence ****/

// Sorting
int findLongest(int arr[], int n)
{
	sort(arr, arr + n);
	int res = 1, curr = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1] + 1)
			curr++;
		else {
			res = max(res, curr);
			curr = 1;
		}
	}
	res = max(res, curr);
	return res;
}
// Efficient

int findLongest(int arr[], int n)
{
	unordered_set<int> s;
	int res = 0;

	for (int i = 0; i < n; i++)
		s.insert(arr[i]);

	for (int i = 0; i < n; i++) {
		if (s.find(arr[i] - 1) == s.end()) {
			int curr = 1;
			while (s.find(curr + arr[i]) != s.end())
				curr++;

			res = max(res, curr);
		}
	}
	return res;
}

/****** Count Distinct Elements in Every Window ********/

// Naive
void printDistinct(int arr[], int n, int k)
{
	for (int i = 0; i <= n - k; i++) {
		int count = 0;
		for (int j = 0; j < k; j++) {
			bool flag = false;
			for (int p = 0; p < j; p++) {
				if (arr[i + j] == arr[i + p])
				{
					flag = true; break;
				}
			}
			if (flag == false)count++;

		}
		cout << count << " ";
	}
}

// Efficient

void printDistinct(int arr[], int n, int k)
{
	map<int, int> m;

	for (int i = 0; i < k; i++) {
		m[arr[i]] += 1;
	}

	cout << m.size() << " ";

	for (int i = k; i < n; i++) {

		m[arr[i - k]] -= 1;

		if (m[arr[i - k]] == 0) {
			m.erase(arr[i - k]);
		}
		m[arr[i]] += 1;

		cout << m.size() << " ";
	}

}

/******* More than n/k Occurences *********/

// Naive
void printNByK(int arr[], int n, int k)
{
	sort(arr, arr + n);
	int i = 1, count = 1;
	while (i < n) {
		while (i < n && arr[i] == arr[i - 1]) {
			count++;
			i++;
		}
		if (count > n / k)
			cout << arr[i - 1] << " ";
		count = 1;
		i++;
	}

}

//Efficient

void printNByK(int arr[], int n, int k)
{
	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[arr[i]]++;
	for (auto e : m)
		if (e.second > n / k)
			cout << e.first << " ";

}


/******* More than n/k Occurences (O(nk) solution)********/

void printNByK(int arr[], int n, int k)
{
	unordered_map<int, int> m;

	for (int i = 0; i < n; i++) {
		if (m.find(arr[i]) != m.end())
			m[arr[i]]++;
		else if (m.size() < k - 1)
			m[arr[i]] = 1;
		else
			for (auto x : m) {
				x.second--;
				if (x.second == 0)
					m.erase(x.first);
			}
	}
	for (auto x : m) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (x.first == arr[i])
				count++;

		}
		if (count > n / k)
			cout << x.first << " ";
	}
}

/* Using Map Find */
void findUsage(){
	map<int,string> mp; // Red Black Tree
	m[1] ="abac", // O(log(n))
	m[2] ="absc",
	m[3] ="adbc",
	m[4] ="abcf",
	m[5] ="abfc",

	auto it = mp.find(3); // It will points to 3 iterator if not exists if will points to map.end : O(log(n))

	if(it==mp.end()){
		cout<<"No Value";
	}else{
		cout<< (*it).first<<" "<<(*it).second;
	}

	// For Erasing : O(log(n))
	if(it!=m.end())
		mp.erase(it) // It will delete m[3] 

}






























