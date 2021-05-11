#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	/** @Two Pointer Approach O(n^2) **/

	vector<int> twoSum(vector<int> &nums, int target) {
		vector<int>res;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					res.push_back(i + 1);
					res.push_back(j + 1);
					// break;
				}
			}

		}
		return res;
	}

	/*****@ HashMap Approach O(n)  *****/

	vector<int> twoSumEffi(vector<int> &numbers, int target) {
		vector<int> res;
		map<int, int> hmap;
		hmap.clear();
		for (int i = 0; i < numbers.size(); i++) {
			hmap[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); i++) {
			if (hmap.find(target - numbers[i]) != hmap.end()) {
				if (i < hmap[target - numbers[i]]) {
					res.push_back(i + 1);
					res.push_back(hmap[target - numbers[i]] + 1);
					break;
					// return res;
				}
				if (i > hmap[target - numbers[i]]) {
					res.push_back(hmap[target - numbers[i]] + 1);
					res.push_back(i + 1);
					break;
					// return res;
				}
			}
		}
		return res;
	}
};


int main() {
	Solution s;
	vector<int> nums = {1, 2, 3, 4, 5, 6, 1, 2, 0};
	int target = 3;
	// auto it = s.twoSum(nums, target);
	auto it = s.twoSumEffi(nums, target);

	for (auto x : it) {
		cout << x << " ";
	}
}