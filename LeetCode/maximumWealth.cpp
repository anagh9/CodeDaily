// https://leetcode.com/problems/richest-customer-wealth/submissions/

int maximumWealth(vector<vector<int>>& accounts) {

	int richest = 0;
	for (auto &customer : accounts)
		richest = max (richest, accumulate(customer.begin(), customer.end(), 0));
	return richest;
}


int maximumWealth(vector<vector<int>>& accounts) {
	int result{0}, maxx{0};
	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts.size(); j++) {
			result += accounts[i][j];
			maxx = max(result , maxx);
		}
	}
	return maxx;
}
