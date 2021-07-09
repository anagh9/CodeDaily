/******* Searching and Sorting and Strings **********/

/* INtroduction to String */

main()
{
	string str = "geeksforgeeks";
	int count[26] = {0};
	for (int i = 0; i < str.length(); i++) {
		count[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] > 0) {
			cout << char(i + 'a') << " " << count[i] << endl;
		}
	}
}

main() {
	char str[] = "gfg";
	cout << str;
	cout << sizeof(str);
	char str[] = {'g', 'f', 'g'};
	cout << str;
	char str[] = {'g', 'f', 'g', '\0'};
	cout << str;
}

main() {
	char s1[] = "abc";
	char s2[] = "bcd";
	int res = strcmp(s1, s2);
	if (res > 0)
		cout << "Greater";
	else if (res == 0)
		cout << "Same";
	else
		cout << "Smaller";
}

main() {
	char s1[] = "gfg";
	char s2[] = "bcd";
	int res = strcmp(s1, s2);
	if (res > 0)
		cout << "Greater";
	else if (res == 0)
		cout << "Same";
	else
		cout << "Smaller";
}

main() {
	char s1[] = "bcd";
	char s2[] = "bcd";
	int res = strcmp(s1, s2);
	if (res > 0)
		cout << "Greater";
	else if (res == 0)
		cout << "Same";
	else
		cout << "Smaller";
}

main() {
	string str = "geeksforgeeks";
	cout << str.length() << " ";
	str = str + "xyz";
	cout << str << " ";
	cout << str.substr(1, 3) << " ";
	cout << str.find("eek") << " ";
	return 0;
}

main() {
	char s1[] = "abc";
	char s2[] = "bcd";
	if (s1 == s2)
		cout << "Same";
	else if (s1 < s2)
		cout << "Smaller";
	else
		cout << "Greater";
}

main() {
	string str;
	cout << "Enter your name";
	cin >> str;
	cout << "\nYour name is " << str;
}

main() {
	string str;
	cout << "Enter your name";
	getline(cin, str);
	cout << "\nYour name is " << str;
	return 0;
}

main() {
	string str;
	cout << "Enter your name";
	getline(cin, str, 'a');
	cout << "\nYour name is " << str;
	return 0;
}

main() {
	string str = "geeksforgeeks";
	for (int i = 0; i < str.length(); i++)
		cout << str[i];
	cout << endl;
	for (char x : str)
		cout << x;
}

/* Check if a String is Subsequence of Other */

// Iterative

bool isSubSeq(string s1, string s2, int n, int m) {
	int j = 0;

	for (int i = 0; i < n && j < m; i++) {
		if (s1[i] == s2[j])
			j++;
	}

	return j == m;
}

int main() {
	int n, m;
	string s1, s2;
	cin >> n >> m;
	cin >> s1 >> s2;

	cout << boolalpha << isSubSeq(s1, s2, n, m);

	return 0;
}

// Recursive Solution

bool isSubSeq(string s1, string s2, int n, int m) {
	if ( m == 0 )
		return true;

	if ( n == 0 )
		return false;

	if ( s1[n - 1] == s2[m - 1] )
		return isSubSeq(s1, s2, n - 1, m - 1);

	else
		return isSubSeq(s1, s2, n - 1, m);
}

int main() {
	int n, m;
	string s1, s2;
	cin >> n >> m;
	cin >> s1 >> s2;

	cout << boolalpha << isSubSeq(s1, s2, n, m);

	return 0;
}

/* Check for Anagram */

// Naive
bool areAnagram(string &s1, string &s2)
{
	int n1 = s1.length();
	int n2 = s2.length();
	if (n1 != n2)
		return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return (s1 == s2);
}

// Efficient
const int CHAR = 256;
bool areAnagram(string &s1, string &s2)
{
	int n1 = s1.length();
	int n2 = s2.length();
	if (n1 != n2)
		return false;

	int count[CHAR] = {0};
	for (int i = 0; i < s1.length(); i++) {
		count[s1[i]]++;
		count[s2[i]]--;
	}

	for (int i = 0; i < CHAR; i++) {
		if (count[i] != 0)return false;
	}
	return true;
}

/* Leftmost Repeating Character */

// Naive
int leftMost(string &str)
{
	for (int i = 0; i < str.length(); i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] == str[j])return i;
		}
	}
	return -1;
}

// Better Approach

const int CHAR = 256;
int leftMost(string &str)
{
	int count[CHAR] = {0};
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++;
	}
	for (int i = 0; i < str.length(); i++) {
		if (count[str[i]] > 1)return i;
	}
	return -1;
}

// Efficient Approach 1
const int CHAR = 256;
int leftMost(string &str)
{
	int fIndex[CHAR] = {0};
	fill(fIndex, fIndex + CHAR, -1);
	int res = INT_MAX;
	for (int i = 0; i < str.length(); i++) {
		int fi = fIndex[str[i]];
		if (fi == -1)
			fIndex[str[i]] = i;
		else
			res = min(res, fi);
	}

	return (res == INT_MAX) ? -1 : res;
}

// Efficient Approach 2
const int CHAR = 256;
int leftMost(string &str)
{
	bool visited[CHAR];
	fill(visited, visited + CHAR, false);
	int res = -1;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (visited[str[i]])
			res = i;
		else
			visited[str[i]] = true;
	}

	return res;
}


/* Leftmost Non-repeating Element */

// Naive
int nonRep(string &str)
{
	for (int i = 0; i < str.length(); i++) {
		bool flag = false;
		for (int j = 0; j < str.length(); j++) {
			if (i != j && str[i] == str[j]) {
				flag = true;
				break;
			}
		}
		if (flag == false)return i;
	}
	return -1;
}

//Better Approach
const int CHAR = 256;
int nonRep(string &str)
{
	int count[CHAR] = {0};
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++;
	}
	for (int i = 0; i < str.length(); i++) {
		if (count[str[i]] == 1)return i;
	}
	return -1;
}

// Efficient Approach
const int CHAR = 256;
int nonRep(string &str)
{
	int fI[CHAR];
	fill(fI, fI + CHAR, -1);

	for (int i = 0; i < str.length(); i++) {
		if (fI[str[i]] == -1)
			fI[str[i]] = i;
		else
			fI[str[i]] = -2;
	}
	int res = INT_MAX;
	for (int i = 0; i < CHAR; i++) {
		if (fI[i] >= 0)res = min(res, fI[i]);
	}
	return (res == INT_MAX) ? -1 : res;
}

/* Reverse words in a String */

void reverse(char str[], int low, int high) {
	while (low <= high) {
		swap(str[low], str[high]);
		low++;
		high--;
	}
}

void reverseWords(char str[], int n) {
	int start = 0;
	for (int end = 0; end < n; end++) {
		if (str[end] == ' ') {
			reverse(str, start, end - 1);
			start = end + 1;
		}
	}
	reverse(str, start, n - 1);
	reverse(str, 0, n - 1);
}


/* Naive Pattern Searching */

void patSearchinng(string &txt, string &pat) {
	int m = pat.length();
	int n = txt.length();
	for (int i = 0; i <= (n - m); i++) {
		int j;
		for (j = 0; j < m; j++)
			if (pat[j] != txt[i + j])
				break;

		if (j == m)
			cout << i << " ";
	}
}

/* Improved Naive Pattern Searching for Distinct */
void patSearchinng(string &txt, string &pat) {
	int m = pat.length();
	int n = txt.length();
	for (int i = 0; i <= (n - m);  ) {
		int j;
		for (j = 0; j < m; j++)
			if (pat[j] != txt[i + j])
				break;

		if (j == m)
			cout << i << " ";
		if (j == 0) {
			i++;
		}
		else {
			i = (i + j);
		}
	}
}

/* Rabin Karp Algorithm */

#define d 256
const int q = 101;
void RBSearch(string pat, string txt, int M, int N) {

	//Compute (d^(M-1))%q
	int h = 1;
	for (int i = 1; i <= M - 1; i++)
		h = (h * d) % q;

	//Compute p and to
	int p = 0, t = 0;
	for (int i = 0; i < M; i++) {
		p = (p * d + pat[i]) % q;
		t = (t * d + txt[i]) % q;
	}

	for (int i = 0; i <= (N - M); i++) {
		//Check for hit
		if (p == t) {
			bool flag = true;
			for (int j = 0; j < M; j++)
				if (txt[i + j] != pat[j]) {flag = false; break;}
			if (flag == true)cout << i << " ";
		}
		//Compute ti+1 using ti
		if (i < N - M) {
			t = ((d * (t - txt[i] * h)) + txt[i + M]) % q;
			if (t < 0)t = t + q;
		}
	}

}

int main()
{
	string txt = "GEEKS FOR GEEKS"; string pat = "GEEK";
	cout << "All index numbers where pattern found:" << " ";
	RBSearch(pat, txt, 4, 15);

	return 0;
}

/* KMP Algorithm (Part 1: Constructing LPS Array )*/

// Naive
int longPropPreSuff(string str, int n) {
	for (int len = n - 1; len > 0; len--) {
		bool flag = true;
		for (int i = 0; i < len; i++)
			if (str[i] != str[n - len + i])
				flag = false;

		if (flag == true)
			return len;
	}
	return 0;
}

void fillLPS(string str, int *lps) {
	for (int i = 0; i < str.length(); i++) {
		lps[i] = longPropPreSuff(str, i + 1);
	}
}

// TC - O(n^3)

// Efficient Solution
void fillLPS(string str, int *lps) {
	int n = str.length(), len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < n) {
		if (str[i] == str[len])
		{len++; lps[i] = len; i++;}
		else
		{	if (len == 0) {lps[i] = 0; i++;}
			else {len = lps[len - 1];}
		}
	}
}

int main()
{
	string txt = "abacabad"; int lps[txt.length()];
	fillLPS(txt, lps);
	for (int i = 0; i < txt.length(); i++) {
		cout << lps[i] << " ";
	}

	return 0;
}


// TC - O(n)

/* KMP Algorithm (Part 2: Complete Algorithm )*/

void fillLPS(string str, int *lps) {
	int n = str.length(), len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < n) {
		if (str[i] == str[len])
		{len++; lps[i] = len; i++;}
		else
		{	if (len == 0) {lps[i] = 0; i++;}
			else {len = lps[len - 1];}
		}
	}
}
void KMP(string pat, string txt) {
	int N = txt.length();
	int M = pat.length();
	int lps[M];
	fillLPS(pat, lps);
	int i = 0, j = 0;
	while (i < N) {
		if (pat[j] == txt[i]) {i++; j++;}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j == 0)
				i++;
			else
				j = lps[j - 1];
		}
	}
}

int main()
{
	string txt = "ababcababaad", pat = "ababa";
	KMP(pat, txt);
	return 0;
}

/* Check if Strings are Rotations */
bool areRotations(string s1, string s2) {
	if (s1.length() != s2.length())return false;
	return ((s1 + s1).find(s2) != string::npos);
}

int main()
{
	string s1 = "ABCD"; string s2 = "CDAB";
	if (areRotations(s1, s2)) {cout << "Strings are rotations of each other" << endl;}
	else {cout << "Strings are not rotations of each other" << endl;}

	return 0;
}

/* Anagram Search */

// Naive

const int CHAR = 256;
bool areAnagram(string &pat, string &txt, int i)
{
	int count[CHAR] = {0};
	for (int j = 0; j < pat.length(); j++) {
		count[pat[j]]++;
		count[txt[i + j]]--;
	}
	for (int j = 0; j < CHAR; j++) {
		if (count[j] != 0)return false;
	}
	return true;
}

bool isPresent(string &txt, string &pat) {
	int n = txt.length();
	int m = pat.length();
	for (int i = 0; i <= n - m; i++) {
		if (areAnagram(pat, txt, i))return true;
	}
	return false;
}

int main()
{
	string txt = "geeksforgeeks";
	string pat = "frog";
	if (isPresent(txt, pat))
		cout << "Anagram search found";
	else
		cout << "Anagram search not found";

	return 0;
}

// Efficient
const int CHAR = 256;

bool areSame(int CT[], int CP[]) {
	for (int i = 0; i < CHAR; i++) {
		if (CT[i] != CP[i])return false;
	}
	return true;
}

bool isPresent(string &txt, string &pat) {
	int CT[CHAR] = {0}, CP[CHAR] = {0};
	for (int i = 0; i < pat.length(); i++) {
		CT[txt[i]]++;
		CP[pat[i]]++;
	}
	for (int i = pat.length(); i < txt.length(); i++) {
		if (areSame(CT, CP))return true;
		CT[txt[i]]++;
		CT[txt[i - pat.length()]]--;
	}
	return false;
}

int main()
{
	string txt = "geeksforgeeks";
	string pat = "frog";
	if (isPresent(txt, pat))
		cout << "Anagram search found";
	else
		cout << "Anagram search not found";

	return 0;
}

/* Lexicographic Rank of a String */

const int CHAR = 256;
int fact(int n)
{
	return (n <= 1) ? 1 : n * fact(n - 1);
}

int lexRank(string &str)
{
	int res = 1;
	int n = str.length();
	int mul = fact(n);
	int count[CHAR] = {0};
	for (int i = 0; i < n; i++)
		count[str[i]]++;
	for (int i = 1; i < CHAR; i++)
		count[i] += count[i - 1];
	for (int i = 0; i < n - 1; i++) {
		mul = mul / (n - i);
		res = res + count[str[i] - 1] * mul;
		for (int j = str[i]; j < CHAR; j++)
			count[j]--;
	}
	return res;
}


int main()
{
	string str = "STRING";
	cout << lexRank(str);
	return 0;
}

/* Longest Substring with Distinct Characters */

// Naive O(n^3)
bool areDistinct(string str, int i, int j)
{

	vector<bool> visited(256);

	for (int k = i; k <= j; k++) {
		if (visited[str[k]] == true)
			return false;
		visited[str[k]] = true;
	}
	return true;
}

int longestDistinct(string str)
{
	int n = str.length();
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (areDistinct(str, i, j))
				res = max(res, j - i + 1);
	return res;
}

int main()
{
	string str = "geeksforgeeks";
	int len = longestDistinct(str);
	cout << "The length of the longest distinct characters substring is " << len;
	return 0;
}

// Better Approach O(n^2)

int longestDistinct(string str)
{
	int n = str.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		vector<bool> visited(256);
		for (int j = i; j < n; j++) {
			if (visited[str[j]] == true) {
				break;
			}
			else {
				res = max(res, j - i + 1);
				visited[str[j]] = true;
			}
		}
	}
	return res;
}

int main()
{
	string str = "geeksforgeeks";
	int len = longestDistinct(str);
	cout << "The length of the longest distinct characters substring is " << len;
	return 0;
}

// Efficient Solution O(n)

int longestDistinct(string str)
{
	int n = str.length();
	int res = 0;
	vector<int> prev(256, -1);
	int i = 0;
	for (int j = 0; j < n; j++) {
		i = max(i, prev[str[j]] + 1);
		int maxEnd = j - i + 1;
		res = max(res, maxEnd);
		prev[str[j]] = j;
	}
	return res;
}

int main()
{
	string str = "geeksforgeeks";
	int len = longestDistinct(str);
	cout << "The length of the longest distinct characters substring is " << len;
	return 0;
}


/***** Searching *******/


/* Binary Search (Iterative) */



int bSearch(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (arr[mid] == x)
			return mid;

		else if (arr[mid] > x)
			high = mid - 1;

		else
			low = mid + 1;
	}

	return -1;
}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60}, n = 6;

	int x = 25;

	cout << bSearch(arr, n, x);
	return 0;
}

/* Binary Search (Recursive) */


int bSearch(int arr[], int low, int high, int x)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (arr[mid] == x)
		return mid;

	else if (arr[mid] > x)
		return bSearch(arr, low, mid - 1, x);

	else
		return bSearch(arr, mid + 1, high, x);
}

/* Index of First Occurence in Sorted */

int firstOcc(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (x > arr[mid])
			low = mid + 1;

		else if (x < arr[mid])
			high = mid - 1;

		else
		{
			if (mid == 0 || arr[mid - 1] != arr[mid])
				return mid;

			else
				high = mid - 1;
		}

	}

	return -1;
}

// Efficient Recursive

int firstOcc(int arr[], int low, int high, int x)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (x > arr[mid])
		return firstOcc(arr, mid + 1, high, x);

	else if (x < arr[mid])
		return firstOcc(arr, low, mid - 1, x);

	else
	{
		if (mid == 0 || arr[mid - 1] != arr[mid])
			return mid;

		else
			return firstOcc(arr, low, mid - 1, x);
	}
}

// Naive
int firstOccurrence(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;

	return -1;
}


/***Index of Last Occurence in Sorted ***/

// Iterative

int lastOcc(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (x > arr[mid])
			low = mid + 1;

		else if (x < arr[mid])
			high = mid - 1;

		else
		{
			if (mid == n - 1 || arr[mid + 1] != arr[mid])
				return mid;

			else
				low = mid + 1;
		}

	}

	return -1;
}
// Recursive

int lastOcc(int arr[], int low, int high, int x, int n)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (x > arr[mid])
		return lastOcc(arr, mid + 1, high, x, n);

	else if (x < arr[mid])
		return lastOcc(arr, low, mid - 1, x, n);

	else
	{
		if (mid == n - 1 || arr[mid + 1] != arr[mid])
			return mid;

		else
			return lastOcc(arr, mid + 1, high, x, n);
	}
}

/*** Count Occurences in Sorted ****/

int lastOcc(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (x > arr[mid])
			low = mid + 1;

		else if (x < arr[mid])
			high = mid - 1;

		else
		{
			if (mid == n - 1 || arr[mid + 1] != arr[mid])
				return mid;

			else
				low = mid + 1;
		}

	}

	return -1;
}

int countOcc(int arr[], int n, int x)
{
	int first = firstOcc(arr, n, x);

	if (first == -1)
		return 0;
	else
		return lastOcc(arr, n, x) - first + 1;
}

/* Count 1s in a Sorted Binary Array */


int countOnes(int arr[], int n)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (arr[mid] == 0)
			low = mid + 1;
		else
		{
			if (mid == 0 || arr[mid - 1] == 0)
				return (n - mid);
			else
				high = mid - 1;
		}
	}

	return 0;
}

/* Square Root */

// Efficient

int sqRootFloor(int x)
{
	int low = 1, high = x, ans = -1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		int mSq = mid * mid;

		if (mSq == x)
			return mid;
		else if (mSq > x)
			high = mid - 1;
		else
		{
			low = mid + 1;
			ans = mid;
		}
	}

	return ans;
}
// cout << sqRootFloor(10); o/p-: 3

// Naive

int sqRootFloor(int x)
{
	int i = 1;

	while (i * i <= x)
		i++;

	return i - 1;
}

/* Search in Infinite Sized Array */

// Efficient

int bSearch(int arr[], int low, int high, int x)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (arr[mid] == x)
		return mid;

	else if (arr[mid] > x)
		return bSearch(arr, low, mid - 1, x);

	else
		return bSearch(arr, mid + 1, high, x);
}


int search(int arr[], int x)
{
	if (arr[0] == x) return 0;

	int i = 1;

	while (arr[i] < x)
		i = i * 2;

	if (arr[i] == x) return i;


	return bSearch(arr, i / 2 + 1, i - 1, x);
}

// Naive


int search(int arr[], int x)
{
	int i = 0;

	while (true)
	{
		if (arr[i] == x) return i;

		if (arr[i] > x) return -1;

		i++;
	}
}

/* Search in Sorted Rotated Array*/

// Efficient


int search(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (arr[mid] == x)
			return mid;
		if (arr[low] < arr[mid])
		{
			if (x >= arr[low] && x < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		else
		{
			if (x > arr[mid] && x <= arr[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}


	return -1;
}

// Naive
int search(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;

	return -1;
}


/* Find a Peak Element */

// Efficient

int getPeak(int arr[], int n)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
		        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
			return mid;
		if (mid > 0 && arr[mid - 1] >= arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

// Naive


int getPeak(int arr[], int n)
{
	if (n == 1)
		return arr[0];
	if (arr[0] >= arr[1])
		return arr[0];
	if (arr[n - 1] >= arr[n - 2])
		return arr[n - 1];

	for (int i = 1; i < n - 1; i++)
		if (arr[i] >= arr[i - 1] && arr[i] <= arr[i + 1])
			return arr[i];
}

/* Two Pointer Approach */
// Find pair in unsorted array which gives sum X


void printPairs(int arr[], int arr_size, int sum)
{
	unordered_set<int> s;
	for (int i = 0; i < arr_size; i++) {
		int temp = sum - arr[i];

		if (s.find(temp) != s.end())
			cout << "Pair with given sum " << sum << " is (" << arr[i] << ", " << temp << ")" << endl;

		s.insert(arr[i]);
	}
}


// Find pair in sorted array which gives sum X

bool isPresent(int arr[], int n, int sum)
{
	int l = 0, h = n - 1;
	int mid;
	while (l <= h)
	{
		if (arr[l] + arr[h] == sum)
			return true;
		else if (arr[l] + arr[h] > sum)
			h--;
		else l++;
	}
	return false;
}

// Find triplet in an array which gives sum X

bool find3Numbers(int A[], int arr_size, int sum)
{
	int l, r;

	/* Sort the elements */
	sort(A, A + arr_size);

	/* Now fix the first element one by one and find the
	other two elements */
	for (int i = 0; i < arr_size - 2; i++) {

		// To find the other two elements, start two index
		// variables from two corners of the array and move
		// them toward each other
		l = i + 1; // index of the first element in the
		// remaining elements

		r = arr_size - 1; // index of the last element
		while (l < r) {
			if (A[i] + A[l] + A[r] == sum) {
				printf("Triplet is %d, %d, %d", A[i],
				       A[l], A[r]);
				return true;
			}
			else if (A[i] + A[l] + A[r] < sum)
				l++;
			else // A[i] + A[l] + A[r] > sum
				r--;
		}
	}

	// If we reach here, then no triplet was found
	return false;
}

/* Median of two Sorted Arrays */


double getMed(int a1[], int a2[], int n1, int n2)
{
	int begin1 = 0, end1 = n1;

	while (begin1 < end1)
	{
		int i1 = (begin1 + end1) / 2;
		int i2 = (n1 + n2 + 1) / 2 - i1;

		int min1 = (i1 == n1) ? INT_MAX : a1[i1];
		int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];

		int min2 = (i2 == n2) ? INT_MAX : a2[i2];
		int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

		if (max1 <= min2 && max2 <= min1)
		{
			if ((n1 + n2) % 2 == 0)
				return ((double)max(max1, max2) + min(min1, min2)) / 2;
			else
				return (double)max(max1, max2);
		}
		else if (max1 > min2)
			end1 = i1 - 1;
		else
			begin1 = i1 + 1;
	}
}

main() {
	int a1[] = {10, 20, 30, 40, 50}, n1 = 5, a2[] = {5, 15, 25, 35, 45}, n2 = 5;

	cout << getMed(a1, a2, n1, n2);
}


/* Majority Element */

// Efficient


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

// Naive Approach

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

/****** Repeating Elements Part (1) *******/



int repeat(int arr[], int n)
{
	bool visit[n];

	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++)
	{
		if (visit[arr[i]])
			return arr[i];
		visit[arr[i]] = true;
	}

	return -1;
}

/****** Repeating Elements Part (2) *******/


int repeat(int arr[], int n)
{
	int slow = arr[0], fast = arr[0];

	do {
		slow = arr[slow];
		fast = arr[arr[fast]];

	} while (slow != fast);

	slow = arr[0];

	while (slow != fast)
	{
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}

/********* Allocation Minimum Pages (Naive Method) ***********/

int sum(int arr[], int b, int e) {
	int s = 0;
	for (int i = b; i <= e; i++)
		s += arr[i];
	return s;
}

int minPages(int arr[], int n, int k) {
	if (k == 1)
		return sum(arr, 0, n - 1);
	if (n == 1)
		return arr[0];
	int res = INT_MAX;
	for (int i = 1; i < n; i++) {
		res = min(res, max(minPages(arr, i, k - 1), sum(arr, i, n - 1)));
	}
	return res;
}

int main()
{
	int arr[] = {10, 20, 10, 30};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;

	cout << minPages(arr, n, k);
}

/******* Allocation Minimum Pages (Binary Search) *******/

bool isFeasible(int arr[], int n, int k, int ans) {
	int req = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] > ans) {
			req++;
			sum = arr[i];
		}
		else {
			sum += arr[i];
		}
	}
	return (req <= k);
}

int minPages(int arr[], int n, int k) {
	int sum = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		mx = max(mx, arr[i]);
	}
	int low = mx, high = sum, res = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (isFeasible(arr, n, k, mid)) {
			res = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return res;
}

/***********Sorting************************/
main() {

	int arr[] = {10, 20, 5, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n);

	for (int x : arr)
		cout << x << " ";

	sort(arr, arr + n, greater<int>());

	cout << endl;
	for (int x : arr)
		cout << x << " ";
}

main() {

	vector<int> v = {10, 20, 5, 7};

	sort(v.begin(), v.end());

	for (int x : v)
		cout << x << " ";

	sort(v.begin(), v.end(), greater<int>());

	cout << endl;
	for (int x : v)
		cout << x << " ";
}

/** (Own Object & Order) **/
struct Point {
	int x, y;
};

bool MyComp(Point p1, Point p2) {
	return p1.x < p2.x;
}

int main() {

	Point arr[] = {{3, 10}, {2, 8}, {5, 4}};

	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n, MyComp);

	for (auto i : arr)
		cout << i.x << " " << i.y << endl;
}

/** Bubble Sort **/

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < n - i - 1; j++) {
			if ( arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

/** Selection Sort **/

void selectionSort(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		int min_ind = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_ind]) {
				min_ind = j;
			}
		}

		swap(arr[i], arr[min_ind]);
	}
}

/** Insertion Sort **/

void iSort(int arr[], int n) {

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

/** Merge Two Sorted Arrays (Naive) **/
void merge(int a[], int b[], int m, int n) {

	int c[m + n];
	for (int i = 0; i < m; i++)
		c[i] = a[i];
	for (int j = 0; j < n; j++)
		c[j + m] = b[j];

	sort(c, c + m + n);

	for (int i = 0; i < m + n; i++)
		cout << c[i] << " ";
}


/** Merge Two Sorted Arrays (Efficient) **/

void merge(int a[], int b[], int m, int n) {

	int i = 0, j = 0;
	while (i < m && j < n) {
		if (a[i] < b[j])
			cout << a[i++] << " ";
		else
			cout << b[j++] << " ";
	}
	while (i < m)
		cout << a[i++] << " ";
	while (j < n)
		cout << b[j++] << " ";
}

/** Merge Function of Merge Sort **/
void merge(int arr[], int l, int m, int h) {

	int n1 = m - l + 1, n2 = h - m;
	int left[n1], right[n2];
	for (int i = 0; i < n1; i++)
		left[i] = arr[i + l];
	for (int j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];
}

/** Merge Sorting Algorithm **/

void merge(int arr[], int l, int m, int h) {

	int n1 = m - l + 1, n2 = h - m;
	int left[n1], right[n2];
	for (int i = 0; i < n1; i++)
		left[i] = arr[i + l];
	for (int j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) {
	if (r > l) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

/** Insertion of Two Sorted Arrays **/
//Naive

void intersection(int a[], int b[], int m, int n) {

	for (int i = 0; i < m; i++) {
		if (i > 0 && a[i - 1] == a[i])
			continue;
		for (int j = 0; j < n; j++)
			if (a[i] == b[j]) {
				cout << a[i] << " ";
				break;
			}
	}
}

// Efficient
void intersection(int a[], int b[], int m, int n) {
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (i > 0 && a[i - 1] == a[i]) {
			i++;
			continue;
		}
		if (a[i] < b[j]) {
			i++;
		}
		else if (a[i] > b[j]) {
			j++;
		}
		else {
			cout << a[i] << " ";
			i++; j++;
		}
	}
}

/** Union of Two Sorted Arrays **/

// Naive

void printUnion(int a[], int b[], int m, int n) {

	int c[m + n];
	for (int i = 0; i < m; i++)
		c[i] = a[i];
	for (int i = 0; i < n; i++)
		c[i + m] = b[i];
	sort(c, c + m + n);

	for (int i = 0; i < m + n; i++) {
		if (i == 0 || c[i] != c[i - 1])
			cout << c[i] << " ";
	}
}

// Efficient

void printUnion(int a[], int b[], int m, int n) {

	int i = 0, j = 0;
	while (i < m && j < n) {
		if (i > 0 && a[i - 1] == a[i]) {i++; continue;}
		if (j > 0 && b[j - 1] == b[j]) {j++; continue;}
		if (a[i] < b[j]) {cout << a[i] << " "; i++;}
		else if (a[i] > b[j]) {cout << b[j] << " "; j++;}
		else {cout << a[i] << " "; i++; j++;}
	}
	while (i < m) {if (i == 0 || a[i] != a[i - 1])cout << a[i] << " "; i++;}
	while (j < n) {if (j == 0 || b[j] != b[j - 1])cout << b[j] << " "; j++;}
}

/** Count inversions in Array **/

// NAIVE

int countInversions(int arr[], int n) {

	int res = 0;
	for (int i = 0; i < (n - 1); i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])
				res++;
		}
	}
	return res;
}

// Efficient
int countAndMerge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;
	int left[n1], right[n2];
	for (int i = 0; i < n1; i++)
		left[i] = arr[i + l];
	for (int j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];
	int res = 0, i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j])
		{arr[k++] = left[i++];}
		else {
			arr[k++] = right[j++];
			res = res + (n1 - i);
		}
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];
	return res;
}

int countInv(int arr[], int l, int r)
{
	int res = 0;
	if (l < r) {

		int m = (r + l) / 2;

		res += countInv(arr, l, m);
		res += countInv(arr, m + 1, r);
		res += countAndMerge(arr, l, m , r);
	}
	return res;
}

/** Naive Patition **/

// This video introduces us to the Partition method of Quick Sort. This partitioning method is a naive way of approach towards partitioning an array.

void partition(int arr[], int l, int h, int p)
{
	int temp[h - l + 1], index = 0;
	for (int i = l; i <= h; i++)
		if (arr[i] <= arr[p])
		{
			temp[index] = arr[i]; index++;
		}
	for (int i = l; i <= h; i++)
		if (arr[i] > arr[p])
		{
			temp[index] = arr[i]; index++;
		}
	for (int i = l; i <= h; i++)
		arr[i] = temp[i - l];
}

/** Lomuto Partition **/

int iPartition(int arr[], int l, int h)
{
	int pivot = arr[h];
	int i = l - 1;
	for (int j = l; j <= h - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return i + 1;
}

/** Hoare Partition **/

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = l - 1, j = h + 1;
	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i >= j)return j;
		swap(arr[i], arr[j]);
	}
}

/** QuickSort using Lomuto Parititon **/

int iPartition(int arr[], int l, int h)
{
	int pivot = arr[h];
	int i = l - 1;
	for (int j = l; j <= h - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return i + 1;
}

void qSort(int arr[], int l, int h) {
	if (l < h) {
		int p = iPartition(arr, l, h);
		qSort(arr, l, p - 1);
		qSort(arr, p + 1, h);
	}
}

/** QuickSort using Hoare Partition **/

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = l - 1, j = h + 1;
	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i >= j)return j;
		swap(arr[i], arr[j]);
	}
}

void qSort(int arr[], int l, int h) {
	if (l < h) {
		int p = partition(arr, l, h);
		qSort(arr, l, p);
		qSort(arr, p + 1, h);
	}
}

/** Tail Call Elimination in QuickSort **/
int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = l - 1, j = h + 1;
	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i >= j)return j;
		swap(arr[i], arr[j]);
	}
}

void qSort(int arr[], int l, int h) {
Begin:
	if (l < h) {
		int p = partition(arr, l, h);
		qSort(arr, l, p);
		l = p + 1;
		goto Begin;
	}
}

/** Kth Smallest Element Naive **/

int kthSmallest(int arr[], int n, int k)
{
	sort(arr, arr + n);
	return arr[k - 1];
}

/** Kth Smallest Element Efficient **/

int partition(int arr[], int l, int h)
{
	int pivot = arr[h];
	int i = l - 1;
	for (int j = l; j <= h - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return i + 1;
}

int kthSmallest(int arr[], int n, int k) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int p = partition(arr, l, r);
		if (p == k - 1)
			return p;
		else if (p > k - 1)
			r = p - 1;
		else
			l = p + 1;
	}
	return -1;
}

/** Chocolate Distribution Problem **/
int minDiff(int arr[], int n, int m) {
	if (m > n)
		return -1;
	sort(arr, arr + n);
	int res = arr[m - 1] - arr[0];
	for (int i = 0; (i + m - 1) < n; i++)
		res = min(res, arr[i + m - 1] - arr[i]);
	return res;
}

/** Sort an Array with two types of Elements **/

// Naive
void sort(int arr[], int n) {
	int temp[n], i = 0;

	for (int j = 0; j < n; j++)
		if (arr[j] < 0)
			temp[i++] = arr[j];
	for (int j = 0; j < n; j++)
		if (arr[j] >= 0)
			temp[i++] = arr[j];
	for (int j = 0; j < n; j++)
		arr[j] = temp[j];
}

// Efficient
void sort(int arr[], int n) {
	int i = -1, j = n;
	while (true)
	{
		do {i++;} while (arr[i] < 0);
		do {j--;} while (arr[j] >= 0);
		if (i >= j)return;
		swap(arr[i], arr[j]);
	}
}

/** Sort an array with three types of elements **/

// Naive
void sort(int arr[], int n) {
	int temp[n], i = 0;

	for (int j = 0; j < n; j++)
		if (arr[j] == 0)
			temp[i++] = arr[j];
	for (int j = 0; j < n; j++)
		if (arr[j] == 1)
			temp[i++] = arr[j];
	for (int k = 0; k < n; k++)
		if (arr[k] == 2)
			temp[i++] = arr[k];
	for (int j = 0; j < n; j++)
		arr[j] = temp[j];

}

// Efficient
void sort(int arr[], int n) {
	int l = 0, h = n - 1, mid = 0;
	while (mid <= h) {
		switch (arr[mid]) {
		case 0:
			swap(arr[l], arr[mid]);
			l++; mid++;
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(arr[h], arr[mid]);
			h--;
			break;
		}
	}
}

/** Minimum Difference in an Array **/
// Naive
int getMinDiff(int arr[], int n) {
	int res = INT_MAX;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			res = min(res, abs(arr[i] - arr[j]));
		}
	}
	return res;
}

//Efficient
int getMinDiff(int arr[], int n) {
	sort(arr, arr + n);
	int res = INT_MAX;

	for (int i = 1; i < n; i++) {
		res = min(res, arr[i] - arr[i - 1]);
	}
	return res;
}

/** Merge Overlapping intervals **/

// Efficient

struct Interval
{
	int s, e;
};

bool mycomp(Interval a, Interval b)
{ return a.s < b.s; }

void mergeIntervals(Interval arr[], int n)
{
	sort(arr, arr + n, mycomp);

	int res = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[res].e >=  arr[i].s)
		{
			arr[res].e = max(arr[res].e, arr[i].e);
			arr[res].s = min(arr[res].s, arr[i].s);
		}
		else {
			res++;
			arr[res] = arr[i];
		}
	}

	for (int i = 0; i <= res; i++)
		cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

int main()
{
	Interval arr[] =  { {5, 10}, {3, 15}, {18, 30}, {2, 7} };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, n);

	return 0;
}

/** Meeting the maximum guests **/

int maxGuest(int arr[], int dep[], int n)
{
	sort(arr, arr + n);
	sort(dep, dep + n);

	int i = 1, j = 0, res = 1, curr = 1;
	while (i < n && j < n) {
		if (arr[i] < dep[j]) {
			curr++; i++;
		}
		else {
			curr--; j++;
		}
		res = max(curr, res);
	}
	return res;
}


/** Cycle Sort **/
void cycleSortDistinct(int arr[], int n)
{
	for (int cs = 0; cs < n - 1; cs++) {
		int item = arr[cs];
		int pos = cs;
		for (int i = cs + 1; i < n; i++)
			if (arr[i] < item)
				pos++;
		swap(item, arr[pos]);
		while (pos != cs) {
			pos = cs;
			for (int i = cs + 1; i < n; i++)
				if (arr[i] < item)
					pos++;
			swap(item, arr[pos]);
		}
	}
}

/** Heap Sort **/

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void buildheap(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
	buildheap(arr, n);

	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}

/** Counting Sort **/

// Naive

void countSort(int arr[], int n, int k)
{
	int count[k];
	for (int i = 0; i < k; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[arr[i]]++;

	int index = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < count[i]; j++) {
			arr[index] = i;
			index++;
		}
	}
}

// Efficient

void countSort(int arr[], int n, int k)
{
	int count[k];
	for (int i = 0; i < k; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[arr[i]]++;

	for (int i = 1; i < k; i++)
		count[i] = count[i - 1] + count[i];

	int output[n];
	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}

/** Radix Sort **/
void countingSort(int arr[], int n, int exp)
{
	int output[n];
	int count[10] = { 0 };
	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];

	for (int exp = 1; mx / exp > 0; exp *= 10)
		countingSort(arr, n, exp);
}

/** Bucket Sort **/

void bucketSort(int arr[], int n, int k)
{
	int max_val = arr[0];
	for (int i = 1; i < n; i++)
		max_val = max(max_val, arr[i]);

	max_val++;
	vector<int> bkt[k];

	for (int i = 0; i < n; i++) {
		int bi = (k * arr[i]) / max_val;
		bkt[bi].push_back(arr[i]);
	}

	for (int i = 0; i < k; i++)
		sort(bkt[i].begin(), bkt[i].end());

	int index = 0;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < bkt[i].size(); j++)
			arr[index++] = bkt[i][j];
}



int main()
{
	int arr[] = { 30, 40, 10, 80, 5, 12, 70 };
	int n = sizeof(arr) / sizeof(arr[0]); int k = 4;
	bucketSort(arr, n, k);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}




































































































