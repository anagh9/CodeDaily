// https://leetcode.com/problems/monotonic-array/submissions/

// Analysis : First Tried To implement it in 2 loop approach Then change it to single loop

// Approach : First Run a loop and check for every next element greater than prev one if not flag = false break the loop

// Then we will only process for decresing array if condition is false if true we simply return it in decreasing loop we do the same check for every next element less than previous one

// My Solution

bool isMontonic(Ints &nums) {
	bool flag = false;
	if (nums.size() == 1)
		return true;
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] <= nums[i + 1]) {
			flag = true;
		} else {
			flag = false;
			break;
		}
	}

	if (!flag) {
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] >= nums[i + 1]) {
				flag = true;
			} else {
				flag = false;
				break;
			}
		}
	}
	return flag;

}
// TC -> O(n)
// Approach name: Two Pass

class Solution {
public:
	bool increasing(Ints &nums) {
		for (int i = 0; i < nums.size() - 1; i++)
			if (nums[i] >= nums[i + 1]) return false;
		return true;
	}

	bool decreasing(Ints &nums) {
		for (int i = 0; i < nums.size() - 1; i++)
			if (nums[i] <= nums[i + 1]) return false;
		return true;
	}

	bool isMontonic(Ints &nums) {
		return increasing(nums) || decreasing(nums);
	}

}

// Same as My Aproach but checking opposite

// Approach 3 : One Pass

class Soltion {
public:
	int compare(int a, int b) {
		if (a == b) return 0;
		if (a < b) return -1;
		if (a > b) return 1;
		return 0;
	}

	bool onePass(Ints &A) {
		int store = 0;
		for (int i = 0; i < A.size() - 1; ++i) {
			int c = compare(A[i], A[i + 1]);
			if (c != 0) {
				if (c != store && store != 0)
					return false;
				store = c;
			}
		}

		return true;
	}
};
// TC - O(n) A.S -O(1)

// Approach 4: Simple Variant of One Pass

class MonotonicArray
{
public:
	MonotonicArray();
	~MonotonicArray();
	bool isMontonic(Ints &A) {
		bool increasing = true;
		bool decreasing = true;

		for (int i = 0; i < A.size() - 1; ++i) {
			if (A[i] > A[i + 1])
				increasing = false;
			if (A[i] < A[i + 1])
				decreasing = false;
		}
		return increasing || decreasing;
	}
};