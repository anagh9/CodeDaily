
/**
 * https://leetcode.com/problems/third-maximum-number/
 * i/p : {1,2,3,4,5,6,7,8}
 * o/p : 6
 *
 * i/p : {3,2,1}
 * o/p : 1
 *
 * i/p : {1,2}
 * o/p : 2
 *
 * i/p : {2,2,3,1}
 * o/p : 1
 *
 * **/


int ThirdMaximumNo(Ints v) {
	int first = v[0],
	    second = INT_MIN,
	    third = INT_MIN,
	    n = v.size(),
	    count = 0;

	if (n < 3) {
		if (n == 1)
			return v[0];
		else
			return max(v[0], v[1]);
	}

	for (int i = 1; i < n; i++) {
		if (first < v[i])
			first = v[i];
	}
	cout << first << endl;
	for (int i = 0; i < n; i++) {
		if (first > v[i] && v[i] > second) {
			second = v[i];
		}
	}
	cout << second << endl;

	for (int i = 0; i < n; i++) {
		if (second > v[i] && v[i] >= third) {
			third = v[i];
			count++;
		}
	}

	if (third == INT_MIN) {
		if (count != 0)
			return third;
		third = first;
	}
	return third;
}
