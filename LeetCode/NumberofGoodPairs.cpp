// https://leetcode.com/problems/number-of-good-pairs/submissions/

int numIdenticalPairs(vector<int>& nums) {
	int count{0};
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] == nums[i]) count++;
		}
	}
	return count;
}


int numIdenticalPairs(vector<int>& nums) {
	int res = 0;
	unordered_map<int, int> count;
	for (int a : nums) {
		res += count[a]++;
	}
	return res;
}