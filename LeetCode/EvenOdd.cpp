// https://leetcode.com/problems/sort-array-by-parity-ii/submissions/

//Two Pointer Approach
vector<int> sortArrayByParityII(vector<int>& A) {
	for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
		while (i < A.size() && A[i] % 2 == 0) i += 2;
		while (j < A.size() && A[j] % 2 == 1) j += 2;
		if (i < A.size()) swap(A[i], A[j]);
	}
	return A;
}

vector<int> sortArrayByParityII(vector<int>& nums) {
	int i{0}, j{1};
	int sz = nums.size();

	while (i < sz && j < sz) {
		if (nums[i] % 2 == 0)
			i += 2;
		else if (nums[j] % 2 == 1)
			j += 2;
		else {
			swap(nums[i], nums[j]);
			i += 2;
			j += 2;
		}
	}
	return nums;

}

vector<int> sortArrayByParityII(vector<int>& nums) {
	vector<int> even;
	vector<int> odd;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] % 2 == 0) even.push_back(nums[i]);
		else odd.push_back(nums[i]);
	}

	int j = 0;

	for (int i = 0; i < nums.size(); i = i + 2) {
		nums[i] = even[j]; j++;
	}

	j = 0;

	for (int i = 1; i < nums.size(); i = i + 2) {
		nums[i] = odd[j]; j++;
	}

	// for (auto it : nums) cout << it << " ";


	return nums;
}